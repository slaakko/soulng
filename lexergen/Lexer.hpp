#ifndef Lexer_hpp_5039
#define Lexer_hpp_5039

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/lexergen/Model.hpp>

namespace soulng { namespace lexergen {

class LexerGrammar : public soulng::parsing::Grammar
{
public:
    static LexerGrammar* Create();
    static LexerGrammar* Create(soulng::parsing::ParsingDomain* parsingDomain);
    LexerFile* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName);
private:
    std::vector<std::u32string> keywords0;
    LexerGrammar(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class LexerFileRule;
    class DeclarationRule;
    class ClassMapRule;
    class PrefixRule;
    class IncludeRule;
    class TokensRule;
    class TokenRule;
    class KeywordsRule;
    class KeywordRule;
    class ExpressionsRule;
    class ExpressionRule;
    class ExprRule;
    class VariableRule;
    class LexerRule;
    class LexerClauseRule;
    class VariablesRule;
    class IdentifierRule;
    class ApiRule;
    class ActionsRule;
    class ActionRule;
};

} } // namespace soulng.lexergen

#endif // Lexer_hpp_5039
