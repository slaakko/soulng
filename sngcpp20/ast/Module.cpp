// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Module.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <sngcpp20/ast/Reader.hpp>

namespace sngcpp::ast {

ModuleDeclarationNode::ModuleDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::moduleDeclarationNode, sourcePos_)
{
}

ModuleDeclarationNode::ModuleDeclarationNode(const SourcePos& sourcePos_, Node* exprt_, Node* modle_, Node* moduleName_, Node* modulePartition_, Node* attributes_, Node* semicolon_) :
    CompoundNode(NodeKind::moduleDeclarationNode, sourcePos_), exprt(exprt_), modle(modle_), moduleName(moduleName_), modulePartition(modulePartition_), attributes(attributes_), semicolon(semicolon_)
{
}

void ModuleDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ModuleDeclarationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(exprt.get());
    writer.Write(modle.get());
    writer.Write(moduleName.get());
    writer.Write(modulePartition.get());
    writer.Write(attributes.get());
    writer.Write(semicolon.get());
}

void ModuleDeclarationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    exprt.reset(reader.ReadNode());
    modle.reset(reader.ReadNode());
    moduleName.reset(reader.ReadNode());
    modulePartition.reset(reader.ReadNode());
    attributes.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
}

ExportDeclarationNode::ExportDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::exportDeclarationNode, sourcePos_)
{
}

ExportDeclarationNode::ExportDeclarationNode(const SourcePos& sourcePos_, Node* exprt_, Node* subject_, const SourcePos& lbPos_, const SourcePos& rbPos_) :
    CompoundNode(NodeKind::exportDeclarationNode, sourcePos_), exprt(exprt_), subject(subject_), lbPos(lbPos_), rbPos(rbPos_)
{
}

void ExportDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ExportDeclarationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(exprt.get());
    writer.Write(subject.get());
    writer.Write(lbPos);
    writer.Write(rbPos);
}

void ExportDeclarationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    exprt.reset(reader.ReadNode());
    subject.reset(reader.ReadNode());
    lbPos = reader.ReadSourcePos();
    rbPos = reader.ReadSourcePos();
}

ExportNode::ExportNode(const SourcePos& sourcePos_) : Node(NodeKind::exportNode, sourcePos_)
{
}

void ExportNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ImportNode::ImportNode(const SourcePos& sourcePos_) : Node(NodeKind::importNode, sourcePos_)
{
}

void ImportNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ImportDeclarationNode::ImportDeclarationNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::importDeclarationNode, sourcePos_)
{
}

ImportDeclarationNode::ImportDeclarationNode(const SourcePos& sourcePos_, Node* imprt_, Node* subject_, Node* attributes_, Node* semicolon_) : 
    CompoundNode(NodeKind::importDeclarationNode, sourcePos_), imprt(imprt_), subject(subject_), attributes(attributes_), semicolon(semicolon_)
{
}

void ImportDeclarationNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ImportDeclarationNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(imprt.get());
    writer.Write(subject.get());
    writer.Write(attributes.get());
    writer.Write(semicolon.get());
}

void ImportDeclarationNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    imprt.reset(reader.ReadNode());
    subject.reset(reader.ReadNode());
    attributes.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
}

ModulePartitionNode::ModulePartitionNode(const SourcePos& sourcePos_) : UnaryNode(NodeKind::modulePartitionNode, sourcePos_, nullptr)
{
}

ModulePartitionNode::ModulePartitionNode(const SourcePos& sourcePos_, Node* moduleName_) : UnaryNode(NodeKind::modulePartitionNode, sourcePos_, moduleName_)
{
}

void ModulePartitionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ModuleNode::ModuleNode(const SourcePos& sourcePos_) : Node(NodeKind::moduleNode, sourcePos_)
{
}

void ModuleNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

GlobalModuleFragmentNode::GlobalModuleFragmentNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::globalModuleFragmentNode, sourcePos_)
{
}

GlobalModuleFragmentNode::GlobalModuleFragmentNode(const SourcePos& sourcePos_, Node* modle_, Node* semicolon_, Node* declarations_) :
    CompoundNode(NodeKind::globalModuleFragmentNode, sourcePos_), modle(modle_), semicolon(semicolon_), declarations(declarations_)
{
}

void GlobalModuleFragmentNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void GlobalModuleFragmentNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(modle.get());
    writer.Write(semicolon.get());
    writer.Write(declarations.get());
}

void GlobalModuleFragmentNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    modle.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
    declarations.reset(reader.ReadNode());
}

PrivateModuleFragmentNode::PrivateModuleFragmentNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::privateModuleFragmentNode, sourcePos_)
{
}

PrivateModuleFragmentNode::PrivateModuleFragmentNode(const SourcePos& sourcePos_, Node* modle_, Node* colon_, Node* privat_, Node* semicolon_, Node* declarations_) :
    CompoundNode(NodeKind::privateModuleFragmentNode, sourcePos_), modle(modle_), colon(colon_), privat(privat_), semicolon(semicolon_), declarations(declarations_)
{
}

void PrivateModuleFragmentNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void PrivateModuleFragmentNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(modle.get());
    writer.Write(colon.get());
    writer.Write(privat.get());
    writer.Write(semicolon.get());
    writer.Write(declarations.get());
}

void PrivateModuleFragmentNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    modle.reset(reader.ReadNode());
    colon.reset(reader.ReadNode());
    privat.reset(reader.ReadNode());
    semicolon.reset(reader.ReadNode());
    declarations.reset(reader.ReadNode());
}

AngleHeaderName::AngleHeaderName(const SourcePos& sourcePos_) : Node(NodeKind::angleHeaderNameNode, sourcePos_)
{
}

AngleHeaderName::AngleHeaderName(const SourcePos& sourcePos_, const std::u32string& rep_) : Node(NodeKind::angleHeaderNameNode, sourcePos_), rep(rep_)
{
}

void AngleHeaderName::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void AngleHeaderName::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(rep);
}

void AngleHeaderName::Read(Reader& reader)
{
    Node::Read(reader);
    rep = reader.ReadStr();
}

QuoteHeaderName::QuoteHeaderName(const SourcePos& sourcePos_) : Node(NodeKind::quoteHeaderNameNode, sourcePos_)
{
}

QuoteHeaderName::QuoteHeaderName(const SourcePos& sourcePos_, const std::u32string& rep_) : Node(NodeKind::quoteHeaderNameNode, sourcePos_), rep(rep_)
{
}

void QuoteHeaderName::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void QuoteHeaderName::Write(Writer& writer)
{
    Node::Write(writer);
    writer.Write(rep);
}

void QuoteHeaderName::Read(Reader& reader)
{
    Node::Read(reader);
    rep = reader.ReadStr();
}

} // namespace sngcpp::ast
