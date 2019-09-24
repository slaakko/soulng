// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXER_LEXER_INCLUDED
#define SOULNG_LEXER_LEXER_INCLUDED
#include <soulng/lexer/Keyword.hpp>
#include <soulng/lexer/Span.hpp>
#include <vector>
#include <list>
#include <map>

namespace soulng { namespace lexer {

class SOULNG_LEXER_API Lexer
{
public:
    Lexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    virtual ~Lexer();
    int operator*() const { return current->id; }
    void operator++();
    int GetPos() const { return current - tokens.begin(); }
    void SetPos(int pos) { current = tokens.begin() + pos;  }
    virtual int NextState(int state, char32_t c);
    void SetKeywordMap(KeywordMap* keywordMap_) { keywordMap = keywordMap_; }
    KeywordMap* GetKeywordMap() { return keywordMap; }
    int GetKeywordToken(const Lexeme& lexeme) const;
    void Retract() { token.match.end = pos; }
    const std::string& FileName() const { return fileName; }
    Span GetSpan() const { return Span(fileIndex, line, GetPos()); }
    Token GetToken(int tokenIndex) const;
    Token token;
    std::u32string GetMatch(const Span& span) const;
    std::u32string ErrorLines(const Token& token) const;
    std::u32string ErrorLines(const Span& span) const;
    void ThrowExpectationFailure(int pos, const std::u32string& name);
protected:
    Lexeme lexeme;
    int line;
private:
    std::u32string content;
    std::string fileName;
    int fileIndex;
    KeywordMap* keywordMap;
    const char32_t* start;
    const char32_t* end;
    const char32_t* pos;
    std::vector<Token> tokens;
    std::vector<Token>::iterator current;
    void NextToken();
};

} } // namespace soulng::lexer

#endif // SOULNG_LEXER_LEXER_INCLUDED
