#include "SourceFileParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/FunctionParser.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/SourceFileParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

void SourceFileParser::Parse(MinilangLexer& lexer)
{
    ++lexer;
    int pos = lexer.GetPos();
    soulng::parser::Match match = SourceFileParser::SourceFile(lexer);
    if (match.hit)
    {
        if (*lexer == soulng::lexer::END)
        {
            return;
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
    return;
}

soulng::parser::Match SourceFileParser::SourceFile(MinilangLexer& lexer)
{
    soulng::parser::Match match(true);
    soulng::parser::Match* parentMatch0 = &match;
    {
        while (true)
        {
            int save = lexer.GetPos();
            {
                soulng::parser::Match match = FunctionParser::Function(lexer);
                if (match.hit)
                {
                    *parentMatch0 = match;
                }
                else
                {
                    lexer.SetPos(save);
                    break;
                }
            }
        }
    }
    return match;
}
