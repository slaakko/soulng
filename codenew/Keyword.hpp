#ifndef Keyword_hpp_12866
#define Keyword_hpp_12866

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>

namespace soulng { namespace code {

class Keyword : public soulng::parsing::Grammar
{
public:
    static Keyword* Create();
    static Keyword* Create(soulng::parsing::ParsingDomain* parsingDomain);
private:
    std::vector<std::u32string> keywords0;
    Keyword(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
};

} } // namespace soulng.code

#endif // Keyword_hpp_12866
