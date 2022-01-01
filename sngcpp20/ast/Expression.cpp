// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Expression.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <sngcpp20/ast/Reader.hpp>

namespace sngcpp::ast {

BinaryExprNode::BinaryExprNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::binaryExprNode, sourcePos_, nullptr, nullptr)
{
}

BinaryExprNode::BinaryExprNode(const SourcePos& sourcePos_, Node* op_, Node* left_, Node* right_) :
    BinaryNode(NodeKind::binaryExprNode, sourcePos_, left_, right_), op(op_)
{
}

void BinaryExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void BinaryExprNode::Write(Writer& writer)
{
    BinaryNode::Write(writer);
    writer.Write(op.get());
}

void BinaryExprNode::Read(Reader& reader)
{
    BinaryNode::Read(reader);
    op.reset(reader.ReadNode());
}

UnaryExprNode::UnaryExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::unaryExprNode, sourcePos_, nullptr)
{
}

UnaryExprNode::UnaryExprNode(const SourcePos& sourcePos_, Node* op_, Node* child_) : UnaryNode(NodeKind::unaryExprNode, sourcePos_, child_), op(op_)
{
}

void UnaryExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void UnaryExprNode::Write(Writer& writer) 
{
    UnaryNode::Write(writer);
    writer.Write(op.get());
}

void UnaryExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    op.reset(reader.ReadNode());
}

ExpressionListNode::ExpressionListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::expressionListNode, sourcePos_)
{
}

void ExpressionListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ExpressionListNode::Write(Writer& writer)
{
    ListNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void ExpressionListNode::Read(Reader& reader)
{
    ListNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

AssignmentInitNode::AssignmentInitNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::assignmentInitializerNode, sourcePos_, nullptr)
{
}

AssignmentInitNode::AssignmentInitNode(const SourcePos& sourcePos_, Node* initializer_) : UnaryNode(NodeKind::assignmentInitializerNode, sourcePos_, initializer_)
{
}

void AssignmentInitNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

YieldExprNode::YieldExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::yieldExprNode, sourcePos_, nullptr)
{
}

YieldExprNode::YieldExprNode(const SourcePos& sourcePos_, Node* child_) : UnaryNode(NodeKind::yieldExprNode, sourcePos_, child_)
{
}

void YieldExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ThrowExprNode::ThrowExprNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::throwExprNode, sourcePos_)
{
}

ThrowExprNode::ThrowExprNode(const SourcePos& sourcePos_, Node* exception_) : CompoundNode(NodeKind::throwExprNode, sourcePos_), exception(exception_)
{
}

void ThrowExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ThrowExprNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(exception.get());
}

void ThrowExprNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    exception.reset(reader.ReadNode());
}

ConditionalExprNode::ConditionalExprNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::conditionalExprNode, sourcePos_)
{
}

ConditionalExprNode::ConditionalExprNode(const SourcePos& sourcePos_, Node* condition_, Node* quest_, Node* thenExpr_, Node* colon_, Node* elseExpr_) :
    CompoundNode(NodeKind::conditionalExprNode, sourcePos_), condition(condition_), quest(quest_), thenExpr(thenExpr_), colon(colon_), elseExpr(elseExpr_)
{
}

void ConditionalExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ConditionalExprNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(condition.get());
    writer.Write(quest.get());
    writer.Write(thenExpr.get());
    writer.Write(colon.get());
    writer.Write(elseExpr.get());
}

void ConditionalExprNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    condition.reset(reader.ReadNode());
    quest.reset(reader.ReadNode());
    thenExpr.reset(reader.ReadNode());
    colon.reset(reader.ReadNode());
    elseExpr.reset(reader.ReadNode());
}

CommaNode::CommaNode(const SourcePos& sourcePos_) : Node(NodeKind::commaNode, sourcePos_)
{
}

void CommaNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AssignNode::AssignNode(const SourcePos& sourcePos_) : Node(NodeKind::assignNode, sourcePos_)
{
}

void AssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PlusAssignNode::PlusAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::plusAssignNode, sourcePos_)
{
}

void PlusAssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MinusAssignNode::MinusAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::minusAssignNode, sourcePos_)
{
}

void MinusAssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MulAssignNode::MulAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::mulAssignNode, sourcePos_)
{
}

void MulAssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DivAssignNode::DivAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::divAssignNode, sourcePos_)
{
}

void DivAssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ModAssignNode::ModAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::modAssignNode, sourcePos_)
{
}

void ModAssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

XorAssignNode::XorAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::xorAssignNode, sourcePos_)
{
}

void XorAssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AndAssignNode::AndAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::andAssignNode, sourcePos_)
{
}

void AndAssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

OrAssignNode::OrAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::orAssignNode, sourcePos_)
{
}

void OrAssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ShiftLeftAssignNode::ShiftLeftAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::shiftLeftAssignNode, sourcePos_)
{
}

void ShiftLeftAssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ShiftRightAssignNode::ShiftRightAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::shiftRightAssignNode, sourcePos_)
{
}

void ShiftRightAssignNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

QuestNode::QuestNode(const SourcePos& sourcePos_) : Node(NodeKind::questNode, sourcePos_)
{
}

void QuestNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ColonNode::ColonNode(const SourcePos& sourcePos_) : Node(NodeKind::colonNode, sourcePos_)
{
}

void ColonNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DisjunctionNode::DisjunctionNode(const SourcePos& sourcePos_) : Node(NodeKind::disjunctionNode, sourcePos_)
{
}

void DisjunctionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ConjunctionNode::ConjunctionNode(const SourcePos& sourcePos_) : Node(NodeKind::conjunctionNode, sourcePos_)
{
}

void ConjunctionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

InclusiveOrNode::InclusiveOrNode(const SourcePos& sourcePos_) : Node(NodeKind::inclusiveOrNode, sourcePos_)
{
}

void InclusiveOrNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExclusiveOrNode::ExclusiveOrNode(const SourcePos& sourcePos_) : Node(NodeKind::exclusiveOrNode, sourcePos_)
{
}

void ExclusiveOrNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AndNode::AndNode(const SourcePos& sourcePos_) : Node(NodeKind::andNode, sourcePos_)
{
}

void AndNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

EqualNode::EqualNode(const SourcePos& sourcePos_) : Node(NodeKind::equalNode, sourcePos_)
{
}

void EqualNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

NotEqualNode::NotEqualNode(const SourcePos& sourcePos_) : Node(NodeKind::notEqualNode, sourcePos_)
{
}

void NotEqualNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LessNode::LessNode(const SourcePos& sourcePos_) : Node(NodeKind::lessNode, sourcePos_)
{
}

void LessNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

GreaterNode::GreaterNode(const SourcePos& sourcePos_) : Node(NodeKind::greaterNode, sourcePos_)
{
}

void GreaterNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LessOrEqualNode::LessOrEqualNode(const SourcePos& sourcePos_) : Node(NodeKind::lessOrEqualNode, sourcePos_)
{
}

void LessOrEqualNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

GreaterOrEqualNode::GreaterOrEqualNode(const SourcePos& sourcePos_) : Node(NodeKind::greaterOrEqualNode, sourcePos_)
{
}

void GreaterOrEqualNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CompareNode::CompareNode(const SourcePos& sourcePos_) : Node(NodeKind::compareNode, sourcePos_)
{
}

void CompareNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ShiftLeftNode::ShiftLeftNode(const SourcePos& sourcePos_) : Node(NodeKind::shiftLeftNode, sourcePos_)
{
}

void ShiftLeftNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ShiftRightNode::ShiftRightNode(const SourcePos& sourcePos_) : Node(NodeKind::shiftRightNode, sourcePos_)
{
}

void ShiftRightNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PlusNode::PlusNode(const SourcePos& sourcePos_) : Node(NodeKind::plusNode, sourcePos_)
{
}

void PlusNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MinusNode::MinusNode(const SourcePos& sourcePos_) : Node(NodeKind::minusNode, sourcePos_)
{
}

void MinusNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MulNode::MulNode(const SourcePos& sourcePos_) : Node(NodeKind::mulNode, sourcePos_)
{
}

void MulNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DivNode::DivNode(const SourcePos& sourcePos_) : Node(NodeKind::divNode, sourcePos_)
{
}

void DivNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ModNode::ModNode(const SourcePos& sourcePos_) : Node(NodeKind::modNode, sourcePos_)
{
}

void ModNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DotStarNode::DotStarNode(const SourcePos& sourcePos_) : Node(NodeKind::dotStarNode, sourcePos_)
{
}

void DotStarNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ArrowStarNode::ArrowStarNode(const SourcePos& sourcePos_) : Node(NodeKind::arrowStarNode, sourcePos_)
{
}

void ArrowStarNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CastExprNode::CastExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::castExprNode, sourcePos_, nullptr)
{
}

CastExprNode::CastExprNode(const SourcePos& sourcePos_, Node* typeId_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::castExprNode, sourcePos_, child_), typeId(typeId_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void CastExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CastExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(typeId.get());
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void CastExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    typeId.reset(reader.ReadNode());
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

DerefNode::DerefNode(const SourcePos& sourcePos_) : Node(NodeKind::derefNode, sourcePos_)
{
}

void DerefNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AddrOfNode::AddrOfNode(const SourcePos& sourcePos_) : Node(NodeKind::addrOfNode, sourcePos_)
{
}

void AddrOfNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

NotNode::NotNode(const SourcePos& sourcePos_) : Node(NodeKind::notNode, sourcePos_)
{
}

void NotNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ComplementNode::ComplementNode(const SourcePos& sourcePos_) : Node(NodeKind::complementNode, sourcePos_)
{
}

void ComplementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PrefixIncNode::PrefixIncNode(const SourcePos& sourcePos_) : Node(NodeKind::prefixIncNode, sourcePos_)
{
}

void PrefixIncNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PrefixDecNode::PrefixDecNode(const SourcePos& sourcePos_) : Node(NodeKind::prefixDecNode, sourcePos_)
{
}

void PrefixDecNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AwaitExprNode::AwaitExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::awaitExprNode, sourcePos_, nullptr)
{
}

AwaitExprNode::AwaitExprNode(const SourcePos& sourcePos_, Node* child_) : UnaryNode(NodeKind::awaitExprNode, sourcePos_, child_)
{
}

void AwaitExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

SizeOfTypeExprNode::SizeOfTypeExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::sizeOfTypeExprNode, sourcePos_, nullptr)
{
}

SizeOfTypeExprNode::SizeOfTypeExprNode(const SourcePos& sourcePos_, Node* typeId_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::sizeOfTypeExprNode, sourcePos_, typeId_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void SizeOfTypeExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SizeOfTypeExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void SizeOfTypeExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

SizeOfPackExprNode::SizeOfPackExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::sizeOfPackExpNode, sourcePos_, nullptr)
{
}

SizeOfPackExprNode::SizeOfPackExprNode(const SourcePos& sourcePos_, Node* idNode_, const SourcePos& ellipsisPos_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    UnaryNode(NodeKind::sizeOfPackExpNode, sourcePos_, idNode_), ellipsisPos(ellipsisPos_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void SizeOfPackExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SizeOfPackExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(ellipsisPos);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void SizeOfPackExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    ellipsisPos = reader.ReadSourcePos();
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

SizeOfUnaryExprNode::SizeOfUnaryExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::sizeOfUnaryExprNode, sourcePos_, nullptr)
{
}

SizeOfUnaryExprNode::SizeOfUnaryExprNode(const SourcePos& sourcePos_, Node* child_) : 
    UnaryNode(NodeKind::sizeOfUnaryExprNode, sourcePos_, child_)
{
}

void SizeOfUnaryExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AlignOfExprNode::AlignOfExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::alignOfExprNode, sourcePos_, nullptr)
{
}

AlignOfExprNode::AlignOfExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::alignOfExprNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void AlignOfExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void AlignOfExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void AlignOfExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

NoexceptExprNode::NoexceptExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::noexceptExprNode, sourcePos_, nullptr)
{
}

NoexceptExprNode::NoexceptExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::noexceptExprNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void NoexceptExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NoexceptExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void NoexceptExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

NewExprNode::NewExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::newExprNode, sourcePos_, nullptr)
{
}

NewExprNode::NewExprNode(const SourcePos& sourcePos_, Node* placement_, Node* child_, Node* initializer_, Node* colonColonHead_, const SourcePos& newPos_) :
    UnaryNode(NodeKind::newExprNode, sourcePos_, child_), placement(placement_), initializer(initializer_), colonColonHead(colonColonHead_), newPos(newPos_)
{
}

void NewExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NewExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(colonColonHead.get());
    writer.Write(placement.get());
    writer.Write(initializer.get());
    writer.Write(newPos);
}

void NewExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    colonColonHead.reset(reader.ReadNode());
    placement.reset(reader.ReadNode());
    initializer.reset(reader.ReadNode());
    newPos = reader.ReadSourcePos();
}

NewPlacementNode::NewPlacementNode(const SourcePos& sourcePos_) : ListNode(NodeKind::newPlacementNode, sourcePos_)
{
}

void NewPlacementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NewPlacementNode::Write(Writer& writer)
{
    ListNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void NewPlacementNode::Read(Reader& reader)
{
    ListNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

ParenNewTypeIdNode::ParenNewTypeIdNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::parenNewTypeIdNode, sourcePos_, nullptr)
{
}

ParenNewTypeIdNode::ParenNewTypeIdNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::parenNewTypeIdNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void ParenNewTypeIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ParenNewTypeIdNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void ParenNewTypeIdNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

NewTypeIdNode::NewTypeIdNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::newTypeIdNode, sourcePos_)
{
}

NewTypeIdNode::NewTypeIdNode(const SourcePos& sourcePos_, Node* typeSpecifierSeq_, Node* newDeclarator_) : CompoundNode(NodeKind::newTypeIdNode, sourcePos_), typeSpecifierSeq(typeSpecifierSeq_), newDeclarator(newDeclarator_)
{
}

void NewTypeIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NewTypeIdNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(typeSpecifierSeq.get());
    writer.Write(newDeclarator.get());
}

void NewTypeIdNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    typeSpecifierSeq.reset(reader.ReadNode());
    newDeclarator.reset(reader.ReadNode());
}

ArrayDeletePtrNode::ArrayDeletePtrNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::arrayDeletePtrNode, sourcePos_, nullptr)
{
}

ArrayDeletePtrNode::ArrayDeletePtrNode(const SourcePos& sourcePos_, Node* ptr_, Node* colonColonHead_, const SourcePos& deletePos_, const SourcePos& lbPos_, const SourcePos& rbPos_) :
    UnaryNode(NodeKind::arrayDeletePtrNode, sourcePos_, ptr_), colonColonHead(colonColonHead_), deletePos(deletePos_), lbPos(lbPos_), rbPos(rbPos_)
{
}

void ArrayDeletePtrNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ArrayDeletePtrNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(colonColonHead.get());
    writer.Write(deletePos);
    writer.Write(lbPos);
    writer.Write(rbPos);
}

void ArrayDeletePtrNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    colonColonHead.reset(reader.ReadNode());
    deletePos = reader.ReadSourcePos();
    lbPos = reader.ReadSourcePos();
    rbPos = reader.ReadSourcePos();
}

DeletePtrNode::DeletePtrNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::deletePtrNode, sourcePos_, nullptr)
{
}

DeletePtrNode::DeletePtrNode(const SourcePos& sourcePos_, Node* ptr_, Node* colonColonHead_, const SourcePos& deletePos_) : 
    UnaryNode(NodeKind::deletePtrNode, sourcePos_, ptr_), colonColonHead(colonColonHead_), deletePos(deletePos_)
{
}

void DeletePtrNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void DeletePtrNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(colonColonHead.get());
    writer.Write(deletePos);
}

void DeletePtrNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    colonColonHead.reset(reader.ReadNode());
    deletePos = reader.ReadSourcePos();
}

SubscriptExprNode::SubscriptExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::subscriptExprNode, sourcePos_, nullptr)
{
}

SubscriptExprNode::SubscriptExprNode(const SourcePos& sourcePos_, Node* child_, Node* index_, const SourcePos& lbPos_, const SourcePos& rbPos_) : 
    UnaryNode(NodeKind::subscriptExprNode, sourcePos_, child_), index(index_), lbPos(lbPos_), rbPos(rbPos_)
{
}

void SubscriptExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SubscriptExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(index.get());
    writer.Write(lbPos);
    writer.Write(rbPos);
}

void SubscriptExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    index.reset(reader.ReadNode());
    lbPos = reader.ReadSourcePos();
    rbPos = reader.ReadSourcePos();
}

InvokeExprNode::InvokeExprNode(const SourcePos& sourcePos_) : ListNode(NodeKind::invokeExprNode, sourcePos_)
{
}

InvokeExprNode::InvokeExprNode(const SourcePos& sourcePos_, Node* subject_) : ListNode(NodeKind::invokeExprNode, sourcePos_), subject(subject_)
{
}

void InvokeExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void InvokeExprNode::Write(Writer& writer)
{
    ListNode::Write(writer);
    writer.Write(subject.get());
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void InvokeExprNode::Read(Reader& reader)
{
    ListNode::Read(reader);
    subject.reset(reader.ReadNode());
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

PairNode::PairNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::pairNode, sourcePos_, nullptr, nullptr)
{
}

PairNode::PairNode(const SourcePos& sourcePos_, Node* left_, Node* right_) : BinaryNode(NodeKind::pairNode, sourcePos_, left_, right_)
{
}

void PairNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ArrowNode::ArrowNode(const SourcePos& sourcePos_) : Node(NodeKind::arrowNode, sourcePos_)
{
}

void ArrowNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MemberExprNode::MemberExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::memberExprNode, sourcePos_, nullptr)
{
}

MemberExprNode::MemberExprNode(const SourcePos& sourcePos_, Node* child_, Node* op_, Node* id_) : UnaryNode(NodeKind::memberExprNode, sourcePos_, child_), op(op_), id(id_)
{
}

void MemberExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void MemberExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(op.get());
    writer.Write(id.get());
}

void MemberExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    op.reset(reader.ReadNode());
    id.reset(reader.ReadNode());
}

PostfixIncExprNode::PostfixIncExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::postfixIncExprNode, sourcePos_, nullptr)
{
}

PostfixIncExprNode::PostfixIncExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& opPos_) : UnaryNode(NodeKind::postfixIncExprNode, sourcePos_, child_), opPos(opPos_)
{
}

void PostfixIncExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void PostfixIncExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(opPos);
}

void PostfixIncExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    opPos = reader.ReadSourcePos();
}

PostfixDecExprNode::PostfixDecExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::postfixDecExprNode, sourcePos_, nullptr)
{
}

PostfixDecExprNode::PostfixDecExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& opPos_) : UnaryNode(NodeKind::postfixDecExprNode, sourcePos_, child_), opPos(opPos_)
{
}

void PostfixDecExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void PostfixDecExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(opPos);
}

void PostfixDecExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    opPos = reader.ReadSourcePos();
}

TypeIdExprNode::TypeIdExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::typeIdExprNode, sourcePos_, nullptr)
{
}

TypeIdExprNode::TypeIdExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::typeIdExprNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void TypeIdExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TypeIdExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void TypeIdExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

DynamicCastNode::DynamicCastNode(const SourcePos& sourcePos_) : Node(NodeKind::dynamicCastNode, sourcePos_)
{
}

void DynamicCastNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

StaticCastNode::StaticCastNode(const SourcePos& sourcePos_) : Node(NodeKind::staticCastNode, sourcePos_)
{
}

void StaticCastNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ReinterpretCastNode::ReinterpretCastNode(const SourcePos& sourcePos_) : Node(NodeKind::reinterpretCastNode, sourcePos_)
{
}

void ReinterpretCastNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ConstCastNode::ConstCastNode(const SourcePos& sourcePos_) : Node(NodeKind::constCastNode, sourcePos_)
{
}

void ConstCastNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CppCastExprNode::CppCastExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::cppCastExprNode, sourcePos_, nullptr)
{
}

CppCastExprNode::CppCastExprNode(const SourcePos& sourcePos_, Node* typeId_, Node* child_, Node* op_, const SourcePos& laPos_, const SourcePos& raPos_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::cppCastExprNode, sourcePos_, child_), typeId(typeId_), op(op_), laPos(laPos_), raPos(raPos_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void CppCastExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CppCastExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(typeId.get());
    writer.Write(op.get());
    writer.Write(laPos);
    writer.Write(raPos);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void CppCastExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    typeId.reset(reader.ReadNode());
    op.reset(reader.ReadNode());
    laPos = reader.ReadSourcePos();
    raPos = reader.ReadSourcePos();
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

ThisNode::ThisNode(const SourcePos& sourcePos_) : Node(NodeKind::thisNode, sourcePos_)
{
}

void ThisNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ParenthesizedExprNode::ParenthesizedExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::parenExprNode, sourcePos_, nullptr)
{
}

ParenthesizedExprNode::ParenthesizedExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::parenExprNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

void ParenthesizedExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ParenthesizedExprNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void ParenthesizedExprNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

FoldExprNode::FoldExprNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::foldExprNode, sourcePos_)
{
}

void FoldExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void FoldExprNode::Write(Writer& writer)
{
    SequenceNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void FoldExprNode::Read(Reader& reader)
{
    SequenceNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

NewDeclaratorNode::NewDeclaratorNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::newDeclaratorNode, sourcePos_)
{
}

void NewDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ArrayNewDeclaratorNode::ArrayNewDeclaratorNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::arrayNewDeclaratorNode, sourcePos_)
{
}

void ArrayNewDeclaratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

NewInitializerNode::NewInitializerNode(const SourcePos& sourcePos_) : ListNode(NodeKind::newInitializerNode, sourcePos_)
{
}

void NewInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NewInitializerNode::Write(Writer& writer)
{
    ListNode::Write(writer);
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void NewInitializerNode::Read(Reader& reader)
{
    ListNode::Read(reader);
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

BracedInitListNode::BracedInitListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::bracedInitListNode, sourcePos_)
{
}

void BracedInitListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DesignatedInitializerNode::DesignatedInitializerNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::designatedInitializerNode, sourcePos_, nullptr, nullptr)
{
}

DesignatedInitializerNode::DesignatedInitializerNode(const SourcePos& sourcePos_, Node* designator_, Node* initializer_) : 
    BinaryNode(NodeKind::designatedInitializerNode, sourcePos_, designator_, initializer_)
{
}

void DesignatedInitializerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DesignatorNode::DesignatorNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::designatorNode, sourcePos_, nullptr)
{
}

DesignatorNode::DesignatorNode(const SourcePos& sourcePos_, Node* identifier_) : UnaryNode(NodeKind::designatorNode, sourcePos_, identifier_)
{
}

void DesignatorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

EllipsisNode::EllipsisNode(const SourcePos& sourcePos_) : Node(NodeKind::EllipsisNode, sourcePos_)
{
}

void EllipsisNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} // sngcpp::ast
