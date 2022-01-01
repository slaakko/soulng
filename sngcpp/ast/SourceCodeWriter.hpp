// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_SOURCE_CODE_WRITER_INCLUDED
#define SNGCPP_AST_SOURCE_CODE_WRITER_INCLUDED
#include <sngcpp/ast/AstApi.hpp>
#include <string>

namespace sngcpp { namespace ast {

class SNGCPP_AST_API SourceCodeWriter
{
public:
    virtual ~SourceCodeWriter();
    virtual void WriteLineNumber(const std::u32string& lineNumber) = 0;
    virtual void WriteLineComment(const std::u32string& comment) = 0;
    virtual void WriteBlockComment(const std::u32string& comment) = 0;
    virtual void WriteKeyword(const std::u32string& keyword) = 0;
    virtual void WriteIdentifier(const std::u32string& identifier) = 0;
    virtual void WriteLink(const std::u32string& identifier, const std::u32string& ref) = 0;
    virtual void WritePP(const std::u32string& pp) = 0;
    virtual void WriteChar(const std::u32string& chars) = 0;
    virtual void WriteString(const std::u32string& string) = 0;
    virtual void WriteNumber(const std::u32string& number) = 0;
    virtual void WriteType(const std::u32string& type) = 0;
    virtual void WriteSpace(int numSpaces) = 0;
    virtual void WriteSpaces(const std::u32string& spaces) = 0;
    virtual void WriteOther(const std::u32string& other) = 0;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_SOURCE_CODE_WRITER_INCLUDED
