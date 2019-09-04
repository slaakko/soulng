#ifndef CmajorLexer_HPP
#define CmajorLexer_HPP
#include <soulng/cmajorlexer/TokenValueParsers.hpp>
#include <soulng/cmajorlexer/CmajorLexerApi.hpp>
#include <soulng/lexer/Lexer.hpp>

class CMAJOR_LEXER_API CmajorLexer : public soulng::lexer::Lexer
{
public:
    CmajorLexer(const std::u32string& content_, const std::string& fileName_, int fileIndex_);
    int NextState(int state, char32_t c) override;
    double floatingLit;
    bool floatingLitFloat;
    uint64_t intLit;
    bool intLitUnsigned;
    char32_t chrLit;
    int chrLitPrefix;
    std::u32string strLit;
    int strLitPrefix;
    int leftAngleCount;
    bool parsingOperatorFunctionGroupId;
private:
    int GetTokenId(int statementIndex);
};
#endif
