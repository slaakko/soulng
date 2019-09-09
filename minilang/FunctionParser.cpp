#include "FunctionParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/minilang/TypeParser.hpp>
#include <soulng/minilang/IdentifierParser.hpp>
#include <soulng/minilang/StatementParser.hpp>
#include <soulng/minilang/MinilangLexer.hpp>
#include <soulng/minilang/MinilangTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng/minilang/FunctionParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match MinilangFunctionParser::Function(MinilangLexer& lexer)
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
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match = MinilangTypeParser::Type(lexer);
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match = MinilangIdentifierParser::Identifier(lexer);
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
                        if (*lexer == LPAREN)
                        {
                            ++lexer;
                            match.hit = true;
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
                soulng::parser::Match* parentMatch7 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        soulng::parser::Match match = MinilangFunctionParser::ParameterList(lexer);
                        if (match.hit)
                        {
                            *parentMatch8 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
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
                if (*lexer == RPAREN)
                {
                    ++lexer;
                    match.hit = true;
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
        soulng::parser::Match* parentMatch10 = &match;
        {
            soulng::parser::Match match = MinilangStatementParser::CompoundStatement(lexer);
            *parentMatch10 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match MinilangFunctionParser::ParameterList(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = MinilangFunctionParser::Parameter(lexer);
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch2 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch3 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == COMMA)
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
                                soulng::parser::Match match = MinilangFunctionParser::Parameter(lexer);
                                *parentMatch4 = match;
                            }
                            *parentMatch3 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch2 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                            break;
                        }
                    }
                }
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match MinilangFunctionParser::Parameter(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = MinilangTypeParser::Type(lexer);
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match = MinilangIdentifierParser::Identifier(lexer);
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}
