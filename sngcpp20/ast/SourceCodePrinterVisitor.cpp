// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/SourceCodePrinterVisitor.hpp>
#include <sngcpp20/ast/Node.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::ast {

using namespace soulng::unicode;

SourceCodePrinterVisitor::SourceCodePrinterVisitor(std::ostream& stream) : formatter(stream), line(1), col(1)
{
}

void SourceCodePrinterVisitor::Move(const SourcePos& sourcePos)
{
    while (sourcePos.line > line)
    {
        formatter.WriteLine();
        ++line;
        col = 1;
    }
    if (sourcePos.col > col)
    {
        int n = sourcePos.col - col;
        formatter.Write(std::string(n, ' '));
        col += n;
    }
}

void SourceCodePrinterVisitor::Move(const std::u32string& str)
{
    for (char32_t c : str)
    {
        if (c == '\n')
        {
            ++line;
            col = 1;
        }
        else if (c == '\t')
        {
            col += 4;
        }
        else
        {
            ++col;
        }
    }
}

void SourceCodePrinterVisitor::Write(const std::string& str)
{
    formatter.Write(str);
    Move(ToUtf32(str));
}

void SourceCodePrinterVisitor::Write(const std::u32string& str)
{
    formatter.Write(ToUtf8(str));
    Move(str);
}

void SourceCodePrinterVisitor::BeginVisit(Node& node)
{
    Move(node.GetSourcePos());
}

void SourceCodePrinterVisitor::VisitIdentfier(const std::u32string& id, const SourcePos& sourcePos)
{
    Move(sourcePos);
    Write(id);
}

void SourceCodePrinterVisitor::VisitKeyword(const std::string& keyword, const SourcePos& sourcePos)
{
    Move(sourcePos);
    Write(keyword);
}

void SourceCodePrinterVisitor::VisitOperator(const std::string& symbol, const SourcePos& sourcePos)
{
    Move(sourcePos);
    Write(symbol);
}

void SourceCodePrinterVisitor::VisitToken(const std::u32string& tokenStr, const SourcePos& sourcePos)
{
    Move(sourcePos);
    Write(tokenStr);
}

void SourceCodePrinterVisitor::VisitLiteral(const std::u32string& rep, const SourcePos& sourcePos)
{
    Move(sourcePos);
    Write(rep);
}

void SourceCodePrinterVisitor::VisitHeaderName(const std::u32string& rep, const SourcePos& sourcePos)
{
    Move(sourcePos);
    Write(rep);
}

} // namespace sngcpp::ast
