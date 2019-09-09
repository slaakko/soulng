#ifndef Rule_hpp_26071
#define Rule_hpp_26071

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/parsing/Rule.hpp>

namespace soulng { namespace syntax {

class Rule : public soulng::parsing::Grammar
{
public:
    static Rule* Create();
    static Rule* Create(soulng::parsing::ParsingDomain* parsingDomain);
    soulng::parsing::Rule* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::Scope* enclosingScope);
private:
    Rule(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class RuleRule;
    class RuleHeaderRule;
    class RuleBodyRule;
};

} } // namespace soulng.syntax

#endif // Rule_hpp_26071
