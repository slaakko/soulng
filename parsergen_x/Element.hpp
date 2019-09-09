#ifndef Element_hpp_26071
#define Element_hpp_26071

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/parsing/Scope.hpp>
#include <soulng/parsing/Grammar.hpp>

namespace soulng { namespace syntax {

class Element : public soulng::parsing::Grammar
{
public:
    static Element* Create();
    static Element* Create(soulng::parsing::ParsingDomain* parsingDomain);
    void Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::Grammar* grammar);
private:
    std::vector<std::u32string> keywords0;
    Element(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class RuleLinkRule;
    class SignatureRule;
    class ParameterListRule;
    class VariableRule;
    class ParameterRule;
    class ReturnTypeRule;
    class IdentifierRule;
    class QualifiedIdRule;
    class StringArrayRule;
};

} } // namespace soulng.syntax

#endif // Element_hpp_26071
