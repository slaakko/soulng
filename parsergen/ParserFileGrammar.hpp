#ifndef ParserFileGrammar_hpp_5757
#define ParserFileGrammar_hpp_5757

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/parsergen/ParserFile.hpp>

namespace soulng { namespace parsergen {

class ParserFileGrammar : public soulng::parsing::Grammar
{
public:
    static ParserFileGrammar* Create();
    static ParserFileGrammar* Create(soulng::parsing::ParsingDomain* parsingDomain);
    ParserFile* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName);
private:
    std::vector<std::u32string> keywords0;
    ParserFileGrammar(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class ParserFileRule;
    class DeclarationRule;
    class IncludeDeclarationRule;
    class IncludePrefixRule;
    class UsingNamespaceDeclarationRule;
    class GrammarDeclarationRule;
    class GrammarStatementRule;
    class MainStatementRule;
    class UsingStatementRule;
    class LexerStatementRule;
    class RuleInfoStatementRule;
    class RuleInfoRule;
    class RuleStatementRule;
    class RuleBodyRule;
    class AlternativeRule;
    class SequenceRule;
    class DifferenceRule;
    class ListRule;
    class PostfixRule;
    class PrimaryRule;
    class RuleCallRule;
    class PrimitiveRule;
    class GroupingRule;
    class ExpectationRule;
    class ActionRule;
    class NonterminalRule;
    class ParameterListRule;
    class ParameterRule;
    class ReturnTypeRule;
    class IdentifierRule;
    class UsingQualifiedIdRule;
};

} } // namespace soulng.parsergen

#endif // ParserFileGrammar_hpp_5757
