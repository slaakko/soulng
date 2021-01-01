// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/LexerFile.hpp>
#include <sng2html/sng2html/RegExLexer.hpp>
#include <sng2html/sng2html/RegExParser.hpp>
#include <soulng/cppcode/Expression.hpp>
#include <soulng/cppcode/Visitor.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <fstream>
#include <iostream>

namespace sng2html { namespace sng2html {

const char* LexerGeneratorVersionStr()
{
    return "3.0.0";
}

using namespace soulng::util;
using namespace soulng::unicode;

Declaration::Declaration(const std::u32string& name_) : name(name_)
{
}

Declaration::~Declaration()
{
}

ClassMap::ClassMap(const std::u32string& name_) : Declaration(name_)
{
}

Prefix::Prefix(const std::u32string& prefix_) : Declaration(prefix_)
{
}

IncludeDeclaration::IncludeDeclaration(const std::u32string& header_) : Declaration(U"include"), header(header_)
{
}

Token::Token() : name(), info()
{
}

Token::Token(const std::u32string& name_, const std::string& info_) : name(name_), info(info_)
{
}

Tokens::Tokens(const std::u32string& name_) : Declaration(name_)
{
}

void Tokens::Add(const Token& token)
{
    tokens.push_back(token);
}

Keyword::Keyword(const std::u32string& kw_, const std::u32string& token_) : kw(kw_), token(token_)
{
}

Keywords::Keywords(const std::u32string& name_) : Declaration(name_)
{
}

void Keywords::Add(Keyword* keyword)
{
    keywords.push_back(std::unique_ptr<Keyword>(keyword));
    keywordMap[keyword->token] = keyword->kw;
}

std::u32string Keywords::GetKeyword(const std::u32string& tokenId) const
{
    auto it = keywordMap.find(tokenId);
    if (it != keywordMap.cend())
    {
        return it->second;
    }
    else
    {
        return std::u32string();
    }
}

void Keywords::AddToLexerFile(LexerFile& lexerFile)
{
    lexerFile.SetKeywords(this);
}

Expression::Expression(int index_, const std::u32string& id_, const std::u32string& value_, int line_) : index(index_), id(id_), value(value_), line(line_)
{
}

void Expression::Parse(LexerContext& lexerContext)
{
    RegExLexer lexer(value, "", 0);
    regEx = RegExParser::Parse(lexer, &lexerContext);
}

Expressions::Expressions() : Declaration(U"expressions")
{
}

void Expressions::AddToLexerFile(LexerFile& lexerFile)
{
    lexerFile.SetExpressions(this);
}

void Expressions::Add(Expression* expression) 
{
    expressions.push_back(std::unique_ptr<Expression>(expression));
    exprMap[expression->Id()] = expression->Index();
}

Expression* Expressions::Get(const std::u32string& id) const
{
    auto it = exprMap.find(id);
    if (it != exprMap.cend())
    {
        int index = it->second;
        return expressions[index].get();
    }
    else
    {
        throw std::runtime_error("expression '" + ToUtf8(id) + "' not found");
    }
}

void Expressions::Parse(LexerContext& lexerContext)
{
    for (auto& expr : expressions)
    {
        expr->Parse(lexerContext);
    }
    Expression* idStart = new Expression(expressions.size(), U"idstart", std::u32string(), 0);
    idStart->SetRegEx(new SymbolExpr(lexerContext.MakeIdStart()));
    Add(idStart);
    Expression* idCont = new Expression(expressions.size(), U"idcont", std::u32string(), 0);
    idCont->SetRegEx(new SymbolExpr(lexerContext.MakeIdCont()));
    Add(idCont);
}

LexerVariable::LexerVariable(soulng::cppcode::TypeId* type_, const std::u32string& name_) : type(type_), name(name_)
{
}

class TokenIdResolverVisitor : public soulng::cppcode::Visitor
{
public:
    void Visit(soulng::cppcode::ReturnStatement& object) override;
    const std::u32string& TokenId() const { return tokenId; }
private:
    std::u32string tokenId;
};

void TokenIdResolverVisitor::Visit(soulng::cppcode::ReturnStatement& object)
{
    if (tokenId.empty())
    {
        if (object.GetExpression())
        {
            tokenId = object.GetExpression()->Name();
        }
    }
}

LexerStatement::LexerStatement(const std::u32string& expr_, soulng::cppcode::CompoundStatement* stmt_, int action_, int line_) :
    index(-1), expr(expr_), stmt(stmt_), retract(true), action(action_), line(line_)
{
    TokenIdResolverVisitor visitor;
    stmt->Accept(visitor);
    tokenId = visitor.TokenId();
}

void LexerStatement::Parse(LexerContext& lexerContext)
{
    RegExLexer lexer(expr, "", 0);
    regEx = RegExParser::Parse(lexer, &lexerContext);
}

Lexer::Lexer(const std::u32string& api_, const std::u32string& name_) : Declaration(name_), api(api_)
{
}

void Lexer::AddStatement(LexerStatement* stmt)
{
    stmt->SetIndex(statements.size());
    statements.push_back(std::unique_ptr<LexerStatement>(stmt));
    lexerStatementMap[stmt->TokenId()] = stmt;
}

LexerStatement* Lexer::GetStatement(const std::u32string& tokenId) const
{
    auto it = lexerStatementMap.find(tokenId);
    if (it != lexerStatementMap.cend())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

void Lexer::AddVariable(LexerVariable* variable)
{
    variables.push_back(std::unique_ptr<LexerVariable>(variable));
}

void Lexer::AddAction(Action* action)
{
    actions.Add(action);
}

void Lexer::AddToLexerFile(LexerFile& lexerFile)
{
    lexerFile.SetLexer(this);
}

void Lexer::Parse(LexerContext& lexerContext)
{
    for (auto& statement : statements)
    {
        statement->Parse(lexerContext);
    }
}

Action::Action(int id_, soulng::cppcode::CompoundStatement* stmt_) : id(id_), stmt(stmt_)
{
}

Actions::Actions() : Declaration(U"actions")
{
}

void Actions::Add(Action* action)
{
    actions.push_back(std::unique_ptr<Action>(action));
    actionMap[action->Id()] = action;
}

Action* Actions::Get(int id) const
{
    auto it = actionMap.find(id);
    if (it != actionMap.cend())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

LexerFile::LexerFile() : keywords(nullptr), lexer(nullptr), expressions(nullptr)
{
}

void LexerFile::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void LexerFile::Add(Declaration* declaration)
{
    declarations.push_back(std::unique_ptr<Declaration>(declaration));
    declaration->AddToLexerFile(*this);
}

void LexerFile::Parse(LexerContext& lexerContext)
{
    expressions->Parse(lexerContext);
    lexer->Parse(lexerContext);
}

} } // namespace sng2html::sng2html

