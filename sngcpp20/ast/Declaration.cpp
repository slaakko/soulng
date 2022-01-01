// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Declaration.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <sngcpp20/ast/Reader.hpp>

namespace sngcpp::ast {

DeclarationSequenceNode::DeclarationSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::declarationSequenceNode, sourcePos_)
{
}

void DeclarationSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

SimpleDeclarationNode::SimpleDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::simpleDeclarationNode, sourcePos_)
{
}

SimpleDeclarationNode::SimpleDeclarationNode(const SourcePos& sourcePos_, Node* declarationSpecifiers_, Node* initDeclaratorList_, Node* attributes_, Node* semicolon_) :
    CompoundNode(NodeKind::simpleDeclarationNode, sourcePos_), declarationSpecifiers(declarationSpecifiers_), initDeclaratorList(initDeclaratorList_), attributes(attributes_), semicolon(semicolon_)
{
}

void SimpleDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SimpleDeclarationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(declarationSpecifiers.get());
    writer.Write(initDeclaratorList.get());
    writer.Write(attributes.get());
    writer.Write(semicolon.get());
}

void SimpleDeclarationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    declarationSpecifiers.reset(reader.ReadNode());
    initDeclaratorList.reset(reader.ReadNode());
    attributes.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
}

AsmDeclarationNode::AsmDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::asmDeclarationNode, sourcePos_)
{
}

AsmDeclarationNode::AsmDeclarationNode(const SourcePos& sourcePos_, Node* asm__, Node* asmText_, Node* semicolon_, Node* attributes_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::asmDeclarationNode, sourcePos_), asm_(asm__), asmText(asmText_), semicolon(semicolon_), attributes(attributes_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void AsmDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void AsmDeclarationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(asm_.get());
    writer.Write(asmText.get());
    writer.Write(semicolon.get());
    writer.Write(attributes.get());
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void AsmDeclarationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    asm_.reset(reader.ReadNode());
    asmText.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
    attributes.reset(reader.ReadNode());
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

AsmNode::AsmNode(const SourcePos& sourcePos_) : Node(NodeKind::asmNode, sourcePos_)
{
}

void AsmNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LinkageSpecificationNode::LinkageSpecificationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::linkageSpecificationNode, sourcePos_)
{
}

LinkageSpecificationNode::LinkageSpecificationNode(const SourcePos& sourcePos_, Node* extrn_, Node* linkage_, Node* declarations_, const SourcePos& lbPos_, const SourcePos& rbPos_) :
    CompoundNode(NodeKind::linkageSpecificationNode, sourcePos_), extrn(extrn_), linkage(linkage_), declarations(declarations_), lbPos(lbPos_), rbPos(rbPos_)
{
}

void LinkageSpecificationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void LinkageSpecificationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(extrn.get());
    writer.Write(linkage.get());
    writer.Write(declarations.get());
    writer.Write(lbPos);
    writer.Write(rbPos);
}

void LinkageSpecificationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    extrn.reset(reader.ReadNode());
    linkage.reset(reader.ReadNode());
    declarations.reset(reader.ReadNode());
    lbPos = reader.ReadSourcePos();
    rbPos = reader.ReadSourcePos();
}

NamespaceDefinitionNode::NamespaceDefinitionNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::namespaceDefinitionNode, sourcePos_)
{
}

NamespaceDefinitionNode::NamespaceDefinitionNode(const SourcePos& sourcePos_, Node* nskw_, Node* nsName_, Node* nsBody_, Node* inln_, Node* attributes_,
    const SourcePos& lbPos_, const SourcePos& rbPos_) :
    CompoundNode(NodeKind::namespaceDefinitionNode, sourcePos_), nskw(nskw_), nsName(nsName_), nsBody(nsBody_), inln(inln_), attributes(attributes_), lbPos(lbPos_), rbPos(rbPos_)
{
}

void NamespaceDefinitionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NamespaceDefinitionNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(nskw.get());
    writer.Write(nsName.get());
    writer.Write(nsBody.get());
    writer.Write(inln.get());
    writer.Write(attributes.get());
    writer.Write(lbPos);
    writer.Write(rbPos);
}

void NamespaceDefinitionNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    nskw.reset(reader.ReadNode());
    nsName.reset(reader.ReadNode());
    nsBody.reset(reader.ReadNode());
    inln.reset(reader.ReadNode());
    attributes.reset(reader.ReadNode());
    lbPos = reader.ReadSourcePos();
    rbPos = reader.ReadSourcePos();
}

NamespaceBodyNode::NamespaceBodyNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::namespaceBodyNode, sourcePos_)
{
}

NamespaceBodyNode::NamespaceBodyNode(const SourcePos& sourcePos_, Node* declarations_) : CompoundNode(NodeKind::namespaceBodyNode, sourcePos_), declarations(declarations_)
{
}

void NamespaceBodyNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NamespaceBodyNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(declarations.get());
}

void NamespaceBodyNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    declarations.reset(reader.ReadNode());
}

NamespaceAliasDefinitionNode::NamespaceAliasDefinitionNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::namespaceAliasDefinitionNode, sourcePos_)
{
}

NamespaceAliasDefinitionNode::NamespaceAliasDefinitionNode(const SourcePos& sourcePos_, Node* id_, Node* assign_, Node* qns_, Node* semicolon_) :
    CompoundNode(NodeKind::namespaceAliasDefinitionNode, sourcePos_), id(id_), assign(assign_), qns(qns_), semicolon(semicolon_)
{
}

void NamespaceAliasDefinitionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NamespaceAliasDefinitionNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(id.get());
    writer.Write(assign.get());
    writer.Write(qns.get());
    writer.Write(semicolon.get());
}

void NamespaceAliasDefinitionNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    id.reset(reader.ReadNode());
    assign.reset(reader.ReadNode());
    qns.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
}

UsingDeclarationNode::UsingDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::usingDeclarationNode, sourcePos_)
{
}

UsingDeclarationNode::UsingDeclarationNode(const SourcePos& sourcePos_, Node* usng_, Node* declarators_, Node* semicolon_) :
    CompoundNode(NodeKind::usingDeclarationNode, sourcePos_), usng(usng_), declarators(declarators_), semicolon(semicolon_)
{
}

void UsingDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void UsingDeclarationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(usng.get());
    writer.Write(declarators.get());
    writer.Write(semicolon.get());
}

void UsingDeclarationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    usng.reset(reader.ReadNode());
    declarators.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
}

UsingNode::UsingNode(const SourcePos& sourcePos_) : Node(NodeKind::usingNode, sourcePos_)
{
}

void UsingNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

UsingDeclaratorListNode::UsingDeclaratorListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::usingDeclaratorListNode, sourcePos_)
{
}

void UsingDeclaratorListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

UsingEnumDeclarationNode::UsingEnumDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::usingEnumDeclarationNode, sourcePos_)
{
}

UsingEnumDeclarationNode::UsingEnumDeclarationNode(const SourcePos& sourcePos_, Node* usng_, Node* ees_, Node* semicolon_) :
    CompoundNode(NodeKind::usingEnumDeclarationNode, sourcePos_), usng(usng_), ees(ees_), semicolon(semicolon_)
{
}

void UsingEnumDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void UsingEnumDeclarationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(usng.get());
    writer.Write(ees.get());
    writer.Write(semicolon.get());
}

void UsingEnumDeclarationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    usng.reset(reader.ReadNode());
    ees.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
}

UsingDirectiveNode::UsingDirectiveNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::usingDirectiveNode, sourcePos_)
{
}

UsingDirectiveNode::UsingDirectiveNode(const SourcePos& sourcePos_, Node* usng_, Node* nskw_, Node* id_, Node* semicolon_, Node* attributes_) :
    CompoundNode(NodeKind::usingDirectiveNode, sourcePos_), usng(usng_), nskw(nskw_), id(id_), semicolon(semicolon_), attributes(attributes_)
{
}

void UsingDirectiveNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void UsingDirectiveNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(usng.get());
    writer.Write(nskw.get());
    writer.Write(id.get());
    writer.Write(semicolon.get());
    writer.Write(attributes.get());
}

void UsingDirectiveNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    usng.reset(reader.ReadNode());
    nskw.reset(reader.ReadNode());
    id.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
    attributes.reset(reader.ReadNode());
}

NamespaceNode::NamespaceNode(const SourcePos& sourcePos_) : Node(NodeKind::namespaceNode, sourcePos_)
{
}

void NamespaceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
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

void StaticAssertDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void StaticAssertDeclarationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(staticAssert.get());
    writer.Write(constantExpr.get());
    writer.Write(comma.get());
    writer.Write(stringLiteral.get());
    writer.Write(semicolon.get());
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void StaticAssertDeclarationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    staticAssert.reset(reader.ReadNode());
    constantExpr.reset(reader.ReadNode());
    comma.reset(reader.ReadNode());
    stringLiteral.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

StaticAssertNode::StaticAssertNode(const SourcePos& sourcePos_) : Node(NodeKind::staticAssertNode, sourcePos_)
{
}

void StaticAssertNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AliasDeclarationNode::AliasDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::aliasDeclarationNode, sourcePos_)
{
}

AliasDeclarationNode::AliasDeclarationNode(const SourcePos& sourcePos_, Node* usng_, Node* identifier_, Node* assign_, Node* definingTypeId_, Node* attributes_, Node* semicolon_) :
    CompoundNode(NodeKind::aliasDeclarationNode, sourcePos_), usng(usng_), identifier(identifier_), assign(assign_), definingTypeId(definingTypeId_), attributes(attributes_), semicolon(semicolon_)
{
}

void AliasDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void AliasDeclarationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(usng.get());
    writer.Write(identifier.get());
    writer.Write(assign.get());
    writer.Write(definingTypeId.get());
    writer.Write(attributes.get());
    writer.Write(semicolon.get());
}

void AliasDeclarationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    usng.reset(reader.ReadNode());
    identifier.reset(reader.ReadNode());
    assign.reset(reader.ReadNode());
    definingTypeId.reset(reader.ReadNode());
    attributes.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
}

EmptyDeclarationNode::EmptyDeclarationNode(const SourcePos& sourcePos_) : Node(NodeKind::emptyDeclarationNode, sourcePos_)
{
}

void EmptyDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AttributeDeclarationNode::AttributeDeclarationNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::attributeDeclarationNode, sourcePos_, nullptr, nullptr)
{
}

AttributeDeclarationNode::AttributeDeclarationNode(const SourcePos& sourcePos_, Node* attributes_, Node* semicolon_) : 
    BinaryNode(NodeKind::attributeDeclarationNode, sourcePos_, attributes_, semicolon_)
{
}

void AttributeDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

InitDeclaratorListNode::InitDeclaratorListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::initDeclaratorListNode, sourcePos_)
{
}

void InitDeclaratorListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

InitDeclaratorNode::InitDeclaratorNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::initDeclaratorNode, sourcePos_, nullptr, nullptr)
{
}

InitDeclaratorNode::InitDeclaratorNode(const SourcePos& sourcePos_, Node* declarator_, Node* init_) : BinaryNode(NodeKind::initDeclaratorNode, sourcePos_, declarator_, init_)
{
}

void InitDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TrailingFunctionDeclaratorNode::TrailingFunctionDeclaratorNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::trailingFunctionDeclaratorNode, sourcePos_)
{
}

TrailingFunctionDeclaratorNode::TrailingFunctionDeclaratorNode(const SourcePos& sourcePos_, Node* declarator_, Node* params_, Node* trailingReturnType_) :
    CompoundNode(NodeKind::trailingFunctionDeclaratorNode, sourcePos_), declarator(declarator_), params(params_), trailingReturnType(trailingReturnType_)
{
}

void TrailingFunctionDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TrailingFunctionDeclaratorNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(declarator.get());
    writer.Write(params.get());
    writer.Write(trailingReturnType.get());
}

void TrailingFunctionDeclaratorNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    declarator.reset(reader.ReadNode());
    params.reset(reader.ReadNode());
    trailingReturnType.reset(reader.ReadNode());
}

ParenthesizedDeclaratorNode::ParenthesizedDeclaratorNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::parenthesizedDeclaratorNode, sourcePos_)
{
}

ParenthesizedDeclaratorNode::ParenthesizedDeclaratorNode(const SourcePos& sourcePos_, Node* declarator_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::parenthesizedDeclaratorNode, sourcePos_), declarator(declarator_)
{
}

void ParenthesizedDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ParenthesizedDeclaratorNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(declarator.get());
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void ParenthesizedDeclaratorNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    declarator.reset(reader.ReadNode());
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

AbstractDeclaratorNode::AbstractDeclaratorNode(const SourcePos& sourcePos_) : Node(NodeKind::abstractDeclaratorNode, sourcePos_)
{
}

void AbstractDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DeclSpecifierSequenceNode::DeclSpecifierSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::declSpecifierSequenceNode, sourcePos_)
{
}

void DeclSpecifierSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

FriendNode::FriendNode(const SourcePos& sourcePos_) : Node(NodeKind::friendNode, sourcePos_)
{
}

void FriendNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TypedefNode::TypedefNode(const SourcePos& sourcePos_) : Node(NodeKind::typedefNode, sourcePos_)
{
}

void TypedefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ConstExprNode::ConstExprNode(const SourcePos& sourcePos_) : Node(NodeKind::constExprNode, sourcePos_)
{
}

void ConstExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ConstEvalNode::ConstEvalNode(const SourcePos& sourcePos_) : Node(NodeKind::constEvalNode, sourcePos_)
{
}

void ConstEvalNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ConstInitNode::ConstInitNode(const SourcePos& sourcePos_) : Node(NodeKind::constInitNode, sourcePos_)
{
}

void ConstInitNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CDeclNode::CDeclNode(const SourcePos& sourcePos_) : Node(NodeKind::cdeclNode, sourcePos_)
{
}

void CDeclNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

FastCallNode::FastCallNode(const SourcePos& sourcePos_) : Node(NodeKind::fastCallNode, sourcePos_)
{
}

void FastCallNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

StdCallNode::StdCallNode(const SourcePos& sourcePos_) : Node(NodeKind::stdCallNode, sourcePos_)
{
}

void StdCallNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ThisCallNode::ThisCallNode(const SourcePos& sourcePos_) : Node(NodeKind::thisCallNode, sourcePos_)
{
}

void ThisCallNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

VectorCallNode::VectorCallNode(const SourcePos& sourcePos_) : Node(NodeKind::vectorCallNode, sourcePos_)
{
}

void VectorCallNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

UnalignedNode::UnalignedNode(const SourcePos& sourcePos_) : Node(NodeKind::unalignedNode, sourcePos_)
{
}

void UnalignedNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DeclSpecNode::DeclSpecNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::declSpecNode, sourcePos_)
{
}

DeclSpecNode::DeclSpecNode(const SourcePos& sourcePos_, Node* identifier_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    CompoundNode(NodeKind::declSpecNode, sourcePos_), identifier(identifier_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void DeclSpecNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void DeclSpecNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(identifier.get());
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void DeclSpecNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    identifier.reset(reader.ReadNode());
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

InlineNode::InlineNode(const SourcePos& sourcePos_) : Node(NodeKind::inlineNode, sourcePos_)
{
}

void InlineNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

StaticNode::StaticNode(const SourcePos& sourcePos_) : Node(NodeKind::staticNode, sourcePos_)
{
}

void StaticNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ThreadLocalNode::ThreadLocalNode(const SourcePos& sourcePos_) : Node(NodeKind::threadLocalNode, sourcePos_)
{
}

void ThreadLocalNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExternNode::ExternNode(const SourcePos& sourcePos_) : Node(NodeKind::externNode, sourcePos_)
{
}

void ExternNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MutableNode::MutableNode(const SourcePos& sourcePos_) : Node(NodeKind::mutableNode, sourcePos_)
{
}

void MutableNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExplicitNode::ExplicitNode(const SourcePos& sourcePos_) : Node(NodeKind::explicitNode, sourcePos_)
{
}

void ExplicitNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ConditionalExplicitNode::ConditionalExplicitNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::conditionalExplicitNode, sourcePos_, nullptr)
{
}

ConditionalExplicitNode::ConditionalExplicitNode(const SourcePos& sourcePos_, Node* cond_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    UnaryNode(NodeKind::conditionalExplicitNode, sourcePos_, cond_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void ConditionalExplicitNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ConditionalExplicitNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(cond.get());
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void ConditionalExplicitNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    cond.reset(reader.ReadNode());
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

QualifiedPtrNode::QualifiedPtrNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::qualifiedPtrNode, sourcePos_, nullptr, nullptr)
{
}

QualifiedPtrNode::QualifiedPtrNode(const SourcePos& sourcePos_, Node* nns_, Node* ptr_) : 
    BinaryNode(NodeKind::qualifiedPtrNode, sourcePos_, nns_, ptr_)
{
}

void QualifiedPtrNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PtrOperatorNode::PtrOperatorNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::ptrOperatorNode, sourcePos_, nullptr)
{
}

PtrOperatorNode::PtrOperatorNode(const SourcePos& sourcePos_, Node* child_) : UnaryNode(NodeKind::ptrOperatorNode, sourcePos_, child_)
{
}

void PtrOperatorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PtrDeclaratorNode::PtrDeclaratorNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::ptrDeclaratorNode, sourcePos_)
{
}

void PtrDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PackDeclaratorIdNode::PackDeclaratorIdNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::packDeclaratorIdNode, sourcePos_, nullptr, nullptr)
{
}

PackDeclaratorIdNode::PackDeclaratorIdNode(const SourcePos& sourcePos_, Node* ellipsis_, Node* idExpr_) :
    BinaryNode(NodeKind::packDeclaratorIdNode, sourcePos_, ellipsis_, idExpr_)
{
}

void PackDeclaratorIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ArrayDeclaratorNode::ArrayDeclaratorNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::arrayDeclaratorNode, sourcePos_, nullptr)
{
}

ArrayDeclaratorNode::ArrayDeclaratorNode(const SourcePos& sourcePos_, Node* child_, Node* dimension_, const SourcePos& lbPos_, const SourcePos& rbPos_) :
    UnaryNode(NodeKind::arrayDeclaratorNode, sourcePos_, child_), dimension(dimension_), lbPos(lbPos_), rbPos(rbPos_)
{
}

void ArrayDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ArrayDeclaratorNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(dimension.get());
    writer.Write(lbPos);
    writer.Write(rbPos);
}

void ArrayDeclaratorNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    dimension.reset(reader.ReadNode());
    lbPos = reader.ReadSourcePos();
    rbPos = reader.ReadSourcePos();
}

FunctionDeclaratorNode::FunctionDeclaratorNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::functionDeclaratorNode, sourcePos_, nullptr)
{
}

FunctionDeclaratorNode::FunctionDeclaratorNode(const SourcePos& sourcePos_, Node* child_, Node* parameters_) : UnaryNode(NodeKind::functionDeclaratorNode, sourcePos_, child_), params(parameters_)
{
}

void FunctionDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void FunctionDeclaratorNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(params.get());
}

void FunctionDeclaratorNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    params.reset(reader.ReadNode());
}

PrefixNode::PrefixNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::prefixNode, sourcePos_, nullptr, nullptr)
{
}

PrefixNode::PrefixNode(const SourcePos& sourcePos_, Node* prefix_, Node* subject_) : BinaryNode(NodeKind::prefixNode, sourcePos_, prefix_, subject_)
{
}

void PrefixNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TrailingQualifiersNode::TrailingQualifiersNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::trailingQualifiersNode, sourcePos_)
{
}

TrailingQualifiersNode::TrailingQualifiersNode(const SourcePos& sourcePos_, Node* subject_) : SequenceNode(NodeKind::trailingQualifiersNode, sourcePos_), subject(subject_)
{
}

void TrailingQualifiersNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TrailingQualifiersNode::Write(Writer& writer)
{
    SequenceNode::Write(writer);
    writer.Write(subject.get());
}

void TrailingQualifiersNode::Read(Reader& reader)
{
    SequenceNode::Read(reader);
    subject.reset(reader.ReadNode());
}

TrailingAttributesNode::TrailingAttributesNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::trailingAttributesNode, sourcePos_, nullptr, nullptr)
{
}

TrailingAttributesNode::TrailingAttributesNode(const SourcePos& sourcePos_, Node* left_, Node* attributes_) : BinaryNode(NodeKind::trailingAttributesNode, sourcePos_, left_, attributes_)
{
}

void TrailingAttributesNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

NoexceptSpecifierNode::NoexceptSpecifierNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::noexceptSpecifierNode, sourcePos_)
{
}

NoexceptSpecifierNode::NoexceptSpecifierNode(const SourcePos& sourcePos_, Node* constantExpr_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::noexceptSpecifierNode, sourcePos_), constantExpr(constantExpr_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void NoexceptSpecifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NoexceptSpecifierNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(constantExpr.get());
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void NoexceptSpecifierNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    constantExpr.reset(reader.ReadNode());
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

ThrowSpecifierNode::ThrowSpecifierNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::throwSpecifierNode, sourcePos_)
{
}

ThrowSpecifierNode::ThrowSpecifierNode(const SourcePos& sourcePos_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::throwSpecifierNode, sourcePos_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void ThrowSpecifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ThrowSpecifierNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void ThrowSpecifierNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

} // namespace sngcpp::ast
