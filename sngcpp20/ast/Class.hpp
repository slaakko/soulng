// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_CLASS_INCLUDED
#define SNGCPP_AST_CLASS_INCLUDED
#include <sngcpp20/ast/Node.hpp>
#include <sngcpp20/ast/Declaration.hpp>

namespace sngcpp::ast {

class AST_API ClassSpecifierNode : public SequenceNode
{
public:
    ClassSpecifierNode(const SourcePos& sourcePos_);
    ClassSpecifierNode(const SourcePos& sourcePos_, Node* classHead_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ClassHead() const { return classHead.get(); }
    void SetLBracePos(const SourcePos& lbPos_) { lbPos = lbPos_; }
    void SetRBracePos(const SourcePos& rbPos_) { rbPos = rbPos_; }
    const SourcePos& LBracePos() const { return lbPos; }
    const SourcePos& RBracePos() const { return rbPos; }
private:
    std::unique_ptr<Node> classHead;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API ClassHeadNode : public CompoundNode
{
public:
    ClassHeadNode(const SourcePos& sourcePos_);
    ClassHeadNode(const SourcePos& sourcePos_, Node* classKey_, Node* classHeadName_, Node* classVirtSpecifier_, Node* baseClause_, Node* attributes_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ClassKey() const { return classKey.get(); }
    Node* ClassHeadName() const { return classHeadName.get(); }
    Node* ClassVirtSpecifier() const { return classVirtSpecifier.get();  }
    Node* BaseClause() const { return baseClause.get(); }
    Node* Attibutes() const { return attributes.get(); }
private:
    std::unique_ptr<Node> classKey;
    std::unique_ptr<Node> classHeadName; 
    std::unique_ptr<Node> classVirtSpecifier;
    std::unique_ptr<Node> baseClause;
    std::unique_ptr<Node> attributes;
};

class AST_API BaseClauseNode : public UnaryNode
{
public:
    BaseClauseNode(const SourcePos& sourcePos_);
    BaseClauseNode(const SourcePos& sourcePos_, Node* baseSpecifierList_);
    void Accept(Visitor& visitor) override;
};

class AST_API BaseSpecifierListNode : public ListNode
{
public:
    BaseSpecifierListNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API BaseSpecifierNode : public CompoundNode
{
public:
    BaseSpecifierNode(const SourcePos& sourcePos_);
    BaseSpecifierNode(const SourcePos& sourcePos_, Node* classOrDeclType_, Node* accessSpecifier_, Node* virtualSpecifier_, Node* attributes_, bool virtualFirst_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ClassOrDeclType() const { return classOrDeclType.get(); }
    Node* AccessSpecifier() const { return accessSpecifier.get(); }
    Node* VirtualSpecifier() const { return virtualSpecifier.get(); }
    Node* Attributes() const { return attributes.get(); }
    bool VirtualFirst() const { return virtualFirst; }
private:
    std::unique_ptr<Node> classOrDeclType;
    std::unique_ptr<Node> accessSpecifier;
    std::unique_ptr<Node> virtualSpecifier;
    std::unique_ptr<Node> attributes;
    bool virtualFirst;
};

class AST_API BeginAccessGroupNode : public UnaryNode
{
public:
    BeginAccessGroupNode(const SourcePos& sourcePos_);
    BeginAccessGroupNode(const SourcePos& sourcePos_, Node* accessSpecifier_, const SourcePos& colonPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& ColonPos() const { return colonPos; }
private:
    SourcePos colonPos;
};

class AST_API MemberDeclarationNode : public CompoundNode
{
public:
    MemberDeclarationNode(const SourcePos& sourcePos_);
    MemberDeclarationNode(const SourcePos& sourcePos_, Node* attributes_, Node* declSpecifiers_, Node* memberDeclarators_, Node* semicolon_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Attributes() const { return attributes.get(); }
    Node* DeclSpecifiers() const { return declSpecifiers.get(); }
    Node* MemberDeclarators() const { return memberDeclarators.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> declSpecifiers;
    std::unique_ptr<Node> memberDeclarators;
    std::unique_ptr<Node> semicolon;
};

class AST_API MemberDeclaratorListNode : public ListNode
{
public:
    MemberDeclaratorListNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ConstructorNode : public BinaryNode
{
public:
    ConstructorNode(const SourcePos& sourcePos_);
    ConstructorNode(const SourcePos& sourcePos_, Node* constructorInitializer_, Node* compoundStatement_);
    void Accept(Visitor& visitor) override;
};

class AST_API ConstructorInitializerNode : public UnaryNode
{
public:
    ConstructorInitializerNode(const SourcePos& sourcePos_);
    ConstructorInitializerNode(const SourcePos& sourcePos_, Node* memberInitializerList_);
    void Accept(Visitor& visitor) override;
};

class AST_API MemberInitializerListNode : public ListNode
{
public:
    MemberInitializerListNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API MemberInitializerNode : public BinaryNode
{
public:
    MemberInitializerNode(const SourcePos& sourcePos_);
    MemberInitializerNode(const SourcePos& sourcePos_, Node* id_, Node* initializer_);
    void Accept(Visitor& visitor) override;
};

class AST_API VirtSpecifierSequenceNode : public SequenceNode
{
public:
    VirtSpecifierSequenceNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ClassNode : public Node
{
public:
    ClassNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API StructNode : public Node
{
public:
    StructNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API UnionNode : public Node
{
public:
    UnionNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API PublicNode : public Node
{
public:
    PublicNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API ProtectedNode : public Node
{
public:
    ProtectedNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API PrivateNode : public Node
{
public:
    PrivateNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API VirtualNode : public Node
{
public:
    VirtualNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API OverrideNode : public Node
{
public:
    OverrideNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API FinalNode : public Node
{
public:
    FinalNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API PureSpecifierNode : public Node
{
public:
    PureSpecifierNode(const SourcePos& sourcePos_);
    PureSpecifierNode(const SourcePos& sourcePos_, const SourcePos& zeroPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& ZeroPos() const { return zeroPos; }
private:
    SourcePos zeroPos;
};

} // sngcpp::ast

#endif // SNGCPP_AST_CLASS_INCLUDED
