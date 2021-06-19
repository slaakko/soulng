// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Class.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/DeclarationProcessor.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/Evaluator.hpp>
#include <sngcpp20/parser/CompoundStatementRecorder.hpp>
#include <sngcpp20/ast/Literal.hpp>
#include <soulng/util/Unicode.hpp>
#include <sngcpp20/ast/Function.hpp>
#include <sngcpp20/ast/Template.hpp>
#include <sngcpp20/ast/Type.hpp>
#include <sngcpp20/ast/Visitor.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

class ClassCreatorVisitor : public DefaultVisitor
{
public:
    enum class Stage
    {
        createClass, addBases
    };
    ClassCreatorVisitor(Context* context_);
    void Visit(ClassSpecifierNode& node) override;
    void Visit(ElaboratedTypeSpecifierNode& node) override;
    void Visit(ClassHeadNode& node) override;
    void Visit(BaseSpecifierNode& node) override;
    void Visit(TemplateIdNode& node) override;
    void Visit(TypeIdNode& node) override;
    void Visit(IdentifierNode& node) override;
    void Visit(UnnamedNode& node) override;
    void Visit(BooleanLiteralNode& node) override;
    void Visit(IntegerLiteralNode& node) override;
private:
    static EvaluationContext evaluationContext;
    Stage stage;
    Context* context;
    Node* specifierNode;
    ClassTypeSymbol* classTypeSymbol;
    std::vector<Symbol*> templateArguments;
};

EvaluationContext ClassCreatorVisitor::evaluationContext;

ClassCreatorVisitor::ClassCreatorVisitor(Context* context_) : context(context_), specifierNode(nullptr), stage(Stage::createClass), classTypeSymbol(nullptr)
{
}

void ClassCreatorVisitor::Visit(ClassSpecifierNode& node)
{
    specifierNode = &node;
    node.ClassHead()->Accept(*this);
}

void ClassCreatorVisitor::Visit(ElaboratedTypeSpecifierNode& node)
{
    specifierNode = &node;
    node.Id()->Accept(*this);
}

void ClassCreatorVisitor::Visit(ClassHeadNode& node)
{
    stage = Stage::createClass;
    node.ClassHeadName()->Accept(*this);
    if (node.BaseClause())
    {
        stage = Stage::addBases;
        node.BaseClause()->Accept(*this);
    }
}

void ClassCreatorVisitor::Visit(BaseSpecifierNode& node)
{
    templateArguments.clear();
    node.ClassOrDeclType()->Accept(*this);
}

void ClassCreatorVisitor::Visit(TemplateIdNode& node)
{
    VisitListContent(node);
    node.TemplateName()->Accept(*this);
}

void ClassCreatorVisitor::Visit(BooleanLiteralNode& node)
{
    Value* value = EvaluateConstantExpression(&node, evaluationContext);
    templateArguments.push_back(value);
}

void ClassCreatorVisitor::Visit(IntegerLiteralNode& node)
{
    Value* value = EvaluateConstantExpression(&node, evaluationContext);
    templateArguments.push_back(value);
}

void ClassCreatorVisitor::Visit(TypeIdNode& node)
{
    TypeSymbol* type = ProcessTypeId(&node, context);
    templateArguments.push_back(type);
}

void ClassCreatorVisitor::Visit(IdentifierNode& node)
{
    if (stage == Stage::createClass)
    {
        context->GetSymbolTable()->BeginClass(specifierNode, &node, templateArguments, context);
        Symbol* symbol = context->GetSymbolTable()->GetSymbol(specifierNode);
        if (symbol->Kind() == SymbolKind::classTypeSymbol)
        {
            classTypeSymbol = static_cast<ClassTypeSymbol*>(symbol);
        }
        else
        {
            throw Exception("class type symbol expected", node.GetSourcePos(), context);
        }
    }
    else if (stage == Stage::addBases)
    {
        Symbol* symbol = context->GetSymbolTable()->Lookup(node.Str(), node.GetSourcePos(), context);
        if (symbol && symbol->Kind() == SymbolKind::classGroupSymbol)
        {
            ClassGroupSymbol* classGroup = static_cast<ClassGroupSymbol*>(symbol);
            bool exact = false;
            ClassTypeSymbol* baseClass = classGroup->GetClass(templateArguments, MatchKind::partial, exact);
            if (baseClass)
            {
                if (exact)
                {
                    classTypeSymbol->AddBaseClass(baseClass, node.GetSourcePos(), context);
                }
                else
                {
                    context->GetSymbolTable()->BeginClass(nullptr, &node, templateArguments, context);
                    Symbol* symbol = context->GetSymbolTable()->GetSymbol(&node);
                    if (symbol)
                    {
                        if (symbol->Kind() == SymbolKind::classTypeSymbol)
                        {
                            ClassTypeSymbol* baseCls = static_cast<ClassTypeSymbol*>(symbol);
                            if (baseClass->IsClassTemplate())
                            {
                                baseCls->SetClassTemplate(baseClass);
                            }
                        }
                    }
                    context->GetSymbolTable()->EndClass();
                }
            }
            else
            {
                throw Exception("base class '" + ToUtf8(node.Str()) + "' not found", node.GetSourcePos(), context);
            }
        }
        else
        {
            throw Exception("base class '" + ToUtf8(node.Str()) + "' not found", node.GetSourcePos(), context);
        }
    }
}

void ClassCreatorVisitor::Visit(UnnamedNode& node)
{
    if (stage == Stage::createClass)
    {
        context->GetSymbolTable()->BeginClass(specifierNode, &node, templateArguments, context);
        Symbol* symbol = context->GetSymbolTable()->GetSymbol(specifierNode);
        if (symbol->Kind() == SymbolKind::classTypeSymbol)
        {
            classTypeSymbol = static_cast<ClassTypeSymbol*>(symbol);
        }
        else
        {
            throw Exception("class type symbol expected", node.GetSourcePos(), context);
        }
    }
}

void BeginClass(Node* node, Context* context)
{
    ClassCreatorVisitor visitor(context);
    node->Accept(visitor);
    context->PushSetFlag(ContextFlags::parseMemberFunction);
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
    if (!context->GetFlag(ContextFlags::parsingTemplateDeclaration))
    {
        BeginFunctionDefinition(node.DeclSpecifiers(), node.Declarator(), context);
        FunctionBodyNode* functionBody = static_cast<FunctionBodyNode*>(node.FunctionBody());
        CompoundStatementNode* compoundStatementNode = static_cast<CompoundStatementNode*>(functionBody->Child());
        sngcpp::par::RecordedParse(compoundStatementNode, context);
        EndFunctionDefinition(context);
    }
}

void ParseInlineMemberFunctions(Node* classSpecifierNode, Context* context)
{
    Symbol* symbol = context->GetSymbolTable()->GetSymbol(classSpecifierNode);
    if (symbol)
    {
        if (symbol->Kind() == SymbolKind::classTypeSymbol)
        {
            ClassTypeSymbol* classTypeSymbol = static_cast<ClassTypeSymbol*>(symbol);
            context->GetSymbolTable()->BeginScope(*classTypeSymbol->GetScope());
            InlineMemberFunctionParserVisitor visitor(context);
            classSpecifierNode->Accept(visitor);
            context->GetSymbolTable()->EndScope();
        }
        else
        {
            throw Exception("class symbol expected", classSpecifierNode->GetSourcePos(), context);
        }
    }
    else
    {
        throw Exception("class symbol not found", classSpecifierNode->GetSourcePos(), context);
    }
}

} // sngcpp::symbols

