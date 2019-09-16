#ifndef MINILANG_VISITOR_HPP
#define MINILANG_VISITOR_HPP

namespace minilang {

class UnaryOpExprNode;
class InvokeNode;
class BinaryOpExprNode;
class IntNode;
class BoolNode;
class VoidNode;
class BooleanLiteralNode;
class IntegerLiteralNode;
class IdentifierNode;
class ParenthesizedExpressionNode;
class IfStatementNode;
class WhileStatementNode;
class ReturnStatementNode;
class ConstructionStatementNode;
class AssignmentStatementNode;
class CompoundStatementNode;
class ParameterNode;
class FunctionNode;
class SourceFileNode;

class Visitor
{
public:
	virtual void Visit(UnaryOpExprNode& node) {}
	virtual void Visit(InvokeNode& node) {}
	virtual void Visit(BinaryOpExprNode& node) {}
	virtual void Visit(IntNode& node) {}
	virtual void Visit(BoolNode& node) {}
	virtual void Visit(VoidNode& node) {}
	virtual void Visit(BooleanLiteralNode& node) {}
	virtual void Visit(IntegerLiteralNode& node) {}
	virtual void Visit(IdentifierNode& node) {}
	virtual void Visit(ParenthesizedExpressionNode& node) {}
	virtual void Visit(IfStatementNode& node) {}
	virtual void Visit(WhileStatementNode& node) {}
	virtual void Visit(ReturnStatementNode& node) {}
	virtual void Visit(ConstructionStatementNode& node) {}
	virtual void Visit(AssignmentStatementNode& node) {}
	virtual void Visit(CompoundStatementNode& node) {}
	virtual void Visit(ParameterNode& node) {}
	virtual void Visit(FunctionNode& node) {}
	virtual void Visit(SourceFileNode& node) {}
};

} // namespace minilang

#endif // MINILANG_VISITOR_HPP
