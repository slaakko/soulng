#ifndef LEXERDECLARATORPARSER_HPP
#define LEXERDECLARATORPARSER_HPP
#include <soulng/cppcode/Declaration.hpp>
#include <soulng/cppcode/Type.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/tools/sng2html/sng2html/LexerDeclaratorParser.parser' using soulng parser generator spg version 3.0.0

class LexerFileLexer;

struct LexerDeclaratorParser
{
    static soulng::parser::Match InitDeclaratorList(LexerFileLexer& lexer);
    static soulng::parser::Match InitDeclarator(LexerFileLexer& lexer);
    static soulng::parser::Match Declarator(LexerFileLexer& lexer);
    static soulng::parser::Match DirectDeclarator(LexerFileLexer& lexer);
    static soulng::parser::Match DeclaratorId(LexerFileLexer& lexer);
    static soulng::parser::Match TypeId(LexerFileLexer& lexer);
    static soulng::parser::Match Type(LexerFileLexer& lexer);
    static soulng::parser::Match TypeSpecifierSeq(LexerFileLexer& lexer, soulng::cppcode::TypeId* typeId);
    static soulng::parser::Match AbstractDeclarator(LexerFileLexer& lexer);
    static soulng::parser::Match DirectAbstractDeclarator(LexerFileLexer& lexer);
    static soulng::parser::Match PtrOperator(LexerFileLexer& lexer);
    static soulng::parser::Match CVQualifierSeq(LexerFileLexer& lexer);
    static soulng::parser::Match Initializer(LexerFileLexer& lexer);
    static soulng::parser::Match InitializerClause(LexerFileLexer& lexer);
    static soulng::parser::Match InitializerList(LexerFileLexer& lexer, soulng::cppcode::AssignInit* init);
};

#endif // LEXERDECLARATORPARSER_HPP
