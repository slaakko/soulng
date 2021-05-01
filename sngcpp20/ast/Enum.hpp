// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_ENUM_INCLUDED
#define SNGCPP_AST_ENUM_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API EnumSpecifierNode : public ListNode
{
public:
    EnumSpecifierNode(const SourcePos& sourcePos_);
    EnumSpecifierNode(const SourcePos& sourcePos_, Node* enumHead_);
    Node* EnumHead() const { return enumHead.get(); }
    void SetLBracePos(const SourcePos& lbPos_) { lbPos = lbPos_; }
    void SetRBracePos(const SourcePos& rbPos_) { rbPos = rbPos_; }
    const SourcePos& LBracePos() const { return lbPos; }
    const SourcePos& RBracePos() const { return rbPos; }
private:
    std::unique_ptr<Node> enumHead;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API EnumHeadNode : public CompoundNode
{
public:
    EnumHeadNode(const SourcePos& sourcePos_);
    EnumHeadNode(const SourcePos& sourcePos_, Node* enumKey_, Node* enumHeadName_, Node* enumBase_, Node* attributes_);
    Node* EnumKey() const { return enumKey.get(); }
    Node* EnumHeadName() const { return enumHeadName.get(); }
    Node* EnumBase() const { return enumBase.get(); }
    Node* Attributes() const { return attributes.get(); }
private:
    std::unique_ptr<Node> enumKey;
    std::unique_ptr<Node> enumHeadName;
    std::unique_ptr<Node> enumBase;
    std::unique_ptr<Node> attributes;
};

class AST_API EnumBaseNode : public UnaryNode
{
public:
    EnumBaseNode(const SourcePos& sourcePos_);
    EnumBaseNode(const SourcePos& sourcePos_, Node* typeSpecifiers_);
};

class AST_API EnumClassNode : public CompoundNode
{
public:
    EnumClassNode(const SourcePos& sourcePos_);
    EnumClassNode(const SourcePos& sourcePos_, const SourcePos& classPos_);
    const SourcePos& ClassPos() const { return classPos; }
private:
    SourcePos classPos;
};

class AST_API EnumStructNode : public CompoundNode
{
public:
    EnumStructNode(const SourcePos& sourcePos_);
    EnumStructNode(const SourcePos& sourcePos_, const SourcePos& structPos_);
    const SourcePos& StructPos() const { return structPos; }
private:
    SourcePos structPos;
};

class AST_API EnumNode : public Node
{
public:
    EnumNode(const SourcePos& sourcePos_);
};

class AST_API EnumeratorDefinitionNode : public CompoundNode
{
public:
    EnumeratorDefinitionNode(const SourcePos& sourcePos_);
    EnumeratorDefinitionNode(const SourcePos& sourcePos_, Node* enumerator_, Node* value_, const SourcePos& assignPos_);
    Node* Enumerator() const { return enumerator.get(); }
    Node* Value() const { return value.get(); }
    const SourcePos& AssignPos() const { return assignPos; }
private:
    std::unique_ptr<Node> enumerator;
    std::unique_ptr<Node> value;
    SourcePos assignPos;
};

class AST_API EnumeratorNode : public CompoundNode
{
public:
    EnumeratorNode(const SourcePos& sourcePos_);
    EnumeratorNode(const SourcePos& sourcePos_, Node* identifier_, Node* attributes_);
    Node* Identifier() const { return identifier.get(); }
    Node* Attributes() const { return attributes.get(); }
private:
    std::unique_ptr<Node> identifier;
    std::unique_ptr<Node> attributes;
};

class AST_API ElaboratedEnumSpecifierNode : public UnaryNode
{
public:
    ElaboratedEnumSpecifierNode(const SourcePos& sourcePos_);
    ElaboratedEnumSpecifierNode(const SourcePos& sourcePos_, Node* enumName_);
};

class AST_API OpaqueEnumDeclarationNode : public CompoundNode
{
public:
    OpaqueEnumDeclarationNode(const SourcePos& sourcePos_);
    OpaqueEnumDeclarationNode(const SourcePos& sourcePos_, Node* enumKey_, Node* enumHeadName_, Node* enumBase_, Node* attributes_, Node* semicolon_);
    Node* EnumKey() const { return enumKey.get(); }
    Node* EnumHeadName() const { return enumHeadName.get(); }
    Node* EnumBase() const { return enumBase.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> enumKey;
    std::unique_ptr<Node> enumHeadName;
    std::unique_ptr<Node> enumBase;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
};

} // sngcpp::ast

#endif // SNGCPP_AST_ENUM_INCLUDED
