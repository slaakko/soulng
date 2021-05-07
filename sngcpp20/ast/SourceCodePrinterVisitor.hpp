// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_SOURCE_CODE_PRINTER_VISITOR_INCLUDED
#define SNGCPP_AST_SOURCE_CODE_PRINTER_VISITOR_INCLUDED
#include <sngcpp20/ast/Visitor.hpp>
#include <soulng/util/CodeFormatter.hpp>

namespace sngcpp::ast {

using namespace soulng::util;

class AST_API SourceCodePrinterVisitor : public DefaultVisitor
{
public:
    SourceCodePrinterVisitor(std::ostream& stream);
    void BeginVisit(Node& node) override;
    void VisitIdentfier(const std::u32string& id, const SourcePos& sourcePos) override;
    void VisitKeyword(const std::string& keyword, const SourcePos& sourcePos) override;
    void VisitOperator(const std::string& symbol, const SourcePos& sourcePos) override;
    void VisitToken(const std::u32string& tokenStr, const SourcePos& sourcePos) override;
    void VisitLiteral(const std::u32string& rep, const SourcePos& sourcePos) override;
    void VisitHeaderName(const std::u32string& rep, const SourcePos& sourcePos) override;
private:
    void Move(const SourcePos& sourcePos);
    void Move(const std::u32string& str);
    void Write(const std::string& str);
    void Write(const std::u32string& str);
    CodeFormatter formatter;
    int line;
    int col;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_SOURCE_CODE_PRINTER_VISITOR_INCLUDED
