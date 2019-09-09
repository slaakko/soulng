#include "LexerFileParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/slg/CppDeclaratorParser.hpp>
#include <soulng/slg/CppStatementParser.hpp>
#include <soulng/slg/LexerFileLexer.hpp>
#include <soulng/slg/LexerFileTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/slg/LexerFileParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace LexerFileTokens;

std::unique_ptr<soulng::slg::LexerFile> LexerFileParser::Parse(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::slg::LexerFile> value;
    ++lexer;
    int pos = lexer.GetPos();
    soulng::parser::Match match = LexerFileParser::LexerFile(lexer);
    value.reset(static_cast<soulng::slg::LexerFile*>(match.value));
    if (match.hit)
    {
        if (*lexer == soulng::lexer::END)
        {
            return value;
        }
        else
        {
            lexer.ThrowExpectationFailure(lexer.GetPos(), ToUtf32(GetTokenInfo(soulng::lexer::END)));
        }
    }
    else
    {
        lexer.ThrowExpectationFailure(pos, U"lexer file");
    }
    return value;
}

soulng::parser::Match LexerFileParser::LexerFile(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::slg::LexerFile> lexerFile = std::unique_ptr<soulng::slg::LexerFile>();
    std::unique_ptr<soulng::slg::Declaration> declaration;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match(true);
            if (match.hit)
            {
                lexerFile.reset(new soulng::slg::LexerFile);
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch2 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch5 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = LexerFileParser::Declaration(lexer);
                                declaration.reset(static_cast<soulng::slg::Declaration*>(match.value));
                                if (match.hit)
                                {
                                    lexerFile->Add(declaration.release());
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch4 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, lexerFile.release());
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Declaration(LexerFileLexer& lexer)
{
    std::unique_ptr<soulng::slg::ClassMap> classMapDeclaration;
    std::unique_ptr<soulng::slg::Prefix> prefixDeclaration;
    std::unique_ptr<soulng::slg::Include> includeDeclaration;
    std::unique_ptr<soulng::slg::Tokens> tokensDeclaration;
    std::unique_ptr<soulng::slg::Keywords> keywordsDeclaration;
    std::unique_ptr<soulng::slg::Expressions> expressionsDeclaration;
    std::unique_ptr<soulng::slg::Lexer> lexerDeclaration;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = LexerFileParser::ClassMap(lexer);
                                classMapDeclaration.reset(static_cast<soulng::slg::ClassMap*>(match.value));
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, classMapDeclaration.release());
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = LexerFileParser::Prefix(lexer);
                                        prefixDeclaration.reset(static_cast<soulng::slg::Prefix*>(match.value));
                                        if (match.hit)
                                        {
                                            return soulng::parser::Match(true, prefixDeclaration.release());
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch10 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = LexerFileParser::Include(lexer);
                                    includeDeclaration.reset(static_cast<soulng::slg::Include*>(match.value));
                                    if (match.hit)
                                    {
                                        return soulng::parser::Match(true, includeDeclaration.release());
                                    }
                                    *parentMatch10 = match;
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch12 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = LexerFileParser::Tokens(lexer);
                                tokensDeclaration.reset(static_cast<soulng::slg::Tokens*>(match.value));
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, tokensDeclaration.release());
                                }
                                *parentMatch12 = match;
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch13 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch14 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = LexerFileParser::Keywords(lexer);
                            keywordsDeclaration.reset(static_cast<soulng::slg::Keywords*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, keywordsDeclaration.release());
                            }
                            *parentMatch14 = match;
                        }
                        *parentMatch13 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch15 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch16 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = LexerFileParser::Expressions(lexer);
                        expressionsDeclaration.reset(static_cast<soulng::slg::Expressions*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, expressionsDeclaration.release());
                        }
                        *parentMatch16 = match;
                    }
                    *parentMatch15 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch17 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch18 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = LexerFileParser::Lexer(lexer);
                    lexerDeclaration.reset(static_cast<soulng::slg::Lexer*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, lexerDeclaration.release());
                    }
                    *parentMatch18 = match;
                }
                *parentMatch17 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match LexerFileParser::ClassMap(LexerFileLexer& lexer)
{
    std::u32string classMapName = std::u32string();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == CLASSMAP)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == ID)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                        }
                    }
                    if (match.hit)
                    {
                        classMapName = lexer.GetMatch(span);
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch4 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::slg::ClassMap(classMapName));
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Prefix(LexerFileLexer& lexer)
{
    std::u32string prefix = std::u32string();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == PREFIX)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == STRINGLIT)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(STRINGLIT)));
                        }
                    }
                    if (match.hit)
                    {
                        prefix = soulng::slg::MakeStrValue(lexer.FileName(), lexer.GetToken(pos));
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch4 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::slg::Prefix(prefix));
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Include(LexerFileLexer& lexer)
{
    std::u32string path = std::u32string();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == HASH)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == INCLUDE)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch3 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch4 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == FILEPATH)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(FILEPATH)));
                    }
                }
                if (match.hit)
                {
                    path = soulng::slg::MakePathValue(lexer.FileName(), lexer.GetToken(pos));
                    return soulng::parser::Match(true, new soulng::slg::Include(path));
                }
                *parentMatch4 = match;
            }
            *parentMatch3 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Tokens(LexerFileLexer& lexer)
{
    std::u32string tokensDeclarationName = std::u32string();
    std::unique_ptr<soulng::slg::Tokens> tokens = std::unique_ptr<soulng::slg::Tokens>();
    std::unique_ptr<soulng::parser::Value<soulng::slg::Token>> token;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == TOKENS)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == ID)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                                }
                            }
                            if (match.hit)
                            {
                                tokensDeclarationName = lexer.GetMatch(span);
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LBRACE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LBRACE)));
                            }
                        }
                        if (match.hit)
                        {
                            tokens.reset(new soulng::slg::Tokens(tokensDeclarationName));
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch9 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = LexerFileParser::Token(lexer);
                            token.reset(static_cast<soulng::parser::Value<soulng::slg::Token>*>(match.value));
                            if (match.hit)
                            {
                                tokens->Add(token->value);
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch10 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                while (true)
                                {
                                    int save = lexer.GetPos();
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch14 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == COMMA)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            *parentMatch14 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch15 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch16 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = LexerFileParser::Token(lexer);
                                                    token.reset(static_cast<soulng::parser::Value<soulng::slg::Token>*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        tokens->Add(token->value);
                                                    }
                                                    *parentMatch16 = match;
                                                }
                                                *parentMatch15 = match;
                                            }
                                            *parentMatch14 = match;
                                        }
                                        if (match.hit)
                                        {
                                            *parentMatch13 = match;
                                        }
                                        else
                                        {
                                            lexer.SetPos(save);
                                            break;
                                        }
                                    }
                                }
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch10 = match;
                    }
                    if (match.hit)
                    {
                        *parentMatch9 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch8 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch17 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch18 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RBRACE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, tokens.release());
                }
                *parentMatch18 = match;
            }
            *parentMatch17 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Token(LexerFileLexer& lexer)
{
    std::u32string tokenName = std::u32string();
    std::u32string tokenInfo = std::u32string();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == LPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == ID)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                                }
                            }
                            if (match.hit)
                            {
                                tokenName = lexer.GetMatch(span);
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == COMMA)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(COMMA)));
                        }
                    }
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch8 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == STRINGLIT)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(STRINGLIT)));
                        }
                    }
                    if (match.hit)
                    {
                        tokenInfo = soulng::slg::MakeStrValue(lexer.FileName(), lexer.GetToken(pos));
                    }
                    *parentMatch8 = match;
                }
                *parentMatch7 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch9 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch10 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::parser::Value<soulng::slg::Token>(soulng::slg::Token(tokenName, ToUtf8(tokenInfo))));
                }
                *parentMatch10 = match;
            }
            *parentMatch9 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Keywords(LexerFileLexer& lexer)
{
    std::u32string keywordsDeclarationName = std::u32string();
    std::unique_ptr<soulng::slg::Keywords> keywords = std::unique_ptr<soulng::slg::Keywords>();
    std::unique_ptr<soulng::slg::Keyword> keyword;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == KEYWORDS)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == ID)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                                }
                            }
                            if (match.hit)
                            {
                                keywordsDeclarationName = lexer.GetMatch(span);
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LBRACE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LBRACE)));
                            }
                        }
                        if (match.hit)
                        {
                            keywords.reset(new soulng::slg::Keywords(keywordsDeclarationName));
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch9 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = LexerFileParser::Keyword(lexer);
                            keyword.reset(static_cast<soulng::slg::Keyword*>(match.value));
                            if (match.hit)
                            {
                                keywords->Add(keyword.release());
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch10 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch13 = &match;
                            {
                                while (true)
                                {
                                    int save = lexer.GetPos();
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch14 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == COMMA)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            *parentMatch14 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch15 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch16 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = LexerFileParser::Keyword(lexer);
                                                    keyword.reset(static_cast<soulng::slg::Keyword*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        keywords->Add(keyword.release());
                                                    }
                                                    *parentMatch16 = match;
                                                }
                                                *parentMatch15 = match;
                                            }
                                            *parentMatch14 = match;
                                        }
                                        if (match.hit)
                                        {
                                            *parentMatch13 = match;
                                        }
                                        else
                                        {
                                            lexer.SetPos(save);
                                            break;
                                        }
                                    }
                                }
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch10 = match;
                    }
                    if (match.hit)
                    {
                        *parentMatch9 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch8 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch17 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch18 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RBRACE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, keywords.release());
                }
                *parentMatch18 = match;
            }
            *parentMatch17 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Keyword(LexerFileLexer& lexer)
{
    std::u32string kw = std::u32string();
    std::u32string tokenName = std::u32string();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == LPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == STRINGLIT)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(STRINGLIT)));
                                }
                            }
                            if (match.hit)
                            {
                                kw = soulng::slg::MakeStrValue(lexer.FileName(), lexer.GetToken(pos));
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == COMMA)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(COMMA)));
                        }
                    }
                    *parentMatch6 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch8 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == ID)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                        }
                    }
                    if (match.hit)
                    {
                        tokenName = lexer.GetMatch(span);
                    }
                    *parentMatch8 = match;
                }
                *parentMatch7 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch9 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch10 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::slg::Keyword(kw, tokenName));
                }
                *parentMatch10 = match;
            }
            *parentMatch9 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Expressions(LexerFileLexer& lexer)
{
    int index = int();
    std::unique_ptr<soulng::slg::Expressions> expressions = std::unique_ptr<soulng::slg::Expressions>();
    std::unique_ptr<soulng::slg::Expression> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == EXPRESSIONS)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        index = 0;
                        expressions.reset(new soulng::slg::Expressions);
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == LBRACE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LBRACE)));
                        }
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = LexerFileParser::Expression(lexer, index);
                                expr.reset(static_cast<soulng::slg::Expression*>(match.value));
                                if (match.hit)
                                {
                                    expressions->Add(expr.release());
                                    index = index + 1;
                                }
                                *parentMatch7 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch6 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch8 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RBRACE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, expressions.release());
                }
                *parentMatch9 = match;
            }
            *parentMatch8 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Expression(LexerFileLexer& lexer, int index)
{
    std::u32string exprName = std::u32string();
    int line = int();
    std::unique_ptr<soulng::parser::Value<std::u32string>> exprValue;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == ID)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        exprName = lexer.GetMatch(span);
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == ASSIGN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = LexerFileParser::ExprString(lexer);
                        exprValue.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"regular expression string");
                        }
                    }
                    if (match.hit)
                    {
                        line = lexer.GetToken(pos).line;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch7 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::slg::Expression(index, exprName, exprValue->value, line));
                }
                *parentMatch8 = match;
            }
            *parentMatch7 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::ExprString(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        if (*lexer == STRINGLIT)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(soulng::slg::MakeExprStringValue(lexer.FileName(), lexer.GetToken(pos))));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Lexer(LexerFileLexer& lexer)
{
    std::u32string lexerDeclarationName = std::u32string();
    std::unique_ptr<soulng::slg::Lexer> currentLexer = std::unique_ptr<soulng::slg::Lexer>();
    std::unique_ptr<soulng::parser::Value<std::u32string>> lexerApi;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == LEXER)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match = LexerFileParser::Api(lexer);
                            lexerApi.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch6 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == ID)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                                }
                            }
                            if (match.hit)
                            {
                                lexerDeclarationName = lexer.GetMatch(span);
                            }
                            *parentMatch7 = match;
                        }
                        *parentMatch6 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch8 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch9 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LBRACE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LBRACE)));
                            }
                        }
                        if (match.hit)
                        {
                            currentLexer.reset(new soulng::slg::Lexer(lexerApi->value, lexerDeclarationName));
                        }
                        *parentMatch9 = match;
                    }
                    *parentMatch8 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch10 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch11 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match = LexerFileParser::LexerClause(lexer, currentLexer.get());
                            if (match.hit)
                            {
                                *parentMatch11 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch10 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch12 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch13 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RBRACE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                    }
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, currentLexer.release());
                }
                *parentMatch13 = match;
            }
            *parentMatch12 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Api(LexerFileLexer& lexer)
{
    std::u32string id = std::u32string();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == API)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == LPAREN)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch5 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch6 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == ID)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                            }
                        }
                        if (match.hit)
                        {
                            id = lexer.GetMatch(span);
                        }
                        *parentMatch6 = match;
                    }
                    *parentMatch5 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch8 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == RPAREN)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                        }
                    }
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(id));
                    }
                    *parentMatch8 = match;
                }
                *parentMatch7 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch10 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(true);
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(std::u32string()));
                    }
                    *parentMatch10 = match;
                }
                *parentMatch9 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match LexerFileParser::LexerClause(LexerFileLexer& lexer, soulng::slg::Lexer* currentLexer)
{
    int line = int();
    std::unique_ptr<soulng::parser::Value<std::u32string>> expr;
    std::unique_ptr<soulng::parser::Value<int>> action;
    std::unique_ptr<soulng::cppcode::CompoundStatement> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = LexerFileParser::ExprString(lexer);
                            expr.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                            if (match.hit)
                            {
                                line = lexer.GetToken(pos).line;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match = LexerFileParser::Action(lexer);
                            action.reset(static_cast<soulng::parser::Value<int>*>(match.value));
                            *parentMatch6 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = CppStatementParser::CompoundStatement(lexer);
                            stmt.reset(static_cast<soulng::cppcode::CompoundStatement*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"compound statement");
                            }
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    currentLexer->AddStatement(new soulng::slg::LexerStatement(expr->value, stmt.release(), action->value, line));
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch8 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match = LexerFileParser::Variables(lexer, currentLexer);
                    *parentMatch8 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match = LexerFileParser::Actions(lexer, currentLexer);
                *parentMatch9 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match LexerFileParser::Variables(LexerFileLexer& lexer, soulng::slg::Lexer* currentLexer)
{
    std::unique_ptr<soulng::slg::Variable> variable;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == VARIABLES)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == LBRACE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LBRACE)));
                        }
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch4 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch5 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = LexerFileParser::Variable(lexer);
                                variable.reset(static_cast<soulng::slg::Variable*>(match.value));
                                if (match.hit)
                                {
                                    currentLexer->AddVariable(variable.release());
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch5 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch4 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch7 = &match;
        {
            soulng::parser::Match match(true);
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(false);
                if (*lexer == RBRACE)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (!match.hit)
                {
                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                }
            }
            *parentMatch7 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Variable(LexerFileLexer& lexer)
{
    std::u32string name = std::u32string();
    std::unique_ptr<soulng::cppcode::TypeId> type;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match = CppDeclaratorParser::TypeId(lexer);
            type.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == ID)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        name = lexer.GetMatch(span);
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch4 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(false);
                if (*lexer == SEMICOLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    return soulng::parser::Match(true, new soulng::slg::Variable(type.release(), name));
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Actions(LexerFileLexer& lexer, soulng::slg::Lexer* currentLexer)
{
    std::unique_ptr<soulng::parser::Value<int>> action;
    std::unique_ptr<soulng::cppcode::CompoundStatement> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == ACTIONS)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == LBRACE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LBRACE)));
                        }
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch4 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch5 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            bool pass = true;
                                            soulng::parser::Match match = LexerFileParser::Action(lexer);
                                            action.reset(static_cast<soulng::parser::Value<int>*>(match.value));
                                            if (match.hit)
                                            {
                                                pass = action->value != -1;
                                            }
                                            if (match.hit && !pass)
                                            {
                                                match = soulng::parser::Match(false);
                                            }
                                            *parentMatch9 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch10 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == ASSIGN)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            *parentMatch10 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch11 = &match;
                                    {
                                        soulng::parser::Match match(true);
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = CppStatementParser::CompoundStatement(lexer);
                                            stmt.reset(static_cast<soulng::cppcode::CompoundStatement*>(match.value));
                                            if (!match.hit)
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"compound statement");
                                            }
                                        }
                                        *parentMatch11 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                if (match.hit)
                                {
                                    currentLexer->AddAction(new soulng::slg::Action(action->value, stmt.release()));
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch5 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch4 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch12 = &match;
        {
            soulng::parser::Match match(true);
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(false);
                if (*lexer == RBRACE)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (!match.hit)
                {
                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                }
            }
            *parentMatch12 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match LexerFileParser::Action(LexerFileLexer& lexer)
{
    int actionId = int();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == DOLLAR)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == LPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                }
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch6 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == INTLIT)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(INTLIT)));
                                }
                            }
                            if (match.hit)
                            {
                                actionId = soulng::slg::MakeActionIntValue(lexer.FileName(), lexer.GetToken(pos));
                            }
                            *parentMatch7 = match;
                        }
                        *parentMatch6 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch8 = &match;
                {
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == RPAREN)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                        }
                    }
                    *parentMatch8 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                return soulng::parser::Match(true, new soulng::parser::Value<int>(actionId));
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch10 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(true);
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, new soulng::parser::Value<int>(-1));
                    }
                    *parentMatch10 = match;
                }
                *parentMatch9 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}
