// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_SYMBOL_CREATOR_INCLUDED
#define SNGCPP_SYMBOLS_SYMBOL_CREATOR_INCLUDED
#include <sngcpp/symbols/TypeSymbol.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <string>
#include <vector>
#include <stack>

namespace sngcpp { namespace symbols {

using namespace sngcpp::ast;

class SymbolTable;

class SNGCPP_SYMBOLS_API SymbolCreator : public sngcpp::ast::Visitor
{
public:
    SymbolCreator(SymbolTable& symbolTable_, const std::u32string& projectName_);
    SymbolCreator(const SymbolCreator&) = delete;
    SymbolCreator(SymbolCreator&&) = delete;
    SymbolCreator& operator=(const SymbolCreator&) = delete;
    SymbolCreator& operator=(SymbolCreator&&) = delete;
    void Visit(SourceFileNode& sourceFileNode) override;
    void Visit(SourceFileSequenceNode& sourceFileSequenceNode) override;
    void Visit(NamespaceNode& namespaceNode) override;
    void Visit(DeclarationSequenceNode& declarationSequenceNode) override;
    void Visit(LinkageSpecificationNode& linkageSpecificationNode) override;
    void Visit(TypedefNode& typedefNode) override;
    void Visit(TypeParameterNode& typeParameterNode) override;
    void Visit(TemplateParameterSequenceNode& templateParameterSequenceNode) override;
    void Visit(TemplateDeclarationNode& templateDeclarationNode) override;
    void Visit(ClassNode& classNode) override;
    void Visit(MemberAccessDeclarationNode& memberAccessDeclarationNode);
    void Visit(MemberDeclarationNode& memberDeclarationNode) override;
    void Visit(ArrayDeclaratorNode& arrayDeclaratorNode) override;
    void Visit(EnumTypeNode& enumTypeNode) override;
    void Visit(EnumeratorNode& enumeratorNode) override;
    void Visit(EnumeratorSequenceNode& enumeratorSequenceNode) override;
    void Visit(IdentifierNode& identifierNode) override;
    void Visit(TemplateIdNode& templateIdNode) override;
    void Visit(TemplateArgumentNode& templateArgumentNode) override;
    void Visit(OperatorFunctionIdNode& operatorFunctionIdNode) override;
    void Visit(ConversionFunctionIdNode& conversionFunctionIdNode) override;
    void Visit(NestedIdNode& nestedIdNode) override;
    void Visit(DtorIdNode& dDtorIdNode) override;
    void Visit(SimpleDeclarationNode& simpleDeclarationNode) override;
    void Visit(InitDeclaratorNode& initDeclaratorNode) override;
    void Visit(FunctionDeclaratorNode& functionDeclaratorNode) override;
    void Visit(FunctionPtrIdNode& functionPtrIdNode) override;
    void Visit(MemberFunctionPtrIdNode& memberFunctionPtrIdNode) override;
    void Visit(FunctionNode& functionNode) override;
    void Visit(SpecialMemberFunctionNode& specialMemberFunctionNode) override;
    void Visit(LabeledStatementNode& labeledStatementNode) override;
    void Visit(CompoundStatementNode& compoundStatementNode) override;
    void Visit(StatementSequenceNode& statementSequenceNode) override;
    void Visit(DeclarationStatementNode& declarationStatementNode) override;
    void Visit(IfStatementNode& ifStatementNode) override;
    void Visit(SwitchStatementNode& switchStatementNode) override;
    void Visit(CaseStatementNode& caseStatementNode) override;
    void Visit(DefaultStatementNode& defaultStatementNode) override;
    void Visit(WhileStatementNode& whileStatementNode) override;
    void Visit(DoStatementNode& doStatementNode) override;
    void Visit(RangeForStatementNode& rangeForStatementNode) override;
    void Visit(ForStatementNode& forStatementNode) override;
    void Visit(ReturnStatementNode& returnStatementNode) override;
    void Visit(TryStatementNode& tryStatementNode) override;
    void Visit(HandlerNode& handlerNode) override;
    void Visit(HandlerSequenceNode& handlerSequenceNode) override;
    void Visit(IdDeclaratorNode& idDeclaratorNode) override;
    void Visit(ParameterNode& parameterNode) override;
    void Visit(ParameterSequenceNode& parameterSequenceNode) override;
    void Visit(ExpressionStatementNode& expressionStatementNode) override;
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
    void Visit(DeleteExpressionNode& deleteExpressionNode) override;
    void Visit(SubscriptExpressionNode& subscriptExpressionNode) override;
    void Visit(DotNode& dotNode) override;
    void Visit(ExpressionSequenceNode& expressionSequenceNode) override;
    void Visit(InvokeExpressionNode& invokeExpressionNode) override;
    void Visit(AssignmentInitializerNode& assignmentInitializerNode) override;
    void Visit(ExpressionListInitializerNode& expressionListInitializerNode) override;
    void Visit(ExpressionInitializerNode& expressionInitializerNode) override;
    void Visit(BracedInitializerListNode& bracedInitializerListNode) override;
    void Visit(LambdaExpressionNode& lambdaExpressionNode) override;
    void Visit(CaptureSequenceNode& captureSequenceNode) override;
    void Visit(IdentifierCaptureNode& identifierCaptureNode) override;
    void SetCpp2CmMode() { cpp2cmMode = true; }
private:
    SymbolTable& symbolTable;
    std::u32string projectName;
    std::vector<std::pair<std::u32string, int>> nameSequence;
    std::vector<std::unique_ptr<TypeSymbol>> templateParameters;
    std::u32string groupName;
    bool functionBodyFollowsOrIsPureDeletedOrDefault;
    int nameSequenceCount;
    bool wasFunctionDeclaration;
    bool wasArrayDeclaration;
    bool skip;
    bool processingTemplateArguments;
    bool cpp2cmMode;
    Specifier specifiers;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_SYMBOL_CREATOR_INCLUDED

