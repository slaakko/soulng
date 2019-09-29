#ifndef ContainerFileLexer_HPP
#define ContainerFileLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/examples/cmajor/lexer/ContainerFileLexer.lexer' using soulng lexer generator slg version 1.2.0

#include <cmajor/lexer/CmajorLexerApi.hpp>
#include <cmajor/lexer/TokenValueParsers.hpp>
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
