#ifndef CppTokenLexer_HPP
#define CppTokenLexer_HPP

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/lexer/CppTokenLexer.lexer' using soulng lexer generator slg version 3.10.0

#include <sngcpp20/lexer/CppLexerApi.hpp>
#include <sngcpp20/ast/SourceCodeWriter.hpp>
#include <soulng/lexer/Lexer.hpp>

class LEXER_API CppTokenLexer : public soulng::lexer::Lexer
{
public:
    CppTokenLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    CppTokenLexer(const char32_t* start_, const char32_t* end_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    bool inBlockComment;
    sngcpp::ast::SourceCodeWriter* writer;
private:
    int GetTokenId(int statementIndex);
};
#endif
