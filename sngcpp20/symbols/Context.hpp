// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SYMBOLS_CONTEXT_INCLUDED
#define SYMBOLS_CONTEXT_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <string>
#include <stack>

namespace soulng::lexer
{
    class Lexer;
    struct SourcePos;
}

namespace sngcpp::ast
{
    class Node;
}

namespace sngcpp::symbols {

class SymbolTable;

enum class ContextFlags : int
{
    none = 0,
    parsingTemplateId = 1 << 0,
    parseMemberFunction = 1 << 1,
    parseSavedMemberFunctionBody = 1 << 2,
    parsingTemplateDeclaration = 1 << 3,
    assumeType = 1 << 4,
    hasDefiningTypeSpecifier = 1 << 5,
    msvcMode = 1 << 6
};

SYMBOLS_API inline ContextFlags operator|(ContextFlags left, ContextFlags right)
{
    return ContextFlags(int(left) | int(right));
}

SYMBOLS_API inline ContextFlags operator&(ContextFlags left, ContextFlags right)
{
    return ContextFlags(int(left) & int(right));
}

SYMBOLS_API inline ContextFlags operator~(ContextFlags flags)
{
    return ContextFlags(~int(flags));
}

class SYMBOLS_API Context
{
public:
    Context();
    void PushFlags();
    void PopFlags();
    void PushSetFlag(ContextFlags flag);
    void PushResetFlag(ContextFlags flag);
    void SetFlag(ContextFlags flag) { flags = flags | flag; }
    bool GetFlag(ContextFlags flag) const { return (flags & flag) != ContextFlags::none; }
    void ResetFlag(ContextFlags flag) { flags = flags & ~flag; }
    void PushNode(sngcpp::ast::Node* node_);
    void PopNode();
    sngcpp::ast::Node* GetNode() const { return node; }
    SymbolTable* GetSymbolTable() const { return symbolTable; }
    void SetSymbolTable(SymbolTable* symbolTable_) { symbolTable = symbolTable_; }
    soulng::lexer::Lexer* GetLexer() const { return lexer; }
    void SetLexer(soulng::lexer::Lexer* lexer_) { lexer = lexer_; }
private:
    ContextFlags flags;
    std::stack<ContextFlags> flagStack;
    std::stack<sngcpp::ast::Node*> nodeStack;
    sngcpp::ast::Node* node;
    SymbolTable* symbolTable;
    soulng::lexer::Lexer* lexer;
};

SYMBOLS_API std::string MappedFileName(Context* context, const soulng::lexer::SourcePos& sourcePos);
SYMBOLS_API std::string MappedFileLine(Context* context, const soulng::lexer::SourcePos& sourcePos);
SYMBOLS_API std::string MappedErrorLines(Context* context, const soulng::lexer::SourcePos& sourcePos);
SYMBOLS_API int MappedLineNumber(Context* context, const soulng::lexer::SourcePos& sourcePos);

} // namespace sngcpp::symbols

#endif // PARSER_CONTEXT_INCLUDED
