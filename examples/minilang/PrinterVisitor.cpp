#include <minilang/PrinterVisitor.hpp>
#include <minilang/Tree.hpp>
#include <soulng/util/Unicode.hpp>

namespace minilang {

std::string OperatorStr(Operator op)
{
	switch (op)
	{
		case Operator::equal: return "==";
		case Operator::notEqual: return "!=";
		case Operator::less: return "<";
		case Operator::greater: return ">";
		case Operator::lessOrEqual: return "<=";
		case Operator::greaterOrEqual: return ">=";
		case Operator::add: return "+";
		case Operator::sub: return "-";
		case Operator::mul: return "*";
		case Operator::div: return "/";
		case Operator::mod: return "%";
		case Operator::unaryPlus: return "+";
		case Operator::unaryMinus: return "-";
		case Operator::not_: return "!";
	}
	return std::string();
}

PrinterVisitor::PrinterVisitor(soulng::util::CodeFormatter& formatter_) : formatter(formatter_)
{
}

void PrinterVisitor::Visit(UnaryOpExprNode& node)
{
	formatter.Write(OperatorStr(node.Op()));
	node.Child()->Accept(*this);
}

void PrinterVisitor::Visit(InvokeNode& node)
{
	node.Child()->Accept(*this);
	formatter.Write("(");
	bool first = true;
	for (const auto& arg : node.Args())
	{
		if (first)
		{
			first = false;
		}
		else
		{
			formatter.Write(", ");
		}
		arg->Accept(*this);
	}
	formatter.Write(")");
}

void PrinterVisitor::Visit(BinaryOpExprNode& node)
{
	node.Left()->Accept(*this);
	formatter.Write(" ");
	formatter.Write(OperatorStr(node.Op()));
	formatter.Write(" ");
	node.Right()->Accept(*this);
}

void PrinterVisitor::Visit(IntNode& node)
{
	formatter.Write("int");
}

void PrinterVisitor::Visit(BoolNode& node)
{
	formatter.Write("bool");
}

void PrinterVisitor::Visit(VoidNode& node)
{
	formatter.Write("void");
}

void PrinterVisitor::Visit(BooleanLiteralNode& node)
{
	if (node.Value())
	{
		formatter.Write("true");
	}
	else
	{
		formatter.Write("false");
	}
}

void PrinterVisitor::Visit(IntegerLiteralNode& node)
{
	formatter.Write(std::to_string(node.Value()));
}

void PrinterVisitor::Visit(IdentifierNode& node)
{
	formatter.Write(soulng::unicode::ToUtf8(node.Str()));
}

void PrinterVisitor::Visit(ParenthesizedExpressionNode& node)
{
	formatter.Write("(");
	node.Child()->Accept(*this);
	formatter.Write(")");
}

void PrinterVisitor::Visit(IfStatementNode& node)
{
	formatter.Write("if (");
	node.Condition()->Accept(*this);
	formatter.Write(")");
	if (node.ThenS()->IsCompoundStatement())
	{
		formatter.WriteLine();
	}
	else
	{
		formatter.Write(" ");
	}
	node.ThenS()->Accept(*this);
	if (node.ElseS() != nullptr)
	{
		if (node.ThenS()->IsCompoundStatement())
		{
			formatter.WriteLine();
		}
		else
		{
			formatter.Write(" ");
		}
		formatter.Write("else");
		if (node.ElseS()->IsCompoundStatement())
		{
			formatter.WriteLine();
		}
		else
		{
			formatter.Write(" ");
		}
		node.ElseS()->Accept(*this);
	}
}

void PrinterVisitor::Visit(WhileStatementNode& node)
{
	formatter.Write("while (");
	node.Condition()->Accept(*this);
	formatter.Write(")");
	if (node.Statement()->IsCompoundStatement())
	{
		formatter.WriteLine();
	}
	else
	{
		formatter.Write(" ");
	}
	node.Statement()->Accept(*this);
}

void PrinterVisitor::Visit(ReturnStatementNode& node)
{
	formatter.Write("return");
	if (node.ReturnValue() != nullptr)
	{
		formatter.Write(" ");
		node.ReturnValue()->Accept(*this);
	}
	formatter.WriteLine(";");
}

void PrinterVisitor::Visit(ConstructionStatementNode& node)
{
	node.Type()->Accept(*this);
	formatter.Write(" ");
	node.VariableName()->Accept(*this);
	formatter.Write(" = ");
	node.Value()->Accept(*this);
	formatter.WriteLine(";");
}

void PrinterVisitor::Visit(AssignmentStatementNode& node)
{
	node.VariableName()->Accept(*this);
	formatter.Write(" = ");
	node.Value()->Accept(*this);
	formatter.WriteLine(";");
}

void PrinterVisitor::Visit(CompoundStatementNode& node)
{
	formatter.WriteLine("{");
	formatter.IncIndent();
	for (const auto& statement : node.Statements())
	{
		statement->Accept(*this);
	}
	formatter.DecIndent();
	formatter.WriteLine("}");
}

void PrinterVisitor::Visit(ParameterNode& node)
{
	node.ParamType()->Accept(*this);
	formatter.Write(" ");
	node.ParamName()->Accept(*this);
}

void PrinterVisitor::Visit(FunctionNode& node)
{
	node.ReturnType()->Accept(*this);
	formatter.Write(" ");
	node.FunctionName()->Accept(*this);
	formatter.Write("(");
	bool first = true;
	for (const auto& param : node.Parameters())
	{
		if (first)
		{
			first = false;
		}
		else
		{
			formatter.Write(", ");
		}
		param->Accept(*this);
	}
	formatter.WriteLine(")");
	node.Body()->Accept(*this);
}

void PrinterVisitor::Visit(SourceFileNode& node)
{
	bool first = true;
	for (const auto& function : node.Functions())
	{
		if (first)
		{
			first = false;
		}
		else
		{
			formatter.WriteLine();
		}
		function->Accept(*this);
	}
}

} // namespace minilang
