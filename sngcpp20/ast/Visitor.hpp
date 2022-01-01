// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_VISITOR_INCLUDED
#define SNGCPP_AST_VISITOR_INCLUDED
#include <sngcpp20/ast/AstApi.hpp>
#include <soulng/lexer/SourcePos.hpp>

namespace sngcpp::ast {

using soulng::lexer::SourcePos;

// Base classes;
class Node;
class CompoundNode;
class UnaryNode;
class BinaryNode;
class SequenceNode;
class ListNode;
// Attribute:
class AttributeSpecifierSequenceNode;
class AttributeSpecifierNode;
class AttributeUsingPrefixNode;
class AttributeNode;
class AttributeScopedTokenNode;
class AttributeArgumentsNode;
class BalancedTokenSequenceNode;
class TokenNode;
class AlignmentSpecifierNode;
class LParenNode;
class RParenNode;
class LBracketNode;
class RBracketNode;
class LBraceNode;
class RBraceNode;
// Class:
class ClassSpecifierNode;
class ClassHeadNode;
class BaseClauseNode;
class BaseSpecifierListNode;
class BaseSpecifierNode;
class BeginAccessGroupNode;
class MemberDeclarationNode;
class MemberDeclaratorListNode;
class ConstructorNode;
class ConstructorInitializerNode;
class MemberInitializerListNode;
class MemberInitializerNode;
class VirtSpecifierSequenceNode;
class ClassNode;
class StructNode;
class UnionNode;
class PublicNode;
class ProtectedNode;
class PrivateNode;
class VirtualNode;
class OverrideNode;
class FinalNode;
class PureSpecifierNode;
// Concept:
class ConceptDefinitionNode;
class RequiresExprNode;
class RequirementBodyNode;
class SimpleRequirementNode;
class TypeRequirementNode;
class CompoundRequirementNode;
class ReturnTypeRequirementNode;
class NestedRequirementNode;
class TypeConstraintNode;
class RequiresClauseNode;
// Declaration:
class DeclarationSequenceNode;
class SimpleDeclarationNode;
class AsmDeclarationNode;
class AsmNode;
class LinkageSpecificationNode;
class NamespaceDefinitionNode;
class NamespaceBodyNode;
class NamespaceAliasDefinitionNode;
class UsingDeclarationNode;
class UsingNode;
class UsingDeclaratorListNode;
class UsingEnumDeclarationNode;
class UsingDirectiveNode;
class NamespaceNode;
class StaticAssertDeclarationNode;
class StaticAssertNode;
class AliasDeclarationNode;
class EmptyDeclarationNode;
class AttributeDeclarationNode;
class InitDeclaratorListNode;
class InitDeclaratorNode;
class TrailingFunctionDeclaratorNode;
class ParenthesizedDeclaratorNode;
class AbstractDeclaratorNode;
class DeclSpecifierSequenceNode;
class FriendNode;
class TypedefNode;
class ConstExprNode;
class ConstEvalNode;
class ConstInitNode;
class CDeclNode;
class FastCallNode;
class StdCallNode;
class ThisCallNode;
class VectorCallNode;
class UnalignedNode;
class DeclSpecNode;
class InlineNode;
class StaticNode;
class ThreadLocalNode;
class ExternNode;
class MutableNode;
class ExplicitNode;
class ConditionalExplicitNode;
class QualifiedPtrNode;
class PtrOperatorNode;
class PtrDeclaratorNode;
class PackDeclaratorIdNode;
class ArrayDeclaratorNode;
class FunctionDeclaratorNode;
class PrefixNode;
class TrailingQualifiersNode;
class TrailingAttributesNode;
class NoexceptSpecifierNode;
class ThrowSpecifierNode;
// Enum:
class EnumSpecifierNode;
class EnumHeadNode;
class EnumBaseNode;
class EnumClassNode;
class EnumStructNode;
class EnumNode;
class EnumeratorDefinitionNode;
class EnumeratorNode;
class ElaboratedEnumSpecifierNode;
class OpaqueEnumDeclarationNode;
// Expression:
class BinaryExprNode;
class UnaryExprNode;
class ExpressionListNode;
class AssignmentInitNode;
class YieldExprNode;
class ThrowExprNode;
class ConditionalExprNode;
class CommaNode;
class AssignNode;
class PlusAssignNode;
class MinusAssignNode;
class MulAssignNode;
class DivAssignNode;
class ModAssignNode;
class XorAssignNode;
class AndAssignNode;
class OrAssignNode;
class ShiftLeftAssignNode;
class ShiftRightAssignNode;
class QuestNode;
class ColonNode;
class DisjunctionNode;
class ConjunctionNode;
class InclusiveOrNode;
class ExclusiveOrNode;
class AndNode;
class EqualNode;
class NotEqualNode;
class LessNode;
class GreaterNode;
class LessOrEqualNode;
class GreaterOrEqualNode;
class CompareNode;
class ShiftLeftNode;
class ShiftRightNode;
class PlusNode;
class MinusNode;
class MulNode;
class DivNode;
class ModNode;
class DotStarNode;
class ArrowStarNode;
class CastExprNode;
class DerefNode;
class AddrOfNode;
class NotNode;
class ComplementNode;
class PrefixIncNode;
class PrefixDecNode;
class AwaitExprNode;
class SizeOfTypeExprNode;
class SizeOfPackExprNode;
class SizeOfUnaryExprNode;
class AlignOfExprNode;
class NoexceptExprNode;
class NewExprNode;
class NewPlacementNode;
class ParenNewTypeIdNode;
class NewTypeIdNode;
class ArrayDeletePtrNode;
class DeletePtrNode;
class SubscriptExprNode;
class InvokeExprNode;
class PairNode;
class ArrowNode;
class MemberExprNode;
class PostfixIncExprNode;
class PostfixDecExprNode;
class TypeIdExprNode;
class DynamicCastNode;
class StaticCastNode;
class ReinterpretCastNode;
class ConstCastNode;
class CppCastExprNode;
class ThisNode;
class ParenthesizedExprNode;
class FoldExprNode;
class NewDeclaratorNode;
class ArrayNewDeclaratorNode;
class NewInitializerNode;
class BracedInitListNode;
class DesignatedInitializerNode;
class DesignatorNode;
class EllipsisNode;
// Function:
class FunctionDefinitionNode;
class FunctionBodyNode;
class DefaultNode;
class DeleteNode;
class DefaultedOrDeletedFunctionNode;
class FunctionDeclarationNode;
class OperatorNode;
class NewArrayOpNode;
class NewOpNode;
class DeleteArrayOpNode;
class DeleteOpNode;
class CoAwaitOpNode;
class InvokeOpNode;
class SubscriptOpNode;
class OperatorFunctionIdNode;
class ConversionFunctionIdNode;
class ConversionTypeIdNode;
class ConversionDeclaratorNode;
class DestructorIdNode;
class ParameterNode;
class ParameterListNode;
class NoexceptNode;
class FunctionTryBlockNode;
// Identifier:
class IdentifierNode;
class UnnamedNode;
class ColonColonNode;
class NestedNameSpecifierNode;
class QualifiedIdNode;
class IdentifierListNode;
class QualifiedModuleIdNode;
class DotNode;
// Lambda:
class LambdaExpressionNode;
class LambdaIntroducerNode;
class LambdaCaptureNode;
class DefaultRefCaptureNode;
class DefaultCopyCaptureNode;
class ByRefCaptureNode;
class SimpleCaptureNode;
class CurrentObjectCopyCapture;
class CurrentObjectByRefCapture;
class InitCaptureNode;
class LambdaDeclaratorNode;
class LambdaSpecifiersNode;
class LambdaTemplateParamsNode;
// Literal:
class IntegerLiteralNode;
class FloatingLiteralNode;
class CharacterLiteralNode;
class StringLiteralNode;
class RawStringLiteralNode;
class BooleanLiteralNode;
class NullPtrLiteralNode;
class UserDefinedLiteraNode;
class LiteralOperatorIdNode;
// Module:
class ModuleDeclarationNode;
class ExportDeclarationNode;
class ExportNode;
class ImportNode;
class ImportDeclarationNode;
class ModulePartitionNode;
class ModuleNode;
class GlobalModuleFragmentNode;
class PrivateModuleFragmentNode;
class AngleHeaderName;
class QuoteHeaderName;
// Qualifier:
class ConstNode;
class VolatileNode;
class LvalueRefNode;
class RvalueRefNode;
class PtrNode;
class CVQualifierSequenceNode;
// SimpleType:
class CharNode;
class Char8Node;
class Char16Node;
class Char32Node;
class WCharNode;
class BoolNode;
class ShortNode;
class IntNode;
class LongNode;
class SignedNode;
class UnsignedNode;
class FloatNode;
class DoubleNode;
class VoidNode;
class Int64Node;
class Int32Node;
class Int16Node;
class Int8Node;
// Statement:
class LabeledStatementNode;
class CaseStatementNode;
class DefaultStatementNode;
class CompoundStatementNode;
class IfStatementNode;
class SwitchStatementNode;
class WhileStatementNode;
class DoStatementNode;
class RangeForStatementNode;
class ForRangeDeclarationNode;
class StructuredBindingNode;
class ForStatementNode;
class BreakStatementNode;
class ContinueStatementNode;
class ReturnStatementNode;
class CoReturnStatementNode;
class GotoStatementNode;
class TryStatementNode;
class HandlerSequenceNode;
class HandlerNode;
class ExceptionDeclarationNode;
class ExpressionStatementNode;
class DeclarationStatementNode;
class InitConditionNode;
class SemicolonNode;
// Template:
class TemplateDeclarationNode;
class TemplateHeadNode;
class TemplateParameterListNode;
class TypeParameterNode;
class TemplateIdNode;
class TypenameNode;
class DeductionGuideNode;
class ExplicitInstantiationNode;
class TemplateNode;
class ExplicitSpecializationNode;
// TranslationUnit:
class TranslationUnitNode;
class ModuleUnitNode;
// Type:
class TypeSpecifierSequenceNode;
class TypenameSpecifierNode;
class TypeIdNode;
class DefiningTypeIdNode;
class DefiningTypeSpecifierSequenceNode;
class TrailingReturnTypeNode;
class ElaboratedTypeSpecifierNode;
class DeclTypeSpecifierNode;
class PlaceholderTypeSpecifierNode;
// MS:
class PragmaNode;

class AST_API Visitor
{
public:
    virtual ~Visitor();

    void VisitSingleNode(Node& node);
    void VisitUnaryNode(UnaryNode& unaryNode);
    void VisitBinaryNode(BinaryNode& binaryNode);
    void VisitSequence(SequenceNode& sequenceNode);
    void VisitSequenceContent(SequenceNode& sequenceNode);
    void VisitList(ListNode& listNode);
    void VisitListContent(ListNode& listNode);

    virtual void BeginVisit(Node& node) {}
    virtual void EndVisit(Node& node) {}
    virtual void VisitIdentfier(const std::u32string& id, const SourcePos& sourcePos) {}
    virtual void VisitKeyword(const std::string& keyword, const SourcePos& sourcePos) {}
    virtual void VisitOperator(const std::string& symbol, const SourcePos& sourcePos) {}
    virtual void VisitToken(const std::u32string& tokenStr, const SourcePos& sourcePos) {}
    virtual void VisitLiteral(const std::u32string& rep, const SourcePos& sourcePos) {}
    virtual void VisitHeaderName(const std::u32string& rep, const SourcePos& sourcePos) {}

    //  Attribute:
    virtual void Visit(AttributeSpecifierSequenceNode& node) {}
    virtual void Visit(AttributeSpecifierNode& node) {}
    virtual void Visit(AttributeUsingPrefixNode& node) {}
    virtual void Visit(AttributeNode& node) {}
    virtual void Visit(AttributeScopedTokenNode& node) {}
    virtual void Visit(AttributeArgumentsNode& node) {}
    virtual void Visit(BalancedTokenSequenceNode& node) {}
    virtual void Visit(TokenNode& node) {}
    virtual void Visit(AlignmentSpecifierNode& node) {}
    virtual void Visit(LParenNode& node) {}
    virtual void Visit(RParenNode& node) {}
    virtual void Visit(LBracketNode& node) {}
    virtual void Visit(RBracketNode& node) {}
    virtual void Visit(LBraceNode& node) {}
    virtual void Visit(RBraceNode& node) {}
    //  Class:
    virtual void Visit(ClassSpecifierNode& node) {}
    virtual void Visit(ClassHeadNode& node) {}
    virtual void Visit(BaseClauseNode& node) {}
    virtual void Visit(BaseSpecifierListNode& node) {}
    virtual void Visit(BaseSpecifierNode& node) {}
    virtual void Visit(BeginAccessGroupNode& node) {}
    virtual void Visit(MemberDeclarationNode& node) {}
    virtual void Visit(MemberDeclaratorListNode& node) {}
    virtual void Visit(ConstructorNode& node) {}
    virtual void Visit(ConstructorInitializerNode& node) {}
    virtual void Visit(MemberInitializerListNode& node) {}
    virtual void Visit(MemberInitializerNode& node) {}
    virtual void Visit(VirtSpecifierSequenceNode& node) {}
    virtual void Visit(ClassNode& node) {}
    virtual void Visit(StructNode& node) {}
    virtual void Visit(UnionNode& node) {}
    virtual void Visit(PublicNode& node) {}
    virtual void Visit(ProtectedNode& node) {}
    virtual void Visit(PrivateNode& node) {}
    virtual void Visit(VirtualNode& node) {}
    virtual void Visit(OverrideNode& node) {}
    virtual void Visit(FinalNode& node) {}
    virtual void Visit(PureSpecifierNode& node) {}
    // Concept:
    virtual void Visit(ConceptDefinitionNode& node) {}
    virtual void Visit(RequiresExprNode& node) {}
    virtual void Visit(RequirementBodyNode& node) {}
    virtual void Visit(SimpleRequirementNode& node) {}
    virtual void Visit(TypeRequirementNode& node) {}
    virtual void Visit(CompoundRequirementNode& node) {}
    virtual void Visit(ReturnTypeRequirementNode& node) {}
    virtual void Visit(NestedRequirementNode& node) {}
    virtual void Visit(TypeConstraintNode& node) {}
    virtual void Visit(RequiresClauseNode& node) {}
    // Declaration:
    virtual void Visit(DeclarationSequenceNode& node) {}
    virtual void Visit(SimpleDeclarationNode& node) {}
    virtual void Visit(AsmDeclarationNode& node) {}
    virtual void Visit(AsmNode& node) {}
    virtual void Visit(LinkageSpecificationNode& node) {}
    virtual void Visit(NamespaceDefinitionNode& node) {}
    virtual void Visit(NamespaceBodyNode& node) {}
    virtual void Visit(NamespaceAliasDefinitionNode& node) {}
    virtual void Visit(UsingDeclarationNode& node) {}
    virtual void Visit(UsingNode& node) {}
    virtual void Visit(UsingDeclaratorListNode& node) {}
    virtual void Visit(UsingEnumDeclarationNode& node) {}
    virtual void Visit(UsingDirectiveNode& node) {}
    virtual void Visit(NamespaceNode& node) {}
    virtual void Visit(StaticAssertDeclarationNode& node) {}
    virtual void Visit(StaticAssertNode& node) {}
    virtual void Visit(AliasDeclarationNode& node) {}
    virtual void Visit(EmptyDeclarationNode& node) {}
    virtual void Visit(AttributeDeclarationNode& node) {}
    virtual void Visit(InitDeclaratorListNode& node) {}
    virtual void Visit(InitDeclaratorNode& node) {}
    virtual void Visit(TrailingFunctionDeclaratorNode& node) {}
    virtual void Visit(ParenthesizedDeclaratorNode& node) {}
    virtual void Visit(AbstractDeclaratorNode& node) {}
    virtual void Visit(DeclSpecifierSequenceNode& node) {}
    virtual void Visit(FriendNode& node) {}
    virtual void Visit(TypedefNode& node) {}
    virtual void Visit(ConstExprNode& node) {}
    virtual void Visit(ConstEvalNode& node) {}
    virtual void Visit(ConstInitNode& node) {}
    virtual void Visit(CDeclNode& node) {}
    virtual void Visit(FastCallNode& node) {}
    virtual void Visit(StdCallNode& node) {}
    virtual void Visit(ThisCallNode& node) {}
    virtual void Visit(VectorCallNode& node) {}
    virtual void Visit(UnalignedNode& node) {}
    virtual void Visit(DeclSpecNode& node) {}
    virtual void Visit(InlineNode& node) {}
    virtual void Visit(StaticNode& node) {}
    virtual void Visit(ThreadLocalNode& node) {}
    virtual void Visit(ExternNode& node) {}
    virtual void Visit(MutableNode& node) {}
    virtual void Visit(ExplicitNode& node) {}
    virtual void Visit(ConditionalExplicitNode& node) {}
    virtual void Visit(QualifiedPtrNode& node) {}
    virtual void Visit(PtrOperatorNode& node) {}
    virtual void Visit(PtrDeclaratorNode& node) {}
    virtual void Visit(PackDeclaratorIdNode& node) {}
    virtual void Visit(ArrayDeclaratorNode& node) {}
    virtual void Visit(FunctionDeclaratorNode& node) {}
    virtual void Visit(PrefixNode& node) {}
    virtual void Visit(TrailingQualifiersNode& node) {}
    virtual void Visit(TrailingAttributesNode& node) {}
    virtual void Visit(NoexceptSpecifierNode& node) {}
    virtual void Visit(ThrowSpecifierNode& node) {}
    // Enum:
    virtual void Visit(EnumSpecifierNode& node) {}
    virtual void Visit(EnumHeadNode& node) {}
    virtual void Visit(EnumBaseNode& node) {}
    virtual void Visit(EnumClassNode& node) {}
    virtual void Visit(EnumStructNode& node) {}
    virtual void Visit(EnumNode& node) {}
    virtual void Visit(EnumeratorDefinitionNode& node) {}
    virtual void Visit(EnumeratorNode& node) {}
    virtual void Visit(ElaboratedEnumSpecifierNode& node) {}
    virtual void Visit(OpaqueEnumDeclarationNode& node) {}
    // Expression:
    virtual void Visit(BinaryExprNode& node) {}
    virtual void Visit(UnaryExprNode& node) {}
    virtual void Visit(ExpressionListNode& node) {}
    virtual void Visit(AssignmentInitNode& node) {}
    virtual void Visit(YieldExprNode& node) {}
    virtual void Visit(ThrowExprNode& node) {}
    virtual void Visit(ConditionalExprNode& node) {}
    virtual void Visit(CommaNode& node) {}
    virtual void Visit(AssignNode& node) {}
    virtual void Visit(PlusAssignNode& node) {}
    virtual void Visit(MinusAssignNode& node) {}
    virtual void Visit(MulAssignNode& node) {}
    virtual void Visit(DivAssignNode& node) {}
    virtual void Visit(ModAssignNode& node) {}
    virtual void Visit(XorAssignNode& node) {}
    virtual void Visit(AndAssignNode& node) {}
    virtual void Visit(OrAssignNode& node) {}
    virtual void Visit(ShiftLeftAssignNode& node) {}
    virtual void Visit(ShiftRightAssignNode& node) {}
    virtual void Visit(QuestNode& node) {}
    virtual void Visit(ColonNode& node) {}
    virtual void Visit(DisjunctionNode& node) {}
    virtual void Visit(ConjunctionNode& node) {}
    virtual void Visit(InclusiveOrNode& node) {}
    virtual void Visit(ExclusiveOrNode& node) {}
    virtual void Visit(AndNode& node) {}
    virtual void Visit(EqualNode& node) {}
    virtual void Visit(NotEqualNode& node) {}
    virtual void Visit(LessNode& node) {}
    virtual void Visit(GreaterNode& node) {}
    virtual void Visit(LessOrEqualNode& node) {}
    virtual void Visit(GreaterOrEqualNode& node) {}
    virtual void Visit(CompareNode& node) {}
    virtual void Visit(ShiftLeftNode& node) {}
    virtual void Visit(ShiftRightNode& node) {}
    virtual void Visit(PlusNode& node) {}
    virtual void Visit(MinusNode& node) {}
    virtual void Visit(MulNode& node) {}
    virtual void Visit(DivNode& node) {}
    virtual void Visit(ModNode& node) {}
    virtual void Visit(DotStarNode& node) {}
    virtual void Visit(ArrowStarNode& node) {}
    virtual void Visit(CastExprNode& node) {}
    virtual void Visit(DerefNode& node) {}
    virtual void Visit(AddrOfNode& node) {}
    virtual void Visit(NotNode& node) {}
    virtual void Visit(ComplementNode& node) {}
    virtual void Visit(PrefixIncNode& node) {}
    virtual void Visit(PrefixDecNode& node) {}
    virtual void Visit(AwaitExprNode& node) {}
    virtual void Visit(SizeOfTypeExprNode& node) {}
    virtual void Visit(SizeOfPackExprNode& node) {}
    virtual void Visit(SizeOfUnaryExprNode& node) {}
    virtual void Visit(AlignOfExprNode& node) {}
    virtual void Visit(NoexceptExprNode& node) {}
    virtual void Visit(NewExprNode& node) {}
    virtual void Visit(NewPlacementNode& node) {}
    virtual void Visit(ParenNewTypeIdNode& node) {}
    virtual void Visit(NewTypeIdNode& node) {}
    virtual void Visit(ArrayDeletePtrNode& node) {}
    virtual void Visit(DeletePtrNode& node) {}
    virtual void Visit(SubscriptExprNode& node) {}
    virtual void Visit(InvokeExprNode& node) {}
    virtual void Visit(PairNode& node) {}
    virtual void Visit(ArrowNode& node) {}
    virtual void Visit(MemberExprNode& node) {}
    virtual void Visit(PostfixIncExprNode& node) {}
    virtual void Visit(PostfixDecExprNode& node) {}
    virtual void Visit(TypeIdExprNode& node) {}
    virtual void Visit(DynamicCastNode& node) {}
    virtual void Visit(StaticCastNode& node) {}
    virtual void Visit(ReinterpretCastNode& node) {}
    virtual void Visit(ConstCastNode& node) {}
    virtual void Visit(CppCastExprNode& node) {}
    virtual void Visit(ThisNode& node) {}
    virtual void Visit(ParenthesizedExprNode& node) {}
    virtual void Visit(FoldExprNode& node) {}
    virtual void Visit(NewDeclaratorNode& node) {}
    virtual void Visit(ArrayNewDeclaratorNode& node) {}
    virtual void Visit(NewInitializerNode& node) {}
    virtual void Visit(BracedInitListNode& node) {}
    virtual void Visit(DesignatedInitializerNode& node) {}
    virtual void Visit(DesignatorNode& node) {}
    virtual void Visit(EllipsisNode& node) {}
    // Function:
    virtual void Visit(FunctionDefinitionNode& node) {}
    virtual void Visit(FunctionBodyNode& node) {}
    virtual void Visit(DefaultNode& node) {}
    virtual void Visit(DeleteNode& node) {}
    virtual void Visit(DefaultedOrDeletedFunctionNode& node) {}
    virtual void Visit(FunctionDeclarationNode& node) {}
    virtual void Visit(OperatorNode& node) {}
    virtual void Visit(NewArrayOpNode& node) {}
    virtual void Visit(NewOpNode& node) {}
    virtual void Visit(DeleteArrayOpNode& node) {}
    virtual void Visit(DeleteOpNode& node) {}
    virtual void Visit(CoAwaitOpNode& node) {}
    virtual void Visit(InvokeOpNode& node) {}
    virtual void Visit(SubscriptOpNode& node) {}
    virtual void Visit(OperatorFunctionIdNode& node) {}
    virtual void Visit(ConversionFunctionIdNode& node) {}
    virtual void Visit(ConversionTypeIdNode& node) {}
    virtual void Visit(ConversionDeclaratorNode& node) {}
    virtual void Visit(DestructorIdNode& node) {}
    virtual void Visit(ParameterNode& node) {}
    virtual void Visit(ParameterListNode& node) {}
    virtual void Visit(NoexceptNode& node) {}
    virtual void Visit(FunctionTryBlockNode& node) {}
    // Identifier:
    virtual void Visit(IdentifierNode& node) {}
    virtual void Visit(UnnamedNode& node) {}
    virtual void Visit(ColonColonNode& node) {}
    virtual void Visit(NestedNameSpecifierNode& node) {}
    virtual void Visit(QualifiedIdNode& node) {}
    virtual void Visit(IdentifierListNode& node) {}
    virtual void Visit(QualifiedModuleIdNode& node) {}
    virtual void Visit(DotNode& node) {}
    // Lambda:
    virtual void Visit(LambdaExpressionNode& node) {}
    virtual void Visit(LambdaIntroducerNode& node) {}
    virtual void Visit(LambdaCaptureNode& node) {}
    virtual void Visit(DefaultRefCaptureNode& node) {}
    virtual void Visit(DefaultCopyCaptureNode& node) {}
    virtual void Visit(ByRefCaptureNode& node) {}
    virtual void Visit(SimpleCaptureNode& node) {}
    virtual void Visit(CurrentObjectCopyCapture& node) {}
    virtual void Visit(CurrentObjectByRefCapture& node) {}
    virtual void Visit(InitCaptureNode& node) {}
    virtual void Visit(LambdaDeclaratorNode& node) {}
    virtual void Visit(LambdaSpecifiersNode& node) {}
    virtual void Visit(LambdaTemplateParamsNode& node) {}
    // Literal:
    virtual void Visit(IntegerLiteralNode& node) {}
    virtual void Visit(FloatingLiteralNode& node) {}
    virtual void Visit(CharacterLiteralNode& node) {}
    virtual void Visit(StringLiteralNode& node) {}
    virtual void Visit(RawStringLiteralNode& node) {}
    virtual void Visit(BooleanLiteralNode& node) {}
    virtual void Visit(NullPtrLiteralNode& node) {}
    virtual void Visit(UserDefinedLiteraNode& node) {}
    virtual void Visit(LiteralOperatorIdNode& node) {}
    // Module:
    virtual void Visit(ModuleDeclarationNode& node) {}
    virtual void Visit(ExportDeclarationNode& node) {}
    virtual void Visit(ExportNode& node) {}
    virtual void Visit(ImportNode& node) {}
    virtual void Visit(ImportDeclarationNode& node) {}
    virtual void Visit(ModulePartitionNode& node) {}
    virtual void Visit(ModuleNode& node) {}
    virtual void Visit(GlobalModuleFragmentNode& node) {}
    virtual void Visit(PrivateModuleFragmentNode& node) {}
    virtual void Visit(AngleHeaderName& node) {}
    virtual void Visit(QuoteHeaderName& node) {}
    // Qualifier:
    virtual void Visit(ConstNode& node) {}
    virtual void Visit(VolatileNode& node) {}
    virtual void Visit(LvalueRefNode& node) {}
    virtual void Visit(RvalueRefNode& node) {}
    virtual void Visit(PtrNode& node) {}
    virtual void Visit(CVQualifierSequenceNode& node) {}
    // SimpleType:
    virtual void Visit(CharNode& node) {}
    virtual void Visit(Char8Node& node) {}
    virtual void Visit(Char16Node& node) {}
    virtual void Visit(Char32Node& node) {}
    virtual void Visit(WCharNode& node) {}
    virtual void Visit(BoolNode& node) {}
    virtual void Visit(ShortNode& node) {}
    virtual void Visit(IntNode& node) {}
    virtual void Visit(LongNode& node) {}
    virtual void Visit(SignedNode& node) {}
    virtual void Visit(UnsignedNode& node) {}
    virtual void Visit(FloatNode& node) {}
    virtual void Visit(DoubleNode& node) {}
    virtual void Visit(VoidNode& node) {}
    virtual void Visit(Int64Node& node) {}
    virtual void Visit(Int32Node& node) {}
    virtual void Visit(Int16Node& node) {}
    virtual void Visit(Int8Node& node) {}
    // Statement:
    virtual void Visit(LabeledStatementNode& node) {}
    virtual void Visit(CaseStatementNode& node) {}
    virtual void Visit(DefaultStatementNode& node) {}
    virtual void Visit(CompoundStatementNode& node) {}
    virtual void Visit(IfStatementNode& node) {}
    virtual void Visit(SwitchStatementNode& node) {}
    virtual void Visit(WhileStatementNode& node) {}
    virtual void Visit(DoStatementNode& node) {}
    virtual void Visit(RangeForStatementNode& node) {}
    virtual void Visit(ForRangeDeclarationNode& node) {}
    virtual void Visit(StructuredBindingNode& node) {}
    virtual void Visit(ForStatementNode& node) {}
    virtual void Visit(BreakStatementNode& node) {}
    virtual void Visit(ContinueStatementNode& node) {}
    virtual void Visit(ReturnStatementNode& node) {}
    virtual void Visit(CoReturnStatementNode& node) {}
    virtual void Visit(GotoStatementNode& node) {}
    virtual void Visit(TryStatementNode& node) {}
    virtual void Visit(HandlerSequenceNode& node) {}
    virtual void Visit(HandlerNode& node) {}
    virtual void Visit(ExceptionDeclarationNode& node) {}
    virtual void Visit(ExpressionStatementNode& node) {}
    virtual void Visit(DeclarationStatementNode& node) {}
    virtual void Visit(InitConditionNode& node) {}
    virtual void Visit(SemicolonNode& node) {}
    // Template:
    virtual void Visit(TemplateDeclarationNode& node) {}
    virtual void Visit(TemplateHeadNode& node) {}
    virtual void Visit(TemplateParameterListNode& node) {}
    virtual void Visit(TypeParameterNode& node) {}
    virtual void Visit(TemplateIdNode& node) {}
    virtual void Visit(TypenameNode& node) {}
    virtual void Visit(DeductionGuideNode& node) {}
    virtual void Visit(ExplicitInstantiationNode& node) {}
    virtual void Visit(TemplateNode& node) {}
    virtual void Visit(ExplicitSpecializationNode& node) {}
    // TranslationUnit:
    virtual void Visit(TranslationUnitNode& node) {}
    virtual void Visit(ModuleUnitNode& node) {}
    // Type:
    virtual void Visit(TypeSpecifierSequenceNode& node) {}
    virtual void Visit(TypenameSpecifierNode& node) {}
    virtual void Visit(TypeIdNode& node) {}
    virtual void Visit(DefiningTypeIdNode& node) {}
    virtual void Visit(DefiningTypeSpecifierSequenceNode& node) {}
    virtual void Visit(TrailingReturnTypeNode& node) {}
    virtual void Visit(ElaboratedTypeSpecifierNode& node) {}
    virtual void Visit(DeclTypeSpecifierNode& node) {}
    virtual void Visit(PlaceholderTypeSpecifierNode& node) {}
    // MS:
    virtual void Visit(PragmaNode& node) {}
};

class AST_API DefaultVisitor : public Visitor
{
public:
    // Attribute:
    void Visit(AttributeSpecifierSequenceNode& node);
    void Visit(AttributeSpecifierNode& node);
    void Visit(AttributeUsingPrefixNode& node);
    void Visit(AttributeNode& node);
    void Visit(AttributeScopedTokenNode& node);
    void Visit(AttributeArgumentsNode& node);
    void Visit(BalancedTokenSequenceNode& node);
    void Visit(TokenNode& node);
    void Visit(AlignmentSpecifierNode& node);
    void Visit(LParenNode& node);
    void Visit(RParenNode& node);
    void Visit(LBracketNode& node);
    void Visit(RBracketNode& node);
    void Visit(LBraceNode& node);
    void Visit(RBraceNode& node);
    //  Class:
    void Visit(ClassSpecifierNode& node);
    void Visit(ClassHeadNode& node);
    void Visit(BaseClauseNode& node);
    void Visit(BaseSpecifierListNode& node);
    void Visit(BaseSpecifierNode& node);
    void Visit(BeginAccessGroupNode& node);
    void Visit(MemberDeclarationNode& node);
    void Visit(MemberDeclaratorListNode& node);
    void Visit(ConstructorNode& node);
    void Visit(ConstructorInitializerNode& node);
    void Visit(MemberInitializerListNode& node);
    void Visit(MemberInitializerNode& node);
    void Visit(VirtSpecifierSequenceNode& node);
    void Visit(ClassNode& node);
    void Visit(StructNode& node);
    void Visit(UnionNode& node);
    void Visit(PublicNode& node);
    void Visit(ProtectedNode& node);
    void Visit(PrivateNode& node);
    void Visit(VirtualNode& node);
    void Visit(OverrideNode& node);
    void Visit(FinalNode& node);
    void Visit(PureSpecifierNode& node);
    // Concept:
    void Visit(ConceptDefinitionNode& node);
    void Visit(RequiresExprNode& node);
    void Visit(RequirementBodyNode& node);
    void Visit(SimpleRequirementNode& node);
    void Visit(TypeRequirementNode& node);
    void Visit(CompoundRequirementNode& node);
    void Visit(ReturnTypeRequirementNode& node);
    void Visit(NestedRequirementNode& node);
    void Visit(TypeConstraintNode& node);
    void Visit(RequiresClauseNode& node);
    // Declaration:
    void Visit(DeclarationSequenceNode& node);
    void Visit(SimpleDeclarationNode& node);
    void Visit(AsmDeclarationNode& node);
    void Visit(AsmNode& node);
    void Visit(LinkageSpecificationNode& node);
    void Visit(NamespaceDefinitionNode& node);
    void Visit(NamespaceBodyNode& node);
    void Visit(NamespaceAliasDefinitionNode& node);
    void Visit(UsingDeclarationNode& node);
    void Visit(UsingNode& node);
    void Visit(UsingDeclaratorListNode& node);
    void Visit(UsingEnumDeclarationNode& node);
    void Visit(UsingDirectiveNode& node);
    void Visit(NamespaceNode& node);
    void Visit(StaticAssertDeclarationNode& node);
    void Visit(StaticAssertNode& node);
    void Visit(AliasDeclarationNode& node);
    void Visit(EmptyDeclarationNode& node);
    void Visit(AttributeDeclarationNode& node);
    void Visit(InitDeclaratorListNode& node);
    void Visit(InitDeclaratorNode& node);
    void Visit(TrailingFunctionDeclaratorNode& node);
    void Visit(ParenthesizedDeclaratorNode& node);
    void Visit(AbstractDeclaratorNode& node);
    void Visit(DeclSpecifierSequenceNode& node);
    void Visit(FriendNode& node);
    void Visit(TypedefNode& node);
    void Visit(ConstExprNode& node);
    void Visit(ConstEvalNode& node);
    void Visit(ConstInitNode& node);
    void Visit(CDeclNode& node);
    void Visit(FastCallNode& node);
    void Visit(StdCallNode& node);
    void Visit(ThisCallNode& node);
    void Visit(VectorCallNode& node);
    void Visit(UnalignedNode& node);
    void Visit(DeclSpecNode& node);
    void Visit(InlineNode& node);
    void Visit(StaticNode& node);
    void Visit(ThreadLocalNode& node);
    void Visit(ExternNode& node);
    void Visit(MutableNode& node);
    void Visit(ExplicitNode& node);
    void Visit(ConditionalExplicitNode& node);
    void Visit(QualifiedPtrNode& node);
    void Visit(PtrOperatorNode& node);
    void Visit(PtrDeclaratorNode& node);
    void Visit(PackDeclaratorIdNode& node);
    void Visit(ArrayDeclaratorNode& node);
    void Visit(FunctionDeclaratorNode& node);
    void Visit(PrefixNode& node);
    void Visit(TrailingQualifiersNode& node);
    void Visit(TrailingAttributesNode& node);
    void Visit(NoexceptSpecifierNode& node);
    void Visit(ThrowSpecifierNode& node);
    // Enum:
    void Visit(EnumSpecifierNode& node);
    void Visit(EnumHeadNode& node);
    void Visit(EnumBaseNode& node);
    void Visit(EnumClassNode& node);
    void Visit(EnumStructNode& node);
    void Visit(EnumNode& node);
    void Visit(EnumeratorDefinitionNode& node);
    void Visit(EnumeratorNode& node);
    void Visit(ElaboratedEnumSpecifierNode& node);
    void Visit(OpaqueEnumDeclarationNode& node);
    // Expression:
    void Visit(BinaryExprNode& node);
    void Visit(UnaryExprNode& node);
    void Visit(ExpressionListNode& node);
    void Visit(AssignmentInitNode& node);
    void Visit(YieldExprNode& node);
    void Visit(ThrowExprNode& node);
    void Visit(ConditionalExprNode& node);
    void Visit(CommaNode& node);
    void Visit(AssignNode& node);
    void Visit(PlusAssignNode& node);
    void Visit(MinusAssignNode& node);
    void Visit(MulAssignNode& node);
    void Visit(DivAssignNode& node);
    void Visit(ModAssignNode& node);
    void Visit(XorAssignNode& node);
    void Visit(AndAssignNode& node);
    void Visit(OrAssignNode& node);
    void Visit(ShiftLeftAssignNode& node);
    void Visit(ShiftRightAssignNode& node);
    void Visit(QuestNode& node);
    void Visit(ColonNode& node);
    void Visit(DisjunctionNode& node);
    void Visit(ConjunctionNode& node);
    void Visit(InclusiveOrNode& node);
    void Visit(ExclusiveOrNode& node);
    void Visit(AndNode& node);
    void Visit(EqualNode& node);
    void Visit(NotEqualNode& node);
    void Visit(LessNode& node);
    void Visit(GreaterNode& node);
    void Visit(LessOrEqualNode& node);
    void Visit(GreaterOrEqualNode& node);
    void Visit(CompareNode& node);
    void Visit(ShiftLeftNode& node);
    void Visit(ShiftRightNode& node);
    void Visit(PlusNode& node);
    void Visit(MinusNode& node);
    void Visit(MulNode& node);
    void Visit(DivNode& node);
    void Visit(ModNode& node);
    void Visit(DotStarNode& node);
    void Visit(ArrowStarNode& node);
    void Visit(CastExprNode& node);
    void Visit(DerefNode& node);
    void Visit(AddrOfNode& node);
    void Visit(NotNode& node);
    void Visit(ComplementNode& node);
    void Visit(PrefixIncNode& node);
    void Visit(PrefixDecNode& node);
    void Visit(AwaitExprNode& node);
    void Visit(SizeOfTypeExprNode& node);
    void Visit(SizeOfPackExprNode& node);
    void Visit(SizeOfUnaryExprNode& node);
    void Visit(AlignOfExprNode& node);
    void Visit(NoexceptExprNode& node);
    void Visit(NewExprNode& node);
    void Visit(NewPlacementNode& node);
    void Visit(ParenNewTypeIdNode& node);
    void Visit(NewTypeIdNode& node);
    void Visit(ArrayDeletePtrNode& node);
    void Visit(DeletePtrNode& node);
    void Visit(SubscriptExprNode& node);
    void Visit(InvokeExprNode& node);
    void Visit(PairNode& node);
    void Visit(ArrowNode& node);
    void Visit(MemberExprNode& node);
    void Visit(PostfixIncExprNode& node);
    void Visit(PostfixDecExprNode& node);
    void Visit(TypeIdExprNode& node);
    void Visit(DynamicCastNode& node);
    void Visit(StaticCastNode& node);
    void Visit(ReinterpretCastNode& node);
    void Visit(ConstCastNode& node);
    void Visit(CppCastExprNode& node);
    void Visit(ThisNode& node);
    void Visit(ParenthesizedExprNode& node);
    void Visit(FoldExprNode& node);
    void Visit(NewDeclaratorNode& node);
    void Visit(ArrayNewDeclaratorNode& node);
    void Visit(NewInitializerNode& node);
    void Visit(BracedInitListNode& node);
    void Visit(DesignatedInitializerNode& node);
    void Visit(DesignatorNode& node);
    void Visit(EllipsisNode& node);
    // Function:
    void Visit(FunctionDefinitionNode& node);
    void Visit(FunctionBodyNode& node);
    void Visit(DefaultNode& node);
    void Visit(DeleteNode& node);
    void Visit(DefaultedOrDeletedFunctionNode& node);
    void Visit(FunctionDeclarationNode& node);
    void Visit(OperatorNode& node);
    void Visit(NewArrayOpNode& node);
    void Visit(NewOpNode& node);
    void Visit(DeleteArrayOpNode& node);
    void Visit(DeleteOpNode& node);
    void Visit(CoAwaitOpNode& node);
    void Visit(InvokeOpNode& node);
    void Visit(SubscriptOpNode& node);
    void Visit(OperatorFunctionIdNode& node);
    void Visit(ConversionFunctionIdNode& node);
    void Visit(ConversionTypeIdNode& node);
    void Visit(ConversionDeclaratorNode& node);
    void Visit(DestructorIdNode& node);
    void Visit(ParameterNode& node);
    void Visit(ParameterListNode& node);
    void Visit(NoexceptNode& node);
    void Visit(FunctionTryBlockNode& node);
    // Identifier:
    void Visit(IdentifierNode& node);
    void Visit(UnnamedNode& node);
    void Visit(ColonColonNode& node);
    void Visit(NestedNameSpecifierNode& node);
    void Visit(QualifiedIdNode& node);
    void Visit(IdentifierListNode& node);
    void Visit(QualifiedModuleIdNode& node);
    void Visit(DotNode& node);
    // Lambda:
    void Visit(LambdaExpressionNode& node);
    void Visit(LambdaIntroducerNode& node);
    void Visit(LambdaCaptureNode& node);
    void Visit(DefaultRefCaptureNode& node);
    void Visit(DefaultCopyCaptureNode& node);
    void Visit(ByRefCaptureNode& node);
    void Visit(SimpleCaptureNode& node);
    void Visit(CurrentObjectCopyCapture& node);
    void Visit(CurrentObjectByRefCapture& node);
    void Visit(InitCaptureNode& node);
    void Visit(LambdaDeclaratorNode& node);
    void Visit(LambdaSpecifiersNode& node);
    void Visit(LambdaTemplateParamsNode& node);
    // Literal:
    void Visit(IntegerLiteralNode& node);
    void Visit(FloatingLiteralNode& node);
    void Visit(CharacterLiteralNode& node);
    void Visit(StringLiteralNode& node);
    void Visit(RawStringLiteralNode& node);
    void Visit(BooleanLiteralNode& node);
    void Visit(NullPtrLiteralNode& node);
    void Visit(UserDefinedLiteraNode& node);
    void Visit(LiteralOperatorIdNode& node);
    // Module:
    void Visit(ModuleDeclarationNode& node);
    void Visit(ExportDeclarationNode& node);
    void Visit(ExportNode& node);
    void Visit(ImportNode& node);
    void Visit(ImportDeclarationNode& node);
    void Visit(ModulePartitionNode& node);
    void Visit(ModuleNode& node);
    void Visit(GlobalModuleFragmentNode& node);
    void Visit(PrivateModuleFragmentNode& node);
    void Visit(AngleHeaderName& node);
    void Visit(QuoteHeaderName& node);
    // Qualifier:
    void Visit(ConstNode& node);
    void Visit(VolatileNode& node);
    void Visit(LvalueRefNode& node);
    void Visit(RvalueRefNode& node);
    void Visit(PtrNode& node);
    void Visit(CVQualifierSequenceNode& node);
    // SimpleType:
    void Visit(CharNode& node);
    void Visit(Char8Node& node);
    void Visit(Char16Node& node);
    void Visit(Char32Node& node);
    void Visit(WCharNode& node);
    void Visit(BoolNode& node);
    void Visit(ShortNode& node);
    void Visit(IntNode& node);
    void Visit(LongNode& node);
    void Visit(SignedNode& node);
    void Visit(UnsignedNode& node);
    void Visit(FloatNode& node);
    void Visit(DoubleNode& node);
    void Visit(VoidNode& node);
    void Visit(Int64Node& node);
    void Visit(Int32Node& node);
    void Visit(Int16Node& node);
    void Visit(Int8Node& node);
    // Statement:
    void Visit(LabeledStatementNode& node);
    void Visit(CaseStatementNode& node);
    void Visit(DefaultStatementNode& node);
    void Visit(CompoundStatementNode& node);
    void Visit(IfStatementNode& node);
    void Visit(SwitchStatementNode& node);
    void Visit(WhileStatementNode& node);
    void Visit(DoStatementNode& node);
    void Visit(RangeForStatementNode& node);
    void Visit(ForRangeDeclarationNode& node);
    void Visit(StructuredBindingNode& node);
    void Visit(ForStatementNode& node);
    void Visit(BreakStatementNode& node);
    void Visit(ContinueStatementNode& node);
    void Visit(ReturnStatementNode& node);
    void Visit(CoReturnStatementNode& node);
    void Visit(GotoStatementNode& node);
    void Visit(TryStatementNode& node);
    void Visit(HandlerSequenceNode& node);
    void Visit(HandlerNode& node);
    void Visit(ExceptionDeclarationNode& node);
    void Visit(ExpressionStatementNode& node);
    void Visit(DeclarationStatementNode& node);
    void Visit(InitConditionNode& node);
    void Visit(SemicolonNode& node);
    // Template:
    void Visit(TemplateDeclarationNode& node);
    void Visit(TemplateHeadNode& node);
    void Visit(TemplateParameterListNode& node);
    void Visit(TypeParameterNode& node);
    void Visit(TemplateIdNode& node);
    void Visit(TypenameNode& node);
    void Visit(DeductionGuideNode& node);
    void Visit(ExplicitInstantiationNode& node);
    void Visit(TemplateNode& node);
    void Visit(ExplicitSpecializationNode& node);
    // TranslationUnit:
    void Visit(TranslationUnitNode& node);
    void Visit(ModuleUnitNode& node);
    // Type:
    void Visit(TypeSpecifierSequenceNode& node);
    void Visit(TypenameSpecifierNode& node);
    void Visit(TypeIdNode& node);
    void Visit(DefiningTypeIdNode& node);
    void Visit(DefiningTypeSpecifierSequenceNode& node);
    void Visit(TrailingReturnTypeNode& node);
    void Visit(ElaboratedTypeSpecifierNode& node);
    void Visit(DeclTypeSpecifierNode& node);
    void Visit(PlaceholderTypeSpecifierNode& node);
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_VISITOR_INCLUDED
