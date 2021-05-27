// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/PPParser.hpp>
#include <sngcpp20/pp/PPTokens.hpp>
#include <sngcpp20/pp/TextTokens.hpp>
#include <sngcpp20/pp/Scan.hpp>
#include <sngcpp20/pp/Util.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::pp {

using namespace soulng::unicode;

void SkipPPTokens(PPLexer& lexer)
{
    while (*lexer != PPTokens::END && *lexer != PPTokens::NEWLINE)
    {
        if (*lexer == PPTokens::BEGINBLOCKCOMMENT)
        {
            Token token = lexer.GetToken(lexer.GetPos());
            if (ScanBlockComment(lexer, token))
            {
                int n = GetNumberOfNewLines(token.match);
                lexer.pp->SetLineIndex(lexer.pp->GetLineIndex() + n);
                ++lexer;
            }
            else
            {
                std::string error = "error: open block comment: " + lexer.pp->FileName() + ":" + std::to_string(lexer.pp->GetLineIndex() + 1);
                lexer.pp->AddError(error);
                return;
            }
        }
        else if (*lexer == PPTokens::LINECOMMENT)
        {
            Token token = lexer.GetToken(lexer.GetPos());
            if (ScanLineCommentWithoutNewLine(lexer, token))
            {
                ++lexer;
            }
            else
            {
                std::string error = "internal error: invalid line comment: " + lexer.pp->FileName() + ":" + std::to_string(lexer.pp->GetLineIndex() + 1);
                lexer.pp->AddError(error);
                return;
            }
        }
        else
        {
            ++lexer;
        }
    }
}

std::string ParseAngleHeaderName(const soulng::lexer::Token& headerNameToken, PP* pp)
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
        std::string error = "invalid header name in file '" + pp->FileName() + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString()));
        pp->AddError(error);
        return std::string();
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
        std::string error = "invalid header name in file '" + pp->FileName() + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString()));
        pp->AddError(error);
        return std::string();
    }
    if (p == e)
    {
        return ToUtf8(std::u32string(begin, end));
    }
    else
    {
        std::string error = "invalid header name in file '" + pp->FileName() + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString()));
        pp->AddError(error);
        return std::string();
    }
}

std::string ParseQuoteHeaderName(const soulng::lexer::Token& headerNameToken, PP* pp)
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
        std::string error = "invalid header name in file '" + pp->FileName() + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString()));
        pp->AddError(error);
        return std::string();
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
        std::string error = "invalid header name in file '" + pp->FileName() + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString()));
        pp->AddError(error);
        return std::string();
    }
    if (p == e)
    {
        return ToUtf8(std::u32string(begin, end));
    }
    else
    {
        std::string error = "invalid header name in file '" + pp->FileName() + ":" + std::to_string(headerNameToken.line) + "': " + ToUtf8(std::u32string(headerNameToken.match.ToString()));
        pp->AddError(error);
        return std::string();
    }
}

void OptWs(PPLexer& lexer)
{
    while (*lexer == PPTokens::WS || *lexer == PPTokens::LINECOMMENT || *lexer == PPTokens::BEGINBLOCKCOMMENT)
    {
        if (*lexer == PPTokens::BEGINBLOCKCOMMENT)
        {
            Token token = lexer.GetToken(lexer.GetPos());
            if (ScanBlockComment(lexer, token))
            {
                int n = GetNumberOfNewLines(token.match);
                lexer.pp->SetLineIndex(lexer.pp->GetLineIndex() + n);
                ++lexer;
            }
            else
            {
                std::string error = "error: open block comment: " + lexer.pp->FileName() + ":" + std::to_string(lexer.pp->GetLineIndex() + 1);
                lexer.pp->AddError(error);
                return;
            }
        }
        else if (*lexer == PPTokens::LINECOMMENT)
        {
            Token token = lexer.GetToken(lexer.GetPos());
            if (ScanLineCommentWithoutNewLine(lexer, token))
            {
                ++lexer;
            }
            else
            {
                std::string error = "internal error: invalid line comment: " + lexer.pp->FileName() + ":" + std::to_string(lexer.pp->GetLineIndex() + 1);
                lexer.pp->AddError(error);
                return;
            }
        }
        else
        {
            ++lexer;
        }
    }
}

bool ParseHash(PPLexer& lexer)
{
    if (*lexer == PPTokens::HASH)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseNewLine(PPLexer& lexer)
{
    if (*lexer == PPTokens::NEWLINE)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseId(PPLexer& lexer, Token& id)
{
    if (*lexer == PPTokens::ID)
    {
        id = lexer.GetToken(lexer.GetPos());
        ++lexer;
        return true;
    }
    return false;
}

bool ParseLParen(PPLexer& lexer)
{
    if (*lexer == PPTokens::LPAREN)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseRParen(PPLexer& lexer)
{
    if (*lexer == PPTokens::RPAREN)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseDefineKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::DEFINE)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseUndefKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::UNDEF)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseLineKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::LINE)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseErrorKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::ERROR)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParsePragmaKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::PRAGMA)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseIncludeKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::INCLUDE)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseIfdefKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::IFDEF)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseIfndefKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::IFNDEF)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseIfKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::IF)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseElifKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::ELIF)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseElseKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::ELSE)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseEndifKeyword(PPLexer& lexer)
{
    if (*lexer == PPTokens::ENDIF)
    {
        ++lexer;
        return true;
    }
    return false;
}

bool ParseReplacementList(PPLexer& lexer, std::vector<Token>& replacementList)
{
    while (*lexer != PPTokens::END && *lexer != PPTokens::NEWLINE)
    {
        if (*lexer == PPTokens::BEGINBLOCKCOMMENT)
        {
            Token token = lexer.GetToken(lexer.GetPos());
            if (ScanBlockComment(lexer, token))
            {
                Token spaceToken(TextTokens::WS, lexer.pp->Space(), lexer.pp->LineNumber());
                replacementList.push_back(spaceToken);
                int n = GetNumberOfNewLines(token.match);
                lexer.pp->SetLineIndex(lexer.pp->GetLineIndex() + n);
                ++lexer;
            }
            else
            {
                std::string error = "error: open block comment: " + lexer.pp->FileName() + ":" + std::to_string(lexer.pp->GetLineIndex() + 1);
                lexer.pp->AddError(error);
                return false;
            }
        }
        else if (*lexer == PPTokens::LINECOMMENT)
        {
            Token token = lexer.GetToken(lexer.GetPos());
            if (ScanLineCommentWithoutNewLine(lexer, token))
            {
                Token spaceToken(TextTokens::WS, lexer.pp->Space(), lexer.pp->LineNumber());
                replacementList.push_back(spaceToken);
                ++lexer;
            }
            else
            {
                std::string error = "internal error: invalid line comment: " + lexer.pp->FileName() + ":" + std::to_string(lexer.pp->GetLineIndex() + 1);
                lexer.pp->AddError(error);
                return false;
            }
        }
        else
        {
            replacementList.push_back(ConvertPPTokenToTextToken(lexer.GetToken(lexer.GetPos())));
            ++lexer;
        }
    }
    replacementList = TrimTextTokens(replacementList);
    return true;
}

bool ParseMacroParams(PPLexer& lexer, std::vector<Token>& paramList)
{
    Token id;
    if (ParseId(lexer, id))
    {
        paramList.push_back(id);
        OptWs(lexer);
        while (*lexer == PPTokens::COMMA)
        {
            ++lexer;
            OptWs(lexer);
            if (ParseId(lexer, id))
            {
                paramList.push_back(id);
                OptWs(lexer);
            }
        }
    }
    if (*lexer == PPTokens::ELLIPSES)
    {
        paramList.push_back(lexer.GetToken(lexer.GetPos()));
        ++lexer;
    }
    return true;
}

bool ParseDefine(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseDefineKeyword(lexer))
        {
            if (lexer.pp->Skip())
            {
                SkipPPTokens(lexer);
                if (ParseNewLine(lexer))
                {
                    return true;
                }
            }
            else
            {
                OptWs(lexer);
                Token id;
                if (ParseId(lexer, id))
                {
                    if (ParseLParen(lexer))
                    {
                        OptWs(lexer);
                        std::vector<Token> paramList;
                        if (ParseMacroParams(lexer, paramList))
                        {
                            OptWs(lexer);
                            if (ParseRParen(lexer))
                            {
                                std::vector<Token> replacementList;
                                if (ParseReplacementList(lexer, replacementList))
                                {
                                    OptWs(lexer);
                                    if (ParseNewLine(lexer))
                                    {
                                        if (!lexer.pp->Skip())
                                        {
                                            lexer.pp->DefineFunctionMacro(id.match, paramList, replacementList, NoCommentString(replacementList));
                                        }
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        OptWs(lexer);
                        std::vector<Token> replacementList;
                        if (ParseReplacementList(lexer, replacementList))
                        {
                            OptWs(lexer);
                            if (ParseNewLine(lexer))
                            {
                                if (!lexer.pp->Skip())
                                {
                                    lexer.pp->DefineObjectMacro(id.match, replacementList, NoCommentString(replacementList));
                                }
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

bool ParseUndef(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseUndefKeyword(lexer))
        {
            if (lexer.pp->Skip())
            {
                SkipPPTokens(lexer);
                if (ParseNewLine(lexer))
                {
                    return true;
                }
            }
            else
            {
                OptWs(lexer);
                Token id;
                if (ParseId(lexer, id))
                {
                    OptWs(lexer);
                    if (ParseNewLine(lexer))
                    {
                        if (!lexer.pp->Skip())
                        {
                            lexer.pp->Undefine(id.match);
                        }
                        return true;
                    }
                }
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

void OptPPTokens(PPLexer& lexer, std::vector<Token>& tokens)
{
    while (*lexer != PPTokens::END && *lexer != PPTokens::NEWLINE)
    {
        if (*lexer == PPTokens::BEGINBLOCKCOMMENT)
        {
            Token token = lexer.GetToken(lexer.GetPos());
            if (ScanBlockComment(lexer, token))
            {
                int n = GetNumberOfNewLines(token.match);
                lexer.pp->SetLineIndex(lexer.pp->GetLineIndex() + n);
                Token spaceToken(TextTokens::WS, lexer.pp->Space(), lexer.pp->LineNumber());
                tokens.push_back(spaceToken);
                ++lexer;
            }
            else
            {
                std::string error = "error: open block comment: " + lexer.pp->FileName() + ":" + std::to_string(lexer.pp->GetLineIndex() + 1);
                lexer.pp->AddError(error);
                return;
            }
        }
        else if (*lexer == PPTokens::LINECOMMENT)
        {
            Token token = lexer.GetToken(lexer.GetPos());
            if (ScanLineCommentWithoutNewLine(lexer, token))
            {
                Token spaceToken(TextTokens::WS, lexer.pp->Space(), lexer.pp->LineNumber());
                tokens.push_back(spaceToken);
                ++lexer;
            }
            else
            {
                std::string error = "internal error: invalid line comment: " + lexer.pp->FileName() + ":" + std::to_string(lexer.pp->GetLineIndex() + 1);
                lexer.pp->AddError(error);
                return;
            }
        }
        else
        {
            tokens.push_back(ConvertPPTokenToTextToken(lexer.GetToken(lexer.GetPos())));
            ++lexer;
        }
    }
}

bool ParsePPTokens(PPLexer& lexer, std::vector<Token>& tokens)
{
    if (*lexer != PPTokens::END && *lexer != PPTokens::NEWLINE)
    {
        OptPPTokens(lexer, tokens);
        return true;
    }
    return false;
}

bool ParseLine(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseLineKeyword(lexer))
        {
            if (lexer.pp->Skip())
            {
                SkipPPTokens(lexer);
                if (ParseNewLine(lexer))
                {
                    return true;
                }
            }
            else
            {
                OptWs(lexer);
                std::vector<Token> tokens;
                if (ParsePPTokens(lexer, tokens))
                {
                    OptWs(lexer);
                    if (ParseNewLine(lexer))
                    {
                        if (!lexer.pp->Skip())
                        {
                            lexer.pp->Line(tokens);
                        }
                        return true;
                    }
                }
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

bool ParseError(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseErrorKeyword(lexer))
        {
            if (lexer.pp->Skip())
            {
                SkipPPTokens(lexer);
                if (ParseNewLine(lexer))
                {
                    return true;
                }
            }
            else
            {
                OptWs(lexer);
                std::vector<Token> tokens;
                OptPPTokens(lexer, tokens);
                if (ParseNewLine(lexer))
                {
                    if (!lexer.pp->Skip())
                    {
                        lexer.pp->Error(tokens);
                    }
                    return true;
                }
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

bool ParsePragma(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParsePragmaKeyword(lexer))
        {
            if (lexer.pp->Skip())
            {
                SkipPPTokens(lexer);
                if (ParseNewLine(lexer))
                {
                    return true;
                }
            }
            else
            {
                OptWs(lexer);
                std::vector<Token> tokens;
                OptPPTokens(lexer, tokens);
                if (ParseNewLine(lexer))
                {
                    if (!lexer.pp->Skip())
                    {
                        lexer.pp->Pragma(tokens);
                    }
                    return true;
                }
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

bool ParseInclude(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseIncludeKeyword(lexer))
        {
            if (lexer.pp->Skip())
            {
                SkipPPTokens(lexer);
                if (ParseNewLine(lexer))
                {
                    return true;
                }
            }
            else
            {
                OptWs(lexer);
                std::vector<Token> tokens;
                if (ParsePPTokens(lexer, tokens))
                {
                    OptWs(lexer);
                    if (ParseNewLine(lexer))
                    {
                        if (!lexer.pp->Skip())
                        {
                            lexer.pp->Include(tokens);
                        }
                        return true;
                    }
                }
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

bool ParseIfdef(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseIfdefKeyword(lexer))
        {
            OptWs(lexer);
            Token id;
            if (ParseId(lexer, id))
            {
                OptWs(lexer);
                if (ParseNewLine(lexer))
                {
                    lexer.pp->Ifdef(id);
                    return true;
                }
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

bool ParseIfndef(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseIfndefKeyword(lexer))
        {
            OptWs(lexer);
            Token id;
            if (ParseId(lexer, id))
            {
                OptWs(lexer);
                if (ParseNewLine(lexer))
                {
                    lexer.pp->Ifndef(id);
                    return true;
                }
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

bool ParseIf(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseIfKeyword(lexer))
        {
            OptWs(lexer);
            std::vector<Token> tokens;
            if (ParsePPTokens(lexer, tokens))
            {
                OptWs(lexer);
                if (ParseNewLine(lexer))
                {
                    lexer.pp->If(tokens);
                    return true;
                }
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

bool ParseElif(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseElifKeyword(lexer))
        {
            OptWs(lexer);
            std::vector<Token> tokens;
            if (ParsePPTokens(lexer, tokens))
            {
                OptWs(lexer);
                if (ParseNewLine(lexer))
                {
                    lexer.pp->Elif(tokens);
                    return true;
                }
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

bool ParseElse(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseElseKeyword(lexer))
        {
            OptWs(lexer);
            if (ParseNewLine(lexer))
            {
                lexer.pp->Else();
                return true;
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

bool ParseEndif(PPLexer& lexer)
{
    int64_t save = lexer.GetPos();
    if (ParseHash(lexer))
    {
        OptWs(lexer);
        if (ParseEndifKeyword(lexer))
        {
            OptWs(lexer);
            if (ParseNewLine(lexer))
            {
                lexer.pp->EndIf();
                return true;
            }
        }
    }
    lexer.SetPos(save);
    return false;
}

void ParseControlLine(PPLexer& lexer)
{
    OptWs(lexer);
    bool matched = ParseDefine(lexer);
    if (!matched)
    {
        matched = ParseUndef(lexer);
    }
    if (!matched)
    {
        matched = ParseLine(lexer);
    }
    if (!matched)
    {
        matched = ParseError(lexer);
    }
    if (!matched)
    {
        matched = ParsePragma(lexer);
    }
    if (!matched)
    {
        matched = ParseInclude(lexer);
    }
    if (!matched)
    {
        matched = ParseIfdef(lexer);
    }
    if (!matched)
    {
        matched = ParseIfndef(lexer);
    }
    if (!matched)
    {
        matched = ParseIf(lexer);
    }
    if (!matched)
    {
        matched = ParseElif(lexer);
    }
    if (!matched)
    {
        matched = ParseElse(lexer);
    }
    if (!matched)
    {
        matched = ParseEndif(lexer);
    }
    if (!matched)
    {
        matched = ParseHash(lexer);
        if (matched)
        {
            matched = ParseNewLine(lexer);
        }
    }
    if (!matched)
    {
        lexer.pp->AddError(lexer.GetFarthestError());
    }
}

} // namespace sngcpp::pp
