#ifndef RegExLexer_HPP
#define RegExLexer_HPP

// this file has been automatically generated from 'C:/work/soulng/soulng/slg/RegExLexer.lexer' using soulng lexer generator slg version 3.10.0

#include <soulng/lexer/Lexer.hpp>

class RegExLexer : public soulng::lexer::Lexer
{
public:
    RegExLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    RegExLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
private:
    int GetTokenId(int statementIndex);
};
#endif
