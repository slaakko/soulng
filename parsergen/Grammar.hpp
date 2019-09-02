#ifndef Grammar_hpp_26071
#define Grammar_hpp_26071

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/parsing/Grammar.hpp>

namespace soulng { namespace syntax {

class GrammarGrammar : public soulng::parsing::Grammar
{
public:
    static GrammarGrammar* Create();
    static GrammarGrammar* Create(soulng::parsing::ParsingDomain* parsingDomain);
    soulng::parsing::Grammar* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::Scope* enclosingScope);
private:
    GrammarGrammar(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class GrammarRule;
    class GrammarContentRule;
    class StartClauseRule;
    class SkipClauseRule;
};

} } // namespace soulng.syntax

#endif // Grammar_hpp_26071
