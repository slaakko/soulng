// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_WRITER_INCLUDED
#define SNGCPP_AST_WRITER_INCLUDED
#include <sngcpp/ast/AstApi.hpp>
#include <sngcpp/ast/SimpleType.hpp>
#include <sngcpp/ast/Specifier.hpp>
#include <sngcpp/ast/Class.hpp>
#include <sngcpp/ast/Enumeration.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Literal.hpp>
#include <soulng/lexer/Lexer.hpp>
#include <soulng/util/BinaryWriter.hpp>

namespace sngcpp { namespace ast {

class SNGCPP_AST_API Writer
{
public:
    Writer(const std::vector<soulng::lexer::Lexer*>& lexers_, soulng::util::BinaryWriter& binaryWriter_);
    void Write(soulng::lexer::Span& span);
    void Write(SimpleTypeSpecifier specifier);
    void Write(NodeType nodeType);
    void Write(Specifier specifiers);
    void Write(ClassKey classKey);
    void Write(EnumKey enumKey);
    void Write(Operator op);
    void Write(Suffix suffix);
    void Write(Base base);
    soulng::util::BinaryWriter& GetBinaryWriter() { return binaryWriter; }
private:
    const std::vector<soulng::lexer::Lexer*>& lexers;
    soulng::util::BinaryWriter& binaryWriter;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_WRITER_INCLUDED
