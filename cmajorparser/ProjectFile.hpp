#ifndef PROJECTFILE_HPP
#define PROJECTFILE_HPP
#include <cmajorast/Project.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/ProjectFile.parser' using soulng parser generator spg version 1.0.0

class ContainerFileLexer;

struct ProjectFileParser
{
    static std::unique_ptr<cmajor::ast::Project> Parse(ContainerFileLexer& lexer, std::string config, cmajor::ast::BackEnd backend);
    static soulng::parser::Match ProjectFile(ContainerFileLexer& lexer, std::string config, cmajor::ast::BackEnd backend);
    static soulng::parser::Match QualifiedId(ContainerFileLexer& lexer);
    static soulng::parser::Match Declaration(ContainerFileLexer& lexer);
    static soulng::parser::Match ReferenceDeclaration(ContainerFileLexer& lexer);
    static soulng::parser::Match SourceFileDeclaration(ContainerFileLexer& lexer);
    static soulng::parser::Match TextFileDeclaration(ContainerFileLexer& lexer);
    static soulng::parser::Match TargetDeclaration(ContainerFileLexer& lexer);
    static soulng::parser::Match Target(ContainerFileLexer& lexer);
};

#endif // PROJECTFILE_HPP
