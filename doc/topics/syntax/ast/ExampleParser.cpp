#include "ExampleParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <ExampleLexer.hpp>
#include <ExampleTokens.hpp>
#include <boost/filesystem.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/doc/topics/syntax/ast/ExampleParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace ExampleTokens;
using namespace boost::filesystem;

std::unique_ptr<Node> ExampleParser::Parse(ExampleLexer& lexer, SymbolTable* symbolTable)
{
    std::unique_ptr<Node> value;
    ++lexer;
    int pos = lexer.GetPos();
    soulng::parser::Match match = ExampleParser::Statement(lexer, symbolTable);
    value.reset(static_cast<Node*>(match.value));
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
        lexer.ThrowExpectationFailure(pos, U"Statement");
    }
    return value;
}

soulng::parser::Match ExampleParser::Statement(ExampleLexer& lexer, SymbolTable* symbolTable)
{
    std::unique_ptr<Node> whileStatement;
    std::unique_ptr<Node> emptyStatement;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = ExampleParser::WhileStatement(lexer, symbolTable);
            whileStatement.reset(static_cast<Node*>(match.value));
            if (match.hit)
            {
                return soulng::parser::Match(true, whileStatement.release());
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ExampleParser::EmptyStatement(lexer);
                    emptyStatement.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, emptyStatement.release());
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match ExampleParser::WhileStatement(ExampleLexer& lexer, SymbolTable* symbolTable)
{
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> stmt;
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
                    if (*lexer == WHILE)
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
                    soulng::parser::Match match = ExampleParser::Expression(lexer);
                    cond.reset(static_cast<Node*>(match.value));
                    *parentMatch5 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == RPAREN)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch6 = match;
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
                soulng::parser::Match match = ExampleParser::Statement(lexer, symbolTable);
                stmt.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    return soulng::parser::Match(true, new WhileStatementNode(cond.release(), stmt.release()));
                }
                *parentMatch8 = match;
            }
            *parentMatch7 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExampleParser::EmptyStatement(ExampleLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
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
            return soulng::parser::Match(true, new EmptyStatementNode);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ExampleParser::Expression(ExampleLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
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
            soulng::lexer::Token token = lexer.GetToken(pos);
            return soulng::parser::Match(true, new IdentifierNode(token.match.ToString()));
        }
        *parentMatch0 = match;
    }
    return match;
}
