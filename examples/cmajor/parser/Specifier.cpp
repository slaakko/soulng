#include "Specifier.hpp"
#include <soulng/util/Unicode.hpp>
#include <cmajor/lexer/CmajorLexer.hpp>
#include <cmajor/lexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/parser/Specifier.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace CmajorTokens;

soulng::parser::Match SpecifierParser::Specifiers(CmajorLexer& lexer)
{
    cmajor::ast::Specifiers specifiers = cmajor::ast::Specifiers();
    std::unique_ptr<soulng::parser::Value<cmajor::ast::Specifiers>> specifier;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(true);
        soulng::parser::Match* parentMatch1 = &match;
        {
            while (true)
            {
                int save = lexer.GetPos();
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch2 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = SpecifierParser::Specifier(lexer);
                        specifier.reset(static_cast<soulng::parser::Value<cmajor::ast::Specifiers>*>(match.value));
                        if (match.hit)
                        {
                            specifiers = specifiers | specifier->value;
                        }
                        *parentMatch2 = match;
                    }
                    if (match.hit)
                    {
                        *parentMatch1 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                        break;
                    }
                }
            }
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(specifiers));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match SpecifierParser::Specifier(CmajorLexer& lexer)
{
    soulng::parser::Match match(false);
    int pos = lexer.GetPos();
    soulng::lexer::Span span = lexer.GetSpan();
    switch (*lexer)
    {
        case PUBLIC:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::public_));
            }
            break;
        }
        case PROTECTED:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::protected_));
            }
            break;
        }
        case PRIVATE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::private_));
            }
            break;
        }
        case INTERNAL:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::internal_));
            }
            break;
        }
        case STATIC:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::static_));
            }
            break;
        }
        case VIRTUAL:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::virtual_));
            }
            break;
        }
        case OVERRIDE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::override_));
            }
            break;
        }
        case ABSTRACT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::abstract_));
            }
            break;
        }
        case INLINE:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::inline_));
            }
            break;
        }
        case EXPLICIT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::explicit_));
            }
            break;
        }
        case EXTERN:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::external_));
            }
            break;
        }
        case SUPPRESS:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::suppress_));
            }
            break;
        }
        case DEFAULT:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::default_));
            }
            break;
        }
        case CONSTEXPR:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::constexpr_));
            }
            break;
        }
        case CDECL:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::cdecl_));
            }
            break;
        }
        case NOTHROW:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::nothrow_));
            }
            break;
        }
        case THROW:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::throw_));
            }
            break;
        }
        case NEW:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::new_));
            }
            break;
        }
        case UNIT_TEST:
        {
            ++lexer;
            {
                return soulng::parser::Match(true, new soulng::parser::Value<cmajor::ast::Specifiers>(cmajor::ast::Specifiers::unit_test_));
            }
            break;
        }
    }
    return match;
}
