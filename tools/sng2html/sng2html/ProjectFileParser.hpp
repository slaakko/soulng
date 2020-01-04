#ifndef PROJECTFILEPARSER_HPP
#define PROJECTFILEPARSER_HPP
#include <sng2html/sng2html/ProjectFile.hpp>
#include <memory>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/tools/sng2html/sng2html/ProjectFileParser.parser' using soulng parser generator spg version 3.0.0

class ProjectFileLexer;

struct ProjectFileParser
{
    static std::unique_ptr<sng2html::sng2html::ProjectFile> Parse(ProjectFileLexer& lexer);
    static soulng::parser::Match ProjectFile(ProjectFileLexer& lexer);
    static soulng::parser::Match ProjectFileContent(ProjectFileLexer& lexer, sng2html::sng2html::ProjectFile* projectFile);
    static soulng::parser::Match QualifiedId(ProjectFileLexer& lexer);
    static soulng::parser::Match SourceFile(ProjectFileLexer& lexer, sng2html::sng2html::ProjectFile* projectFile);
};

#endif // PROJECTFILEPARSER_HPP
