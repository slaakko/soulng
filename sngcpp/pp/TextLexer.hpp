#ifndef TextLexer_HPP
#define TextLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/pp/TextLexer.lexer' using soulng lexer generator slg version 3.0.0

#include <sngcpp/pp/PP.hpp>
#include <soulng/lexer/Lexer.hpp>

class SNGCPP_PP_API TextLexer : public soulng::lexer::Lexer
{
public:
    TextLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    TextLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    sngcpp::pp::PP* pp;
private:
    int GetTokenId(int statementIndex);
};
#endif
