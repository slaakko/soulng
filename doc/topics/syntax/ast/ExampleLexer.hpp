#ifndef ExampleLexer_HPP
#define ExampleLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/doc/topics/syntax/ast/ExampleLexer.lexer' using soulng lexer generator slg version 1.0.0

#include <soulng/lexer/Lexer.hpp>

class ExampleLexer : public soulng::lexer::Lexer
{
public:
    ExampleLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
private:
    int GetTokenId(int statementIndex);
};
#endif
