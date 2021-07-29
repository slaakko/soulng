#ifndef PARSERDECLARATIONPARSER_HPP
#define PARSERDECLARATIONPARSER_HPP
#include <soulng/cppcode/Declaration.hpp>
#include <soulng/cppcode/Type.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/tools/sng2html/sng2html/ParserDeclarationParser.parser' using soulng parser generator spg version 4.0.0

class ParserFileLexer;

struct ParserDeclarationParser
{
    static soulng::parser::Match BlockDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match SimpleDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match DeclSpecifierSeq(ParserFileLexer& lexer, soulng::cppcode::SimpleDeclaration* declaration);
    static soulng::parser::Match DeclSpecifier(ParserFileLexer& lexer);
    static soulng::parser::Match StorageClassSpecifier(ParserFileLexer& lexer);
    static soulng::parser::Match TypeSpecifier(ParserFileLexer& lexer);
    static soulng::parser::Match SimpleTypeSpecifier(ParserFileLexer& lexer);
    static soulng::parser::Match TypeName(ParserFileLexer& lexer);
    static soulng::parser::Match TemplateArgumentList(ParserFileLexer& lexer, soulng::cppcode::TypeName* typeName);
    static soulng::parser::Match TemplateArgument(ParserFileLexer& lexer);
    static soulng::parser::Match Typedef(ParserFileLexer& lexer);
    static soulng::parser::Match CVQualifier(ParserFileLexer& lexer);
    static soulng::parser::Match NamespaceAliasDefinition(ParserFileLexer& lexer);
    static soulng::parser::Match UsingDeclaration(ParserFileLexer& lexer);
    static soulng::parser::Match UsingDirective(ParserFileLexer& lexer);
};

#endif // PARSERDECLARATIONPARSER_HPP
