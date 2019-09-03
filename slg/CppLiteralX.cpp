#include "CppLiteral.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/slg/LexerFileLexer.hpp>
#include <soulng/slg/LexerFileTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng/slg/CppLiteral.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace LexerFileTokens;

soulng::parser::Match CppLiteralParser::CppLiteral(LexerFileLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    Span span = lexer.GetSpan();
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
