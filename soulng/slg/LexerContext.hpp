// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SLG_LEXER_CONTEXT_INCLUDED
#define SOULNG_SLG_LEXER_CONTEXT_INCLUDED
#include <soulng/slg/Nfa.hpp>
#include <soulng/slg/Dfa.hpp>
#include <vector>
#include <map>

namespace soulng { namespace slg {

class ClassMap;
class Prefix;
class Include;
class Tokens;
class Keywords;
class Expressions;
class Lexer;
class Expression;
class Variable;
class Parser;

enum class IdentifierClassKind
{
    none, unicode, ascii
};

class LexerContext
{
public:
    LexerContext(IdentifierClassKind identifierClassKind);
    ~LexerContext();
    NfaState* MakeNfaState();
    const std::vector<NfaState*>& NfaStates() const { return nfaStates; }
    DfaState* MakeDfaState(const std::vector<NfaState*>& nfaStates);
    Symbol* MakeChar(char32_t c);
    Symbol* MakeAny() { return &any; }
    Symbol* MakeEpsilon() { return &epsilon; }
    Symbol* MakeRange(char32_t start, char32_t end);
    Class* MakeIdStart() { return idStart; }
    Class* MakeIdCont() { return idCont; }
    Class* MakeClass();
    const std::vector<Symbol*>& Symbols() const { return symbols; }
    void SetFileName(const std::string& fileName_);
    const std::string& FileName() const { return fileName; }
    void SetClassMap(ClassMap* classMap_);
    ClassMap* GetClassMap() const { return classMap; }
    void SetPrefix(Prefix* prefix_);
    Prefix* GetPrefix() const { return prefix; }
    void SetTokens(Tokens* tokens_);
    Tokens* GetTokens() const { return tokens; }
    void SetKeywords(Keywords* keywords_);
    Keywords* GetKeywords() const { return keywords; }
    void SetExpressions(Expressions* expressions_);
    void SetLexer(Lexer* lexer_) { lexer = lexer_; }
    Lexer* GetLexer() const { return lexer; }
    void SetParser(Parser* parser_) { parser = parser_; }
    Parser* GetParser() const { return parser; }
    Nfa MakeExpr(const std::u32string& id);
    void SetCurrentExpression(Expression* currentExpression_) { currentExpression = currentExpression_; }
    void MakeCanonicalClasses();
    void MakeClassPartition(bool debug);
    void MakeClassMap(const std::string& root, bool verbose);
    const std::vector<Class*>& Partition() const { return partition; }
    const std::vector<Include*>& Includes() const { return includes; }
    void AddInclude(Include* include);
    void SetApi(const std::u32string& api_) { api = api_; }
    const std::u32string& Api() const { return api; }
    void Print(CodeFormatter& formatter);
private:
    std::vector<Include*> includes;
    int nextNfaStateId;
    int nextDfaStateId;
    int lexerStatementIndex;
    int classIndex;
    std::string fileName;
    std::vector<NfaState*> nfaStates;
    std::vector<DfaState*> dfaStates;
    std::vector<Symbol*> symbols;
    std::vector<Class*> canonicalClasses;
    std::vector<Class*> partition;
    std::map<char32_t, Symbol*> charSymbols;
    std::map<Range, Symbol*> rangeSymbols;
    Any any;
    Char epsilon;
    Class* idStart;
    Class* idCont;
    ClassMap* classMap;
    Prefix* prefix;
    Tokens* tokens;
    Keywords* keywords;
    Expressions* expressions;
    Lexer* lexer;
    Parser* parser;
    Expression* currentExpression;
    std::u32string api;
};

} } // namespace soulng::slg

#endif // SOULNG_SLG_LEXER_CONTEXT_INCLUDED
