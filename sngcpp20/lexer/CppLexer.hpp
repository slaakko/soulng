#ifndef CppLexer_HPP
#define CppLexer_HPP

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/lexer/CppLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <sngcpp20/lexer/CppLexerApi.hpp>
#include <soulng/lexer/Lexer.hpp>

class LEXER_API CppLexer : public soulng::lexer::Lexer
{
public:
    CppLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    CppLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    int langleCount;
private:
    int GetTokenId(int statementIndex);
};
#endif
