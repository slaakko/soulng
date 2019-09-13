#include <minilang/Tree.hpp>

namespace minilang {

Node::~Node()
{
}

void Node::AddArgument(Node* arg)
{
	throw std::runtime_error("cannot add argument to this kind of node");
}

UnaryNode::UnaryNode(Node* child_) : child(child_)
{
}

UnaryOpExprNode::UnaryOpExprNode(Operator op_, Node* child_) : UnaryNode(child_), op(op_)
{
}

InvokeNode::InvokeNode(Node* child_) : UnaryNode(child_)
{
}

void InvokeNode::AddArgument(Node* arg)
{
	args.push_back(std::unique_ptr<Node>(arg));
}

BinaryNode::BinaryNode(Node* left_, Node* right_) : left(left_), right(right_)
{
}

BinaryOpExprNode::BinaryOpExprNode(Operator op_, Node* left_, Node* right_) : BinaryNode(left_, right_), op(op_)
{
}

BooleanLiteralNode::BooleanLiteralNode(bool value_) : value(value_)
{
}

IntegerLiteralNode::IntegerLiteralNode(int64_t value_) : value(value_)
{
}

IdentifierNode::IdentifierNode(const std::u32string& str_) : str(str_)
{
}

ParenthesizedExpressionNode::ParenthesizedExpressionNode(Node* child_) : UnaryNode(child_)
{
}

IfStatementNode::IfStatementNode(Node* condition_, Node* thenS_, Node* elseS_) : condition(condition_), thenS(thenS_), elseS(elseS_)
{
}

WhileStatementNode::WhileStatementNode(Node* condition_, Node* statement_) : condition(condition_), statement(statement_)
{
}

ReturnStatementNode::ReturnStatementNode(Node* returnValue_)
{
}

ConstructionStatementNode::ConstructionStatementNode(Node* type_, IdentifierNode* variableName_, Node* value_) : type(type_), variableName(variableName_), value(value_)
{
}

AssignmentStatementNode::AssignmentStatementNode(IdentifierNode* variableName_, Node* value_) : variableName(variableName_), value(value_)
{
}

void CompoundStatementNode::AddStatement(Node* statement)
{
	statements.push_back(std::unique_ptr<Node>(statement));
}

ParameterNode::ParameterNode(Node* paramType_, IdentifierNode* paramName_) : paramType(paramType_), paramName(paramName_)
{
}

FunctionNode::FunctionNode(Node* returnType_, IdentifierNode* functionName_) : returnType(returnType_), functionName(functionName_)
{
}

void FunctionNode::AddParam(ParameterNode* param)
{
	parameters.push_back(std::unique_ptr<ParameterNode>(param));
}

void FunctionNode::SetBody(CompoundStatementNode* body_)
{
	body.reset(body_);
}

void SourceFileNode::AddFunction(FunctionNode* function)
{
	functions.push_back(std::unique_ptr<FunctionNode>(function));
}

} // namespace minilang
