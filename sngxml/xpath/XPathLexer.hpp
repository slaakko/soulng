#ifndef XPathLexer_HPP
#define XPathLexer_HPP

// this file has been automatically generated from 'C:/work/soulng/sngxml/xpath/XPathLexer.lexer' using soulng lexer generator slg version 3.1.0

#include <sngxml/xpath/XPathApi.hpp>
#include <soulng/lexer/Lexer.hpp>

class SNGXML_XPATH_API XPathLexer : public soulng::lexer::Lexer
{
public:
    XPathLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    XPathLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
private:
    int GetTokenId(int statementIndex);
};
#endif
