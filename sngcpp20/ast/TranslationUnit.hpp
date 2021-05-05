// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_TRANSLATION_UNIT_INCLUDED
#define SNGCPP_AST_TRANSLATION_UNIT_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API TranslationUnitNode : public CompoundNode
{
public:
    TranslationUnitNode(const SourcePos& sourcePos_);
    TranslationUnitNode(const SourcePos& sourcePos_, Node* unit_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Unit() const { return unit.get(); }
private:
    std::unique_ptr<Node> unit;
};

class AST_API ModuleUnitNode : public CompoundNode
{
public:
    ModuleUnitNode(const SourcePos& sourcePos_);
    ModuleUnitNode(const SourcePos& sourcePos_, Node* globalModuleFragment_, Node* moduleDeclaration_, Node* declarations_, Node* privateModuleFragment_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* GlobalModuleFragment() const { return globalModuleFragment.get(); }
    Node* ModuleDeclaration() const { return moduleDeclaration.get(); }
    Node* Declarations() const { return declarations.get(); }
    Node* PrivateModuleFragment() const { return privateModuleFragment.get(); }
private:
    std::unique_ptr<Node> globalModuleFragment;
    std::unique_ptr<Node> moduleDeclaration;
    std::unique_ptr<Node> declarations;
    std::unique_ptr<Node> privateModuleFragment;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_TRANSLATION_UNIT_INCLUDED
