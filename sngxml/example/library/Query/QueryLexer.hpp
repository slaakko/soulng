#ifndef QueryLexer_HPP
#define QueryLexer_HPP

// this file has been automatically generated from 'C:/work/soulng/sngxml/example/library/Query/QueryLexer.lexer' using soulng lexer generator slg version 3.1.0

#include <Query/Api.hpp>
#include <soulng/lexer/Lexer.hpp>

class QUERY_API QueryLexer : public soulng::lexer::Lexer
{
public:
    QueryLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    QueryLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
private:
    int GetTokenId(int statementIndex);
};
#endif
