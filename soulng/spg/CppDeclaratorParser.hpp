#ifndef CPPDECLARATORPARSER_HPP
#define CPPDECLARATORPARSER_HPP
#include <soulng/cppcode/Declaration.hpp>
#include <soulng/cppcode/Type.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/soulng/spg/CppDeclaratorParser.parser' using soulng parser generator spg version 1.2.0

class ParserFileLexer;

struct CppDeclaratorParser
{
    static soulng::parser::Match InitDeclaratorList(ParserFileLexer& lexer);
    static soulng::parser::Match InitDeclarator(ParserFileLexer& lexer);
    static soulng::parser::Match Declarator(ParserFileLexer& lexer);
    static soulng::parser::Match DirectDeclarator(ParserFileLexer& lexer);
    static soulng::parser::Match DeclaratorId(ParserFileLexer& lexer);
    static soulng::parser::Match TypeId(ParserFileLexer& lexer);
    static soulng::parser::Match Type(ParserFileLexer& lexer);
    static soulng::parser::Match TypeSpecifierSeq(ParserFileLexer& lexer, soulng::cppcode::TypeId* typeId);
    static soulng::parser::Match AbstractDeclarator(ParserFileLexer& lexer);
    static soulng::parser::Match DirectAbstractDeclarator(ParserFileLexer& lexer);
    static soulng::parser::Match PtrOperator(ParserFileLexer& lexer);
    static soulng::parser::Match CVQualifierSeq(ParserFileLexer& lexer);
    static soulng::parser::Match Initializer(ParserFileLexer& lexer);
    static soulng::parser::Match InitializerClause(ParserFileLexer& lexer);
    static soulng::parser::Match InitializerList(ParserFileLexer& lexer, soulng::cppcode::AssignInit* init);
};

#endif // CPPDECLARATORPARSER_HPP
