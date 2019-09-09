#ifndef ParserFile_hpp_5581
#define ParserFile_hpp_5581

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/syntax/ParserFileContent.hpp>

namespace soulng { namespace syntax {

class ParserFile : public soulng::parsing::Grammar
{
public:
    static ParserFile* Create();
    static ParserFile* Create(soulng::parsing::ParsingDomain* parsingDomain);
    ParserFileContent* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName, int id_, soulng::parsing::ParsingDomain* parsingDomain_);
private:
    ParserFile(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class ParserFileRule;
    class IncludeDirectivesRule;
    class IncludeDirectiveRule;
    class FileAttributeRule;
    class IncludeFileNameRule;
    class NamespaceContentRule;
    class NamespaceRule;
};

} } // namespace soulng.syntax

#endif // ParserFile_hpp_5581
