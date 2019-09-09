#include "SourceFileParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/minilang/FunctionParser.hpp>
#include <soulng/minilang/MinilangLexer.hpp>
#include <soulng/minilang/MinilangTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng/minilang/SourceFileParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match MinilangSourceFileParser::SourceFile(MinilangLexer& lexer)
{
    soulng::parser::Match match(true);
    soulng::parser::Match* parentMatch0 = &match;
    {
        while (true)
        {
            int save = lexer.GetPos();
            {
                soulng::parser::Match match = MinilangFunctionParser::Function(lexer);
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
