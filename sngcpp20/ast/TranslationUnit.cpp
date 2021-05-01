// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/TranslationUnit.hpp>

namespace sngcpp::ast {

TranslationUnitNode::TranslationUnitNode(const SourcePos& sourcePos_, Node* unit_) : CompoundNode(NodeKind::translationUnitNode, sourcePos_), unit(unit_)
{
}

ModuleUnitNode::ModuleUnitNode(const SourcePos& sourcePos_, Node* globalModuleFragment_, Node* moduleDeclaration_, Node* declarations_, Node* privateModuleFragment_) : 
    CompoundNode(NodeKind::moduleUnitNode, sourcePos_), globalModuleFragment(globalModuleFragment_), moduleDeclaration(moduleDeclaration_), declarations(declarations_), 
    privateModuleFragment(privateModuleFragment_)
{
}

} // namespace sngcpp::ast
