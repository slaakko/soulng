#ifndef CommentLexer_HPP
#define CommentLexer_HPP
#include <soulng/lexer/Lexer.hpp>

class CommentLexer : public soulng::lexer::Lexer
{
public:
    CommentLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
private:
    int GetTokenId(int statementIndex);
};
#endif
