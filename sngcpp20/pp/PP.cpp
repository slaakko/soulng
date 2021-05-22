// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/PP.hpp>
#include <sngcpp20/pp/Lines.hpp>
#include <sngcpp20/pp/Scan.hpp>
#include <sngcpp20/pp/PPLexer.hpp>
#include <sngcpp20/pp/PPParser.hpp>
#include <sngcpp20/pp/PPTokens.hpp>
#include <sngcpp20/pp/TextLexer.hpp>
#include <sngcpp20/pp/TextTokens.hpp>
#include <sngcpp20/pp/Util.hpp>
#include <sngcpp20/lexer/CppKeywords.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/lexer/CppTokens.hpp>
#include <sngcpp20/parser/LiteralTokenParser.hpp>
#include <sngcpp20/parser/ExpressionParser.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Time.hpp>
#include <soulng/util/Unicode.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

namespace sngcpp::pp {

using namespace soulng::util;
using namespace soulng::unicode;

PPSourceLocation::PPSourceLocation() : fileIndex(0), lineNumber(0)
{
}

PPSourceLocation::PPSourceLocation(int fileIndex_, int lineNumber_) : fileIndex(fileIndex_), lineNumber(lineNumber_)
{
}

Token CombineStringLitTokens(const Token& left, const Token& right, PP* pp)
{
    std::unique_ptr<sngcpp::ast::StringLiteralNode> leftNode(sngcpp::par::ParseStringLiteral(pp->GetSourcePos(), pp->FileName(), left.match.ToString()));
    sngcpp::ast::EncodingPrefix leftEncodingPrefix = leftNode->GetEncodingPrefix();
    std::unique_ptr<sngcpp::ast::StringLiteralNode> rightNode(sngcpp::par::ParseStringLiteral(pp->GetSourcePos(), pp->FileName(), right.match.ToString()));
    sngcpp::ast::EncodingPrefix rightEncodingPrefix = rightNode->GetEncodingPrefix();
    sngcpp::ast::EncodingPrefix commonEncodingPrefix = CommonEncodingPrefix(leftEncodingPrefix, rightEncodingPrefix);
    std::u32string rep = sngcpp::ast::EncodingPrefixStr(commonEncodingPrefix);
    rep.append(1, '"');
    rep.append(leftNode->Value());
    rep.append(rightNode->Value());
    rep.append(1, '"');
    Lexeme lexeme = pp->StringsRef().Install(std::move(rep));
    return Token(TextTokens::STRINGLITERAL, lexeme, left.line);
}

std::vector<Token> CombineAdjacentStringLiterals(const std::vector<Token>& tokens, PP* pp)
{
    std::vector<Token> combinedTokens;
    int n = tokens.size();
    int state = 0;
    if (n > 0)
    {
        for (int i = 0; i < n; ++i)
        {
            Token token = tokens[i];
            switch (state)
            {
                case 0:
                {
                    if (token.id == TextTokens::STRINGLITERAL || token.id == TextTokens::QUOTEHEADERNAME)
                    {
                        token.id = TextTokens::STRINGLITERAL;
                        combinedTokens.push_back(token);
                        state = 1;
                    }
                    else
                    {
                        combinedTokens.push_back(token);
                    }
                    break;
                }
                case 1:
                {
                    if (token.id == TextTokens::STRINGLITERAL || token.id == TextTokens::QUOTEHEADERNAME)
                    {
                        token.id = TextTokens::STRINGLITERAL;
                        std::vector<Token>::iterator p = combinedTokens.end() - 1;
                        while (p != combinedTokens.begin() && (p->id == TextTokens::WS || p->id == TextTokens::NEWLINE))
                        {
                            --p;
                        }
                        *p = CombineStringLitTokens(*p, token, pp);
                        combinedTokens.erase(p + 1, combinedTokens.end());
                    }
                    else if (token.id == TextTokens::WS || token.id == TextTokens::NEWLINE)
                    {
                        combinedTokens.push_back(token);
                    }
                    else
                    {
                        combinedTokens.push_back(token);
                        state = 0;
                    }
                    break;
                }
            }
        }
    }
    return combinedTokens;
}

class PPTokenToTextTokenMap
{
public:
    static void Init();
    static void Done();
    static PPTokenToTextTokenMap& Instance() { return *instance; }
    Token GetTextToken(const Token& ppToken) const;
private:
    PPTokenToTextTokenMap();
    static std::unique_ptr<PPTokenToTextTokenMap> instance;
    std::map<int, int> map;
};

std::unique_ptr<PPTokenToTextTokenMap> PPTokenToTextTokenMap::instance;

void PPTokenToTextTokenMap::Init()
{
    instance.reset(new PPTokenToTextTokenMap());
}

void PPTokenToTextTokenMap::Done()
{
    instance.reset();
}

PPTokenToTextTokenMap::PPTokenToTextTokenMap()
{
    map[PPTokens::END] = TextTokens::END;
    map[PPTokens::DEFINED] = TextTokens::DEFINED;
    map[PPTokens::ANGLEHEADERNAME] = TextTokens::ANGLEHEADERNAME;
    map[PPTokens::QUOTEHEADERNAME] = TextTokens::QUOTEHEADERNAME;
    map[PPTokens::PPNUMBER] = TextTokens::PPNUMBER;
    map[PPTokens::CHARLITERAL] = TextTokens::CHARLITERAL;
    map[PPTokens::STRINGLITERAL] = TextTokens::STRINGLITERAL;
    map[PPTokens::BEGINRAWSTRINGLITERAL] = TextTokens::BEGINRAWSTRINGLITERAL;
    map[PPTokens::BLOCKCOMMENT] = TextTokens::BLOCKCOMMENT;
    map[PPTokens::LINECOMMENT] = TextTokens::LINECOMMENT;
    map[PPTokens::WS] = TextTokens::WS;
    map[PPTokens::NEWLINE] = TextTokens::NEWLINE;
    map[PPTokens::HASHHASH] = TextTokens::HASHHASH;
    map[PPTokens::HASH] = TextTokens::HASH;
    map[PPTokens::CHAR] = TextTokens::CHAR;
    map[PPTokens::ID] = TextTokens::ID;
    map[PPTokens::COLONCOLON] = TextTokens::COLONCOLON;
    map[PPTokens::COMMA] = TextTokens::COMMA;
    map[PPTokens::ASSIGN] = TextTokens::ASSIGN;
    map[PPTokens::MULASSIGN] = TextTokens::MULASSIGN;
    map[PPTokens::DIVASSIGN] = TextTokens::DIVASSIGN;
    map[PPTokens::REMASSIGN] = TextTokens::REMASSIGN;
    map[PPTokens::ADDASSIGN] = TextTokens::ADDASSIGN;
    map[PPTokens::SUBASSIGN] = TextTokens::SUBASSIGN;
    map[PPTokens::SHIFTRIGHTASSIGN] = TextTokens::SHIFTRIGHTASSIGN;
    map[PPTokens::SHIFTLEFTASSIGN] = TextTokens::SHIFTLEFTASSIGN;
    map[PPTokens::ANDASSIGN] = TextTokens::ANDASSIGN;
    map[PPTokens::XORASSIGN] = TextTokens::XORASSIGN;
    map[PPTokens::ORASSIGN] = TextTokens::ORASSIGN;
    map[PPTokens::QUEST] = TextTokens::QUEST;
    map[PPTokens::COLON] = TextTokens::COLON;
    map[PPTokens::OROR] = TextTokens::OROR;
    map[PPTokens::AMPAMP] = TextTokens::AMPAMP;
    map[PPTokens::OR] = TextTokens::OR;
    map[PPTokens::XOR] = TextTokens::XOR;
    map[PPTokens::AMP] = TextTokens::AMP;
    map[PPTokens::EQ] = TextTokens::EQ;
    map[PPTokens::NEQ] = TextTokens::NEQ;
    map[PPTokens::LEQ] = TextTokens::LEQ;
    map[PPTokens::GEQ] = TextTokens::GEQ;
    map[PPTokens::SPACESHIP] = TextTokens::SPACESHIP;
    map[PPTokens::LANGLE] = TextTokens::LANGLE;
    map[PPTokens::RANGLE] = TextTokens::RANGLE;
    map[PPTokens::SHIFTLEFT] = TextTokens::SHIFTLEFT;
    map[PPTokens::SHIFTRIGHT] = TextTokens::SHIFTRIGHT;
    map[PPTokens::PLUS] = TextTokens::PLUS;
    map[PPTokens::MINUS] = TextTokens::MINUS;
    map[PPTokens::STAR] = TextTokens::STAR;
    map[PPTokens::DIV] = TextTokens::DIV;
    map[PPTokens::MOD] = TextTokens::MOD;
    map[PPTokens::DOTSTAR] = TextTokens::DOTSTAR;
    map[PPTokens::ARROWSTAR] = TextTokens::ARROWSTAR;
    map[PPTokens::LPAREN] = TextTokens::LPAREN;
    map[PPTokens::RPAREN] = TextTokens::RPAREN;
    map[PPTokens::PLUSPLUS] = TextTokens::PLUSPLUS;
    map[PPTokens::MINUSMINUS] = TextTokens::MINUSMINUS;
    map[PPTokens::EXCLAMATION] = TextTokens::EXCLAMATION;
    map[PPTokens::TILDE] = TextTokens::TILDE;
    map[PPTokens::LBRACKET] = TextTokens::LBRACKET;
    map[PPTokens::RBRACKET] = TextTokens::RBRACKET;
    map[PPTokens::LBRACE] = TextTokens::LBRACE;
    map[PPTokens::RBRACE] = TextTokens::RBRACE;
    map[PPTokens::DOT] = TextTokens::DOT;
    map[PPTokens::ARROW] = TextTokens::ARROW;
    map[PPTokens::SEMICOLON] = TextTokens::SEMICOLON;
    map[PPTokens::ELLIPSES] = TextTokens::ELLIPSES;
    map[PPTokens::OTHER] = TextTokens::OTHER;
}

Token PPTokenToTextTokenMap::GetTextToken(const Token& ppToken) const
{
    int id = TextTokens::OTHER;
    auto it = map.find(ppToken.id);
    if (it != map.cend())
    {
        id = it->second;
    }
    return Token(id, ppToken.match, ppToken.line);
}

Token ConvertPPTokenToTextToken(const Token& ppToken)
{
    return PPTokenToTextTokenMap::Instance().GetTextToken(ppToken);
}

class TextTokenToCppTokenMap
{
public:
    static void Init();
    static void Done();
    static TextTokenToCppTokenMap& Instance() { return *instance; }
    std::vector<Token> ConvertTextTokensToCppTokens(const std::vector<Token>& textTokens, PP* pp) const;
private:
    TextTokenToCppTokenMap();
    static std::unique_ptr<TextTokenToCppTokenMap> instance;
    std::map<int, int> map;
};

std::unique_ptr<TextTokenToCppTokenMap> TextTokenToCppTokenMap::instance;

void TextTokenToCppTokenMap::Init()
{
    instance.reset(new TextTokenToCppTokenMap());
}

void TextTokenToCppTokenMap::Done()
{
    instance.reset();
}

TextTokenToCppTokenMap::TextTokenToCppTokenMap()
{
    for (int tokenId = TextTokens::END; tokenId < TextTokens::MAX; ++tokenId)
    {
        map[tokenId] = INVALID_TOKEN;
    }
    map[TextTokens::END] = CppTokens::END;
    map[TextTokens::CHARLITERAL] = CppTokens::CHARLIT;
    map[TextTokens::STRINGLITERAL] = CppTokens::STRINGLIT;
    map[TextTokens::ID] = CppTokens::ID;
    map[TextTokens::COLONCOLON] = CppTokens::COLONCOLON;
    map[TextTokens::COMMA] = CppTokens::COMMA;
    map[TextTokens::ASSIGN] = CppTokens::ASSIGN;
    map[TextTokens::MULASSIGN] = CppTokens::MULASSIGN;
    map[TextTokens::DIVASSIGN] = CppTokens::DIVASSIGN;
    map[TextTokens::REMASSIGN] = CppTokens::REMASSIGN;
    map[TextTokens::ADDASSIGN] = CppTokens::ADDASSIGN;
    map[TextTokens::SUBASSIGN] = CppTokens::SUBASSIGN;
    map[TextTokens::SHIFTRIGHTASSIGN] = CppTokens::SHIFTRIGHTASSIGN;
    map[TextTokens::SHIFTLEFTASSIGN] = CppTokens::SHIFTLEFTASSIGN;
    map[TextTokens::ANDASSIGN] = CppTokens::ANDASSIGN;
    map[TextTokens::XORASSIGN] = CppTokens::XORASSIGN;
    map[TextTokens::ORASSIGN] = CppTokens::ORASSIGN;
    map[TextTokens::QUEST] = CppTokens::QUEST;
    map[TextTokens::COLON] = CppTokens::COLON;
    map[TextTokens::OROR] = CppTokens::OROR;
    map[TextTokens::AMPAMP] = CppTokens::AMPAMP;
    map[TextTokens::OR] = CppTokens::OR;
    map[TextTokens::XOR] = CppTokens::XOR;
    map[TextTokens::AMP] = CppTokens::AMP;
    map[TextTokens::EQ] = CppTokens::EQ;
    map[TextTokens::NEQ] = CppTokens::NEQ;
    map[TextTokens::LEQ] = CppTokens::LEQ;
    map[TextTokens::GEQ] = CppTokens::GEQ;
    map[TextTokens::SPACESHIP] = CppTokens::SPACESHIP;
    map[TextTokens::LANGLE] = CppTokens::LANGLE;
    map[TextTokens::RANGLE] = CppTokens::RANGLE;
    map[TextTokens::SHIFTLEFT] = CppTokens::SHIFTLEFT;
    map[TextTokens::SHIFTRIGHT] = CppTokens::SHIFTRIGHT;
    map[TextTokens::PLUS] = CppTokens::PLUS;
    map[TextTokens::MINUS] = CppTokens::MINUS;
    map[TextTokens::STAR] = CppTokens::STAR;
    map[TextTokens::DIV] = CppTokens::DIV;
    map[TextTokens::MOD] = CppTokens::MOD;
    map[TextTokens::DOTSTAR] = CppTokens::DOTSTAR;
    map[TextTokens::ARROWSTAR] = CppTokens::ARROWSTAR;
    map[TextTokens::LPAREN] = CppTokens::LPAREN;
    map[TextTokens::RPAREN] = CppTokens::RPAREN;
    map[TextTokens::PLUSPLUS] = CppTokens::PLUSPLUS;
    map[TextTokens::MINUSMINUS] = CppTokens::MINUSMINUS;
    map[TextTokens::EXCLAMATION] = CppTokens::EXCLAMATION;
    map[TextTokens::TILDE] = CppTokens::TILDE;
    map[TextTokens::LBRACKET] = CppTokens::LBRACKET;
    map[TextTokens::RBRACKET] = CppTokens::RBRACKET;
    map[TextTokens::LBRACE] = CppTokens::LBRACE;
    map[TextTokens::RBRACE] = CppTokens::RBRACE;
    map[TextTokens::DOT] = CppTokens::DOT;
    map[TextTokens::ARROW] = CppTokens::ARROW;
    map[TextTokens::SEMICOLON] = CppTokens::SEMICOLON;
    map[TextTokens::ELLIPSES] = CppTokens::ELLIPSES;
}

const char32_t* zeroLit = U"0";
const soulng::lexer::Lexeme zeroLexeme(zeroLit, zeroLit + 1);
const soulng::lexer::Token zeroToken(CppTokens::INTLIT, zeroLexeme, 1);

const char32_t* oneLit = U"1";
const soulng::lexer::Lexeme oneLexeme(oneLit, oneLit + 1);
const soulng::lexer::Token oneToken(CppTokens::INTLIT, oneLexeme, 1);

std::vector<Token> TextTokenToCppTokenMap::ConvertTextTokensToCppTokens(const std::vector<Token>& textTokens, PP* pp) const
{
    std::vector<Token> cppTokens;
    int state = 0;
    for (const Token& textToken : textTokens)
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
                        cppTokens.push_back(lexer.GetToken(lexer.GetPos()));
                        break;
                    }
                    case TextTokens::DEFINED:
                    {
                        state = 1;
                        break;
                    }
                    case TextTokens::WS:
                    {
                        break;
                    }
                    default:
                    {
                        auto it = map.find(textToken.id);
                        if (it != map.cend())
                        {
                            int id = it->second;
                            cppTokens.push_back(Token(id, textToken.match, textToken.line));
                        }
                        else
                        {
                            cppTokens.push_back(INVALID_TOKEN);
                        }
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
                        if (pp->IsMacroDefined(textToken.match))
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
                    case TextTokens::WS:
                    {
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
                        if (pp->IsMacroDefined(textToken.match))
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
                    case TextTokens::WS:
                    {
                        break;
                    }
                    default:
                    {
                        cppTokens.push_back(zeroToken);
                        state = 3;
                        break;
                    }
                }
                break;
            }
            case 3:
            {
                switch (textToken.id)
                {
                    case TextTokens::RPAREN:
                    {
                        state = 0;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
                break;
            }
        }
    }
    return cppTokens;
}

std::vector<Token> ConvertTextTokensToCppTokens(const std::vector<Token>& textTokens, PP* pp)
{
    return TextTokenToCppTokenMap::Instance().ConvertTextTokensToCppTokens(textTokens, pp);
}

PPResult::PPResult() : lineMapper(*this), empty(true), msvcMode(false)
{
}

PPResult::PPResult(std::vector<std::string>&& fileNames_, Strings&& strings_, std::vector<std::unique_ptr<LogicalPhysicalMapping>>&& logicalPhysicalMappings_, 
    std::map<int, PPSourceLocation>&& lineMap_, const Lexeme& resultText_, std::vector<std::string>&& errors_) :
    lineMapper(*this), fileNames(std::move(fileNames_)), strings(std::move(strings_)), logicalPhysicalMappings(std::move(logicalPhysicalMappings_)), lineMap(lineMap_), resultText(resultText_), 
    errors(std::move(errors_)), empty(false), msvcMode(false)
{
}

const PPSourceLocation* PPResult::GetSourceLocation(int line) const
{
    auto it = lineMap.find(line);
    if (it != lineMap.cend())
    {
        return &it->second;
    }
    else
    {
        return nullptr;
    }
}

std::string PPResult::GetFileName(int fileIndex) const
{
    if (fileIndex >= 0 && fileIndex < fileNames.size())
    {
        return fileNames[fileIndex];
    }
    else
    {
        return std::string();
    }
}

const LogicalPhysicalMapping* PPResult::GetMapping(int fileIndex) const
{
    if (fileIndex >= 0 && fileIndex < logicalPhysicalMappings.size())
    {
        return logicalPhysicalMappings[fileIndex].get();
    }
    else
    {
        return nullptr;
    }
}

std::string PPResult::GetSourceLine(int fileIndex, int lineNumber)
{
    const LogicalPhysicalMapping* mapping = GetMapping(fileIndex);
    if (mapping && lineNumber <= mapping->LogicalLines().Count())
    {
        Lexeme line = mapping->LogicalLines()[lineNumber - 1];
        return ToUtf8(line.ToString());
    }
    else
    {
        return std::string();
    }
}

PPLineMapper::PPLineMapper(PPResult& ppResult_) : ppResult(ppResult_)
{
}

SourceInfo PPLineMapper::GetSourceInfo(int line)
{
    const PPSourceLocation* sourceLocation = ppResult.GetSourceLocation(line);
    if (sourceLocation && sourceLocation->lineNumber)
    {
        SourceInfo sourceInfo;
        sourceInfo.fileName = ppResult.GetFileName(sourceLocation->fileIndex);
        sourceInfo.lineNumber = sourceLocation->lineNumber;
        sourceInfo.sourceLine = ppResult.GetSourceLine(sourceLocation->fileIndex, sourceLocation->lineNumber);
        return sourceInfo;
    }
    else
    {
        return SourceInfo();
    }
}

PP::PP(EvaluationContext& evaluationContext_) : evaluationContext(evaluationContext_), fileIndex(-1), skip(false), lineNumber(1), level(0), lineIndex(0), skipToEnd(false)
{
    space = strings.Install(U" ");
    std::string date = GetCurrentDate().ToString();
    std::string dateTime = GetCurrentDateTime().ToString();
    std::string time = dateTime.substr(11);
    DefineObjectMacro(U"__DATE__", ToUtf32(date));
    DefineObjectMacro(U"__TIME__", ToUtf32(time));
    fileMacro.reset(new ObjectMacro(strings.Install(U"__FILE__"), "", 0, std::vector<Token>(), std::u32string()));
    lineMacro.reset(new ObjectMacro(strings.Install(U"__LINE__"), "", 0, std::vector<Token>(), std::u32string()));
    sngcppMSVCModeMacroName = strings.Install(U"__SNGCPP_MSVC_MODE");
}

bool PP::IsKeywordToken(const Token& token) const
{
    soulng::lexer::KeywordMap* keywordMap = CppKeywords::GetKeywordMap();
    return keywordMap->GetKeywordToken(token.match) != soulng::lexer::INVALID_TOKEN;
}

Macro* PP::GetMacro(const Lexeme& name) const
{
    auto it = macroMap.find(name);
    if (it != macroMap.cend())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

std::vector<Token> PP::MacroExpand(const std::vector<Token>& tokens)
{
    return MacroExpand(tokens, false);
}

std::vector<Token> PP::MacroExpand(const std::vector<Token>& tokens, bool saveDefined)
{
    std::set<Macro*> expandedMacros;
    std::vector<Token>::const_iterator i = tokens.cbegin();
    std::vector<Token>::const_iterator e = tokens.cend();
    std::vector<Token> expandedTokens;
    std::vector<Token> tokensToProcess;
    bool expanded = true;
    bool definedSeen = false;
    bool recursive = false;
    while (expanded)
    {
        expanded = false;
        std::set<Macro*> loopExpandedMacros;
        while (i != e)
        {
            Token token = *i;
            switch (token.id)
            {
                case TextTokens::ID:
                {
                    if (saveDefined && definedSeen)
                    {
                        expandedTokens.push_back(token);
                        definedSeen = false;
                    }
                    else
                    {
                        Macro* macro = GetMacro(token.match);
                        if (macro)
                        {
                            if (!recursive || expandedMacros.find(macro) == expandedMacros.cend())
                            {
                                i = macro->Expand(i, e, expandedTokens, this);
                                expanded = true;
                                loopExpandedMacros.insert(macro);
                            }
                            else
                            {
                                expandedTokens.push_back(token);
                            }
                        }
                        else
                        {
                            expandedTokens.push_back(token);
                        }
                    }
                    break;
                }
                case TextTokens::DEFINED:
                {
                    expandedTokens.push_back(token);
                    definedSeen = true;
                    break;
                }
                default:
                {
                    expandedTokens.push_back(token);
                    break;
                }
            }
            if (i != e)
            {
                ++i;
            }
        }
        if (expanded)
        {
            for (const auto& macro : loopExpandedMacros)
            {
                expandedMacros.insert(macro);
            }
            tokensToProcess.clear();
            std::swap(expandedTokens, tokensToProcess);
            tokensToProcess = ConcatenateTokens(tokensToProcess, this);
            i = tokensToProcess.cbegin();
            e = tokensToProcess.cend();
            recursive = true;
        }
    }
    return expandedTokens;
}

void PP::AddError(const std::string& error)
{
    errors.push_back(error);
}

void PP::AddToken(const Token& token)
{
    tokens.push_back(token);
}

Lexeme PP::EmitText()
{
    std::u32string text;
    for (const Token& token : tokens)
    {
        text.append(token.match.ToString());
    }
    return strings.Install(std::move(text));
}

void PP::SetFile(const std::string& file_)
{
    fileStr = ToUtf32(file_);
    fileMacro->SetValue(Token(TextTokens::STRINGLITERAL, Lexeme(fileStr.c_str(), fileStr.c_str() + fileStr.length()), 1));
}

void PP::SetLine(int line_)
{
    lineStr = ToUtf32(std::to_string(line_));
    lineMacro->SetValue(Token(TextTokens::PPNUMBER, Lexeme(lineStr.c_str(), lineStr.c_str() + lineStr.length()), 1));
}

void PP::PushLineIndex()
{
    lineIndexStack.push(lineIndex);
}

void PP::PopLineIndex()
{
    lineIndex = lineIndexStack.top();
    lineIndexStack.pop();
}

void PP::PushLineNumber()
{
    lineNumberStack.push(lineNumber);
}

void PP::PopLineNumber()
{
    lineNumber = lineNumberStack.top();
    lineNumberStack.pop();
}

void PP::AddProcessedHeader(const std::string& header)
{
    processedHeaders.insert(header);
}

bool PP::IsHeaderProcessed(const std::string& header) const
{
    return processedHeaders.find(header) != processedHeaders.cend();
}

void PP::AddFileName(const std::string& fileName)
{
    fileNames.push_back(fileName);
}

void PP::AddLogicalPhysicalMapping(std::unique_ptr<LogicalPhysicalMapping>&& mapping)
{
    logicalPhysicalMappings.push_back(std::move(mapping));
}

void PP::DefineObjectMacro(const Lexeme& name, const std::vector<Token>& replacementList, const std::u32string& definitionStr)
{
    Macro* prevMacro = GetMacro(name);
    if (prevMacro)
    {
        if (prevMacro->IsObjectMacro())
        {
            ObjectMacro* objectMacro = static_cast<ObjectMacro*>(prevMacro);
            if (definitionStr != objectMacro->DefinitionStr())
            {
                std::string error = "error: object macro '" + ToUtf8(name.ToString()) + "' definition not equal to previous definition: " + fileName + ":" + std::to_string(lineNumber);
                error.append("\nnote: previous definition was in '" + prevMacro->FileName() + ":" + std::to_string(prevMacro->LineNumber()) + "'");
                AddError(error);
            }
        }
        else if (prevMacro->IsFunctionMacro())
        {
            std::string error = "error: object macro '" + ToUtf8(name.ToString()) + "' definition not equal to previous definition: note: previous was function macro: " + 
                fileName + ":" + std::to_string(lineNumber);
            error.append("\nnote: previous definition was in '" + prevMacro->FileName() + ":" + std::to_string(prevMacro->LineNumber()) + "'");
            AddError(error);
        }
    }
    else
    {
        std::vector<Token> definition = MacroExpand(replacementList);
        if (ContainsHash(definition))
        {
            std::string error = "error: replacement list of an object macro cannot contain the # operator: " + fileName + ":" + std::to_string(lineNumber);
            AddError(error);
        }
        else if (ContainsHashHash(definition))
        {
            std::string error = "error: replacement list of an object macro cannot contain the ## operator: " + fileName + ":" + std::to_string(lineNumber);
            AddError(error);
        }
        std::unique_ptr<Macro> macro(new ObjectMacro(name, fileName, lineNumber, definition, definitionStr));
        macroMap[name] = macro.get();
        macros.push_back(std::move(macro));
    }
}

void PP::DefineFunctionMacro(const Lexeme& name, const std::vector<Token>& paramList, const std::vector<Token>& replacementList, const std::u32string& definitionStr)
{
    Macro* prevMacro = GetMacro(name);
    if (prevMacro)
    {
        if (prevMacro->IsObjectMacro())
        {
            std::string error = "error: function macro '" + ToUtf8(name.ToString()) + "' definition not equal to previous definition: note: previous was object macro: " + 
                fileName + ":" + std::to_string(lineNumber);
            error.append("\nnote: previous definition was in '" + prevMacro->FileName() + ":" + std::to_string(prevMacro->LineNumber()) + "'");
            AddError(error);
        }
        else if (prevMacro->IsFunctionMacro())
        {
            FunctionMacro* functionMacro = static_cast<FunctionMacro*>(prevMacro);
            if (ToString(functionMacro->Parameters()) != ToString(paramList))
            {
                std::string error = "error: function macro '" + ToUtf8(name.ToString()) + "' definition not equal to previous definition: " + fileName + ":" + std::to_string(lineNumber);
                error.append("\nnote: parameter lists differ: note: previous definition in '" + prevMacro->FileName() + ":" + std::to_string(prevMacro->LineNumber()) + "'");
                AddError(error);
            }
            else if (functionMacro->DefinitionStr() != definitionStr)
            {
                std::string error = "error: function macro '" + ToUtf8(name.ToString()) + "' definition not equal to previous definition: " + fileName + ":" + std::to_string(lineNumber);
                error.append("\nnote: definitions differ: note: previous definition was in '" + prevMacro->FileName() + ":" + std::to_string(prevMacro->LineNumber()) + "'");
                AddError(error);
            }
        }
    }
    else
    {
        std::vector<Token> definition = MacroExpand(replacementList);
        std::unique_ptr<FunctionMacro> macro(new FunctionMacro(name, fileName, lineNumber, paramList, definition, definitionStr, this));
        if (!macro->MakeParamIndexMap())
        {
            std::string error = "error: duplicate identifier in parameter list of function macro '" + ToUtf8(macro->Name().ToString()) + "' : " + fileName + ":" + std::to_string(lineNumber);
            AddError(error);
        }
        else
        {
            macroMap[name] = macro.get();
            macros.push_back(std::move(macro));
        }
    }
}

void PP::DefineObjectMacro(const std::u32string& name, const std::u32string& value)
{
    std::u32string nm = name;
    Lexeme macroName = strings.Install(std::move(nm));
    if (!value.empty())
    {
        std::u32string replacementText = value;
        Lexeme replacement = strings.Install(std::move(replacementText));
        PPLexer lexer(replacement.begin, replacement.end, fileName, fileIndex);
        ++lexer;
        std::vector<Token> replacementList;
        ParseReplacementList(lexer, replacementList);
        DefineObjectMacro(macroName, replacementList, value);
    }
    else
    {
        DefineObjectMacro(macroName, std::vector<Token>(), std::u32string());
    }
}

void PP::Undefine(const Lexeme& name)
{
    macroMap.erase(name);
}

void PP::Line(const std::vector<Token>& tokens)
{
    // todo
}

void PP::Error(const std::vector<Token>& tokens)
{
    // todo
}

void PP::Pragma(const std::vector<Token>& tokens)
{
    if (IsMacroDefined(sngcppMSVCModeMacroName))
    {
        if (tokens.size() == 1 && tokens.front().match.ToString() == U"once")
        {
            if (IsHeaderProcessed(fileName))
            {
                SetSkipToEnd();
            }
            else
            {
                AddProcessedHeader(fileName);
            }
        }
    }
}

struct IncludeGuard
{
    IncludeGuard(PP* pp_) : pp(pp_)
    {
        pp->PushLineIndex();
        pp->PushLineNumber();
    }
    ~IncludeGuard()
    {
        pp->PopLineNumber();
        pp->PopLineIndex();
    }
    PP* pp;
};

void PP::Include(const std::vector<Token>& tokens)
{
    std::string headerName;
    bool parse = true;
    bool expanded = false;
    bool searchCurrentDir = false;
    if (!tokens.empty())
    {
        Token token = tokens.front();
        while (parse)
        {
            if (token.id == TextTokens::ANGLEHEADERNAME)
            {
                headerName = ParseAngleHeaderName(token, this);
                parse = false;
            }
            else if (token.id == TextTokens::QUOTEHEADERNAME)
            {
                headerName = ParseQuoteHeaderName(token, this);
                searchCurrentDir = true;
                parse = false;
            }
            else 
            {
                if (expanded)
                {
                    parse = false;
                }
                else
                {
                    expanded = true;
                    std::vector<Token> replacementTokens = TrimTextTokens(MacroExpand(tokens));
                    if (!replacementTokens.empty())
                    {
                        token = replacementTokens.front();
                    }
                    else
                    {
                        parse = false;
                    }
                }
            }
        }
    }
    if (!headerName.empty())
    {
        for (const std::string& includePath : includePaths)
        {
            std::string filePath = GetFullPath(Path::Combine(includePath, headerName));
            if (boost::filesystem::exists(filePath))
            {
                IncludeGuard guard(this);
                Preprocess(filePath, this);
                return;
            }
        }
        if (searchCurrentDir)
        {
            std::string filePath = GetFullPath(Path::Combine(Path::GetDirectoryName(fileName), headerName));
            if (boost::filesystem::exists(filePath))
            {
                IncludeGuard guard(this);
                Preprocess(filePath, this);
                return;
            }
        }
        std::string error = "include file name '" + headerName + "' not found: " + fileName + ":" + std::to_string(lineNumber);
        AddError(error);
    }
    else
    {
        std::string error = "invalid include directive: " + fileName + ":" + std::to_string(lineNumber);
        AddError(error);
    }
}

bool PP::IsMacroDefined(const Lexeme& macroName) const
{
    return macroMap.find(macroName) != macroMap.cend();
}

void PP::Ifdef(const Token& id)
{
    skipStack.push(skip);
    if (!skip)
    {
        bool defined = IsMacroDefined(id.match);
        skip = !defined;
    }
}

void PP::Ifndef(const Token& id)
{
    skipStack.push(skip);
    if (!skip)
    {
        bool defined = IsMacroDefined(id.match);
        skip = defined;
    }
}

void PP::If(const std::vector<Token>& tokens)
{
    skipStack.push(skip);
    if (!skip)
    {
        bool cond = Evaluate(tokens);
        skip = !cond;
    }
}

void PP::Elif(const std::vector<Token>& tokens)
{
    if (!skipStack.top() && skip)
    {
        bool cond = Evaluate(tokens);
        skip = !cond;
    }
}

void PP::Else()
{
    if (!skipStack.top() && skip)
    {
        skip = false;
    }
}

void PP::EndIf()
{
    skip = skipStack.top();
    skipStack.pop();
}

bool PP::Evaluate(const std::vector<Token>& tokens)
{
    try
    {
        std::vector<Token> conditionTextTokens = MacroExpand(tokens, true);
        std::vector<Token> conditionCppTokens = ConvertTextTokensToCppTokens(conditionTextTokens, this);
        CppLexer lexer(std::u32string(), fileName, fileIndex);
        lexer.SetLine(lineNumber);
        lexer.SetTokens(conditionCppTokens);
        sngcpp::symbols::Context ctx;
        std::unique_ptr<sngcpp::ast::Node> expr = ExpressionParser::Parse(lexer, &ctx);
        bool value = EvaluateBooleanConstantExpression(expr.get(), evaluationContext, this);
        return value;
    }
    catch (const std::exception& ex)
    {
        AddError(ex.what());
    }
    return false;
}

void PP::AddIncludePath(const std::string& includePath)
{
    includePaths.push_back(includePath);
}

void PP::PushFileName(const std::string& fileName_)
{
    fileNameStack.push(fileName);
    fileName = fileName_;
}

void PP::PopFileName()
{
    fileName = fileNameStack.top();
    fileNameStack.pop();
}

SourcePos PP::GetSourcePos() const
{
    return SourcePos(-1, lineNumber, 1);
}

void PP::PrintMacros()
{
    std::u32string macroText;
    for (const auto& macro : macroMap)
    {
        macroText.append(U"#define ").append(ToUtf32(macro.second->ToString())).append(1, '\n');
    }
}

void PP::MapLine(int lineNumber, const PPSourceLocation& sourceLocation)
{
    lineMap[lineNumber] = sourceLocation;
}

std::unique_ptr<PPResult> Preprocess(const std::string& fileName, PP* pp)
{
    try
    {
        pp->AddFileName(fileName);
        pp->IncFileIndex();
        pp->SetFile(fileName);
        pp->IncLevel();
        pp->PushFileName(fileName);
        Lexeme fileContent = pp->StringsRef().Install(ToUtf32(ReadFile(fileName)));
        pp->AddLogicalPhysicalMapping(MapLines(fileContent, pp));
        LogicalPhysicalMapping* lineMapping = pp->CurrentLogicalPhysicalMapping();
        const Lines& lines = lineMapping->LogicalLines();
        int lineIndex = 0;
        while (lineIndex < lines.Count())
        {
            pp->SetLineIndex(lineIndex);
            pp->SetLine(lineIndex + 1);
            Lexeme line = lines[lineIndex];
            if (IsPPLine(line))
            {
                PPLexer lexer(line.begin, lines.End(), fileName, pp->FileIndex());
                lexer.SetLine(pp->LineNumber());
                lexer.SetCountLines(false);
                lexer.pp = pp;
                ++lexer;
                ParseControlLine(lexer);
                lineIndex = pp->GetLineIndex();
                if (pp->SkipToEnd())
                {
                    pp->ResetSkipToEnd();
                    lineIndex = lines.Count();
                    continue;
                }
            }
            else if (!pp->Skip())
            {
                PPSourceLocation ppSourceLocation(pp->FileIndex(), lineIndex + 1);
                pp->MapLine(pp->LineNumber(), ppSourceLocation);
                TextLexer lexer(line.begin, lines.End(), fileName, pp->FileIndex());
                lexer.pp = pp;
                lexer.SetLine(pp->LineNumber());
                lexer.SetCountLines(false);
                ++lexer;
                int i = 0;
                std::vector<Token> tokens;
                bool end = false;
                while (*lexer != TextTokens::END && !end)
                {
                    soulng::lexer::Token token = lexer.GetToken(i++);
                    switch (token.id)
                    {
                        case TextTokens::NEWLINE:
                        {
                            end = true;
                            tokens.push_back(token);
                            pp->SetLineNumber(pp->LineNumber() + 1);
                            break;
                        }
                        case TextTokens::LINECOMMENT:
                        {
                            tokens.push_back(token);
                            end = true;
                            break;
                        }
                        case TextTokens::BEGINBLOCKCOMMENT:
                        {
                            if (ScanBlockComment(lexer, token))
                            {
                                int n = GetNumberOfNewLines(token.match);
                                lineIndex += n;
                            }
                            else
                            {
                                std::string error = "error: open block comment: " + pp->FileName() + ":" + std::to_string(pp->LineNumber());
                                pp->AddError(error);
                                end = true;
                            }
                            break;
                        }
                        case TextTokens::BEGINRAWSTRINGLITERAL:
                        {
                            if (ScanRawStringLiteral(lexer, token))
                            {
                                int n = GetNumberOfNewLines(token.match);
                                lineIndex += n;
                                pp->SetLineNumber(pp->LineNumber() + n);
                            }
                            else
                            {
                                std::string error = "error: open raw string literal: " + pp->FileName() + ":" + std::to_string(pp->LineNumber());
                                pp->AddError(error);
                                end = true;
                            }
                            break;
                        }
                        case TextTokens::QUOTEHEADERNAME:
                        {
                            token.id = TextTokens::STRINGLITERAL;
                            break;
                        }
                    }
                    if (!end)
                    {
                        tokens.push_back(token);
                        ++lexer;
                    }
                }
                tokens = pp->MacroExpand(tokens);
                for (const Token& token : tokens)
                {
                    switch (token.id)
                    {
                        case TextTokens::BLOCKCOMMENT:
                        case TextTokens::LINECOMMENT:
                        {
                            pp->AddToken(Token(TextTokens::WS, pp->Space(), pp->LineNumber()));
                            break;
                        }
                        default:
                        {
                            pp->AddToken(token);
                            break;
                        }
                    }
                }
            }
            ++lineIndex;
        }
        pp->PopFileName();
        pp->DecLevel();
        if (pp->Level() == 0)
        {
            std::vector<Token> tokens = pp->GetTokens();
            tokens = CombineAdjacentStringLiterals(tokens, pp);
            pp->SetTokens(std::move(tokens));
            Lexeme resultText = pp->EmitText();
            std::vector<std::string> fileNames = pp->GetFileNames();
            std::vector<std::unique_ptr<LogicalPhysicalMapping>> mappings = pp->GetLogicalPhysicalMappings();
            std::map<int, PPSourceLocation> lineMap = pp->GetLineMap();
            std::vector<std::string> errors = pp->GetErrors();
            Strings strings = pp->GetStrings();
            return std::unique_ptr<PPResult>(new PPResult(std::move(fileNames), std::move(strings), std::move(mappings), std::move(lineMap), resultText, std::move(errors)));
        }
    }
    catch (const std::exception& ex)
    {
        pp->AddProcessedHeader(fileName);
        pp->AddError(pp->FileName() + ":" + std::to_string(pp->LineNumber()) + ": " + ex.what());
        pp->PopFileName();
        pp->DecLevel();
    }
    return std::unique_ptr<PPResult>();
}

void InitPP()
{
    PPTokenToTextTokenMap::Init();
    TextTokenToCppTokenMap::Init();
}

void DonePP()
{
    TextTokenToCppTokenMap::Done();
    PPTokenToTextTokenMap::Done();
}

} // namespace sngcpp::pp
