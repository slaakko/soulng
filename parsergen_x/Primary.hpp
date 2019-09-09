#ifndef Primary_hpp_26071
#define Primary_hpp_26071

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/parsing/Parser.hpp>
#include <soulng/parsing/Scope.hpp>

namespace soulng { namespace syntax {

class Primary : public soulng::parsing::Grammar
{
public:
    static Primary* Create();
    static Primary* Create(soulng::parsing::ParsingDomain* parsingDomain);
    soulng::parsing::Parser* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::Scope* enclosingScope);
private:
    Primary(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class PrimaryRule;
    class RuleCallRule;
    class NonterminalRule;
    class AliasRule;
    class GroupingRule;
    class TokenRule;
    class ExpectationRule;
    class ActionRule;
};

} } // namespace soulng.syntax

#endif // Primary_hpp_26071
