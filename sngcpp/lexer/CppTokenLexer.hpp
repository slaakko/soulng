#ifndef CppTokenLexer_HPP
#define CppTokenLexer_HPP

// this file has been automatically generated from 'D:/work/soulng-project/sngcpp/lexer/CppTokenLexer.lexer' using soulng lexer generator slg version 2.0.0

#include <sngcpp/lexer/CppLexerApi.hpp>
#include <sngcpp/ast/SourceCodeWriter.hpp>
#include <soulng/lexer/Lexer.hpp>

class SNGCPP_LEXER_API CppTokenLexer : public soulng::lexer::Lexer
{
public:
    CppTokenLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    CppTokenLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    sngcpp::ast::SourceCodeWriter* writer;
private:
    int GetTokenId(int statementIndex);
};
#endif
