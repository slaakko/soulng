// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SLG_MODEL_INCLUDED
#define SOULNG_SLG_MODEL_INCLUDED
#include <soulng/slg/Nfa.hpp>
#include <soulng/slg/Dfa.hpp>
#include <memory>
#include <string>
#include <map>
#include <soulng/cppcode/Statement.hpp>
#include <soulng/cppcode/Type.hpp>
#include <soulng/util/CodeFormatter.hpp>

namespace soulng { namespace slg {

const char* LexerGeneratorVersionStr();

using namespace soulng::util;

class LexerContext;

class Parser
{
public:
    virtual ~Parser();
    virtual Nfa Parse(const std::u32string& expression, LexerContext* lexerContext, int line) = 0;
};

class Tokens;

class Declaration
{
public:
    Declaration(const std::u32string& name_);
    virtual ~Declaration();
    virtual void FillContext(LexerContext& lexerContext) = 0;
    virtual void Process(const std::string& root, bool verbose, LexerContext& lexerContext) = 0;
    const std::u32string& Name() const { return name; }
private:
    std::u32string name;
};

class ClassMap : public Declaration
{
public:
    ClassMap(const std::u32string& name_);
    void FillContext(LexerContext& lexerContext);
    void Process(const std::string& root, bool verbose, LexerContext& lexerContext);
};

class Prefix : public Declaration
{
public:
    Prefix(const std::u32string& prefix_);
    void FillContext(LexerContext& lexerContext);
    void Process(const std::string& root, bool verbose, LexerContext& lexerContext);
};

class Include : public Declaration
{
public:
    Include(const std::u32string& header_);
    void FillContext(LexerContext& lexerContext);
    void Process(const std::string& root, bool verbose, LexerContext& lexerContext);
    const std::u32string& Header() const { return header; }
private:
    std::u32string header;
};

struct Token
{
    Token();
    Token(const std::u32string& name_, const std::string& info_);
    std::u32string name;
    std::string info;
};

class Tokens : public Declaration
{
public:
    Tokens(const std::u32string& name_);
    void Add(const Token& token);
    void FillContext(LexerContext& lexerContext) override;
    void Process(const std::string& root, bool verbose, LexerContext& lexerContext) override;
private:
    std::vector<Token> tokens;
};

class Keyword
{
public:
    Keyword(const std::u32string& kw_, const std::u32string& token_);
    std::u32string kw;
    std::u32string token;
};

class Keywords : public Declaration
{
public:
    Keywords(const std::u32string& name_);
    void Add(Keyword* keyword);
    void FillContext(LexerContext& lexerContext) override;
    void Process(const std::string& root, bool verbose, LexerContext& lexerContext) override;
private:
    std::vector<std::unique_ptr<Keyword>> keywords;
};

class Expression
{
public:
    Expression(int index_, const std::u32string& id_, const std::u32string& value_, int line_);
    int Index() const { return index; }
    const std::u32string& Id() const { return id; }
    const std::u32string& Value() const { return value; }
    int Line() const { return line; }
private:
    int index;
    std::u32string id;
    std::u32string value;
    int line;
};

class Expressions : public Declaration
{
public:
    Expressions();
    void Add(Expression* expression);
    Expression* Get(const std::u32string& id) const;
    void FillContext(LexerContext& lexerContext) override;
    void Process(const std::string& root, bool verbose, LexerContext& lexerContext) override;
private:
    std::vector<std::unique_ptr<Expression>> expressions;
    std::map<std::u32string, int> exprMap;
};

class Variable
{
public:
    Variable(soulng::cppcode::TypeId* type_, const std::u32string& name_);
    soulng::cppcode::TypeId* GetType() const { return type.get(); }
    const std::u32string& Name() const { return name; }
private:
    std::unique_ptr<soulng::cppcode::TypeId> type;
    std::u32string name;
};

class LexerStatement
{
public:
    LexerStatement(const std::u32string& expr_, soulng::cppcode::CompoundStatement* stmt_, int action_, int line_);
    void Process(LexerContext& lexerContext);
    void SetIndex(int index_) { index = index_; }
    int Index() const { return index; }
    const Nfa& GetNfa() const { return nfa; }
    soulng::cppcode::CompoundStatement* Code() const { return stmt.get(); }
    bool Retract() const { return retract; }
    int Action() const { return action; }
    int Line() const { return line; }
private:
    int index;
    std::u32string expr;
    Nfa nfa;
    std::unique_ptr<soulng::cppcode::CompoundStatement> stmt;
    bool retract;
    int action;
    int line;
};

class Action
{
public:
    Action(int id_, soulng::cppcode::CompoundStatement* stmt_);
    int Id() const { return id; }
    soulng::cppcode::CompoundStatement* Code() const { return stmt.get(); }
private:
    int id;
    std::unique_ptr<soulng::cppcode::CompoundStatement> stmt;
};

class Actions : public Declaration
{
public:
    Actions();
    void FillContext(LexerContext& lexerContext);
    void Process(const std::string& root, bool verbose, LexerContext& lexerContext);
    void Add(Action* action);
    Action* Get(int id) const;
private:
    std::vector<std::unique_ptr<Action>> actions;
    std::map<int, Action*> actionMap;
};

class Lexer : public Declaration
{
public:
    Lexer(const std::u32string& api_, const std::u32string& name_);
    void AddStatement(LexerStatement* stmt);
    void AddVariable(Variable* variable);
    void AddAction(Action* action);
    void FillContext(LexerContext& lexerContext) override;
    void Process(const std::string& root, bool verbose, LexerContext& lexerContext) override;
    void MakeMasterNfa(LexerContext& lexerContext);
    void MakeDfa(LexerContext& lexerContext);
    void WriteAutomaton(const std::string& root, bool verbose, LexerContext& lexerContext);
private:
    std::u32string api;
    std::vector<std::unique_ptr<LexerStatement>> statements;
    std::vector<std::unique_ptr<Variable>> variables;
    Actions actions;
    Nfa masterNfa;
    Dfa dfa;
};

class LexerFile
{
public:
    void Add(Declaration* declaration);
    void Process(const std::string& root, bool verbose, bool debug, LexerContext& lexerContext);
private:
    std::vector<std::unique_ptr<Declaration>> declarations;
    std::map<std::u32string, Declaration*> declarationMap;
};

} } // namespace soulng::slg

#endif // SOULNG_SLG_MODEL_INCLUDED
