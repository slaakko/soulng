#ifndef CPPDECLARATION_HPP
#define CPPDECLARATION_HPP
#include <soulng/cppcode/Declaration.hpp>
#include <soulng/cppcode/Type.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng/slg/CppDeclaration.parser' using soulng parser generator spg version 1.0.0

class LexerFileLexer;

struct CppDeclarationParser
{
    static soulng::parser::Match BlockDeclaration(LexerFileLexer& lexer);
    static soulng::parser::Match SimpleDeclaration(LexerFileLexer& lexer);
    static soulng::parser::Match DeclSpecifierSeq(LexerFileLexer& lexer, soulng::cppcode::SimpleDeclaration* declaration);
    static soulng::parser::Match DeclSpecifier(LexerFileLexer& lexer);
    static soulng::parser::Match StorageClassSpecifier(LexerFileLexer& lexer);
    static soulng::parser::Match TypeSpecifier(LexerFileLexer& lexer);
    static soulng::parser::Match SimpleTypeSpecifier(LexerFileLexer& lexer);
    static soulng::parser::Match TypeName(LexerFileLexer& lexer);
    static soulng::parser::Match TemplateArgumentList(LexerFileLexer& lexer, soulng::cppcode::TypeName* typeName);
    static soulng::parser::Match TemplateArgument(LexerFileLexer& lexer);
    static soulng::parser::Match Typedef(LexerFileLexer& lexer);
    static soulng::parser::Match CVQualifier(LexerFileLexer& lexer);
    static soulng::parser::Match NamespaceAliasDefinition(LexerFileLexer& lexer);
    static soulng::parser::Match UsingDeclaration(LexerFileLexer& lexer);
    static soulng::parser::Match UsingDirective(LexerFileLexer& lexer);
};

#endif // CPPDECLARATION_HPP
