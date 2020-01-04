#ifndef ParserFileLexer_HPP
#define ParserFileLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/tools/sng2html/sng2html/ParserFileLexer.lexer' using soulng lexer generator slg version 3.0.0

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
