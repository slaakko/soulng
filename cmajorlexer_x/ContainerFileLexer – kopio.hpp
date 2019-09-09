#ifndef ContainerFileLexer_HPP
#define ContainerFileLexer_HPP
#include <soulng/cmajorlexer/CmajorLexerApi.hpp>
#include <soulng/cmajorlexer/TokenValueParsers.hpp>
#include <soulng/lexer/Lexer.hpp>

class CMAJOR_LEXER_API ContainerFileLexer : public soulng::lexer::Lexer
{
public:
    ContainerFileLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    std::string filePath;
private:
    int GetTokenId(int statementIndex);
};
#endif
