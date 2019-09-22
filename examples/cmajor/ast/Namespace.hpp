// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CMAJOR_AST_NAMESPACE_INCLUDED
#define CMAJOR_AST_NAMESPACE_INCLUDED
#include <cmajor/ast/Node.hpp>
#include <cmajor/ast/NodeList.hpp>

namespace cmajor { namespace ast {

class IdentifierNode;

class CMAJOR_AST_API NamespaceNode : public Node
{
public:
    NamespaceNode(const Span& span_);
    NamespaceNode(const Span& span_, IdentifierNode* id_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    void Write(AstWriter& writer) override;
    void Read(AstReader& reader) override;
    void AddMember(Node* member);
    IdentifierNode* Id() const;
    NodeList<Node>& Members() { return members; }
    const NodeList<Node>& Members() const { return members; }
private:
    std::unique_ptr<IdentifierNode> id;
    NodeList<Node> members;
};

class CMAJOR_AST_API AliasNode : public Node
{
public:
    AliasNode(const Span& span_);
    AliasNode(const Span& span_, IdentifierNode* id_, IdentifierNode* qid_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    void Write(AstWriter& writer) override;
    void Read(AstReader& reader) override;
    IdentifierNode* Id() const;
    IdentifierNode* Qid() const;
private:
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<IdentifierNode> qid;
};

class CMAJOR_AST_API NamespaceImportNode : public Node
{
public:
    NamespaceImportNode(const Span& span_);
    NamespaceImportNode(const Span& span_, IdentifierNode* ns_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    void Write(AstWriter& writer) override;
    void Read(AstReader& reader) override;
    IdentifierNode* Ns() const;
private:
    std::unique_ptr<IdentifierNode> ns;
};

} } // namespace cmajor::ast

#endif // CMAJOR_AST_NAMESPACE_INCLUDED
