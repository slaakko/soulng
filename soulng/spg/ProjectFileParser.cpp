#include "ProjectFileParser.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/spg/ProjectFileLexer.hpp>
#include <soulng/spg/ProjectFileTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/ProjectFileParser.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace soulng::lexer;
using namespace ProjectFileTokens;

std::unique_ptr<soulng::spg::ProjectFile> ProjectFileParser::Parse(ProjectFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::ProjectFile> value;
    ++lexer;
    int pos = lexer.GetPos();
    soulng::parser::Match match = ProjectFileParser::ProjectFile(lexer);
    value.reset(static_cast<soulng::spg::ProjectFile*>(match.value));
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
        lexer.ThrowExpectationFailure(pos, U"ProjectFile");
    }
    return value;
}

soulng::parser::Match ProjectFileParser::ProjectFile(ProjectFileLexer& lexer)
{
    std::unique_ptr<soulng::spg::ProjectFile> projectFile = std::unique_ptr<soulng::spg::ProjectFile>();
    std::unique_ptr<soulng::parser::Value<std::u32string>> projectName;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == PROJECT)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ProjectFileParser::QualifiedId(lexer);
                        projectName.reset(static_cast<soulng::parser::Value<std::u32string>*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch4 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, U"QualifiedId");
                        }
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
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
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == SEMICOLON)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            *parentMatch7 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                        }
                    }
                    if (match.hit)
                    {
                        projectFile.reset(new soulng::spg::ProjectFile(lexer.FileName(), projectName->value));
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch8 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch9 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = ProjectFileParser::ProjectFileContent(lexer, projectFile.get());
                if (match.hit)
                {
                    return soulng::parser::Match(true, projectFile.release());
                }
                *parentMatch9 = match;
            }
            *parentMatch8 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ProjectFileParser::ProjectFileContent(ProjectFileLexer& lexer, soulng::spg::ProjectFile* projectFile)
{
    soulng::parser::Match match(true);
    soulng::parser::Match* parentMatch0 = &match;
    {
        while (true)
        {
            int save = lexer.GetPos();
            {
                soulng::parser::Match match = ProjectFileParser::SourceFile(lexer, projectFile);
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

soulng::parser::Match ProjectFileParser::QualifiedId(ProjectFileLexer& lexer)
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
                int pos = lexer.GetPos();
                soulng::lexer::Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == ID)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s = span;
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
                                soulng::parser::Match match(false);
                                if (*lexer == DOT)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::lexer::Span span = lexer.GetSpan();
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
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
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
            return soulng::parser::Match(true, new soulng::parser::Value<std::u32string>(lexer.GetMatch(s)));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match ProjectFileParser::SourceFile(ProjectFileLexer& lexer, soulng::spg::ProjectFile* projectFile)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            if (*lexer == SOURCE)
            {
                ++lexer;
                match.hit = true;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == FILEPATH)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (match.hit)
                        {
                            *parentMatch4 = match;
                        }
                        else
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(FILEPATH)));
                        }
                    }
                    if (match.hit)
                    {
                        projectFile->AddSourceFile(lexer.filePath);
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch5 = &match;
        {
            soulng::parser::Match match(true);
            soulng::parser::Match* parentMatch6 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(false);
                if (*lexer == SEMICOLON)
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
                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                }
            }
            *parentMatch5 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}
