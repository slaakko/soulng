// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Statement.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>

namespace sngcpp { namespace ast {

LabeledStatementNode::LabeledStatementNode() : UnaryNode(NodeType::labeledStatementNode)
{
}

LabeledStatementNode::LabeledStatementNode(const Span& span_, const std::u32string& label_, Node* statement_) : UnaryNode(NodeType::labeledStatementNode, span_, statement_), label(label_)
{
}

void LabeledStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void LabeledStatementNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.GetBinaryWriter().Write(label);
}

void LabeledStatementNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    label = reader.GetBinaryReader().ReadUtf32String();
}

CaseStatementNode::CaseStatementNode() : UnaryNode(NodeType::caseStatementNode)
{
}

CaseStatementNode::CaseStatementNode(const Span& span_, Node* caseExpr_, Node* statement_) : UnaryNode(NodeType::caseStatementNode, span_, statement_), caseExpr(caseExpr_)
{
}

void CaseStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CaseStatementNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    caseExpr->Write(writer);
}

void CaseStatementNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    caseExpr.reset(reader.ReadNode());
}

DefaultStatementNode::DefaultStatementNode() : UnaryNode(NodeType::defaultStatementNode)
{
}

DefaultStatementNode::DefaultStatementNode(const Span& span_, Node* statement_) : UnaryNode(NodeType::defaultStatementNode, span_, statement_)
{
}

void DefaultStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ExpressionStatementNode::ExpressionStatementNode() : UnaryNode(NodeType::expressionStatementNode)
{
}

ExpressionStatementNode::ExpressionStatementNode(const Span& span_, Node* expression_) : UnaryNode(NodeType::expressionStatementNode, span_, expression_)
{
}

void ExpressionStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CompoundStatementNode::CompoundStatementNode() : UnaryNode(NodeType::compoundStatementNode)
{
}

CompoundStatementNode::CompoundStatementNode(const Span& span_) : UnaryNode(NodeType::compoundStatementNode, span_)
{
}

void CompoundStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CompoundStatementNode::Write(Writer& writer)
{
    UnaryNode::Write(writer);
    writer.Write(endBraceSpan);
}

void CompoundStatementNode::Read(Reader& reader)
{
    UnaryNode::Read(reader);
    reader.Read(endBraceSpan);
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

StatementSequenceNode::StatementSequenceNode() : BinaryNode(NodeType::statementSequenceNode)
{
}

StatementSequenceNode::StatementSequenceNode(const Span& span_, Node* leftStatement_, Node* rightStatement_) : BinaryNode(NodeType::statementSequenceNode, span_, leftStatement_, rightStatement_)
{
}

void StatementSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

IfStatementNode::IfStatementNode() : Node(NodeType::ifStatementNode)
{
}

IfStatementNode::IfStatementNode(const Span& span_, Node* condition_, Node* thenS_, Node* elseS_, const Span& elseSpan_) : 
    Node(NodeType::ifStatementNode, span_), condition(condition_), thenS(thenS_), elseS(elseS_), elseSpan(elseSpan_)
{
}

void IfStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void IfStatementNode::Write(Writer& writer)
{
    Node::Write(writer);
    condition->Write(writer);
    thenS->Write(writer);
    writer.GetBinaryWriter().Write(elseS != nullptr);
    if (elseS)
    {
        elseS->Write(writer);
        writer.Write(elseSpan);
    }
}

void IfStatementNode::Read(Reader& reader)
{
    Node::Read(reader);
    condition.reset(reader.ReadNode());
    thenS.reset(reader.ReadNode());
    bool hasElseS = reader.GetBinaryReader().ReadBool();
    if (hasElseS)
    {
        elseS.reset(reader.ReadNode());
        reader.Read(elseSpan);
    }
}

SwitchStatementNode::SwitchStatementNode() : Node(NodeType::switchStatementNode)
{
}

SwitchStatementNode::SwitchStatementNode(const Span& span_, Node* condition_, Node* statement_) : Node(NodeType::switchStatementNode, span_), condition(condition_), statement(statement_)
{
}

void SwitchStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SwitchStatementNode::Write(Writer& writer)
{
    Node::Write(writer);
    condition->Write(writer);
    statement->Write(writer);
}

void SwitchStatementNode::Read(Reader& reader)
{
    Node::Read(reader);
    condition.reset(reader.ReadNode());
    statement.reset(reader.ReadNode());
}

WhileStatementNode::WhileStatementNode() : Node(NodeType::whileStatementNode)
{
}

WhileStatementNode::WhileStatementNode(const Span& span_, Node* condition_, Node* statement_) : Node(NodeType::whileStatementNode, span_), condition(condition_), statement(statement_)
{
}

void WhileStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void WhileStatementNode::Write(Writer& writer)
{
    Node::Write(writer);
    condition->Write(writer);
    statement->Write(writer);
}

void WhileStatementNode::Read(Reader& reader)
{
    Node::Read(reader);
    condition.reset(reader.ReadNode());
    statement.reset(reader.ReadNode());
}

DoStatementNode::DoStatementNode() : Node(NodeType::doStatementNode)
{
}

DoStatementNode::DoStatementNode(const Span& span_, Node* statement_, Node* condition_, const Span& whileSpan_) : 
    Node(NodeType::doStatementNode, span_), statement(statement_), condition(condition_), whileSpan(whileSpan_)
{
}

void DoStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void DoStatementNode::Write(Writer& writer)
{
    Node::Write(writer);
    statement->Write(writer);
    condition->Write(writer);
    writer.Write(whileSpan);
}

void DoStatementNode::Read(Reader& reader)
{
    Node::Read(reader);
    statement.reset(reader.ReadNode());
    condition.reset(reader.ReadNode());
    reader.Read(whileSpan);
}

RangeForStatementNode::RangeForStatementNode() : Node(NodeType::rangeForStatementNode)
{
}

RangeForStatementNode::RangeForStatementNode(const Span& span_, Node* forRangeDeclaration_, Node* forRangeInitializer_, Node* statement_) :
    Node(NodeType::rangeForStatementNode, span_), forRangeDeclaration(forRangeDeclaration_), forRangeInitializer(forRangeInitializer_), statement(statement_)
{
}

void RangeForStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void RangeForStatementNode::Write(Writer& writer)
{
    Node::Write(writer);
    forRangeDeclaration->Write(writer);
    forRangeInitializer->Write(writer);
    statement->Write(writer);
}

void RangeForStatementNode::Read(Reader& reader)
{
    Node::Read(reader);
    forRangeDeclaration.reset(reader.ReadNode());
    forRangeInitializer.reset(reader.ReadNode());
    statement.reset(reader.ReadNode());
}

ForStatementNode::ForStatementNode() : Node(NodeType::forStatementNode)
{
}

ForStatementNode::ForStatementNode(const Span& span_, Node* initS_, Node* condition_, Node* loopExpr_, Node* actionS_) :
    Node(NodeType::forStatementNode, span_), initS(initS_), condition(condition_), loopExpr(loopExpr_), actionS(actionS_)
{
}

void ForStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ForStatementNode::Write(Writer& writer)
{
    Node::Write(writer);
    initS->Write(writer);
    writer.GetBinaryWriter().Write(condition != nullptr);
    if (condition)
    {
        condition->Write(writer);
    }
    writer.GetBinaryWriter().Write(loopExpr != nullptr);
    if (loopExpr)
    {
        loopExpr->Write(writer);
    }
    actionS->Write(writer);
}

void ForStatementNode::Read(Reader& reader)
{
    Node::Read(reader);
    initS.reset(reader.ReadNode());
    bool hasCondition = reader.GetBinaryReader().ReadBool();
    if (hasCondition)
    {
        condition.reset(reader.ReadNode());
    }
    bool hasLoopExpr = reader.GetBinaryReader().ReadBool();
    if (hasLoopExpr)
    {
        loopExpr.reset(reader.ReadNode());
    }
    actionS.reset(reader.ReadNode());
}

BreakStatementNode::BreakStatementNode() : Node(NodeType::breakStatementNode)
{
}

BreakStatementNode::BreakStatementNode(const Span& span_) : Node(NodeType::breakStatementNode, span_)
{
}

void BreakStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ContinueStatementNode::ContinueStatementNode() : Node(NodeType::continueStatementNode)
{
}

ContinueStatementNode::ContinueStatementNode(const Span& span_) : Node(NodeType::continueStatementNode, span_)
{
}

void ContinueStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

ReturnStatementNode::ReturnStatementNode() : Node(NodeType::returnStatementNode)
{
}

ReturnStatementNode::ReturnStatementNode(const Span& span_, Node* returnExpr_) : Node(NodeType::returnStatementNode, span_), returnExpr(returnExpr_)
{
}

void ReturnStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void ReturnStatementNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(returnExpr != nullptr);
    if (returnExpr)
    {
        returnExpr->Write(writer);
    }
}

void ReturnStatementNode::Read(Reader& reader)
{
    Node::Read(reader);
    bool hasReturnExpr = reader.GetBinaryReader().ReadBool();
    if (hasReturnExpr)
    {
        returnExpr.reset(reader.ReadNode());
    }
}

GotoStatementNode::GotoStatementNode() : Node(NodeType::gotoStatementNode)
{
}

GotoStatementNode::GotoStatementNode(const Span& span_, const std::u32string& target_) : Node(NodeType::gotoStatementNode, span_), target(target_)
{
}

void GotoStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void GotoStatementNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(target);
}

void GotoStatementNode::GotoStatementNode::Read(Reader& reader)
{
    Node::Read(reader);
    target = reader.GetBinaryReader().ReadUtf32String();
}

DeclarationStatementNode::DeclarationStatementNode() : UnaryNode(NodeType::declarationStatementNode)
{
}

DeclarationStatementNode::DeclarationStatementNode(const Span& span_, Node* declaration_) : UnaryNode(NodeType::declarationStatementNode, span_, declaration_)
{
}

void DeclarationStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

TryStatementNode::TryStatementNode() : Node(NodeType::tryStatementNode)
{
}

TryStatementNode::TryStatementNode(const Span& span_, CompoundStatementNode* tryBlock_) : Node(NodeType::tryStatementNode, span_), tryBlock(tryBlock_)
{
}

void TryStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void TryStatementNode::Write(Writer& writer)
{
    Node::Write(writer);
    tryBlock->Write(writer);
    writer.GetBinaryWriter().Write(handlers != nullptr);
    if (handlers)
    {
        handlers->Write(writer);
    }
}

void TryStatementNode::Read(Reader& reader)
{
    Node::Read(reader);
    tryBlock.reset(reader.ReadCompoundStatementNode());
    bool hasHandlers = reader.GetBinaryReader().ReadBool();
    if (hasHandlers)
    {
        handlers.reset(reader.ReadNode());
    }
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

HandlerNode::HandlerNode() : Node(NodeType::handlerNode)
{
}

HandlerNode::HandlerNode(const Span& span_, Node* exceptionDeclaration_, CompoundStatementNode* catchBlock_) :
    Node(NodeType::handlerNode, span_), exceptionDeclaration(exceptionDeclaration_), catchBlock(catchBlock_)
{
}

void HandlerNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void HandlerNode::Write(Writer& writer)
{
    Node::Write(writer);
    exceptionDeclaration->Write(writer);
    catchBlock->Write(writer);
}

void HandlerNode::Read(Reader& reader)
{
    Node::Read(reader);
    exceptionDeclaration.reset(reader.ReadNode());
    catchBlock.reset(reader.ReadCompoundStatementNode());
}

HandlerSequenceNode::HandlerSequenceNode() : BinaryNode(NodeType::handlerSequenceNode)
{
}

HandlerSequenceNode::HandlerSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::handlerSequenceNode, span_, left_, right_)
{
}

void HandlerSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CatchAllNode::CatchAllNode() : Node(NodeType::catchAllNode)
{
}

CatchAllNode::CatchAllNode(const Span& span_) : Node(NodeType::catchAllNode, span_)
{
}

void CatchAllNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
