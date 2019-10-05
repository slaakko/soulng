// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Statement.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace ast {

LabeledStatementNode::LabeledStatementNode(const Span& span_, const std::u32string& label_, Node* statement_) : UnaryNode(span_, statement_), label(label_)
{
}

void LabeledStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CaseStatementNode::CaseStatementNode(const Span& span_, Node* caseExpr_, Node* statement_) : UnaryNode(span_, statement_), caseExpr(caseExpr_)
{
}

void CaseStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DefaultStatementNode::DefaultStatementNode(const Span& span_, Node* statement_) : UnaryNode(span_, statement_)
{
}

void DefaultStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExpressionStatementNode::ExpressionStatementNode(const Span& span_, Node* expression_) : UnaryNode(span_, expression_)
{
}

void ExpressionStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CompoundStatementNode::CompoundStatementNode(const Span& span_) : UnaryNode(span_)
{
}

void CompoundStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CompoundStatementNode::AddStatement(const Span& span_, Node* statement)
{
    if (Child())
    {
        SetChild(new StatementSequenceNode(span_, ReleaseChild(), statement));
    }
    else
    {
        SetChild(statement);
    }
}

StatementSequenceNode::StatementSequenceNode(const Span& span_, Node* leftStatement_, Node* rightStatement_) : BinaryNode(span_, leftStatement_, rightStatement_)
{
}

void StatementSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

IfStatementNode::IfStatementNode(const Span& span_, Node* condition_, Node* thenS_, Node* elseS_, const Span& elseSpan_) : 
    Node(span_), condition(condition_), thenS(thenS_), elseS(elseS_), elseSpan(elseSpan_)
{
}

void IfStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

SwitchStatementNode::SwitchStatementNode(const Span& span_, Node* condition_, Node* statement_) : Node(span_), condition(condition_), statement(statement_)
{
}

void SwitchStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

WhileStatementNode::WhileStatementNode(const Span& span_, Node* condition_, Node* statement_) : Node(span_), condition(condition_), statement(statement_)
{
}

void WhileStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DoStatementNode::DoStatementNode(const Span& span_, Node* statement_, Node* condition_, const Span& whileSpan_) : 
    Node(span_), statement(statement_), condition(condition_), whileSpan(whileSpan_)
{
}

void DoStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

RangeForStatementNode::RangeForStatementNode(const Span& span_, Node* forRangeDeclaration_, Node* forRangeInitializer_, Node* statement_) :
    Node(span_), forRangeDeclaration(forRangeDeclaration_), forRangeInitializer(forRangeInitializer_), statement(statement_)
{
}

void RangeForStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ForStatementNode::ForStatementNode(const Span& span_, Node* initS_, Node* condition_, Node* loopExpr_, Node* actionS_) :
    Node(span_), initS(initS_), condition(condition_), loopExpr(loopExpr_), actionS(actionS_)
{
}

void ForStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

BreakStatementNode::BreakStatementNode(const Span& span_) : Node(span_)
{
}

void BreakStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ContinueStatementNode::ContinueStatementNode(const Span& span_) : Node(span_)
{
}

void ContinueStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ReturnStatementNode::ReturnStatementNode(const Span& span_, Node* returnExpr_) : Node(span_), returnExpr(returnExpr_)
{
}

void ReturnStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

GotoStatementNode::GotoStatementNode(const Span& span_, const std::u32string& target_) : Node(span_), target(target_)
{
}

void GotoStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

DeclarationStatementNode::DeclarationStatementNode(const Span& span_, Node* declaration_) : UnaryNode(span_, declaration_)
{
}

void DeclarationStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TryStatementNode::TryStatementNode(const Span& span_, CompoundStatementNode* tryBlock_) : Node(span_), tryBlock(tryBlock_)
{
}

void TryStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TryStatementNode::AddHandler(const Span& span, Node* handler)
{
    if (handlers)
    {
        handlers.reset(new HandlerSequenceNode(span, handlers.release(), handler));
    }
    else
    {
        handlers.reset(handler);
    }
}

HandlerNode::HandlerNode(const Span& span_, Node* exceptionDeclaration_, CompoundStatementNode* catchBlock_) :
    Node(span_), exceptionDeclaration(exceptionDeclaration_), catchBlock(catchBlock_)
{
}

void HandlerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

HandlerSequenceNode::HandlerSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void HandlerSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CatchAllNode::CatchAllNode(const Span& span_) : Node(span_)
{
}

void CatchAllNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
