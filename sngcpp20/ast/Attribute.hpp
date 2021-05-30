// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_ATTRIBUTE_INCLUDED
#define SNGCPP_AST_ATTRIBUTE_INCLUDED
#include <sngcpp20/ast/Node.hpp>
#include <string>

namespace sngcpp::ast {

class AST_API AttributeSpecifierSequenceNode : public SequenceNode
{
public:
    AttributeSpecifierSequenceNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API AttributeSpecifierNode : public ListNode
{
public:
    AttributeSpecifierNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void SetUsingPrefix(Node* usingPrefix_) { usingPrefix.reset(usingPrefix_); }
    Node* UsingPrefix() const { return usingPrefix.get(); }
    void SetBracketPositions(const SourcePos& lbPos1_, const SourcePos& lbPos2_, const SourcePos& rbPos1_, const SourcePos& rbPos2_);
    const SourcePos& LBracketPos1() const { return lbPos1; }
    const SourcePos& LBracketPos2() const { return lbPos2; }
    const SourcePos& RBracketPos1() const { return rbPos1; }
    const SourcePos& RBracketPos2() const { return rbPos2; }
private:
    std::unique_ptr<Node> usingPrefix;
    SourcePos lbPos1;
    SourcePos lbPos2;
    SourcePos rbPos1;
    SourcePos rbPos2;
};

class AST_API AttributeUsingPrefixNode : public UnaryNode
{
public:
    AttributeUsingPrefixNode(const SourcePos& sourcePos_);
    AttributeUsingPrefixNode(const SourcePos& sourcePos_, Node* attributeNamespace_, const SourcePos& colonPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const SourcePos& ColonPos() const { return colonPos; }
private:
    SourcePos colonPos;
};

class AST_API AttributeNode : public CompoundNode
{
public:
    AttributeNode(const SourcePos& sourcePos_);
    AttributeNode(const SourcePos& sourcePos_, Node* attributeToken_, Node* attributeArgs_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* AttributeToken() const { return attributeToken.get(); }
    Node* AttributeArgs() const { return attributeArgs.get(); }
private:
    std::unique_ptr<Node> attributeToken;
    std::unique_ptr<Node> attributeArgs;
};

class AST_API AttributeScopedTokenNode : public CompoundNode
{
public:
    AttributeScopedTokenNode(const SourcePos& sourcePos_);
    AttributeScopedTokenNode(const SourcePos& sourcePos_, Node* ns_, Node* colonColon_, Node* identifier_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Ns() const { return ns.get(); }
    Node* ColonColon() const { return colonColon.get(); }
    Node* Identifier() const { return identifier.get(); }
private:
    std::unique_ptr<Node> ns;
    std::unique_ptr<Node> colonColon;
    std::unique_ptr<Node> identifier;
};

class AST_API AttributeArgumentsNode : public CompoundNode
{
public:
    AttributeArgumentsNode(const SourcePos& sourcePos_);
    AttributeArgumentsNode(const SourcePos& sourcePos_, Node* balancedTokenSequence_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* BalancedTokenSequence() const { return balancedTokenSequence.get(); }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> balancedTokenSequence;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API BalancedTokenSequenceNode : public SequenceNode
{
public:
    BalancedTokenSequenceNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API TokenNode : public CompoundNode
{
public:
    TokenNode(const SourcePos& sourcePos_);
    TokenNode(const SourcePos& sourcePos_, const std::u32string& str_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    std::u32string Str() const override { return str; }
private:
    std::u32string str;
};

class AST_API AlignmentSpecifierNode : public CompoundNode
{
public:
    AlignmentSpecifierNode(const SourcePos& sourcePos_);
    AlignmentSpecifierNode(const SourcePos& sourcePos_, Node* alignment_, Node* ellipsis_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Alignment() const { return alignment.get(); }
    Node* Ellipsis() const { return ellipsis.get(); }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> alignment;
    std::unique_ptr<Node> ellipsis;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API LParenNode : public Node
{
public:
    LParenNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API RParenNode : public Node
{
public:
    RParenNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API LBracketNode : public Node
{
public:
    LBracketNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API RBracketNode : public Node
{
public:
    RBracketNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API LBraceNode : public Node
{
public:
    LBraceNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API RBraceNode : public Node
{
public:
    RBraceNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

} // sngcpp::ast

#endif // SNGCPP_AST_ATTRIBUTE_INCLUDED
