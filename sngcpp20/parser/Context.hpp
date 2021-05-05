// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef PARSER_CONTEXT_INCLUDED
#define PARSER_CONTEXT_INCLUDED
#include <sngcpp20/parser/ParserApi.hpp>
#include <stack>

namespace sngcpp::ast
{
    class Node;
}

namespace sngcpp::symbols
{
    class SymbolTable;
}

namespace sngcpp::par {

enum class ContextFlags : int
{
    none = 0,
    parsingTemplateId = 1 << 0,
    parseMemberFunction = 1 << 1,
    parseSavedMemberFunctionBody = 1 << 2
};

PARSER_API inline ContextFlags operator|(ContextFlags left, ContextFlags right)
{
    return ContextFlags(int(left) | int(right));
}

PARSER_API inline ContextFlags operator&(ContextFlags left, ContextFlags right)
{
    return ContextFlags(int(left) & int(right));
}

PARSER_API inline ContextFlags operator~(ContextFlags flags)
{
    return ContextFlags(~int(flags));
}

class PARSER_API Context
{
public:
    Context();
    void PushFlags();
    void PopFlags();
    void PushSetFlag(ContextFlags flag);
    void PushResetFlag(ContextFlags flag);
    bool GetFlag(ContextFlags flag) const { return (flags & flag) != ContextFlags::none; }
    void PushNode(sngcpp::ast::Node* node_);
    void PopNode();
    sngcpp::ast::Node* GetNode() const { return node; }
    sngcpp::symbols::SymbolTable* GetSymbolTable() const { return symbolTable; }
    void SetSymbolTable(sngcpp::symbols::SymbolTable* symbolTable_) { symbolTable = symbolTable_; }
private:
    ContextFlags flags;
    std::stack<ContextFlags> flagStack;
    std::stack<sngcpp::ast::Node*> nodeStack;
    sngcpp::ast::Node* node;
    sngcpp::symbols::SymbolTable* symbolTable;
};

} // namespace sngcpp::par

#endif // PARSER_CONTEXT_INCLUDED
