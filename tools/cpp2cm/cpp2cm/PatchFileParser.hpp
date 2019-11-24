#ifndef PATCHFILEPARSER_HPP
#define PATCHFILEPARSER_HPP
#include <cpp2cm/cpp2cm/Patch.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/tools/cpp2cm/cpp2cm/PatchFileParser.parser' using soulng parser generator spg version 2.0.0

class TrivialLexer;

struct PatchFileParser
{
    static std::unique_ptr<cpp2cm::PatchFile> Parse(TrivialLexer& lexer);
    static soulng::parser::Match PatchFile(TrivialLexer& lexer);
    static soulng::parser::Match PatchLine(TrivialLexer& lexer);
    static soulng::parser::Match FileName(TrivialLexer& lexer);
    static soulng::parser::Match LineNumber(TrivialLexer& lexer);
    static soulng::parser::Match Patch(TrivialLexer& lexer);
    static soulng::parser::Match Insert(TrivialLexer& lexer);
    static soulng::parser::Match Delete(TrivialLexer& lexer);
    static soulng::parser::Match Modify(TrivialLexer& lexer);
    static soulng::parser::Match Text(TrivialLexer& lexer);
    static soulng::parser::Match Newline(TrivialLexer& lexer);
};

#endif // PATCHFILEPARSER_HPP
