// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_INCLUDED
#define SNGCPP_PP_INCLUDED
#include <sngcpp/pp/File.hpp>
#include <sngcpp/pp/Evaluator.hpp>
#include <soulng/lexer/Token.hpp>
#include <vector>
#include <string>
#include <map>
#include <stack>

namespace sngcpp { namespace pp {

SNGCPP_PP_API extern const soulng::lexer::Lexeme ndebug;

struct SNGCPP_PP_API PP
{
    PP(EvaluationContext& context_);
    virtual ~PP();
    PP(const PP&) = delete;
    PP(PP&&) = delete;
    PP& operator=(const PP&) = delete;
    PP& operator=(PP&&) = delete;
    std::vector<soulng::lexer::Token>* BeginDefine(const soulng::lexer::Lexeme& id);
    void EndDefine(std::vector<soulng::lexer::Token>& ppTokens);
    void Define(const soulng::lexer::Lexeme& lexeme);
    bool IsDefined(const soulng::lexer::Lexeme& lexeme) const;
    bool IsKeywordToken(const soulng::lexer::Token& token) const;
    bool IsProjectHeaderFile(const std::string& headerFilePath) const;
    void Include(bool isAngleHeader, const std::string& headerName);
    bool Evaluate(const std::vector<soulng::lexer::Token>& exprPPTokens) const;
    void If(const std::vector<soulng::lexer::Token>& exprPPTokens);
    void Ifdef(bool defined);
    void Ifndef(bool defined);
    void Elif(const std::vector<soulng::lexer::Token>& exprPPTokens);
    void Else();
    void Endif();
    void Emit(const char32_t* s);
    void Emit(const soulng::lexer::Lexeme& lexeme);
    void Emit(const char32_t* s, const soulng::lexer::Lexeme& lexeme, int tokenID);
    int fileIndex;
    bool save;
    bool process;
    std::stack<bool> processStack;
    bool processed;
    std::stack<bool> processedStack;
    bool elseGroupProcessed;
    std::stack<bool> elseGroupProcessedStack;
    bool inIfGroup;
    std::stack<bool> inIfGroupStack;
    bool verbose;
    std::string fileName;
    int line;
    std::u32string text;
    std::u32string ctext;
    std::vector<std::unique_ptr<File>> files;
    std::map<soulng::lexer::Lexeme, std::vector<soulng::lexer::Token>> macroMap;
    std::string root;
    std::vector<std::string> includePath;
    ProjectHeaderFileSet* projectHeaderFileSet;
    EvaluationContext& context;
    bool rootMode;
    std::vector<std::string> headerFilePaths;
    std::vector<soulng::lexer::Token>* tokens;
};

SNGCPP_PP_API void InitTextTokenCppTokenMap();
SNGCPP_PP_API void InitPPTokenTextTokenMap();
SNGCPP_PP_API std::string ParseAngleHeaderName(const std::string& fileName, const soulng::lexer::Token& headerNameToken);
SNGCPP_PP_API std::string ParseQuoteHeaderName(const std::string& fileName, const soulng::lexer::Token& headerNameToken);
SNGCPP_PP_API void Preprocess(const std::string& fileName, PP* pp);

} } // namespace sngcpp::pp

#endif // SNGCPP_PP_INCLUDED
