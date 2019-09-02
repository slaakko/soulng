#ifndef Declarator_hpp_12866
#define Declarator_hpp_12866

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/cppcode/Declaration.hpp>

namespace soulng { namespace code {

class Declarator : public soulng::parsing::Grammar
{
public:
    static Declarator* Create();
    static Declarator* Create(soulng::parsing::ParsingDomain* parsingDomain);
    soulng::cppcode::InitDeclaratorList* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName);
private:
    Declarator(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class InitDeclaratorListRule;
    class InitDeclaratorRule;
    class DeclaratorRule;
    class DirectDeclaratorRule;
    class DeclaratorIdRule;
    class TypeIdRule;
    class TypeRule;
    class TypeSpecifierSeqRule;
    class AbstractDeclaratorRule;
    class DirectAbstractDeclaratorRule;
    class CVQualifierSeqRule;
    class InitializerRule;
    class InitializerClauseRule;
    class InitializerListRule;
};

} } // namespace soulng.code

#endif // Declarator_hpp_12866
