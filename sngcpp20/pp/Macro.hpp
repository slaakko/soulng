// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_MACRO_INCLUDED
#define SNGCPP_PP_MACRO_INCLUDED
#include <sngcpp20/pp/PPApi.hpp>
#include <soulng/lexer/Lexer.hpp>
#include <map>
#include <vector>

namespace sngcpp::pp {

using namespace soulng::lexer;

class PP;

struct PP_API MacroArgument
{
    std::vector<Token> tokens;
};

class PP_API Macro
{
public:
    Macro(const Lexeme& name_, const std::string& fileName_, int lineNumber_, const std::u32string& defitionStr_);
    virtual ~Macro();
    virtual bool IsObjectMacro() const { return false; }
    virtual bool IsFunctionMacro() const { return false; }
    virtual int Expand(int i, int e, const std::vector<Token>& tokens, soulng::lexer::Lexer* lexer, std::vector<Token>& expandedTokens, PP* pp, bool& end);
    virtual std::string ToString() const = 0;
    const Lexeme& Name() const { return name; }
    const std::string& FileName() const { return fileName; }
    int LineNumber() const { return lineNumber; }
    const std::u32string& DefinitionStr() const { return definitionStr; }
private:
    Lexeme name;
    std::string fileName;
    int lineNumber;
    std::u32string definitionStr;
};

class PP_API ObjectMacro : public Macro
{
public:
    ObjectMacro(const Lexeme& name_, const std::string& fileName_, int lineNumber_, const std::vector<Token>& replacementList_, const std::u32string& definitionStr_);
    bool IsObjectMacro() const override { return true; }
    const std::vector<Token>& ReplacementList() const { return replacementList; }
    void SetValue(const Token& value);
    void SetReplacementList(const std::vector<Token>& replacementList_);
    int Expand(int i, int e, const std::vector<Token>& tokens, soulng::lexer::Lexer* lexer, std::vector<Token>& expandedTokens, PP* pp, bool& end) override;
    std::string ToString() const override;
private:
    std::vector<Token> replacementList;
};

class PP_API FunctionMacro : public Macro
{
public:
    FunctionMacro(const Lexeme& name_, const std::string& fileName_, int lineNumber_, const std::vector<Token>& paramList_, const std::vector<Token>& replacementList_, 
        const std::u32string& definitionStr_, PP* pp);
    bool IsFunctionMacro() const override { return true; }
    bool MakeParamIndexMap();
    const std::vector<Token>& Parameters() const { return paramList; }
    const std::vector<Token>& ReplacementList() const { return replacementList; }
    int Expand(int i, int e, const std::vector<Token>& tokens, soulng::lexer::Lexer* lexer, std::vector<Token>& expandedTokens, PP* pp, bool& end) override;
    std::string ToString() const override;
    int GetParamIndex(const Lexeme& id) const;
    bool IsVariableArgs() const { return variableArgs; }
private:
    std::vector<Token> paramList;
    std::vector<Token> replacementList;
    std::map<Lexeme, int> paramIndexMap;
    bool variableArgs;
};

PP_API std::u32string ToString(const std::vector<Token>& replacementList);
PP_API std::u32string NoCommentString(const std::vector<Token>& replacementList);

} // namespace sngcpp::pp

#endif // SNGCPP_PP_MACRO_INCLUDED
