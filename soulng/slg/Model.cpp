// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/slg/Model.hpp>
#include <soulng/slg/LexerContext.hpp>
#include <soulng/slg/Algorithm.hpp>
#include <soulng/cppcode/Expression.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <fstream>
#include <iostream>

namespace soulng { namespace slg {

const char* LexerGeneratorVersionStr()
{
    return "3.0.0";
}

using namespace soulng::util;
using namespace soulng::unicode;

Parser::~Parser()
{
}

Declaration::Declaration(const std::u32string& name_) : name(name_)
{
}

Declaration::~Declaration()
{
}

ClassMap::ClassMap(const std::u32string& name_) : Declaration(name_)
{
}

void ClassMap::FillContext(LexerContext& lexerContext)
{
    lexerContext.SetClassMap(this);
}

void ClassMap::Process(const std::string& root, bool verbose, LexerContext& lexerContext)
{
}

Prefix::Prefix(const std::u32string& prefix_) : Declaration(prefix_)
{
}

void Prefix::FillContext(LexerContext& lexerContext)
{
    lexerContext.SetPrefix(this);
}

void Prefix::Process(const std::string& root, bool verbose, LexerContext& lexerContext)
{
}

Include::Include(const std::u32string& header_) : Declaration(U"include"), header(header_)
{
}

void Include::FillContext(LexerContext& lexerContext)
{
    lexerContext.AddInclude(this);
}

void Include::Process(const std::string& root, bool verbose, LexerContext& lexerContext)
{
}

Token::Token() : name(), info()
{
}

Token::Token(const std::u32string& name_, const std::string& info_) : name(name_), info(info_)
{
}

Tokens::Tokens(const std::u32string& name_) : Declaration(name_)
{
}

void Tokens::Add(const Token& token)
{
    tokens.push_back(token);
}

void Tokens::FillContext(LexerContext& lexerContext)
{
    lexerContext.SetTokens(this);
}

void Tokens::Process(const std::string& root, bool verbose, LexerContext& lexerContext)
{
    std::string tokenFileName = ToUtf8(Name()) + ".hpp";
    std::ofstream tokenFile(Path::Combine(root, tokenFileName));
    CodeFormatter formatter(tokenFile);
    formatter.WriteLine("#ifndef " + ToUtf8(Name()) + "_HPP");
    formatter.WriteLine("#define " + ToUtf8(Name()) + "_HPP");
    formatter.WriteLine();
    formatter.WriteLine("// this file has been automatically generated from '" + lexerContext.FileName() + "' using soulng lexer generator slg version " + LexerGeneratorVersionStr());
    formatter.WriteLine();
    for (Include* include : lexerContext.Includes())
    {
        formatter.WriteLine("#include <" + ToUtf8(include->Header()) + ">");
    }
    formatter.WriteLine("#include <string>");
    formatter.WriteLine();
    formatter.WriteLine("namespace " + ToUtf8(Name()));
    formatter.WriteLine("{");
    formatter.IncIndent();
    formatter.WriteLine("const int END = 0;");
    std::map<std::u32string, int> tokenIdMap;
    int i = 1;
    for (const auto& t : tokens)
    {
        tokenIdMap[t.name] = i;
        formatter.WriteLine("const int " + ToUtf8(t.name) + " = " + std::to_string(i++) + ";");
    }
    formatter.WriteLine();
    std::string api;
    if (!lexerContext.Api().empty())
    {
        api = ToUtf8(lexerContext.Api()) + " ";
    }
    formatter.WriteLine(api + "void InitTokenIdMap();");
    formatter.WriteLine(api + "int GetTokenId(const std::u32string& tokenName);");
    formatter.WriteLine(api + "const char* GetTokenName(int tokenId);");
    formatter.WriteLine(api + "const char* GetTokenInfo(int tokenId);");
    formatter.DecIndent();
    formatter.WriteLine("}");
    formatter.WriteLine("#endif");
    if (verbose)
    {
        std::cout << "==> " << Path::Combine(root, tokenFileName) << std::endl;
    }
    std::string tokenSourceFileName = Path::Combine(root, ToUtf8(Name()) + ".cpp");
    std::ofstream tokenSourceFile(tokenSourceFileName);
    CodeFormatter sourceFileFormatter(tokenSourceFile);
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.WriteLine("// this file has been automatically generated from '" + lexerContext.FileName() + "' using soulng lexer generator slg version " + LexerGeneratorVersionStr());
    sourceFileFormatter.WriteLine();
    std::string tokenFileInclude = "#include \"" + tokenFileName + "\"";
    if (lexerContext.GetPrefix())
    {
        tokenFileInclude = "#include <" + Path::Combine(ToUtf8(lexerContext.GetPrefix()->Name()), ToUtf8(Name()) + ".hpp") + ">";
    }
    sourceFileFormatter.WriteLine(tokenFileInclude);
    sourceFileFormatter.WriteLine("#include <map>");
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.WriteLine("namespace " + ToUtf8(Name()));
    sourceFileFormatter.WriteLine("{");
    sourceFileFormatter.IncIndent();
    sourceFileFormatter.WriteLine("std::map<std::u32string, int> tokenIdMap;");
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.WriteLine("void InitTokenIdMap()");
    sourceFileFormatter.WriteLine("{");
    sourceFileFormatter.IncIndent();
    for (const auto& p : tokenIdMap)
    {
        sourceFileFormatter.WriteLine("tokenIdMap[U\"" + ToUtf8(p.first) + "\"] = " + std::to_string(p.second) + ";");
    }
    sourceFileFormatter.DecIndent();
    sourceFileFormatter.WriteLine("}");
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.WriteLine("int GetTokenId(const std::u32string& tokenName)");
    sourceFileFormatter.WriteLine("{");
    sourceFileFormatter.IncIndent();
    sourceFileFormatter.WriteLine("auto it = tokenIdMap.find(tokenName);");
    sourceFileFormatter.WriteLine("if (it != tokenIdMap.cend())");
    sourceFileFormatter.WriteLine("{");
    sourceFileFormatter.IncIndent();
    sourceFileFormatter.WriteLine("return it->second;");
    sourceFileFormatter.DecIndent();
    sourceFileFormatter.WriteLine("}");
    sourceFileFormatter.WriteLine("else");
    sourceFileFormatter.WriteLine("{");
    sourceFileFormatter.IncIndent();
    sourceFileFormatter.WriteLine("return -1;");
    sourceFileFormatter.DecIndent();
    sourceFileFormatter.WriteLine("}");
    sourceFileFormatter.DecIndent();
    sourceFileFormatter.WriteLine("}");
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.WriteLine("const char* tokenName[] =");
    sourceFileFormatter.WriteLine("{");
    sourceFileFormatter.IncIndent();
    sourceFileFormatter.WriteLine("\"END\",");
    bool first = true;
    for (const auto& t : tokens)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            sourceFileFormatter.WriteLine(",");
        }
        sourceFileFormatter.Write("\"" + ToUtf8(t.name) + "\"");
    }
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.DecIndent();
    sourceFileFormatter.WriteLine("};");
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.WriteLine("const char* GetTokenName(int tokenId)");
    sourceFileFormatter.WriteLine("{");
    sourceFileFormatter.IncIndent();
    sourceFileFormatter.WriteLine("return tokenName[tokenId];");
    sourceFileFormatter.DecIndent();
    sourceFileFormatter.WriteLine("}");
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.WriteLine("const char* tokenInfo[] =");
    sourceFileFormatter.WriteLine("{");
    sourceFileFormatter.IncIndent();
    sourceFileFormatter.WriteLine("\"end of file\",");
    first = true;
    for (const auto& t : tokens)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            sourceFileFormatter.WriteLine(",");
        }
        sourceFileFormatter.Write("\"" + t.info + "\"");
    }
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.DecIndent();
    sourceFileFormatter.WriteLine("};");
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.WriteLine("const char* GetTokenInfo(int tokenId)");
    sourceFileFormatter.WriteLine("{");
    sourceFileFormatter.IncIndent();
    sourceFileFormatter.WriteLine("return tokenInfo[tokenId];");
    sourceFileFormatter.DecIndent();
    sourceFileFormatter.WriteLine("}");
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.WriteLine("struct Initializer");
    sourceFileFormatter.WriteLine("{");
    sourceFileFormatter.IncIndent();
    sourceFileFormatter.WriteLine("Initializer() { InitTokenIdMap(); }");
    sourceFileFormatter.DecIndent();
    sourceFileFormatter.WriteLine("};");
    sourceFileFormatter.WriteLine();
    sourceFileFormatter.WriteLine("Initializer initializer;");
    sourceFileFormatter.DecIndent();
    sourceFileFormatter.WriteLine("}");
    if (verbose)
    {
        std::cout << "==> " << tokenSourceFileName << std::endl;
    }
}

Keyword::Keyword(const std::u32string& kw_, const std::u32string& token_) : kw(kw_), token(token_)
{
}

Keywords::Keywords(const std::u32string& name_) : Declaration(name_)
{
}

void Keywords::Add(Keyword* keyword)
{
    keywords.push_back(std::unique_ptr<Keyword>(keyword));
}

void Keywords::FillContext(LexerContext& lexerContext)
{
    lexerContext.SetKeywords(this);
}

void Keywords::Process(const std::string& root, bool verbose, LexerContext& lexerContext)
{
    std::string api;
    if (!lexerContext.Api().empty())
    {
        api = ToUtf8(lexerContext.Api()) + " ";
    }
    std::string keywordsHeaderFileName = ToUtf8(Name()) + ".hpp";
    std::ofstream keywordsHeaderFile(Path::Combine(root, keywordsHeaderFileName));
    CodeFormatter headerFormatter(keywordsHeaderFile);
    headerFormatter.WriteLine("#ifndef " + ToUtf8(Name()) + "_HPP");
    headerFormatter.WriteLine("#define " + ToUtf8(Name()) + "_HPP");
    headerFormatter.WriteLine();
    headerFormatter.WriteLine("// this file has been automatically generated from '" + lexerContext.FileName() + "' using soulng lexer generator slg version " + LexerGeneratorVersionStr());
    headerFormatter.WriteLine();
    for (Include* include : lexerContext.Includes())
    {
        headerFormatter.WriteLine("#include <" + ToUtf8(include->Header()) + ">");
    }
    headerFormatter.WriteLine("#include <soulng/lexer/Keyword.hpp>");
    headerFormatter.WriteLine();
    headerFormatter.WriteLine("namespace " + ToUtf8(Name()));
    headerFormatter.WriteLine("{");
    headerFormatter.IncIndent();
    headerFormatter.WriteLine("using namespace soulng::lexer;");
    headerFormatter.WriteLine();
    headerFormatter.WriteLine(api + "KeywordMap* GetKeywordMap();");
    headerFormatter.DecIndent();
    headerFormatter.WriteLine("}");
    headerFormatter.WriteLine("#endif");
    if (verbose)
    {
        std::cout << "==> " << Path::Combine(root, keywordsHeaderFileName) << std::endl;
    }
    std::string keywordsSourceFileName = Path::Combine(root, ToUtf8(Name()) + ".cpp");
    std::ofstream keywordsSourceFile(keywordsSourceFileName);
    CodeFormatter sourceFormatter(keywordsSourceFile);
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("// this file has been automatically generated from '" + lexerContext.FileName() + "' using soulng lexer generator slg version " + LexerGeneratorVersionStr());
    sourceFormatter.WriteLine();
    std::string keywordsHeaderFileInclude = "#include \"" + keywordsHeaderFileName + "\"";
    if (lexerContext.GetPrefix())
    {
        keywordsHeaderFileInclude = "#include <" + Path::Combine(ToUtf8(lexerContext.GetPrefix()->Name()), ToUtf8(Name()) + ".hpp") + ">";
    }
    sourceFormatter.WriteLine(keywordsHeaderFileInclude);

    std::string tokenFileName = ToUtf8(lexerContext.GetTokens()->Name()) + ".hpp";
    std::string tokenFileInclude = "#include \"" + tokenFileName + "\"";
    if (lexerContext.GetPrefix())
    {
        tokenFileInclude = "#include <" + Path::Combine(ToUtf8(lexerContext.GetPrefix()->Name()), ToUtf8(lexerContext.GetTokens()->Name()) + ".hpp") + ">";
    }
    sourceFormatter.WriteLine(tokenFileInclude);
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("namespace " + ToUtf8(Name()));
    sourceFormatter.WriteLine("{");
    sourceFormatter.IncIndent();
    sourceFormatter.WriteLine("using namespace " + ToUtf8(lexerContext.GetTokens()->Name()) + ";");
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("Keyword keywords[] =");
    sourceFormatter.WriteLine("{");
    sourceFormatter.IncIndent();
    bool first = true;
    for (const auto& k : keywords)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            sourceFormatter.WriteLine(", ");
        }
        sourceFormatter.Write("{U\"" + ToUtf8(k->kw) + "\", " + ToUtf8(k->token) + "}");
    }
    if (!keywords.empty())
    {
        sourceFormatter.WriteLine(",");
    }
    sourceFormatter.WriteLine("{nullptr, -1}");
    sourceFormatter.DecIndent();
    sourceFormatter.WriteLine("};");
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("KeywordMap keywordMap(keywords);");
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("KeywordMap* GetKeywordMap()");
    sourceFormatter.WriteLine("{");
    sourceFormatter.IncIndent();
    sourceFormatter.WriteLine("return &keywordMap;");
    sourceFormatter.DecIndent();
    sourceFormatter.WriteLine("}");
    sourceFormatter.DecIndent();
    sourceFormatter.WriteLine("}");
    if (verbose)
    {
        std::cout << "==> " << keywordsSourceFileName << std::endl;
    }
}

Expression::Expression(int index_, const std::u32string& id_, const std::u32string& value_, int line_) : index(index_), id(id_), value(value_), line(line_)
{
}

Expressions::Expressions() : Declaration(U"expressions")
{
}

void Expressions::Add(Expression* expression) 
{
    expressions.push_back(std::unique_ptr<Expression>(expression));
    exprMap[expression->Id()] = expression->Index();
}

Expression* Expressions::Get(const std::u32string& id) const
{
    auto it = exprMap.find(id);
    if (it != exprMap.cend())
    {
        int index = it->second;
        return expressions[index].get();
    }
    else
    {
        throw std::runtime_error("expression '" + ToUtf8(id) + "' not found");
    }
}

void Expressions::FillContext(LexerContext& lexerContext)
{
    lexerContext.SetExpressions(this);
}

void Expressions::Process(const std::string& root, bool verbose, LexerContext& lexerContext)
{
}

Variable::Variable(soulng::cppcode::TypeId* type_, const std::u32string& name_) : type(type_), name(name_)
{
}

LexerStatement::LexerStatement(const std::u32string& expr_, soulng::cppcode::CompoundStatement* stmt_, int action_, int line_) :
    index(-1), expr(expr_), stmt(stmt_), retract(true), action(action_), line(line_)
{
}

void LexerStatement::Process(LexerContext& lexerContext)
{
    nfa = lexerContext.GetParser()->Parse(expr, &lexerContext, line);
    nfa.End()->SetStatementIndex(index);
}

Lexer::Lexer(const std::u32string& api_, const std::u32string& name_) : Declaration(name_), api(api_)
{
}

void Lexer::AddStatement(LexerStatement* stmt)
{
    stmt->SetIndex(statements.size());
    statements.push_back(std::unique_ptr<LexerStatement>(stmt));
}

void Lexer::AddVariable(Variable* variable)
{
    variables.push_back(std::unique_ptr<Variable>(variable));
}

void Lexer::AddAction(Action* action)
{
    actions.Add(action);
}

void Lexer::FillContext(LexerContext& lexerContext)
{
    lexerContext.SetApi(api);
    lexerContext.SetLexer(this);
}

void Lexer::Process(const std::string& root, bool verbose, LexerContext& lexerContext)
{
    for (const auto& statement : statements)
    {
        statement->Process(lexerContext);
    }
}

void Lexer::MakeMasterNfa(LexerContext& lexerContext)
{
    NfaState* start = lexerContext.MakeNfaState();
    masterNfa.SetStart(start);
    for (const auto& statement : statements)
    {
        start->AddEdge(NfaEdge(lexerContext.MakeEpsilon(), statement->GetNfa().Start()));
    }
}

void Lexer::MakeDfa(LexerContext& lexerContext)
{
    dfa = Compile(lexerContext, masterNfa);
}

void Lexer::WriteAutomaton(const std::string& root, bool verbose, LexerContext& lexerContext)
{
    std::string api;
    if (!lexerContext.Api().empty())
    {
        api = ToUtf8(lexerContext.Api()) + " ";
    }
    std::string lexerHeaderFileName = ToUtf8(Name()) + ".hpp";
    std::ofstream lexerHeaderFile(Path::Combine(root, lexerHeaderFileName));
    CodeFormatter headerFormatter(lexerHeaderFile);
    headerFormatter.WriteLine("#ifndef " + ToUtf8(Name()) + "_HPP");
    headerFormatter.WriteLine("#define " + ToUtf8(Name()) + "_HPP");
    headerFormatter.WriteLine();
    headerFormatter.WriteLine("// this file has been automatically generated from '" + lexerContext.FileName() + "' using soulng lexer generator slg version " + LexerGeneratorVersionStr());
    headerFormatter.WriteLine();
    for (Include* include : lexerContext.Includes())
    {
        headerFormatter.WriteLine("#include <" + ToUtf8(include->Header()) + ">");
    }
    headerFormatter.WriteLine("#include <soulng/lexer/Lexer.hpp>");
    headerFormatter.WriteLine();
    std::string comma;
    if (!variables.empty())
    {
        comma = ",";
    }
    headerFormatter.WriteLine("class " + api + ToUtf8(Name()) + " : public soulng::lexer::Lexer");
    headerFormatter.WriteLine("{");
    headerFormatter.WriteLine("public:");
    headerFormatter.IncIndent();
    headerFormatter.WriteLine(ToUtf8(Name()) + "(const std::u32string& content_, const std::string& fileName_, int fileIndex_);");
    headerFormatter.WriteLine(ToUtf8(Name()) + "(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);");
    headerFormatter.WriteLine("int NextState(int state, char32_t c) override;");
    for (const auto& variable : variables)
    {
        variable->GetType()->Print(headerFormatter);
        headerFormatter.Write(" ");
        headerFormatter.WriteLine(ToUtf8(variable->Name()) + ";");
    }
    headerFormatter.DecIndent();
    headerFormatter.WriteLine("private:");
    headerFormatter.IncIndent();
    headerFormatter.WriteLine("int GetTokenId(int statementIndex);");
    headerFormatter.DecIndent();
    headerFormatter.WriteLine("};");
    headerFormatter.WriteLine("#endif");
    if (verbose)
    {
        std::cout << "==> " << Path::Combine(root, lexerHeaderFileName) << std::endl;
    }
    std::string lexerSourceFileName = Path::Combine(root, ToUtf8(Name()) + ".cpp");
    std::ofstream lexerSourceFile(lexerSourceFileName);
    CodeFormatter sourceFormatter(lexerSourceFile);
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("// this file has been automatically generated from '" + lexerContext.FileName() + "' using soulng lexer generator slg version " + LexerGeneratorVersionStr());
    sourceFormatter.WriteLine();
    std::string lexerHeaderInclude = "#include \"" + lexerHeaderFileName + "\"";
    if (lexerContext.GetPrefix())
    {
        lexerHeaderInclude = "#include <" + Path::Combine(ToUtf8(lexerContext.GetPrefix()->Name()), ToUtf8(Name()) + ".hpp") + ">";
    }
    sourceFormatter.WriteLine(lexerHeaderInclude);
    if (lexerContext.GetKeywords())
    {
        std::string keywordsHeaderFileName = ToUtf8(lexerContext.GetKeywords()->Name()) + ".hpp";
        std::string keywordsFileInclude = "#include \"" + keywordsHeaderFileName + "\"";
        if (lexerContext.GetPrefix())
        {
            keywordsFileInclude = "#include <" + Path::Combine(ToUtf8(lexerContext.GetPrefix()->Name()), ToUtf8(lexerContext.GetKeywords()->Name()) + ".hpp") + ">";
        }
        sourceFormatter.WriteLine(keywordsFileInclude);
    }
    sourceFormatter.WriteLine("#include <soulng/lexer/Token.hpp>");
    std::string tokensFileInclude = "#include \"" + ToUtf8(lexerContext.GetTokens()->Name()) + ".hpp\"";
    if (lexerContext.GetPrefix())
    {
        tokensFileInclude = "#include <" + Path::Combine(ToUtf8(lexerContext.GetPrefix()->Name()), ToUtf8(lexerContext.GetTokens()->Name()) + ".hpp") + ">";
    }
    sourceFormatter.WriteLine(tokensFileInclude);
    std::string classMapName = "ClassMap";
    if (lexerContext.GetClassMap())
    {
        classMapName = ToUtf8(lexerContext.GetClassMap()->Name());
    }
    std::string classMapHeaderFileName = "ClassMap.hpp";
    if (lexerContext.GetClassMap())
    {
        classMapHeaderFileName = ToUtf8(lexerContext.GetClassMap()->Name()) + ".hpp";
    }
    std::string classMapFileInclude = "#include \"" + classMapHeaderFileName + "\"";
    if (lexerContext.GetPrefix())
    {
        classMapFileInclude = "#include <" + Path::Combine(ToUtf8(lexerContext.GetPrefix()->Name()), classMapHeaderFileName) + ">";
    }
    sourceFormatter.WriteLine(classMapFileInclude);
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("using namespace soulng::lexer;");
    sourceFormatter.WriteLine("using namespace " + ToUtf8(lexerContext.GetTokens()->Name()) + ";");
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine(ToUtf8(Name()) + "::" + ToUtf8(Name()) + "(const std::u32string& content_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(content_, fileName_, fileIndex_)" + comma);
    if (!variables.empty())
    {
        sourceFormatter.IncIndent();
        bool first = true;
        for (const auto& variable : variables)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                sourceFormatter.Write(", ");
            }
            sourceFormatter.Write(ToUtf8(variable->Name()) + "()");
        }
        sourceFormatter.WriteLine();
        sourceFormatter.DecIndent();
    }
    sourceFormatter.WriteLine("{");
    if (lexerContext.GetKeywords())
    {
        sourceFormatter.IncIndent();
        sourceFormatter.WriteLine("SetKeywordMap(" + ToUtf8(lexerContext.GetKeywords()->Name()) + "::GetKeywordMap());");
        sourceFormatter.DecIndent();
    }
    sourceFormatter.WriteLine("}");
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine(ToUtf8(Name()) + "::" + ToUtf8(Name()) + "(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_) : soulng::lexer::Lexer(start_, end_, fileName_, fileIndex_)" + comma);
    if (!variables.empty())
    {
        sourceFormatter.IncIndent();
        bool first = true;
        for (const auto& variable : variables)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                sourceFormatter.Write(", ");
            }
            sourceFormatter.Write(ToUtf8(variable->Name()) + "()");
        }
        sourceFormatter.WriteLine();
        sourceFormatter.DecIndent();
    }
    sourceFormatter.WriteLine("{");
    if (lexerContext.GetKeywords())
    {
        sourceFormatter.IncIndent();
        sourceFormatter.WriteLine("SetKeywordMap(" + ToUtf8(lexerContext.GetKeywords()->Name()) + "::GetKeywordMap());");
        sourceFormatter.DecIndent();
    }
    sourceFormatter.WriteLine("}");
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("int " + ToUtf8(Name()) + "::NextState(int state, char32_t c)");
    sourceFormatter.WriteLine("{");
    sourceFormatter.IncIndent();
    sourceFormatter.WriteLine("int i = " + classMapName + "::GetClass(c);");
    sourceFormatter.WriteLine("switch (state)");
    sourceFormatter.WriteLine("{");
    sourceFormatter.IncIndent();
    for (const auto& state : dfa.States())
    {
        sourceFormatter.WriteLine("case " + std::to_string(state->Id()) + ":");
        sourceFormatter.WriteLine("{");
        sourceFormatter.IncIndent();
        if (state->Accept())
        {
            sourceFormatter.WriteLine("Lexeme prevMatch = token.match;");
            sourceFormatter.WriteLine("token.match = lexeme;");
            sourceFormatter.WriteLine("int tokenId = GetTokenId(" + std::to_string(state->StatementIndex()) + ");");
            sourceFormatter.WriteLine("if (tokenId == CONTINUE_TOKEN)");
            sourceFormatter.WriteLine("{");
            sourceFormatter.IncIndent();
            sourceFormatter.WriteLine("token.id = tokenId;");
            sourceFormatter.WriteLine("return -1;");
            sourceFormatter.DecIndent();
            sourceFormatter.WriteLine("}");
            sourceFormatter.WriteLine("else if (tokenId != INVALID_TOKEN)");
            sourceFormatter.WriteLine("{");
            sourceFormatter.IncIndent();
            sourceFormatter.WriteLine("token.id = tokenId;");
            sourceFormatter.DecIndent();
            sourceFormatter.WriteLine("}");
            sourceFormatter.WriteLine("else");
            sourceFormatter.WriteLine("{");
            sourceFormatter.IncIndent();
            sourceFormatter.WriteLine("token.match = prevMatch;");
            sourceFormatter.DecIndent();
            sourceFormatter.WriteLine("}");
        }
        std::map<int, std::set<int>> m;
        for (Class* cls : lexerContext.Partition())
        {
            DfaState* next = state->Next(cls->Index());
            if (next != nullptr)
            {
                m[next->Id()].insert(cls->Index());
            }
        }
        if (m.empty())
        {
            sourceFormatter.WriteLine("return -1;");
        }
        else
        {
            sourceFormatter.WriteLine("switch (i)");
            sourceFormatter.WriteLine("{");
            sourceFormatter.IncIndent();
            for (const auto& p : m)
            {
                int n = p.first;
                const std::set<int>& s = p.second;
                for (int k : s)
                {
                    sourceFormatter.WriteLine("case " + std::to_string(k) + ":");
                }
                sourceFormatter.WriteLine("{");
                sourceFormatter.IncIndent();
                sourceFormatter.WriteLine("return " + std::to_string(n) + ";");
                sourceFormatter.DecIndent();
                sourceFormatter.WriteLine("}");
            }
            sourceFormatter.WriteLine("default:");
            sourceFormatter.WriteLine("{");
            sourceFormatter.IncIndent();
            sourceFormatter.WriteLine("return -1;");
            sourceFormatter.DecIndent();
            sourceFormatter.WriteLine("}");
            sourceFormatter.DecIndent();
            sourceFormatter.WriteLine("}");
        }
        sourceFormatter.DecIndent();
        sourceFormatter.WriteLine("}");
    }
    sourceFormatter.DecIndent();
    sourceFormatter.WriteLine("}");
    sourceFormatter.WriteLine("return -1;");
    sourceFormatter.DecIndent();
    sourceFormatter.WriteLine("}");
    sourceFormatter.WriteLine();
    sourceFormatter.WriteLine("int " + ToUtf8(Name()) + "::GetTokenId(int statementIndex)");
    sourceFormatter.WriteLine("{");
    sourceFormatter.IncIndent();
    sourceFormatter.WriteLine("switch (statementIndex)");
    sourceFormatter.WriteLine("{");
    sourceFormatter.IncIndent();
    for (const auto& statement : statements)
    {
        sourceFormatter.WriteLine("case " + std::to_string(statement->Index()) + ":");
        if (statement->Retract())
        {
            statement->Code()->InsertFront(new soulng::cppcode::ExpressionStatement(new soulng::cppcode::InvokeExpr(new soulng::cppcode::IdExpr(U"Retract"))), true);
        }
        if (statement->Action() != -1)
        {
            Action* action = actions.Get(statement->Action());
            if (action != nullptr)
            {
                for (const auto& s : action->Code()->Statements())
                {
                    statement->Code()->InsertFront(s, false);
                }
            }
            else
            {
                throw std::runtime_error("action " + std::to_string(statement->Action()) + " not found");
            }
        }
        statement->Code()->Add(new soulng::cppcode::BreakStatement());
        statement->Code()->Print(sourceFormatter);
    }
    sourceFormatter.DecIndent();
    sourceFormatter.WriteLine("}");
    sourceFormatter.WriteLine("return CONTINUE_TOKEN;");
    sourceFormatter.DecIndent();
    sourceFormatter.WriteLine("}");
    if (verbose)
    {
        std::cout << "==> " << lexerSourceFileName << std::endl;
    }
}

Action::Action(int id_, soulng::cppcode::CompoundStatement* stmt_) : id(id_), stmt(stmt_)
{
}

Actions::Actions() : Declaration(U"actions")
{
}

void Actions::FillContext(LexerContext& lexerContext)
{
}

void Actions::Process(const std::string& root, bool verbose, LexerContext& lexerContext)
{
}

void Actions::Add(Action* action)
{
    actions.push_back(std::unique_ptr<Action>(action));
    actionMap[action->Id()] = action;
}

Action* Actions::Get(int id) const
{
    auto it = actionMap.find(id);
    if (it != actionMap.cend())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

void LexerFile::Add(Declaration* declaration)
{
    declarations.push_back(std::unique_ptr<Declaration>(declaration));
    declarationMap[declaration->Name()] = declaration;
}

void LexerFile::Process(const std::string& root, bool verbose, bool debug, LexerContext& lexerContext)
{
    for (auto& d : declarations)
    {
        d->FillContext(lexerContext);
    }
    if (!lexerContext.GetTokens())
    {
        throw std::runtime_error("error: no tokens defined");
    }
    if (!lexerContext.GetLexer())
    {
        throw std::runtime_error("error: no lexer defined");
    }
    for (const auto& d : declarations)
    {
        d->Process(root, verbose, lexerContext);
    }
    lexerContext.MakeCanonicalClasses();
    lexerContext.MakeClassPartition(debug);
    lexerContext.MakeClassMap(root, verbose);
    lexerContext.GetLexer()->MakeMasterNfa(lexerContext);
    lexerContext.GetLexer()->MakeDfa(lexerContext);
    lexerContext.GetLexer()->WriteAutomaton(root, verbose, lexerContext);
}

} } // namespace soulng::slg

