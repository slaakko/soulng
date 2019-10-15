// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_VISITOR_INCLUDED
#define SNGCPP_AST_VISITOR_INCLUDED
#include <sngcpp/ast/AstApi.hpp>

namespace sngcpp { namespace ast {

class BaseClassSpecifierNode;
class BaseClassSpecifierSequenceNode;
class ForwardClassDeclarationNode;
class ElaborateClassNameNode;
class ClassNode;
class MemberAccessDeclarationNode;
class MemberDeclarationNode;
class SpecialMemberFunctionNode;
class CtorInitializerNode;
class MemberInitializerNode;
class MemberInitializerSequenceNode;
class SourceFileNode;
class SourceFileSequenceNode;
class IncludeDirectiveNode;
class IncludeDirectiveSequenceNode;
class SimpleDeclarationNode;
class AliasDeclarationNode;
class UsingDirectiveNode;
class UsingDeclarationNode;
class TypedefNode;
class DeclarationSequenceNode;
class LinkageSpecificationNode;
class IdDeclaratorNode;
class ArrayDeclaratorNode;
class FunctionDeclaratorNode;
class FunctionPtrIdNode;
class MemberFunctionPtrIdNode;
class InitDeclaratorNode;
class AssignmentInitializerNode;
class ExpressionListInitializerNode;
class ExpressionInitializerNode;
class BracedInitializerListNode;
class EnumTypeNode;
class EnumeratorNode;
class EnumeratorSequenceNode;
class ExpressionSequenceNode;
class CommaExpressionNode;
class AssignmentExpressionNode;
class ConditionalExpressionNode;
class ThrowExpressionNode;
class LogicalOrExpressionNode;
class LogicalAndExpressionNode;
class InclusiveOrExpressionNode;
class ExclusiveOrExpressionNode;
class AndExpressionNode;
class EqualityExpressionNode;
class RelationalExpressionNode;
class ShiftExpressionNode;
class AdditiveExpressionNode;
class MultiplicativeExpressionNode;
class PMExpressionNode;
class CastExpressionNode;
class UnaryExpressionNode;
class NewExpressionNode;
class DeleteExpressionNode;
class SubscriptExpressionNode;
class InvokeExpressionNode;
class DotNode;
class ArrowNode;
class PostfixIncNode;
class PostfixDecNode;
class CppCastExpressionNode;
class TypeIdExpressionNode;
class ThisNode;
class ParenthesizedExprNode;
class LambdaExpressionNode;
class CaptureSequenceNode;
class AssignCapture;
class RefCapture;
class ThisCapture;
class IdentifierCapture;
class IdentifierNode;
class OperatorFunctionIdNode;
class ConversionFunctionIdNode;
class DtorIdNode;
class NestedIdNode;
class ParameterNode;
class ParameterSequenceNode;
class FunctionNode;
class FloatingLiteralNode;
class IntegerLiteralNode;
class CharacterLiteralNode;
class StringLiteralNode;
class BooleanLiteralNode;
class NullPtrLiteralNode;
class NamespaceNode;
class SimpleTypeNode;
class LabeledStatementNode;
class CaseStatementNode;
class DefaultStatementNode;
class ExpressionStatementNode;
class CompoundStatementNode;
class StatementSequenceNode;
class IfStatementNode;
class SwitchStatementNode;
class WhileStatementNode;
class DoStatementNode;
class RangeForStatementNode;
class ForStatementNode;
class BreakStatementNode;
class ContinueStatementNode;
class ReturnStatementNode;
class GotoStatementNode;
class DeclarationStatementNode;
class TryStatementNode;
class HandlerNode;
class HandlerSequenceNode;
class CatchAllNode;
class TypeParameterNode;
class TemplateParameterSequenceNode;
class TemplateDeclarationNode;
class TemplateArgumentSequenceNode;
class TemplateIdNode;
class TemplateArgumentNode;
class ExplicitInstantiationNode;
class ExplicitSpecializationNode;
class ConstNode;
class VolatileNode;
class PointerNode;
class RValueRefNode;
class LValueRefNode;
class TypeExprNode;

class SNGCPP_AST_API Visitor
{
public:
    virtual ~Visitor();
    virtual void Visit(BaseClassSpecifierNode& baseClassSpecifierNode) {}
    virtual void Visit(BaseClassSpecifierSequenceNode& baseClassSpecifierSequenceNode) {}
    virtual void Visit(ForwardClassDeclarationNode& forwardClassDeclarationNode) {}
    virtual void Visit(ElaborateClassNameNode& elaborateClassNameNode) {}
    virtual void Visit(ClassNode& classNode) {}
    virtual void Visit(MemberAccessDeclarationNode& memberAccessDeclarationNode) {}
    virtual void Visit(MemberDeclarationNode& memberDeclarationNode) {}
    virtual void Visit(SpecialMemberFunctionNode& specialMemberFunctionNode) {}
    virtual void Visit(CtorInitializerNode& ctorInitializerNode) {}
    virtual void Visit(MemberInitializerNode& memberInitializerNode) {}
    virtual void Visit(MemberInitializerSequenceNode& memberInitializerSequenceNode) {}
    virtual void Visit(SourceFileNode& sourceFileNode) {}
    virtual void Visit(SourceFileSequenceNode& sourceFileSequenceNode) {}
    virtual void Visit(IncludeDirectiveNode& includeDirectiveNode) {}
    virtual void Visit(IncludeDirectiveSequenceNode& includeDirectiveSequenceNode) {}
    virtual void Visit(SimpleDeclarationNode& simpleDeclarationNode) {}
    virtual void Visit(AliasDeclarationNode& aliasDeclarationNode) {}
    virtual void Visit(UsingDirectiveNode& usingDirectiveNode) {}
    virtual void Visit(UsingDeclarationNode& usingDeclarationNode) {}
    virtual void Visit(TypedefNode& typedefNode) {}
    virtual void Visit(DeclarationSequenceNode& declarationSequenceNode) {}
    virtual void Visit(LinkageSpecificationNode& linkageSpecificationNode) {}
    virtual void Visit(IdDeclaratorNode& idDeclaratorNode) {}
    virtual void Visit(ArrayDeclaratorNode& arrayDeclaratorNode) {}
    virtual void Visit(FunctionDeclaratorNode& functionDeclaratorNode) {}
    virtual void Visit(FunctionPtrIdNode& functionPtrIdNode) {}
    virtual void Visit(MemberFunctionPtrIdNode& memberFunctionPtrIdNode) {}
    virtual void Visit(InitDeclaratorNode& initDeclaratorNode) {}
    virtual void Visit(AssignmentInitializerNode& assignmentInitializerNode) {}
    virtual void Visit(ExpressionListInitializerNode& expressionListInitializerNode) {}
    virtual void Visit(ExpressionInitializerNode& expressionInitializerNode) {}
    virtual void Visit(BracedInitializerListNode& bracedInitializerListNode) {}
    virtual void Visit(EnumTypeNode& enumTypeNode) {}
    virtual void Visit(EnumeratorNode& enumeratorNode) {}
    virtual void Visit(EnumeratorSequenceNode& enumeratorSequenceNode) {}
    virtual void Visit(ExpressionSequenceNode& expressionSequenceNode) {}
    virtual void Visit(CommaExpressionNode& commaExpressionNode) {}
    virtual void Visit(AssignmentExpressionNode& assignmentExpressionNode) {}
    virtual void Visit(ConditionalExpressionNode& conditionalExpressionNode) {}
    virtual void Visit(ThrowExpressionNode& throwExpressionNode) {}
    virtual void Visit(LogicalOrExpressionNode& logicalOrExpressionNode) {}
    virtual void Visit(LogicalAndExpressionNode& logicalAndExpressionNode) {}
    virtual void Visit(InclusiveOrExpressionNode& inclusiveOrExpressionNode) {}
    virtual void Visit(ExclusiveOrExpressionNode& exclusiveOrExpressionNode) {}
    virtual void Visit(AndExpressionNode& andExpressionNode) {}
    virtual void Visit(EqualityExpressionNode& equalityExpressionNode) {}
    virtual void Visit(RelationalExpressionNode& relationalExpressionNode) {}
    virtual void Visit(ShiftExpressionNode& shiftExpressionNode) {}
    virtual void Visit(AdditiveExpressionNode& additiveExpressionNode) {}
    virtual void Visit(MultiplicativeExpressionNode& multiplicativeExpressionNode) {}
    virtual void Visit(PMExpressionNode& pmExpressionNode) {}
    virtual void Visit(CastExpressionNode& castExpressionNode) {}
    virtual void Visit(UnaryExpressionNode& unaryExpressionNode) {}
    virtual void Visit(NewExpressionNode& newExpressionNode) {}
    virtual void Visit(DeleteExpressionNode& deleteExpressionNode) {}
    virtual void Visit(SubscriptExpressionNode& subscriptExpressionNode) {}
    virtual void Visit(InvokeExpressionNode& invokeExpressionNode) {}
    virtual void Visit(DotNode& dotNode) {}
    virtual void Visit(ArrowNode& arrowNode) {}
    virtual void Visit(PostfixIncNode& postfixIncNode) {}
    virtual void Visit(PostfixDecNode& postfixDecNode) {}
    virtual void Visit(CppCastExpressionNode& cppCastExpressionNode) {}
    virtual void Visit(TypeIdExpressionNode& typeIdExpressionNode) {}
    virtual void Visit(ThisNode& thisNode) {}
    virtual void Visit(ParenthesizedExprNode& parenthesizedExprNode) {}
    virtual void Visit(LambdaExpressionNode& lambdaExpressionNode) {}
    virtual void Visit(CaptureSequenceNode& captureSequenceNode) {}
    virtual void Visit(AssignCapture& assignCapture) {}
    virtual void Visit(RefCapture& refCapture) {}
    virtual void Visit(ThisCapture& thisCapture) {}
    virtual void Visit(IdentifierCapture& identifierCapture) {}
    virtual void Visit(IdentifierNode& identifierNode) {}
    virtual void Visit(OperatorFunctionIdNode& operatorFunctionIdNode) {}
    virtual void Visit(ConversionFunctionIdNode& conversionFunctionIdNode) {}
    virtual void Visit(DtorIdNode& dDtorIdNode) {}
    virtual void Visit(NestedIdNode& nestedIdNode) {}
    virtual void Visit(ParameterNode& parameterNode) {}
    virtual void Visit(ParameterSequenceNode& parameterSequenceNode) {}
    virtual void Visit(FunctionNode& functionNode) {}
    virtual void Visit(FloatingLiteralNode& floatingLiteralNode) {}
    virtual void Visit(IntegerLiteralNode& integerLiteralNode) {}
    virtual void Visit(CharacterLiteralNode& characterLiteralNode) {}
    virtual void Visit(StringLiteralNode& stringLiteralNode) {}
    virtual void Visit(BooleanLiteralNode& booleanLiteralNode) {}
    virtual void Visit(NullPtrLiteralNode& nullPtrLiteralNode) {}
    virtual void Visit(NamespaceNode& namespaceNode) {}
    virtual void Visit(SimpleTypeNode& simpleTypeNode) {}
    virtual void Visit(LabeledStatementNode& labeledStatementNode) {}
    virtual void Visit(CaseStatementNode& caseStatementNode) {}
    virtual void Visit(DefaultStatementNode& defaultStatementNode) {}
    virtual void Visit(ExpressionStatementNode& expressionStatementNode) {}
    virtual void Visit(CompoundStatementNode& compoundStatementNode) {}
    virtual void Visit(StatementSequenceNode& statementSequenceNode) {}
    virtual void Visit(IfStatementNode& ifStatementNode) {}
    virtual void Visit(SwitchStatementNode& switchStatementNode) {}
    virtual void Visit(WhileStatementNode& whileStatementNode) {}
    virtual void Visit(DoStatementNode& doStatementNode) {}
    virtual void Visit(RangeForStatementNode& rangeForStatementNode) {}
    virtual void Visit(ForStatementNode& forStatementNode) {}
    virtual void Visit(BreakStatementNode& breakStatementNode) {}
    virtual void Visit(ContinueStatementNode& continueStatementNode) {}
    virtual void Visit(ReturnStatementNode& returnStatementNode) {}
    virtual void Visit(GotoStatementNode& gotoStatementNode) {}
    virtual void Visit(DeclarationStatementNode& declarationStatementNode) {}
    virtual void Visit(TryStatementNode& tryStatementNode) {}
    virtual void Visit(HandlerNode& handlerNode) {}
    virtual void Visit(HandlerSequenceNode& handlerSequenceNode) {}
    virtual void Visit(CatchAllNode& catchAllNode) {}
    virtual void Visit(TypeParameterNode& typeParameterNode) {}
    virtual void Visit(TemplateParameterSequenceNode& templateParameterSequenceNode) {}
    virtual void Visit(TemplateDeclarationNode& templateDeclarationNode) {}
    virtual void Visit(TemplateArgumentSequenceNode& templateArgumentSequenceNode) {}
    virtual void Visit(TemplateIdNode& templateIdNode) {}
    virtual void Visit(TemplateArgumentNode& templateArgumentNode) {}
    virtual void Visit(ExplicitInstantiationNode& explicitInstantiationNode) {}
    virtual void Visit(ExplicitSpecializationNode& explicitSpecializationNode) {}
    virtual void Visit(ConstNode& constNode) {}
    virtual void Visit(VolatileNode& volatileNode) {}
    virtual void Visit(PointerNode& pointerNode) {}
    virtual void Visit(RValueRefNode& rValueRefNode) {}
    virtual void Visit(LValueRefNode& lValueRefNode) {}
    virtual void Visit(TypeExprNode& typerExprNode) {}
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_VISITOR_INCLUDED
