// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Lambda.hpp>

namespace sngcpp::ast {

LambdaExpressionNode::LambdaExpressionNode(const SourcePos& sourcePos_, Node* introducer_, Node* templateParams_, Node* declarator_, Node* body_) :
    CompoundNode(NodeKind::lambdaExpressionNode, sourcePos_), introducer(introducer_), templateParams(templateParams_), declarator(declarator_), body(body_)
{
}

LambdaIntroducerNode::LambdaIntroducerNode(const SourcePos& sourcePos_, Node* capture_, const SourcePos& lbPos_, const SourcePos& rbPos_) :
    CompoundNode(NodeKind::lambdaIntroducerNode, sourcePos_), capture(capture_), lbPos(lbPos_), rbPos(rbPos_)
{
}

LambdaCaptureNode::LambdaCaptureNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::lambdaCaptureNode, sourcePos_)
{
}

DefaultRefCaptureNode::DefaultRefCaptureNode(const SourcePos& sourcePos_) : Node(NodeKind::defaultRefCaptureNode, sourcePos_)
{
}

DefaultCopyCaptureNode::DefaultCopyCaptureNode(const SourcePos& sourcePos_) : Node(NodeKind::defaultCopyCaptureNode, sourcePos_)
{
}

ByRefCaptureNode::ByRefCaptureNode(const SourcePos& sourcePos_) : Node(NodeKind::byRefCaptureNode, sourcePos_)
{
}

SimpleCaptureNode::SimpleCaptureNode(const SourcePos& sourcePos_, Node* identifier_, Node* byRefCapture_, Node* ellipses_) : 
    CompoundNode(NodeKind::simpleCaptureNode, sourcePos_), identifier(identifier_), byRefCapture(byRefCapture_), ellipses(ellipses_)
{
}

CurrentObjectCopyCapture::CurrentObjectCopyCapture(const SourcePos& sourcePos_) : Node(NodeKind::currentObjectCopyCapture, sourcePos_)
{
}

CurrentObjectByRefCapture::CurrentObjectByRefCapture(const SourcePos& sourcePos_, const SourcePos& thisPos_) : CompoundNode(NodeKind::currentObjectByRefCapture, sourcePos_), thisPos(thisPos_)
{
}

InitCaptureNode::InitCaptureNode(const SourcePos& sourcePos_, Node* identifier_, Node* initializer_, Node* byRefCapture_, Node* ellipses_) :
    CompoundNode(NodeKind::initCaptureNode, sourcePos_), identifier(identifier_), initializer(initializer_), byRefCapture(byRefCapture_), ellipses(ellipses_)
{
}

LambdaDeclaratorNode::LambdaDeclaratorNode(const SourcePos& sourcePos_, Node* parameterList_, Node* specifiers_, Node* requiresClause_) : 
    CompoundNode(NodeKind::lambdaDeclaratorNode, sourcePos_), parameterList(parameterList_), specifiers(specifiers_), requiresClause(requiresClause_)
{
}

LambdaSpecifiersNode::LambdaSpecifiersNode(const SourcePos& sourcePos_, Node* declSpecifiers_, Node* noexceptSpecifier_, Node* attributes_, Node* trailingReturnType_) :
    CompoundNode(NodeKind::lambdaSpecifiersNode, sourcePos_), declSpecifiers(declSpecifiers_), noexceptSpecifier(noexceptSpecifier_), attributes(attributes_), trailingReturnType(trailingReturnType_)
{
}

bool LambdaSpecifiersNode::IsEmpty() const
{
    return !declSpecifiers && !noexceptSpecifier && !attributes && !trailingReturnType;
}

LambdaTemplateParamsNode::LambdaTemplateParamsNode(const SourcePos& sourcePos_, Node* templateParams_, Node* requiresClause_) : 
    CompoundNode(NodeKind::lambdaTemplateParamsNode, sourcePos_), templateParams(templateParams_), requiresClause(requiresClause_)
{
}

} // namespace sngcpp::ast
