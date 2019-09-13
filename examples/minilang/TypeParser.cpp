#include "TypeParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>
#include <minilang/Tree.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/TypeParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace MinilangTokens;

soulng::parser::Match TypeParser::Type(MinilangLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case INT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new minilang::IntNode);
            }
            break;
        }
        case BOOL:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new minilang::BoolNode);
            }
            break;
        }
        case VOID:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new minilang::VoidNode);
            }
            break;
        }
    }
    return match;
}
