// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_LEXER_FILEINCLUDED
#define SNG2HTML_SNG2HTML_LEXER_FILEINCLUDED
#include <sng2html/sng2html/RegEx.hpp>
#include <sng2html/sng2html/LexerContext.hpp>
#include <soulng/cppcode/Statement.hpp>
#include <soulng/cppcode/Type.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <memory>
#include <string>
#include <map>
#include <unordered_map>

namespace sng2html { namespace sng2html {

const char* LexerGeneratorVersionStr();

using namespace soulng::util;

class Tokens;

class LexerFile;

class Declaration
{
public:
    Declaration(const std::u32string& name_);
    virtual ~Declaration();
    const std::u32string& Name() const { return name; }
    virtual void AddToLexerFile(LexerFile& lexerFile) {}
private:
    std::u32string name;
};

class ClassMap : public Declaration
{
public:
    ClassMap(const std::u32string& name_);
};

class Prefix : public Declaration
{
public:
    Prefix(const std::u32string& prefix_);
};

class IncludeDeclaration : public Declaration
{
public:
    IncludeDeclaration(const std::u32string& header_);
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
    void AddToLexerFile(LexerFile& lexerFile) override;
    std::u32string GetKeyword(const std::u32string& tokenId) const;
private:
    std::vector<std::unique_ptr<Keyword>> keywords;
    std::map<std::u32string, std::u32string> keywordMap;
};

class Expression
{
public:
    Expression(int index_, const std::u32string& id_, const std::u32string& value_, int line_);
    int Index() const { return index; }
    const std::u32string& Id() const { return id; }
    const std::u32string& Value() const { return value; }
    int Line() const { return line; }
    void Parse(LexerContext& lexerContext);
    void SetRegEx(RegExpression* regEx_) { regEx.reset(regEx_); }
    RegExpression* RegEx() const { return regEx.get(); }
private:
    int index;
    std::u32string id;
    std::u32string value;
    int line;
    std::unique_ptr<RegExpression> regEx;
};

class Expressions : public Declaration
{
public:
    Expressions();
    void Add(Expression* expression);
    Expression* Get(const std::u32string& id) const;
    void AddToLexerFile(LexerFile& lexerFile) override;
    void Parse(LexerContext& lexerContext);
private:
    std::vector<std::unique_ptr<Expression>> expressions;
    std::map<std::u32string, int> exprMap;
};

class LexerVariable
{
public:
    LexerVariable(soulng::cppcode::TypeId* type_, const std::u32string& name_);
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
    void SetIndex(int index_) { index = index_; }
    int Index() const { return index; }
    const std::u32string& Expr() const { return expr; }
    soulng::cppcode::CompoundStatement* Code() const { return stmt.get(); }
    bool Retract() const { return retract; }
    int Action() const { return action; }
    int Line() const { return line; }
    const std::u32string& TokenId() const { return tokenId; }
    void Parse(LexerContext& lexerContext);
    RegExpression* RegEx() const { return regEx.get(); }
private:
    int index;
    std::u32string expr;
    std::u32string tokenId;
    std::unique_ptr<soulng::cppcode::CompoundStatement> stmt;
    std::unique_ptr<RegExpression> regEx;
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
    LexerStatement* GetStatement(const std::u32string& tokenId) const;
    void AddVariable(LexerVariable* variable);
    void AddAction(Action* action);
    void AddToLexerFile(LexerFile& lexerFile) override;
    void Parse(LexerContext& lexerContext);
private:
    std::u32string api;
    std::vector<std::unique_ptr<LexerStatement>> statements;
    std::vector<std::unique_ptr<LexerVariable>> variables;
    Actions actions;
    std::unordered_map<std::u32string, LexerStatement*> lexerStatementMap;
};

class LexerFile
{
public:
    LexerFile();
    void Accept(Visitor& visitor);
    void Add(Declaration* declaration);
    Keywords* GetKeywords() const { return keywords; }
    void SetKeywords(Keywords* keywords_) { keywords = keywords_; }
    Expressions* GetExpressions() const { return expressions; }
    void SetExpressions(Expressions* expressions_) { expressions = expressions_; }
    Lexer* GetLexer() const { return lexer; }
    void SetLexer(Lexer* lexer_) { lexer = lexer_; }
    void Parse(LexerContext& lexerContext);
private:
    std::vector<std::unique_ptr<Declaration>> declarations;
    Keywords* keywords;
    Lexer* lexer;
    Expressions* expressions;
};

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_LEXER_FILEINCLUDED
