// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Class.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/parser/CompoundStatementRecorder.hpp>
#include <sngcpp20/ast/Function.hpp>
#include <sngcpp20/ast/Visitor.hpp>

namespace sngcpp::symbols {

class ClassCreatorVisitor : public DefaultVisitor
{
public:
    ClassCreatorVisitor(Context* context_);
    void Visit(ClassSpecifierNode& node);
    void Visit(IdentifierNode& node) override;
    void Visit(UnnamedNode& node) override;
private:
    Context* context;
    ClassSpecifierNode* specifierNode;
};

ClassCreatorVisitor::ClassCreatorVisitor(Context* context_) : context(context_), specifierNode(nullptr)
{
}

void ClassCreatorVisitor::Visit(ClassSpecifierNode& node)
{
    specifierNode = &node;
    node.ClassHead()->Accept(*this);
}

void ClassCreatorVisitor::Visit(IdentifierNode& node)
{
    context->GetSymbolTable()->BeginClass(specifierNode, &node, context);
}

void ClassCreatorVisitor::Visit(UnnamedNode& node)
{
    context->GetSymbolTable()->BeginClass(specifierNode , &node, context);
}

void BeginClass(Node* node, Context* context)
{
    ClassCreatorVisitor visitor(context);
    node->Accept(visitor);
    context->PushSetFlag(ContextFlags::parseMemberFunction | ContextFlags::skipSimpleDeclarations);
}

void EndClass(Context* context)
{
    context->PopFlags();
    context->GetSymbolTable()->EndClass();
}

class InlineMemberFunctionParserVisitor : public DefaultVisitor
{
public:
    InlineMemberFunctionParserVisitor(Context* context_);
    void Visit(FunctionDefinitionNode& node) override;
private:
    Context* context;
};

InlineMemberFunctionParserVisitor::InlineMemberFunctionParserVisitor(Context* context_) : context(context_)
{
}

void InlineMemberFunctionParserVisitor::Visit(FunctionDefinitionNode& node)
{
    FunctionBodyNode* functionBody = static_cast<FunctionBodyNode*>(node.FunctionBody());
    CompoundStatementNode* compoundStatementNode = static_cast<CompoundStatementNode*>(functionBody->Child());
    sngcpp::par::RecordedParse(compoundStatementNode, context);
}

void ParseInlineMemberFunctions(Node* classSpecifierNode, Context* context)
{
    InlineMemberFunctionParserVisitor visitor(context);
    classSpecifierNode->Accept(visitor);
}

} // sngcpp::symbols
