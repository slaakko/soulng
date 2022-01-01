// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Concept.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Concept.hpp>

namespace sngcpp::symbols {

class ConceptCreatorVisitor : public DefaultVisitor
{
public:
    ConceptCreatorVisitor(Context* context_);
    void Visit(ConceptDefinitionNode& node);
    void Visit(IdentifierNode& node) override;
private:
    Context* context;
};

ConceptCreatorVisitor::ConceptCreatorVisitor(Context* context_) : context(context_)
{
}

void ConceptCreatorVisitor::Visit(ConceptDefinitionNode& node)
{
    node.ConceptName()->Accept(*this);
}

void ConceptCreatorVisitor::Visit(IdentifierNode& node)
{
    std::vector<Symbol*> templateArguments;
    context->GetSymbolTable()->AddConcept(&node, templateArguments, context);
}

void AddConcept(Node* node, Context* context)
{
    ConceptCreatorVisitor visitor(context);
    node->Accept(visitor);
}

} // sngcpp::symbols
