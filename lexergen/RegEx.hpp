#ifndef RegEx_hpp_18958
#define RegEx_hpp_18958

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/lexergen/Model.hpp>
#include <soulng/lexergen/LexerContext.hpp>

namespace soulng { namespace lexergen {

class RegExGrammar : public soulng::parsing::Grammar
{
public:
    static RegExGrammar* Create();
    static RegExGrammar* Create(soulng::parsing::ParsingDomain* parsingDomain);
    Nfa Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, LexerContext* lexerContext);
private:
    RegExGrammar(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class RegExRule;
    class AlternativeRule;
    class CatenationRule;
    class RepetitionRule;
    class PrimaryRule;
    class ClassRule;
    class RangeRule;
    class CharRule;
    class EscapeRule;
};

} } // namespace soulng.lexergen

#endif // RegEx_hpp_18958
