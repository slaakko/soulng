#include "ParserFileParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/spg/CppIdentifierParser.hpp>
#include <soulng/spg/CppDeclaratorParser.hpp>
#include <soulng/spg/CppExpressionParser.hpp>
#include <soulng/spg/CppStatementParser.hpp>
#include <soulng/spg/TokenValueParsers.hpp>
#include <soulng/spg/ParserFileLexer.hpp>
#include <soulng/spg/ParserFileTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/ParserFileParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace ParserFileTokens;

std::unique_ptr<soulng::spg::ParserFile> ParserFileParser::Parse(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::ParserFile> value;
    ++lexer;
    int pos = lexer.GetPos();
    soulng::parser::Match match = ParserFileParser::ParserFile(lexer);
    value.reset(static_cast<soulng::spg::ParserFile*>(match.value));
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
        lexer.ThrowExpectationFailure(pos, U"ParserFile");
    }
    return value;
}

soulng::parser::Match ParserFileParser::ParserFile(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::ParserFile> parserFile = std::unique_ptr<soulng::spg::ParserFile>();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                if (match.hit)
                {
                    parserFile.reset(new soulng::spg::ParserFile(lexer.FileName()));
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match = ParserFileParser::Declaration(lexer, parserFile.get());
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
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, parserFile.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::Declaration(ParserFileLexer& lexer, soulng::spg::ParserFile* parserFile)
{
    std::unique_ptr<soulng::spg::Include> includeDeclaration;
    std::unique_ptr<soulng::parser::Value<std::u32string>> usingNamespaceDeclaration;
    std::unique_ptr<soulng::spg::GrammarParser> parserDeclaration;
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
                soulng::parser::Match match = ParserFileParser::IncludeDeclaration(lexer);
                includeDeclaration.reset(static_cast<soulng::spg::Include*>(match.value));
                if (match.hit)
                {
                    parserFile->AddInclude(includeDeclaration.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ParserFileParser::UsingNamespaceDeclaration(lexer);
                        usingNamespaceDeclaration.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                        if (match.hit)
                        {
                            parserFile->AddUsingNamespace(usingNamespaceDeclaration->value);
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ParserFileParser::ParserDeclaration(lexer);
                    parserDeclaration.reset(static_cast<soulng::spg::GrammarParser*>(match.value));
                    if (match.hit)
                    {
                        parserFile->AddParser(parserDeclaration.release());
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ParserFileParser::IncludeDeclaration(ParserFileLexer& lexer)
{
    bool prefix = bool();
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<bool>> includePrefix;
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
                lexer.parsingIncludeDeclaration = true;
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
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(true);
                            int save = lexer.GetPos();
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ParserFileParser::IncludePrefix(lexer);
                                    includePrefix.reset(static_cast<soulng::parser::Value<bool>*>(match.value));
                                    if (match.hit)
                                    {
                                        prefix = includePrefix->value;
                                    }
                                    *parentMatch8 = match;
                                }
                                if (match.hit)
                                {
                                    *parentMatch7 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                }
                            }
                            *parentMatch6 = match;
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
                                    soulng::lexer::Span span = lexer.GetSpan();
                                    soulng::parser::Match match(false);
                                    if (*lexer == HASH)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        s = span;
                                    }
                                    *parentMatch10 = match;
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch5 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == INCLUDE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
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
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == FILEPATH)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                s.end = span.end;
                            }
                            *parentMatch13 = match;
                        }
                        *parentMatch12 = match;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    lexer.parsingIncludeDeclaration = false;
                    return soulng::parser::Match(true, new soulng::spg::Include(prefix, lexer.GetMatch(s)));
                }
                else
                {
                    lexer.parsingIncludeDeclaration = false;
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::IncludePrefix(ParserFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case CPPPREFIX:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<bool>(false));
            }
            break;
        }
        case HPPPREFIX:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<bool>(true));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match ParserFileParser::UsingNamespaceDeclaration(ParserFileLexer& lexer)
{
    Span s = Span();
    std::unique_ptr<soulng::parser::Value<std::u32string>> ns;
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
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == USING)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        s = span;
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
                    if (*lexer == NAMESPACE)
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
                soulng::parser::Match match = CppIdentifierParser::QualifiedCppId(lexer);
                ns.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch8 = &match;
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
                        *parentMatch8 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(lexer.GetMatch(s)));
                }
                *parentMatch7 = match;
            }
            *parentMatch6 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::ParserDeclaration(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::GrammarParser> grammarParser = std::unique_ptr<soulng::spg::GrammarParser>();
    std::unique_ptr<soulng::parser::Value<std::u32string>> parserApi;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
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
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == PARSER)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match = ParserFileParser::Api(lexer);
                                parserApi.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
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
                                soulng::lexer::Span span = lexer.GetSpan();
                                soulng::parser::Match match(false);
                                if (*lexer == ID)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    grammarParser.reset(new soulng::spg::GrammarParser(lexer.GetMatch(span), parserApi->value));
                                }
                                *parentMatch8 = match;
                            }
                            *parentMatch7 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch9 = &match;
                    {
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch10 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LBRACE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                *parentMatch10 = match;
                            }
                            else
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LBRACE)));
                            }
                        }
                        *parentMatch9 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch11 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch12 = &match;
                    {
                        while (true)
                        {
                            int save = lexer.GetPos();
                            {
                                soulng::parser::Match match = ParserFileParser::Statement(lexer, grammarParser.get());
                                if (match.hit)
                                {
                                    *parentMatch12 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                    break;
                                }
                            }
                        }
                    }
                    *parentMatch11 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch13 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch14 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RBRACE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        *parentMatch14 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                    }
                }
                *parentMatch13 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, grammarParser.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::Api(ParserFileLexer& lexer)
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
                        soulng::lexer::Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == ID)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                *parentMatch7 = match;
                            }
                            else
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
            soulng::parser::Match* parentMatch8 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == RPAREN)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            *parentMatch10 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                        }
                    }
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(id));
                    }
                    *parentMatch9 = match;
                }
                *parentMatch8 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
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
                    soulng::parser::Match match(true);
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(std::u32string()));
                    }
                    *parentMatch12 = match;
                }
                *parentMatch11 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ParserFileParser::Statement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser)
{
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
                    soulng::parser::Match match = ParserFileParser::MainStatement(lexer, grammarParser);
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch4 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match = ParserFileParser::UsingStatement(lexer, grammarParser);
                            *parentMatch4 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match = ParserFileParser::LexerStatement(lexer, grammarParser);
                        *parentMatch5 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match = ParserFileParser::RuleInfoStatement(lexer, grammarParser);
                    *parentMatch6 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match = ParserFileParser::RuleStatement(lexer, grammarParser);
                *parentMatch7 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ParserFileParser::MainStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        if (*lexer == MAIN)
        {
            ++lexer;
            match.hit = true;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch3 = &match;
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
                        *parentMatch3 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    grammarParser->SetMain();
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::UsingStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser)
{
    std::unique_ptr<soulng::parser::Value<std::u32string>> parserId;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == USING)
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
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ParserFileParser::UsingQualifiedId(lexer);
                    parserId.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                    if (match.hit)
                    {
                        *parentMatch3 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, U"UsingQualifiedId");
                    }
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
                soulng::parser::Match* parentMatch6 = &match;
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
                        *parentMatch6 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    grammarParser->AddUsing(parserId->value);
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::UsingQualifiedId(ParserFileLexer& lexer)
{
    Span s = Span();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == ID)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s = span;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
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
                                soulng::parser::Match match(false);
                                if (*lexer == DOT)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch5 = match;
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
                                        soulng::lexer::Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == ID)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
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
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(lexer.GetMatch(s)));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::LexerStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser)
{
    std::u32string lexerName = std::u32string();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == USELEXER)
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
                    soulng::lexer::Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == ID)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            *parentMatch4 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                        }
                    }
                    if (match.hit)
                    {
                        lexerName = lexer.GetMatch(span);
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
        soulng::parser::Match* parentMatch5 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch7 = &match;
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
                        *parentMatch7 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    grammarParser->SetLexer(lexerName);
                }
                *parentMatch6 = match;
            }
            *parentMatch5 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::RuleInfoStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser)
{
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
                if (*lexer == RULEINFO)
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
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == LBRACE)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            *parentMatch4 = match;
                        }
                        else
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
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch6 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        soulng::parser::Match match = ParserFileParser::RuleInfo(lexer, grammarParser);
                        *parentMatch7 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                while (true)
                                {
                                    int save = lexer.GetPos();
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch10 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == COMMA)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            *parentMatch10 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch11 = &match;
                                            {
                                                soulng::parser::Match match = ParserFileParser::RuleInfo(lexer, grammarParser);
                                                *parentMatch11 = match;
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
                                            break;
                                        }
                                    }
                                }
                            }
                            *parentMatch8 = match;
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
        soulng::parser::Match* parentMatch12 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch13 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(false);
                if (*lexer == RBRACE)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    *parentMatch13 = match;
                }
                else
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

soulng::parser::Match ParserFileParser::RuleInfo(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser)
{
    std::u32string ruleName = std::u32string();
    std::u32string ruleInfo = std::u32string();
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
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == ID)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    *parentMatch6 = match;
                                }
                                else
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                                }
                            }
                            if (match.hit)
                            {
                                ruleName = lexer.GetMatch(span);
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
                soulng::parser::Match* parentMatch7 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == COMMA)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            *parentMatch8 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(COMMA)));
                        }
                    }
                    *parentMatch7 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
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
                    soulng::parser::Match* parentMatch11 = &match;
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
                            *parentMatch11 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(STRINGLIT)));
                        }
                    }
                    if (match.hit)
                    {
                        ruleInfo = soulng::spg::ParseStringLiteral(lexer.FileName(), lexer.GetToken(pos));
                    }
                    *parentMatch10 = match;
                }
                *parentMatch9 = match;
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
                soulng::parser::Match* parentMatch14 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        *parentMatch14 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                if (match.hit)
                {
                    grammarParser->AddRuleInfo(ruleName, ruleInfo);
                }
                *parentMatch13 = match;
            }
            *parentMatch12 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::RuleStatement(ParserFileLexer& lexer, soulng::spg::GrammarParser* grammarParser)
{
    std::unique_ptr<soulng::spg::RuleParser> rule = std::unique_ptr<soulng::spg::RuleParser>();
    std::unique_ptr<soulng::cppcode::TypeId> returnType;
    std::unique_ptr<soulng::spg::Parser> definition;
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
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::lexer::Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == ID)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                rule.reset(new soulng::spg::RuleParser(lexer.GetMatch(span)));
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
                            soulng::parser::Match match(true);
                            int save = lexer.GetPos();
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match = ParserFileParser::ParametersAndVariables(lexer, rule.get());
                                if (match.hit)
                                {
                                    *parentMatch7 = match;
                                }
                                else
                                {
                                    lexer.SetPos(save);
                                }
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
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
                            soulng::parser::Match match = ParserFileParser::ReturnType(lexer);
                            returnType.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
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
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch10 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == PRODUCES)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch10 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch11 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch12 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ParserFileParser::RuleBody(lexer);
                    definition.reset(static_cast<soulng::spg::Parser*>(match.value));
                    if (match.hit)
                    {
                        *parentMatch12 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, U"RuleBody");
                    }
                }
                *parentMatch11 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch13 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch14 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch15 = &match;
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
                        *parentMatch15 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    rule->SetDefinition(definition.release());
                    rule->SetReturnType(returnType.release());
                    grammarParser->AddRule(rule.release());
                }
                *parentMatch14 = match;
            }
            *parentMatch13 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::ParametersAndVariables(ParserFileLexer& lexer, soulng::spg::RuleParser* rule)
{
    std::unique_ptr<soulng::spg::Parameter> paramOrVariable;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == LPAREN)
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
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ParserFileParser::ParamOrVariable(lexer);
                            paramOrVariable.reset(static_cast<soulng::spg::Parameter*>(match.value));
                            if (match.hit)
                            {
                                rule->AddParamOrVariable(paramOrVariable.release());
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
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                while (true)
                                {
                                    int save = lexer.GetPos();
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            if (*lexer == COMMA)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            *parentMatch8 = match;
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
                                                    soulng::parser::Match match = ParserFileParser::ParamOrVariable(lexer);
                                                    paramOrVariable.reset(static_cast<soulng::spg::Parameter*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        rule->AddParamOrVariable(paramOrVariable.release());
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                        if (match.hit)
                                        {
                                            *parentMatch7 = match;
                                        }
                                        else
                                        {
                                            lexer.SetPos(save);
                                            break;
                                        }
                                    }
                                }
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        *parentMatch3 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
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
        soulng::parser::Match* parentMatch11 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch12 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(false);
                if (*lexer == RPAREN)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    *parentMatch12 = match;
                }
                else
                {
                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                }
            }
            *parentMatch11 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::ParamOrVariable(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TypeId> varType;
    std::unique_ptr<soulng::parser::Value<std::u32string>> varName;
    std::unique_ptr<soulng::cppcode::TypeId> paramType;
    std::unique_ptr<soulng::parser::Value<std::u32string>> paramName;
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
                if (*lexer == VAR)
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
                    soulng::parser::Match match = CppDeclaratorParser::TypeId(lexer);
                    varType.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
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
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch5 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = CppDeclaratorParser::Declarator(lexer);
                    varName.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, new soulng::spg::Variable(varType.release(), varName->value));
                    }
                    *parentMatch5 = match;
                }
                *parentMatch4 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch7 = &match;
                {
                    soulng::parser::Match match = CppDeclaratorParser::TypeId(lexer);
                    paramType.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
                    *parentMatch7 = match;
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
                            soulng::parser::Match match = CppDeclaratorParser::Declarator(lexer);
                            paramName.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, new soulng::spg::Parameter(paramType.release(), paramName->value));
                            }
                            *parentMatch9 = match;
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch7 = match;
                }
                *parentMatch6 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ParserFileParser::ReturnType(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::cppcode::TypeId> type;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        if (*lexer == COLON)
        {
            ++lexer;
            match.hit = true;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = CppDeclaratorParser::TypeId(lexer);
                type.reset(static_cast<soulng::cppcode::TypeId*>(match.value));
                if (match.hit)
                {
                    return soulng::parser::Match(true, type.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::RuleBody(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::Parser> alt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = ParserFileParser::Alternative(lexer);
        alt.reset(static_cast<soulng::spg::Parser*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, alt.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::Alternative(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::Parser> value = std::unique_ptr<soulng::spg::Parser>();
    std::unique_ptr<soulng::spg::Parser> left;
    std::unique_ptr<soulng::spg::Parser> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = ParserFileParser::Sequence(lexer);
                left.reset(static_cast<soulng::spg::Parser*>(match.value));
                if (match.hit)
                {
                    value.reset(left.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
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
                                soulng::parser::Match match(false);
                                if (*lexer == BITOR)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch5 = match;
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
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ParserFileParser::Sequence(lexer);
                                            right.reset(static_cast<soulng::spg::Parser*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch8 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"Sequence");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            value.reset(new soulng::spg::AlternativeParser(value.release(), right.release()));
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
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
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, value.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::Sequence(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::Parser> value = std::unique_ptr<soulng::spg::Parser>();
    std::unique_ptr<soulng::spg::Parser> left;
    std::unique_ptr<soulng::spg::Parser> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = ParserFileParser::Difference(lexer);
                left.reset(static_cast<soulng::spg::Parser*>(match.value));
                if (match.hit)
                {
                    value.reset(left.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
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
                                soulng::parser::Match match = ParserFileParser::Difference(lexer);
                                right.reset(static_cast<soulng::spg::Parser*>(match.value));
                                if (match.hit)
                                {
                                    value.reset(new soulng::spg::SequenceParser(value.release(), right.release()));
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
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, value.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::Difference(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::Parser> value = std::unique_ptr<soulng::spg::Parser>();
    std::unique_ptr<soulng::spg::Parser> left;
    std::unique_ptr<soulng::spg::Parser> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = ParserFileParser::List(lexer);
                left.reset(static_cast<soulng::spg::Parser*>(match.value));
                if (match.hit)
                {
                    value.reset(left.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
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
                                soulng::parser::Match match(false);
                                if (*lexer == MINUS)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch5 = match;
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
                                        soulng::parser::Match* parentMatch8 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ParserFileParser::List(lexer);
                                            right.reset(static_cast<soulng::spg::Parser*>(match.value));
                                            if (match.hit)
                                            {
                                                *parentMatch8 = match;
                                            }
                                            else
                                            {
                                                lexer.ThrowExpectationFailure(pos, U"List");
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            value.reset(new soulng::spg::DifferenceParser(value.release(), right.release()));
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
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
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, value.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::List(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::Parser> value = std::unique_ptr<soulng::spg::Parser>();
    std::unique_ptr<soulng::spg::Parser> left;
    std::unique_ptr<soulng::spg::Parser> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = ParserFileParser::Postfix(lexer);
                left.reset(static_cast<soulng::spg::Parser*>(match.value));
                if (match.hit)
                {
                    value.reset(left.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == REM)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch5 = match;
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
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ParserFileParser::Postfix(lexer);
                                    right.reset(static_cast<soulng::spg::Parser*>(match.value));
                                    if (match.hit)
                                    {
                                        *parentMatch8 = match;
                                    }
                                    else
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"Postfix");
                                    }
                                }
                                if (match.hit)
                                {
                                    value.reset(new soulng::spg::ListParser(value.release(), right.release()));
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
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
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, value.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::Postfix(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::Parser> value = std::unique_ptr<soulng::spg::Parser>();
    std::unique_ptr<soulng::spg::Parser> primary;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = ParserFileParser::Primary(lexer);
                primary.reset(static_cast<soulng::spg::Parser*>(match.value));
                if (match.hit)
                {
                    value.reset(primary.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            int save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == STAR)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    value.reset(new soulng::spg::KleeneParser(value.release()));
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        if (*lexer == PLUS)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            value.reset(new soulng::spg::PositiveParser(value.release()));
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch6 = match;
                            }
                        }
                        *parentMatch5 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch10 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == QUEST)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        value.reset(new soulng::spg::OptionalParser(value.release()));
                                    }
                                    *parentMatch11 = match;
                                }
                                *parentMatch10 = match;
                            }
                            *parentMatch5 = match;
                        }
                    }
                    if (match.hit)
                    {
                        *parentMatch4 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, value.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::Primary(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::Parser> value = std::unique_ptr<soulng::spg::Parser>();
    std::unique_ptr<soulng::spg::Parser> ruleCall;
    std::unique_ptr<soulng::spg::Parser> primitive;
    std::unique_ptr<soulng::spg::Parser> grouping;
    std::unique_ptr<soulng::cppcode::CompoundStatement> successCode;
    std::unique_ptr<soulng::cppcode::CompoundStatement> failureCode;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
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
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ParserFileParser::RuleCall(lexer);
                            ruleCall.reset(static_cast<soulng::spg::Parser*>(match.value));
                            if (match.hit)
                            {
                                value.reset(ruleCall.release());
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ParserFileParser::Primitive(lexer);
                                    primitive.reset(static_cast<soulng::spg::Parser*>(match.value));
                                    if (match.hit)
                                    {
                                        value.reset(primitive.release());
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = ParserFileParser::Grouping(lexer);
                                grouping.reset(static_cast<soulng::spg::Parser*>(match.value));
                                if (match.hit)
                                {
                                    value.reset(grouping.release());
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch10 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch11 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == EXCLAMATION)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                value.reset(new soulng::spg::ExpectationParser(value.release()));
                            }
                            *parentMatch12 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch11 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch10 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch13 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch14 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch15 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch16 = &match;
                        {
                            soulng::parser::Match match = CppStatementParser::CompoundStatement(lexer);
                            successCode.reset(static_cast<soulng::cppcode::CompoundStatement*>(match.value));
                            *parentMatch16 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch17 = &match;
                            {
                                soulng::parser::Match match(true);
                                int save = lexer.GetPos();
                                soulng::parser::Match* parentMatch18 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch19 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == DIV)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch19 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch20 = &match;
                                        {
                                            soulng::parser::Match match = CppStatementParser::CompoundStatement(lexer);
                                            failureCode.reset(static_cast<soulng::cppcode::CompoundStatement*>(match.value));
                                            *parentMatch20 = match;
                                        }
                                        *parentMatch19 = match;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch18 = match;
                                    }
                                    else
                                    {
                                        lexer.SetPos(save);
                                    }
                                }
                                *parentMatch17 = match;
                            }
                            *parentMatch16 = match;
                        }
                        if (match.hit)
                        {
                            value.reset(new soulng::spg::ActionParser(successCode.release(), failureCode.release(), value.release()));
                        }
                        *parentMatch15 = match;
                    }
                    if (match.hit)
                    {
                        *parentMatch14 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch13 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, value.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::RuleCall(ParserFileLexer& lexer)
{
    std::u32string ruleName = std::u32string();
    std::unique_ptr<soulng::cppcode::ExpressionList> exprList = std::unique_ptr<soulng::cppcode::ExpressionList>();
    int nonterminalPos = int();
    std::unique_ptr<soulng::parser::Value<std::u32string>> nt;
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
                    soulng::parser::Match match = ParserFileParser::Nonterminal(lexer);
                    nt.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                    if (match.hit)
                    {
                        ruleName = nt->value;
                        nonterminalPos = pos;
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
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    bool pass = true;
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        pass = soulng::lexer::NoWhiteSpaceBetweenTokens(lexer.GetToken(nonterminalPos), lexer.GetToken(pos));
                                        exprList.reset(new soulng::cppcode::ExpressionList);
                                    }
                                    if (match.hit && !pass)
                                    {
                                        match = soulng::parser::Match(false);
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch7 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch9 = &match;
                                {
                                    soulng::parser::Match match = CppExpressionParser::ExpressionList(lexer, exprList.get());
                                    *parentMatch9 = match;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch10 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == RPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch10 = match;
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
            soulng::parser::Match* parentMatch11 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == COLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch11 = match;
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
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch14 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == ID)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        *parentMatch14 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ID)));
                    }
                }
                if (match.hit)
                {
                    std::u32string name = lexer.GetMatch(span);
                    soulng::spg::NonterminalParser * nonterminalParser = new soulng::spg::NonterminalParser(name, ruleName);
                    nonterminalParser->SetArguments(exprList.get());
                    return soulng::parser::Match(true, nonterminalParser);
                }
                *parentMatch13 = match;
            }
            *parentMatch12 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::Nonterminal(ParserFileLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::lexer::Span span = lexer.GetSpan();
        soulng::parser::Match match(false);
        if (*lexer == ID)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(lexer.GetMatch(span)));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ParserFileParser::Primitive(ParserFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case EMPTY:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::spg::EmptyParser);
            }
            break;
        }
        case ID:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::spg::TokenParser(lexer.GetMatch(span)));
            }
            break;
        }
    }
    return match;
}

soulng::parser::Match ParserFileParser::Grouping(ParserFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::Parser> alt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == LPAREN)
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
                    soulng::parser::Match match = ParserFileParser::Alternative(lexer);
                    alt.reset(static_cast<soulng::spg::Parser*>(match.value));
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
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RPAREN)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        *parentMatch5 = match;
                    }
                    else
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                    }
                }
                *parentMatch4 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::spg::GroupingParser(alt.release()));
        }
        *parentMatch0 = match;
    }
    return match;
}
