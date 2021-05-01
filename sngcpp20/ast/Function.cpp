// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Function.hpp>
#include <stdexcept>

namespace sngcpp::ast {

FunctionDefinitionNode::FunctionDefinitionNode(const SourcePos& sourcePos_, Node* attributes_, Node* declSpecifiers_, Node* declarator_, Node* specifiers_, Node* functionBody_) :
    CompoundNode(NodeKind::functionDefinitionNode, sourcePos_), attributes(attributes_), declSpecifiers(declSpecifiers_), declarator(declarator_), specifiers(specifiers_), functionBody(functionBody_)
{
}

FunctionBodyNode::FunctionBodyNode(const SourcePos& sourcePos_, Node* compoundStatement_) : UnaryNode(NodeKind::functionBodyNode, sourcePos_, compoundStatement_)
{
}

GeneratedFunctionBodyNode::GeneratedFunctionBodyNode(const SourcePos& sourcePos_, Node* assign_, Node* gen_, Node* semicolon_) : 
    CompoundNode(NodeKind::generatedFunctionBodyNode, sourcePos_), assign(assign_), gen(gen_), semicolon(semicolon_)
{
}

FunctionDeclarationNode::FunctionDeclarationNode(const SourcePos& sourcePos_, Node* declarator_, Node* attributes_, Node* semicolon_) :
    CompoundNode(NodeKind::functionDeclarationNode, sourcePos_), declarator(declarator_), attributes(attributes_), semicolon(semicolon_)
{
}

DefaultNode::DefaultNode(const SourcePos& sourcePos_) : Node(NodeKind::defaultNode, sourcePos_)
{
}

DeleteNode::DeleteNode(const SourcePos& sourcePos_) : Node(NodeKind::deleteNode, sourcePos_)
{

}

OperatorNode::OperatorNode(const SourcePos& sourcePos_) : Node(NodeKind::operatorNode, sourcePos_)
{
}

NewArrayOpNode::NewArrayOpNode(const SourcePos& sourcePos_, const SourcePos& lbPos_, const SourcePos& rbPos_) :
    CompoundNode(NodeKind::newArrayOpNode, sourcePos_), lbPos(lbPos_), rbPos(rbPos_)
{
}

NewOpNode::NewOpNode(const SourcePos& sourcePos_) : Node(NodeKind::newOpNode, sourcePos_)
{
}

DeleteArrayOpNode::DeleteArrayOpNode(const SourcePos& sourcePos_, const SourcePos& lbPos_, const SourcePos& rbPos_) : 
    CompoundNode(NodeKind::deleteArrayOpNode, sourcePos_)
{
}

DeleteOpNode::DeleteOpNode(const SourcePos& sourcePos_) : Node(NodeKind::deleteOpNode, sourcePos_)
{
}

CoAwaitOpNode::CoAwaitOpNode(const SourcePos& sourcePos_) : Node(NodeKind::coAwaitOpNode, sourcePos_)
{
}

InvokeOpNode::InvokeOpNode(const SourcePos& sourcePos_) : Node(NodeKind::invokeOpNode, sourcePos_)
{
}

SubscriptOpNode::SubscriptOpNode(const SourcePos& sourcePos_) : Node(NodeKind::subscriptOpNode, sourcePos_)
{
}

OperatorFunctionIdNode::OperatorFunctionIdNode(const SourcePos& sourcePos_, Node* operatorKwNode_, Node* op_) : 
    BinaryNode(NodeKind::operatorFnIdNode, sourcePos_, operatorKwNode_, op_)
{
}

ConversionFunctionIdNode::ConversionFunctionIdNode(const SourcePos& sourcePos_, Node* operatorKwNode_, Node* conversionTypeId_) : 
    BinaryNode(NodeKind::conversionFnIdNode, sourcePos_, operatorKwNode_, conversionTypeId_)
{
}

ConversionTypeIdNode::ConversionTypeIdNode(const SourcePos& sourcePos_, Node* typeSpecifierSeq_, Node* conversionDeclarator_) :
    CompoundNode(NodeKind::conversionTypeIdNode, sourcePos_), typeSpecifierSeq(typeSpecifierSeq_), conversionDeclarator(conversionDeclarator_)
{
}

ConversionDeclaratorNode::ConversionDeclaratorNode(const SourcePos& sourcePos_, Node* ptrOp_, Node* conversionDeclarator_) : 
    CompoundNode(NodeKind::conversionDeclaratorNode, sourcePos_), ptrOp(ptrOp_), conversionDeclarator(conversionDeclarator_)
{
}

DestructorIdNode::DestructorIdNode(const SourcePos& sourcePos_, Node* typeName_) : UnaryNode(NodeKind::destructorIdNode, sourcePos_, typeName_)
{
}

ParameterNode::ParameterNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::parameterNode, sourcePos_)
{
}

void ParameterNode::SetAttributes(Node* attributes_)
{
    attributes.reset(attributes_);
}

void ParameterNode::SetDeclSpecifiers(Node* declSpecifiers_)
{
    declSpecifiers.reset(declSpecifiers_);
}

void ParameterNode::SetDeclarator(Node* declarator_)
{
    declarator.reset(declarator_);
}

void ParameterNode::SetAssign(Node* assign_)
{
    assign.reset(assign_);
}

void ParameterNode::SetInitializer(Node* initializer_)
{
    initializer.reset(initializer_);
}

ParameterListNode::ParameterListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::parameterListNode, sourcePos_)
{
}

NoexceptNode::NoexceptNode(const SourcePos& sourcePos_) : Node(NodeKind::noexceptNode, sourcePos_)
{
}

FunctionTryBlockNode::FunctionTryBlockNode(const SourcePos& sourcePos_, Node* ctorInitializer_, Node* tryBlock_, Node* handlers_) :
    CompoundNode(NodeKind::functionTryBlock, sourcePos_), ctorInitializer(ctorInitializer_), tryBlock(tryBlock_), handlers(handlers_)
{
}

} // namespace sngcpp::ast
