#ifndef LibraryFile_hpp_5581
#define LibraryFile_hpp_5581

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/parsing/ParsingDomain.hpp>

namespace soulng { namespace syntax {

class LibraryFile : public soulng::parsing::Grammar
{
public:
    static LibraryFile* Create();
    static LibraryFile* Create(soulng::parsing::ParsingDomain* parsingDomain);
    void Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, soulng::parsing::ParsingDomain* parsingDomain);
private:
    LibraryFile(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class LibraryFileRule;
    class NamespaceContentRule;
    class NamespaceRule;
    class GrammarRule;
    class GrammarContentRule;
    class RuleRule;
};

} } // namespace soulng.syntax

#endif // LibraryFile_hpp_5581
