#ifndef LexerFileLexer_HPP
#define LexerFileLexer_HPP
#include <soulng/lexer/Lexer.hpp>

class LexerFileLexer : public soulng::lexer::Lexer
{
public:
    LexerFileLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    int leftAngleCount;
private:
    int GetTokenId(int statementIndex);
};
#endif
