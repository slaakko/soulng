#ifndef ParserFileTokenLexer_HPP
#define ParserFileTokenLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/tools/gendoc/html/ParserFileTokenLexer.lexer' using soulng lexer generator slg version 2.0.0

#include <soulng/lexer/Lexer.hpp>

class ParserFileTokenLexer : public soulng::lexer::Lexer
{
public:
    ParserFileTokenLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    ParserFileTokenLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
private:
    int GetTokenId(int statementIndex);
};
#endif
