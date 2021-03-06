#ifndef ParserFileLexer_HPP
#define ParserFileLexer_HPP

// this file has been automatically generated from 'C:/work/soulng/soulng/spg/ParserFileLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <soulng/lexer/Lexer.hpp>

class ParserFileLexer : public soulng::lexer::Lexer
{
public:
    ParserFileLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    ParserFileLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    int leftAngleCount;
    bool parsingIncludeDeclaration;
private:
    int GetTokenId(int statementIndex);
};
#endif
