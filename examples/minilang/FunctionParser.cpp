#include "FunctionParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/TypeParser.hpp>
#include <minilang/IdentifierParser.hpp>
#include <minilang/StatementParser.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/FunctionParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match FunctionParser::Function(MinilangLexer& lexer)
{
    std::unique_ptr<minilang::FunctionNode> function = std::unique_ptr<minilang::FunctionNode>();
    std::unique_ptr<minilang::Node> returnType;
    std::unique_ptr<minilang::IdentifierNode> functionName;
    std::unique_ptr<minilang::CompoundStatementNode> functionBody;
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
                            soulng::parser::Match match = TypeParser::Type(lexer);
                            returnType.reset(static_cast<minilang::Node*>(match.value));
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                    functionName.reset(static_cast<minilang::IdentifierNode*>(match.value));
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"Identifier");
                                    }
                                }
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
                                if (match.hit)
                                {
                                    function.reset(new minilang::FunctionNode(returnType.release(), functionName.release()));
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
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch10 = &match;
                        {
                            soulng::parser::Match match = FunctionParser::ParameterList(lexer, function.get());
                            if (match.hit)
                            {
                                *parentMatch10 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
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
                    *parentMatch11 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
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
                        soulng::parser::Match match = StatementParser::CompoundStatement(lexer);
                        functionBody.reset(static_cast<minilang::CompoundStatementNode*>(match.value));
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"CompoundStatement");
                        }
                    }
                    if (match.hit)
                    {
                        function->SetBody(functionBody.release());
                    }
                    *parentMatch13 = match;
                }
                *parentMatch12 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, function.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match FunctionParser::ParameterList(MinilangLexer& lexer, minilang::FunctionNode* function)
{
    std::unique_ptr<minilang::ParameterNode> left;
    std::unique_ptr<minilang::ParameterNode> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match = FunctionParser::Parameter(lexer);
            left.reset(static_cast<minilang::ParameterNode*>(match.value));
            if (match.hit)
            {
                function->AddParam(left.release());
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
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch3 = &match;
            {
                while (true)
                {
                    int save = lexer.GetPos();
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch4 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == COMMA)
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
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = FunctionParser::Parameter(lexer);
                                        right.reset(static_cast<minilang::ParameterNode*>(match.value));
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, U"Parameter");
                                        }
                                    }
                                    if (match.hit)
                                    {
                                        function->AddParam(right.release());
                                    }
                                    *parentMatch6 = match;
                                }
                                *parentMatch5 = match;
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
                            break;
                        }
                    }
                }
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match FunctionParser::Parameter(MinilangLexer& lexer)
{
    std::unique_ptr<minilang::Node> type;
    std::unique_ptr<minilang::IdentifierNode> name;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = TypeParser::Type(lexer);
        type.reset(static_cast<minilang::Node*>(match.value));
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
                soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                name.reset(static_cast<minilang::IdentifierNode*>(match.value));
                if (match.hit)
                {
                    return soulng::parser::Match(true, new minilang::ParameterNode(type.release(), name.release()));
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}
