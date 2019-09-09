// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CMAJOR_AST_IDENTIFIER_INCLUDED
#define CMAJOR_AST_IDENTIFIER_INCLUDED
#include <soulng/lexer/Token.hpp>
#include <cmajor/ast/Node.hpp>

namespace cmajor { namespace ast {

class CMAJOR_AST_API IdentifierNode : public Node
{
public:
    IdentifierNode(const Span& span_);
    IdentifierNode(const Span& span_, NodeType nodeType_);
    IdentifierNode(const Span& span_, const std::u32string& identifier_);
    IdentifierNode(const Span& span_, NodeType nodeType_, const std::u32string& identifier_);
    IdentifierNode(const Span& span_, const soulng::lexer::Token& token);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    void Write(AstWriter& writer) override;
    void Read(AstReader& reader) override;
    const std::u32string& Str() const { return identifier; }
    std::string ToString() const override;
private:
    std::u32string identifier;
};

class CMAJOR_AST_API CursorIdNode : public IdentifierNode
{
public:
    CursorIdNode(const Span& span_);
    CursorIdNode(const Span& span_, const std::u32string& identifier_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    void Write(AstWriter& writer) override;
    void Read(AstReader& reader) override;
};

} } // namespace cmajor::ast

#endif // CMAJOR_AST_IDENTIFIER_INCLUDED
