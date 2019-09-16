#ifndef MINILANG_PRINTER_VISITOR_HPP
#define MINILANG_PRINTER_VISITOR_HPP
#include <minilang/Visitor.hpp>
#include <soulng/util/CodeFormatter.hpp>

namespace minilang {

class PrinterVisitor : public Visitor
{
public:
	PrinterVisitor(soulng::util::CodeFormatter& formatter_);
	void Visit(UnaryOpExprNode& node) override;
	void Visit(InvokeNode& node) override;
	void Visit(BinaryOpExprNode& node) override;
	void Visit(IntNode& node) override;
	void Visit(BoolNode& node) override;
	void Visit(VoidNode& node) override;
	void Visit(BooleanLiteralNode& node) override;
	void Visit(IntegerLiteralNode& node) override;
	void Visit(IdentifierNode& node) override;
	void Visit(ParenthesizedExpressionNode& node) override;
	void Visit(IfStatementNode& node) override;
	void Visit(WhileStatementNode& node) override;
	void Visit(ReturnStatementNode& node) override;
	void Visit(ConstructionStatementNode& node) override;
	void Visit(AssignmentStatementNode& node) override;
	void Visit(CompoundStatementNode& node) override;
	void Visit(ParameterNode& node) override;
	void Visit(FunctionNode& node) override;
	void Visit(SourceFileNode& node) override;
private:
	soulng::util::CodeFormatter& formatter;
};

} // namespace minilang

#endif // MINILANG_PRINTER_VISITOR_HPP
