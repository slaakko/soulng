// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_PRAGMA_INCLUDED
#define SNGCPP_AST_PRAGMA_INCLUDED
#include <sngcpp20/ast/Node.hpp>

namespace sngcpp::ast {

class AST_API PragmaNode : public Node
{
public:
    PragmaNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_PRAGMA_INCLUDED
