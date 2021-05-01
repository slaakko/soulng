// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Expression.hpp>

namespace sngcpp::ast {

BinaryExprNode::BinaryExprNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::binaryExprNode, sourcePos_, nullptr, nullptr)
{
}

BinaryExprNode::BinaryExprNode(const SourcePos& sourcePos_, Node* op_, Node* left_, Node* right_) :
    BinaryNode(NodeKind::binaryExprNode, sourcePos_, left_, right_), op(op_)
{
}

UnaryExprNode::UnaryExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::unaryExprNode, sourcePos_, nullptr)
{
}

UnaryExprNode::UnaryExprNode(const SourcePos& sourcePos_, Node* op_, Node* child_) : UnaryNode(NodeKind::unaryExprNode, sourcePos_, child_), op(op_)
{
}

ExpressionListNode::ExpressionListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::expressionListNode, sourcePos_)
{
}

AssignmentInitNode::AssignmentInitNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::assignmentInitializerNode, sourcePos_, nullptr)
{
}

AssignmentInitNode::AssignmentInitNode(const SourcePos& sourcePos_, Node* initializer_) : UnaryNode(NodeKind::assignmentInitializerNode, sourcePos_, initializer_)
{
}

YieldExprNode::YieldExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::yieldExprNode, sourcePos_, nullptr)
{
}

YieldExprNode::YieldExprNode(const SourcePos& sourcePos_, Node* child_) : UnaryNode(NodeKind::yieldExprNode, sourcePos_, child_)
{
}

ThrowExprNode::ThrowExprNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::throwExprNode, sourcePos_)
{
}

ThrowExprNode::ThrowExprNode(const SourcePos& sourcePos_, Node* exception_) : CompoundNode(NodeKind::throwExprNode, sourcePos_)
{
}

ConditionalExprNode::ConditionalExprNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::conditionalExprNode, sourcePos_)
{
}

ConditionalExprNode::ConditionalExprNode(const SourcePos& sourcePos_, Node* condition_, Node* quest_, Node* thenExpr_, Node* colon_, Node* elseExpr_) :
    CompoundNode(NodeKind::conditionalExprNode, sourcePos_), condition(condition_), quest(quest_), thenExpr(thenExpr_), colon(colon_), elseExpr(elseExpr_)
{
}

ColonNode::ColonNode(const SourcePos& sourcePos_) : Node(NodeKind::colonNode, sourcePos_)
{
}

CommaNode::CommaNode(const SourcePos& sourcePos_) : Node(NodeKind::commaNode, sourcePos_)
{
}

AssignNode::AssignNode(const SourcePos& sourcePos_) : Node(NodeKind::assignNode, sourcePos_)
{
}

PlusAssignNode::PlusAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::plusAssignNode, sourcePos_)
{
}

MinusAssignNode::MinusAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::minusAssignNode, sourcePos_)
{
}

MulAssignNode::MulAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::mulAssignNode, sourcePos_)
{
}

DivAssignNode::DivAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::divAssignNode, sourcePos_)
{
}

ModAssignNode::ModAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::modAssignNode, sourcePos_)
{
}

XorAssignNode::XorAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::xorAssignNode, sourcePos_)
{
}

AndAssignNode::AndAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::andAssignNode, sourcePos_)
{
}

OrAssignNode::OrAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::orAssignNode, sourcePos_)
{
}

ShiftLeftAssignNode::ShiftLeftAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::shiftLeftAssignNode, sourcePos_)
{
}

ShiftRightAssignNode::ShiftRightAssignNode(const SourcePos& sourcePos_) : Node(NodeKind::shiftRightAssignNode, sourcePos_)
{
}

QuestNode::QuestNode(const SourcePos& sourcePos_) : Node(NodeKind::questNode, sourcePos_)
{
}

DisjunctionNode::DisjunctionNode(const SourcePos& sourcePos_) : Node(NodeKind::disjunctionNode, sourcePos_)
{
}

ConjunctionNode::ConjunctionNode(const SourcePos& sourcePos_) : Node(NodeKind::conjunctionNode, sourcePos_)
{
}

InclusiveOrNode::InclusiveOrNode(const SourcePos& sourcePos_) : Node(NodeKind::inclusiveOrNode, sourcePos_)
{
}

ExclusiveOrNode::ExclusiveOrNode(const SourcePos& sourcePos_) : Node(NodeKind::exclusiveOrNode, sourcePos_)
{
}

AndNode::AndNode(const SourcePos& sourcePos_) : Node(NodeKind::andNode, sourcePos_)
{
}

EqualNode::EqualNode(const SourcePos& sourcePos_) : Node(NodeKind::equalNode, sourcePos_)
{
}

NotEqualNode::NotEqualNode(const SourcePos& sourcePos_) : Node(NodeKind::notEqualNode, sourcePos_)
{
}

LessNode::LessNode(const SourcePos& sourcePos_) : Node(NodeKind::lessNode, sourcePos_)
{
}

GreaterNode::GreaterNode(const SourcePos& sourcePos_) : Node(NodeKind::greaterNode, sourcePos_)
{
}

LessOrEqualNode::LessOrEqualNode(const SourcePos& sourcePos_) : Node(NodeKind::lessOrEqualNode, sourcePos_)
{
}

GreaterOrEqualNode::GreaterOrEqualNode(const SourcePos& sourcePos_) : Node(NodeKind::greaterOrEqualNode, sourcePos_)
{
}

CompareNode::CompareNode(const SourcePos& sourcePos_) : Node(NodeKind::compareNode, sourcePos_)
{
}

ShiftLeftNode::ShiftLeftNode(const SourcePos& sourcePos_) : Node(NodeKind::shiftLeftNode, sourcePos_)
{
}

ShiftRightNode::ShiftRightNode(const SourcePos& sourcePos_) : Node(NodeKind::shiftRightNode, sourcePos_)
{
}

PlusNode::PlusNode(const SourcePos& sourcePos_) : Node(NodeKind::plusNode, sourcePos_)
{
}

MinusNode::MinusNode(const SourcePos& sourcePos_) : Node(NodeKind::minusNode, sourcePos_)
{
}

MulNode::MulNode(const SourcePos& sourcePos_) : Node(NodeKind::mulNode, sourcePos_)
{
}

DivNode::DivNode(const SourcePos& sourcePos_) : Node(NodeKind::divNode, sourcePos_)
{
}

ModNode::ModNode(const SourcePos& sourcePos_) : Node(NodeKind::modNode, sourcePos_)
{
}

DotStarNode::DotStarNode(const SourcePos& sourcePos_) : Node(NodeKind::dotStarNode, sourcePos_)
{
}

ArrowStarNode::ArrowStarNode(const SourcePos& sourcePos_) : Node(NodeKind::arrowStarNode, sourcePos_)
{
}

CastExprNode::CastExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::castExprNode, sourcePos_, nullptr)
{
}

CastExprNode::CastExprNode(const SourcePos& sourcePos_, Node* typeId_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::castExprNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

DerefNode::DerefNode(const SourcePos& sourcePos_) : Node(NodeKind::derefNode, sourcePos_)
{
}

AddrOfNode::AddrOfNode(const SourcePos& sourcePos_) : Node(NodeKind::addrOfNode, sourcePos_)
{
}

NotNode::NotNode(const SourcePos& sourcePos_) : Node(NodeKind::notNode, sourcePos_)
{
}

ComplementNode::ComplementNode(const SourcePos& sourcePos_) : Node(NodeKind::complementNode, sourcePos_)
{
}

PrefixIncNode::PrefixIncNode(const SourcePos& sourcePos_) : Node(NodeKind::prefixIncNode, sourcePos_)
{
}

PrefixDecNode::PrefixDecNode(const SourcePos& sourcePos_) : Node(NodeKind::prefixDecNode, sourcePos_)
{
}

AwaitExprNode::AwaitExprNode(const SourcePos& sourcePos_, Node* child_) : UnaryNode(NodeKind::awaitExprNode, sourcePos_, child_)
{
}

SizeOfTypeExprNode::SizeOfTypeExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::sizeOfTypeExprNode, sourcePos_, nullptr)
{
}

SizeOfTypeExprNode::SizeOfTypeExprNode(const SourcePos& sourcePos_, Node* typeId_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::sizeOfTypeExprNode, sourcePos_, typeId_), lpPos(lpPos_), rpPos(rpPos_)
{
}

SizeOfPackExprNode::SizeOfPackExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::sizeOfPackExpNode, sourcePos_, nullptr)
{
}

SizeOfPackExprNode::SizeOfPackExprNode(const SourcePos& sourcePos_, Node* idNode_, const SourcePos& ellipsesPos_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    UnaryNode(NodeKind::sizeOfPackExpNode, sourcePos_, idNode_), ellipsesPos(ellipsesPos_), lpPos(lpPos_), rpPos(rpPos_)
{
}

SizeOfUnaryExprNode::SizeOfUnaryExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::sizeOfUnaryExprNode, sourcePos_, nullptr)
{
}

SizeOfUnaryExprNode::SizeOfUnaryExprNode(const SourcePos& sourcePos_, Node* child_) : 
    UnaryNode(NodeKind::sizeOfUnaryExprNode, sourcePos_, child_)
{
}

AlignOfExprNode::AlignOfExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::alignOfExprNode, sourcePos_, nullptr)
{
}

AlignOfExprNode::AlignOfExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::alignOfExprNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

NoexceptExprNode::NoexceptExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::noexceptExprNode, sourcePos_, nullptr)
{
}

NoexceptExprNode::NoexceptExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::noexceptExprNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

NewExprNode::NewExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::newExprNode, sourcePos_, nullptr)
{
}

NewExprNode::NewExprNode(const SourcePos& sourcePos_, Node* placement_, Node* child_, Node* initializer_, Node* colonColonHead_) :
    UnaryNode(NodeKind::newExprNode, sourcePos_, child_), placement(placement_), initializer(initializer_), colonColonHead(colonColonHead_)
{
}

NewPlacementNode::NewPlacementNode(const SourcePos& sourcePos_) : ListNode(NodeKind::newPlacementNode, sourcePos_)
{
}

ParenNewTypeIdNode::ParenNewTypeIdNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::parenNewTypeIdNode, sourcePos_, nullptr)
{
}

ParenNewTypeIdNode::ParenNewTypeIdNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::parenNewTypeIdNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

NewTypeIdNode::NewTypeIdNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::newTypeIdNode, sourcePos_)
{
}

NewTypeIdNode::NewTypeIdNode(const SourcePos& sourcePos_, Node* typeSpecifierSeq_, Node* newDeclarator_) : CompoundNode(NodeKind::newTypeIdNode, sourcePos_), typeSpecifierSeq(typeSpecifierSeq_), newDeclarator(newDeclarator_)
{
}

ArrayDeletePtrNode::ArrayDeletePtrNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::arrayDeletePtrNode, sourcePos_, nullptr)
{
}

ArrayDeletePtrNode::ArrayDeletePtrNode(const SourcePos& sourcePos_, Node* ptr_, const SourcePos& lbPos_, const SourcePos& rbPos_) : 
    UnaryNode(NodeKind::arrayDeletePtrNode, sourcePos_, ptr_), lbPos(lbPos_), rbPos(rbPos_)
{
}

DeletePtrNode::DeletePtrNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::deletePtrNode, sourcePos_, nullptr)
{
}


DeletePtrNode::DeletePtrNode(const SourcePos& sourcePos_, Node* ptr_) : UnaryNode(NodeKind::deletePtrNode, sourcePos_, ptr_)
{
}

SubscriptExprNode::SubscriptExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::subscriptExprNode, sourcePos_, nullptr)
{
}

SubscriptExprNode::SubscriptExprNode(const SourcePos& sourcePos_, Node* child_, Node* index_, const SourcePos& lbPos_, const SourcePos& rbPos_) : 
    UnaryNode(NodeKind::subscriptExprNode, sourcePos_, child_), index(index_), lbPos(lbPos_), rbPos(rbPos_)
{
}

InvokeExprNode::InvokeExprNode(const SourcePos& sourcePos_) : ListNode(NodeKind::invokeExprNode, sourcePos_)
{
}

InvokeExprNode::InvokeExprNode(const SourcePos& sourcePos_, Node* subject_) : ListNode(NodeKind::invokeExprNode, sourcePos_), subject(subject_)
{
}

PairNode::PairNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::pairNode, sourcePos_, nullptr, nullptr)
{
}

PairNode::PairNode(const SourcePos& sourcePos_, Node* left_, Node* right_) : BinaryNode(NodeKind::pairNode, sourcePos_, left_, right_)
{
}

ArrowNode::ArrowNode(const SourcePos& sourcePos_) : Node(NodeKind::arrowNode, sourcePos_)
{
}

MemberExprNode::MemberExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::memberExprNode, sourcePos_, nullptr)
{
}

MemberExprNode::MemberExprNode(const SourcePos& sourcePos_, Node* child_, Node* op_, Node* id_) : UnaryNode(NodeKind::memberExprNode, sourcePos_, child_), op(op_), id(id_)
{
}

PostfixIncExprNode::PostfixIncExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::postfixIncExprNode, sourcePos_, nullptr)
{
}

PostfixIncExprNode::PostfixIncExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& opPos_) : UnaryNode(NodeKind::postfixIncExprNode, sourcePos_, child_), opPos(opPos_)
{
}

PostfixDecExprNode::PostfixDecExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::postfixDecExprNode, sourcePos_, nullptr)
{
}

PostfixDecExprNode::PostfixDecExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& opPos_) : UnaryNode(NodeKind::postfixDecExprNode, sourcePos_, child_), opPos(opPos_)
{
}

TypeIdExprNode::TypeIdExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::typeIdExprNode, sourcePos_, nullptr)
{
}

TypeIdExprNode::TypeIdExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::typeIdExprNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

DynamicCastNode::DynamicCastNode(const SourcePos& sourcePos_) : Node(NodeKind::dynamicCastNode, sourcePos_)
{
}

StaticCastNode::StaticCastNode(const SourcePos& sourcePos_) : Node(NodeKind::staticCastNode, sourcePos_)
{
}

ReinterpretCastNode::ReinterpretCastNode(const SourcePos& sourcePos_) : Node(NodeKind::reinterpretCastNode, sourcePos_)
{
}

ConstCastNode::ConstCastNode(const SourcePos& sourcePos_) : Node(NodeKind::constCastNode, sourcePos_)
{
}

CppCastExprNode::CppCastExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::cppCastExprNode, sourcePos_, nullptr)
{
}

CppCastExprNode::CppCastExprNode(const SourcePos& sourcePos_, Node* typeId_, Node* child_, Node* op_, const SourcePos& laPos_, const SourcePos& raPos_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::cppCastExprNode, sourcePos_, child_), typeId(typeId_), op(op_), laPos(laPos_), raPos(raPos_), lpPos(lpPos_), rpPos(rpPos_)
{
}

ThisNode::ThisNode(const SourcePos& sourcePos_) : Node(NodeKind::thisNode, sourcePos_)
{
}

ParenthesizedExprNode::ParenthesizedExprNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::parenExprNode, sourcePos_, nullptr)
{
}

ParenthesizedExprNode::ParenthesizedExprNode(const SourcePos& sourcePos_, Node* child_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    UnaryNode(NodeKind::parenExprNode, sourcePos_, child_), lpPos(lpPos_), rpPos(rpPos_)
{
}

FoldExprNode::FoldExprNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::foldExprNode, sourcePos_)
{
}

NewDeclaratorNode::NewDeclaratorNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::newDeclaratorNode, sourcePos_)
{
}

ArrayNewDeclaratorNode::ArrayNewDeclaratorNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::arrayNewDeclaratorNode, sourcePos_)
{
}

NewInitializerNode::NewInitializerNode(const SourcePos& sourcePos_) : ListNode(NodeKind::newInitializerNode, sourcePos_)
{
}

BracedInitListNode::BracedInitListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::bracedInitListNode, sourcePos_)
{
}

DesignatedInitializerNode::DesignatedInitializerNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::designatedInitializerNode, sourcePos_, nullptr, nullptr)
{
}

DesignatedInitializerNode::DesignatedInitializerNode(const SourcePos& sourcePos_, Node* designator_, Node* initializer_) : 
    BinaryNode(NodeKind::designatedInitializerNode, sourcePos_, designator_, initializer_)
{
}

DesignatorNode::DesignatorNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::designatorNode, sourcePos_, nullptr)
{
}

DesignatorNode::DesignatorNode(const SourcePos& sourcePos_, Node* identifier_) : UnaryNode(NodeKind::designatorNode, sourcePos_, identifier_)
{
}

EllipsesNode::EllipsesNode(const SourcePos& sourcePos_) : Node(NodeKind::ellipsesNode, sourcePos_)
{
}

} // sngcpp::ast
