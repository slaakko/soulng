// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/slg/LexerContext.hpp>
#include <soulng/slg/Model.hpp>
#include <soulng/slg/Identifier.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Path.hpp>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

namespace soulng { namespace slg {

using namespace soulng::unicode;
using namespace soulng::util;

LexerContext::LexerContext(IdentifierClassKind identifierClassKind) :
    nextNfaStateId(0), nextDfaStateId(0), lexerStatementIndex(-1), classIndex(0), any(), epsilon(eps), idStart(new Class(classIndex++)), idCont(new Class(classIndex++)),
    classMap(nullptr), prefix(nullptr), tokens(nullptr), keywords(nullptr), expressions(nullptr), lexer(nullptr), parser(nullptr), currentExpression(nullptr)
{
    if (identifierClassKind == IdentifierClassKind::unicode)
    {
        MakeUnicodeIdentifierClasses(*this);
    }
    else if (identifierClassKind == IdentifierClassKind::ascii)
    {
        MakeAsciiIdentifierClasses(*this);
    }
    symbols.push_back(idStart);
    symbols.push_back(idCont);
}

LexerContext::~LexerContext()
{
    for (NfaState* state : nfaStates)
    {
        delete state;
    }
    for (DfaState* state : dfaStates)
    {
        delete state;
    }
    for (Symbol* symbol : symbols)
    {
        delete symbol;
    }
    for (Class* cls : canonicalClasses)
    {
        delete cls;
    }
}

NfaState* LexerContext::MakeNfaState()
{
    NfaState* state = new NfaState(nextNfaStateId++, lexerStatementIndex);
    nfaStates.push_back(state);
    return state;
}

DfaState* LexerContext::MakeDfaState(const std::vector<NfaState*>& nfaStates)
{
    std::vector<NfaState*> s(nfaStates);
    std::sort(s.begin(), s.end());
    for (DfaState* state : dfaStates)
    {
        if (state->NfaStates() == s)
        {
            return state;
        }
    }
    DfaState* state = new DfaState(nextDfaStateId++, s);
    dfaStates.push_back(state);
    return state;
}

Symbol* LexerContext::MakeChar(char32_t c)
{
    auto it = charSymbols.find(c);
    if (it != charSymbols.cend())
    {
        return it->second;
    }
    Symbol* symbol = new Char(c);
    symbol->DontSetContained();
    symbols.push_back(symbol);
    charSymbols[c] = symbol;
    return symbol;
}

Symbol* LexerContext::MakeRange(char32_t start, char32_t end)
{
    Range range(start, end);
    auto it = rangeSymbols.find(range);
    if (it != rangeSymbols.cend())
    {
        return it->second;
    }
    Symbol* symbol = new Range(start, end);
    symbols.push_back(symbol);
    rangeSymbols[range] = symbol;
    return symbol;
}

Class* LexerContext::MakeClass()
{
    Class* cls = new Class(classIndex++);
    symbols.push_back(cls);
    return cls;
}

void LexerContext::SetClassMap(ClassMap* classMap_)
{
    if (classMap)
    {
        throw std::runtime_error("error in " + fileName + ": cannot have more than one class map declaration per .lexer file");
    }
    classMap = classMap_;
}

void LexerContext::SetPrefix(Prefix* prefix_)
{
    if (prefix)
    {
        throw std::runtime_error("error in " + fileName + ": cannot have more than one prefix declaration per .lexer file");
    }
    prefix = prefix_;
}

void LexerContext::SetTokens(Tokens* tokens_)
{
    if (tokens)
    {
        throw std::runtime_error("error in " + fileName + ": cannot have more than one set of token definitions per .lexer file");
    }
    tokens = tokens_;
}

void LexerContext::SetKeywords(Keywords* keywords_)
{
    if (keywords)
    {
        throw std::runtime_error("error in " + fileName + ": cannot have more than one set of keyword definitions per .lexer file");
    }
    keywords = keywords_;
}

void LexerContext::SetExpressions(Expressions* expressions_)
{
    if (expressions)
    {
        throw std::runtime_error("error in " + fileName + ": cannot have more than one set of expressions per .lexer file");
    }
    expressions = expressions_;
}

void LexerContext::SetFileName(const std::string& fileName_)
{
    fileName = fileName_;
}

Nfa LexerContext::MakeExpr(const std::u32string& id)
{
    if (id == U"idstart")
    {
        return MakeNfa(*this, MakeIdStart());
    }
    else if (id == U"idcont")
    {
        return MakeNfa(*this, MakeIdCont());
    }
    if (expressions)
    {
        Expression* expr = expressions->Get(id);
        if (currentExpression)
        {
            if (expr->Index() >= currentExpression->Index())
            {
                throw std::runtime_error("error: forward reference '" + ToUtf8(expr->Id()) + "' from expression '" + ToUtf8(currentExpression->Id()) + "'");
            }
        }
        if (parser)
        {
            Expression* prevExpression = currentExpression;
            currentExpression = expr;
            Nfa nfa = parser->Parse(expr->Value(), this, expr->Line());
            currentExpression = prevExpression;
            return nfa;
        }
        else
        {
            throw std::runtime_error("parser not set");
        }
    }
    else
    {
        throw std::runtime_error("expressions not set");
    }
}

void LexerContext::MakeCanonicalClasses()
{
    std::vector<Symbol*> s = symbols;
    for (Symbol* symbol : s)
    {
        if (symbol->Contained()) continue;
        if (symbol->IsClass())
        {
            Class* cls = static_cast<Class*>(symbol);
            Class* canonicalClass = cls->MakeCanonical(*this);
            canonicalClasses.push_back(canonicalClass);
        }
        else if (symbol->IsChar())
        {
            Char* chr = static_cast<Char*>(symbol);
            Class* canonicalClass = new Class(-1);
            canonicalClass->Ranges().push_back(Range(chr->Chr(), chr->Chr()));
            canonicalClasses.push_back(canonicalClass);
        }
        else if (symbol->IsAny())
        {
            Symbol* range = MakeRange(static_cast<char32_t>(1), static_cast<char32_t>(0x10FFFF));
            Class* canonicalClass = new Class(-1);
            canonicalClass->Ranges().push_back(Range(static_cast<char32_t>(1), static_cast<char32_t>(0x10FFFF)));
            canonicalClasses.push_back(canonicalClass);
        }
        else if (symbol->IsRange())
        {
            Range* range = static_cast<Range*>(symbol);
            Class* canonicalClass = new Class(-1);
            canonicalClass->Ranges().push_back(*range);
            canonicalClasses.push_back(canonicalClass);
        }
    }
    for (Class* canonicalClass : canonicalClasses)
    {
        for (const Range& range : canonicalClass->Ranges())
        {
            if (canonicalClass->Chars().empty())
            {
                canonicalClass->AddChar(range.Start());
            }
            break;
        }
    }
}

struct ClassLess
{
    bool operator()(const Class* left, const Class* right) const
    {
        if (left->Ranges().size() < right->Ranges().size()) return false;
        if (left->Ranges().size() > right->Ranges().size()) return false;
        if (!left->Ranges().empty())
        {
            Range leftRange = left->Ranges().front();
            Range rightRange = right->Ranges().front();
            return leftRange < rightRange;
        }
        return false;
    }
};

struct ClassesEqual
{
    bool operator()(const Class* left, const Class* right) const
    {
        return left->Ranges() == right->Ranges();
    }
};

void LexerContext::MakeClassPartition()
{
    std::list<Class*> classes;
    for (Class* cls : canonicalClasses)
    {
        classes.push_back(cls);
    }
    auto classIt = classes.begin();
    while (classIt != classes.end())
    {
        bool classChanged = false;
        Class* cls = *classIt;
        auto sourceIt = classes.begin();
        while (!cls->Ranges().empty() && sourceIt != classes.end())
        {
            if (sourceIt == classIt)
            {
                ++sourceIt;
                continue;
            }
            bool sourceChanged = false;
            Class* source = *sourceIt;
            std::unique_ptr<Class> splitClass(new Class(-1));
            auto leftIt = cls->Ranges().begin();
            while (leftIt != cls->Ranges().end())
            {
                bool leftChanged = false;
                auto rightIt = source->Ranges().begin();
                while (leftIt != cls->Ranges().end() && rightIt != source->Ranges().end())
                {
                    bool rightChanged = false;
                    if (Intersect(*leftIt, *rightIt))
                    {
                        std::vector<Range> leftRanges = *leftIt - *rightIt;
                        std::vector<Range> rightRanges = *rightIt - *leftIt;
                        Range intersection = *leftIt & *rightIt;
                        for (const Range& leftRange : leftRanges)
                        {
                            if (leftRange.IsEmpty()) continue;
                            auto it = leftIt;
                            ++it;
                            cls->Ranges().insert(it, leftRange);
                        }
                        leftIt = cls->Ranges().erase(leftIt);
                        leftChanged = true;
                        if (!intersection.IsEmpty())
                        {
                            splitClass->Ranges().push_back(intersection);
                        }
                        for (const Range& rightRange : rightRanges)
                        {
                            if (rightRange.IsEmpty()) continue;
                            auto it = rightIt;
                            ++it;
                            source->Ranges().insert(it, rightRange);
                        }
                        rightIt = source->Ranges().erase(rightIt);
                        rightChanged = true;
                    }
                    if (!rightChanged)
                    {
                        ++rightIt;
                    }
                }
                if (!leftChanged)
                {
                    ++leftIt;
                }
            }
            if (source->Ranges().empty())
            {
                sourceIt = classes.erase(sourceIt);
                sourceChanged = true;
            }
            if (!splitClass->Ranges().empty())
            {
                classes.insert(sourceIt, splitClass.get());
                symbols.push_back(splitClass.release());
                sourceChanged = true;
            }
            if (!sourceChanged)
            {
                ++sourceIt;
            }
        }
        if (cls->Ranges().empty())
        {
            classIt = classes.erase(classIt);
            classChanged = true;
        }
        if (!classChanged)
        {
            ++classIt;
        }
    }
    for (Class* cls : classes)
    {
        cls->MakeMinimal(*this);
        partition.push_back(cls);
    }
    for (int i = 0; i < partition.size(); ++i)
    {
        Class* cls = partition[i];
        cls->SetIndex(i);
    }
}

void LexerContext::MakeClassMap(const std::string& root, bool verbose)
{
    std::vector<int> classMapVec(0x110000, -1);
    for (Class* cls : partition)
    {
        for (const Range& range : cls->Ranges())
        {
            for (char32_t i = range.Start(); i <= range.End(); ++i)
            {
                if (classMapVec[i] == -1)
                {
                    classMapVec[static_cast<int>(i)] = cls->Index();
                }
                else
                {
                    int x = 0;
                }
            }
        }
    }
    std::string classMapName = "ClassMap";
    if (classMap)
    {
        classMapName = ToUtf8(classMap->Name());
    }
    std::string classMapHeaderFileName = Path::Combine(root, "ClassMap.hpp");
    if (classMap)
    {
        classMapHeaderFileName = Path::Combine(root, ToUtf8(classMap->Name()) + ".hpp");
    }
    std::string classMapSourceFileName = Path::Combine(root, "ClassMap.cpp");
    if (classMap)
    {
        classMapSourceFileName = Path::Combine(root, ToUtf8(classMap->Name()) + ".cpp");
    }
    std::ofstream hppFile(classMapHeaderFileName);
    CodeFormatter hppFormatter(hppFile);
    hppFormatter.WriteLine("#ifndef " + classMapName + "_HPP");
    hppFormatter.WriteLine("#define " + classMapName + "_HPP");
    for (Include* include : Includes())
    {
        hppFormatter.WriteLine(ToUtf8(include->Header()));
    }
    hppFormatter.WriteLine();
    std::string api;
    if (!Api().empty())
    {
        api = ToUtf8(Api()) + " ";
    }
    hppFormatter.WriteLine("struct " + api + classMapName);
    hppFormatter.WriteLine("{");
    hppFormatter.IncIndent();
    hppFormatter.WriteLine("static int GetClass(char32_t c);");
    hppFormatter.DecIndent();
    hppFormatter.WriteLine("};");
    hppFormatter.WriteLine("#endif");
    if (verbose)
    {
        std::cout << "==> " << classMapHeaderFileName << std::endl;
    }
    std::ofstream cppFile(classMapSourceFileName);
    CodeFormatter cppFormatter(cppFile);
    std::string classMapHeaderName = "ClassMap.hpp";
    if (GetClassMap())
    {
        classMapHeaderName = ToUtf8(GetClassMap()->Name()) + ".hpp";
    }
    std::string classMapFileInclude = "#include \"" + classMapHeaderName + "\"";
    if (prefix)
    {
        classMapFileInclude = "#include <" + Path::Combine(ToUtf8(prefix->Name()), classMapHeaderName) + ">";
    }
    cppFormatter.WriteLine(classMapFileInclude);
    cppFormatter.WriteLine();
    cppFormatter.WriteLine("static int classMap[] = ");
    cppFormatter.WriteLine("{");
    cppFormatter.IncIndent();
    bool first = true;
    for (int i : classMapVec)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            cppFormatter.WriteLine(",");
        }
        cppFormatter.Write(std::to_string(i));
    }
    cppFormatter.WriteLine();
    cppFormatter.DecIndent();
    cppFormatter.WriteLine("};");
    cppFormatter.WriteLine();
    cppFormatter.WriteLine("int " + classMapName + "::GetClass(char32_t c)");
    cppFormatter.WriteLine("{");
    cppFormatter.IncIndent();
    cppFormatter.WriteLine("int i = static_cast<int>(c);");
    cppFormatter.WriteLine("if (i < 0x110000)");
    cppFormatter.WriteLine("{");
    cppFormatter.IncIndent();
    cppFormatter.WriteLine("return classMap[i];");
    cppFormatter.DecIndent();
    cppFormatter.WriteLine("}");
    cppFormatter.WriteLine("else");
    cppFormatter.WriteLine("{");
    cppFormatter.IncIndent();
    cppFormatter.WriteLine("return -1;");
    cppFormatter.DecIndent();
    cppFormatter.WriteLine("}");
    cppFormatter.DecIndent();
    cppFormatter.WriteLine("}");
    if (verbose)
    {
        std::cout << "==> " << classMapSourceFileName << std::endl;
    }
}

void LexerContext::AddInclude(Include* include)
{
    includes.push_back(include);
}

} } // namespace soulng::slg
