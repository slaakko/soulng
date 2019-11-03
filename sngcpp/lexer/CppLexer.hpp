#ifndef CppLexer_HPP
#define CppLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/lexer/CppLexer.lexer' using soulng lexer generator slg version 2.0.0

#include <sngcpp/lexer/CppLexerApi.hpp>
#include <soulng/lexer/Lexer.hpp>

class SNGCPP_LEXER_API CppLexer : public soulng::lexer::Lexer
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