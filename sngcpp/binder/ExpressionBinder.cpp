// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/binder/ExpressionBinder.hpp>
#include <sngcpp/binder/StatementBinder.hpp>
#include <sngcpp/binder/TypeResolver.hpp>
#include <sngcpp/symbols/TypedefSymbol.hpp>
#include <sngcpp/symbols/PseudoTypeSymbol.hpp>
#include <sngcpp/ast/TypeExpr.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace binder {

class ExpressionBinder : public sngcpp::ast::Visitor
{
public:
    ExpressionBinder(SymbolTable& symbolTable_, ContainerScope* containerScope_, BoundSourceFile* boundSourceFile_, FunctionSymbol* currentFunction_, StatementBinder* statementBinder_);
    std::vector<Symbol*> GetSymbols() { return std::move(symbols); }
    void Visit(InitDeclaratorNode& initDeclaratorNode) override;
    void Visit(CtorInitializerNode& ctorInitializerNode) override;
    void Visit(MemberInitializerNode& memberInitializerNode) override;
    void Visit(MemberInitializerSequenceNode& memberInitializerSequenceNode) override;
    void Visit(AssignmentInitializerNode& assignmentInitializerNode) override;
    void Visit(ExpressionListInitializerNode& expressionListInitializerNode) override;
    void Visit(ExpressionInitializerNode& expressionInitializerNode) override;
    void Visit(BracedInitializerListNode& bracedInitializerListNode) override;
    void Visit(ExpressionSequenceNode& expressionSequenceNode) override;
    void Visit(SimpleDeclarationNode& simpleDeclarationNode) override;
    void Visit(IdDeclaratorNode& idDeclaratorNode) override;
    void Visit(CommaExpressionNode& commaExpressionNode) override;
    void Visit(AssignmentExpressionNode& assignmentExpressionNode) override;
    void Visit(ConditionalExpressionNode& conditionalExpressionNode) override;
    void Visit(ThrowExpressionNode& throwExpressionNode) override;
    void Visit(LogicalOrExpressionNode& logicalOrExpressionNode) override;
    void Visit(LogicalAndExpressionNode& logicalAndExpressionNode) override;
    void Visit(InclusiveOrExpressionNode& inclusiveOrExpressionNode) override;
    void Visit(ExclusiveOrExpressionNode& exclusiveOrExpressionNode) override;
    void Visit(AndExpressionNode& andExpressionNode) override;
    void Visit(EqualityExpressionNode& equalityExpressionNode) override;
    void Visit(RelationalExpressionNode& relationalExpressionNode) override;
    void Visit(ShiftExpressionNode& shiftExpressionNode) override;
    void Visit(AdditiveExpressionNode& additiveExpressionNode) override;
    void Visit(MultiplicativeExpressionNode& multiplicativeExpressionNode) override;
    void Visit(PMExpressionNode& pmExpressionNode) override;
    void Visit(CastExpressionNode& castExpressionNode) override;
    void Visit(UnaryExpressionNode& unaryExpressionNode) override;
    void Visit(NewExpressionNode& newExpressionNode) override;
    void Visit(SubscriptExpressionNode& subscriptExpressionNode) override;
    void Visit(InvokeExpressionNode& invokeExpressionNode) override;
    void Visit(DotNode& dotNode) override;
    void Visit(ArrowNode& arrowNode) override;
    void Visit(PostfixIncNode& postfixIncNode) override;
    void Visit(PostfixDecNode& postfixDecNode) override;
    void Visit(CppCastExpressionNode& cppCastExpressionNode) override;
    void Visit(TypeIdExpressionNode& typeIdExpressionNode) override;
    void Visit(ThisNode& thisNode) override;
    void Visit(LambdaExpressionNode& lambdaExpressionNode) override;
    void Visit(CaptureSequenceNode& captureSequenceNode) override;
    void Visit(IdentifierCaptureNode& identifierCaptureNode) override;
    void Visit(NestedIdNode& nestedIdNode) override;
    void Visit(IdentifierNode& identifierNode) override;
    void Visit(TypeExprNode& typeExprNode) override;
private:
    StatementBinder* statementBinder;
    SymbolTable& symbolTable;
    ContainerScope* containerScope;
    BoundSourceFile* boundSourceFile;
    FunctionSymbol* currentFunction;
    std::vector<Symbol*> symbols;
};

ExpressionBinder::ExpressionBinder(SymbolTable& symbolTable_, ContainerScope* containerScope_, BoundSourceFile* boundSourceFile_, FunctionSymbol* currentFunction_, StatementBinder* statementBinder_) :
    statementBinder(statementBinder_), symbolTable(symbolTable_), containerScope(containerScope_), boundSourceFile(boundSourceFile_), currentFunction(currentFunction_), symbols()
{
}

void ExpressionBinder::Visit(InitDeclaratorNode& initDeclaratorNode)
{
    BindExpression(initDeclaratorNode.Declarator(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(initDeclaratorNode.Initializer(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(CtorInitializerNode& ctorInitializerNode)
{
    BindExpression(ctorInitializerNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(MemberInitializerNode& memberInitializerNode)
{
    BindExpression(memberInitializerNode.Id(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(memberInitializerNode.Initializer(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(MemberInitializerSequenceNode& memberInitializerSequenceNode)
{
    BindExpression(memberInitializerSequenceNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(memberInitializerSequenceNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(AssignmentInitializerNode& assignmentInitializerNode)
{
    symbols = std::move(BindExpression(assignmentInitializerNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
}

void ExpressionBinder::Visit(ExpressionListInitializerNode& expressionListInitializerNode)
{
    if (expressionListInitializerNode.Child())
    {
        symbols = std::move(BindExpression(expressionListInitializerNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
    }
}

void ExpressionBinder::Visit(ExpressionInitializerNode& expressionInitializerNode)
{
    symbols = std::move(BindExpression(expressionInitializerNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
}

void ExpressionBinder::Visit(BracedInitializerListNode& bracedInitializerListNode)
{
    if (bracedInitializerListNode.Child())
    {
        symbols = std::move(BindExpression(bracedInitializerListNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
    }
}

void ExpressionBinder::Visit(ExpressionSequenceNode& expressionSequenceNode)
{
    std::vector<Symbol*> leftSymbols = BindExpression(expressionSequenceNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    symbols.insert(symbols.end(), leftSymbols.begin(), leftSymbols.end());
    std::vector<Symbol*> rightSymbols = BindExpression(expressionSequenceNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    symbols.insert(symbols.end(), rightSymbols.begin(), rightSymbols.end());
}

void ExpressionBinder::Visit(SimpleDeclarationNode& simpleDeclarationNode)
{
    BindExpression(simpleDeclarationNode.TypeExpr(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    if (simpleDeclarationNode.Declarator())
    {
        symbols = std::move(BindExpression(simpleDeclarationNode.Declarator(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
    }
}

void ExpressionBinder::Visit(IdDeclaratorNode& idDeclaratorNode)
{
    symbols = std::move(BindExpression(idDeclaratorNode.IdNode(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
}

void ExpressionBinder::Visit(CommaExpressionNode& commaExpressionNode)
{
    BindExpression(commaExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(commaExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(AssignmentExpressionNode& assignmentExpressionNode)
{
    BindExpression(assignmentExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(assignmentExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(ConditionalExpressionNode& conditionalExpressionNode)
{
    BindExpression(conditionalExpressionNode.Condition(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(conditionalExpressionNode.ThenExpr(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(conditionalExpressionNode.ElseExpr(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(ThrowExpressionNode& throwExpressionNode)
{
    if (throwExpressionNode.Child())
    {
        BindExpression(throwExpressionNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    }
}

void ExpressionBinder::Visit(LogicalOrExpressionNode& logicalOrExpressionNode)
{
    BindExpression(logicalOrExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(logicalOrExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(LogicalAndExpressionNode& logicalAndExpressionNode)
{
    BindExpression(logicalAndExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(logicalAndExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(InclusiveOrExpressionNode& inclusiveOrExpressionNode)
{
    BindExpression(inclusiveOrExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(inclusiveOrExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(ExclusiveOrExpressionNode& exclusiveOrExpressionNode)
{
    BindExpression(exclusiveOrExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(exclusiveOrExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(AndExpressionNode& andExpressionNode)
{
    BindExpression(andExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(andExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(EqualityExpressionNode& equalityExpressionNode)
{
    BindExpression(equalityExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(equalityExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(RelationalExpressionNode& relationalExpressionNode)
{
    BindExpression(relationalExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(relationalExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(ShiftExpressionNode& shiftExpressionNode)
{
    BindExpression(shiftExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(shiftExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(AdditiveExpressionNode& additiveExpressionNode)
{
    BindExpression(additiveExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(additiveExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(MultiplicativeExpressionNode& multiplicativeExpressionNode)
{
    BindExpression(multiplicativeExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(multiplicativeExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(PMExpressionNode& pmExpressionNode)
{
    BindExpression(pmExpressionNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(pmExpressionNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(CastExpressionNode& castExpressionNode)
{
    BindExpression(castExpressionNode.TypeExpr(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(castExpressionNode.Expr(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(UnaryExpressionNode& unaryExpressionNode)
{
    std::vector<Symbol*> subjectSymbols = BindExpression(unaryExpressionNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    Symbol* subject = nullptr;
    if (!subjectSymbols.empty())
    {
        subject = subjectSymbols.front();
    }
    if (subject)
    {
        switch (unaryExpressionNode.Op())
        {
            case Operator::deref:
            {
                symbols.push_back(subject);
                break;
            }
        }
    }
}

void ExpressionBinder::Visit(NewExpressionNode& newExpressionNode)
{
    if (newExpressionNode.Placement())
    {
        BindExpression(newExpressionNode.Placement(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    }
    BindExpression(newExpressionNode.TypeExpr(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    if (newExpressionNode.Initializer())
    {
        BindExpression(newExpressionNode.Initializer(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    }
}

void ExpressionBinder::Visit(SubscriptExpressionNode& subscriptExpressionNode)
{
    BindExpression(subscriptExpressionNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(subscriptExpressionNode.Index(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(InvokeExpressionNode& invokeExpressionNode)
{
    FunctionGroupSymbol* functionGroup = nullptr;
    std::vector<Symbol*> subjectSymbols = BindExpression(invokeExpressionNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    if (!subjectSymbols.empty())
    {
        Symbol* subject = subjectSymbols.front();
        if (subject)
        {
            if (subject->IsFunctionGroupSymbol())
            {
                functionGroup = static_cast<FunctionGroupSymbol*>(subject);
            }
            else if (subject->IsPseudoTypeSymbol())
            {
                PseudoTypeSymbol* pseudoTypeSymbol = static_cast<PseudoTypeSymbol*>(subject);
                functionGroup = pseudoTypeSymbol->GetFunctionGroup();
            }
        }
    }
    std::vector<Symbol*> argumentSymbols;
    if (invokeExpressionNode.Arguments())
    {
        argumentSymbols = std::move(BindExpression(invokeExpressionNode.Arguments(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
    }
    if (functionGroup)
    {
        FunctionSymbol* functionSymbol = functionGroup->ResolveOverload(argumentSymbols);
        if (functionSymbol)
        {
            symbolTable.MapNode(&invokeExpressionNode, functionSymbol);
            symbols.push_back(functionSymbol);
            currentFunction->AddToCalls(functionSymbol);
            functionSymbol->AddToCalledBy(currentFunction);
        }
    }
}

void ExpressionBinder::Visit(DotNode& dotNode)
{
    std::vector<Symbol*> leftSymbols = BindExpression(dotNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    Symbol* s = nullptr;
    if (!leftSymbols.empty())
    {
        s = leftSymbols.front();
    }
    if (s)
    {
        TypeSymbol* type = s->GetType();
        if (type)
        {
            containerScope = type->BaseType()->GetContainerScope();
        }
    }
    if (containerScope)
    {
        symbols = std::move(BindExpression(dotNode.Id(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
    }
}

void ExpressionBinder::Visit(ArrowNode& arrowNode)
{
    std::vector<Symbol*> leftSymbols = BindExpression(arrowNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    Symbol* s = nullptr;
    if (!leftSymbols.empty())
    {
        s = leftSymbols.front();
    }
    if (s)
    {
        TypeSymbol* type = s->GetType();
        if (type)
        {
            containerScope = type->BaseType()->GetContainerScope();
        }
    }
    if (containerScope)
    {
        symbols = std::move(BindExpression(arrowNode.Id(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
    }
}

void ExpressionBinder::Visit(PostfixIncNode& postfixIncNode)
{
    BindExpression(postfixIncNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(PostfixDecNode& postfixDecNode)
{
    BindExpression(postfixDecNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(CppCastExpressionNode& cppCastExpressionNode)
{
    BindExpression(cppCastExpressionNode.TypeExpr(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(cppCastExpressionNode.Expr(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(TypeIdExpressionNode& typeIdExpressionNode)
{
    BindExpression(typeIdExpressionNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(ThisNode& thisNode)
{
    ClassTypeSymbol* cls = currentFunction->Class();
    if (cls)
    {
        symbols.push_back(cls);
    }
}

void ExpressionBinder::Visit(LambdaExpressionNode& lambdaExpressionNode)
{
    if (lambdaExpressionNode.Captures())
    {
        BindExpression(lambdaExpressionNode.Captures(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    }
    lambdaExpressionNode.Body()->Accept(*statementBinder);
}

void ExpressionBinder::Visit(CaptureSequenceNode& captureSequenceNode)
{
    BindExpression(captureSequenceNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    BindExpression(captureSequenceNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(IdentifierCaptureNode& identifierCaptureNode)
{
    BindExpression(identifierCaptureNode.Child(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(NestedIdNode& nestedIdNode)
{
    std::vector<Symbol*> symbols;
    if (nestedIdNode.Left())
    {
        symbols = std::move(BindExpression(nestedIdNode.Left(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
    }
    else
    {
        symbols.push_back(symbolTable.GlobalNs());
    }
    Symbol* s = nullptr;
    if (!symbols.empty())
    {
        s = symbols.front();
    }
    if (s)
    {
        if (s->IsNamespaceSymbol())
        {
            containerScope = s->GetContainerScope();
        }
        else if (s->IsTypedefSymbol())
        {
            TypedefSymbol* typedefSymbol = static_cast<TypedefSymbol*>(s);
            TypeSymbol* type = typedefSymbol->GetType();
            containerScope = type->GetContainerScope();
        }
        else if (s->IsTypeSymbol())
        {
            containerScope = s->GetContainerScope();
        }
        else if (s->IsClassGroupSymbol())
        {
            ClassGroupSymbol* group = static_cast<ClassGroupSymbol*>(s);
            ClassTypeSymbol* cls = group->GetClass(0);
            if (cls)
            {
                containerScope = cls->GetContainerScope();
            }
        }
    }
    if (containerScope)
    {
        symbols = std::move(BindExpression(nestedIdNode.Right(), symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder));
    }
    else
    {
        symbols.clear();
    }
    this->symbols = std::move(symbols);
}

void ExpressionBinder::Visit(IdentifierNode& identifierNode)
{
    Symbol* symbol = containerScope->Lookup(identifierNode.Identifier(), ScopeLookup::this_and_bases_and_parent);
    if (!symbol)
    {
        for (const std::unique_ptr<FileScope>& fileScope : boundSourceFile->FileScopes())
        {
            symbol = fileScope->Lookup(identifierNode.Identifier());
            if (symbol)
            {
                break;
            }
        }
    }
    if (symbol)
    {
        symbolTable.MapNode(&identifierNode, symbol);
        symbols.push_back(symbol);
    }
}

void ExpressionBinder::Visit(TypeExprNode& typeExprNode)
{
    Symbol* symbol = symbolTable.GetSymbolNothrow(&typeExprNode);
    if (symbol)
    {
        symbols.push_back(symbol);
    }
}

std::vector<Symbol*> BindExpression(Node* node, SymbolTable& symbolTable, ContainerScope* containerScope, BoundSourceFile* boundSourceFile, FunctionSymbol* currentFunction,
    StatementBinder* statementBinder)
{
    ExpressionBinder expressionBinder(symbolTable, containerScope, boundSourceFile, currentFunction, statementBinder);
    node->Accept(expressionBinder);
    std::vector<Symbol*> symbols = expressionBinder.GetSymbols();
    if (symbols.empty())
    {
        TypeSymbol* type = ResolveType(symbolTable, containerScope, *boundSourceFile, TypeResolverFlags::noExternalTypes | TypeResolverFlags::nothrow, node);
        if (type)
        {
            symbols.push_back(type);
        }
        else
        {
            symbols.push_back(nullptr);
        }
    }
    return symbols;
}

} } // namespace sngcppp::binder
