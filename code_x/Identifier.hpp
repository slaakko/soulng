#ifndef Identifier_hpp_5555
#define Identifier_hpp_5555

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>

namespace soulng { namespace code {

class Identifier : public soulng::parsing::Grammar
{
public:
    static Identifier* Create();
    static Identifier* Create(soulng::parsing::ParsingDomain* parsingDomain);
    std::u32string Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName);
private:
    Identifier(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class IdentifierRule;
    class QualifiedIdRule;
};

} } // namespace soulng.code

#endif // Identifier_hpp_5555
