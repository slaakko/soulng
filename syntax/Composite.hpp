#ifndef Composite_hpp_5581
#define Composite_hpp_5581

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/parsing/Scope.hpp>
#include <soulng/parsing/Parser.hpp>

namespace soulng { namespace syntax {

class Composite : public soulng::parsing::Grammar
{
public:
    static Composite* Create();
    static Composite* Create(soulng::parsing::ParsingDomain* parsingDomain);
    soulng::parsing::Parser* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::Scope* enclosingScope);
private:
    Composite(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class AlternativeRule;
    class SequenceRule;
    class DifferenceRule;
    class ExclusiveOrRule;
    class IntersectionRule;
    class ListRule;
    class PostfixRule;
};

} } // namespace soulng.syntax

#endif // Composite_hpp_5581
