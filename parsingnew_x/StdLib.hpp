#ifndef StdLib_hpp_5649
#define StdLib_hpp_5649

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <stdint.h>

namespace soulng { namespace parsing {

class PARSING_API stdlib : public soulng::parsing::Grammar
{
public:
    static stdlib* Create();
    static stdlib* Create(soulng::parsing::ParsingDomain* parsingDomain);
private:
    stdlib(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class intRule;
    class uintRule;
    class longRule;
    class ulongRule;
    class hexuintRule;
    class hexRule;
    class hex_literalRule;
    class realRule;
    class urealRule;
    class numRule;
    class boolRule;
    class identifierRule;
    class qualified_idRule;
    class escapeRule;
    class charRule;
    class stringRule;
};

} } // namespace soulng.parsing

#endif // StdLib_hpp_5649
