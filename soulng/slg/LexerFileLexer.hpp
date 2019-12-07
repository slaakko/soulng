#ifndef LexerFileLexer_HPP
#define LexerFileLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/soulng/slg/LexerFileLexer.lexer' using soulng lexer generator slg version 3.0.0

#include <soulng/lexer/Lexer.hpp>

class LexerFileLexer : public soulng::lexer::Lexer
{
public:
    LexerFileLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    LexerFileLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    int leftAngleCount;
private:
    int GetTokenId(int statementIndex);
};
#endif
