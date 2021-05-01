// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Declaration.hpp>

namespace sngcpp::ast {

DeclarationSequenceNode::DeclarationSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::declarationSequenceNode, sourcePos_)
{
}

SimpleDeclarationNode::SimpleDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::simpleDeclarationNode, sourcePos_)
{
}

SimpleDeclarationNode::SimpleDeclarationNode(const SourcePos& sourcePos_, Node* declarationSpecifiers_, Node* initDeclaratorList_, Node* attributes_, Node* semicolon_) :
    CompoundNode(NodeKind::simpleDeclarationNode, sourcePos_), declarationSpecifiers(declarationSpecifiers_), initDeclaratorList(initDeclaratorList_), attributes(attributes_), semicolon(semicolon_)
{
}

AsmDeclarationNode::AsmDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::asmDeclarationNode, sourcePos_)
{
}

AsmDeclarationNode::AsmDeclarationNode(const SourcePos& sourcePos_, Node* asm__, Node* asmText_, Node* semicolon_, Node* attributes_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::asmDeclarationNode, sourcePos_), asm_(asm__), asmText(asmText_), semicolon(semicolon_), attributes(attributes_), lpPos(lpPos_), rpPos(rpPos_)
{
}

AsmNode::AsmNode(const SourcePos& sourcePos_) : Node(NodeKind::asmNode, sourcePos_)
{
}

LinkageSpecificationNode::LinkageSpecificationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::linkageSpecificationNode, sourcePos_)
{
}

LinkageSpecificationNode::LinkageSpecificationNode(const SourcePos& sourcePos_, Node* extrn_, Node* linkage_, Node* declarations_, const SourcePos& lbPos_, const SourcePos& rbPos_) :
    CompoundNode(NodeKind::linkageSpecificationNode, sourcePos_), extrn(extrn_), linkage(linkage_), declarations(declarations_), lbPos(lbPos_), rbPos(rbPos_)
{
}

NamespaceDefinitionNode::NamespaceDefinitionNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::namespaceDefinitionNode, sourcePos_)
{
}

NamespaceDefinitionNode::NamespaceDefinitionNode(const SourcePos& sourcePos_, Node* nskw_, Node* nsName_, Node* nsBody_, Node* inln_, Node* attributes_,
    const SourcePos& lbPos_, const SourcePos& rbPos_) :
    CompoundNode(NodeKind::namespaceDefinitionNode, sourcePos_), nskw(nskw_), nsName(nsName_), nsBody(nsBody_), inln(inln_), attributes(attributes_), lbPos(lbPos_), rbPos(rbPos_)
{
}

NamespaceBodyNode::NamespaceBodyNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::namespaceBodyNode, sourcePos_)
{
}

NamespaceBodyNode::NamespaceBodyNode(const SourcePos& sourcePos_, Node* declarations_) : CompoundNode(NodeKind::namespaceBodyNode, sourcePos_), declarations(declarations_)
{
}

NamespaceAliasDefinitionNode::NamespaceAliasDefinitionNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::namespaceAliasDefinitionNode, sourcePos_)
{
}

NamespaceAliasDefinitionNode::NamespaceAliasDefinitionNode(const SourcePos& sourcePos_, Node* id_, Node* assign_, Node* qns_, Node* semicolon_) :
    CompoundNode(NodeKind::namespaceAliasDefinitionNode, sourcePos_), id(id_), assign(assign_), qns(qns_), semicolon(semicolon_)
{
}

UsingDeclarationNode::UsingDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::usingDeclarationNode, sourcePos_)
{
}

UsingDeclarationNode::UsingDeclarationNode(const SourcePos& sourcePos_, Node* usng_, Node* declarators_, Node* semicolon_) :
    CompoundNode(NodeKind::usingDeclarationNode, sourcePos_), usng(usng_), declarators(declarators_), semicolon(semicolon_)
{
}

UsingNode::UsingNode(const SourcePos& sourcePos_) : Node(NodeKind::usingNode, sourcePos_)
{
}

UsingDeclaratorListNode::UsingDeclaratorListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::usingDeclaratorListNode, sourcePos_)
{
}

UsingEnumDeclarationNode::UsingEnumDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::usingEnumDeclarationNode, sourcePos_)
{
}

UsingEnumDeclarationNode::UsingEnumDeclarationNode(const SourcePos& sourcePos_, Node* usng_, Node* ees_, Node* semicolon_) :
    CompoundNode(NodeKind::usingEnumDeclarationNode, sourcePos_), usng(usng_), ees(ees_), semicolon(semicolon_)
{
}

UsingDirectiveNode::UsingDirectiveNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::usingDirectiveNode, sourcePos_)
{
}

UsingDirectiveNode::UsingDirectiveNode(const SourcePos& sourcePos_, Node* usng_, Node* nskw_, Node* id_, Node* semicolon_, Node* attributes_) :
    CompoundNode(NodeKind::usingDirectiveNode, sourcePos_), usng(usng_), nskw(nskw_), id(id_), semicolon(semicolon_), attributes(attributes_)
{
}

NamespaceNode::NamespaceNode(const SourcePos& sourcePos_) : Node(NodeKind::namespaceNode, sourcePos_)
{
}

StaticAssertDeclarationNode::StaticAssertDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::staticAssertDeclarationNode, sourcePos_)
{
}

StaticAssertDeclarationNode::StaticAssertDeclarationNode(const SourcePos& sourcePos_, Node* staticAssert_, Node* constantExpr_, Node* comma_, Node* stringLiteral_, Node* semicolon_,
    const SourcePos& lpPos_, const SourcePos rpPos_) :
    CompoundNode(NodeKind::staticAssertDeclarationNode, sourcePos_), staticAssert(staticAssert_), constantExpr(constantExpr_), comma(comma_), stringLiteral(stringLiteral_), semicolon(semicolon_),
    lpPos(lpPos_), rpPos(rpPos_)
{
}

StaticAssertNode::StaticAssertNode(const SourcePos& sourcePos_) : Node(NodeKind::staticAssertNode, sourcePos_)
{
}

AliasDeclarationNode::AliasDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::aliasDeclarationNode, sourcePos_)
{
}

AliasDeclarationNode::AliasDeclarationNode(const SourcePos& sourcePos_, Node* usng_, Node* identifier_, Node* assign_, Node* definingTypeId_, Node* attributes_, Node* semicolon_) :
    CompoundNode(NodeKind::aliasDeclarationNode, sourcePos_), usng(usng_), identifier(identifier_), assign(assign_), definingTypeId(definingTypeId_), attributes(attributes_), semicolon(semicolon_)
{
}

EmptyDeclarationNode::EmptyDeclarationNode(const SourcePos& sourcePos_) : Node(NodeKind::emptyDeclarationNode, sourcePos_)
{
}

AttributeDeclarationNode::AttributeDeclarationNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::attributeDeclarationNode, sourcePos_, nullptr, nullptr)
{
}

AttributeDeclarationNode::AttributeDeclarationNode(const SourcePos& sourcePos_, Node* attributes_, Node* semicolon_) : 
    BinaryNode(NodeKind::attributeDeclarationNode, sourcePos_, attributes_, semicolon_)
{
}

InitDeclaratorListNode::InitDeclaratorListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::initDeclaratorListNode, sourcePos_)
{
}

InitDeclaratorNode::InitDeclaratorNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::initDeclaratorNode, sourcePos_, nullptr, nullptr)
{
}

InitDeclaratorNode::InitDeclaratorNode(const SourcePos& sourcePos_, Node* declarator_, Node* init_) : BinaryNode(NodeKind::initDeclaratorNode, sourcePos_, declarator_, init_)
{
}

TrailingInvokeDeclaratorNode::TrailingInvokeDeclaratorNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::trailingInvokeDeclaratorNode, sourcePos_)
{
}

TrailingInvokeDeclaratorNode::TrailingInvokeDeclaratorNode(const SourcePos& sourcePos_, Node* declarator_, Node* params_, Node* trailingReturnType_) :
    CompoundNode(NodeKind::trailingInvokeDeclaratorNode, sourcePos_), declarator(declarator_), params(params_), trailingReturnType(trailingReturnType_)
{
}

ParenthesizedDeclaratorNode::ParenthesizedDeclaratorNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::parenthesizedDeclaratorNode, sourcePos_)
{
}

ParenthesizedDeclaratorNode::ParenthesizedDeclaratorNode(const SourcePos& sourcePos_, Node* declarator_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::parenthesizedDeclaratorNode, sourcePos_), declarator(declarator_)
{
}

AbstractDeclaratorNode::AbstractDeclaratorNode(const SourcePos& sourcePos_) : Node(NodeKind::abstractDeclaratorNode, sourcePos_)
{
}

DeclSpecifierSequenceNode::DeclSpecifierSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::declSpecifierSequenceNode, sourcePos_)
{
}

FriendNode::FriendNode(const SourcePos& sourcePos_) : Node(NodeKind::friendNode, sourcePos_)
{
}

TypedefNode::TypedefNode(const SourcePos& sourcePos_) : Node(NodeKind::typedefNode, sourcePos_)
{
}

ConstExprNode::ConstExprNode(const SourcePos& sourcePos_) : Node(NodeKind::constExprNode, sourcePos_)
{
}

ConstEvalNode::ConstEvalNode(const SourcePos& sourcePos_) : Node(NodeKind::constEvalNode, sourcePos_)
{
}

ConstInitNode::ConstInitNode(const SourcePos& sourcePos_) : Node(NodeKind::constInitNode, sourcePos_)
{
}

InlineNode::InlineNode(const SourcePos& sourcePos_) : Node(NodeKind::inlineNode, sourcePos_)
{
}

StaticNode::StaticNode(const SourcePos& sourcePos_) : Node(NodeKind::staticNode, sourcePos_)
{
}

ThreadLocalNode::ThreadLocalNode(const SourcePos& sourcePos_) : Node(NodeKind::threadLocalNode, sourcePos_)
{
}

ExternNode::ExternNode(const SourcePos& sourcePos_) : Node(NodeKind::externNode, sourcePos_)
{
}

MutableNode::MutableNode(const SourcePos& sourcePos_) : Node(NodeKind::mutableNode, sourcePos_)
{
}

ExplicitNode::ExplicitNode(const SourcePos& sourcePos_) : Node(NodeKind::explicitNode, sourcePos_)
{
}

ConditionalExplicitNode::ConditionalExplicitNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::conditionalExplicitNode, sourcePos_, nullptr)
{
}

ConditionalExplicitNode::ConditionalExplicitNode(const SourcePos& sourcePos_, Node* cond_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    UnaryNode(NodeKind::conditionalExplicitNode, sourcePos_, cond_), lpPos(lpPos_), rpPos(rpPos_)
{
}

QualifiedPtrNode::QualifiedPtrNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::qualifiedPtrNode, sourcePos_, nullptr, nullptr)
{
}

QualifiedPtrNode::QualifiedPtrNode(const SourcePos& sourcePos_, Node* nns_, Node* ptr_) : 
    BinaryNode(NodeKind::qualifiedPtrNode, sourcePos_, nns_, ptr_)
{
}

PtrOperatorNode::PtrOperatorNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::ptrOperatorNode, sourcePos_, nullptr)
{
}

PtrOperatorNode::PtrOperatorNode(const SourcePos& sourcePos_, Node* child_) : UnaryNode(NodeKind::ptrOperatorNode, sourcePos_, child_)
{
}

PtrDeclaratorNode::PtrDeclaratorNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::ptrDeclaratorNode, sourcePos_)
{
}

PackDeclaratorIdNode::PackDeclaratorIdNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::packDeclaratorIdNode, sourcePos_, nullptr, nullptr)
{
}

PackDeclaratorIdNode::PackDeclaratorIdNode(const SourcePos& sourcePos_, Node* ellipses_, Node* idExpr_) :
    BinaryNode(NodeKind::packDeclaratorIdNode, sourcePos_, ellipses_, idExpr_)
{
}

SubscriptDeclaratorNode::SubscriptDeclaratorNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::subscriptDeclaratorNode, sourcePos_, nullptr)
{
}

SubscriptDeclaratorNode::SubscriptDeclaratorNode(const SourcePos& sourcePos_, Node* child_, Node* index_, const SourcePos& lbPos_, const SourcePos& rbPos_) :
    UnaryNode(NodeKind::subscriptDeclaratorNode, sourcePos_, child_), index(index_), lbPos(lbPos_), rbPos(rbPos_)
{
}

InvokeDeclaratorNode::InvokeDeclaratorNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::invokeDeclaratorNode, sourcePos_, nullptr)
{
}

InvokeDeclaratorNode::InvokeDeclaratorNode(const SourcePos& sourcePos_, Node* child_, Node* parameters_) : UnaryNode(NodeKind::invokeDeclaratorNode, sourcePos_, child_), params(parameters_)
{
}

PrefixNode::PrefixNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::prefixNode, sourcePos_, nullptr, nullptr)
{
}

PrefixNode::PrefixNode(const SourcePos& sourcePos_, Node* prefix_, Node* subject_) : BinaryNode(NodeKind::prefixNode, sourcePos_, prefix_, subject_)
{
}

TrailingQualifiersNode::TrailingQualifiersNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::trailingQualifiersNode, sourcePos_)
{
}

TrailingQualifiersNode::TrailingQualifiersNode(const SourcePos& sourcePos_, Node* subject_) : SequenceNode(NodeKind::trailingQualifiersNode, sourcePos_), subject(subject_)
{
}

TrailingAttributesNode::TrailingAttributesNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::trailingAttributesNode, sourcePos_, nullptr, nullptr)
{
}

TrailingAttributesNode::TrailingAttributesNode(const SourcePos& sourcePos_, Node* left_, Node* attributes_) : BinaryNode(NodeKind::trailingAttributesNode, sourcePos_, left_, attributes_)
{
}

NoexceptSpecifierNode::NoexceptSpecifierNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::noexceptSpecifierNode, sourcePos_, nullptr)
{
}

NoexceptSpecifierNode::NoexceptSpecifierNode(const SourcePos& sourcePos_, Node* constantExpr_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    UnaryNode(NodeKind::noexceptSpecifierNode, sourcePos_, constantExpr_), lpPos(lpPos_), rpPos(rpPos_)
{
}

} // namespace sngcpp::ast
