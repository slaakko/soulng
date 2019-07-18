// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXER_LEXER_INCLUDED
#define SOULNG_LEXER_LEXER_INCLUDED
#include <soulng/lexer/Keyword.hpp>
#include <vector>
#include <list>
#include <map>

namespace soulng { namespace lexer {

class LEXER_API Lexer
{
public:
    Lexer(const std::u32string& content_);
    virtual ~Lexer();
    int operator*() const { return current->id; }
    void operator++();
    int GetPos() const { return current - tokens.begin(); }
    void SetPos(int pos) { current = tokens.begin() + pos; }
    virtual void GetNextToken();
    void SetKeywordMap(KeywordMap* keywordMap_) { keywordMap = keywordMap_; }
    KeywordMap* GetKeywordMap() { return keywordMap; }
    int GetKeywordToken(const Lexeme& lexeme) const;
protected:
    Lexeme lexeme;
    Token token;
private:
    std::u32string content;
    KeywordMap* keywordMap;
    const char32_t* start;
    const char32_t* end;
    const char32_t* pos;
    int state;
    char32_t c;
    int line;
    std::vector<Token> tokens;
    std::vector<Token>::iterator current;
    void NextToken();
};

} } // namespace soulng::lexer

#endif // SOULNG_LEXER_LEXER_INCLUDED
