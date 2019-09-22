#include "SourceFileParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/FunctionParser.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/SourceFileParser.parser' using soulng parser generator spg version 1.1.0

using namespace soulng::unicode;
using namespace MinilangTokens;

std::unique_ptr<minilang::SourceFileNode> SourceFileParser::Parse(MinilangLexer& lexer)
{
    std::unique_ptr<minilang::SourceFileNode> value;
    ++lexer;
    int pos = lexer.GetPos();
    soulng::parser::Match match = SourceFileParser::SourceFile(lexer);
    value.reset(static_cast<minilang::SourceFileNode*>(match.value));
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
        lexer.ThrowExpectationFailure(pos, U"SourceFile");
    }
    return value;
}

soulng::parser::Match SourceFileParser::SourceFile(MinilangLexer& lexer)
{
    std::unique_ptr<minilang::SourceFileNode> sourceFile = std::unique_ptr<minilang::SourceFileNode>();
    std::unique_ptr<minilang::FunctionNode> function;
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
                    sourceFile.reset(new minilang::SourceFileNode);
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
                                soulng::parser::Match match = FunctionParser::Function(lexer);
                                function.reset(static_cast<minilang::FunctionNode*>(match.value));
                                if (match.hit)
                                {
                                    sourceFile->AddFunction(function.release());
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
            return soulng::parser::Match(true, sourceFile.release());
        }
        *parentMatch0 = match;
    }
    return match;
}
