#ifndef MINILANG_TREE_HPP
#define MINILANG_TREE_HPP
#include <string>
#include <vector>
#include <stdint.h>
#include <memory>

namespace minilang {

class Visitor;

enum class Operator
{
	equal, notEqual, less, greater, lessOrEqual, greaterOrEqual, add, sub, mul, div, mod, unaryPlus, unaryMinus, not_
};

class Node
{
public:
	virtual ~Node();
	virtual void AddArgument(Node* arg);
	virtual void Accept(Visitor& visitor) = 0;
	virtual bool IsCompoundStatement() const { return false; }
};

class UnaryNode : public Node
{
public:
	UnaryNode(Node* child_);
	Node* Child() const { return child.get(); }
private:
	std::unique_ptr<Node> child;
};

class UnaryOpExprNode : public UnaryNode
{
public:
	UnaryOpExprNode(Operator op_, Node* child_);
	Operator Op() const { return op; }
	void Accept(Visitor& visitor) override;
private:
	Operator op;
};

class InvokeNode : public UnaryNode
{
public:
	InvokeNode(Node* child_);
	const std::vector<std::unique_ptr<Node>>& Args() const { return args; }
	void AddArgument(Node* arg) override;
	void Accept(Visitor& visitor) override;
private:
	std::vector<std::unique_ptr<Node>> args;
};

class BinaryNode : public Node
{
public:
	BinaryNode(Node* left_, Node* right_);
	Node* Left() const { return left.get(); }
	Node* Right() const { return right.get(); }
private:
	std::unique_ptr<Node> left;
	std::unique_ptr<Node> right;
};

class BinaryOpExprNode : public BinaryNode
{
public:
	BinaryOpExprNode(Operator op_, Node* left_, Node* right_);
	Operator Op() const { return op; }
	void Accept(Visitor& visitor) override;
private:
	Operator op;
};

class IntNode : public Node
{
public:
	void Accept(Visitor& visitor) override;
};

class BoolNode : public Node
{
public:
	void Accept(Visitor& visitor) override;
};

class VoidNode : public Node
{
public:
	void Accept(Visitor& visitor) override;
};

class BooleanLiteralNode : public Node
{
public:
	BooleanLiteralNode(bool value_);
	bool Value() const { return value; }
	void Accept(Visitor& visitor) override;
private:
	bool value;
};

class IntegerLiteralNode : public Node
{
public:
	IntegerLiteralNode(int64_t value_);
	int64_t Value() const { return value; }
	void Accept(Visitor& visitor) override;
private:
	int64_t value;
};

class IdentifierNode : public Node
{
public:
	IdentifierNode(const std::u32string& str_);
	const std::u32string& Str() const { return str; }
	void Accept(Visitor& visitor) override;
private:
	std::u32string str;
};

class ParenthesizedExpressionNode : public UnaryNode
{
public:
	ParenthesizedExpressionNode(Node* child_);
	void Accept(Visitor& visitor) override;
};

class IfStatementNode : public Node
{
public:
	IfStatementNode(Node* condition_, Node* thenS_, Node* elseS_);
	Node* Condition() const { return condition.get(); }
	Node* ThenS() const { return thenS.get(); }
	Node* ElseS() const { return elseS.get(); }
	void Accept(Visitor& visitor) override;
private:
	std::unique_ptr<Node> condition;
	std::unique_ptr<Node> thenS;
	std::unique_ptr<Node> elseS;
};

class WhileStatementNode : public Node
{
public:
	WhileStatementNode(Node* condition_, Node* statement_);
	Node* Condition() const { return condition.get(); }
	Node* Statement() const { return statement.get(); }
	void Accept(Visitor& visitor) override;
private:
	std::unique_ptr<Node> condition;
	std::unique_ptr<Node> statement;
};

class ReturnStatementNode : public Node
{
public:
	ReturnStatementNode(Node* returnValue_);
	Node* ReturnValue() const { return returnValue.get(); }
	void Accept(Visitor& visitor) override;
private:
	std::unique_ptr<Node> returnValue;
};

class ConstructionStatementNode : public Node
{
public:
	ConstructionStatementNode(Node* type_, IdentifierNode* variableName_, Node* value_);
	Node* Type() const { return type.get(); }
	IdentifierNode* VariableName() const { return variableName.get(); }
	Node* Value() const { return value.get(); }
	void Accept(Visitor& visitor) override;
private:
	std::unique_ptr<Node> type;
	std::unique_ptr<IdentifierNode> variableName;
	std::unique_ptr<Node> value;
};

class AssignmentStatementNode : public Node
{
public:
	AssignmentStatementNode(IdentifierNode* variableName_, Node* value_);
	IdentifierNode* VariableName() const { return variableName.get(); }
	Node* Value() const { return value.get(); }
	void Accept(Visitor& visitor) override;
private:
	std::unique_ptr<IdentifierNode> variableName;
	std::unique_ptr<Node> value;
};

class CompoundStatementNode : public Node
{
public:
	void AddStatement(Node* statement);
	const std::vector<std::unique_ptr<Node>>& Statements() const { return statements; }
	void Accept(Visitor& visitor) override;
	bool IsCompoundStatement() const override { return true; }
private:
	std::vector<std::unique_ptr<Node>> statements;
};

class ParameterNode : public Node
{
public:
	ParameterNode(Node* paramType_, IdentifierNode* paramName_);
	Node* ParamType() const { return paramType.get(); }
	IdentifierNode* ParamName() const { return paramName.get(); }
	void Accept(Visitor& visitor) override;
private:
	std::unique_ptr<Node> paramType;
	std::unique_ptr<IdentifierNode> paramName;
};

class FunctionNode : public Node
{
public:
	FunctionNode(Node* returnType_, IdentifierNode* functionName_);
	Node* ReturnType() const { return returnType.get(); }
	IdentifierNode* FunctionName() const { return functionName.get(); }
	void AddParam(ParameterNode* param);
	const std::vector<std::unique_ptr<ParameterNode>>& Parameters() const { return parameters; }
	void SetBody(CompoundStatementNode* body_);
	CompoundStatementNode* Body() const { return body.get(); }
	void Accept(Visitor& visitor) override;
private:
	std::unique_ptr<Node> returnType;
	std::unique_ptr<IdentifierNode> functionName;
	std::vector<std::unique_ptr<ParameterNode>> parameters;
	std::unique_ptr<CompoundStatementNode> body;
};

class SourceFileNode : public Node
{
public:
	void AddFunction(FunctionNode* function);
	const std::vector<std::unique_ptr<FunctionNode>>& Functions() const { return functions; }
	void Accept(Visitor& visitor) override;
private:
	std::vector<std::unique_ptr<FunctionNode>> functions;
};

} // namespace minilang

#endif // MINILANG_TREE_HPP
