// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_STATEMENT_INCLUDED
#define SNGCPP_AST_STATEMENT_INCLUDED
#include <sngcpp20/ast/Node.hpp>
#include <soulng/lexer/Lexer.hpp>

namespace sngcpp::ast {

class AST_API LabeledStatementNode : public CompoundNode
{
public:
    LabeledStatementNode(const SourcePos& sourcePos_);
    LabeledStatementNode(const SourcePos& sourcePos_, Node* label_, Node* stmt_, Node* attributes_, const SourcePos& colonPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Label() const { return label.get(); }
    Node* Statement() const { return stmt.get(); }
    Node* Attributes() const { return attributes.get(); }
    const SourcePos& ColonPos() const { return colonPos; }
private:
    std::unique_ptr<Node> label;
    std::unique_ptr<Node> stmt;
    std::unique_ptr<Node> attributes;
    SourcePos colonPos;
};

class AST_API CaseStatementNode : public CompoundNode
{
public:
    CaseStatementNode(const SourcePos& sourcePos_);
    CaseStatementNode(const SourcePos& sourcePos_, Node* caseExpr_, Node* stmt_, Node* attributes_, const SourcePos& casePos_, const SourcePos& colonPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* CaseExpression() const { return caseExpr.get(); }
    Node* Statement() const { return stmt.get(); }
    Node* Attributes() const { return attributes.get(); }
    const SourcePos& CasePos() const { return casePos; }
    const SourcePos& ColonPos() const { return colonPos; }
private:
    std::unique_ptr<Node> caseExpr;
    std::unique_ptr<Node> stmt;
    std::unique_ptr<Node> attributes;
    SourcePos casePos;
    SourcePos colonPos;
};

class AST_API DefaultStatementNode : public CompoundNode
{
public:
    DefaultStatementNode(const SourcePos& sourcePos_);
    DefaultStatementNode(const SourcePos& sourcePos_, Node* stmt_, Node* attributes_, const SourcePos& defaultPos_, const SourcePos& colonPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Statement() const { return stmt.get(); }
    Node* Attributes() const { return attributes.get(); }
    const SourcePos& DefaultPos() const { return defaultPos; }
    const SourcePos& ColonPos() const { return colonPos; }
private:
    std::unique_ptr<Node> stmt;
    std::unique_ptr<Node> attributes;
    SourcePos defaultPos;
    SourcePos colonPos;
};

class AST_API CompoundStatementNode : public SequenceNode
{
public:
    CompoundStatementNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Attributes() const { return attributes.get(); }
    void SetAttributes(Node* attributes_) { attributes.reset(attributes_); }
    void SetTokenPosPair(const soulng::lexer::LexerPosPair& tokenPosPair_);
    const soulng::lexer::LexerPosPair& GetTokenPosPair() const { return tokenPosPair; }
    void SetLBracePos(const SourcePos& lbPos_) { lbPos = lbPos_; }
    void SetRBracePos(const SourcePos& rbPos_) { rbPos = rbPos_; }
    const SourcePos& LBracePos() const { return lbPos; }
    const SourcePos& RBracePos() const { return rbPos; }
private:
    std::unique_ptr<Node> attributes;
    SourcePos lbPos;
    SourcePos rbPos;
    soulng::lexer::LexerPosPair tokenPosPair;
};

class AST_API IfStatementNode : public CompoundNode
{
public:
    IfStatementNode(const SourcePos& sourcePos_);
    IfStatementNode(const SourcePos& sourcePos_, Node* initStmt_, Node* cond_, Node* thenStmt_, Node* elseStmt_, Node* attributes_, 
        const SourcePos& ifPos_,  const SourcePos& lpPos_, const SourcePos& rpPos_, const SourcePos& constExprPos_, const SourcePos& elsePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* InitStatement() const { return initStmt.get(); }
    Node* Condition() const { return cond.get(); }
    Node* ThenStatement() const { return thenStmt.get(); }
    Node* ElseStatement() const { return elseStmt.get(); }
    Node* Attributes() const { return attributes.get(); }
    const SourcePos& IfPos() const { return ifPos; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
    const SourcePos& ConstExprSourcePos() const { return constExprPos; }
    const SourcePos& ElsePos() const { return elsePos; }
    bool IsConstExprIf() const { return constExprPos.IsValid(); }
private:
    std::unique_ptr<Node> initStmt;
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> thenStmt;
    std::unique_ptr<Node> elseStmt;
    std::unique_ptr<Node> attributes;
    SourcePos ifPos;
    SourcePos lpPos;
    SourcePos rpPos;
    SourcePos constExprPos;
    SourcePos elsePos;
};

class AST_API SwitchStatementNode : public CompoundNode
{
public:
    SwitchStatementNode(const SourcePos& sourcePos_);
    SwitchStatementNode(const SourcePos& sourcePos_, Node* initStmt_, Node* cond_, Node* stmt_, Node* attributes_, const SourcePos& switchPos_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* InitStatement() const { return initStmt.get(); }
    Node* Condition() const { return cond.get(); }
    Node* Statement() const { return stmt.get(); }
    Node* Attributes() const { return attributes.get(); }
    const SourcePos& SwitchPos() const { return switchPos; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> initStmt;
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> stmt;
    std::unique_ptr<Node> attributes;
    SourcePos switchPos;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API WhileStatementNode : public CompoundNode
{
public:
    WhileStatementNode(const SourcePos& sourcePos_);
    WhileStatementNode(const SourcePos& sourcePos_, Node* cond_, Node* stmt_, Node* attributes_, const SourcePos& whilePos_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Condition() const { return cond.get(); }
    Node* Statement() const { return stmt.get(); }
    Node* Attributes() const { return attributes.get(); }
    const SourcePos& WhilePos() const { return whilePos; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> stmt;
    std::unique_ptr<Node> attributes;
    SourcePos whilePos;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API DoStatementNode : public CompoundNode
{
public:
    DoStatementNode(const SourcePos& sourcePos_);
    DoStatementNode(const SourcePos& sourcePos_, Node* stmt_, Node* expr_, Node* attributes_, Node* semicolon_, 
        const SourcePos& doPos_, const SourcePos& whilePos_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Statement() const { return stmt.get(); }
    Node* Expression() const { return expr.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    const SourcePos& DoPos() const { return doPos; }
    const SourcePos& WhilePos() const { return whilePos; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> stmt;
    std::unique_ptr<Node> expr;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
    SourcePos doPos;
    SourcePos whilePos;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API RangeForStatementNode : public CompoundNode
{
public:
    RangeForStatementNode(const SourcePos& sourcePos_);
    RangeForStatementNode(const SourcePos& sourcePos_, Node* initStmt_, Node* declaration_, Node* initializer_, Node* stmt_, Node* attributes_,
        const SourcePos& forPos_, const SourcePos& lpPos_, const SourcePos& rpPos_, const SourcePos& colonPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* InitStatement() const { return initStmt.get(); }
    Node* Declaration() const { return declaration.get(); }
    Node* Initializer() const { return initializer.get(); }
    Node* Statement() const { return stmt.get(); }
    Node* Attributes() const { return attributes.get(); }
    const SourcePos& ForPos() const { return forPos; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
    const SourcePos& ColonPos() const { return colonPos; }
private:
    std::unique_ptr<Node> initStmt;
    std::unique_ptr<Node> declaration;
    std::unique_ptr<Node> initializer;
    std::unique_ptr<Node> stmt;
    std::unique_ptr<Node> attributes;
    SourcePos forPos;
    SourcePos lpPos;
    SourcePos rpPos;
    SourcePos colonPos;
};

class AST_API ForRangeDeclarationNode : public BinaryNode
{
public:
    ForRangeDeclarationNode(const SourcePos& sourcePos_);
    ForRangeDeclarationNode(const SourcePos& sourcePos_, Node* declSpecifierSeq_, Node* declarator_, Node* attributes_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Attributes() const { return attributes.get(); }
private:
    std::unique_ptr<Node> attributes;
};

class AST_API StructuredBindingNode : public CompoundNode
{
public:
    StructuredBindingNode(const SourcePos& sourcePos_);
    StructuredBindingNode(const SourcePos& sourcePos_, Node* declSpecifierSeq_, Node* refQualifier_, Node* identifiers_, Node* initializer_, Node* attributes_, Node* semicolon_, 
        const SourcePos& lbPos_, const SourcePos& rbPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* DeclSpecifiers() const { return declSpecifiers.get(); }
    Node* RefQualifier() const { return refQualifier.get(); }
    Node* Identifiers() const { return identifiers.get(); }
    Node* Initializer() const { return initializer.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    const SourcePos& LBracketPos() const { return lbPos; }
    const SourcePos& RBracketPos() const { return rbPos; }
private:
    std::unique_ptr<Node> declSpecifiers;
    std::unique_ptr<Node> refQualifier;
    std::unique_ptr<Node> identifiers;
    std::unique_ptr<Node> initializer;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
    SourcePos lbPos;
    SourcePos rbPos;
};

class AST_API ForStatementNode : public CompoundNode
{
public:
    ForStatementNode(const SourcePos& sourcePos_);
    ForStatementNode(const SourcePos& sourcePos_, Node* initStmt_, Node* cond_, Node* loopExpr_, Node* stmt_, Node* attributes_, Node* semicolon_, const SourcePos& forPos_,
        const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* InitStatement() const { return initStmt.get(); }
    Node* Condition() const { return cond.get(); }
    Node* LoopExpr() const { return loopExpr.get(); }
    Node* Statement() const { return stmt.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    const SourcePos& ForPos() const { return forPos; }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> initStmt;
    std::unique_ptr<Node> cond;
    std::unique_ptr<Node> loopExpr;
    std::unique_ptr<Node> stmt;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
    SourcePos forPos;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API BreakStatementNode : public CompoundNode
{
public:
    BreakStatementNode(const SourcePos& sourcePos_);
    BreakStatementNode(const SourcePos& sourcePos_, Node* attributes_, Node* semicolon_, const SourcePos& breakPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    const SourcePos& BreakPos() const { return breakPos; }
private:
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
    SourcePos breakPos;
};

class AST_API ContinueStatementNode : public CompoundNode
{
public:
    ContinueStatementNode(const SourcePos& sourcePos_);
    ContinueStatementNode(const SourcePos& sourcePos_, Node* attributes_, Node* semicolon_, const SourcePos& continuePos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    const SourcePos& ContinuePos() const { return continuePos; }
private:
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
    SourcePos continuePos;
};

class AST_API ReturnStatementNode : public CompoundNode
{
public:
    ReturnStatementNode(const SourcePos& sourcePos_);
    ReturnStatementNode(const SourcePos& sourcePos_, Node* returnValue_, Node* attributes_, Node* semicolon_, const SourcePos& returnPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ReturnValue() const { return returnValue.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    const SourcePos& ReturnPos() const { return returnPos; }
private:
    std::unique_ptr<Node> returnValue;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
    SourcePos returnPos;
};

class AST_API CoReturnStatementNode : public CompoundNode
{
public:
    CoReturnStatementNode(const SourcePos& sourcePos_);
    CoReturnStatementNode(const SourcePos& sourcePos_, Node* returnValue_, Node* attributes_, Node* semicolon_, const SourcePos& coReturnPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* ReturnValue() const { return returnValue.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
    const SourcePos& CoReturnPos() const { return coReturnPos; }
private:
    std::unique_ptr<Node> returnValue;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
    SourcePos coReturnPos;
};

class AST_API GotoStatementNode : public CompoundNode
{
public:
    GotoStatementNode(const SourcePos& sourcePos_);
    GotoStatementNode(const SourcePos& sourcePos_, Node* target_, Node* attributes_, Node* semicolon_, const SourcePos& gotoPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Target() const { return target.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semimcolon() const { return semicolon.get(); }
    const SourcePos& GotoPos() const { return gotoPos; }
private:
    std::unique_ptr<Node> target;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
    SourcePos gotoPos;
};

class AST_API TryStatementNode : public CompoundNode
{
public:
    TryStatementNode(const SourcePos& sourcePos_);
    TryStatementNode(const SourcePos& sourcePos_, Node* tryBlock_, Node* handlers_, Node* attributes_, const SourcePos& tryPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TryBlock() const { return tryBlock.get(); }
    Node* Handlers() const { return handlers.get(); }
    Node* Attributes() const { return attributes.get(); }
    const SourcePos& TryPos() const { return tryPos; }
private:
    std::unique_ptr<Node> tryBlock;
    std::unique_ptr<Node> handlers;
    std::unique_ptr<Node> attributes;
    SourcePos tryPos;
};

class AST_API HandlerSequenceNode : public SequenceNode
{
public:
    HandlerSequenceNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

class AST_API HandlerNode : public CompoundNode
{
public:
    HandlerNode(const SourcePos& sourcePos_);
    HandlerNode(const SourcePos& sourcePos_, Node* exception_, Node* catchBlock_, const SourcePos& lpPos_, const SourcePos& rpPos_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Exception() const { return exception.get(); }
    Node* CatchBlock() const { return catchBlock.get(); }
    const SourcePos& LParenPos() const { return lpPos; }
    const SourcePos& RParenPos() const { return rpPos; }
private:
    std::unique_ptr<Node> exception;
    std::unique_ptr<Node> catchBlock;
    SourcePos lpPos;
    SourcePos rpPos;
};

class AST_API ExceptionDeclarationNode : public CompoundNode
{
public:
    ExceptionDeclarationNode(const SourcePos& sourcePos_);
    ExceptionDeclarationNode(const SourcePos& sourcePos_, Node* typeSpecifiers_, Node* declarator_, Node* attributes_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* TypeSpecifiers() const { return typeSpecifiers.get(); }
    Node* Declarator() const { return declarator.get(); }
    Node* Attributes() const { return attributes.get(); }
private:
    std::unique_ptr<Node> typeSpecifiers;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> attributes;
};

class AST_API ExpressionStatementNode : public CompoundNode
{
public:
    ExpressionStatementNode(const SourcePos& sourcePos_);
    ExpressionStatementNode(const SourcePos& sourcePos_, Node* expr_, Node* attributes_, Node* semicolon_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Expression() const { return expr.get(); }
    Node* Attributes() const { return attributes.get(); }
    Node* Semicolon() const { return semicolon.get(); }
private:
    std::unique_ptr<Node> expr;
    std::unique_ptr<Node> attributes;
    std::unique_ptr<Node> semicolon;
};

class AST_API DeclarationStatementNode : public CompoundNode
{
public:
    DeclarationStatementNode(const SourcePos& sourcePos_);
    DeclarationStatementNode(const SourcePos& sourcePos_, Node* declaration_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* Declaration() const { return declaration.get();  }
private:
    std::unique_ptr<Node> declaration;
};

class AST_API InitConditionNode : public CompoundNode
{
public:
    InitConditionNode(const SourcePos& sourcePos_);
    InitConditionNode(const SourcePos& sourcePos_, Node* declSpecifiers_, Node* declarator_, Node* initializer_, Node* attributes_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    Node* DeclSpecifiers() const { return declSpecifiers.get(); }
    Node* Declarator() const { return declarator.get(); }
    Node* Initializer() const { return initializer.get(); }
    Node* Attributes() const { return attributes.get(); }
private:
    std::unique_ptr<Node> declSpecifiers;
    std::unique_ptr<Node> declarator;
    std::unique_ptr<Node> initializer;
    std::unique_ptr<Node> attributes;
};

class AST_API SemicolonNode : public Node
{
public:
    SemicolonNode(const SourcePos& sourcePos_);
    void Accept(Visitor& visitor) override;
};

} // sngcpp::ast

#endif // SNGCPP_AST_STATEMENT_INCLUDED
