// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

std::u32string OpStr(Operator op)
{
    switch (op)
    {
        case Operator::assign: return U" = ";
        case Operator::mulAssign: return U" *= ";
        case Operator::divAssign: return U" /= ";
        case Operator::remAssign: return U" %= ";
        case Operator::addAssign: return U" += ";
        case Operator::subAssign: return U" -= ";
        case Operator::shiftRightAssign: return U" >>= ";
        case Operator::shiftLeftAssign: return U" <<= ";
        case Operator::andAssign: return U" &= ";
        case Operator::xorAssign: return U" ^= ";
        case Operator::orAssign: return U" |= ";
        case Operator::equal: return U" == ";
        case Operator::notEqual: return U" != ";
        case Operator::lessOrEqual: return U" <= ";
        case Operator::greaterOrEqual: return U" >= ";
        case Operator::less: return U" < ";
        case Operator::greater: return U" > ";
        case Operator::shiftLeft: return U" << ";
        case Operator::shiftRight: return U" >> ";
        case Operator::add: return U" + ";
        case Operator::sub: return U" - ";
        case Operator::mul: return U" * ";
        case Operator::div: return U" / ";
        case Operator::rem: return U" % ";
        case Operator::dotStar: return U".*";
        case Operator::arrowStar: return U"->*";
        case Operator::arrow: return U"->";
        case Operator::inc: return U"++";
        case Operator::dec: return U"--";
        case Operator::deref: return U"*";
        case Operator::addrOf: return U"&";
        case Operator::unaryPlus: return U"+";
        case Operator::unaryMinus: return U"-";
        case Operator::not_: return U"!";
        case Operator::complement: return U"~";
        case Operator::sizeOf: return U"sizeof";
        case Operator::alignOf: return U"alignof";
        case Operator::dynamicCast: return U"dynamic_cast";
        case Operator::staticCast: return U"static_cast";
        case Operator::reinterpretCast: return U"reinterpret_cast";
        case Operator::constCast: return U"const_cast";
        case Operator::logicalAnd: return U" && ";
        case Operator::logicalOr: return U" || ";
        case Operator::xor_: return U" ^ ";
        case Operator::and_: return U" & ";
        case Operator::or_: return U" | ";
        case Operator::apply: return U"()";
        case Operator::subscript: return U"[]";
        case Operator::comma: return U", ";
        case Operator::newArray: return U"new []";
        case Operator::deleteArray: return U"delete []";
        case Operator::new_: return U"new";
        case Operator::delete_: return U"delete";
    }
    return std::u32string();
}

ExpressionSequenceNode::ExpressionSequenceNode() : BinaryNode(NodeType::expressionSequenceNode)
{
}

ExpressionSequenceNode::ExpressionSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::expressionSequenceNode, span_, left_, right_)
{
}

void ExpressionSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CommaExpressionNode::CommaExpressionNode() : BinaryNode(NodeType::commaExpressionNode)
{
}

CommaExpressionNode::CommaExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::commaExpressionNode, span_, left_, right_)
{
}

void CommaExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AssignmentExpressionNode::AssignmentExpressionNode() : BinaryNode(NodeType::assignmentExpressionNode)
{
}

AssignmentExpressionNode::AssignmentExpressionNode(const Span& span_, Node* left_, Operator op_, Node* right_) : BinaryNode(NodeType::assignmentExpressionNode, span_, left_, right_), op(op_)
{
}

void AssignmentExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void AssignmentExpressionNode::Write(Writer& writer)
{
    BinaryNode::Write(writer);
    writer.Write(op);
}

void AssignmentExpressionNode::Read(Reader& reader)
{
    BinaryNode::Read(reader);
    op = reader.ReadOperator();
}

ConditionalExpressionNode::ConditionalExpressionNode() : Node(NodeType::conditionalExpressionNode)
{
}

ConditionalExpressionNode::ConditionalExpressionNode(const Span& span_, Node* condition_, Node* thenExpr_, Node* elseExpr_) :
    Node(NodeType::conditionalExpressionNode, span_), condition(condition_), thenExpr(thenExpr_), elseExpr(elseExpr_)
{
}

void ConditionalExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ConditionalExpressionNode::Write(Writer& writer)
{
    Node::Write(writer);
    condition->Write(writer);
    thenExpr->Write(writer);
    elseExpr->Write(writer);
}

void ConditionalExpressionNode::Read(Reader& reader)
{
    Node::Read(reader);
    condition.reset(reader.ReadNode());
    thenExpr.reset(reader.ReadNode());
    elseExpr.reset(reader.ReadNode());
}

ThrowExpressionNode::ThrowExpressionNode() : UnaryNode(NodeType::throwExpressionNode)
{
}

ThrowExpressionNode::ThrowExpressionNode(const Span& span_, Node* exceptionExpr_) : UnaryNode(NodeType::throwExpressionNode, span_, exceptionExpr_)
{
}

void ThrowExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LogicalOrExpressionNode::LogicalOrExpressionNode() : BinaryNode(NodeType::logicalOrExpressionNode)
{
}

LogicalOrExpressionNode::LogicalOrExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::logicalOrExpressionNode, span_, left_, right_)
{
}

void LogicalOrExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LogicalAndExpressionNode::LogicalAndExpressionNode() : BinaryNode(NodeType::logicalAndExpressionNode)
{
}

LogicalAndExpressionNode::LogicalAndExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::logicalAndExpressionNode, span_, left_, right_)
{
}

void LogicalAndExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

InclusiveOrExpressionNode::InclusiveOrExpressionNode() : BinaryNode(NodeType::inclusiveOrExpressionNode)
{
}

InclusiveOrExpressionNode::InclusiveOrExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::inclusiveOrExpressionNode, span_, left_, right_)
{
}

void InclusiveOrExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExclusiveOrExpressionNode::ExclusiveOrExpressionNode() : BinaryNode(NodeType::exclusiveOrExpressionNode)
{
}

ExclusiveOrExpressionNode::ExclusiveOrExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::exclusiveOrExpressionNode, span_, left_, right_)
{
}

void ExclusiveOrExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AndExpressionNode::AndExpressionNode() : BinaryNode(NodeType::andExpressionNode)
{
}

AndExpressionNode::AndExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::andExpressionNode, span_, left_, right_)
{
}

void AndExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

EqualityExpressionNode::EqualityExpressionNode() : BinaryNode(NodeType::equalityExpressionNode), op()
{
}

EqualityExpressionNode::EqualityExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(NodeType::equalityExpressionNode, span_, left_, right_), op(op_)
{
}

void EqualityExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void EqualityExpressionNode::Write(Writer& writer)
{
    BinaryNode::Write(writer);
    writer.Write(op);
}

void EqualityExpressionNode::Read(Reader& reader)
{
    BinaryNode::Read(reader);
    op = reader.ReadOperator();
}

RelationalExpressionNode::RelationalExpressionNode() : BinaryNode(NodeType::relationalExpressionNode), op()
{
}

RelationalExpressionNode::RelationalExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(NodeType::relationalExpressionNode, span_, left_, right_), op(op_)
{
}

void RelationalExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void RelationalExpressionNode::Write(Writer& writer)
{
    BinaryNode::Write(writer);
    writer.Write(op);
}

void RelationalExpressionNode::Read(Reader& reader)
{
    BinaryNode::Read(reader);
    op = reader.ReadOperator();
}

ShiftExpressionNode::ShiftExpressionNode() : BinaryNode(NodeType::shiftExpressionNode), op()
{
}

ShiftExpressionNode::ShiftExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(NodeType::shiftExpressionNode, span_, left_, right_), op(op_)
{
}

void ShiftExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ShiftExpressionNode::Write(Writer& writer)
{
    BinaryNode::Write(writer);
    writer.Write(op);
}

void ShiftExpressionNode::Read(Reader& reader)
{
    BinaryNode::Read(reader);
    op = reader.ReadOperator();
}

AdditiveExpressionNode::AdditiveExpressionNode() : BinaryNode(NodeType::additiveExpressionNode), op()
{
}

AdditiveExpressionNode::AdditiveExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(NodeType::additiveExpressionNode, span_, left_, right_), op(op_)
{
}

void AdditiveExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void AdditiveExpressionNode::Write(Writer& writer)
{
    BinaryNode::Write(writer);
    writer.Write(op);
}

void AdditiveExpressionNode::Read(Reader& reader)
{
    BinaryNode::Read(reader);
    op = reader.ReadOperator();
}

MultiplicativeExpressionNode::MultiplicativeExpressionNode() : BinaryNode(NodeType::multiplicativeExpressionNode), op()
{
}

MultiplicativeExpressionNode::MultiplicativeExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(NodeType::multiplicativeExpressionNode, span_, left_, right_), op(op_)
{
}

void MultiplicativeExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void MultiplicativeExpressionNode::Write(Writer& writer)
{
    BinaryNode::Write(writer);
    writer.Write(op);
}

void MultiplicativeExpressionNode::Read(Reader& reader)
{
    BinaryNode::Read(reader);
    op = reader.ReadOperator();
}

PMExpressionNode::PMExpressionNode() : BinaryNode(NodeType::pmExpressionNode), op()
{
}

PMExpressionNode::PMExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(NodeType::pmExpressionNode, span_, left_, right_), op(op_)
{
}

void PMExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void PMExpressionNode::Write(Writer& writer)
{
    BinaryNode::Write(writer);
    writer.Write(op);
}

void PMExpressionNode::Read(Reader& reader)
{
    BinaryNode::Read(reader);
    op = reader.ReadOperator();
}

CastExpressionNode::CastExpressionNode() : Node(NodeType::castExpressionNode)
{
}

CastExpressionNode::CastExpressionNode(const Span& span_, Node* typeExpr_, Node* expr_) : Node(NodeType::castExpressionNode, span_), typeExpr(typeExpr_), expr(expr_)
{
}

void CastExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CastExpressionNode::Write(Writer& writer)
{
    Node::Write(writer);
    typeExpr->Write(writer);
    expr->Write(writer);
}

void CastExpressionNode::Read(Reader& reader)
{
    Node::Read(reader);
    typeExpr.reset(reader.ReadNode());
    expr.reset(reader.ReadNode());
}

UnaryExpressionNode::UnaryExpressionNode() : UnaryNode(NodeType::unaryExpressionNode), op()
{
}

UnaryExpressionNode::UnaryExpressionNode(const Span& span_, Operator op_, Node* expr_) : UnaryNode(NodeType::unaryExpressionNode, span_, expr_), op(op_)
{
}

void UnaryExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void UnaryExpressionNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(op);
}

void UnaryExpressionNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    op = reader.ReadOperator();
}

NewExpressionNode::NewExpressionNode() : Node(NodeType::newExpressionNode)
{
}

NewExpressionNode::NewExpressionNode(const Span& span_, Node* placement_, Node* typeExpr_, Node* initializer_) :
    Node(NodeType::newExpressionNode, span_), placement(placement_), typeExpr(typeExpr_), initializer(initializer_)
{
}

void NewExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void NewExpressionNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(placement != nullptr);
    if (placement)
    {
        placement->Write(writer);
    }
    typeExpr->Write(writer);
    writer.GetBinaryWriter().Write(initializer != nullptr);
    if (initializer)
    {
        initializer->Write(writer);
    }
}

void NewExpressionNode::Read(Reader& reader)
{
    Node::Read(reader);
    bool hasPlacement = reader.GetBinaryReader().ReadBool();
    if (hasPlacement)
    {
        placement.reset(reader.ReadNode());
    }
    typeExpr.reset(reader.ReadNode());
    bool hasInitializer = reader.GetBinaryReader().ReadBool();
    if (hasInitializer)
    {
        initializer.reset(reader.ReadNode());
    }
}

DeleteExpressionNode::DeleteExpressionNode() : UnaryNode(NodeType::deleteExpressionNode), array_()
{
}

DeleteExpressionNode::DeleteExpressionNode(const Span& span_, bool array__, Node* ptr_) : UnaryNode(NodeType::deleteExpressionNode, span_, ptr_), array_(array__)
{
}

void DeleteExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void DeleteExpressionNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.GetBinaryWriter().Write(array_);
}

void DeleteExpressionNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    array_ = reader.GetBinaryReader().ReadBool();
}

SubscriptExpressionNode::SubscriptExpressionNode() : UnaryNode(NodeType::subscriptExpressionNode)
{
}

SubscriptExpressionNode::SubscriptExpressionNode(const Span& span_, Node* subject_, Node* index_) : UnaryNode(NodeType::subscriptExpressionNode, span_, subject_), index(index_)
{
}

void SubscriptExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SubscriptExpressionNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    index->Write(writer);
}

void SubscriptExpressionNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    index.reset(reader.ReadNode());
}

InvokeExpressionNode::InvokeExpressionNode() : UnaryNode(NodeType::invokeExpressionNode)
{
}

InvokeExpressionNode::InvokeExpressionNode(const Span& span_, Node* subject_, Node* arguments_) : UnaryNode(NodeType::invokeExpressionNode, span_, subject_), arguments(arguments_)
{
}

void InvokeExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void InvokeExpressionNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.GetBinaryWriter().Write(arguments != nullptr);
    if (arguments)
    {
        arguments->Write(writer);
    }
}

void InvokeExpressionNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    bool hasArguments = reader.GetBinaryReader().ReadBool();
    if (hasArguments)
    {
        arguments.reset(reader.ReadNode());
    }
}

DotNode::DotNode() : UnaryNode(NodeType::dotNode)
{
}

DotNode::DotNode(const Span& span_, Node* subject_, Node* id_) : UnaryNode(NodeType::dotNode, span_, subject_), id(id_)
{
}

void DotNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void DotNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    id->Write(writer);
}

void DotNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    id.reset(reader.ReadNode());
}

ArrowNode::ArrowNode() : UnaryNode(NodeType::arrowNode)
{
}

ArrowNode::ArrowNode(const Span& span_, Node* subject_, Node* id_) : UnaryNode(NodeType::arrowNode, span_, subject_), id(id_)
{
}

void ArrowNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ArrowNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    id->Write(writer);
}

void ArrowNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    id.reset(reader.ReadNode());
}

PostfixIncNode::PostfixIncNode() : UnaryNode(NodeType::postfixIncNode)
{
}

PostfixIncNode::PostfixIncNode(const Span& span_, Node* subject_) : UnaryNode(NodeType::postfixIncNode, span_, subject_)
{
}

void PostfixIncNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PostfixDecNode::PostfixDecNode() : UnaryNode(NodeType::postfixDecNode)
{
}

PostfixDecNode::PostfixDecNode(const Span& span_, Node* subject_) : UnaryNode(NodeType::postfixDecNode, span_, subject_)
{
}

void PostfixDecNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CppCastExpressionNode::CppCastExpressionNode() : Node(NodeType::cppCastExpressionNode), op()
{
}

CppCastExpressionNode::CppCastExpressionNode(const Span& span_, Node* typeExpr_, Node* expr_, Operator op_) : Node(NodeType::cppCastExpressionNode, span_), typeExpr(typeExpr_), expr(expr_), op(op_)
{
}

void CppCastExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CppCastExpressionNode::Write(Writer& writer)
{
    Node::Write(writer);
    typeExpr->Write(writer);
    expr->Write(writer);
    writer.Write(op);
}

void CppCastExpressionNode::Read(Reader& reader)
{
    Node::Read(reader);
    typeExpr.reset(reader.ReadNode());
    expr.reset(reader.ReadNode());
    op = reader.ReadOperator();
}

TypeIdExpressionNode::TypeIdExpressionNode() : UnaryNode(NodeType::typeIdExpressionNode)
{
}

TypeIdExpressionNode::TypeIdExpressionNode(const Span& span_, Node* subject_) : UnaryNode(NodeType::typeIdExpressionNode, span_, subject_)
{
}

void TypeIdExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ThisNode::ThisNode() : Node(NodeType::thisNode)
{
}

ThisNode::ThisNode(const Span& span_) : Node(NodeType::thisNode, span_)
{
}

void ThisNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

IdentifierNode::IdentifierNode() : Node(NodeType::identifierNode)
{
}

IdentifierNode::IdentifierNode(NodeType nodeType_) : Node(nodeType_)
{
}

IdentifierNode::IdentifierNode(const Span& span_, const std::u32string& identifier_) : Node(NodeType::identifierNode, span_), identifier(identifier_)
{
}

IdentifierNode::IdentifierNode(NodeType nodeType_, const Span& span_, const std::u32string& identifier_) : Node(nodeType_, span_), identifier(identifier_)
{
}

void IdentifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void IdentifierNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(identifier);
}

void IdentifierNode::Read(Reader& reader)
{
    Node::Read(reader);
    identifier = reader.GetBinaryReader().ReadUtf32String();
}

OperatorFunctionIdNode::OperatorFunctionIdNode() : IdentifierNode(NodeType::operatorFunctionIdNode), op()
{
}

OperatorFunctionIdNode::OperatorFunctionIdNode(const Span& span_, Operator op_) : IdentifierNode(NodeType::operatorFunctionIdNode, span_, U"operator"), op(op_)
{
}

void OperatorFunctionIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void OperatorFunctionIdNode::Write(Writer& writer)
{
    IdentifierNode::Write(writer);
    writer.Write(op);
}

void OperatorFunctionIdNode::Read(Reader& reader)
{
    IdentifierNode::Read(reader);
    op = reader.ReadOperator();
}

std::u32string OperatorFunctionIdNode::OpStr() const
{
    switch (op)
    {
        case Operator::newArray: return U" new[]";
        case Operator::deleteArray: return U" delete[]";
        case Operator::new_: return U" new";
        case Operator::delete_: return U" delete";
        case Operator::assign: return U"=";
        case Operator::mulAssign: return U"*=";
        case Operator::divAssign: return U"/=";
        case Operator::remAssign: return U"%=";
        case Operator::addAssign: return U"+=";
        case Operator::subAssign: return U"-=";
        case Operator::shiftLeftAssign: return U"<<=";
        case Operator::shiftRightAssign: return U">>=";
        case Operator::andAssign: return U"&=";
        case Operator::xorAssign: return U"^=";
        case Operator::orAssign: return U"|=";
        case Operator::inc: return U"++";
        case Operator::dec: return U"--";
        case Operator::shiftLeft: return U"<<";
        case Operator::shiftRight: return U">>";
        case Operator::logicalAnd: return U"&&";
        case Operator::logicalOr: return U"||";
        case Operator::equal: return U"==";
        case Operator::notEqual: return U"!=";
        case Operator::lessOrEqual: return U"<=";
        case Operator::greaterOrEqual: return U">=";
        case Operator::dotStar: return U".*";
        case Operator::arrowStar: return U"->*";
        case Operator::arrow: return U"->";
        case Operator::apply: return U"()";
        case Operator::subscript: return U"[]";
        case Operator::less: return U"<";
        case Operator::greater: return U">";
        case Operator::add: return U"+";
        case Operator::sub: return U"-";
        case Operator::mul: return U"*";
        case Operator::div: return U"/";
        case Operator::rem: return U"%";
        case Operator::xor_: return U"^";
        case Operator::and_: return U"&";
        case Operator::or_: return U"|";
        case Operator::complement: return U"~";
        case Operator::not_: return U"!";
        case Operator::comma: return U",";
    }
    return std::u32string();
}

std::u32string OperatorFunctionIdNode::Str() const
{
    switch (op)
    {
        case Operator::newArray: return U"operator new[]";
        case Operator::deleteArray: return U"operator delete[]";
        case Operator::new_: return U"operator new";
        case Operator::delete_: return U"operator delete";
        case Operator::assign: return U"operator=";
        case Operator::mulAssign: return U"operator*=";
        case Operator::divAssign: return U"operator/=";
        case Operator::remAssign: return U"operator%=";
        case Operator::addAssign: return U"operator+=";
        case Operator::subAssign: return U"operator-=";
        case Operator::shiftLeftAssign: return U"operator<<=";
        case Operator::shiftRightAssign: return U"operator>>=";
        case Operator::andAssign: return U"operator&=";
        case Operator::xorAssign: return U"operator^=";
        case Operator::orAssign: return U"operator|=";
        case Operator::inc: return U"operator++";
        case Operator::dec: return U"operator--";
        case Operator::shiftLeft: return U"operator<<";
        case Operator::shiftRight: return U"operator>>";
        case Operator::logicalAnd: return U"operator&&";
        case Operator::logicalOr: return U"operator||";
        case Operator::equal: return U"operator==";
        case Operator::notEqual: return U"operator!=";
        case Operator::lessOrEqual: return U"operator<=";
        case Operator::greaterOrEqual: return U"operator>=";
        case Operator::dotStar: return U"operator.*";
        case Operator::arrowStar: return U"operator->*";
        case Operator::arrow: return U"operator->";
        case Operator::apply: return U"operator()";
        case Operator::subscript: return U"operator[]";
        case Operator::less: return U"operator<";
        case Operator::greater: return U"operator>";
        case Operator::add: return U"operator+";
        case Operator::sub: return U"operator-";
        case Operator::mul: return U"operator*";
        case Operator::div: return U"operator/";
        case Operator::rem: return U"operator%";
        case Operator::xor_: return U"operator^";
        case Operator::and_: return U"operator&";
        case Operator::or_: return U"operator|";
        case Operator::complement: return U"operator~";
        case Operator::not_: return U"operator!";
        case Operator::comma: return U"operator,";
    }
    return std::u32string();
}

std::u32string OperatorFunctionIdNode::GroupName() const
{
    switch (op)
    {
        case Operator::newArray: return U"operator_new_array";
        case Operator::deleteArray: return U"operator_delete_array";
        case Operator::new_: return U"operator_new";
        case Operator::delete_: return U"operator_delete";
        case Operator::assign: return U"operator_assign";
        case Operator::mulAssign: return U"operator_mul_assign";
        case Operator::divAssign: return U"operator_div_assign";
        case Operator::remAssign: return U"operator_rem_assign";
        case Operator::addAssign: return U"operator_add_assign";
        case Operator::subAssign: return U"operator_sub_assign";
        case Operator::shiftLeftAssign: return U"operator_shift_left_assign";
        case Operator::shiftRightAssign: return U"operator_shift_right_assign";
        case Operator::andAssign: return U"operator_and_assign";
        case Operator::xorAssign: return U"operator_xor_assign";
        case Operator::orAssign: return U"operator_or_assign";
        case Operator::inc: return U"operator_inc";
        case Operator::dec: return U"operator_dec";
        case Operator::shiftLeft: return U"operator_shift_left";
        case Operator::shiftRight: return U"operator_shift_right";
        case Operator::logicalAnd: return U"operator_logical_and";
        case Operator::logicalOr: return U"operator_logical_or";
        case Operator::equal: return U"operator_equal";
        case Operator::notEqual: return U"operator_not_equal";
        case Operator::lessOrEqual: return U"operator_less_or_equal";
        case Operator::greaterOrEqual: return U"operator_greater_or_equal";
        case Operator::dotStar: return U"operator_dot_star";
        case Operator::arrowStar: return U"operator_arrow_star";
        case Operator::arrow: return U"operator_arrow";
        case Operator::apply: return U"operator_apply";
        case Operator::subscript: return U"operator_subscript";
        case Operator::less: return U"operator_less";
        case Operator::greater: return U"operator_greater";
        case Operator::add: return U"operator_add";
        case Operator::sub: return U"operator_sub";
        case Operator::mul: return U"operator_mul";
        case Operator::div: return U"operator_div";
        case Operator::rem: return U"operator_rem";
        case Operator::xor_: return U"operator_xor";
        case Operator::and_: return U"operator_and";
        case Operator::or_: return U"operator_or";
        case Operator::complement: return U"operator_complement";
        case Operator::not_: return U"operator_not";
        case Operator::comma: return U"operator_comma";
    }
    return std::u32string();
}

ConversionFunctionIdNode::ConversionFunctionIdNode() : IdentifierNode(NodeType::conversionFunctionIdNode)
{
}

ConversionFunctionIdNode::ConversionFunctionIdNode(const Span& span_, Node* typeExpr_) : IdentifierNode(NodeType::conversionFunctionIdNode, span_, U"operator"), typeExpr(typeExpr_)
{
}

void ConversionFunctionIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ConversionFunctionIdNode::Write(Writer& writer)
{
    IdentifierNode::Write(writer);
    typeExpr->Write(writer);
}

void ConversionFunctionIdNode::Read(Reader& reader)
{
    IdentifierNode::Read(reader);
    typeExpr.reset(reader.ReadNode());
}

DtorIdNode::DtorIdNode() : IdentifierNode(NodeType::dtorIdNode)
{
}

DtorIdNode::DtorIdNode(const Span& span_, const std::u32string& identifier_) : IdentifierNode(NodeType::dtorIdNode, span_, identifier_)
{
}

void DtorIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

NestedIdNode::NestedIdNode() : BinaryNode(NodeType::nestedIdNode)
{
}

NestedIdNode::NestedIdNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::nestedIdNode, span_, left_, right_)
{
}

void NestedIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ParenthesizedExprNode::ParenthesizedExprNode() : UnaryNode(NodeType::parenthesizedExprNode)
{
}

ParenthesizedExprNode::ParenthesizedExprNode(const Span& span_, Node* expr_) : UnaryNode(NodeType::parenthesizedExprNode, span_, expr_)
{
}

void ParenthesizedExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LambdaExpressionNode::LambdaExpressionNode() : Node(NodeType::lambdaExpressionNode)
{
}

LambdaExpressionNode::LambdaExpressionNode(const Span& span_) : Node(NodeType::lambdaExpressionNode, span_)
{
}

void LambdaExpressionNode::AddCapture(Node* capture)
{
    if (captures)
    {
        captures.reset(new CaptureSequenceNode(capture->GetSpan(), captures.release(), capture));
    }
    else
    {
        captures.reset(capture);
    }
}

void LambdaExpressionNode::SetParameters(Node* parameters_)
{
    parameters.reset(parameters_);
}

void LambdaExpressionNode::SetBody(CompoundStatementNode* body_)
{
    body.reset(body_);
}

void LambdaExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void LambdaExpressionNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(captures != nullptr);
    if (captures)
    {
        captures->Write(writer);
    }
    writer.GetBinaryWriter().Write(parameters != nullptr);
    if (parameters)
    {
        parameters->Write(writer);
    }
    body->Write(writer);
}

void LambdaExpressionNode::Read(Reader& reader)
{
    Node::Read(reader);
    bool hasCaptures = reader.GetBinaryReader().ReadBool();
    if (hasCaptures)
    {
        captures.reset(reader.ReadNode());
    }
    bool hasParameters = reader.GetBinaryReader().ReadBool();
    if (hasParameters)
    {
        parameters.reset(reader.ReadNode());
    }
    body.reset(reader.ReadCompoundStatementNode());
}

CaptureSequenceNode::CaptureSequenceNode() : BinaryNode(NodeType::captureSequenceNode)
{
}

CaptureSequenceNode::CaptureSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::captureSequenceNode, span_, left_, right_)
{
}

void CaptureSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AssignCaptureNode::AssignCaptureNode() : Node(NodeType::assignCaptureNode)
{
}

AssignCaptureNode::AssignCaptureNode(const Span& span_) : Node(NodeType::assignCaptureNode, span_)
{
}

void AssignCaptureNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

RefCaptureNode::RefCaptureNode() : Node(NodeType::refCaptureNode)
{
}

RefCaptureNode::RefCaptureNode(const Span& span_) : Node(NodeType::refCaptureNode, span_)
{
}

void RefCaptureNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ThisCaptureNode::ThisCaptureNode() : Node(NodeType::thisCaptureNode)
{
}

ThisCaptureNode::ThisCaptureNode(const Span& span_) : Node(NodeType::thisCaptureNode, span_)
{
}

void ThisCaptureNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

IdentifierCaptureNode::IdentifierCaptureNode() : UnaryNode(NodeType::identifierCaptureNode)
{
}

IdentifierCaptureNode::IdentifierCaptureNode(const Span& span_, IdentifierNode* id_) : UnaryNode(NodeType::identifierCaptureNode, span_, id_)
{
}

void IdentifierCaptureNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
