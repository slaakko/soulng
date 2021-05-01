// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Statement.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Writer.hpp>
#include <sngcpp20/ast/Reader.hpp>

namespace sngcpp::ast {

LabeledStatementNode::LabeledStatementNode(const SourcePos& sourcePos_, Node* label_, Node* stmt_, Node* attributes_, const SourcePos& colonPos_) :
    CompoundNode(NodeKind::labeledStatementNode, sourcePos_), label(label_), stmt(stmt_), attributes(attributes_), colonPos(colonPos_)
{
}

void LabeledStatementNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void LabeledStatementNode::Write(Writer& writer)
{
    writer.Write(label.get());
    writer.Write(stmt.get());
    writer.Write(attributes.get());
    writer.Write(colonPos);
}

void LabeledStatementNode::Read(Reader& reader)
{
    label.reset(reader.ReadNode());
    stmt.reset(reader.ReadNode());
    attributes.reset(reader.ReadNode());
    colonPos = reader.ReadSourcePos();
}

CaseStatementNode::CaseStatementNode(const SourcePos& sourcePos_, Node* caseExpr_, Node* stmt_, Node* attributes_, const SourcePos& casePos_, const SourcePos& colonPos_) :
    CompoundNode(NodeKind::caseStatmentNode, sourcePos_), caseExpr(caseExpr_), stmt(stmt_), attributes(attributes_), casePos(casePos_), colonPos(colonPos_)
{
}

DefaultStatementNode::DefaultStatementNode(const SourcePos& sourcePos_, Node* stmt_, Node* attributes_, const SourcePos& defaultPos_, const SourcePos& colonPos_) : 
    CompoundNode(NodeKind::defaultStatementNode, sourcePos_), stmt(stmt_), attributes(attributes_), defaultPos(defaultPos_), colonPos(colonPos_)
{
}

CompoundStatementNode::CompoundStatementNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::compoundStatementNode, sourcePos_)
{
}

IfStatementNode::IfStatementNode(const SourcePos& sourcePos_, Node* initStmt_, Node* cond_, Node* thenStmt_, Node* elseStmt_, Node* attributes_, 
    const SourcePos& ifPos_, const SourcePos& lpPos_, const SourcePos& rpPos_, const SourcePos& constExprPos_) :
    CompoundNode(NodeKind::ifStatementNode, sourcePos_), initStmt(initStmt_), cond(cond_), thenStmt(thenStmt_), elseStmt(elseStmt_), attributes(attributes_),
    ifPos(ifPos_), lpPos(lpPos_), rpPos(rpPos_), constExprPos(constExprPos_)
{
}

SwitchStatementNode::SwitchStatementNode(const SourcePos& sourcePos_, Node* initStmt_, Node* cond_, Node* stmt_, Node* attributes_, const SourcePos& switchPos_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::switchStatemeNode, sourcePos_), initStmt(initStmt_), cond(cond_), stmt(stmt_), attributes(attributes_), switchPos(switchPos_), lpPos(lpPos_), rpPos(rpPos_)
{
}

WhileStatementNode::WhileStatementNode(const SourcePos& sourcePos_, Node* cond_, Node* stmt_, Node* attributes_, const SourcePos& whilePos_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::whileStatementNode, sourcePos_), cond(cond_), stmt(stmt_), attributes(attributes_), whilePos(whilePos_), lpPos(lpPos_), rpPos(rpPos_)
{
}

DoStatementNode::DoStatementNode(const SourcePos& sourcePos_, Node* stmt_, Node* expr_, Node* attributes_, Node* semicolon_, 
    const SourcePos& doPos_, const SourcePos& whilePos_, const SourcePos& lpPos_, const SourcePos& rpPos_) : 
    CompoundNode(NodeKind::doStatementNode, sourcePos_), stmt(stmt_), expr(expr_), attributes(attributes_), semicolon(semicolon_), doPos(doPos_), whilePos(whilePos_), lpPos(lpPos_), rpPos(rpPos_)
{
}

RangeForStatementNode::RangeForStatementNode(const SourcePos& sourcePos_, Node* initStmt_, Node* declaration_, Node* initializer_, Node* stmt_, Node* attributes_,
    const SourcePos& forPos_, const SourcePos& lpPos_, const SourcePos& rpPos_, const SourcePos& colonPos_) :
    CompoundNode(NodeKind::rangeForStatementNode, sourcePos_), initStmt(initStmt_), declaration(declaration_), initializer(initializer_), stmt(stmt_), attributes(attributes_),
    forPos(forPos_), lpPos(lpPos_), rpPos(rpPos_), colonPos(colonPos_)
{
}

ForRangeDeclarationNode::ForRangeDeclarationNode(const SourcePos& sourcePos_, Node* declSpecifierSeq_, Node* declarator_) : 
    BinaryNode(NodeKind::forRangeDeclarationNode, sourcePos_, declSpecifierSeq_, declarator_)
{
}

StructuredBindingNode::StructuredBindingNode(const SourcePos& sourcePos_, Node* declSpecifierSeq_, Node* refQualifier_, Node* identifiers_, Node* initializer_, Node* attributes_, Node* semicolon_, 
    const SourcePos& lbPos_, const SourcePos& rbPos_) : 
    CompoundNode(NodeKind::structuredBindingNode, sourcePos_), declSpecifiers(declSpecifierSeq_), refQualifier(refQualifier_), identifiers(identifiers_), initializer(initializer_),
    attributes(attributes_), semicolon(semicolon_), lbPos(lbPos_), rbPos(rbPos_)
{
}

ForStatementNode::ForStatementNode(const SourcePos& sourcePos_, Node* initStmt_, Node* cond_, Node* loopExpr_, Node* stmt_, Node* attributes_, Node* semicolon_,
    const SourcePos& forPos_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::forStatementNode, sourcePos_), initStmt(initStmt_), cond(cond_), loopExpr(loopExpr_), stmt(stmt_), attributes(attributes_), semicolon(semicolon_),
    forPos(forPos_), lpPos(lpPos_), rpPos(rpPos_)
{
}

BreakStatementNode::BreakStatementNode(const SourcePos& sourcePos_, Node* attributes_, Node* semicolon_, const SourcePos& breakPos_) :
    CompoundNode(NodeKind::breakStatementNode, sourcePos_), attributes(attributes_), semicolon(semicolon_), breakPos(breakPos_)
{
}

ContinueStatementNode::ContinueStatementNode(const SourcePos& sourcePos_, Node* attributes_, Node* semicolon_, const SourcePos& continuePos_) :
    CompoundNode(NodeKind::continueStatementNode, sourcePos_), attributes(attributes_), semicolon(semicolon_), continuePos(continuePos_)
{
}

ReturnStatementNode::ReturnStatementNode(const SourcePos& sourcePos_, Node* returnValue_, Node* attributes_, Node* semicolon_, const SourcePos& returnPos_) : 
    CompoundNode(NodeKind::returnStatementNode, sourcePos_), returnValue(returnValue_), attributes(attributes_), semicolon(semicolon_), returnPos(returnPos_)
{
}

CoReturnStatementNode::CoReturnStatementNode(const SourcePos& sourcePos_, Node* returnValue_, Node* attributes_, Node* semicolon_, const SourcePos& coReturnPos_) :
    CompoundNode(NodeKind::coReturnStatementNode, sourcePos_), returnValue(returnValue_), attributes(attributes_), semicolon(semicolon_), coReturnPos(coReturnPos_)
{
}

GotoStatementNode::GotoStatementNode(const SourcePos& sourcePos_, Node* target_, Node* attributes_, Node* semicolon_, const SourcePos& gotoPos_) :
    CompoundNode(NodeKind::gotoStatementNode, sourcePos_), target(target_), attributes(attributes_), semicolon(semicolon_), gotoPos(gotoPos_)
{
}

TryStatementNode::TryStatementNode(const SourcePos& sourcePos_, Node* tryBlock_, Node* handlers_, Node* attributes_, const SourcePos& tryPos_) :
    CompoundNode(NodeKind::tryStatementNode, sourcePos_), tryBlock(tryBlock_), handlers(handlers_), attributes(attributes_), tryPos(tryPos_)
{
}

HandlerSequenceNode::HandlerSequenceNode(const SourcePos& sourcePos_) : SequenceNode(NodeKind::handlerSequenceNode, sourcePos_)
{
}

HandlerNode::HandlerNode(const SourcePos& sourcePos_, Node* exception_, Node* catchBlock_, const SourcePos& lpPos_, const SourcePos& rpPos_) :
    CompoundNode(NodeKind::handlerNode, sourcePos_), exception(exception_), catchBlock(catchBlock_), lpPos(lpPos_), rpPos(rpPos_)
{
}

ExceptionDeclarationNode::ExceptionDeclarationNode(const SourcePos& sourcePos_, Node* typeSpecifiers_, Node* declarator_, Node* attributes_) : 
    CompoundNode(NodeKind::exceptionDeclarationNode, sourcePos_), typeSpecifiers(typeSpecifiers_), declarator(declarator_), attributes(attributes_)
{
}

ExpressionStatementNode::ExpressionStatementNode(const SourcePos& sourcePos_, Node* expr_, Node* attributes_, Node* semicolon_) : 
    CompoundNode(NodeKind::expressionStatementNode, sourcePos_), expr(expr_), attributes(attributes_), semicolon(semicolon_)
{
}

DeclarationStatementNode::DeclarationStatementNode(const SourcePos& sourcePos_, Node* declaration_) :
    CompoundNode(NodeKind::declarationStatementNode, sourcePos_), declaration(declaration_)
{
}

InitConditionNode::InitConditionNode(const SourcePos& sourcePos_, Node* declSpecifiers_, Node* declarator_, Node* initializer_, Node* attributes_) : 
    CompoundNode(NodeKind::initConditionNode, sourcePos_), declSpecifiers(declSpecifiers_), declarator(declarator_), initializer(initializer_), attributes(attributes_)
{
}

SemicolonNode::SemicolonNode(const SourcePos& sourcePos_) : Node(NodeKind::semicolonNode, sourcePos_)
{
}

} // sngcpp::ast
