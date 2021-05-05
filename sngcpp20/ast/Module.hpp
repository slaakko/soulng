// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_MODULE_INCLUDED
#define SNGCPP_AST_MODULE_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API ModuleDeclarationNode : public CompoundNode
{
public:
    ModuleDeclarationNode(const SourcePos& sourcePos_);
    ModuleDeclarationNode(const SourcePos& sourcePos_, Node* exprt_, Node* modle_, Node* moduleName_, Node* modulePartition_, Node* attributes_, Node* semicolon_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Export() const { return exprt.get(); }
    Node* Module() const { return modle.get(); }
    Node* ModuleName() const { return moduleName.get(); }
    Node* ModulePartition() const { return modulePartition.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> exprt;
    std::unique_ptr<Node> modle;
    std::unique_ptr<Node> moduleName;
    std::unique_ptr<Node> modulePartition;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
};

class AST_API ExportDeclarationNode : public CompoundNode
{
public:
    ExportDeclarationNode(const SourcePos& sourcePos_);
    ExportDeclarationNode(const SourcePos& sourcePos_, Node* exprt_, Node* subject_, const SourcePos& lbPos_, const SourcePos& rbPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Export() const { return exprt.get(); }
    Node* Subject() const { return subject.get(); }
    const SourcePos& LBracePos() const { return lbPos;  }
    const SourcePos& RBracePos() const { return rbPos; }
private:
    std::unique_ptr<Node> exprt;
    std::unique_ptr<Node> subject;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API ExportNode : public Node
{
public:
    ExportNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ImportNode : public Node
{
public:
    ImportNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ImportDeclarationNode : public CompoundNode
{
public:
    ImportDeclarationNode(const SourcePos& sourcePos_);
    ImportDeclarationNode(const SourcePos& sourcePos_, Node* imprt_, Node* subject_, Node* attributes_, Node* semicolon_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Import() const { return imprt.get(); }
    Node* Subject() const { return subject.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> imprt;
    std::unique_ptr<Node> subject;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
};

class AST_API ModulePartitionNode : public UnaryNode
{
public:
    ModulePartitionNode(const SourcePos& sourcePos_);
    ModulePartitionNode(const SourcePos& sourcePos_, Node* moduleName_);
    void Accept(Visitor& visitor) override;
};

class AST_API ModuleNode : public Node
{
public:
    ModuleNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API GlobalModuleFragmentNode : public CompoundNode
{
public:
    GlobalModuleFragmentNode(const SourcePos& sourcePos_);
    GlobalModuleFragmentNode(const SourcePos& sourcePos_, Node* modle_, Node* semicolon_, Node* declarations_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Module() const { return modle.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    Node* Declarations() const { return declarations.get(); }
private:
    std::unique_ptr<Node> modle;
    std::unique_ptr<Node> semicolon;
    std::unique_ptr<Node> declarations;
};

class AST_API PrivateModuleFragmentNode : public CompoundNode
{
public:
    PrivateModuleFragmentNode(const SourcePos& sourcePos_);
    PrivateModuleFragmentNode(const SourcePos& sourcePos_, Node* modle_, Node* colon_, Node* privat_, Node* semicolon_, Node* declarations_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Module() const { return modle.get(); }
    Node* Colon() const { return colon.get(); }
    Node* Private() const { return privat.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    Node* Declarations() const { return declarations.get(); }
private:
    std::unique_ptr<Node> modle;
    std::unique_ptr<Node> colon;
    std::unique_ptr<Node> privat;
    std::unique_ptr<Node> semicolon;
    std::unique_ptr<Node> declarations;
};

class AST_API AngleHeaderName : public Node
{
public:
    AngleHeaderName(const SourcePos& sourcePos_);
    AngleHeaderName(const SourcePos& sourcePos_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& Rep() const { return rep; }
private:
    std::u32string rep;
};

class AST_API QuoteHeaderName : public Node
{
public:
    QuoteHeaderName(const SourcePos& sourcePos_);
    QuoteHeaderName(const SourcePos& sourcePos_, const std::u32string& rep_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& Rep() const { return rep; }
private:
    std::u32string rep;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_MODULE_INCLUDED
