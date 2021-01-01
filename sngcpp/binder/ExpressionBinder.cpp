// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/binder/ExpressionBinder.hpp>
#include <sngcpp/binder/StatementBinder.hpp>
#include <sngcpp/binder/TypeResolver.hpp>
#include <sngcpp/symbols/TypedefSymbol.hpp>
#include <sngcpp/symbols/ClassTemplateSpecializationSymbol.hpp>
#include <sngcpp/ast/TypeExpr.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <soulng/util/Unicode.hpp>
#include <algorithm>

namespace sngcpp { namespace binder {

using namespace soulng::unicode;

class ExpressionBinder : public sngcpp::ast::Visitor
{
public:
    ExpressionBinder(SymbolTable& symbolTable_, ContainerScope* containerScope_, const std::vector<ContainerScope*>& prevContainerScopes_,
        BoundSourceFile* boundSourceFile_, FunctionSymbol* currentFunction_, StatementBinder* statementBinder_, bool& subjectIsConst_);
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
    void Visit(ParenthesizedExprNode& parenthesizedExprNode) override;
    void Visit(LambdaExpressionNode& lambdaExpressionNode) override;
    void Visit(CaptureSequenceNode& captureSequenceNode) override;
    void Visit(IdentifierCaptureNode& identifierCaptureNode) override;
    void Visit(NestedIdNode& nestedIdNode) override;
    void Visit(IdentifierNode& identifierNode) override;
    void Visit(DtorIdNode& dtorIdNode) override;
    void Visit(TemplateIdNode& templateIdNode) override;
    void Visit(ConstNode& constNode) override;
    void Visit(VolatileNode& volatileNode) override;
    void Visit(PointerNode& pointerNode) override;
    void Visit(RValueRefNode& rValueRefNode) override;
    void Visit(LValueRefNode& lValueRefNode) override;
    void Visit(DeleteExpressionNode& deleteExpressionNode) override;
    void Visit(IntegerLiteralNode& integerLiteralNode) override;
    void Visit(StringLiteralNode& stringLiteralNode) override;
private:
    StatementBinder* statementBinder;
    SymbolTable& symbolTable;
    ContainerScope* containerScope;
    std::vector<ContainerScope*> prevContainerScopes;
    BoundSourceFile* boundSourceFile;
    FunctionSymbol* currentFunction;
    std::vector<Symbol*> symbols;
    bool& subjectIsConst;
};

ExpressionBinder::ExpressionBinder(SymbolTable& symbolTable_, ContainerScope* containerScope_, const std::vector<ContainerScope*>& prevContainerScopes_, BoundSourceFile* boundSourceFile_,
    FunctionSymbol* currentFunction_, StatementBinder* statementBinder_, bool& subjectIsConst_) :
    statementBinder(statementBinder_), symbolTable(symbolTable_), containerScope(containerScope_), prevContainerScopes(prevContainerScopes_), boundSourceFile(boundSourceFile_),
    currentFunction(currentFunction_), symbols(), subjectIsConst(subjectIsConst_)
{
}

void ExpressionBinder::Visit(InitDeclaratorNode& initDeclaratorNode)
{
    BindExpression(initDeclaratorNode.Declarator(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(initDeclaratorNode.Initializer(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(CtorInitializerNode& ctorInitializerNode)
{
    BindExpression(ctorInitializerNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(MemberInitializerNode& memberInitializerNode)
{
    BindExpression(memberInitializerNode.Id(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(memberInitializerNode.Initializer(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(MemberInitializerSequenceNode& memberInitializerSequenceNode)
{
    BindExpression(memberInitializerSequenceNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(memberInitializerSequenceNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(AssignmentInitializerNode& assignmentInitializerNode)
{
    symbols = std::move(BindExpression(assignmentInitializerNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
}

void ExpressionBinder::Visit(ExpressionListInitializerNode& expressionListInitializerNode)
{
    if (expressionListInitializerNode.Child())
    {
        symbols = std::move(BindExpression(expressionListInitializerNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
    }
}

void ExpressionBinder::Visit(ExpressionInitializerNode& expressionInitializerNode)
{
    symbols = std::move(BindExpression(expressionInitializerNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
}

void ExpressionBinder::Visit(BracedInitializerListNode& bracedInitializerListNode)
{
    if (bracedInitializerListNode.Child())
    {
        symbols = std::move(BindExpression(bracedInitializerListNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
    }
}

void ExpressionBinder::Visit(ExpressionSequenceNode& expressionSequenceNode)
{
    std::vector<Symbol*> leftSymbols = BindExpression(expressionSequenceNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    symbols.insert(symbols.end(), leftSymbols.begin(), leftSymbols.end());
    std::vector<Symbol*> rightSymbols = BindExpression(expressionSequenceNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    symbols.insert(symbols.end(), rightSymbols.begin(), rightSymbols.end());
}

void ExpressionBinder::Visit(SimpleDeclarationNode& simpleDeclarationNode)
{
    BindExpression(simpleDeclarationNode.TypeExpr(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    if (simpleDeclarationNode.Declarator())
    {
        symbols = std::move(BindExpression(simpleDeclarationNode.Declarator(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
    }
}

void ExpressionBinder::Visit(IdDeclaratorNode& idDeclaratorNode)
{
    symbols = std::move(BindExpression(idDeclaratorNode.IdNode(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
}

void ExpressionBinder::Visit(CommaExpressionNode& commaExpressionNode)
{
    BindExpression(commaExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(commaExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(AssignmentExpressionNode& assignmentExpressionNode)
{
    BindExpression(assignmentExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(assignmentExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(ConditionalExpressionNode& conditionalExpressionNode)
{
    BindExpression(conditionalExpressionNode.Condition(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(conditionalExpressionNode.ThenExpr(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(conditionalExpressionNode.ElseExpr(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(ThrowExpressionNode& throwExpressionNode)
{
    if (throwExpressionNode.Child())
    {
        BindExpression(throwExpressionNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    }
}

void ExpressionBinder::Visit(LogicalOrExpressionNode& logicalOrExpressionNode)
{
    BindExpression(logicalOrExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(logicalOrExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(LogicalAndExpressionNode& logicalAndExpressionNode)
{
    BindExpression(logicalAndExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(logicalAndExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(InclusiveOrExpressionNode& inclusiveOrExpressionNode)
{
    BindExpression(inclusiveOrExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(inclusiveOrExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(ExclusiveOrExpressionNode& exclusiveOrExpressionNode)
{
    BindExpression(exclusiveOrExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(exclusiveOrExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(AndExpressionNode& andExpressionNode)
{
    BindExpression(andExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(andExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(EqualityExpressionNode& equalityExpressionNode)
{
    BindExpression(equalityExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(equalityExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(RelationalExpressionNode& relationalExpressionNode)
{
    BindExpression(relationalExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(relationalExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(ShiftExpressionNode& shiftExpressionNode)
{
    BindExpression(shiftExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(shiftExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(AdditiveExpressionNode& additiveExpressionNode)
{
    BindExpression(additiveExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(additiveExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(MultiplicativeExpressionNode& multiplicativeExpressionNode)
{
    BindExpression(multiplicativeExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(multiplicativeExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(PMExpressionNode& pmExpressionNode)
{
    BindExpression(pmExpressionNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(pmExpressionNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(CastExpressionNode& castExpressionNode)
{
    BindExpression(castExpressionNode.TypeExpr(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(castExpressionNode.Expr(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(UnaryExpressionNode& unaryExpressionNode)
{
    std::vector<Symbol*> subjectSymbols = BindExpression(unaryExpressionNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
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
        BindExpression(newExpressionNode.Placement(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    }
    BindExpression(newExpressionNode.TypeExpr(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    if (newExpressionNode.Initializer())
    {
        BindExpression(newExpressionNode.Initializer(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    }
}

void ExpressionBinder::Visit(SubscriptExpressionNode& subscriptExpressionNode)
{
    BindExpression(subscriptExpressionNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(subscriptExpressionNode.Index(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(InvokeExpressionNode& invokeExpressionNode)
{
    FunctionGroupSymbol* functionGroup = nullptr;
    bool subjectIsConst = false;
    std::vector<Symbol*> subjectSymbols = BindExpression(invokeExpressionNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder,
        subjectIsConst);
    if (!subjectSymbols.empty())
    {
        Symbol* subject = subjectSymbols.front();
        if (subject)
        {
            if (subject->IsFunctionGroupSymbol())
            {
                functionGroup = static_cast<FunctionGroupSymbol*>(subject);
            }
            else if (subject->IsTypeSymbol())
            {
                TypeSymbol* type = static_cast<TypeSymbol*>(subject);
                if (type->IsTypedefSymbol())
                {
                    TypedefSymbol* typedefSymbol = static_cast<TypedefSymbol*>(type);
                    type = typedefSymbol->GetType();
                }
                if (type && type->IsClassTemplateSpecializationSymbol())
                {
                    ClassTemplateSpecializationSymbol* specialization = static_cast<ClassTemplateSpecializationSymbol*>(type);
                    type = specialization->PrimaryClassTemplateSymbol();
                }
                if (type && type->IsClassTypeSymbol())
                {
                    ClassTypeSymbol* classType = static_cast<ClassTypeSymbol*>(type);
                    Symbol* symbol = classType->GetContainerScope()->Lookup(U"constructor");
                    if (symbol && symbol->IsFunctionGroupSymbol())
                    {
                        functionGroup = static_cast<FunctionGroupSymbol*>(symbol);
                    }
                }
            }
        }
    }
    std::vector<Symbol*> argumentSymbols;
    if (invokeExpressionNode.Arguments())
    {
        argumentSymbols = std::move(BindExpression(invokeExpressionNode.Arguments(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
    }
    if (functionGroup)
    {
        CallableSymbol* functionSymbol = functionGroup->ResolveOverload(argumentSymbols, invokeExpressionNode.Child()->GetNodeType() == NodeType::arrowNode && subjectIsConst);
        if (functionSymbol)
        {
            symbolTable.MapNode(&invokeExpressionNode, functionSymbol);
            symbols.push_back(functionSymbol);
            if (symbolTable.InGendocMode() && functionSymbol->IsFunctionSymbol())
            {
                currentFunction->AddToCalls(static_cast<FunctionSymbol*>(functionSymbol));
                static_cast<FunctionSymbol*>(functionSymbol)->AddToCalledBy(currentFunction);
            }
        }
    }
}

void ExpressionBinder::Visit(DotNode& dotNode)
{
    std::vector<Symbol*> leftSymbols = BindExpression(dotNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    Symbol* s = nullptr;
    if (!leftSymbols.empty())
    {
        s = leftSymbols.front();
    }
    if (s)
    {
        sngcpp::symbols::TypeSymbol* type = s->GetType();
        if (type)
        {
            if (type->IsReferenceTypeSymbol())
            {
                type = type->BaseType();
            }
            if (type->IsTypedefSymbol())
            {
                TypedefSymbol* typedefSymbol = static_cast<TypedefSymbol*>(type);
                type = typedefSymbol->GetType();
            }
            if (type)
            {
                if (std::find(prevContainerScopes.begin(), prevContainerScopes.end(), containerScope) == prevContainerScopes.end()) prevContainerScopes.push_back(containerScope);
                if (type->IsClassTemplateSpecializationSymbol())
                {
                    ClassTemplateSpecializationSymbol* specialization = static_cast<ClassTemplateSpecializationSymbol*>(type);
                    type = specialization->PrimaryClassTemplateSymbol();
                }
                containerScope = type->BaseType()->GetContainerScope();
            }
        }
    }
    if (containerScope)
    {
        symbols = std::move(BindExpression(dotNode.Id(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
    }
}

void ExpressionBinder::Visit(ArrowNode& arrowNode)
{
    std::vector<Symbol*> leftSymbols = BindExpression(arrowNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    Symbol* s = nullptr;
    if (!leftSymbols.empty())
    {
        s = leftSymbols.front();
    }
    if (s)
    {
        sngcpp::symbols::TypeSymbol* type = s->GetType();
        if (type)
        {
            if (type->HasConstDerivation())
            {
                subjectIsConst = true;
            }
            else
            {
                subjectIsConst = false;
            }
            if (type->IsTypedefSymbol())
            {
                TypedefSymbol* typedefSymbol = static_cast<TypedefSymbol*>(type);
                type = typedefSymbol->GetType();
            }
            if (std::find(prevContainerScopes.begin(), prevContainerScopes.end(), containerScope) == prevContainerScopes.end()) prevContainerScopes.push_back(containerScope);
            if (type->IsClassTemplateSpecializationSymbol())
            {
                ClassTemplateSpecializationSymbol* specialization = static_cast<ClassTemplateSpecializationSymbol*>(type);
                type = specialization->PrimaryClassTemplateSymbol();
            }
            containerScope = type->BaseType()->GetContainerScope();
        }
    }
    if (containerScope)
    {
        symbols = std::move(BindExpression(arrowNode.Id(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
    }
}

void ExpressionBinder::Visit(PostfixIncNode& postfixIncNode)
{
    BindExpression(postfixIncNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(PostfixDecNode& postfixDecNode)
{
    BindExpression(postfixDecNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(CppCastExpressionNode& cppCastExpressionNode)
{
    BindExpression(cppCastExpressionNode.TypeExpr(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(cppCastExpressionNode.Expr(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(TypeIdExpressionNode& typeIdExpressionNode)
{
    BindExpression(typeIdExpressionNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(ThisNode& thisNode)
{
    ClassTypeSymbol* cls = currentFunction->Class();
    if (cls)
    {
        symbols.push_back(cls);
    }
}

void ExpressionBinder::Visit(ParenthesizedExprNode& parenthesizedExprNode)
{
    BindExpression(parenthesizedExprNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(LambdaExpressionNode& lambdaExpressionNode)
{
    if (lambdaExpressionNode.Captures())
    {
        BindExpression(lambdaExpressionNode.Captures(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    }
    lambdaExpressionNode.Body()->Accept(*statementBinder);
}

void ExpressionBinder::Visit(CaptureSequenceNode& captureSequenceNode)
{
    BindExpression(captureSequenceNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
    BindExpression(captureSequenceNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(IdentifierCaptureNode& identifierCaptureNode)
{
    BindExpression(identifierCaptureNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(NestedIdNode& nestedIdNode)
{
    std::vector<Symbol*> symbols;
    if (nestedIdNode.Left())
    {
        symbols = std::move(BindExpression(nestedIdNode.Left(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
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
            if (std::find(prevContainerScopes.begin(), prevContainerScopes.end(), containerScope) == prevContainerScopes.end()) prevContainerScopes.push_back(containerScope);
            containerScope = s->GetContainerScope();
        }
        else if (s->IsTypedefSymbol())
        {
            TypedefSymbol* typedefSymbol = static_cast<TypedefSymbol*>(s);
            sngcpp::symbols::TypeSymbol* type = typedefSymbol->GetType();
            if (std::find(prevContainerScopes.begin(), prevContainerScopes.end(), containerScope) == prevContainerScopes.end()) prevContainerScopes.push_back(containerScope);
            containerScope = type->GetContainerScope();
        }
        else if (s->IsTypeSymbol())
        {
            if (std::find(prevContainerScopes.begin(), prevContainerScopes.end(), containerScope) == prevContainerScopes.end()) prevContainerScopes.push_back(containerScope);
            containerScope = s->GetContainerScope();
        }
        else if (s->IsClassGroupSymbol())
        {
            ClassGroupSymbol* group = static_cast<ClassGroupSymbol*>(s);
            ClassTypeSymbol* cls = group->GetClass(0);
            if (cls)
            {
                if (std::find(prevContainerScopes.begin(), prevContainerScopes.end(), containerScope) == prevContainerScopes.end()) prevContainerScopes.push_back(containerScope);
                containerScope = cls->GetContainerScope();
            }
        }
    }
    if (containerScope)
    {
        symbols = std::move(BindExpression(nestedIdNode.Right(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder));
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
        if (!symbol)
        {
            for (ContainerScope* prevContainerScope : prevContainerScopes)
            {
                symbol = prevContainerScope->Lookup(identifierNode.Identifier(), ScopeLookup::this_and_bases_and_parent);
                if (symbol)
                {
                    break;
                }
            }
        }
    }
    if (symbol)
    {
        symbolTable.MapNode(&identifierNode, symbol);
        symbols.push_back(symbol);
    }
}

void ExpressionBinder::Visit(DtorIdNode& dtorIdNode)
{
    ClassTypeSymbol* currentClassType = nullptr;
    if (currentFunction && currentFunction->Parent() && currentFunction->Parent()->IsClassTypeSymbol())
    {
        currentClassType = static_cast<ClassTypeSymbol*>(currentFunction->Parent());
    }
    if (currentClassType)
    {
        symbolTable.MapNode(&dtorIdNode, currentClassType);
    }
}

void ExpressionBinder::Visit(TemplateIdNode& templateIdNode)
{
    ClassTypeSymbol* currentClassType = nullptr;
    if (currentFunction && currentFunction->Parent() && currentFunction->Parent()->IsClassTypeSymbol())
    {
        currentClassType = static_cast<ClassTypeSymbol*>(currentFunction->Parent());
    }
    TypeSymbol* type = ResolveType(symbolTable, containerScope, prevContainerScopes, *boundSourceFile, TypeResolverFlags::none, currentClassType, &templateIdNode);
    symbols.push_back(type);
}

void ExpressionBinder::Visit(ConstNode& constNode)
{
    BindExpression(constNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(VolatileNode& volatileNode)
{
    BindExpression(volatileNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(PointerNode& pointerNode)
{
    BindExpression(pointerNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(RValueRefNode& rValueRefNode)
{
    BindExpression(rValueRefNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(LValueRefNode& lValueRefNode)
{
    BindExpression(lValueRefNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(DeleteExpressionNode& deleteExpressionNode)
{
    BindExpression(deleteExpressionNode.Child(), symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder);
}

void ExpressionBinder::Visit(IntegerLiteralNode& integerLiteralNode)
{
    TypeSymbol* type = symbolTable.GetIntType();
    symbols.push_back(type);
}

void ExpressionBinder::Visit(StringLiteralNode& stringLiteralNode)
{
    if (stringLiteralNode.EncodigPrefix().empty() || stringLiteralNode.EncodigPrefix() == U"u8")
    {
        std::vector<sngcpp::symbols::Derivation> derivations;
        derivations.push_back(sngcpp::symbols::Derivation::const_);
        derivations.push_back(sngcpp::symbols::Derivation::lvalueRef);
        TypeSymbol* type = symbolTable.MakeDerivedTypeSymbol(derivations, symbolTable.MakeExternalTypeSymbol(stringLiteralNode.GetSpan(), U"std::string", sngcpp::ast::ClassKey::none));
        symbols.push_back(type);
    }
    else if (stringLiteralNode.EncodigPrefix() == U"u")
    {
        std::vector<sngcpp::symbols::Derivation> derivations;
        derivations.push_back(sngcpp::symbols::Derivation::const_);
        derivations.push_back(sngcpp::symbols::Derivation::lvalueRef);
        TypeSymbol* type = symbolTable.MakeDerivedTypeSymbol(derivations, symbolTable.MakeExternalTypeSymbol(stringLiteralNode.GetSpan(), U"std::u16string", sngcpp::ast::ClassKey::none));
        symbols.push_back(type);
    }
    else if (stringLiteralNode.EncodigPrefix() == U"U")
    {
        std::vector<sngcpp::symbols::Derivation> derivations;
        derivations.push_back(sngcpp::symbols::Derivation::const_);
        derivations.push_back(sngcpp::symbols::Derivation::lvalueRef);
        TypeSymbol* type = symbolTable.MakeDerivedTypeSymbol(derivations, symbolTable.MakeExternalTypeSymbol(stringLiteralNode.GetSpan(), U"std::u32string", sngcpp::ast::ClassKey::none));
        symbols.push_back(type);
    }
    else if (stringLiteralNode.EncodigPrefix() == U"L")
    {
        std::vector<sngcpp::symbols::Derivation> derivations;
        derivations.push_back(sngcpp::symbols::Derivation::const_);
        derivations.push_back(sngcpp::symbols::Derivation::lvalueRef);
        TypeSymbol* type = symbolTable.MakeDerivedTypeSymbol(derivations, symbolTable.MakeExternalTypeSymbol(stringLiteralNode.GetSpan(), U"std::wstring", sngcpp::ast::ClassKey::none));
        symbols.push_back(type);
    }
}

std::vector<Symbol*> BindExpression(Node* node, SymbolTable& symbolTable, ContainerScope* containerScope, const std::vector<ContainerScope*>& prevContainerScopes, BoundSourceFile* boundSourceFile,
    FunctionSymbol* currentFunction, StatementBinder* statementBinder, bool& subjectIsConst)
{
    ExpressionBinder expressionBinder(symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder, subjectIsConst);
    node->Accept(expressionBinder);
    std::vector<Symbol*> symbols = expressionBinder.GetSymbols();
    if (symbols.empty())
    {
        ClassTypeSymbol* currentClassType = nullptr;
        if (currentFunction && currentFunction->Parent() && currentFunction->Parent()->IsClassTypeSymbol())
        {
            currentClassType = static_cast<ClassTypeSymbol*>(currentFunction->Parent());
        }
        sngcpp::symbols::TypeSymbol* type = ResolveType(symbolTable, containerScope, prevContainerScopes, *boundSourceFile, TypeResolverFlags::noExternalTypes | TypeResolverFlags::nothrow,
            currentClassType, node);
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

std::vector<Symbol*> BindExpression(Node* node, SymbolTable& symbolTable, ContainerScope* containerScope, const std::vector<ContainerScope*>& prevContainerScopes, BoundSourceFile* boundSourceFile,
    FunctionSymbol* currentFunction, StatementBinder* statementBinder)
{
    bool subjectIsConst = false;
    return BindExpression(node, symbolTable, containerScope, prevContainerScopes, boundSourceFile, currentFunction, statementBinder, subjectIsConst);
}

} } // namespace sngcppp::binder
