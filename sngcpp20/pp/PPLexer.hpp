#ifndef PPLexer_HPP
#define PPLexer_HPP

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/pp/PPLexer.lexer' using soulng lexer generator slg version 3.10.0

#include <sngcpp20/pp/PP.hpp>
#include <soulng/lexer/Lexer.hpp>

class PP_API PPLexer : public soulng::lexer::Lexer
{
public:
    PPLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    PPLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    sngcpp::pp::PP* pp;
private:
    int GetTokenId(int statementIndex);
};
#endif
