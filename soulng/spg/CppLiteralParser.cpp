#include "CppLiteralParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/spg/ParserFileLexer.hpp>
#include <soulng/spg/ParserFileTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/CppLiteralParser.parser' using soulng parser generator spg version 1.1.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace ParserFileTokens;

soulng::parser::Match CppLiteralParser::CppLiteral(ParserFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case INTLIT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::Literal(lexer.GetMatch(span)));
            }
            break;
        }
        case FLOATINGLIT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::Literal(lexer.GetMatch(span)));
            }
            break;
        }
        case CHARLIT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::Literal(lexer.GetMatch(span)));
            }
            break;
        }
        case STRINGLIT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::Literal(lexer.GetMatch(span)));
            }
            break;
        }
        case TRUE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::Literal(lexer.GetMatch(span)));
            }
            break;
        }
        case FALSE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::Literal(lexer.GetMatch(span)));
            }
            break;
        }
        case NULLPTR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::cppcode::Literal(lexer.GetMatch(span)));
            }
            break;
        }
    }
    return match;
}
