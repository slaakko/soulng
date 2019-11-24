// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_TYPE_EXPR_INCLUDED
#define SNGCPP_AST_TYPE_EXPR_INCLUDED
#include <sngcpp/ast/Specifier.hpp>
#include <sngcpp/ast/Node.hpp>

namespace sngcpp { namespace ast {

class SNGCPP_AST_API ConstNode : public UnaryNode
{
public:
    ConstNode();
    ConstNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API VolatileNode : public UnaryNode
{
public:
    VolatileNode();
    VolatileNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

SNGCPP_AST_API Node* CreatePrefixTypeExprNode(const Span& span_, Specifier cvSpecifiers, Node* typeExprNode);

class SNGCPP_AST_API PointerNode : public UnaryNode
{
public:
    PointerNode();
    PointerNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API RValueRefNode : public UnaryNode
{
public:
    RValueRefNode();
    RValueRefNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API LValueRefNode : public UnaryNode
{
public:
    LValueRefNode();
    LValueRefNode(const Span& span_, Node* subject_);
    void Accept(Visitor& visitor) override;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_TYPE_EXPR_INCLUDED
