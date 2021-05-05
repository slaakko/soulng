// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Attribute.hpp>
#include <sngcpp20/ast/Class.hpp>
#include <sngcpp20/ast/Concept.hpp>
#include <sngcpp20/ast/Declaration.hpp>
#include <sngcpp20/ast/Enum.hpp>
#include <sngcpp20/ast/Expression.hpp>
#include <sngcpp20/ast/Function.hpp>
#include <sngcpp20/ast/Identifier.hpp>
#include <sngcpp20/ast/Lambda.hpp>
#include <sngcpp20/ast/Literal.hpp>
#include <sngcpp20/ast/Module.hpp>
#include <sngcpp20/ast/Qualifier.hpp>
#include <sngcpp20/ast/SimpleType.hpp>
#include <sngcpp20/ast/Statement.hpp>
#include <sngcpp20/ast/Template.hpp>
#include <sngcpp20/ast/TranslationUnit.hpp>
#include <sngcpp20/ast/Type.hpp>

namespace sngcpp::ast {

Visitor::~Visitor()
{
}

void Visitor::VisitSingleNode(Node& node)
{
    BeginVisit(node);
    EndVisit(node);
}

void Visitor::VisitUnaryNode(UnaryNode& unaryNode)
{
    BeginVisit(unaryNode);
    unaryNode.Child()->Accept(*this);
    EndVisit(unaryNode);
}

void Visitor::VisitBinaryNode(BinaryNode& binaryNode)
{
    BeginVisit(binaryNode);
    binaryNode.Left()->Accept(*this);
    binaryNode.Right()->Accept(*this);
    EndVisit(binaryNode);
}

void Visitor::VisitSequence(SequenceNode& sequenceNode)
{
    BeginVisit(sequenceNode);
    VisitSequenceContent(sequenceNode);
    EndVisit(sequenceNode);
}

void Visitor::VisitSequenceContent(SequenceNode& sequenceNode)
{
    int n = sequenceNode.Nodes().Count();
    for (int i = 0; i < n; ++i)
    {
        Node* node = sequenceNode.Nodes()[i];
        node->Accept(*this);
    }
}

void Visitor::VisitList(ListNode& listNode)
{
    BeginVisit(listNode);
    VisitListContent(listNode);
    EndVisit(listNode);
}

void Visitor::VisitListContent(ListNode& listNode)
{
    int n = listNode.Nodes().Count();
    for (int i = 0; i < n; ++i)
    {
        Node* node = listNode.Nodes()[i];
        node->Accept(*this);
    }
}

// DefaultVisitor:

// Attribute:

void DefaultVisitor::Visit(AttributeSpecifierSequenceNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(AttributeSpecifierNode& node)
{
    BeginVisit(node);
    VisitOperator("[", node.LBracketPos1());
    VisitOperator("[", node.LBracketPos2());
    if (node.UsingPrefix())
    {
        node.UsingPrefix()->Accept(*this);
    }
    VisitListContent(node);
    VisitOperator("]", node.RBracketPos1());
    VisitOperator("]", node.RBracketPos2());
    EndVisit(node);
}

void DefaultVisitor::Visit(AttributeUsingPrefixNode& node)
{
    BeginVisit(node);
    VisitKeyword("using", node.GetSourcePos());
    node.Child()->Accept(*this);
    VisitOperator(":", node.ColonPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(AttributeNode& node)
{
    BeginVisit(node);
    node.AttributeToken()->Accept(*this);
    if (node.AttributeArgs())
    {
        node.AttributeArgs()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(AttributeScopedTokenNode& node)
{
    BeginVisit(node);
    node.Ns()->Accept(*this);
    node.ColonColon()->Accept(*this);
    node.Identifier()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(AttributeArgumentsNode& node)
{
    BeginVisit(node);
    VisitOperator("(", node.LParenPos());
    if (node.BalancedTokenSequence())
    {
        node.BalancedTokenSequence()->Accept(*this);
    }
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(BalancedTokenSequenceNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(TokenNode& node)
{
    BeginVisit(node);
    VisitToken(node.Str(), node.GetSourcePos());
    EndVisit(node);
}

void DefaultVisitor::Visit(AlignmentSpecifierNode& node)
{
    BeginVisit(node);
    VisitKeyword("alignas", node.GetSourcePos());
    VisitOperator("(", node.LParenPos());
    node.Alignment()->Accept(*this);
    if (node.Ellipses())
    {
        node.Ellipses()->Accept(*this);
    }
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(LParenNode& node)
{
    VisitOperator("(", node.GetSourcePos());
}

void DefaultVisitor::Visit(RParenNode& node)
{
    VisitOperator(")", node.GetSourcePos());

}

void DefaultVisitor::Visit(LBracketNode& node)
{
    VisitOperator("[", node.GetSourcePos());
}

void DefaultVisitor::Visit(RBracketNode& node)
{
    VisitOperator("]", node.GetSourcePos());
}

void DefaultVisitor::Visit(LBraceNode& node)
{
    VisitOperator("{", node.GetSourcePos());
}

void DefaultVisitor::Visit(RBraceNode& node)
{
    VisitOperator("}", node.GetSourcePos());
}

//  Class:

void DefaultVisitor::Visit(ClassSpecifierNode& node)
{
    BeginVisit(node);
    node.ClassHead()->Accept(*this);
    VisitOperator("{", node.LBracePos());
    VisitSequenceContent(node);
    VisitOperator("}", node.RBracePos());
    EndVisit(node);
}

void DefaultVisitor::Visit(ClassHeadNode& node)
{
    BeginVisit(node);
    node.ClassKey()->Accept(*this);
    if (node.Attibutes())
    {
        node.Attibutes()->Accept(*this);
    }
    node.ClassHeadName()->Accept(*this);
    if (node.ClassVirtSpecifier())
    {
        node.ClassVirtSpecifier()->Accept(*this);
    }
    if (node.BaseClause())
    {
        node.BaseClause()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(BaseClauseNode& node)
{
    BeginVisit(node);
    VisitOperator(":", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(BaseSpecifierListNode& node)
{
    VisitList(node);
}

void DefaultVisitor::Visit(BaseSpecifierNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    if (node.VirtualFirst())
    {
        if (node.VirtualSpecifier())
        {
            node.VirtualSpecifier()->Accept(*this);
        }
        if (node.AccessSpecifier())
        {
            node.AccessSpecifier()->Accept(*this);
        }
    }
    else
    {
        if (node.AccessSpecifier())
        {
            node.AccessSpecifier()->Accept(*this);
        }
        if (node.VirtualSpecifier())
        {
            node.VirtualSpecifier()->Accept(*this);
        }
    }
    node.ClassOrDeclType()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(BeginAccessGroupNode& node)
{
    BeginVisit(node);
    node.Child()->Accept(*this);
    VisitOperator(":", node.ColonPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(MemberDeclarationNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    if (node.DeclSpecifiers())
    {
        node.DeclSpecifiers()->Accept(*this);
    }
    if (node.MemberDeclarators())
    {
        node.MemberDeclarators()->Accept(*this);
    }
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(MemberDeclaratorListNode& node)
{
    VisitList(node);
}

void DefaultVisitor::Visit(ConstructorNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(ConstructorInitializerNode& node)
{
    BeginVisit(node);
    VisitOperator(":", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(MemberInitializerListNode& node)
{
    VisitList(node);
}

void DefaultVisitor::Visit(MemberInitializerNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(VirtSpecifierSequenceNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(ClassNode& node)
{
    VisitKeyword("class", node.GetSourcePos());
}

void DefaultVisitor::Visit(StructNode& node)
{
    VisitKeyword("struct", node.GetSourcePos());
}

void DefaultVisitor::Visit(UnionNode& node)
{
    VisitKeyword("union", node.GetSourcePos());
}

void DefaultVisitor::Visit(PublicNode& node)
{
    VisitKeyword("public", node.GetSourcePos());
}

void DefaultVisitor::Visit(ProtectedNode& node)
{
    VisitKeyword("protected", node.GetSourcePos());
}

void DefaultVisitor::Visit(PrivateNode& node)
{
    VisitKeyword("private", node.GetSourcePos());
}

void DefaultVisitor::Visit(VirtualNode& node)
{
    VisitKeyword("virtual", node.GetSourcePos());
}

void DefaultVisitor::Visit(OverrideNode& node)
{
    VisitKeyword("override", node.GetSourcePos());
}

void DefaultVisitor::Visit(FinalNode& node)
{
    VisitKeyword("final", node.GetSourcePos());
}

void DefaultVisitor::Visit(PureSpecifierNode& node)
{
    BeginVisit(node);
    VisitOperator("=", node.GetSourcePos());
    VisitOperator("0", node.ZeroPos());
    EndVisit(node);
}

// Concept:

void DefaultVisitor::Visit(ConceptDefinitioNode& node)
{
    BeginVisit(node);
    VisitKeyword("concept", node.GetSourcePos());
    node.ConceptName()->Accept(*this);
    node.Assign()->Accept(*this);
    node.ConstraintExpression()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(RequiresExprNode& node)
{
    BeginVisit(node);
    VisitKeyword("requires", node.GetSourcePos());
    if (node.Params())
    {
        node.Params()->Accept(*this);
    }
    node.Body()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(RequirementBodyNode& node)
{
    BeginVisit(node);
    VisitOperator("{", node.LBracePos());
    VisitSequence(node);
    VisitOperator("}", node.RBracePos());
}

void DefaultVisitor::Visit(SimpleRequirementNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(TypeRequirementNode& node)
{
    BeginVisit(node);
    VisitKeyword("typename", node.GetSourcePos());
    if (node.NestedNameSpecifier())
    {
        node.NestedNameSpecifier()->Accept(*this);
    }
    node.TypeName()->Accept(*this);
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(CompoundRequirementNode& node)
{
    BeginVisit(node);
    VisitOperator("{", node.LBracePos());
    node.Expr()->Accept(*this);
    VisitOperator("}", node.RBracePos());
    if (node.NoExcept())
    {
        node.NoExcept()->Accept(*this);
    }
    if (node.ReturnTypeRequirement())
    {
        node.ReturnTypeRequirement()->Accept(*this);
    }
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ReturnTypeRequirementNode& node)
{
    BeginVisit(node);
    VisitOperator("->", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(NestedRequirementNode& node)
{
    BeginVisit(node);
    VisitKeyword("requires", node.GetSourcePos());
    node.Left()->Accept(*this);
    node.Right()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(TypeConstraintNode& node)
{
    BeginVisit(node);
    node.ConceptName()->Accept(*this);
    if (node.HasTemplateArgumentList())
    {
        VisitOperator("<", node.LAnglePos());
        VisitListContent(node);
        VisitOperator(">", node.RAnglePos());
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(RequiresClauseNode& node)
{
    BeginVisit(node);
    VisitKeyword("requires", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

// Declaration:

void DefaultVisitor::Visit(DeclarationSequenceNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(SimpleDeclarationNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.DeclarationSpecifiers()->Accept(*this);
    if (node.InitDeclaratorList())
    {
        node.InitDeclaratorList()->Accept(*this);
    }
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(AsmDeclarationNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.Asm()->Accept(*this);
    VisitOperator("(", node.LParenPos());
    node.AsmText()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(AsmNode& node)
{
    VisitKeyword("asm", node.GetSourcePos());
}

void DefaultVisitor::Visit(LinkageSpecificationNode& node)
{
    BeginVisit(node);
    node.Extern()->Accept(*this);
    node.Linkage()->Accept(*this);
    if (node.LBracePos().IsValid())
    {
        VisitOperator("{", node.LBracePos());
        if (node.Declarations())
        {
            node.Declarations()->Accept(*this);
        }
        VisitOperator("}", node.RBracePos());
    }
    else
    {
        node.Declarations()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(NamespaceDefinitionNode& node)
{
    BeginVisit(node);
    if (node.Inline())
    {
        node.Inline()->Accept(*this);
    }
    node.Namespace()->Accept(*this);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    if (node.NamespaceName())
    {
        node.NamespaceName()->Accept(*this);
    }
    VisitOperator("{", node.LBracePos());
    node.NamespaceBody()->Accept(*this);
    VisitOperator("}", node.RBracePos());
    EndVisit(node);
}

void DefaultVisitor::Visit(NamespaceBodyNode& node)
{
    if (node.Declarations())
    {
        node.Declarations()->Accept(*this);
    }
}

void DefaultVisitor::Visit(NamespaceAliasDefinitionNode& node)
{
    BeginVisit(node);
    VisitKeyword("namespace", node.GetSourcePos());
    node.Id()->Accept(*this);
    node.Assign()->Accept(*this);
    node.QualifiedNamespaceSpecifier()->Accept(*this);
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(UsingDeclarationNode& node)
{
    BeginVisit(node);
    node.Using()->Accept(*this);
    node.Declarators()->Accept(*this);
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(UsingNode& node)
{
    VisitKeyword("using", node.GetSourcePos());
}

void DefaultVisitor::Visit(UsingDeclaratorListNode& node)
{
    VisitList(node);
}

void DefaultVisitor::Visit(UsingEnumDeclarationNode& node)
{
    BeginVisit(node);
    node.Using()->Accept(*this);
    node.ElaboratedEnumSpecifier()->Accept(*this);
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(UsingDirectiveNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.Using()->Accept(*this);
    node.Namespace()->Accept(*this);
    node.Id()->Accept(*this);
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(NamespaceNode& node)
{
    VisitKeyword("namespace", node.GetSourcePos());
}

void DefaultVisitor::Visit(StaticAssertDeclarationNode& node)
{
    BeginVisit(node);
    node.StaticAssert()->Accept(*this);
    VisitOperator("(", node.LParenPos());
    node.ConstantExpr()->Accept(*this);
    if (node.Comma())
    {
        node.Comma()->Accept(*this);
        node.StringLiteral()->Accept(*this);
    }
    VisitOperator(")", node.RParenPos());
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(StaticAssertNode& node)
{
    VisitKeyword("static_assert", node.GetSourcePos());
}

void DefaultVisitor::Visit(AliasDeclarationNode& node)
{
    BeginVisit(node);
    node.Using()->Accept(*this);
    node.Identifier()->Accept(*this);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.Assign()->Accept(*this);
    node.DefiningTypeId()->Accept(*this);
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(EmptyDeclarationNode& node)
{
    VisitOperator(";", node.GetSourcePos());
}

void DefaultVisitor::Visit(AttributeDeclarationNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(InitDeclaratorListNode& node)
{
    VisitList(node);
}

void DefaultVisitor::Visit(InitDeclaratorNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(TrailingInvokeDeclaratorNode& node)
{
    BeginVisit(node);
    node.Declarator()->Accept(*this);
    node.Parameters()->Accept(*this);
    node.TrailingReturnType()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ParenthesizedDeclaratorNode& node)
{
    BeginVisit(node);
    VisitOperator("(", node.LParenPos());
    node.Declarator()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(AbstractDeclaratorNode& node)
{
}

void DefaultVisitor::Visit(DeclSpecifierSequenceNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(FriendNode& node)
{
    VisitKeyword("friend", node.GetSourcePos());
}

void DefaultVisitor::Visit(TypedefNode& node)
{
    VisitKeyword("typedef", node.GetSourcePos());
}

void DefaultVisitor::Visit(ConstExprNode& node)
{
    VisitKeyword("constexpr", node.GetSourcePos());
}

void DefaultVisitor::Visit(ConstEvalNode& node)
{
    VisitKeyword("consteval", node.GetSourcePos());
}

void DefaultVisitor::Visit(ConstInitNode& node)
{
    VisitKeyword("constinit", node.GetSourcePos());
}

void DefaultVisitor::Visit(InlineNode& node)
{
    VisitKeyword("inline", node.GetSourcePos());
}

void DefaultVisitor::Visit(StaticNode& node)
{
    VisitKeyword("static", node.GetSourcePos());
}

void DefaultVisitor::Visit(ThreadLocalNode& node)
{
    VisitKeyword("thread_local", node.GetSourcePos());
}

void DefaultVisitor::Visit(ExternNode& node)
{
    VisitKeyword("extern", node.GetSourcePos());
}

void DefaultVisitor::Visit(MutableNode& node)
{
    VisitKeyword("mutable", node.GetSourcePos());
}

void DefaultVisitor::Visit(ExplicitNode& node)
{
    VisitKeyword("explicit", node.GetSourcePos());
}

void DefaultVisitor::Visit(ConditionalExplicitNode& node)
{
    BeginVisit(node);
    VisitKeyword("explicit", node.GetSourcePos());
    VisitOperator("(", node.LParenPos());
    node.Condition()->Accept(*this);
    VisitOperator(")", node.RParenPos());
}

void DefaultVisitor::Visit(QualifiedPtrNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(PtrOperatorNode& node)
{
    VisitUnaryNode(node);
}

void DefaultVisitor::Visit(PtrDeclaratorNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(PackDeclaratorIdNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(SubscriptDeclaratorNode& node)
{
    BeginVisit(node);
    node.Child()->Accept(*this);
    VisitOperator("[", node.LBracketPos());
    if (node.Index())
    {
        node.Index()->Accept(*this);
    }
    VisitOperator("]", node.RBracketPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(InvokeDeclaratorNode& node)
{
    VisitUnaryNode(node);
}

void DefaultVisitor::Visit(PrefixNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(TrailingQualifiersNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(TrailingAttributesNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(NoexceptSpecifierNode& node)
{
    BeginVisit(node);
    if (node.ConstantExpr())
    {
        VisitOperator("(", node.LParenPos());
        node.ConstantExpr()->Accept(*this);
        VisitOperator("}", node.RParenPos());
    }
    EndVisit(node);
}

// Enum:

void DefaultVisitor::Visit(EnumSpecifierNode& node)
{
    BeginVisit(node);
    node.EnumHead()->Accept(*this);
    VisitOperator("{", node.LBracePos());
    VisitListContent(node);
    VisitOperator("}", node.RBracePos());
    EndVisit(node);
}

void DefaultVisitor::Visit(EnumHeadNode& node)
{
    BeginVisit(node);
    node.EnumKey()->Accept(*this);
    node.EnumHeadName()->Accept(*this);
    if (node.EnumBase())
    {
        node.EnumBase()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(EnumBaseNode& node)
{
    BeginVisit(node);
    VisitOperator(":", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(EnumClassNode& node)
{
    BeginVisit(node);
    VisitKeyword("enum", node.GetSourcePos());
    VisitKeyword("class", node.ClassPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(EnumStructNode& node)
{
    BeginVisit(node);
    VisitKeyword("enum", node.GetSourcePos());
    VisitKeyword("struct", node.StructPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(EnumNode& node)
{
    VisitKeyword("enum", node.GetSourcePos());
}

void DefaultVisitor::Visit(EnumeratorDefinitionNode& node)
{
    BeginVisit(node);
    node.Enumerator()->Accept(*this);
    VisitOperator("=", node.AssignPos());
    if (node.Value())
    {
        node.Value()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(EnumeratorNode& node)
{
    BeginVisit(node);
    node.Identifier()->Accept(*this);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(ElaboratedEnumSpecifierNode& node)
{
    BeginVisit(node);
    VisitKeyword("enum", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(OpaqueEnumDeclarationNode& node)
{
    BeginVisit(node);
    node.EnumKey()->Accept(*this);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.EnumHeadName()->Accept(*this);
    if (node.EnumBase())
    {
        node.EnumBase()->Accept(*this);
    }
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

// Expression:

void DefaultVisitor::Visit(BinaryExprNode& node)
{
    BeginVisit(node);
    node.Left()->Accept(*this);
    node.Op()->Accept(*this);
    node.Right()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(UnaryExprNode& node)
{
    BeginVisit(node);
    node.Op()->Accept(*this);
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ExpressionListNode& node)
{
    BeginVisit(node);
    VisitOperator("(", node.LParenPos());
    VisitListContent(node);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(AssignmentInitNode& node)
{
    BeginVisit(node);
    VisitOperator("=", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(YieldExprNode& node)
{
    BeginVisit(node);
    VisitKeyword("co_yield", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ThrowExprNode& node)
{
    BeginVisit(node);
    VisitKeyword("throw", node.GetSourcePos());
    if (node.Exception())
    {
        node.Exception()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(ConditionalExprNode& node)
{
    BeginVisit(node);
    node.Condition()->Accept(*this);
    node.Quest()->Accept(*this);
    node.ThenExpr()->Accept(*this);
    node.Colon()->Accept(*this);
    node.ElseExpr()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(CommaNode& node)
{
    VisitOperator(",", node.GetSourcePos());
}

void DefaultVisitor::Visit(AssignNode& node)
{
    VisitOperator("=", node.GetSourcePos());
}

void DefaultVisitor::Visit(PlusAssignNode& node)
{
    VisitOperator("+=", node.GetSourcePos());
}

void DefaultVisitor::Visit(MinusAssignNode& node)
{
    VisitOperator("-=", node.GetSourcePos());
}

void DefaultVisitor::Visit(MulAssignNode& node)
{
    VisitOperator("*=", node.GetSourcePos());
}

void DefaultVisitor::Visit(DivAssignNode& node)
{
    VisitOperator("/=", node.GetSourcePos());
}

void DefaultVisitor::Visit(ModAssignNode& node)
{
    VisitOperator("%=", node.GetSourcePos());
}

void DefaultVisitor::Visit(XorAssignNode& node)
{
    VisitOperator("^=", node.GetSourcePos());
}

void DefaultVisitor::Visit(AndAssignNode& node)
{
    VisitOperator("&=", node.GetSourcePos());
}

void DefaultVisitor::Visit(OrAssignNode& node)
{
    VisitOperator("|=", node.GetSourcePos());
}

void DefaultVisitor::Visit(ShiftLeftAssignNode& node)
{
    VisitOperator("<<=", node.GetSourcePos());
}

void DefaultVisitor::Visit(ShiftRightAssignNode& node)
{
    VisitOperator(">>=", node.GetSourcePos());
}

void DefaultVisitor::Visit(QuestNode& node)
{
    VisitOperator("?", node.GetSourcePos());
}

void DefaultVisitor::Visit(ColonNode& node)
{
    VisitOperator(":", node.GetSourcePos());
}

void DefaultVisitor::Visit(DisjunctionNode& node)
{
    VisitOperator("||", node.GetSourcePos());
}

void DefaultVisitor::Visit(ConjunctionNode& node)
{
    VisitOperator("&&", node.GetSourcePos());
}

void DefaultVisitor::Visit(InclusiveOrNode& node)
{
    VisitOperator("|", node.GetSourcePos());
}

void DefaultVisitor::Visit(ExclusiveOrNode& node)
{
    VisitOperator("^", node.GetSourcePos());
}

void DefaultVisitor::Visit(AndNode& node)
{
    VisitOperator("&", node.GetSourcePos());
}

void DefaultVisitor::Visit(EqualNode& node)
{
    VisitOperator("==", node.GetSourcePos());
}

void DefaultVisitor::Visit(NotEqualNode& node)
{
    VisitOperator("!=", node.GetSourcePos());
}

void DefaultVisitor::Visit(LessNode& node)
{
    VisitOperator("<", node.GetSourcePos());
}

void DefaultVisitor::Visit(GreaterNode& node)
{
    VisitOperator(">", node.GetSourcePos());
}

void DefaultVisitor::Visit(LessOrEqualNode& node)
{
    VisitOperator("<=", node.GetSourcePos());
}

void DefaultVisitor::Visit(GreaterOrEqualNode& node)
{
    VisitOperator(">=", node.GetSourcePos());
}

void DefaultVisitor::Visit(CompareNode& node)
{
    VisitOperator("<=>", node.GetSourcePos());
}

void DefaultVisitor::Visit(ShiftLeftNode& node)
{
    VisitOperator("<<", node.GetSourcePos());
}

void DefaultVisitor::Visit(ShiftRightNode& node)
{
    VisitOperator(">>", node.GetSourcePos());
}

void DefaultVisitor::Visit(PlusNode& node)
{
    VisitOperator("+", node.GetSourcePos());
}

void DefaultVisitor::Visit(MinusNode& node)
{
    VisitOperator("-", node.GetSourcePos());
}

void DefaultVisitor::Visit(MulNode& node)
{
    VisitOperator("*", node.GetSourcePos());
}

void DefaultVisitor::Visit(DivNode& node)
{
    VisitOperator("/", node.GetSourcePos());
}

void DefaultVisitor::Visit(ModNode& node)
{
    VisitOperator("%", node.GetSourcePos());
}

void DefaultVisitor::Visit(DotStarNode& node)
{
    VisitOperator(".*", node.GetSourcePos());
}

void DefaultVisitor::Visit(ArrowStarNode& node)
{
    VisitOperator("->*", node.GetSourcePos());
}

void DefaultVisitor::Visit(CastExprNode& node)
{
    BeginVisit(node);
    VisitOperator("(", node.LParenPos());
    node.TypeId()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(DerefNode& node)
{
    VisitOperator("*", node.GetSourcePos());
}

void DefaultVisitor::Visit(AddrOfNode& node)
{
    VisitOperator("&", node.GetSourcePos());
}

void DefaultVisitor::Visit(NotNode& node)
{
    VisitOperator("!", node.GetSourcePos());
}

void DefaultVisitor::Visit(ComplementNode& node)
{
    VisitOperator("~", node.GetSourcePos());
}

void DefaultVisitor::Visit(PrefixIncNode& node)
{
    VisitOperator("++", node.GetSourcePos());
}

void DefaultVisitor::Visit(PrefixDecNode& node)
{
    VisitOperator("--", node.GetSourcePos());
}

void DefaultVisitor::Visit(AwaitExprNode& node)
{
    BeginVisit(node);
    VisitKeyword("co_await", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(SizeOfTypeExprNode& node)
{
    BeginVisit(node);
    VisitKeyword("sizeof", node.GetSourcePos());
    VisitOperator("(", node.LParenPos());
    node.Child()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(SizeOfPackExprNode& node)
{
    BeginVisit(node);
    VisitKeyword("sizeof", node.GetSourcePos());
    VisitOperator("...", node.EllipsesPos());
    VisitOperator("(", node.LParenPos());
    node.Child()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(SizeOfUnaryExprNode& node)
{
    BeginVisit(node);
    VisitKeyword("sizeof", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(AlignOfExprNode& node)
{
    BeginVisit(node);
    VisitKeyword("alignof", node.GetSourcePos());
    VisitOperator("(", node.LParenPos());
    node.Child()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(NoexceptExprNode& node)
{
    BeginVisit(node);
    VisitKeyword("noexcept", node.GetSourcePos());
    VisitOperator("(", node.LParenPos());
    node.Child()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(NewExprNode& node)
{
    BeginVisit(node);
    if (node.ColonColonHead())
    {
        node.ColonColonHead()->Accept(*this);
    }
    VisitKeyword("new", node.NewPos());
    if (node.Placement())
    {
        node.Placement()->Accept(*this);
    }
    node.Child()->Accept(*this);
    if (node.Initializer())
    {
        node.Initializer()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(NewPlacementNode& node)
{
    BeginVisit(node);
    VisitOperator("(", node.LParenPos());
    VisitListContent(node);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(ParenNewTypeIdNode& node)
{
    BeginVisit(node);
    VisitOperator("(", node.LParenPos());
    node.Child()->Accept(*this);
    VisitOperator(")", node.LParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(NewTypeIdNode& node)
{
    BeginVisit(node);
    node.TypeSpecifierSeq()->Accept(*this);
    if (node.NewDeclarator())
    {
        node.NewDeclarator()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(ArrayDeletePtrNode& node)
{
    BeginVisit(node);
    if (node.ColonColonHead())
    {
        node.ColonColonHead()->Accept(*this);
    }
    VisitKeyword("delete", node.DeletePos());
    VisitOperator("[", node.LBracketPos());
    VisitOperator("]", node.RBracketPos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(DeletePtrNode& node)
{
    BeginVisit(node);
    if (node.ColonColonHead())
    {
        node.ColonColonHead()->Accept(*this);
    }
    VisitKeyword("delete", node.DeletePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(SubscriptExprNode& node)
{
    BeginVisit(node);
    node.Child()->Accept(*this);
    VisitOperator("[", node.LBracketPos());
    node.Index()->Accept(*this);
    VisitOperator("]", node.RBracketPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(InvokeExprNode& node)
{
    BeginVisit(node);
    node.Subject()->Accept(*this);
    VisitOperator("(", node.LParenPos());
    VisitListContent(node);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(PairNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(ArrowNode& node)
{
    VisitOperator("->", node.GetSourcePos());
}

void DefaultVisitor::Visit(MemberExprNode& node)
{
    BeginVisit(node);
    node.Child()->Accept(*this);
    node.Op()->Accept(*this);
    node.Id()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(PostfixIncExprNode& node)
{
    BeginVisit(node);
    node.Child()->Accept(*this);
    VisitOperator("++", node.OpPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(PostfixDecExprNode& node)
{
    BeginVisit(node);
    node.Child()->Accept(*this);
    VisitOperator("--", node.OpPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(TypeIdExprNode& node)
{
    BeginVisit(node);
    VisitKeyword("typeid", node.GetSourcePos());
    VisitOperator("(", node.LParenPos());
    node.Child()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(DynamicCastNode& node)
{
    VisitKeyword("dynamic_cast", node.GetSourcePos());
}

void DefaultVisitor::Visit(StaticCastNode& node)
{
    VisitKeyword("static_cast", node.GetSourcePos());
}

void DefaultVisitor::Visit(ReinterpretCastNode& node)
{
    VisitKeyword("reinterpret_cast", node.GetSourcePos());
}

void DefaultVisitor::Visit(ConstCastNode& node)
{
    VisitKeyword("const_cast", node.GetSourcePos());
}

void DefaultVisitor::Visit(CppCastExprNode& node)
{
    BeginVisit(node);
    node.Op()->Accept(*this);
    VisitOperator("<", node.LAnglePos());
    node.TypeId()->Accept(*this);
    VisitOperator(">", node.RAnglePos());
    VisitOperator("(", node.LParenPos());
    node.Child()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(ThisNode& node)
{
    VisitKeyword("this", node.GetSourcePos());
}

void DefaultVisitor::Visit(ParenthesizedExprNode& node)
{
    BeginVisit(node);
    VisitOperator("(", node.LParenPos());
    node.Child()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(FoldExprNode& node)
{
    BeginVisit(node);
    VisitOperator("(", node.LParenPos());
    VisitSequence(node);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(NewDeclaratorNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(ArrayNewDeclaratorNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(NewInitializerNode& node)
{
    BeginVisit(node);
    VisitOperator("(", node.LParenPos());
    VisitListContent(node);
    VisitOperator(")", node.RParenPos());
}

void DefaultVisitor::Visit(BracedInitListNode& node)
{
    VisitList(node);
}

void DefaultVisitor::Visit(DesignatedInitializerNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(DesignatorNode& node)
{
    BeginVisit(node);
    VisitOperator(".", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(EllipsesNode& node)
{
    VisitOperator("...", node.GetSourcePos());
}

// Function:

void DefaultVisitor::Visit(FunctionDefinitionNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    if (node.DeclSpecifiers()) 
    {
        node.DeclSpecifiers()->Accept(*this);
    }
    node.Declarator()->Accept(*this);
    if (node.Specifiers())
    {
        node.Specifiers()->Accept(*this);
    }
    node.FunctionBody()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(FunctionBodyNode& node)
{
    VisitUnaryNode(node);
}

void DefaultVisitor::Visit(DefaultNode& node)
{
    VisitKeyword("default", node.GetSourcePos());
}

void DefaultVisitor::Visit(DeleteNode& node)
{
    VisitKeyword("delete", node.GetSourcePos());
}

void DefaultVisitor::Visit(GeneratedFunctionBodyNode& node)
{
    BeginVisit(node);
    node.Assign()->Accept(*this);
    node.Gen()->Accept(*this);
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(FunctionDeclarationNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.Declarator()->Accept(*this);
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(OperatorNode& node)
{
    VisitKeyword("operator", node.GetSourcePos());
}

void DefaultVisitor::Visit(NewArrayOpNode& node)
{
    BeginVisit(node);
    VisitKeyword("new", node.GetSourcePos());
    VisitOperator("[", node.LBracketPos());
    VisitOperator("]", node.RBracketPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(NewOpNode& node)
{
    VisitKeyword("new", node.GetSourcePos());
}

void DefaultVisitor::Visit(DeleteArrayOpNode& node)
{
    BeginVisit(node);
    VisitKeyword("delete", node.GetSourcePos());
    VisitOperator("[", node.LBracketPos());
    VisitOperator("]", node.RBracketPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(DeleteOpNode& node)
{
    VisitKeyword("delete", node.GetSourcePos());
}

void DefaultVisitor::Visit(CoAwaitOpNode& node)
{
    VisitKeyword("co_await", node.GetSourcePos());
}

void DefaultVisitor::Visit(InvokeOpNode& node)
{
    VisitOperator("()", node.GetSourcePos());
}

void DefaultVisitor::Visit(SubscriptOpNode& node)
{
    VisitOperator("[]", node.GetSourcePos());
}

void DefaultVisitor::Visit(OperatorFunctionIdNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(ConversionFunctionIdNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(ConversionTypeIdNode& node)
{
    BeginVisit(node);
    node.TypeSpecifierSeq()->Accept(*this);
    if (node.ConversionDeclarator())
    {
        node.ConversionDeclarator()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(ConversionDeclaratorNode& node)
{
    BeginVisit(node);
    node.PtrOp()->Accept(*this);
    if (node.ConversionDeclarator())
    {
        node.ConversionDeclarator()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(DestructorIdNode& node)
{
    BeginVisit(node);
    VisitOperator("~", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ParameterNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.DeclSpecifiers()->Accept(*this);
    if (node.Declarator())
    {
        node.Declarator()->Accept(*this);
    }
    if (node.Assign())
    {
        node.Assign()->Accept(*this);
        node.Initializer()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(ParameterListNode& node)
{
    BeginVisit(node);
    VisitOperator("(", node.LParenPos());
    VisitListContent(node);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(NoexceptNode& node)
{
    VisitKeyword("noexcept", node.GetSourcePos());
}

void DefaultVisitor::Visit(FunctionTryBlockNode& node)
{
    BeginVisit(node);
    VisitKeyword("try", node.GetSourcePos());
    if (node.CtorInitializer())
    {
        node.CtorInitializer()->Accept(*this);
    }
    node.TryBlock()->Accept(*this);
    node.Handlers()->Accept(*this);
    EndVisit(node);
}

// Identifier:

void DefaultVisitor::Visit(IdentifierNode& node)
{
    VisitIdentfier(node.Str(), node.GetSourcePos());
}

void DefaultVisitor::Visit(UnnamedNode& node)
{
}

void DefaultVisitor::Visit(ColonColonNode& node)
{
    VisitOperator("::", node.GetSourcePos());
}

void DefaultVisitor::Visit(NestedNameSpecifierNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(QualifiedIdNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(IdentifierListNode& node)
{
    VisitList(node);
}

void DefaultVisitor::Visit(QualifiedModuleIdNode& node)
{
    BeginVisit(node);
    node.Left()->Accept(*this);
    VisitOperator(".", node.DotPos());
    node.Right()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(DotNode& node)
{
    VisitOperator(".", node.GetSourcePos());
}

// Lambda:

void DefaultVisitor::Visit(LambdaExpressionNode& node)
{
    BeginVisit(node);
    node.Introducer()->Accept(*this);
    if (node.TemplateParams())
    {
        node.TemplateParams()->Accept(*this);
    }
    node.Declarator()->Accept(*this);
    node.Body()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(LambdaIntroducerNode& node)
{
    BeginVisit(node);
    VisitOperator("[", node.LBracketPos());
    if (node.Capture())
    {
        node.Capture()->Accept(*this);
    }
    VisitOperator("]", node.RBracketPos());
}

void DefaultVisitor::Visit(LambdaCaptureNode& node)
{
    VisitList(node);
}

void DefaultVisitor::Visit(DefaultRefCaptureNode& node)
{
    VisitOperator("&", node.GetSourcePos());
}

void DefaultVisitor::Visit(DefaultCopyCaptureNode& node)
{
    VisitOperator("=", node.GetSourcePos());
}

void DefaultVisitor::Visit(ByRefCaptureNode& node)
{
    VisitOperator("&", node.GetSourcePos());
}

void DefaultVisitor::Visit(SimpleCaptureNode& node)
{
    BeginVisit(node);
    if (node.ByRefCapture())
    {
        node.ByRefCapture()->Accept(*this);
    }
    node.Identifier()->Accept(*this);
    if (node.Ellipses())
    {
        node.Ellipses()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(CurrentObjectCopyCapture& node)
{
    BeginVisit(node);
    VisitOperator("*", node.GetSourcePos());
    VisitKeyword("this", node.ThisPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(CurrentObjectByRefCapture& node)
{
    BeginVisit(node);
    VisitKeyword("this", node.ThisPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(InitCaptureNode& node)
{
    BeginVisit(node);
    if (node.ByRefCapture())
    {
        node.ByRefCapture()->Accept(*this);
    }
    if (node.Ellipses())
    {
        node.Ellipses()->Accept(*this);
    }
    node.Identifier()->Accept(*this);
    node.Initializer()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(LambdaDeclaratorNode& node)
{
    BeginVisit(node);
    if (node.ParameterList())
    {
        node.ParameterList()->Accept(*this);
    }
    node.Specifiers()->Accept(*this);
    if (node.RequiresClause())
    {
        node.RequiresClause()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(LambdaSpecifiersNode& node)
{
    if (!node.IsEmpty())
    {
        BeginVisit(node);
        if (node.DeclSpecifiers())
        {
            node.DeclSpecifiers()->Accept(*this);
        }
        if (node.NoexceptionSpecifier())
        {
            node.NoexceptionSpecifier()->Accept(*this);
        }
        if (node.Attributes())
        {
            node.Attributes()->Accept(*this);
        }
        if (node.TrailingReturnType())
        {
            node.TrailingReturnType()->Accept(*this);
        }
        EndVisit(node);
    }
}

void DefaultVisitor::Visit(LambdaTemplateParamsNode& node)
{
    BeginVisit(node);
    node.TemplateParams()->Accept(*this);
    if (node.RequiresClause())
    {
        node.RequiresClause()->Accept(*this);
    }
    EndVisit(node);
}

// Literal:

void DefaultVisitor::Visit(IntegerLiteralNode& node)
{
    VisitLiteral(node.Rep(), node.GetSourcePos());
}

void DefaultVisitor::Visit(FloatingLiteralNode& node)
{
    VisitLiteral(node.Rep(), node.GetSourcePos());
}

void DefaultVisitor::Visit(CharacterLiteralNode& node)
{
    VisitLiteral(node.Rep(), node.GetSourcePos());
}

void DefaultVisitor::Visit(StringLiteralNode& node)
{
    VisitLiteral(node.Rep(), node.GetSourcePos());
}

void DefaultVisitor::Visit(RawStringLiteralNode& node)
{
    VisitLiteral(node.Rep(), node.GetSourcePos());
}

void DefaultVisitor::Visit(BooleanLiteralNode& node)
{
    VisitLiteral(node.Rep(), node.GetSourcePos());
}

void DefaultVisitor::Visit(NullPtrLiteralNode& node)
{
    VisitLiteral(node.Rep(), node.GetSourcePos());
}

void DefaultVisitor::Visit(UserDefinedLiteraNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(LiteralOperatorIdNode& node)
{
    BeginVisit(node);
    VisitKeyword("operator", node.GetSourcePos());
    VisitOperator("\"\"", node.StringLitPos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

// Module:

void DefaultVisitor::Visit(ModuleDeclarationNode& node)
{
    BeginVisit(node); 
    if (node.Export())
    {
        node.Export()->Accept(*this);
    }
    node.Module()->Accept(*this);
    node.ModuleName()->Accept(*this);
    if (node.ModulePartition())
    {
        node.ModulePartition()->Accept(*this);
    }
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ExportDeclarationNode& node)
{
    BeginVisit(node);
    node.Export()->Accept(*this);
    if (node.LBracePos().IsValid())
    {
        VisitOperator("{", node.LBracePos());
        if (node.Subject())
        {
            node.Subject()->Accept(*this);
        }
        VisitOperator("}", node.RBracePos());
    }
    else
    {
        node.Subject()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(ExportNode& node)
{
    VisitKeyword("export", node.GetSourcePos());
}

void DefaultVisitor::Visit(ImportNode& node)
{
    VisitKeyword("import", node.GetSourcePos());
}

void DefaultVisitor::Visit(ImportDeclarationNode& node)
{
    BeginVisit(node);
    node.Import()->Accept(*this);
    node.Subject()->Accept(*this);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ModulePartitionNode& node)
{
    BeginVisit(node);
    VisitOperator(":", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ModuleNode& node)
{
    VisitKeyword("module", node.GetSourcePos());
}

void DefaultVisitor::Visit(GlobalModuleFragmentNode& node)
{
    BeginVisit(node);
    node.Module()->Accept(*this);
    node.Semicolon()->Accept(*this);
    if (node.Declarations())
    {
        node.Declarations()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(PrivateModuleFragmentNode& node)
{
    BeginVisit(node);
    node.Module()->Accept(*this);
    node.Colon()->Accept(*this);
    node.Private()->Accept(*this);
    node.Semicolon()->Accept(*this);
    if (node.Declarations())
    {
        node.Declarations()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(AngleHeaderName& node)
{
    VisitHeaderName(node.Rep(), node.GetSourcePos());
}

void DefaultVisitor::Visit(QuoteHeaderName& node)
{
    VisitHeaderName(node.Rep(), node.GetSourcePos());
}

// Qualifier:

void DefaultVisitor::Visit(ConstNode& node)
{
    VisitKeyword("const", node.GetSourcePos());
}

void DefaultVisitor::Visit(VolatileNode& node)
{
    VisitKeyword("volatile", node.GetSourcePos());
}

void DefaultVisitor::Visit(LvalueRefNode& node)
{
    VisitOperator("&", node.GetSourcePos());
}

void DefaultVisitor::Visit(RvalueRefNode& node)
{
    VisitOperator("&&", node.GetSourcePos());
}

void DefaultVisitor::Visit(PtrNode& node)
{
    VisitOperator("*", node.GetSourcePos());
}

void DefaultVisitor::Visit(CVQualifierSequenceNode& node)
{
    VisitSequence(node);
}

// SimpleType:

void DefaultVisitor::Visit(CharNode& node)
{
    VisitKeyword("char", node.GetSourcePos());
}

void DefaultVisitor::Visit(Char8Node& node)
{
    VisitKeyword("char8_t", node.GetSourcePos());
}

void DefaultVisitor::Visit(Char16Node& node)
{
    VisitKeyword("char16_t", node.GetSourcePos());
}

void DefaultVisitor::Visit(Char32Node& node)
{
    VisitKeyword("char32_t", node.GetSourcePos());
}

void DefaultVisitor::Visit(WCharNode& node)
{
    VisitKeyword("wchar_t", node.GetSourcePos());
}

void DefaultVisitor::Visit(BoolNode& node)
{
    VisitKeyword("bool", node.GetSourcePos());
}

void DefaultVisitor::Visit(ShortNode& node)
{
    VisitKeyword("short", node.GetSourcePos());
}

void DefaultVisitor::Visit(IntNode& node)
{
    VisitKeyword("int", node.GetSourcePos());
}

void DefaultVisitor::Visit(LongNode& node)
{
    VisitKeyword("long", node.GetSourcePos());
}

void DefaultVisitor::Visit(SignedNode& node)
{
    VisitKeyword("signed", node.GetSourcePos());
}

void DefaultVisitor::Visit(UnsignedNode& node)
{
    VisitKeyword("unsigned", node.GetSourcePos());
}

void DefaultVisitor::Visit(FloatNode& node)
{
    VisitKeyword("float", node.GetSourcePos());
}

void DefaultVisitor::Visit(DoubleNode& node)
{
    VisitKeyword("double", node.GetSourcePos());
}

void DefaultVisitor::Visit(VoidNode& node)
{
    VisitKeyword("void", node.GetSourcePos());
}

// Statement:

void DefaultVisitor::Visit(LabeledStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.Label()->Accept(*this);
    VisitOperator(":", node.ColonPos());
    node.Statement()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(CaseStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("case", node.CasePos());
    node.CaseExpression()->Accept(*this);
    VisitOperator(":", node.ColonPos());
    node.Statement()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(DefaultStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("default", node.DefaultPos());
    VisitOperator(":", node.ColonPos());
    node.Statement()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(CompoundStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitOperator("{", node.LBracePos());
    VisitSequenceContent(node);
    VisitOperator("}", node.RBracePos());
    EndVisit(node);
}

void DefaultVisitor::Visit(IfStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("if", node.IfPos());
    if (node.IsConstExprIf())
    {
        VisitKeyword("constexpr", node.ConstExprSourcePos());
    }
    VisitOperator("(", node.LParenPos());
    if (node.InitStatement())
    {
        node.InitStatement()->Accept(*this);
    }
    node.Condition()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    node.ThenStatement()->Accept(*this);
    if (node.ElseStatement())
    {
        VisitKeyword("else", node.ElsePos());
        node.ElseStatement()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(SwitchStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("switch", node.SwitchPos());
    VisitOperator("(", node.LParenPos());
    if (node.InitStatement())
    {
        node.InitStatement()->Accept(*this);
    }
    node.Condition()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    node.Statement()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(WhileStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("while", node.WhilePos());
    VisitOperator("(", node.LParenPos());
    node.Condition()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    node.Statement()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(DoStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("do", node.DoPos());
    node.Statement()->Accept(*this);
    VisitKeyword("while", node.WhilePos());
    VisitOperator("(", node.LParenPos());
    node.Expression()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(RangeForStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("for", node.ForPos());
    VisitOperator("(", node.LParenPos());
    if (node.InitStatement())
    {
        node.InitStatement()->Accept(*this);
    }
    node.Declaration()->Accept(*this);
    VisitOperator(":", node.ColonPos());
    node.Initializer()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    node.Statement()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ForRangeDeclarationNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.Left()->Accept(*this);
    node.Right()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(StructuredBindingNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.DeclSpecifiers()->Accept(*this);
    if (node.RefQualifier())
    {
        node.RefQualifier()->Accept(*this);
    }
    VisitOperator("[", node.LBracketPos());
    node.Identifiers()->Accept(*this);
    VisitOperator("]", node.RBracketPos());
    if (node.Initializer())
    {
        node.Initializer()->Accept(*this);
    }
    if (node.Semicolon())
    {
        node.Semicolon()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(ForStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("for", node.ForPos());
    VisitOperator("(", node.LParenPos());
    node.InitStatement()->Accept(*this);
    if (node.Condition())
    {
        node.Condition()->Accept(*this);
    }
    node.Semicolon()->Accept(*this);
    if (node.LoopExpr())
    {
        node.LoopExpr()->Accept(*this);
    }
    VisitOperator(")", node.RParenPos());
    node.Statement()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(BreakStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("break", node.BreakPos());
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ContinueStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("continue", node.ContinuePos());
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ReturnStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("return", node.ReturnPos());
    if (node.ReturnValue())
    {
        node.ReturnValue()->Accept(*this);
    }
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(CoReturnStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("co_return", node.CoReturnPos());
    if (node.ReturnValue())
    {
        node.ReturnValue()->Accept(*this);
    }
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(GotoStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("goto", node.GotoPos());
    node.Target()->Accept(*this);
    node.Semimcolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(TryStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    VisitKeyword("try", node.TryPos());
    node.TryBlock()->Accept(*this);
    node.Handlers()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(HandlerSequenceNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(HandlerNode& node)
{
    BeginVisit(node);
    VisitKeyword("catch", node.GetSourcePos());
    VisitOperator("(", node.LParenPos());
    node.Exception()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    node.CatchBlock()->Accept(*this);
}

void DefaultVisitor::Visit(ExceptionDeclarationNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.TypeSpecifiers()->Accept(*this);
    if (node.Declarator())
    {
        node.Declarator()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(ExpressionStatementNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    if (node.Expression())
    {
        node.Expression()->Accept(*this);
    }
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(DeclarationStatementNode& node)
{
    BeginVisit(node);
    node.Declaration()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(InitConditionNode& node)
{
    BeginVisit(node);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.DeclSpecifiers()->Accept(*this);
    node.Declarator()->Accept(*this);
    node.Initializer()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(SemicolonNode& node)
{
    VisitOperator(";", node.GetSourcePos());
}

// Template:

void DefaultVisitor::Visit(TemplateDeclarationNode& node)
{
    VisitBinaryNode(node);
}

void DefaultVisitor::Visit(TemplateHeadNode& node)
{
    BeginVisit(node);
    VisitKeyword("template", node.GetSourcePos());
    node.TemplateParamList()->Accept(*this);
    if (node.RequiresClause())
    {
        node.RequiresClause()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(TemplateParameterListNode& node)
{
    BeginVisit(node);
    VisitOperator("<", node.LAnglePos());
    VisitListContent(node);
    VisitOperator(">", node.RAnglePos());
    EndVisit(node);
}

void DefaultVisitor::Visit(TypeParameterNode& node)
{
    BeginVisit(node);
    if (node.TemplateHead())
    {
        node.TemplateHead()->Accept(*this);
    }
    node.TypeConstraint()->Accept(*this);
    if (node.Ellipses())
    {
        node.Ellipses()->Accept(*this);
    }
    if (node.Identifier())
    {
        node.Identifier()->Accept(*this);
    }
    if (node.Assign())
    {
        node.Assign()->Accept(*this);
    }
    if (node.TypeId())
    {
        node.TypeId()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(TemplateIdNode& node)
{
    BeginVisit(node);
    node.TemplateName()->Accept(*this);
    VisitOperator("<", node.LAnglePos());
    VisitListContent(node);
    VisitOperator(">", node.RAnglePos());
    EndVisit(node);
}

void DefaultVisitor::Visit(TypenameNode& node)
{
    VisitKeyword("typename", node.GetSourcePos());
}

void DefaultVisitor::Visit(DeductionGuideNode& node)
{
    BeginVisit(node);
    if (node.ExplicitSpecifier())
    {
        node.ExplicitSpecifier()->Accept(*this);
    }
    node.TemplateName()->Accept(*this);
    VisitOperator("(", node.LParenPos());
    node.Parameters()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    node.Arrow()->Accept(*this);
    node.TemplateId()->Accept(*this);
    node.Semicolon()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ExplicitInstantiationNode& node)
{
    BeginVisit(node);
    if (node.Extern())
    {
        node.Extern()->Accept(*this);
    }
    node.Template()->Accept(*this);
    node.Declaration()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(TemplateNode& node)
{
    VisitKeyword("template", node.GetSourcePos());
}

void DefaultVisitor::Visit(ExplicitSpecializationNode& node)
{
    BeginVisit(node);
    node.Template()->Accept(*this);
    VisitOperator("<", node.LAnglePos());
    VisitOperator(">", node.RAnglePos());
    node.Declaration()->Accept(*this);
    EndVisit(node);
}

// TranslationUnit:

void DefaultVisitor::Visit(TranslationUnitNode& node)
{
    BeginVisit(node);
    if (node.Unit())
    {
        node.Unit()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(ModuleUnitNode& node)
{
    BeginVisit(node);
    if (node.GlobalModuleFragment())
    {
        node.GlobalModuleFragment()->Accept(*this);
    }
    node.ModuleDeclaration()->Accept(*this);
    if (node.Declarations())
    {
        node.Declarations()->Accept(*this);
    }
    if (node.PrivateModuleFragment())
    {
        node.PrivateModuleFragment()->Accept(*this);
    }
    EndVisit(node);
}

// Type:

void DefaultVisitor::Visit(TypeSpecifierSequenceNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(TypenameSpecifierNode& node)
{
    BeginVisit(node);
    VisitKeyword("typename", node.GetSourcePos());
    node.NestedNameSpecifier()->Accept(*this);
    if (node.TemplateNode())
    {
        node.TemplateNode()->Accept(*this);
    }
    node.Id()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(TypeIdNode& node)
{
    BeginVisit(node);
    node.TypeSpecifiers()->Accept(*this);
    if (node.Declarator())
    {
        node.Declarator()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(DefiningTypeIdNode& node)
{
    BeginVisit(node);
    node.DefiningTypeSpecifiers()->Accept(*this);
    if (node.AbstractDeclarator())
    {
        node.AbstractDeclarator()->Accept(*this);
    }
    EndVisit(node);
}

void DefaultVisitor::Visit(DefiningTypeSpecifierSequenceNode& node)
{
    VisitSequence(node);
}

void DefaultVisitor::Visit(TrailingReturnTypeNode& node)
{
    BeginVisit(node);
    VisitOperator("->", node.GetSourcePos());
    node.Child()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(ElaboratedTypeSpecifierNode& node)
{
    BeginVisit(node);
    node.ClassKey()->Accept(*this);
    if (node.Attributes())
    {
        node.Attributes()->Accept(*this);
    }
    node.Id()->Accept(*this);
    EndVisit(node);
}

void DefaultVisitor::Visit(DeclTypeSpecifierNode& node)
{
    BeginVisit(node);
    VisitKeyword("delctype", node.GetSourcePos());
    VisitOperator("(", node.LParenPos());
    node.Expression()->Accept(*this);
    VisitOperator(")", node.RParenPos());
    EndVisit(node);
}

void DefaultVisitor::Visit(PlaceholderTypeSpecifierNode& node)
{
    BeginVisit(node);
    node.TypeConstraint()->Accept(*this);
    if (node.IsDeclType())
    {
        VisitKeyword("delctype", node.DeclTypePos());
        VisitOperator("(", node.LParenPos());
        VisitKeyword("auto", node.AutoPos());
        VisitOperator(")", node.RParenPos());
    }
    else
    {
        VisitKeyword("auto", node.AutoPos());
    }
    EndVisit(node);
}

} // namespace sngcpp::ast
