#include "BasicType.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/BasicType.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match BasicTypeParser::BasicType(CmajorLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case BOOL:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new BoolNode(span));
            }
            break;
        }
        case SBYTE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new SByteNode(span));
            }
            break;
        }
        case BYTE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new ByteNode(span));
            }
            break;
        }
        case SHORT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new ShortNode(span));
            }
            break;
        }
        case USHORT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new UShortNode(span));
            }
            break;
        }
        case INT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new IntNode(span));
            }
            break;
        }
        case UINT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new UIntNode(span));
            }
            break;
        }
        case LONG:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new LongNode(span));
            }
            break;
        }
        case ULONG:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new ULongNode(span));
            }
            break;
        }
        case FLOAT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new FloatNode(span));
            }
            break;
        }
        case DOUBLE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new DoubleNode(span));
            }
            break;
        }
        case CHAR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new CharNode(span));
            }
            break;
        }
        case WCHAR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new WCharNode(span));
            }
            break;
        }
        case UCHAR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new UCharNode(span));
            }
            break;
        }
        case VOID:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new VoidNode(span));
            }
            break;
        }
    }
    return match;
}
