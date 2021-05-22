// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_PP_INCLUDED
#define SNGCPP_PP_PP_INCLUDED
#include <sngcpp20/pp/Lines.hpp>
#include <sngcpp20/pp/Macro.hpp>
#include <sngcpp20/pp/Strings.hpp>
#include <sngcpp20/pp/Evaluator.hpp>
#include <soulng/lexer/Lexer.hpp>
#include <soulng/lexer/Token.hpp>
#include <map>
#include <set>
#include <stack>

namespace sngcpp::pp {

using namespace soulng::lexer;

struct PP_API PPSourceLocation
{
    PPSourceLocation();
    PPSourceLocation(int fileIndex_, int lineNumber_);
    int fileIndex;
    int lineNumber;
};

class PPResult;

class PP_API PPLineMapper : public LineMapper
{
public:
    PPLineMapper(PPResult& ppResult_);
    SourceInfo GetSourceInfo(int line) override;
private:
    PPResult& ppResult;
};

class PP_API PPResult
{
public:
    PPResult();
    PPResult(std::vector<std::string>&& fileNames_, Strings&& strings_, std::vector<std::unique_ptr<LogicalPhysicalMapping>>&& logicalPhysicalMappings_, std::map<int, PPSourceLocation>&& lineMap_, 
        const Lexeme& resultText_,  std::vector<std::string>&& errors_);
    Lexeme ResultText() const { return resultText;  }
    bool IsEmpty() const { return empty; }
    const PPSourceLocation* GetSourceLocation(int line) const;
    std::string GetFileName(int fileIndex) const;
    const LogicalPhysicalMapping* GetMapping(int fileIndex) const;
    std::string GetSourceLine(int fileIndex, int lineNumber);
    LineMapper* GetLineMapper() { return &lineMapper; }
    bool MSVCMode() const { return msvcMode; }
    void SetMSVCMode() { msvcMode = true; }
private:
    PPLineMapper lineMapper;
    bool empty;
    std::vector<std::string> fileNames;
    Strings strings;
    std::vector<std::unique_ptr<LogicalPhysicalMapping>> logicalPhysicalMappings;
    std::map<int, PPSourceLocation> lineMap;
    Lexeme resultText;
    std::vector<std::string> errors;
    bool msvcMode;
};

class PP_API PP
{
public:
    PP(EvaluationContext& evaluationContext_);
    PP(const PP&) = delete;
    PP& operator=(const PP&) = delete;
    bool IsKeywordToken(const Token& token) const;
    Macro* GetMacro(const Lexeme& name) const;
    const std::vector<std::string>& FileNames() const { return fileNames; }
    void AddFileName(const std::string& fileName);
    std::vector<std::string> GetFileNames() { return std::move(fileNames); }
    void AddLogicalPhysicalMapping(std::unique_ptr<LogicalPhysicalMapping>&& mapping);
    std::vector<std::unique_ptr<LogicalPhysicalMapping>> GetLogicalPhysicalMappings() { return std::move(logicalPhysicalMappings); }
    LogicalPhysicalMapping* CurrentLogicalPhysicalMapping() { return logicalPhysicalMappings.back().get(); }
    Strings& StringsRef() { return strings; }
    Strings GetStrings() { return std::move(strings); }
    std::vector<std::string> GetErrors() { return std::move(errors); }
    void DefineObjectMacro(const Lexeme& name, const std::vector<Token>& replacementList, const std::u32string& definitionStr);
    void DefineFunctionMacro(const Lexeme& name, const std::vector<Token>& paramList, const std::vector<Token>& replacementList, const std::u32string& definitionStr);
    void DefineObjectMacro(const std::u32string& name, const std::u32string& value);
    void Undefine(const Lexeme& name);
    void Line(const std::vector<Token>& tokens);
    void Pragma(const std::vector<Token>& tokens);
    void Error(const std::vector<Token>& tokens);
    void Include(const std::vector<Token>& tokens);
    bool IsMacroDefined(const Lexeme& macroName) const;
    void Ifdef(const Token& id);
    void Ifndef(const Token& id);
    void If(const std::vector<Token>& tokens);
    void Elif(const std::vector<Token>& tokens);
    void Else();
    void EndIf();
    bool Evaluate(const std::vector<Token>& tokens);
    void AddIncludePath(const std::string& includePath);
    std::vector<Token> MacroExpand(const std::vector<Token>& tokens);
    std::vector<Token> MacroExpand(const std::vector<Token>& tokens, bool saveDefined);
    int FileIndex() const { return fileIndex; }
    void IncFileIndex() { ++fileIndex; }
    bool Skip() const { return skip; }
    void PushFileName(const std::string& fileName_);
    void PopFileName();
    const std::string& FileName() const { return fileName; }
    int LineNumber() const { return lineNumber; }
    void SetLineNumber(int lineNumber_) { lineNumber = lineNumber_; }
    SourcePos GetSourcePos() const;
    void Emit(const Lexeme& lexeme);
    void AddError(const std::string& error);
    const std::vector<std::string>& Errors() const { return errors; }
    const Lexeme& Space() const { return space; }
    void AddToken(const Token& token);
    int Level() const { return level; }
    void IncLevel() { ++level; }
    void DecLevel() { --level; }
    std::vector<Token> GetTokens() { return std::move(tokens); }
    void SetTokens(std::vector<Token>&& tokens_) { tokens = std::move(tokens_); }
    Lexeme EmitText();
    ObjectMacro* FileMacro() { return fileMacro.get(); }
    ObjectMacro* LineMacro() { return lineMacro.get(); }
    void SetFile(const std::string& file_);
    void SetLine(int line_);
    int GetLineIndex() const { return lineIndex; }
    void SetLineIndex(int lineIndex_) { lineIndex = lineIndex_; }
    void PushLineIndex();
    void PopLineIndex();
    void PushLineNumber();
    void PopLineNumber();
    void SetSkipToEnd() { skipToEnd = true; }
    void ResetSkipToEnd() { skipToEnd = false; }
    bool SkipToEnd() const { return skipToEnd; }
    void AddProcessedHeader(const std::string& header);
    bool IsHeaderProcessed(const std::string& header) const;
    int FileNameStackSize() const { return fileNameStack.size(); }
    void PrintMacros();
    const Lexeme& SNGCPPMSVCModeMacroName() const { return sngcppMSVCModeMacroName; }
    void MapLine(int lineNumber, const PPSourceLocation& sourceLocation);
    std::map<int, PPSourceLocation> GetLineMap() { return std::move(lineMap); }
private:
    EvaluationContext& evaluationContext;
    Lexeme space;
    Strings strings;
    std::vector<std::string> fileNames;
    std::vector<std::unique_ptr<LogicalPhysicalMapping>> logicalPhysicalMappings;
    std::map<Lexeme, Macro*> macroMap;
    std::vector<std::unique_ptr<Macro>> macros;
    std::vector<std::string> includePaths;
    int fileIndex;
    bool skip;
    std::stack<bool> skipStack;
    std::string fileName;
    std::stack<std::string> fileNameStack;
    std::vector<std::string> errors;
    std::vector<Token> tokens;
    int lineNumber;
    std::stack<int> lineNumberStack;
    int level;
    std::unique_ptr<ObjectMacro> fileMacro;
    std::u32string fileStr;
    std::unique_ptr<ObjectMacro> lineMacro;
    std::u32string lineStr;
    int lineIndex;
    std::stack<int> lineIndexStack;
    bool skipToEnd;
    std::set<std::string> processedHeaders;
    Lexeme sngcppMSVCModeMacroName;
    std::map<int, PPSourceLocation> lineMap;
};

PP_API Token ConvertPPTokenToTextToken(const Token& ppToken);

PP_API std::unique_ptr<PPResult> Preprocess(const std::string& fileName, PP* pp);

PP_API std::vector<Token> CombineAdjacentStringLiterals(const std::vector<Token>& tokens, PP* pp);

PP_API void InitPP();
PP_API void DonePP();

} // namespace sngcpp::pp

#endif // SNGCPP_PP_PP_INCLUDED
