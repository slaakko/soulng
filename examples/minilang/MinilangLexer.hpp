#ifndef MinilangLexer_HPP
#define MinilangLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/examples/minilang/minilang.lexer' using soulng lexer generator slg version 1.0.0

#include <soulng/lexer/Lexer.hpp>

class MinilangLexer : public soulng::lexer::Lexer
{
public:
    MinilangLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
private:
    int GetTokenId(int statementIndex);
};
#endif
