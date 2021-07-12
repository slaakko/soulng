// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/DeclTypeEvaluator.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Type.hpp>
#include <stdexcept>

namespace sngcpp::symbols {

class DeclTypeEvaluator : public DefaultVisitor
{
public:
    DeclTypeEvaluator(Context* context_);
    TypeSymbol* GetType();
    void Visit(DeclTypeSpecifierNode& node) override;
    void Visit(NullPtrLiteralNode& node) override;
private:
    Context* context;
    TypeSymbol* type;
};

DeclTypeEvaluator::DeclTypeEvaluator(Context* context_) : context(context_), type(nullptr)
{
}

TypeSymbol* DeclTypeEvaluator::GetType()
{
    return type;
}

void DeclTypeEvaluator::Visit(DeclTypeSpecifierNode& node)
{
    node.Expression()->Accept(*this);
}

void DeclTypeEvaluator::Visit(NullPtrLiteralNode& node)
{
    type = context->GetSymbolTable()->MakeNullPtrTypeSymbol();
}

TypeSymbol* EvaluateDeclTypeNode(Node* declTypeNode, Context* context)
{
    DeclTypeEvaluator evaluator(context);
    declTypeNode->Accept(evaluator);
    TypeSymbol* type = evaluator.GetType();
    if (!type)
    {
        throw std::runtime_error("decltype evaluator incomplete");
    }
    return type;
}

} // sngcpp::symbols
