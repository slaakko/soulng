// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Template.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <sngcpp20/ast/Reader.hpp>

namespace sngcpp::ast {

TemplateDeclarationNode::TemplateDeclarationNode(const SourcePos& sourcePos_) : BinaryNode(NodeKind::templateDeclarationNode, sourcePos_, nullptr, nullptr)
{
}

TemplateDeclarationNode::TemplateDeclarationNode(const SourcePos& sourcePos_, Node* templateHead_, Node* declaration_) :
    BinaryNode(NodeKind::templateDeclarationNode, sourcePos_, templateHead_, declaration_)
{
}

void TemplateDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TemplateHeadNode::TemplateHeadNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::templateHeadNode, sourcePos_)
{
}

TemplateHeadNode::TemplateHeadNode(const SourcePos& sourcePos_, Node* templateParamList_, Node* requiresClause_) : 
    CompoundNode(NodeKind::templateHeadNode, sourcePos_), templateParamList(templateParamList_), requiresClause(requiresClause_)
{
}

void TemplateHeadNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TemplateHeadNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(templateParamList.get());
    writer.Write(requiresClause.get());
}

void TemplateHeadNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    templateParamList.reset(reader.ReadNode());
    requiresClause.reset(reader.ReadNode());
}

TemplateParameterListNode::TemplateParameterListNode(const SourcePos& sourcePos_) : ListNode(NodeKind::templateParameterListNode, sourcePos_)
{
}

void TemplateParameterListNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TemplateParameterListNode::Write(Writer& writer)
{
    ListNode::Write(writer);
    writer.Write(laPos);
    writer.Write(raPos);
}

void TemplateParameterListNode::Read(Reader& reader)
{
    ListNode::Read(reader);
    laPos = reader.ReadSourcePos();
    raPos = reader.ReadSourcePos();
}

TypeParameterNode::TypeParameterNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::typeParameterNode, sourcePos_)
{
}

TypeParameterNode::TypeParameterNode(const SourcePos& sourcePos_, Node* typeConstraint_, Node* identifier_, Node* assign_, Node* typeId_, Node* ellipsis_, Node* templateHead_) :
    CompoundNode(NodeKind::typeParameterNode, sourcePos_), typeConstraint(typeConstraint_), identifier(identifier_), assign(assign_), typeId(typeId_), ellipsis(ellipsis_), templateHead(templateHead_)
{
}

void TypeParameterNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TypeParameterNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(typeConstraint.get());
    writer.Write(identifier.get());
    writer.Write(assign.get());
    writer.Write(typeId.get());
    writer.Write(ellipsis.get());
    writer.Write(templateHead.get());
}

void TypeParameterNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    typeConstraint.reset(reader.ReadNode());
    identifier.reset(reader.ReadNode());
    assign.reset(reader.ReadNode());
    typeId.reset(reader.ReadNode());
    ellipsis.reset(reader.ReadNode());
    templateHead.reset(reader.ReadNode());
}

TemplateIdNode::TemplateIdNode(const SourcePos& sourcePos_) : ListNode(NodeKind::templateIdNode, sourcePos_)
{
}

TemplateIdNode::TemplateIdNode(const SourcePos& sourcePos_, Node* templateName_) : ListNode(NodeKind::templateIdNode, sourcePos_), templateName(templateName_)
{
}

void TemplateIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TemplateIdNode::Write(Writer& writer)
{
    ListNode::Write(writer);
    writer.Write(templateName.get());
    writer.Write(laPos);
    writer.Write(raPos);
}

void TemplateIdNode::Read(Reader& reader)
{
    ListNode::Read(reader);
    templateName.reset(reader.ReadNode());
    laPos = reader.ReadSourcePos();
    raPos = reader.ReadSourcePos();
}

TypenameNode::TypenameNode(const SourcePos& sourcePos_) : Node(NodeKind::typenameNode, sourcePos_)
{
}

void TypenameNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DeductionGuideNode::DeductionGuideNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::deductionGuideNode, sourcePos_)
{
}

DeductionGuideNode::DeductionGuideNode(const SourcePos& sourcePos_, Node* templateName_, Node* params_, Node* arrow_, Node* templateId_, Node* explicitSpecifier_, Node* semicolon_,
    const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::deductionGuideNode, sourcePos_), templateName(templateName_), params(params_), arrow(arrow_), explicitSpecifier(explicitSpecifier_), semicolon(semicolon_), 
    lpPos(lpPos_), rpPos(rpPos_)
{
}

void DeductionGuideNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void DeductionGuideNode::Write(Writer& writer) 
{
    CompoundNode::Write(writer);
    writer.Write(templateName.get());
    writer.Write(params.get());
    writer.Write(arrow.get());
    writer.Write(templateId.get());
    writer.Write(explicitSpecifier.get());
    writer.Write(semicolon.get());
    writer.Write(lpPos);
    writer.Write(rpPos);
}

void DeductionGuideNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    templateName.reset(reader.ReadNode());
    params.reset(reader.ReadNode());
    arrow.reset(reader.ReadNode());
    templateId.reset(reader.ReadNode());
    explicitSpecifier.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
    lpPos = reader.ReadSourcePos();
    rpPos = reader.ReadSourcePos();
}

ExplicitInstantiationNode::ExplicitInstantiationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::explicitInstantiationNode, sourcePos_)
{
}

ExplicitInstantiationNode::ExplicitInstantiationNode(const SourcePos& sourcePos_, Node* extrn_, Node* tmp_, Node* declaration_) : 
    CompoundNode(NodeKind::explicitInstantiationNode, sourcePos_), extrn(extrn_), tmp(tmp_), declaration(declaration_)
{
}

void ExplicitInstantiationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ExplicitInstantiationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(extrn.get());
    writer.Write(tmp.get());
    writer.Write(declaration.get());
}

void ExplicitInstantiationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    extrn.reset(reader.ReadNode());
    tmp.reset(reader.ReadNode());
    declaration.reset(reader.ReadNode());
}

TemplateNode::TemplateNode(const SourcePos& sourcePos_) : Node(NodeKind::templateNode, sourcePos_)
{
}

void TemplateNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExplicitSpecializationNode::ExplicitSpecializationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::explicitSpecializationNode, sourcePos_)
{
}

ExplicitSpecializationNode::ExplicitSpecializationNode(const SourcePos& sourcePos_, Node* tmp_, Node* declaration_, const SourcePos& laPos_, const SourcePos& raPos_) :
    CompoundNode(NodeKind::explicitSpecializationNode, sourcePos_), tmp(tmp_), declaration(declaration_), laPos(laPos_), raPos(raPos_)
{
}

void ExplicitSpecializationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ExplicitSpecializationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(tmp.get());
    writer.Write(declaration.get());
    writer.Write(laPos);
    writer.Write(raPos);
}

void ExplicitSpecializationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    tmp.reset(reader.ReadNode());
    declaration.reset(reader.ReadNode());
    laPos = reader.ReadSourcePos();
    raPos = reader.ReadSourcePos();
}

} // namespace sngcpp::ast
