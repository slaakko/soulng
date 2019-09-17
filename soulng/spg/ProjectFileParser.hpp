#ifndef PROJECTFILEPARSER_HPP
#define PROJECTFILEPARSER_HPP
#include <soulng/spg/ProjectFile.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/ProjectFileParser.parser' using soulng parser generator spg version 1.0.0

class ProjectFileLexer;

struct ProjectFileParser
{
    static std::unique_ptr<soulng::spg::ProjectFile> Parse(ProjectFileLexer& lexer);
    static soulng::parser::Match ProjectFile(ProjectFileLexer& lexer);
    static soulng::parser::Match ProjectFileContent(ProjectFileLexer& lexer, soulng::spg::ProjectFile* projectFile);
    static soulng::parser::Match QualifiedId(ProjectFileLexer& lexer);
    static soulng::parser::Match SourceFile(ProjectFileLexer& lexer, soulng::spg::ProjectFile* projectFile);
};

#endif // PROJECTFILEPARSER_HPP