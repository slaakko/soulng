// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_TEMPLATE_INCLUDED
#define SNGCPP_AST_TEMPLATE_INCLUDED
#include <sngcpp/ast/Expression.hpp>

namespace sngcpp { namespace ast {

class SNGCPP_AST_API TypeParameterNode : public Node
{
public:
    TypeParameterNode(const Span& span_, const std::u32string& id_, Node* defaultTemplateParameter_, bool typenameUsed_);
    void Accept(Visitor& visitor) override;
    const std::u32string& Id() const { return id; }
    Node* DefaultTemplateParameter() { return defaultTemplateParameter.get(); }
    bool TypenameUsed() const { return typenameUsed; }
private:
    std::u32string id;
    std::unique_ptr<Node> defaultTemplateParameter;
    bool typenameUsed;
};

class SNGCPP_AST_API TemplateParameterSequenceNode : public BinaryNode
{
public:
    TemplateParameterSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API TemplateDeclarationNode : public Node
{
public:
    TemplateDeclarationNode(const Span& span_, Node* templateParameters_, Node* declaration_);
    void Accept(Visitor& visitor) override;
    Node* TemplateParameters() { return templateParameters.get(); }
    Node* Declaration() { return declaration.get(); }
private:
    std::unique_ptr<Node> templateParameters;
    std::unique_ptr<Node> declaration;
};

class SNGCPP_AST_API TemplateArgumentSequenceNode : public BinaryNode
{
public:
    TemplateArgumentSequenceNode(const Span& span_, Node* left_, Node* right_);
    bool IsTemplateArgumentSequenceNode() const override { return true; }
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API TemplateIdNode : public Node
{
public:
    TemplateIdNode(const Span& span_, IdentifierNode* id_, Node* templateArguments_, int arity_);
    bool IsTemplateIdNode() const override { return true; }
    void Accept(Visitor& visitor) override;
    IdentifierNode* Id() { return id.get(); }
    Node* TemplateArguments() { return templateArguments.get(); }
    int Arity() const { return arity; }
private:
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<Node> templateArguments;
    int arity;
};

class SNGCPP_AST_API TemplateArgumentNode : public Node
{
public:
    TemplateArgumentNode(const Span& span_, Node* arg_);
    void Accept(Visitor& visitor) override;
    Node* Arg() { return arg.get(); }
private:
    std::unique_ptr<Node> arg;
};

class SNGCPP_AST_API ExplicitInstantiationNode : public UnaryNode
{
public:
    ExplicitInstantiationNode(const Span& span_, Node* declaration_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API ExplicitSpecializationNode : public UnaryNode
{
public:
    ExplicitSpecializationNode(const Span& span_, Node* declaration_);
    void Accept(Visitor& visitor) override;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_TEMPLATE_INCLUDED
