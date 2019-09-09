#include "CppIdentifierParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/spg/ParserFileLexer.hpp>
#include <soulng/spg/ParserFileTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng/spg/CppIdentifierParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace ParserFileTokens;

soulng::parser::Match CppIdentifierParser::CppIdentifier(ParserFileLexer& lexer)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        Span span = lexer.GetSpan();
        soulng::parser::Match match(false);
        if (*lexer == ID)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(lexer.GetMatch(span)));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match CppIdentifierParser::QualifiedCppId(ParserFileLexer& lexer)
{
    Span s = Span();
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
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        if (match.hit)
                        {
                            s = span;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        soulng::parser::Match match(true);
                        int save = lexer.GetPos();
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == COLONCOLON)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                *parentMatch6 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                            }
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
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
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(false);
                        if (*lexer == ID)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            s.end = span.end;
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch7 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch10 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch11 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == COLONCOLON)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch11 = match;
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
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == ID)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                        }
                                        *parentMatch13 = match;
                                    }
                                    *parentMatch12 = match;
                                }
                                *parentMatch11 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch10 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch9 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(lexer.GetMatch(s)));
        }
        *parentMatch0 = match;
    }
    return match;
}
