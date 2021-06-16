// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Enum.hpp>
#include <sngcpp20/symbols/DeclarationProcessor.hpp>
#include <sngcpp20/symbols/EnumTypeSymbol.hpp>
#include <sngcpp20/symbols/Evaluator.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Enum.hpp>
#include <sngcpp20/ast/Literal.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

class EnumCreatorVisitor : public DefaultVisitor
{
public:
    enum class Stage
    {
        createEnumType, createEnumerators
    };
    EnumCreatorVisitor(Stage stage_, Context* context_);
    void Visit(EnumSpecifierNode& node) override;
    void Visit(OpaqueEnumDeclarationNode& node) override;
    void Visit(EnumHeadNode& node) override;
    void Visit(EnumBaseNode& node) override;
    void Visit(IdentifierNode& node) override;
    void Visit(UnnamedNode& node) override;
    void Visit(EnumeratorDefinitionNode& node) override;
    void Visit(IntegerLiteralNode& node) override;
private:
    Stage stage;
    Context* context;
    EnumSpecifierNode* specifierNode;
    Node* idNode;
    TypeSymbol* enumBaseType;
    EnumTypeSymbol* enumType;
    bool first;
    uint64_t value;
};

EnumCreatorVisitor::EnumCreatorVisitor(Stage stage_, Context* context_) : 
    context(context_), stage(stage_), specifierNode(nullptr), idNode(nullptr), enumBaseType(nullptr), enumType(nullptr), value(0), first(true)
{
}

void EnumCreatorVisitor::Visit(EnumSpecifierNode& node)
{
    if (stage == Stage::createEnumType)
    {
        specifierNode = &node;
        node.EnumHead()->Accept(*this);
    }
    else if (stage == Stage::createEnumerators)
    {
        Symbol* symbol = context->GetSymbolTable()->GetSymbol(&node);
        if (symbol->IsEnumTypeSymbol())
        {
            enumType = static_cast<EnumTypeSymbol*>(symbol);
        }
        else
        {
            throw Exception("enum type expected", node.GetSourcePos(), context);
        }
        VisitListContent(node);
    }
}

void EnumCreatorVisitor::Visit(OpaqueEnumDeclarationNode& node)
{
    node.EnumHeadName()->Accept(*this);
    enumBaseType = GetFundamentalType(DeclarationFlags::intFlag, node.GetSourcePos(), context);
    if (node.EnumBase())
    {
        node.EnumBase()->Accept(*this);
    }
    context->GetSymbolTable()->BeginEnumType(nullptr, idNode, enumBaseType, context);
}

void EnumCreatorVisitor::Visit(EnumHeadNode& node)
{
    node.EnumHeadName()->Accept(*this);
    enumBaseType = GetFundamentalType(DeclarationFlags::intFlag, node.GetSourcePos(), context);
    if (node.EnumBase())
    {
        node.EnumBase()->Accept(*this);
    }
    context->GetSymbolTable()->BeginEnumType(specifierNode, idNode, enumBaseType, context);
}

void EnumCreatorVisitor::Visit(EnumBaseNode& node)
{
    enumBaseType = ProcessTypeSpecifierSequence(node.Child(), context);
}

void EnumCreatorVisitor::Visit(IdentifierNode& node)
{
    idNode = &node;
}

void EnumCreatorVisitor::Visit(UnnamedNode& node)
{
    idNode = &node;
}

void EnumCreatorVisitor::Visit(EnumeratorDefinitionNode& node)
{
    EvaluationContext evaluationContext;
    Value* val = nullptr;
    std::u32string rep;
    if (node.Value())
    {
        first = false;
        val = EvaluateConstantExpression(node.Value(), evaluationContext);
        if (val->Kind() == ValueKind::integerValue)
        {
            IntegerValue* integerValue = static_cast<IntegerValue*>(val);
            value = integerValue->GetValue();
            rep = val->Rep();
        }
        else if (val->Kind() == ValueKind::boolValue)
        {
            BoolValue* boolValue = static_cast<BoolValue*>(val);
            value = boolValue->GetValue();
            rep = val->Rep();
        }
        else
        {
            throw Exception("integer or Boolean value expected", node.GetSourcePos(), context);
        }
    }
    else if (first)
    {
        first = false;
        rep = ToUtf32(std::to_string(value));
    }
    else
    {
        ++value;
        rep = ToUtf32(std::to_string(value));
    }
    node.Enumerator()->Accept(*this);
    if (idNode)
    {
        enumType->AddEnumerator(new EnumeratorSymbol(idNode->Str(), value, rep));
    }
    else
    {
        throw Exception("identifier expected", node.GetSourcePos(), context);
    }
}

void EnumCreatorVisitor::Visit(IntegerLiteralNode& node)
{
    value = node.Value();
}

void BeginEnumType(Node* node, Context* context)
{
    EnumCreatorVisitor visitor(EnumCreatorVisitor::Stage::createEnumType, context);
    node->Accept(visitor);
}

void EndEnumType(Context* context)
{
    context->GetSymbolTable()->EndEnumType();
}

void AddEnumerators(Node* node, Context* context)
{
    EnumCreatorVisitor visitor(EnumCreatorVisitor::Stage::createEnumerators, context);
    node->Accept(visitor);
}

} // sngcpp::symbols
