// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Visitor.hpp>

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

ExpressionSequenceNode::ExpressionSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void ExpressionSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CommaExpressionNode::CommaExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void CommaExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AssignmentExpressionNode::AssignmentExpressionNode(const Span& span_, Node* left_, Operator op_, Node* right_) : BinaryNode(span_, left_, right_), op(op_)
{
}

void AssignmentExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ConditionalExpressionNode::ConditionalExpressionNode(const Span& span_, Node* condition_, Node* thenExpr_, Node* elseExpr_) :
    Node(span_), condition(condition_), thenExpr(thenExpr_), elseExpr(elseExpr_)
{
}

void ConditionalExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ThrowExpressionNode::ThrowExpressionNode(const Span& span_, Node* exceptionExpr_) : UnaryNode(span_, exceptionExpr_)
{
}

void ThrowExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LogicalOrExpressionNode::LogicalOrExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void LogicalOrExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LogicalAndExpressionNode::LogicalAndExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void LogicalAndExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

InclusiveOrExpressionNode::InclusiveOrExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void InclusiveOrExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExclusiveOrExpressionNode::ExclusiveOrExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void ExclusiveOrExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AndExpressionNode::AndExpressionNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void AndExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

EqualityExpressionNode::EqualityExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(span_, left_, right_), op(op_)
{
}

void EqualityExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

RelationalExpressionNode::RelationalExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(span_, left_, right_), op(op_)
{
}

void RelationalExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ShiftExpressionNode::ShiftExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(span_, left_, right_), op(op_)
{
}

void ShiftExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AdditiveExpressionNode::AdditiveExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(span_, left_, right_), op(op_)
{
}

void AdditiveExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

MultiplicativeExpressionNode::MultiplicativeExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(span_, left_, right_), op(op_)
{
}

void MultiplicativeExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PMExpressionNode::PMExpressionNode(const Span& span_, Node* left_, Node* right_, Operator op_) : BinaryNode(span_, left_, right_), op(op_)
{
}

void PMExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CastExpressionNode::CastExpressionNode(const Span& span_, Node* typeExpr_, Node* expr_) : Node(span_), typeExpr(typeExpr_), expr(expr_)
{
}

void CastExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

UnaryExpressionNode::UnaryExpressionNode(const Span& span_, Operator op_, Node* expr_) : UnaryNode(span_, expr_), op(op_)
{
}

void UnaryExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

NewExpressionNode::NewExpressionNode(const Span& span_, Node* placement_, Node* typeExpr_, Node* initializer_) :
    Node(span_), placement(placement_), typeExpr(typeExpr_), initializer(initializer_)
{
}

void NewExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DeleteExpressionNode::DeleteExpressionNode(const Span& span_, bool array__, Node* ptr_) : UnaryNode(span_, ptr_), array_(array__)
{
}

void DeleteExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

SubscriptExpressionNode::SubscriptExpressionNode(const Span& span_, Node* subject_, Node* index_) : UnaryNode(span_, subject_), index(index_)
{
}

void SubscriptExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

InvokeExpressionNode::InvokeExpressionNode(const Span& span_, Node* subject_, Node* arguments_) : UnaryNode(span_, subject_), arguments(arguments_)
{
}

void InvokeExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DotNode::DotNode(const Span& span_, Node* subject_, Node* id_) : UnaryNode(span_, subject_), id(id_)
{
}

void DotNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ArrowNode::ArrowNode(const Span& span_, Node* subject_, Node* id_) : UnaryNode(span_, subject_), id(id_)
{
}

void ArrowNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PostfixIncNode::PostfixIncNode(const Span& span_, Node* subject_) : UnaryNode(span_, subject_)
{
}

void PostfixIncNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

PostfixDecNode::PostfixDecNode(const Span& span_, Node* subject_) : UnaryNode(span_, subject_)
{
}

void PostfixDecNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CppCastExpressionNode::CppCastExpressionNode(const Span& span_, Node* typeExpr_, Node* expr_, Operator op_) : Node(span_), typeExpr(typeExpr_), expr(expr_), op(op_)
{
}

void CppCastExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TypeIdExpressionNode::TypeIdExpressionNode(const Span& span_, Node* subject_) : UnaryNode(span_, subject_)
{
}

void TypeIdExpressionNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ThisNode::ThisNode(const Span& span_) : Node(span_)
{
}

void ThisNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

IdentifierNode::IdentifierNode(const Span& span_, const std::u32string& identifier_) : Node(span_), identifier(identifier_)
{
}

void IdentifierNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

OperatorFunctionIdNode::OperatorFunctionIdNode(const Span& span_, Operator op_) : IdentifierNode(span_, U"operator"), op(op_)
{
}

void OperatorFunctionIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
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

ConversionFunctionIdNode::ConversionFunctionIdNode(const Span& span_, Node* typeExpr_) : IdentifierNode(span_, U"operator"), typeExpr(typeExpr_)
{
}

void ConversionFunctionIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DtorIdNode::DtorIdNode(const Span& span_, const std::u32string& identifier_) : IdentifierNode(span_, identifier_)
{
}

void DtorIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

NestedIdNode::NestedIdNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void NestedIdNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ParenthesizedExprNode::ParenthesizedExprNode(const Span& span_, Node* expr_) : UnaryNode(span_, expr_)
{
}

void ParenthesizedExprNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

LambdaExpressionNode::LambdaExpressionNode(const Span& span_) : Node(span_)
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

CaptureSequenceNode::CaptureSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void CaptureSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

AssignCapture::AssignCapture(const Span& span_) : Node(span_)
{
}

void AssignCapture::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

RefCapture::RefCapture(const Span& span_) : Node(span_)
{
}

void RefCapture::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ThisCapture::ThisCapture(const Span& span_) : Node(span_)
{
}

void ThisCapture::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

IdentifierCapture::IdentifierCapture(const Span& span_, IdentifierNode* id_) : UnaryNode(span_, id_)
{
}

void IdentifierCapture::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
