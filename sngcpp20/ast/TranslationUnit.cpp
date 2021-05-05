// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/TranslationUnit.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <sngcpp20/ast/Reader.hpp>

namespace sngcpp::ast {

TranslationUnitNode::TranslationUnitNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::translationUnitNode, sourcePos_)
{
}

TranslationUnitNode::TranslationUnitNode(const SourcePos& sourcePos_, Node* unit_) : CompoundNode(NodeKind::translationUnitNode, sourcePos_), unit(unit_)
{
}

void TranslationUnitNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TranslationUnitNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(unit.get());
}

void TranslationUnitNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    unit.reset(reader.ReadNode());
}

ModuleUnitNode::ModuleUnitNode(const SourcePos& sourcePos_) : CompoundNode(NodeKind::moduleUnitNode, sourcePos_)
{
}

ModuleUnitNode::ModuleUnitNode(const SourcePos& sourcePos_, Node* globalModuleFragment_, Node* moduleDeclaration_, Node* declarations_, Node* privateModuleFragment_) : 
    CompoundNode(NodeKind::moduleUnitNode, sourcePos_), globalModuleFragment(globalModuleFragment_), moduleDeclaration(moduleDeclaration_), declarations(declarations_), 
    privateModuleFragment(privateModuleFragment_)
{
}

void ModuleUnitNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ModuleUnitNode::Write(Writer& writer)
{
    CompoundNode::Write(writer);
    writer.Write(globalModuleFragment.get());
    writer.Write(moduleDeclaration.get());
    writer.Write(declarations.get());
    writer.Write(privateModuleFragment.get());
}

void ModuleUnitNode::Read(Reader& reader)
{
    CompoundNode::Read(reader);
    globalModuleFragment.reset(reader.ReadNode());
    moduleDeclaration.reset(reader.ReadNode());
    declarations.reset(reader.ReadNode());
    privateModuleFragment.reset(reader.ReadNode());
}

} // namespace sngcpp::ast
