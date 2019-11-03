#ifndef PPPARSER_HPP
#define PPPARSER_HPP
#include <sngcpp/pp/PP.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/pp/PPParser.parser' using soulng parser generator spg version 2.0.0

class PPLexer;

struct SNGCPP_PP_API PPLineParser
{
    static void Parse(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match PPLine(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match Define(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match Include(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match If(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match Ifdef(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match Ifndef(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match Elif(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match Else(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match Endif(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match Other(PPLexer& lexer, sngcpp::pp::PP* pp);
    static soulng::parser::Match PPToken(PPLexer& lexer, std::vector<soulng::lexer::Token>* tokens);
};

#endif // PPPARSER_HPP
