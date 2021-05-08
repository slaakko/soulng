// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/PP.hpp>
#include <sngcpp20/pp/PPLexer.hpp>
#include <sngcpp20/pp/PPParser.hpp>
#include <sngcpp20/pp/PPTokens.hpp>
#include <sngcpp20/pp/TextTokens.hpp>
#include <sngcpp20/pp/TextLexer.hpp>
#include <sngcpp20/pp/Evaluator.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/lexer/CppKeywords.hpp>
#include <sngcpp20/lexer/CppTokens.hpp>
#include <sngcpp20/parser/ExpressionParser.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <iostream>

namespace sngcpp::pp {

using namespace soulng::util;
using namespace soulng::unicode;

const char32_t* ndebugStr = U"NDEBUG";
const soulng::lexer::Lexeme ndebug(ndebugStr, ndebugStr + 6);

static int textTokenCppTokenMap[TextTokens::MAX];
static int ppTokenTextTokenMap[PPTokens::MAX];

void InitTextTokenCppTokenMap()
{
    for (int i = 0; i < TextTokens::MAX; ++i)
    {
        textTokenCppTokenMap[i] = soulng::lexer::INVALID_TOKEN;
    }
    textTokenCppTokenMap[TextTokens::END] = CppTokens::END;
    textTokenCppTokenMap[TextTokens::ID] = CppTokens::ID;
    textTokenCppTokenMap[TextTokens::CHARLITERAL] = CppTokens::CHARLIT;
    textTokenCppTokenMap[TextTokens::STRINGLITERAL] = CppTokens::STRINGLIT;
    textTokenCppTokenMap[TextTokens::COLONCOLON] = CppTokens::COLONCOLON;
    textTokenCppTokenMap[TextTokens::COMMA] = CppTokens::COMMA;
    textTokenCppTokenMap[TextTokens::ASSIGN] = CppTokens::ASSIGN;
    textTokenCppTokenMap[TextTokens::MULASSIGN] = CppTokens::MULASSIGN;
    textTokenCppTokenMap[TextTokens::DIVASSIGN] = CppTokens::DIVASSIGN;
    textTokenCppTokenMap[TextTokens::REMASSIGN] = CppTokens::REMASSIGN;
    textTokenCppTokenMap[TextTokens::ADDASSIGN] = CppTokens::ADDASSIGN;
    textTokenCppTokenMap[TextTokens::SUBASSIGN] = CppTokens::SUBASSIGN;
    textTokenCppTokenMap[TextTokens::SHIFTRIGHTASSIGN] = CppTokens::SHIFTRIGHTASSIGN;
    textTokenCppTokenMap[TextTokens::SHIFTLEFTASSIGN] = CppTokens::SHIFTLEFTASSIGN;
    textTokenCppTokenMap[TextTokens::ANDASSIGN] = CppTokens::ANDASSIGN;
    textTokenCppTokenMap[TextTokens::XORASSIGN] = CppTokens::XORASSIGN;
    textTokenCppTokenMap[TextTokens::ORASSIGN] = CppTokens::ORASSIGN;
    textTokenCppTokenMap[TextTokens::QUEST] = CppTokens::QUEST;
    textTokenCppTokenMap[TextTokens::COLON] = CppTokens::COLON;
    textTokenCppTokenMap[TextTokens::OROR] = CppTokens::OROR;
    textTokenCppTokenMap[TextTokens::AMPAMP] = CppTokens::AMPAMP;
    textTokenCppTokenMap[TextTokens::OR] = CppTokens::OR;
    textTokenCppTokenMap[TextTokens::XOR] = CppTokens::XOR;
    textTokenCppTokenMap[TextTokens::AMP] = CppTokens::AMP;
    textTokenCppTokenMap[TextTokens::EQ] = CppTokens::EQ;
    textTokenCppTokenMap[TextTokens::NEQ] = CppTokens::NEQ;
    textTokenCppTokenMap[TextTokens::LEQ] = CppTokens::LEQ;
    textTokenCppTokenMap[TextTokens::GEQ] = CppTokens::GEQ;
    textTokenCppTokenMap[TextTokens::SPACESHIP] = CppTokens::SPACESHIP;
    textTokenCppTokenMap[TextTokens::LANGLE] = CppTokens::LANGLE;
    textTokenCppTokenMap[TextTokens::RANGLE] = CppTokens::RANGLE;
    textTokenCppTokenMap[TextTokens::SHIFTLEFT] = CppTokens::SHIFTLEFT;
    textTokenCppTokenMap[TextTokens::SHIFTRIGHT] = CppTokens::SHIFTRIGHT;
    textTokenCppTokenMap[TextTokens::PLUS] = CppTokens::PLUS;
    textTokenCppTokenMap[TextTokens::MINUS] = CppTokens::MINUS;
    textTokenCppTokenMap[TextTokens::STAR] = CppTokens::STAR;
    textTokenCppTokenMap[TextTokens::DIV] = CppTokens::DIV;
    textTokenCppTokenMap[TextTokens::MOD] = CppTokens::MOD;
    textTokenCppTokenMap[TextTokens::DOTSTAR] = CppTokens::DOTSTAR;
    textTokenCppTokenMap[TextTokens::ARROWSTAR] = CppTokens::ARROWSTAR;
    textTokenCppTokenMap[TextTokens::LPAREN] = CppTokens::LPAREN;
    textTokenCppTokenMap[TextTokens::RPAREN] = CppTokens::RPAREN;
    textTokenCppTokenMap[TextTokens::PLUSPLUS] = CppTokens::PLUSPLUS;
    textTokenCppTokenMap[TextTokens::MINUSMINUS] = CppTokens::MINUSMINUS;
    textTokenCppTokenMap[TextTokens::EXCLAMATION] = CppTokens::EXCLAMATION;
    textTokenCppTokenMap[TextTokens::TILDE] = CppTokens::TILDE;
    textTokenCppTokenMap[TextTokens::LBRACKET] = CppTokens::LBRACKET;
    textTokenCppTokenMap[TextTokens::RBRACKET] = CppTokens::RBRACKET;
    textTokenCppTokenMap[TextTokens::DOT] = CppTokens::DOT;
    textTokenCppTokenMap[TextTokens::ARROW] = CppTokens::ARROW;
    textTokenCppTokenMap[TextTokens::SEMICOLON] = CppTokens::SEMICOLON;
    textTokenCppTokenMap[TextTokens::ELLIPSES] = CppTokens::ELLIPSES;
    textTokenCppTokenMap[TextTokens::LBRACE] = CppTokens::LBRACE;
    textTokenCppTokenMap[TextTokens::RBRACE] = CppTokens::RBRACE;
}

void InitPPTokenTextTokenMap()
{
    for (int i = 0; i < PPTokens::MAX; ++i)
    {
        ppTokenTextTokenMap[i] = soulng::lexer::INVALID_TOKEN;
    }
    ppTokenTextTokenMap[PPTokens::END] = TextTokens::END;
    ppTokenTextTokenMap[PPTokens::DEFINED] = TextTokens::DEFINED;
    ppTokenTextTokenMap[PPTokens::ANGLEHEADERNAME] = TextTokens::ANGLEHEADERNAME;
    ppTokenTextTokenMap[PPTokens::QUOTEHEADERNAME] = TextTokens::QUOTEHEADERNAME;
    ppTokenTextTokenMap[PPTokens::PPNUMBER] = TextTokens::PPNUMBER;
    ppTokenTextTokenMap[PPTokens::CHARLITERAL] = TextTokens::CHARLITERAL;
    ppTokenTextTokenMap[PPTokens::STRINGLITERAL] = TextTokens::STRINGLITERAL;
    ppTokenTextTokenMap[PPTokens::CHAR] = TextTokens::CHAR;
    ppTokenTextTokenMap[PPTokens::ID] = TextTokens::ID;
    ppTokenTextTokenMap[PPTokens::COLONCOLON] = TextTokens::COLONCOLON;
    ppTokenTextTokenMap[PPTokens::COMMA] = TextTokens::COMMA;
    ppTokenTextTokenMap[PPTokens::ASSIGN] = TextTokens::ASSIGN;
    ppTokenTextTokenMap[PPTokens::MULASSIGN] = TextTokens::MULASSIGN;
    ppTokenTextTokenMap[PPTokens::DIVASSIGN] = TextTokens::DIVASSIGN;
    ppTokenTextTokenMap[PPTokens::REMASSIGN] = TextTokens::REMASSIGN;
    ppTokenTextTokenMap[PPTokens::ADDASSIGN] = TextTokens::ADDASSIGN;
    ppTokenTextTokenMap[PPTokens::SUBASSIGN] = TextTokens::SUBASSIGN;
    ppTokenTextTokenMap[PPTokens::SHIFTRIGHTASSIGN] = TextTokens::SHIFTRIGHTASSIGN;
    ppTokenTextTokenMap[PPTokens::SHIFTLEFTASSIGN] = TextTokens::SHIFTLEFTASSIGN;
    ppTokenTextTokenMap[PPTokens::ANDASSIGN] = TextTokens::ANDASSIGN;
    ppTokenTextTokenMap[PPTokens::XORASSIGN] = TextTokens::XORASSIGN;
    ppTokenTextTokenMap[PPTokens::ORASSIGN] = TextTokens::ORASSIGN;
    ppTokenTextTokenMap[PPTokens::QUEST] = TextTokens::QUEST;
    ppTokenTextTokenMap[PPTokens::COLON] = TextTokens::COLON;
    ppTokenTextTokenMap[PPTokens::OROR] = TextTokens::OROR;
    ppTokenTextTokenMap[PPTokens::AMPAMP] = TextTokens::AMPAMP;
    ppTokenTextTokenMap[PPTokens::OR] = TextTokens::OR;
    ppTokenTextTokenMap[PPTokens::XOR] = TextTokens::XOR;
    ppTokenTextTokenMap[PPTokens::AMP] = TextTokens::AMP;
    ppTokenTextTokenMap[PPTokens::EQ] = TextTokens::EQ;
    ppTokenTextTokenMap[PPTokens::NEQ] = TextTokens::NEQ;
    ppTokenTextTokenMap[PPTokens::LEQ] = TextTokens::LEQ;
    ppTokenTextTokenMap[PPTokens::GEQ] = TextTokens::GEQ;
    ppTokenTextTokenMap[PPTokens::SPACESHIP] = TextTokens::SPACESHIP;
    ppTokenTextTokenMap[PPTokens::LANGLE] = TextTokens::LANGLE;
    ppTokenTextTokenMap[PPTokens::RANGLE] = TextTokens::RANGLE;
    ppTokenTextTokenMap[PPTokens::SHIFTLEFT] = TextTokens::SHIFTLEFT;
    ppTokenTextTokenMap[PPTokens::SHIFTRIGHT] = TextTokens::SHIFTRIGHT;
    ppTokenTextTokenMap[PPTokens::PLUS] = TextTokens::PLUS;
    ppTokenTextTokenMap[PPTokens::MINUS] = TextTokens::MINUS;
    ppTokenTextTokenMap[PPTokens::STAR] = TextTokens::STAR;
    ppTokenTextTokenMap[PPTokens::DIV] = TextTokens::DIV;
    ppTokenTextTokenMap[PPTokens::MOD] = TextTokens::MOD;
    ppTokenTextTokenMap[PPTokens::DOTSTAR] = TextTokens::DOTSTAR;
    ppTokenTextTokenMap[PPTokens::ARROWSTAR] = TextTokens::ARROWSTAR;
    ppTokenTextTokenMap[PPTokens::LPAREN] = TextTokens::LPAREN;
    ppTokenTextTokenMap[PPTokens::RPAREN] = TextTokens::RPAREN;
    ppTokenTextTokenMap[PPTokens::PLUSPLUS] = TextTokens::PLUSPLUS;
    ppTokenTextTokenMap[PPTokens::MINUSMINUS] = TextTokens::MINUSMINUS;
    ppTokenTextTokenMap[PPTokens::EXCLAMATION] = TextTokens::EXCLAMATION;
    ppTokenTextTokenMap[PPTokens::TILDE] = TextTokens::TILDE;
    ppTokenTextTokenMap[PPTokens::LBRACKET] = TextTokens::LBRACKET;
    ppTokenTextTokenMap[PPTokens::RBRACKET] = TextTokens::RBRACKET;
    ppTokenTextTokenMap[PPTokens::DOT] = TextTokens::DOT;
    ppTokenTextTokenMap[PPTokens::ARROW] = TextTokens::ARROW;
    ppTokenTextTokenMap[PPTokens::SEMICOLON] = TextTokens::SEMICOLON;
    ppTokenTextTokenMap[PPTokens::ELLIPSES] = TextTokens::ELLIPSES;
    ppTokenTextTokenMap[PPTokens::LBRACE] = TextTokens::LBRACE;
    ppTokenTextTokenMap[PPTokens::RBRACE] = TextTokens::RBRACE;
}

std::vector<soulng::lexer::Token> MacroExpand(const std::vector<soulng::lexer::Token>& tokens, const PP* pp)
{
    bool prevWasMacro = false;
    std::vector<soulng::lexer::Token> expandedTokens;
    for (const soulng::lexer::Token& token : tokens)
    {
        if (token.id == TextTokens::ID)
        {
            auto it = pp->macroMap.find(token.match);
            if (it != pp->macroMap.cend())
            {
                const std::vector<soulng::lexer::Token>& replacementTokens = it->second;
                for (const soulng::lexer::Token& replacementToken : replacementTokens)
                {
                    expandedTokens.push_back(replacementToken);
                }
                prevWasMacro = true;
            }
            else
            {
                expandedTokens.push_back(token);
            }
        }
        else
        {
            if (prevWasMacro)
            {
                prevWasMacro = false;
                if (token.id != TextTokens::WS)
                {
                    expandedTokens.push_back(token);
                }
            }
            else
            {
                expandedTokens.push_back(token);
            }
        }
    }
    return expandedTokens;
}

std::vector<soulng::lexer::Token> ConvertPPTokensToTextTokens(const std::vector<soulng::lexer::Token>& ppTokens)
{
    std::vector<soulng::lexer::Token> textTokens;
    for (const soulng::lexer::Token& ppToken : ppTokens)
    {
        textTokens.push_back(std::move(soulng::lexer::Token(ppTokenTextTokenMap[ppToken.id], ppToken.match, ppToken.line)));
    }
    return textTokens;
}

const char32_t* zeroStr = U"0";
const soulng::lexer::Lexeme zeroLexeme(zeroStr, zeroStr + 1);
const soulng::lexer::Token zeroToken(CppTokens::INTLIT, zeroLexeme, 1);
const char32_t* oneStr = U"1";
const soulng::lexer::Lexeme oneLexeme(oneStr, oneStr + 1);
const soulng::lexer::Token oneToken(CppTokens::INTLIT, oneLexeme, 1);

std::vector<soulng::lexer::Token> ConvertTextTokensToCppTokens(const std::vector<soulng::lexer::Token>& textTokens, const PP* pp)
{
    std::vector<soulng::lexer::Token> cppTokens;
    int state = 0;
    for (const soulng::lexer::Token& textToken : textTokens)
    {
        switch (state)
        {
            case 0:
            {
                switch (textToken.id)
                {
                    case TextTokens::KEYWORD:
                    case TextTokens::ID:
                    {
                        cppTokens.push_back(zeroToken);
                        break;
                    }
                    case TextTokens::PPNUMBER:
                    {
                        CppLexer lexer(textToken.match.begin, textToken.match.end, std::string(), 0);
                        ++lexer;
                        cppTokens.push_back(*lexer);
                        break;
                    }
                    case TextTokens::DEFINED:
                    {
                        state = 1;
                        break;
                    }
                    default:
                    {
                        cppTokens.push_back(std::move(soulng::lexer::Token(textTokenCppTokenMap[textToken.id], textToken.match, textToken.line)));
                        break;
                    }
                }
                break;
            }
            case 1:
            {
                switch (textToken.id)
                {
                    case TextTokens::LPAREN:
                    {
                        state = 2;
                        break;
                    }
                    case TextTokens::ID:
                    {
                        if (pp->IsDefined(textToken.match))
                        {
                            cppTokens.push_back(oneToken);
                        }
                        else
                        {
                            cppTokens.push_back(zeroToken);
                        }
                        state = 0;
                        break;
                    }
                    default:
                    {
                        cppTokens.push_back(zeroToken);
                        state = 0;
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                switch (textToken.id)
                {
                    case TextTokens::ID:
                    {
                        if (pp->IsDefined(textToken.match))
                        {
                            cppTokens.push_back(oneToken);
                        }
                        else
                        {
                            cppTokens.push_back(zeroToken);
                        }
                        state = 3;
                        break;
                    }
                    default:
                    {
                        cppTokens.push_back(zeroToken);
                        state = 3;
                    }
                }
                break;
            }
            case 3:
            {
                if (textToken.id == TextTokens::RPAREN)
                {
                    state = 0;
                    break;
                }
                break;
            }
        }
    }
    return cppTokens;
}

PP::PP(EvaluationContext& context_) :
    fileIndex(0), save(true), process(true), processed(false), elseGroupProcessed(false), inIfGroup(false), verbose(false),
    projectHeaderFileSet(nullptr), root(GetCurrentWorkingDirectory()), line(1), context(context_), rootMode(false), tokens(nullptr)
{
}

PP::~PP()
{
}

std::vector<soulng::lexer::Token>* PP::BeginDefine(const soulng::lexer::Lexeme& id)
{
    if (process)
    {
        return &macroMap[id];
    }
    else
    {
        return nullptr;
    }
}

void PP::EndDefine(std::vector<soulng::lexer::Token>& tokens)
{
    if (process)
    {
        std::vector<soulng::lexer::Token> textTokens = ConvertPPTokensToTextTokens(tokens);
        std::swap(tokens, textTokens);
    }
}

void PP::Define(const soulng::lexer::Lexeme& lexeme)
{
    std::vector<soulng::lexer::Token>* def = BeginDefine(lexeme);
    EndDefine(*def);
}

void PP::Undef(const soulng::lexer::Lexeme& lexeme)
{
    if (process)
    {
        macroMap.erase(lexeme);
    }
}

bool PP::IsDefined(const soulng::lexer::Lexeme& lexeme) const
{
    return macroMap.find(lexeme) != macroMap.cend();
}

bool PP::IsKeywordToken(const soulng::lexer::Token& token) const
{
    soulng::lexer::KeywordMap* keywordMap = CppKeywords::GetKeywordMap();
    return keywordMap->GetKeywordToken(token.match) != soulng::lexer::INVALID_TOKEN;
}

bool PP::IsProjectHeaderFile(const std::string& headerFilePath) const
{
    if (projectHeaderFileSet)
    {
        return projectHeaderFileSet->IsProjectHeaderFile(headerFilePath);
    }
    return false;
}

void PP::Include(bool isAngleHeader, const std::string& headerName)
{
    bool found = false;
    std::string headerFilePath;
    if (isAngleHeader)
    {
        for (const std::string& includeDir : includePath)
        {
            headerFilePath = GetFullPath(Path::Combine(Path::Combine(root, includeDir), headerName));
            if (FileExists(headerFilePath))
            {
                found = true;
                break;
            }
        }
    }
    else
    {
        headerFilePath = GetFullPath(Path::Combine(root, headerName));
        if (FileExists(headerFilePath))
        {
            found = true;
        }
    }
    if (found)
    {
        if (IsProjectHeaderFile(headerFilePath) || rootMode && Path::GetDirectoryName(headerFilePath) == root)
        {
            bool prevSave = save;
            save = false;
            ++fileIndex;
            headerFilePaths.push_back(headerFilePath);
            Preprocess(headerFilePath, this);
            save = prevSave;
        }
    }
}

const char32_t* emptyStr = U"";

bool PP::Evaluate(const std::vector<soulng::lexer::Token>& exprPPTokens) const
{
    std::vector<soulng::lexer::Token> exprTextTokens = ConvertPPTokensToTextTokens(exprPPTokens);
    exprTextTokens = MacroExpand(exprTextTokens, this);
    std::vector<soulng::lexer::Token> cppTokens = ConvertTextTokensToCppTokens(exprTextTokens, this);
    CppLexer lexer(emptyStr, emptyStr, fileName, fileIndex);
    lexer.SetLine(line);
    lexer.SetTokens(cppTokens);
    sngcpp::symbols::Context ctx;
    std::unique_ptr<sngcpp::ast::Node> expr = ExpressionParser::Parse(lexer, &ctx);
    Evaluator evaluator(fileName, line, context);
    expr->Accept(evaluator);
    Value* value = evaluator.GetValue();
    BoolValue* boolValue = value->ToBool(context);
    return boolValue->GetValue();
}

void PP::If(const std::vector<soulng::lexer::Token>& exprPPTokens)
{
    processStack.push(process);
    bool processGroup = processStack.top() && Evaluate(exprPPTokens);
    process = processGroup;
    processedStack.push(processed);
    processed = process;
    inIfGroupStack.push(inIfGroup);
    inIfGroup = true;
    elseGroupProcessedStack.push(elseGroupProcessed);
    elseGroupProcessed = false;
}

void PP::Ifdef(bool defined)
{
    processStack.push(process);
    bool processGroup = processStack.top() && defined;
    process = processGroup;
    processedStack.push(processed);
    processed = process;
    inIfGroupStack.push(inIfGroup);
    inIfGroup = true;
    elseGroupProcessedStack.push(elseGroupProcessed);
    elseGroupProcessed = false;
}

void PP::Ifndef(bool defined)
{
    processStack.push(process);
    bool processGroup = processStack.top() && !defined;
    process = processGroup;
    processedStack.push(processed);
    processed = process;
    inIfGroupStack.push(inIfGroup);
    inIfGroup = true;
    elseGroupProcessedStack.push(elseGroupProcessed);
    elseGroupProcessed = false;
}

void PP::Elif(const std::vector<soulng::lexer::Token>& exprPPTokens)
{
    if (!inIfGroup)
    {
        throw std::runtime_error("error: " + fileName + ":" + std::to_string(line) + ": not in #if group");
    }
    if (processed)
    {
        process = false;
    }
    else
    {
        bool processGroup = Evaluate(exprPPTokens);
        process = processGroup;
        if (process)
        {
            processed = true;
        }
    }
}

void PP::Else()
{
    if (!inIfGroup)
    {
        throw std::runtime_error("error: " + fileName + ":" + std::to_string(line) + ": not in #if group");
    }
    if (elseGroupProcessed)
    {
        throw std::runtime_error("error: " + fileName + ":" + std::to_string(line) + ": duplicate #else group");
    }
    if (processStack.top())
    {
        if (!processed)
        {
            process = true;
            processed = true;
        }
        elseGroupProcessed = true;
    }
    else
    {
        process = false;
    }
}

void PP::Endif()
{
    if (!inIfGroup)
    {
        throw std::runtime_error("error: " + fileName + ":" + std::to_string(line) + ": not in #if group");
    }
    process = processStack.top();
    processStack.pop();
    processed = processedStack.top();
    processedStack.pop();
    elseGroupProcessed = elseGroupProcessedStack.top();
    elseGroupProcessedStack.pop();
    inIfGroup = inIfGroupStack.top();
    inIfGroupStack.pop();
}

void PP::Emit(const char32_t* s)
{
    if (save)
    {
        while (*s)
        {
            text.append(1, *s);
            ++s;
        }
    }
}

void PP::Emit(const soulng::lexer::Lexeme& lexeme)
{
    if (save)
    {
        const char32_t* p = lexeme.begin;
        const char32_t* e = lexeme.end;
        while (p != e)
        {
            text.append(1, *p);
            ++p;
        }
    }
}

void PP::Emit(const char32_t* s, const soulng::lexer::Lexeme& lexeme, int tokenID)
{
    Emit(s);
    soulng::lexer::Lexeme match;
    match.begin = lexeme.begin;
    match.end = lexeme.end;
    if (lexeme.end > lexeme.begin)
    {
        const char32_t* p = lexeme.end - 1;
        while (p != lexeme.begin && (*p == '\r' || *p == '\n'))
        {
            --p;
        }
        ++p;
        match.end = p;
    }
    tokens->push_back(soulng::lexer::Token(tokenID, match, line));
}

inline bool IsPPLine(const char32_t* p, const char32_t* e)
{
    while (p != e && (*p == ' ' || *p == '\t'))
    {
        ++p;
    }
    if (p != e && *p == '#') return true;
    return false;
}

inline void SkipLineEnd(const char32_t*& p, const char32_t* e)
{
    if (p != e && *p == '\r')
    {
        ++p;
    }
    if (p != e && *p == '\n')
    {
        ++p;
    }
}

void GetLine(const char32_t*& p, const char32_t* e, const char32_t*& begin, const char32_t*& end, int& numNewLines)
{
    numNewLines = 0;
    begin = p;
    end = e;
    int state = 0;
    while (p != e)
    {
        switch (state)
        {
            case 0:
            {
                switch (*p)
                {
                    case '\r': case '\n':
                    {
                        SkipLineEnd(p, e);
                        end = p;
                        return;
                    }
                    case '/':
                    {
                        state = 1;
                        break;
                    }
                    case '\\':
                    {
                        state = 6;
                        break;
                    }
                }
                break;
            }
            case 1:
            {
                switch (*p)
                {
                    case '\r': case '\n':
                    {
                        SkipLineEnd(p, e);
                        end = p;
                        return;
                    }
                    case '/':
                    {
                        state = 2;
                        break;
                    }
                    case '*':
                    {
                        state = 3;
                        break;
                    }
                    default:
                    {
                        state = 0;
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                switch (*p)
                {
                    case '\r': case '\n':
                    {
                        SkipLineEnd(p, e);
                        end = p;
                        return;
                    }
                }
                break;
            }
            case 3:
            {
                switch (*p)
                {
                    case '*':
                    {
                        state = 4;
                        break;
                    }
                    case '\n':
                    {
                        ++numNewLines;
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                switch (*p)
                {
                    case '*':
                    {
                        break;
                    }
                    case '/':
                    {
                        ++p;
                        end = p;
                        return;
                    }
                    case '\n':
                    {
                        ++numNewLines;
                        state = 3;
                        break;
                    }
                    default:
                    {
                        state = 3;
                        break;
                    }
                }
                break;
            }
            case 6:
            {
                switch (*p)
                {
                    case '\\':
                    {
                        break;
                    }
                    case '\r': 
                    {
                        state = 7;
                        break;
                    }
                    case '\n':
                    {
                        ++numNewLines;
                        state = 0;
                        break;
                    }
                    default:
                    {
                        state = 0;
                        break;
                    }
                }
                break;
            }
            case 7:
            {
                switch (*p)
                {
                    case '\r':
                    {
                        state = 7;
                        break;
                    }
                    case '\n':
                    {
                        ++numNewLines;
                        state = 0;
                        break;
                    }
                    case '\\':
                    {
                        state = 6;
                        break;
                    }
                    default:
                    {
                        state = 0;
                        break;
                    }
                }
                break;
            }
        }
        ++p;
    }
}

std::string ParseAngleHeaderName(const std::string& fileName, const soulng::lexer::Token& headerNameToken)
{
    const char32_t* p = headerNameToken.match.begin;
    const char32_t* e = headerNameToken.match.end;
    const char32_t* begin = p;
    const char32_t* end = e;
    if (p != e && *p == '<')
    {
        ++p;
        begin = p;
    }
    else
    {
        throw std::runtime_error("invalid header name in file '" + fileName + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString())));
    }
    while (p != e && *p != '>')
    {
        ++p;
    }
    if (p != e && *p == '>')
    {
        end = p;
        ++p;
    }
    else
    {
        throw std::runtime_error("invalid header name in file '" + fileName + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString())));
    }
    if (p == e)
    {
        return ToUtf8(std::u32string(begin, end));
    }
    else
    {
        throw std::runtime_error("invalid header name in file '" + fileName + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString())));
    }
}

std::string ParseQuoteHeaderName(const std::string& fileName, const soulng::lexer::Token& headerNameToken)
{
    const char32_t* p = headerNameToken.match.begin;
    const char32_t* e = headerNameToken.match.end;
    const char32_t* begin = p;
    const char32_t* end = e;
    if (p != e && *p == '"')
    {
        ++p;
        begin = p;
    }
    else
    {
        throw std::runtime_error("invalid header name in file '" + fileName + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString())));
    }
    while (p != e && *p != '"')
    {
        ++p;
    }
    if (p != e && *p == '"')
    {
        end = p;
        ++p;
    }
    else
    {
        throw std::runtime_error("invalid header name in file '" + fileName + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString())));
    }
    if (p == e)
    {
        return ToUtf8(std::u32string(begin, end));
    }
    else
    {
        throw std::runtime_error("invalid header name in file '" + fileName + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString())));
    }
}

void Preprocess(const std::string& fileName, PP* pp)
{
    int prevLine = pp->line;
    pp->line = 1;
    std::string prevFileName = pp->fileName;
    pp->fileName = fileName;
    std::u32string content = ToUtf32(ReadFile(fileName));
    content.append(1, '\n');
    File* file = new File(std::move(content));
    pp->files.push_back(std::unique_ptr<File>(file));
    const char32_t* p = file->content.c_str();
    const char32_t* e = file->content.c_str() + file->content.length();
    while (p != e)
    {
        const char32_t* begin = p;
        const char32_t* end = e;
        int numNewLines = 0;
        GetLine(p, e, begin, end, numNewLines);
        if (IsPPLine(begin, end))
        {
            PPLexer lexer(begin, end, fileName, pp->fileIndex);
            lexer.SetSeparatorChar('\n');
            lexer.pp = pp;
            lexer.SetLine(pp->line);
            lexer.SetCountLines(false);
            PPLineParser::Parse(lexer, pp);
            if (pp->save)
            {
                for (const char32_t* p = begin; p != end; ++p)
                {
                    if (*p != '\n' && *p != '\r')
                    {
                        pp->ctext.append(1, *p);
                    }
                }
            }
        }
        else if (pp->process)
        {
            TextLexer lexer(begin, end, fileName, pp->fileIndex);
            lexer.SetSeparatorChar('\n');
            lexer.pp = pp;
            lexer.SetLine(pp->line);
            lexer.SetCountLines(false);
            std::vector<soulng::lexer::Token> tokens;
            pp->tokens = &tokens;
            bool prevSave = pp->save;
            pp->save = false;
            ++lexer;
            int i = 0;
            while (*lexer != TextTokens::END)
            {
                tokens.push_back(lexer.GetToken(i++));
                ++lexer;
            }
            pp->save = prevSave;
            tokens = MacroExpand(tokens, pp);
            for (const soulng::lexer::Token& token : tokens)
            {
                if (token.id != TextTokens::BLOCKCOMMENT && token.id != TextTokens::LINECOMMENT)
                {
                    pp->Emit(token.match);
                }
                else
                {
                    pp->Emit(U" ");
                }
                if (pp->save)
                {
                    pp->ctext.append(token.match.ToString());
                }
            }
        }
        for (int i = 0; i < numNewLines; ++i)
        {
            pp->Emit(U"\n");
            ++pp->line;
        }
        pp->Emit(U"\n");
        if (pp->save)
        {
            pp->ctext.append(U"\n");
        }
        ++pp->line;
    }
    pp->fileName = prevFileName;
    pp->line = prevLine;
}

} // namespace sngcpp::pp
