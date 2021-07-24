// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Class.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/AliasGroupSymbol.hpp>
#include <sngcpp20/symbols/AliasTypeSymbol.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/DeclarationProcessor.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/Evaluator.hpp>
#include <sngcpp20/symbols/ScopeResolver.hpp>
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
    void Visit(QualifiedIdNode& node) override;
    void Visit(TypeIdNode& node) override;
    void Visit(EllipsisNode& node) override;
    void Visit(IdentifierNode& node) override;
    void Visit(UnnamedNode& node) override;
    void Visit(BooleanLiteralNode& node) override;
    void Visit(IntegerLiteralNode& node) override;
private:
    Stage stage;
    Context* context;
    Scope* scope;
    Node* specifierNode;
    ClassTypeSymbol* classTypeSymbol;
    std::vector<Symbol*> templateArguments;
};

ClassCreatorVisitor::ClassCreatorVisitor(Context* context_) : 
    context(context_), scope(context->GetSymbolTable()->CurrentScope()), specifierNode(nullptr), stage(Stage::createClass), classTypeSymbol(nullptr)
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

void ClassCreatorVisitor::Visit(QualifiedIdNode& node)
{
    scope = ResolveScope(node.Left(), context);
    node.Right()->Accept(*this);
}

void ClassCreatorVisitor::Visit(BooleanLiteralNode& node)
{
    Value* value = EvaluateConstantExpression(&node, GetEvaluationContext());
    templateArguments.push_back(value);
}

void ClassCreatorVisitor::Visit(IntegerLiteralNode& node)
{
    Value* value = EvaluateConstantExpression(&node, GetEvaluationContext());
    templateArguments.push_back(value);
}

void ClassCreatorVisitor::Visit(TypeIdNode& node)
{
    Symbol* typeOrValue = ProcessTypeIdOrValue(&node, context);
    templateArguments.push_back(typeOrValue);
}

void ClassCreatorVisitor::Visit(EllipsisNode& node)
{
    templateArguments.push_back(context->GetSymbolTable()->MakeVarArgTypeSymbol());
}

void ClassCreatorVisitor::Visit(IdentifierNode& node)
{
    try
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
            Symbol* symbol = scope->Lookup(node.Str(), SymbolGroupKind::typeSymbolGroup, ScopeLookup::allScopes, node.GetSourcePos(), context);
            if (symbol && symbol->Kind() == SymbolKind::aliasGroupSymbol)
            {
                AliasGroupSymbol* aliasGroup = static_cast<AliasGroupSymbol*>(symbol);
                bool exact = false;
                AliasTypeSymbol* aliasType = aliasGroup->GetAliasTypeSymbol(templateArguments, MatchKind::exact, exact);
                if (aliasType)
                {
                    classTypeSymbol->AddBaseClass(aliasType, node.GetSourcePos(), context);
                }
                else
                {
                    AliasTypeSymbol* aliasTemplate = aliasGroup->AliasTypeTemplate();
                    if (aliasTemplate)
                    {
                        TypeSymbol* baseClass = context->GetSymbolTable()->Instantiate(aliasTemplate, templateArguments);
                        classTypeSymbol->AddBaseClass(baseClass, node.GetSourcePos(), context);
                    }
                }
            }
            else if (symbol && symbol->Kind() == SymbolKind::classGroupSymbol)
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
                        ClassTypeSymbol* baseClassInstance = context->GetSymbolTable()->Instantiate(baseClass, templateArguments);
                        classTypeSymbol->AddBaseClass(baseClassInstance, node.GetSourcePos(), context);
                    }
                }
                else
                {
                    ClassTypeSymbol* classTemplate = classGroup->GetClassTemplate();
                    if (classTemplate)
                    {
                        ClassTypeSymbol* baseClass = context->GetSymbolTable()->Instantiate(classTemplate, templateArguments);
                        classTypeSymbol->AddBaseClass(baseClass, node.GetSourcePos(), context);
                    }
                }
            }
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        if (stage == Stage::addBases)
        {
            if (classTypeSymbol)
            {
                classTypeSymbol->AddBaseClass(context->GetSymbolTable()->MakeErrorSymbol(errorIndex), SourcePos(), context);
            }
        }
    }
}

void ClassCreatorVisitor::Visit(UnnamedNode& node)
{
    try
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
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
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
        if (node.FunctionBody()->Kind() == NodeKind::functionBodyNode)
        {
            bool constructor = false;
            Symbol* symbol = context->GetSymbolTable()->GetSymbolNothrow(&node);
            if (symbol)
            {
                if (symbol->IsConstructorSymbol())
                {
                    constructor = true;
                }
            } 
            BeginFunctionDefinition(node.DeclSpecifiers(), node.Declarator(), constructor, context);
            try
            {
                FunctionBodyNode* functionBody = static_cast<FunctionBodyNode*>(node.FunctionBody());
                CompoundStatementNode* compoundStatementNode = static_cast<CompoundStatementNode*>(functionBody->Child());
                sngcpp::par::RecordedParse(compoundStatementNode, context);
                EndFunctionDefinition(context);
            }
            catch (const std::exception& ex)
            {
                context->GetSymbolTable()->AddError(ex);
                EndFunctionDefinition(context);
            }
        }
    }
}

void ParseInlineMemberFunctions(Node* classSpecifierNode, Context* context)
{
    try
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
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

bool IsConstructorName(Node* node, Context* context)
{
    if (!context->GetFlag(ContextFlags::matchConstructorName)) return false;
    if (context->GetFlag(ContextFlags::parsingParameters)) return false;
    if (context->GetSymbolTable()->CurrentScope()->Kind() != ScopeKind::classScope) return false;
    Symbol* symbol = context->GetSymbolTable()->GetSymbolNothrow(node);
    if (!symbol) return false;
    Symbol* currentClassTypeSymbol = context->GetSymbolTable()->CurrentScope()->GetSymbol();
    if (symbol->Name() != currentClassTypeSymbol->Name()) return false;
    return true;
}

bool IsQualifiedConstructorName(Node* node, Context* context)
{
    if (node->Kind() != NodeKind::qualifiedIdNode) return false;
    QualifiedIdNode* qn = static_cast<QualifiedIdNode*>(node);
    Scope* scope = ResolveScope(qn->Left(), context);
    if (!scope) return false;
    if (scope->Kind() != ScopeKind::classScope) return false;
    Symbol* scopeSymbol = scope->GetSymbol();
    if (!scopeSymbol) return false;
    if (scopeSymbol->Kind() != SymbolKind::classTypeSymbol) return false;
    ClassTypeSymbol* classTypeSymbol = static_cast<ClassTypeSymbol*>(scopeSymbol);
    Symbol* symbol = context->GetSymbolTable()->GetSymbolNothrow(qn->Right());;
    if (!symbol) return false;
    if (symbol->Name() != classTypeSymbol->Name()) return false;
    return true;
}

} // sngcpp::symbols
