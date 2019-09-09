#ifndef Literal_hpp_5555
#define Literal_hpp_5555

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/codedom/Literal.hpp>

namespace soulng { namespace code {

class Literal : public soulng::parsing::Grammar
{
public:
    static Literal* Create();
    static Literal* Create(soulng::parsing::ParsingDomain* parsingDomain);
    soulng::codedom::Literal* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName);
private:
    Literal(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class LiteralRule;
    class IntegerLiteralRule;
    class CharacterLiteralRule;
    class CCharSequenceRule;
    class FloatingLiteralRule;
    class StringLiteralRule;
    class BooleanLiteralRule;
    class PointerLiteralRule;
};

} } // namespace soulng.code

#endif // Literal_hpp_5555
