#include "Statement.hpp"
#include <soulng/util/Unicode.hpp>
#include <soulng/cmajorparser/Expression.hpp>
#include <soulng/cmajorparser/TypeExpr.hpp>
#include <soulng/cmajorparser/Identifier.hpp>
#include <soulng/cmajorlexer/CmajorLexer.hpp>
#include <soulng/cmajorlexer/CmajorTokens.hpp>

// this file has been automatically generated from 'D:/work/soulng/cmajorparser/Statement.parser' using soulng parser generator spg version 1.0.0

using namespace soulng::unicode;
using namespace cmajor::ast;
using namespace CmajorTokens;

soulng::parser::Match StatementParser::Statement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<StatementNode> labeledStatement;
    std::unique_ptr<StatementNode> controlStatement;
    std::unique_ptr<StatementNode> expressionStatement;
    std::unique_ptr<StatementNode> assignmentStatement;
    std::unique_ptr<ConstructionStatementNode> constructionStatement;
    std::unique_ptr<StatementNode> deleteStatement;
    std::unique_ptr<StatementNode> destroyStatement;
    std::unique_ptr<StatementNode> emptyStatement;
    std::unique_ptr<StatementNode> throwStatement;
    std::unique_ptr<TryStatementNode> tryStatement;
    std::unique_ptr<StatementNode> assertStatement;
    std::unique_ptr<ConditionalCompilationStatementNode> condCompStatement;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int save = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int save = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = StatementParser::LabeledStatement(lexer, ctx);
                                                    labeledStatement.reset(static_cast<StatementNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        return soulng::parser::Match(true, labeledStatement.release());
                                                    }
                                                    *parentMatch11 = match;
                                                }
                                                *parentMatch10 = match;
                                                if (!match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    lexer.SetPos(save);
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch13 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            soulng::parser::Match match = StatementParser::ControlStatement(lexer, ctx);
                                                            controlStatement.reset(static_cast<StatementNode*>(match.value));
                                                            if (match.hit)
                                                            {
                                                                return soulng::parser::Match(true, controlStatement.release());
                                                            }
                                                            *parentMatch13 = match;
                                                        }
                                                        *parentMatch12 = match;
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                            }
                                            *parentMatch9 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch14 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch15 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match = StatementParser::ExpressionStatement(lexer, ctx);
                                                        expressionStatement.reset(static_cast<StatementNode*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            return soulng::parser::Match(true, expressionStatement.release());
                                                        }
                                                        *parentMatch15 = match;
                                                    }
                                                    *parentMatch14 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch16 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch17 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = StatementParser::AssignmentStatement(lexer, ctx);
                                                    assignmentStatement.reset(static_cast<StatementNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        return soulng::parser::Match(true, assignmentStatement.release());
                                                    }
                                                    *parentMatch17 = match;
                                                }
                                                *parentMatch16 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch18 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch19 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = StatementParser::ConstructionStatement(lexer, ctx);
                                                constructionStatement.reset(static_cast<ConstructionStatementNode*>(match.value));
                                                if (match.hit)
                                                {
                                                    return soulng::parser::Match(true, constructionStatement.release());
                                                }
                                                *parentMatch19 = match;
                                            }
                                            *parentMatch18 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch20 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch21 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = StatementParser::DeleteStatement(lexer, ctx);
                                            deleteStatement.reset(static_cast<StatementNode*>(match.value));
                                            if (match.hit)
                                            {
                                                return soulng::parser::Match(true, deleteStatement.release());
                                            }
                                            *parentMatch21 = match;
                                        }
                                        *parentMatch20 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch22 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch23 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = StatementParser::DestroyStatement(lexer, ctx);
                                        destroyStatement.reset(static_cast<StatementNode*>(match.value));
                                        if (match.hit)
                                        {
                                            return soulng::parser::Match(true, destroyStatement.release());
                                        }
                                        *parentMatch23 = match;
                                    }
                                    *parentMatch22 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch24 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch25 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = StatementParser::EmptyStatement(lexer, ctx);
                                    emptyStatement.reset(static_cast<StatementNode*>(match.value));
                                    if (match.hit)
                                    {
                                        return soulng::parser::Match(true, emptyStatement.release());
                                    }
                                    *parentMatch25 = match;
                                }
                                *parentMatch24 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch26 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch27 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = StatementParser::ThrowStatement(lexer, ctx);
                                throwStatement.reset(static_cast<StatementNode*>(match.value));
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, throwStatement.release());
                                }
                                *parentMatch27 = match;
                            }
                            *parentMatch26 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch28 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch29 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = StatementParser::TryStatement(lexer, ctx);
                            tryStatement.reset(static_cast<TryStatementNode*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, tryStatement.release());
                            }
                            *parentMatch29 = match;
                        }
                        *parentMatch28 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch30 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch31 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::AssertStatement(lexer, ctx);
                        assertStatement.reset(static_cast<StatementNode*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, assertStatement.release());
                        }
                        *parentMatch31 = match;
                    }
                    *parentMatch30 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch32 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch33 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = StatementParser::ConditionalCompilationStatement(lexer, ctx);
                    condCompStatement.reset(static_cast<ConditionalCompilationStatementNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, condCompStatement.release());
                    }
                    *parentMatch33 = match;
                }
                *parentMatch32 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match StatementParser::Label(CmajorLexer& lexer)
{
    Span s = Span();
    std::u32string label = std::u32string();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == ID)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s = span;
                    label = lexer.GetMatch(span);
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == COLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        s.end = span.end;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new LabelNode(s, label));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::LabeledStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<StatementNode> stmt = std::unique_ptr<StatementNode>();
    std::unique_ptr<LabelNode> lbl;
    std::unique_ptr<StatementNode> s;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = StatementParser::Label(lexer);
        lbl.reset(static_cast<LabelNode*>(match.value));
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                s.reset(static_cast<StatementNode*>(match.value));
                if (match.hit)
                {
                    stmt.reset(s.release());
                    stmt->SetLabelNode(lbl.release());
                    return soulng::parser::Match(true, stmt.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ControlStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<CompoundStatementNode> compoundStatement;
    std::unique_ptr<StatementNode> returnStatement;
    std::unique_ptr<IfStatementNode> ifStatement;
    std::unique_ptr<WhileStatementNode> whileStatement;
    std::unique_ptr<DoStatementNode> doStatement;
    std::unique_ptr<RangeForStatementNode> rangeForStatement;
    std::unique_ptr<ForStatementNode> forStatement;
    std::unique_ptr<StatementNode> breakStatement;
    std::unique_ptr<StatementNode> continueStatement;
    std::unique_ptr<StatementNode> gotoStatement;
    std::unique_ptr<SwitchStatementNode> switchStatement;
    std::unique_ptr<StatementNode> gotoCaseStatement;
    std::unique_ptr<StatementNode> gotoDefaultStatement;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int save = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int save = lexer.GetPos();
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int save = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int save = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int save = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int save = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch10 = &match;
                                            {
                                                int save = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch11 = &match;
                                                {
                                                    int save = lexer.GetPos();
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch12 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                                                        compoundStatement.reset(static_cast<CompoundStatementNode*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            return soulng::parser::Match(true, compoundStatement.release());
                                                        }
                                                        *parentMatch12 = match;
                                                    }
                                                    *parentMatch11 = match;
                                                    if (!match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch13 = &match;
                                                        lexer.SetPos(save);
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch14 = &match;
                                                            {
                                                                int pos = lexer.GetPos();
                                                                soulng::parser::Match match = StatementParser::ReturnStatement(lexer, ctx);
                                                                returnStatement.reset(static_cast<StatementNode*>(match.value));
                                                                if (match.hit)
                                                                {
                                                                    return soulng::parser::Match(true, returnStatement.release());
                                                                }
                                                                *parentMatch14 = match;
                                                            }
                                                            *parentMatch13 = match;
                                                        }
                                                        *parentMatch11 = match;
                                                    }
                                                }
                                                *parentMatch10 = match;
                                                if (!match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch15 = &match;
                                                    lexer.SetPos(save);
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch16 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            soulng::parser::Match match = StatementParser::IfStatement(lexer, ctx);
                                                            ifStatement.reset(static_cast<IfStatementNode*>(match.value));
                                                            if (match.hit)
                                                            {
                                                                return soulng::parser::Match(true, ifStatement.release());
                                                            }
                                                            *parentMatch16 = match;
                                                        }
                                                        *parentMatch15 = match;
                                                    }
                                                    *parentMatch10 = match;
                                                }
                                            }
                                            *parentMatch9 = match;
                                            if (!match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch17 = &match;
                                                lexer.SetPos(save);
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch18 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match = StatementParser::WhileStatement(lexer, ctx);
                                                        whileStatement.reset(static_cast<WhileStatementNode*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            return soulng::parser::Match(true, whileStatement.release());
                                                        }
                                                        *parentMatch18 = match;
                                                    }
                                                    *parentMatch17 = match;
                                                }
                                                *parentMatch9 = match;
                                            }
                                        }
                                        *parentMatch8 = match;
                                        if (!match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch19 = &match;
                                            lexer.SetPos(save);
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch20 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    soulng::parser::Match match = StatementParser::DoStatement(lexer, ctx);
                                                    doStatement.reset(static_cast<DoStatementNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        return soulng::parser::Match(true, doStatement.release());
                                                    }
                                                    *parentMatch20 = match;
                                                }
                                                *parentMatch19 = match;
                                            }
                                            *parentMatch8 = match;
                                        }
                                    }
                                    *parentMatch7 = match;
                                    if (!match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch21 = &match;
                                        lexer.SetPos(save);
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch22 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match = StatementParser::RangeForStatement(lexer, ctx);
                                                rangeForStatement.reset(static_cast<RangeForStatementNode*>(match.value));
                                                if (match.hit)
                                                {
                                                    return soulng::parser::Match(true, rangeForStatement.release());
                                                }
                                                *parentMatch22 = match;
                                            }
                                            *parentMatch21 = match;
                                        }
                                        *parentMatch7 = match;
                                    }
                                }
                                *parentMatch6 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch23 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch24 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = StatementParser::ForStatement(lexer, ctx);
                                            forStatement.reset(static_cast<ForStatementNode*>(match.value));
                                            if (match.hit)
                                            {
                                                return soulng::parser::Match(true, forStatement.release());
                                            }
                                            *parentMatch24 = match;
                                        }
                                        *parentMatch23 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                            }
                            *parentMatch5 = match;
                            if (!match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch25 = &match;
                                lexer.SetPos(save);
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch26 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = StatementParser::BreakStatement(lexer, ctx);
                                        breakStatement.reset(static_cast<StatementNode*>(match.value));
                                        if (match.hit)
                                        {
                                            return soulng::parser::Match(true, breakStatement.release());
                                        }
                                        *parentMatch26 = match;
                                    }
                                    *parentMatch25 = match;
                                }
                                *parentMatch5 = match;
                            }
                        }
                        *parentMatch4 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch27 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch28 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = StatementParser::ContinueStatement(lexer, ctx);
                                    continueStatement.reset(static_cast<StatementNode*>(match.value));
                                    if (match.hit)
                                    {
                                        return soulng::parser::Match(true, continueStatement.release());
                                    }
                                    *parentMatch28 = match;
                                }
                                *parentMatch27 = match;
                            }
                            *parentMatch4 = match;
                        }
                    }
                    *parentMatch3 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch29 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch30 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = StatementParser::GotoStatement(lexer, ctx);
                                gotoStatement.reset(static_cast<StatementNode*>(match.value));
                                if (match.hit)
                                {
                                    return soulng::parser::Match(true, gotoStatement.release());
                                }
                                *parentMatch30 = match;
                            }
                            *parentMatch29 = match;
                        }
                        *parentMatch3 = match;
                    }
                }
                *parentMatch2 = match;
                if (!match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch31 = &match;
                    lexer.SetPos(save);
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch32 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = StatementParser::SwitchStatement(lexer, ctx);
                            switchStatement.reset(static_cast<SwitchStatementNode*>(match.value));
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, switchStatement.release());
                            }
                            *parentMatch32 = match;
                        }
                        *parentMatch31 = match;
                    }
                    *parentMatch2 = match;
                }
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch33 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch34 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::GotoCaseStatement(lexer, ctx);
                        gotoCaseStatement.reset(static_cast<StatementNode*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, gotoCaseStatement.release());
                        }
                        *parentMatch34 = match;
                    }
                    *parentMatch33 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch35 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch36 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = StatementParser::GotoDefaultStatement(lexer, ctx);
                    gotoDefaultStatement.reset(static_cast<StatementNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, gotoDefaultStatement.release());
                    }
                    *parentMatch36 = match;
                }
                *parentMatch35 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match StatementParser::CompoundStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<CompoundStatementNode> compoundStatement = std::unique_ptr<CompoundStatementNode>();
    std::unique_ptr<StatementNode> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == LBRACE)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    compoundStatement.reset(new CompoundStatementNode(span));
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch5 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                                stmt.reset(static_cast<StatementNode*>(match.value));
                                if (match.hit)
                                {
                                    compoundStatement->AddStatement(stmt.release());
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch4 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch6 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RBRACE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                    }
                }
                if (match.hit)
                {
                    compoundStatement->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, compoundStatement.release());
                }
                *parentMatch7 = match;
            }
            *parentMatch6 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ReturnStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == RETURN)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s = span;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                    expr.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        *parentMatch4 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch5 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new ReturnStatementNode(s, expr.release()));
                }
                *parentMatch6 = match;
            }
            *parentMatch5 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::IfStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    Span leftParenSpan = Span();
    Span rightParenSpan = Span();
    Span elseSpan = Span();
    std::unique_ptr<Node> cond;
    std::unique_ptr<StatementNode> thenS;
    std::unique_ptr<StatementNode> elseS;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                int pos = lexer.GetPos();
                                Span span = lexer.GetSpan();
                                soulng::parser::Match match(false);
                                if (*lexer == IF)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    s = span;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    Span span = lexer.GetSpan();
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        leftParenSpan = span;
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch9 = &match;
                        {
                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                            cond.reset(static_cast<Node*>(match.value));
                            *parentMatch9 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                rightParenSpan = span;
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch10 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch12 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch13 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                        thenS.reset(static_cast<StatementNode*>(match.value));
                        if (match.hit)
                        {
                            s.end = span.end;
                        }
                        *parentMatch13 = match;
                    }
                    *parentMatch12 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch14 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch15 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch16 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch17 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == ELSE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                elseSpan = span;
                            }
                            *parentMatch17 = match;
                        }
                        *parentMatch16 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch18 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch19 = &match;
                            {
                                int pos = lexer.GetPos();
                                Span span = lexer.GetSpan();
                                soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                                elseS.reset(static_cast<StatementNode*>(match.value));
                                if (match.hit)
                                {
                                    s.end = span.end;
                                }
                                *parentMatch19 = match;
                            }
                            *parentMatch18 = match;
                        }
                        *parentMatch16 = match;
                    }
                    if (match.hit)
                    {
                        *parentMatch15 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch14 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            IfStatementNode * value = new IfStatementNode(s, cond.release(), thenS.release(), elseS.release());
            value->SetLeftParenSpan(leftParenSpan);
            value->SetRightParenSpan(rightParenSpan);
            value->SetElseSpan(elseSpan);
            return soulng::parser::Match(true, value);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::WhileStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    Span leftParenSpan = Span();
    Span rightParenSpan = Span();
    std::unique_ptr<Node> cond;
    std::unique_ptr<StatementNode> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == WHILE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                s = span;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int pos = lexer.GetPos();
                                Span span = lexer.GetSpan();
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                    }
                                }
                                if (match.hit)
                                {
                                    leftParenSpan = span;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                            cond.reset(static_cast<Node*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"expression");
                            }
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                            }
                        }
                        if (match.hit)
                        {
                            rightParenSpan = span;
                        }
                        *parentMatch10 = match;
                    }
                    *parentMatch9 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch11 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch12 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                        stmt.reset(static_cast<StatementNode*>(match.value));
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"statement");
                        }
                    }
                    if (match.hit)
                    {
                        s.end = span.end;
                    }
                    *parentMatch12 = match;
                }
                *parentMatch11 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            WhileStatementNode * value = new WhileStatementNode(s, cond.release(), stmt.release());
            value->SetLeftParenSpan(leftParenSpan);
            value->SetRightParenSpan(rightParenSpan);
            return soulng::parser::Match(true, value);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::DoStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    Span whileSpan = Span();
    Span leftParenSpan = Span();
    Span rightParenSpan = Span();
    std::unique_ptr<StatementNode> stmt;
    std::unique_ptr<Node> cond;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    Span span = lexer.GetSpan();
                                    soulng::parser::Match match(false);
                                    if (*lexer == DO)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (match.hit)
                                    {
                                        s = span;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                                        stmt.reset(static_cast<StatementNode*>(match.value));
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, U"statement");
                                        }
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch10 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    Span span = lexer.GetSpan();
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        if (*lexer == WHILE)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(WHILE)));
                                        }
                                    }
                                    if (match.hit)
                                    {
                                        whileSpan = span;
                                    }
                                    *parentMatch10 = match;
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch11 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch12 = &match;
                            {
                                int pos = lexer.GetPos();
                                Span span = lexer.GetSpan();
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                    }
                                }
                                if (match.hit)
                                {
                                    leftParenSpan = span;
                                }
                                *parentMatch12 = match;
                            }
                            *parentMatch11 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch13 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                            cond.reset(static_cast<Node*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"expression");
                            }
                        }
                        *parentMatch13 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch14 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch15 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                            }
                        }
                        if (match.hit)
                        {
                            rightParenSpan = span;
                        }
                        *parentMatch15 = match;
                    }
                    *parentMatch14 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch16 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch17 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == SEMICOLON)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                        }
                    }
                    if (match.hit)
                    {
                        s.end = span.end;
                    }
                    *parentMatch17 = match;
                }
                *parentMatch16 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            DoStatementNode * value = new DoStatementNode(s, stmt.release(), cond.release());
            value->SetWhileSpan(whileSpan);
            value->SetLeftParenSpan(leftParenSpan);
            value->SetRightParenSpan(rightParenSpan);
            return soulng::parser::Match(true, value);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ForStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    Span leftParenSpan = Span();
    Span rightParenSpan = Span();
    std::unique_ptr<StatementNode> init;
    std::unique_ptr<Node> cond;
    std::unique_ptr<StatementNode> loop;
    std::unique_ptr<StatementNode> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == FOR)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            s = span;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch10 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            Span span = lexer.GetSpan();
                                            soulng::parser::Match match(false);
                                            if (*lexer == LPAREN)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                leftParenSpan = span;
                                            }
                                            *parentMatch10 = match;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = StatementParser::ForInitStatement(lexer, ctx);
                                        init.reset(static_cast<StatementNode*>(match.value));
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, U"for initialization statement");
                                        }
                                    }
                                    *parentMatch11 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch12 = &match;
                            {
                                soulng::parser::Match match(true);
                                int save = lexer.GetPos();
                                soulng::parser::Match* parentMatch13 = &match;
                                {
                                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                    cond.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        *parentMatch13 = match;
                                    }
                                    else
                                    {
                                        lexer.SetPos(save);
                                    }
                                }
                                *parentMatch12 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch14 = &match;
                        {
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == SEMICOLON)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                                }
                            }
                            *parentMatch14 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch15 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = StatementParser::ForLoopStatementExpr(lexer, ctx);
                            loop.reset(static_cast<StatementNode*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"for loop expression");
                            }
                        }
                        *parentMatch15 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch16 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch17 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                            }
                        }
                        if (match.hit)
                        {
                            rightParenSpan = span;
                        }
                        *parentMatch17 = match;
                    }
                    *parentMatch16 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch18 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch19 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                        stmt.reset(static_cast<StatementNode*>(match.value));
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, U"statement");
                        }
                    }
                    if (match.hit)
                    {
                        s.end = span.end;
                    }
                    *parentMatch19 = match;
                }
                *parentMatch18 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            ForStatementNode * value = new ForStatementNode(s, init.release(), cond.release(), loop.release(), stmt.release());
            value->SetLeftParenSpan(leftParenSpan);
            value->SetRightParenSpan(rightParenSpan);
            return soulng::parser::Match(true, value);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ForInitStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<StatementNode> assignmentStatement;
    std::unique_ptr<ConstructionStatementNode> constructionStatement;
    std::unique_ptr<StatementNode> emptyStatement;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = StatementParser::AssignmentStatement(lexer, ctx);
                assignmentStatement.reset(static_cast<StatementNode*>(match.value));
                if (match.hit)
                {
                    return soulng::parser::Match(true, assignmentStatement.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::ConstructionStatement(lexer, ctx);
                        constructionStatement.reset(static_cast<ConstructionStatementNode*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, constructionStatement.release());
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = StatementParser::EmptyStatement(lexer, ctx);
                    emptyStatement.reset(static_cast<StatementNode*>(match.value));
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, emptyStatement.release());
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match StatementParser::ForLoopStatementExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<StatementNode> assignmentStatementExpr;
    std::unique_ptr<Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match = StatementParser::AssignmentStatementExpr(lexer, ctx);
                assignmentStatementExpr.reset(static_cast<StatementNode*>(match.value));
                if (match.hit)
                {
                    return soulng::parser::Match(true, assignmentStatementExpr.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                        expr.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            return soulng::parser::Match(true, new ExpressionStatementNode(span, expr.release()));
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch1 = match;
            }
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    if (match.hit)
                    {
                        return soulng::parser::Match(true, new EmptyStatementNode(span));
                    }
                    *parentMatch6 = match;
                }
                *parentMatch5 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}

soulng::parser::Match StatementParser::RangeForStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    Span leftParenSpan = Span();
    Span rightParenSpan = Span();
    Span colonSpan = Span();
    std::unique_ptr<Node> type;
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<Node> container;
    std::unique_ptr<StatementNode> action;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == FOR)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            s = span;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch10 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            Span span = lexer.GetSpan();
                                            soulng::parser::Match match(false);
                                            if (*lexer == LPAREN)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                leftParenSpan = span;
                                            }
                                            *parentMatch10 = match;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                                    type.reset(static_cast<Node*>(match.value));
                                    *parentMatch11 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch12 = &match;
                            {
                                soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                                id.reset(static_cast<IdentifierNode*>(match.value));
                                *parentMatch12 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch13 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch14 = &match;
                            {
                                int pos = lexer.GetPos();
                                Span span = lexer.GetSpan();
                                soulng::parser::Match match(false);
                                if (*lexer == COLON)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (match.hit)
                                {
                                    colonSpan = span;
                                }
                                *parentMatch14 = match;
                            }
                            *parentMatch13 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch15 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                            container.reset(static_cast<Node*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"expression");
                            }
                        }
                        *parentMatch15 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch16 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch17 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == RPAREN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                            }
                        }
                        if (match.hit)
                        {
                            rightParenSpan = span;
                        }
                        *parentMatch17 = match;
                    }
                    *parentMatch16 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch18 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch19 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                    action.reset(static_cast<StatementNode*>(match.value));
                    if (match.hit)
                    {
                        s.end = span.end;
                    }
                    *parentMatch19 = match;
                }
                *parentMatch18 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            RangeForStatementNode * value = new RangeForStatementNode(s, type.release(), id.release(), container.release(), action.release());
            value->SetLeftParenSpan(leftParenSpan);
            value->SetRightParenSpan(rightParenSpan);
            value->SetColonSpan(colonSpan);
            return soulng::parser::Match(true, value);
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::BreakStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            Span span = lexer.GetSpan();
            soulng::parser::Match match(false);
            if (*lexer == BREAK)
            {
                ++lexer;
                match.hit = true;
            }
            if (match.hit)
            {
                s = span;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch2 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new BreakStatementNode(s));
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ContinueStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            Span span = lexer.GetSpan();
            soulng::parser::Match match(false);
            if (*lexer == CONTINUE)
            {
                ++lexer;
                match.hit = true;
            }
            if (match.hit)
            {
                s = span;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch2 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new ContinueStatementNode(s));
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::GotoStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::u32string label = std::u32string();
    Span s = Span();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == GOTO)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s = span;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == ID)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        label = lexer.GetMatch(span);
                    }
                    *parentMatch4 = match;
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch5 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new GotoStatementNode(s, label));
                }
                *parentMatch6 = match;
            }
            *parentMatch5 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::SwitchStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<SwitchStatementNode> switchStatement = std::unique_ptr<SwitchStatementNode>();
    Span leftParenSpan = Span();
    Span rightParenSpan = Span();
    Span beginBraceSpan = Span();
    Span endBraceSpan = Span();
    std::unique_ptr<Node> cond;
    std::unique_ptr<CaseStatementNode> caseStatement;
    std::unique_ptr<DefaultStatementNode> defaultStatement;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == SWITCH)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match(true);
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            if (*lexer == LPAREN)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (!match.hit)
                                            {
                                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                            }
                                        }
                                        if (match.hit)
                                        {
                                            leftParenSpan = span;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                    cond.reset(static_cast<Node*>(match.value));
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, U"expression");
                                    }
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch10 = &match;
                        {
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == RPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                }
                            }
                            *parentMatch10 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        rightParenSpan = span;
                        switchStatement.reset(new SwitchStatementNode(span, cond.release()));
                        switchStatement->SetLeftParenSpan(leftParenSpan);
                        switchStatement->SetRightParenSpan(rightParenSpan);
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch11 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch12 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == LBRACE)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LBRACE)));
                            }
                        }
                        if (match.hit)
                        {
                            beginBraceSpan = span;
                        }
                        *parentMatch12 = match;
                    }
                    *parentMatch11 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch13 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch14 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch15 = &match;
                            {
                                int save = lexer.GetPos();
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch16 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = StatementParser::CaseStatement(lexer, ctx);
                                    caseStatement.reset(static_cast<CaseStatementNode*>(match.value));
                                    if (match.hit)
                                    {
                                        switchStatement->AddCase(caseStatement.release());
                                    }
                                    *parentMatch16 = match;
                                }
                                *parentMatch15 = match;
                                if (!match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch17 = &match;
                                    lexer.SetPos(save);
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch18 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = StatementParser::DefaultStatement(lexer, ctx);
                                            defaultStatement.reset(static_cast<DefaultStatementNode*>(match.value));
                                            if (match.hit)
                                            {
                                                switchStatement->SetDefault(defaultStatement.release());
                                            }
                                            *parentMatch18 = match;
                                        }
                                        *parentMatch17 = match;
                                    }
                                    *parentMatch15 = match;
                                }
                            }
                            if (match.hit)
                            {
                                *parentMatch14 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch13 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch19 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch20 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == RBRACE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RBRACE)));
                    }
                }
                if (match.hit)
                {
                    endBraceSpan = span;
                    switchStatement->SetBeginBraceSpan(beginBraceSpan);
                    switchStatement->SetEndBraceSpan(endBraceSpan);
                    return soulng::parser::Match(true, switchStatement.release());
                }
                *parentMatch20 = match;
            }
            *parentMatch19 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::CaseStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<CaseStatementNode> caseS = std::unique_ptr<CaseStatementNode>();
    Span s = Span();
    Span caseSpan = Span();
    std::unique_ptr<Node> caseExpr;
    std::unique_ptr<StatementNode> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    Span span = lexer.GetSpan();
                                    soulng::parser::Match match(true);
                                    if (match.hit)
                                    {
                                        caseS.reset(new CaseStatementNode(span));
                                        s = span;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch8 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch9 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == CASE)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            caseSpan = span;
                                        }
                                        *parentMatch9 = match;
                                    }
                                    *parentMatch8 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch10 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch11 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                    caseExpr.reset(static_cast<Node*>(match.value));
                                    if (match.hit)
                                    {
                                        caseS->AddCaseSpan(caseSpan);
                                        caseS->AddCaseExpr(caseExpr.release());
                                    }
                                    *parentMatch11 = match;
                                }
                                *parentMatch10 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch12 = &match;
                        {
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == COLON)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(COLON)));
                                }
                            }
                            *parentMatch12 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch13 = &match;
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch14 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch15 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch16 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch17 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            Span span = lexer.GetSpan();
                                            soulng::parser::Match match(true);
                                            if (match.hit)
                                            {
                                                caseS.reset(new CaseStatementNode(span));
                                                s = span;
                                            }
                                            *parentMatch17 = match;
                                        }
                                        *parentMatch16 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch18 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch19 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                Span span = lexer.GetSpan();
                                                soulng::parser::Match match(false);
                                                if (*lexer == CASE)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    caseSpan = span;
                                                }
                                                *parentMatch19 = match;
                                            }
                                            *parentMatch18 = match;
                                        }
                                        *parentMatch16 = match;
                                    }
                                    *parentMatch15 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch20 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch21 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                            caseExpr.reset(static_cast<Node*>(match.value));
                                            if (match.hit)
                                            {
                                                caseS->AddCaseSpan(caseSpan);
                                                caseS->AddCaseExpr(caseExpr.release());
                                            }
                                            *parentMatch21 = match;
                                        }
                                        *parentMatch20 = match;
                                    }
                                    *parentMatch15 = match;
                                }
                                *parentMatch14 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch22 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        if (*lexer == COLON)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(COLON)));
                                        }
                                    }
                                    *parentMatch22 = match;
                                }
                                *parentMatch14 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch13 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    caseS->SetSpan(s);
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch23 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch24 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch25 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                                stmt.reset(static_cast<StatementNode*>(match.value));
                                if (match.hit)
                                {
                                    caseS->AddStatement(stmt.release());
                                }
                                *parentMatch25 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch24 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch23 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, caseS.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::DefaultStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<DefaultStatementNode> defaultS = std::unique_ptr<DefaultStatementNode>();
    Span s = Span();
    std::unique_ptr<StatementNode> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == DEFAULT)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        s = span;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(false);
                            if (*lexer == COLON)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(COLON)));
                            }
                        }
                        if (match.hit)
                        {
                            s.end = span.end;
                            defaultS.reset(new DefaultStatementNode(s));
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch7 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch8 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                                stmt.reset(static_cast<StatementNode*>(match.value));
                                if (match.hit)
                                {
                                    defaultS->AddStatement(stmt.release());
                                }
                                *parentMatch8 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch7 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch6 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, defaultS.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::GotoCaseStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> caseExpr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == GOTO)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        s = span;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == CASE)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                caseExpr.reset(static_cast<Node*>(match.value));
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch6 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new GotoCaseStatementNode(s, caseExpr.release()));
                }
                *parentMatch7 = match;
            }
            *parentMatch6 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::GotoDefaultStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == GOTO)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s = span;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == DEFAULT)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch4 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new GotoDefaultStatementNode(s));
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::AssignmentStatementExpr(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> target;
    std::unique_ptr<Node> source;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    if (match.hit)
                    {
                        ctx->PushParsingLvalue(true);
                        s = span;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                        target.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            ctx->PopParsingLvalue();
                        }
                        else
                        {
                            ctx->PopParsingLvalue();
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                soulng::parser::Match match(false);
                if (*lexer == ASSIGN)
                {
                    ++lexer;
                    match.hit = true;
                }
                *parentMatch6 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch7 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch8 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                source.reset(static_cast<Node*>(match.value));
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new AssignmentStatementNode(s, target.release(), source.release()));
                }
                *parentMatch8 = match;
            }
            *parentMatch7 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::AssignmentStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<StatementNode> statement = std::unique_ptr<StatementNode>();
    std::unique_ptr<StatementNode> stmt;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match = StatementParser::AssignmentStatementExpr(lexer, ctx);
        stmt.reset(static_cast<StatementNode*>(match.value));
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == SEMICOLON)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    statement.reset(stmt.release());
                    statement->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, statement.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ConstructionStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ConstructionStatementNode> constructionStatement = std::unique_ptr<ConstructionStatementNode>();
    std::unique_ptr<Node> type;
    std::unique_ptr<IdentifierNode> id;
    std::unique_ptr<Node> value;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                    type.reset(static_cast<Node*>(match.value));
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                            id.reset(static_cast<IdentifierNode*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"identifier");
                            }
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    constructionStatement.reset(new ConstructionStatementNode(span, type.release(), id.release()));
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    int save = lexer.GetPos();
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int save = lexer.GetPos();
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch8 = &match;
                        {
                            soulng::parser::Match match(false);
                            if (*lexer == ASSIGN)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            *parentMatch8 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch10 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                                        value.reset(static_cast<Node*>(match.value));
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, U"expression");
                                        }
                                    }
                                    if (match.hit)
                                    {
                                        constructionStatement->AddArgument(value.release());
                                        constructionStatement->SetAssignment();
                                    }
                                    *parentMatch10 = match;
                                }
                                *parentMatch9 = match;
                            }
                            *parentMatch8 = match;
                        }
                        *parentMatch7 = match;
                        if (!match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch11 = &match;
                            lexer.SetPos(save);
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch12 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch13 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == LPAREN)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch13 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch14 = &match;
                                        {
                                            soulng::parser::Match match = ExpressionParser::ArgumentList(lexer, ctx, constructionStatement.get());
                                            *parentMatch14 = match;
                                        }
                                        *parentMatch13 = match;
                                    }
                                    *parentMatch12 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch15 = &match;
                                    {
                                        soulng::parser::Match match(true);
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match(false);
                                            if (*lexer == RPAREN)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (!match.hit)
                                            {
                                                lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                            }
                                        }
                                        *parentMatch15 = match;
                                    }
                                    *parentMatch12 = match;
                                }
                                *parentMatch11 = match;
                            }
                            *parentMatch7 = match;
                        }
                    }
                    *parentMatch6 = match;
                    if (!match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch16 = &match;
                        lexer.SetPos(save);
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch17 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(true);
                                if (match.hit)
                                {
                                    constructionStatement->SetEmpty();
                                }
                                *parentMatch17 = match;
                            }
                            *parentMatch16 = match;
                        }
                        *parentMatch6 = match;
                    }
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch18 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch19 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    constructionStatement->SetSpanEnd(span.end);
                    return soulng::parser::Match(true, constructionStatement.release());
                }
                *parentMatch19 = match;
            }
            *parentMatch18 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::DeleteStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> ptr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == DELETE)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s = span;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                    ptr.reset(static_cast<Node*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"expression");
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch4 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new DeleteStatementNode(s, ptr.release()));
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::DestroyStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> ptr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == DESTROY)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s = span;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                    ptr.reset(static_cast<Node*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"expression");
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch4 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new DestroyStatementNode(s, ptr.release()));
                }
                *parentMatch5 = match;
            }
            *parentMatch4 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ExpressionStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            soulng::parser::Match match(true);
            if (match.hit)
            {
                ctx->PushParsingExpressionStatement(true);
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch2 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                int pos = lexer.GetPos();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                        expr.reset(static_cast<Node*>(match.value));
                        if (match.hit)
                        {
                            s = span;
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch6 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == SEMICOLON)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                s.end = span.end;
                            }
                            *parentMatch7 = match;
                        }
                        *parentMatch6 = match;
                    }
                    *parentMatch4 = match;
                }
                if (match.hit)
                {
                    ctx->PopParsingExpressionStatement();
                    return soulng::parser::Match(true, new ExpressionStatementNode(s, expr.release()));
                }
                else
                {
                    ctx->PopParsingExpressionStatement();
                }
                *parentMatch3 = match;
            }
            *parentMatch2 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::EmptyStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        Span span = lexer.GetSpan();
        soulng::parser::Match match(false);
        if (*lexer == SEMICOLON)
        {
            ++lexer;
            match.hit = true;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, new EmptyStatementNode(span));
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ThrowStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> exception;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                if (*lexer == THROW)
                {
                    ++lexer;
                    match.hit = true;
                }
                if (match.hit)
                {
                    s = span;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                int save = lexer.GetPos();
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                    exception.reset(static_cast<Node*>(match.value));
                    if (match.hit)
                    {
                        *parentMatch4 = match;
                    }
                    else
                    {
                        lexer.SetPos(save);
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch5 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch6 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new ThrowStatementNode(s, exception.release()));
                }
                *parentMatch6 = match;
            }
            *parentMatch5 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::TryStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<TryStatementNode> tryStatement = std::unique_ptr<TryStatementNode>();
    std::unique_ptr<CompoundStatementNode> tryBlock;
    std::unique_ptr<CatchNode> ctch;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == TRY)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                        tryBlock.reset(static_cast<CompoundStatementNode*>(match.value));
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    tryStatement.reset(new TryStatementNode(span, tryBlock.release()));
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match = StatementParser::Catch(lexer, ctx);
                        ctch.reset(static_cast<CatchNode*>(match.value));
                        if (match.hit)
                        {
                            tryStatement->AddCatch(ctch.release());
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch6 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(true);
                    soulng::parser::Match* parentMatch8 = &match;
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch9 = &match;
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match = StatementParser::Catch(lexer, ctx);
                                ctch.reset(static_cast<CatchNode*>(match.value));
                                if (match.hit)
                                {
                                    tryStatement->AddCatch(ctch.release());
                                }
                                *parentMatch9 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch8 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, tryStatement.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::Catch(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    Span leftParenSpan = Span();
    Span rightParenSpan = Span();
    std::unique_ptr<Node> catchType;
    std::unique_ptr<IdentifierNode> catchId;
    std::unique_ptr<CompoundStatementNode> catchBlock;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            int pos = lexer.GetPos();
                            Span span = lexer.GetSpan();
                            soulng::parser::Match match(false);
                            if (*lexer == CATCH)
                            {
                                ++lexer;
                                match.hit = true;
                            }
                            if (match.hit)
                            {
                                s = span;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch6 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch7 = &match;
                            {
                                int pos = lexer.GetPos();
                                Span span = lexer.GetSpan();
                                soulng::parser::Match match(true);
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(false);
                                    if (*lexer == LPAREN)
                                    {
                                        ++lexer;
                                        match.hit = true;
                                    }
                                    if (!match.hit)
                                    {
                                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                    }
                                }
                                if (match.hit)
                                {
                                    leftParenSpan = span;
                                }
                                *parentMatch7 = match;
                            }
                            *parentMatch6 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch8 = &match;
                    {
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = TypeExprParser::TypeExpr(lexer, ctx);
                            catchType.reset(static_cast<Node*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"type expression");
                            }
                        }
                        *parentMatch8 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch9 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch10 = &match;
                    {
                        soulng::parser::Match match = IdentifierParser::Identifier(lexer);
                        catchId.reset(static_cast<IdentifierNode*>(match.value));
                        if (match.hit)
                        {
                            *parentMatch10 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch9 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch11 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch12 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(true);
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(false);
                        if (*lexer == RPAREN)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        if (!match.hit)
                        {
                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                        }
                    }
                    if (match.hit)
                    {
                        rightParenSpan = span;
                    }
                    *parentMatch12 = match;
                }
                *parentMatch11 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch13 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch14 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match = StatementParser::CompoundStatement(lexer, ctx);
                catchBlock.reset(static_cast<CompoundStatementNode*>(match.value));
                if (match.hit)
                {
                    s.end = span.end;
                    CatchNode * value = new CatchNode(s, catchType.release(), catchId.release(), catchBlock.release());
                    value->SetLeftParenSpan(leftParenSpan);
                    value->SetRightParenSpan(rightParenSpan);
                    return soulng::parser::Match(true, value);
                }
                *parentMatch14 = match;
            }
            *parentMatch13 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::AssertStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    Span s = Span();
    std::unique_ptr<Node> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == HASH)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        s = span;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    if (*lexer == ASSERT)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch5 = &match;
            {
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match = ExpressionParser::Expression(lexer, ctx);
                    expr.reset(static_cast<Node*>(match.value));
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, U"expression");
                    }
                }
                *parentMatch5 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch6 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch7 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == SEMICOLON)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(SEMICOLON)));
                    }
                }
                if (match.hit)
                {
                    s.end = span.end;
                    return soulng::parser::Match(true, new AssertStatementNode(s, expr.release()));
                }
                *parentMatch7 = match;
            }
            *parentMatch6 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ConditionalCompilationStatement(CmajorLexer& lexer, ParsingContext* ctx)
{
    std::unique_ptr<ConditionalCompilationStatementNode> condCompStmt = std::unique_ptr<ConditionalCompilationStatementNode>();
    Span s = Span();
    Span keywordSpan = Span();
    Span leftParenSpan = Span();
    Span rightParenSpan = Span();
    std::unique_ptr<ConditionalCompilationExpressionNode> ifExpr;
    std::unique_ptr<StatementNode> ifS;
    std::unique_ptr<ConditionalCompilationExpressionNode> elifExpr;
    std::unique_ptr<StatementNode> elifS;
    std::unique_ptr<StatementNode> elseS;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch6 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch7 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch8 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch9 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            Span span = lexer.GetSpan();
                                            soulng::parser::Match match(false);
                                            if (*lexer == HASH)
                                            {
                                                ++lexer;
                                                match.hit = true;
                                            }
                                            if (match.hit)
                                            {
                                                s = span;
                                                keywordSpan = span;
                                            }
                                            *parentMatch9 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch10 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch11 = &match;
                                            {
                                                int pos = lexer.GetPos();
                                                Span span = lexer.GetSpan();
                                                soulng::parser::Match match(false);
                                                if (*lexer == IF)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (match.hit)
                                                {
                                                    keywordSpan.end = span.end;
                                                }
                                                *parentMatch11 = match;
                                            }
                                            *parentMatch10 = match;
                                        }
                                        *parentMatch8 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch12 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch13 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            Span span = lexer.GetSpan();
                                            soulng::parser::Match match(true);
                                            {
                                                int pos = lexer.GetPos();
                                                soulng::parser::Match match(false);
                                                if (*lexer == LPAREN)
                                                {
                                                    ++lexer;
                                                    match.hit = true;
                                                }
                                                if (!match.hit)
                                                {
                                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                                }
                                            }
                                            if (match.hit)
                                            {
                                                leftParenSpan = span;
                                            }
                                            *parentMatch13 = match;
                                        }
                                        *parentMatch12 = match;
                                    }
                                    *parentMatch7 = match;
                                }
                                *parentMatch6 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch14 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch15 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match = StatementParser::ConditionalCompilationExpression(lexer);
                                        ifExpr.reset(static_cast<ConditionalCompilationExpressionNode*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            condCompStmt.reset(new ConditionalCompilationStatementNode(s, ifExpr.release()));
                                            condCompStmt->IfPart()->SetKeywordSpan(keywordSpan);
                                        }
                                        *parentMatch15 = match;
                                    }
                                    *parentMatch14 = match;
                                }
                                *parentMatch6 = match;
                            }
                            *parentMatch5 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch16 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch17 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    Span span = lexer.GetSpan();
                                    soulng::parser::Match match(true);
                                    {
                                        int pos = lexer.GetPos();
                                        soulng::parser::Match match(false);
                                        if (*lexer == RPAREN)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (!match.hit)
                                        {
                                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                        }
                                    }
                                    if (match.hit)
                                    {
                                        rightParenSpan = span;
                                        condCompStmt->IfPart()->SetLeftParenSpan(leftParenSpan);
                                        condCompStmt->IfPart()->SetRightParenSpan(rightParenSpan);
                                    }
                                    *parentMatch17 = match;
                                }
                                *parentMatch16 = match;
                            }
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch18 = &match;
                        {
                            soulng::parser::Match match(true);
                            soulng::parser::Match* parentMatch19 = &match;
                            {
                                while (true)
                                {
                                    int save = lexer.GetPos();
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch20 = &match;
                                        {
                                            int pos = lexer.GetPos();
                                            soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                                            ifS.reset(static_cast<StatementNode*>(match.value));
                                            if (match.hit)
                                            {
                                                condCompStmt->AddIfStatement(ifS.release());
                                            }
                                            *parentMatch20 = match;
                                        }
                                        if (match.hit)
                                        {
                                            *parentMatch19 = match;
                                        }
                                        else
                                        {
                                            lexer.SetPos(save);
                                            break;
                                        }
                                    }
                                }
                            }
                            *parentMatch18 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch21 = &match;
                    {
                        soulng::parser::Match match(true);
                        soulng::parser::Match* parentMatch22 = &match;
                        {
                            while (true)
                            {
                                int save = lexer.GetPos();
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch23 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch24 = &match;
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch25 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch26 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch27 = &match;
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch28 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            Span span = lexer.GetSpan();
                                                            soulng::parser::Match match(false);
                                                            if (*lexer == HASH)
                                                            {
                                                                ++lexer;
                                                                match.hit = true;
                                                            }
                                                            if (match.hit)
                                                            {
                                                                keywordSpan = span;
                                                            }
                                                            *parentMatch28 = match;
                                                        }
                                                        *parentMatch27 = match;
                                                    }
                                                    if (match.hit)
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch29 = &match;
                                                        {
                                                            soulng::parser::Match match(false);
                                                            soulng::parser::Match* parentMatch30 = &match;
                                                            {
                                                                int pos = lexer.GetPos();
                                                                Span span = lexer.GetSpan();
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == ELIF)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                if (match.hit)
                                                                {
                                                                    keywordSpan.end = span.end;
                                                                }
                                                                *parentMatch30 = match;
                                                            }
                                                            *parentMatch29 = match;
                                                        }
                                                        *parentMatch27 = match;
                                                    }
                                                    *parentMatch26 = match;
                                                }
                                                if (match.hit)
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch31 = &match;
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch32 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            Span span = lexer.GetSpan();
                                                            soulng::parser::Match match(true);
                                                            {
                                                                int pos = lexer.GetPos();
                                                                soulng::parser::Match match(false);
                                                                if (*lexer == LPAREN)
                                                                {
                                                                    ++lexer;
                                                                    match.hit = true;
                                                                }
                                                                if (!match.hit)
                                                                {
                                                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(LPAREN)));
                                                                }
                                                            }
                                                            if (match.hit)
                                                            {
                                                                leftParenSpan = span;
                                                            }
                                                            *parentMatch32 = match;
                                                        }
                                                        *parentMatch31 = match;
                                                    }
                                                    *parentMatch26 = match;
                                                }
                                                *parentMatch25 = match;
                                            }
                                            if (match.hit)
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch33 = &match;
                                                {
                                                    soulng::parser::Match match(false);
                                                    soulng::parser::Match* parentMatch34 = &match;
                                                    {
                                                        int pos = lexer.GetPos();
                                                        Span span = lexer.GetSpan();
                                                        soulng::parser::Match match = StatementParser::ConditionalCompilationExpression(lexer);
                                                        elifExpr.reset(static_cast<ConditionalCompilationExpressionNode*>(match.value));
                                                        if (match.hit)
                                                        {
                                                            condCompStmt->AddElifExpr(span, elifExpr.release());
                                                        }
                                                        *parentMatch34 = match;
                                                    }
                                                    *parentMatch33 = match;
                                                }
                                                *parentMatch25 = match;
                                            }
                                            *parentMatch24 = match;
                                        }
                                        if (match.hit)
                                        {
                                            soulng::parser::Match match(false);
                                            soulng::parser::Match* parentMatch35 = &match;
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch36 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    Span span = lexer.GetSpan();
                                                    soulng::parser::Match match(true);
                                                    {
                                                        int pos = lexer.GetPos();
                                                        soulng::parser::Match match(false);
                                                        if (*lexer == RPAREN)
                                                        {
                                                            ++lexer;
                                                            match.hit = true;
                                                        }
                                                        if (!match.hit)
                                                        {
                                                            lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                                        }
                                                    }
                                                    if (match.hit)
                                                    {
                                                        rightParenSpan = span;
                                                        condCompStmt->SetElifLeftParenSpan(leftParenSpan);
                                                        condCompStmt->SetElifRightParenSpan(rightParenSpan);
                                                        condCompStmt->SetElifKeywordSpan(keywordSpan);
                                                    }
                                                    *parentMatch36 = match;
                                                }
                                                *parentMatch35 = match;
                                            }
                                            *parentMatch24 = match;
                                        }
                                        *parentMatch23 = match;
                                    }
                                    if (match.hit)
                                    {
                                        soulng::parser::Match match(false);
                                        soulng::parser::Match* parentMatch37 = &match;
                                        {
                                            soulng::parser::Match match(true);
                                            soulng::parser::Match* parentMatch38 = &match;
                                            {
                                                while (true)
                                                {
                                                    int save = lexer.GetPos();
                                                    {
                                                        soulng::parser::Match match(false);
                                                        soulng::parser::Match* parentMatch39 = &match;
                                                        {
                                                            int pos = lexer.GetPos();
                                                            soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                                                            elifS.reset(static_cast<StatementNode*>(match.value));
                                                            if (match.hit)
                                                            {
                                                                condCompStmt->AddElifStatement(elifS.release());
                                                            }
                                                            *parentMatch39 = match;
                                                        }
                                                        if (match.hit)
                                                        {
                                                            *parentMatch38 = match;
                                                        }
                                                        else
                                                        {
                                                            lexer.SetPos(save);
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                            *parentMatch37 = match;
                                        }
                                        *parentMatch23 = match;
                                    }
                                    if (match.hit)
                                    {
                                        *parentMatch22 = match;
                                    }
                                    else
                                    {
                                        lexer.SetPos(save);
                                        break;
                                    }
                                }
                            }
                        }
                        *parentMatch21 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch40 = &match;
                {
                    soulng::parser::Match match(true);
                    int save = lexer.GetPos();
                    soulng::parser::Match* parentMatch41 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch42 = &match;
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch43 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch44 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch45 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match(false);
                                        if (*lexer == HASH)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        if (match.hit)
                                        {
                                            keywordSpan = span;
                                        }
                                        *parentMatch45 = match;
                                    }
                                    *parentMatch44 = match;
                                }
                                if (match.hit)
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch46 = &match;
                                    {
                                        soulng::parser::Match match(false);
                                        if (*lexer == ELSE)
                                        {
                                            ++lexer;
                                            match.hit = true;
                                        }
                                        *parentMatch46 = match;
                                    }
                                    *parentMatch44 = match;
                                }
                                *parentMatch43 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch47 = &match;
                                {
                                    soulng::parser::Match match(true);
                                    soulng::parser::Match* parentMatch48 = &match;
                                    {
                                        while (true)
                                        {
                                            int save = lexer.GetPos();
                                            {
                                                soulng::parser::Match match(false);
                                                soulng::parser::Match* parentMatch49 = &match;
                                                {
                                                    int pos = lexer.GetPos();
                                                    Span span = lexer.GetSpan();
                                                    soulng::parser::Match match = StatementParser::Statement(lexer, ctx);
                                                    elseS.reset(static_cast<StatementNode*>(match.value));
                                                    if (match.hit)
                                                    {
                                                        condCompStmt->AddElseStatement(span, elseS.release());
                                                    }
                                                    *parentMatch49 = match;
                                                }
                                                if (match.hit)
                                                {
                                                    *parentMatch48 = match;
                                                }
                                                else
                                                {
                                                    lexer.SetPos(save);
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    *parentMatch47 = match;
                                }
                                *parentMatch43 = match;
                            }
                            *parentMatch42 = match;
                        }
                        if (match.hit)
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch50 = &match;
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch51 = &match;
                                {
                                    int pos = lexer.GetPos();
                                    soulng::parser::Match match(true);
                                    if (match.hit)
                                    {
                                        condCompStmt->ElsePart()->SetKeywordSpan(keywordSpan);
                                    }
                                    *parentMatch51 = match;
                                }
                                *parentMatch50 = match;
                            }
                            *parentMatch42 = match;
                        }
                        if (match.hit)
                        {
                            *parentMatch41 = match;
                        }
                        else
                        {
                            lexer.SetPos(save);
                        }
                    }
                    *parentMatch40 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch52 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch53 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == HASH)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        keywordSpan = span;
                    }
                    *parentMatch53 = match;
                }
                *parentMatch52 = match;
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
    }
    if (match.hit)
    {
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch54 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch55 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match(true);
                {
                    int pos = lexer.GetPos();
                    soulng::parser::Match match(false);
                    if (*lexer == ENDIF)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (!match.hit)
                    {
                        lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(ENDIF)));
                    }
                }
                if (match.hit)
                {
                    keywordSpan.end = span.end;
                    condCompStmt->SetEndIfSpan(keywordSpan);
                    return soulng::parser::Match(true, condCompStmt.release());
                }
                *parentMatch55 = match;
            }
            *parentMatch54 = match;
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ConditionalCompilationExpression(CmajorLexer& lexer)
{
    std::unique_ptr<ConditionalCompilationExpressionNode> disjunction;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match = StatementParser::ConditionalCompilationDisjunction(lexer);
        disjunction.reset(static_cast<ConditionalCompilationExpressionNode*>(match.value));
        if (match.hit)
        {
            return soulng::parser::Match(true, disjunction.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ConditionalCompilationDisjunction(CmajorLexer& lexer)
{
    Span s = Span();
    std::unique_ptr<ConditionalCompilationExpressionNode> condCompExpr = std::unique_ptr<ConditionalCompilationExpressionNode>();
    std::unique_ptr<ConditionalCompilationExpressionNode> left;
    std::unique_ptr<ConditionalCompilationExpressionNode> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match = StatementParser::ConditionalCompilationConjunction(lexer);
                left.reset(static_cast<ConditionalCompilationExpressionNode*>(match.value));
                if (match.hit)
                {
                    s = span;
                    condCompExpr.reset(left.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch5 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == DISJUNCTION)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match = StatementParser::ConditionalCompilationConjunction(lexer);
                                        right.reset(static_cast<ConditionalCompilationExpressionNode*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            condCompExpr.reset(new ConditionalCompilationDisjunctionNode(s, condCompExpr.release(), right.release()));
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch4 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, condCompExpr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ConditionalCompilationConjunction(CmajorLexer& lexer)
{
    Span s = Span();
    std::unique_ptr<ConditionalCompilationExpressionNode> condCompExpr = std::unique_ptr<ConditionalCompilationExpressionNode>();
    std::unique_ptr<ConditionalCompilationExpressionNode> left;
    std::unique_ptr<ConditionalCompilationExpressionNode> right;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                int pos = lexer.GetPos();
                Span span = lexer.GetSpan();
                soulng::parser::Match match = StatementParser::ConditionalCompilationPrefix(lexer);
                left.reset(static_cast<ConditionalCompilationExpressionNode*>(match.value));
                if (match.hit)
                {
                    s = span;
                    condCompExpr.reset(left.release());
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch3 = &match;
            {
                soulng::parser::Match match(true);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    while (true)
                    {
                        int save = lexer.GetPos();
                        {
                            soulng::parser::Match match(false);
                            soulng::parser::Match* parentMatch5 = &match;
                            {
                                soulng::parser::Match match(false);
                                if (*lexer == AMPAMP)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                soulng::parser::Match match(false);
                                soulng::parser::Match* parentMatch6 = &match;
                                {
                                    soulng::parser::Match match(false);
                                    soulng::parser::Match* parentMatch7 = &match;
                                    {
                                        int pos = lexer.GetPos();
                                        Span span = lexer.GetSpan();
                                        soulng::parser::Match match = StatementParser::ConditionalCompilationPrefix(lexer);
                                        right.reset(static_cast<ConditionalCompilationExpressionNode*>(match.value));
                                        if (match.hit)
                                        {
                                            s.end = span.end;
                                            condCompExpr.reset(new ConditionalCompilationConjunctionNode(s, condCompExpr.release(), right.release()));
                                        }
                                        *parentMatch7 = match;
                                    }
                                    *parentMatch6 = match;
                                }
                                *parentMatch5 = match;
                            }
                            if (match.hit)
                            {
                                *parentMatch4 = match;
                            }
                            else
                            {
                                lexer.SetPos(save);
                                break;
                            }
                        }
                    }
                }
                *parentMatch3 = match;
            }
            *parentMatch1 = match;
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, condCompExpr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ConditionalCompilationPrefix(CmajorLexer& lexer)
{
    Span s = Span();
    std::unique_ptr<ConditionalCompilationExpressionNode> condCompExpr = std::unique_ptr<ConditionalCompilationExpressionNode>();
    std::unique_ptr<ConditionalCompilationExpressionNode> prefix;
    std::unique_ptr<ConditionalCompilationExpressionNode> primary;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int pos = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int save = lexer.GetPos();
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    int pos = lexer.GetPos();
                    Span span = lexer.GetSpan();
                    soulng::parser::Match match(false);
                    if (*lexer == NOT)
                    {
                        ++lexer;
                        match.hit = true;
                    }
                    if (match.hit)
                    {
                        s = span;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            if (match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch4 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch5 = &match;
                    {
                        int pos = lexer.GetPos();
                        Span span = lexer.GetSpan();
                        soulng::parser::Match match = StatementParser::ConditionalCompilationPrefix(lexer);
                        prefix.reset(static_cast<ConditionalCompilationExpressionNode*>(match.value));
                        if (match.hit)
                        {
                            s.end = span.end;
                            condCompExpr.reset(new ConditionalCompilationNotNode(s, prefix.release()));
                        }
                        *parentMatch5 = match;
                    }
                    *parentMatch4 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch1 = match;
            if (!match.hit)
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch6 = &match;
                lexer.SetPos(save);
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch7 = &match;
                    {
                        int pos = lexer.GetPos();
                        soulng::parser::Match match(true);
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match = StatementParser::ConditionalCompilationPrimary(lexer);
                            primary.reset(static_cast<ConditionalCompilationExpressionNode*>(match.value));
                            if (!match.hit)
                            {
                                lexer.ThrowExpectationFailure(pos, U"conditional compilation primary expression");
                            }
                        }
                        if (match.hit)
                        {
                            condCompExpr.reset(primary.release());
                        }
                        *parentMatch7 = match;
                    }
                    *parentMatch6 = match;
                }
                *parentMatch1 = match;
            }
        }
        if (match.hit)
        {
            return soulng::parser::Match(true, condCompExpr.release());
        }
        *parentMatch0 = match;
    }
    return match;
}

soulng::parser::Match StatementParser::ConditionalCompilationPrimary(CmajorLexer& lexer)
{
    std::u32string symbol = std::u32string();
    std::unique_ptr<ConditionalCompilationExpressionNode> expr;
    soulng::parser::Match match(false);
    soulng::parser::Match* parentMatch0 = &match;
    {
        int save = lexer.GetPos();
        soulng::parser::Match match(false);
        soulng::parser::Match* parentMatch1 = &match;
        {
            int pos = lexer.GetPos();
            Span span = lexer.GetSpan();
            soulng::parser::Match match(false);
            if (*lexer == ID)
            {
                ++lexer;
                match.hit = true;
            }
            if (match.hit)
            {
                symbol = lexer.GetMatch(span);
                return soulng::parser::Match(true, new ConditionalCompilationPrimaryNode(span, symbol));
            }
            *parentMatch1 = match;
        }
        *parentMatch0 = match;
        if (!match.hit)
        {
            soulng::parser::Match match(false);
            soulng::parser::Match* parentMatch2 = &match;
            lexer.SetPos(save);
            {
                soulng::parser::Match match(false);
                soulng::parser::Match* parentMatch3 = &match;
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch4 = &match;
                    {
                        soulng::parser::Match match(false);
                        if (*lexer == LPAREN)
                        {
                            ++lexer;
                            match.hit = true;
                        }
                        *parentMatch4 = match;
                    }
                    if (match.hit)
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch5 = &match;
                        {
                            soulng::parser::Match match = StatementParser::ConditionalCompilationExpression(lexer);
                            expr.reset(static_cast<ConditionalCompilationExpressionNode*>(match.value));
                            *parentMatch5 = match;
                        }
                        *parentMatch4 = match;
                    }
                    *parentMatch3 = match;
                }
                if (match.hit)
                {
                    soulng::parser::Match match(false);
                    soulng::parser::Match* parentMatch6 = &match;
                    {
                        soulng::parser::Match match(false);
                        soulng::parser::Match* parentMatch7 = &match;
                        {
                            int pos = lexer.GetPos();
                            soulng::parser::Match match(true);
                            {
                                int pos = lexer.GetPos();
                                soulng::parser::Match match(false);
                                if (*lexer == RPAREN)
                                {
                                    ++lexer;
                                    match.hit = true;
                                }
                                if (!match.hit)
                                {
                                    lexer.ThrowExpectationFailure(pos, ToUtf32(GetTokenInfo(RPAREN)));
                                }
                            }
                            if (match.hit)
                            {
                                return soulng::parser::Match(true, expr.release());
                            }
                            *parentMatch7 = match;
                        }
                        *parentMatch6 = match;
                    }
                    *parentMatch3 = match;
                }
                *parentMatch2 = match;
            }
            *parentMatch0 = match;
        }
    }
    return match;
}
