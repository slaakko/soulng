// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Module.hpp>

namespace sngcpp::ast {

ModuleDeclarationNode::ModuleDeclarationNode(const SourcePos& sourcePos_, Node* exprt_, Node* modle_, Node* moduleName_, Node* modulePartition_, Node* attributes_, Node* semicolon_) :
    CompoundNode(NodeKind::moduleDeclarationNode, sourcePos_), exprt(exprt_), modle(modle_), moduleName(moduleName_), modulePartition(modulePartition_), attributes(attributes_), semicolon(semicolon_)
{
}

ExportDeclarationNode::ExportDeclarationNode(const SourcePos& sourcePos_, Node* exprt_, Node* subject_, const SourcePos& lbPos_, const SourcePos& rbPos_) :
    BinaryNode(NodeKind::exportDeclarationNode, sourcePos_, exprt_, subject_), lbPos(lbPos_), rbPos(rbPos_)
{
}

ExportNode::ExportNode(const SourcePos& sourcePos_) : Node(NodeKind::exportNode, sourcePos_)
{
}

ImportNode::ImportNode(const SourcePos& sourcePos_) : Node(NodeKind::importNode, sourcePos_)
{
}

ImportDeclarationNode::ImportDeclarationNode(const SourcePos& sourcePos_, Node* subject_, Node* attributes_, Node* semicolon_) : 
    CompoundNode(NodeKind::importDeclarationNode, sourcePos_), subject(subject_), attributes(attributes_), semicolon(semicolon_)
{
}

ModulePartitionNode::ModulePartitionNode(const SourcePos& sourcePos_, Node* moduleName_) : UnaryNode(NodeKind::modulePartitionNode, sourcePos_, moduleName_)
{
}

ModuleNode::ModuleNode(const SourcePos& sourcePos_) : Node(NodeKind::moduleNode, sourcePos_)
{
}

GlobalModuleFragmentNode::GlobalModuleFragmentNode(const SourcePos& sourcePos_, Node* modle_, Node* semicolon_, Node* declarations_) :
    CompoundNode(NodeKind::globalModuleFragmentNode, sourcePos_), modle(modle_), semicolon(semicolon_), declarations(declarations_)
{
}

PrivateModuleFragmentNode::PrivateModuleFragmentNode(const SourcePos& sourcePos_, Node* modle_, Node* colon_, Node* privat_, Node* semicolon_, Node* declarations_) :
    CompoundNode(NodeKind::privateModuleFragmentNode, sourcePos_), modle(modle_), colon(colon_), privat(privat_), semicolon(semicolon_), declarations(declarations_)
{
}

AngleHeaderName::AngleHeaderName(const SourcePos& sourcePos_) : Node(NodeKind::angleHeaderNameNode, sourcePos_)
{
}

QuoteHeaderName::QuoteHeaderName(const SourcePos& sourcePos_) : Node(NodeKind::quoteHeaderNameNode, sourcePos_)
{
}

} // namespace sngcpp::ast
