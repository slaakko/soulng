// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/binder/StatementBinder.hpp>
#include <sngcpp/binder/ExpressionBinder.hpp>
#include <sngcpp/ast/SourceFile.hpp>

namespace sngcpp { namespace binder {

StatementBinder::StatementBinder(SymbolTable& symbolTable_, const std::unordered_map<SourceFileNode*, BoundSourceFile*>& sourceFileMap_) :
    symbolTable(symbolTable_), sourceFileMap(sourceFileMap_), currentSourceFile(nullptr), containerScope(nullptr), currentFunction(nullptr)
{
}

void StatementBinder::Visit(SourceFileNode& sourceFileNode)
{
    auto it = sourceFileMap.find(&sourceFileNode);
    if (it != sourceFileMap.cend())
    {
        currentSourceFile = it->second;
    }
    else
    {
        throw std::runtime_error("source file not found");
    }
    containerScope = symbolTable.GlobalNs()->GetContainerScope();
    sourceFileNode.GlobalNs()->Accept(*this);
}

void StatementBinder::Visit(SourceFileSequenceNode& sourceFileSequenceNode)
{
    sourceFileSequenceNode.Left()->Accept(*this);
    sourceFileSequenceNode.Right()->Accept(*this);
}

void StatementBinder::Visit(NamespaceNode& namespaceNode)
{
    if (namespaceNode.Child())
    {
        namespaceNode.Child()->Accept(*this);
    }
}

void StatementBinder::Visit(DeclarationSequenceNode& declarationSequenceNode)
{
    declarationSequenceNode.Left()->Accept(*this);
    declarationSequenceNode.Right()->Accept(*this);
}

void StatementBinder::Visit(ClassNode& classNode)
{
    Symbol* symbol = symbolTable.GetSymbol(&classNode);
    if (symbol->IsClassTypeSymbol())
    {
        ClassTypeSymbol* classTypeSymbol = static_cast<ClassTypeSymbol*>(symbol);
        ContainerScope* prevContainerScope = containerScope;
        containerScope = classTypeSymbol->GetContainerScope();
        if (classNode.Declarations())
        {
            classNode.Declarations()->Accept(*this);
        }
        containerScope = prevContainerScope;
    }
    else
    {
        throw std::runtime_error("class type symbol expected");
    }
}

void StatementBinder::Visit(FunctionNode& functionNode)
{
    Symbol* symbol = symbolTable.GetSymbolNothrow(&functionNode);
    if (symbol)
    {
        if (symbol->IsFunctionSymbol())
        {
            FunctionSymbol* prevFunction = currentFunction;
            currentFunction = static_cast<FunctionSymbol*>(symbol);
            ContainerScope* prevContainerScope = containerScope;
            containerScope = currentFunction->GetContainerScope();
            if (functionNode.Body())
            {
                functionNode.Body()->Accept(*this);
            }
            currentFunction = prevFunction;
            containerScope = prevContainerScope;
        }
        else
        {
            throw std::runtime_error("function symbol expected");
        }
    }
}

void StatementBinder::Visit(SpecialMemberFunctionNode& specialMemberFunctionNode)
{
    Symbol* symbol = symbolTable.GetSymbolNothrow(&specialMemberFunctionNode);
    if (symbol)
    {
        if (symbol->IsFunctionSymbol())
        {
            FunctionSymbol* prevFunction = currentFunction;
            currentFunction = static_cast<FunctionSymbol*>(symbol);
            ContainerScope* prevContainerScope = containerScope;
            containerScope = currentFunction->GetContainerScope();
            if (specialMemberFunctionNode.CtorInitializer())
            {
                BindExpression(specialMemberFunctionNode.CtorInitializer(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
            }
            if (specialMemberFunctionNode.FunctionBody())
            {
                specialMemberFunctionNode.FunctionBody()->Accept(*this);
            }
            currentFunction = prevFunction;
            containerScope = prevContainerScope;
        }
        else
        {
            throw std::runtime_error("function symbol expected");
        }
    }
}

void StatementBinder::Visit(CompoundStatementNode& compoundStatementNode)
{
    Symbol* symbol = symbolTable.GetSymbol(&compoundStatementNode);
    if (symbol->IsDeclarationBlockSymbol())
    {
        DeclarationBlockSymbol* declarationBlock = static_cast<DeclarationBlockSymbol*>(symbol);
        ContainerScope* prevContainerScope = containerScope;
        containerScope = declarationBlock->GetContainerScope();
        if (compoundStatementNode.Child())
        {
            compoundStatementNode.Child()->Accept(*this);
        }
        containerScope = prevContainerScope;
    }
    else
    {
        throw std::runtime_error("declaration block expected");
    }
}

void StatementBinder::Visit(StatementSequenceNode& statementSequenceNode)
{
    statementSequenceNode.Left()->Accept(*this);
    statementSequenceNode.Right()->Accept(*this);
}

void StatementBinder::Visit(LabeledStatementNode& labeledStatementNode)
{
    labeledStatementNode.Child()->Accept(*this);
}

void StatementBinder::Visit(IfStatementNode& ifStatementNode)
{
    BindExpression(ifStatementNode.Condition(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
    ifStatementNode.ThenS()->Accept(*this);
    if (ifStatementNode.ElseS())
    {
        ifStatementNode.ElseS()->Accept(*this);
    }
}

void StatementBinder::Visit(SwitchStatementNode& switchStatementNode)
{
    BindExpression(switchStatementNode.Condition(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
    switchStatementNode.Statement()->Accept(*this);
}

void StatementBinder::Visit(CaseStatementNode& caseStatementNode)
{
    BindExpression(caseStatementNode.CaseExpr(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
    caseStatementNode.Child()->Accept(*this);
}

void StatementBinder::Visit(DefaultStatementNode& defaultStatementNode)
{
    defaultStatementNode.Child()->Accept(*this);
}

void StatementBinder::Visit(ExpressionStatementNode& expressionStatementNode)
{
    if (expressionStatementNode.Child())
    {
        BindExpression(expressionStatementNode.Child(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
    }
}

void StatementBinder::Visit(WhileStatementNode& whileStatementNode)
{
    BindExpression(whileStatementNode.Condition(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
    whileStatementNode.Statement()->Accept(*this);
}

void StatementBinder::Visit(DoStatementNode& doStatementNode)
{
    doStatementNode.Statement()->Accept(*this);
    BindExpression(doStatementNode.Condition(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
}

void StatementBinder::Visit(RangeForStatementNode& rangeForStatementNode)
{
    Symbol* symbol = symbolTable.GetSymbol(&rangeForStatementNode);
    if (symbol->IsDeclarationBlockSymbol())
    {
        DeclarationBlockSymbol* declarationBlock = static_cast<DeclarationBlockSymbol*>(symbol);
        ContainerScope* prevContainerScope = containerScope;
        containerScope = declarationBlock->GetContainerScope();
        BindExpression(rangeForStatementNode.ForRangeDeclaration(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
        BindExpression(rangeForStatementNode.ForRangeInitializer(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
        rangeForStatementNode.Statement()->Accept(*this);
        containerScope = prevContainerScope;
    }
    else
    {
        throw std::runtime_error("declaration block expected");
    }
}

void StatementBinder::Visit(ForStatementNode& forStatementNode)
{
    Symbol* symbol = symbolTable.GetSymbol(&forStatementNode);
    if (symbol->IsDeclarationBlockSymbol())
    {
        DeclarationBlockSymbol* declarationBlock = static_cast<DeclarationBlockSymbol*>(symbol);
        ContainerScope* prevContainerScope = containerScope;
        containerScope = declarationBlock->GetContainerScope();
        if (forStatementNode.InitS())
        {
            forStatementNode.InitS()->Accept(*this);
        }
        if (forStatementNode.Condition())
        {
            BindExpression(forStatementNode.Condition(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
        }
        if (forStatementNode.LoopExpr())
        {
            BindExpression(forStatementNode.LoopExpr(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
        }
        forStatementNode.ActionS()->Accept(*this);
        containerScope = prevContainerScope;
    }
    else
    {
        throw std::runtime_error("declaration block expected");
    }
}

void StatementBinder::Visit(ReturnStatementNode& returnStatementNode)
{
    if (returnStatementNode.ReturnExpr())
    {
        BindExpression(returnStatementNode.ReturnExpr(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
    }
}

void StatementBinder::Visit(DeclarationStatementNode& declarationStatementNode)
{
    BindExpression(declarationStatementNode.Child(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
}

void StatementBinder::Visit(TryStatementNode& tryStatementNode)
{
    tryStatementNode.TryBlock()->Accept(*this);
    tryStatementNode.Handlers()->Accept(*this);
}

void StatementBinder::Visit(HandlerNode& handlerNode)
{
    BindExpression(handlerNode.ExceptionDeclaration(), symbolTable, containerScope, currentSourceFile, currentFunction, this);
    handlerNode.CatchBlock()->Accept(*this);
}

void StatementBinder::Visit(HandlerSequenceNode& handlerSequenceNode)
{
    handlerSequenceNode.Left()->Accept(*this);
    handlerSequenceNode.Right()->Accept(*this);
}

} } // namespace sngcpp::binder
