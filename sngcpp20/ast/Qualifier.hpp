// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_QUALIFIER_INCLUDED
#define SNGCPP_AST_QUALIFIER_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API ConstNode : public Node
{
public:
    ConstNode(const SourcePos& sourcePos_);
};

class AST_API VolatileNode : public Node
{
public:
    VolatileNode(const SourcePos& sourcePos_);
};

class AST_API LvalueRefNode : public Node
{
public:
    LvalueRefNode(const SourcePos& sourcePos_);
};

class AST_API RvalueRefNode : public Node
{
public:
    RvalueRefNode(const SourcePos& sourcePos_);
};

class AST_API PtrNode : public Node
{
public:
    PtrNode(const SourcePos& sourcePos_);
};

class AST_API CVQualifierSequenceNode : public SequenceNode
{
public:
    CVQualifierSequenceNode(const SourcePos& sourcePos_);
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_QUALIFIER_INCLUDED
