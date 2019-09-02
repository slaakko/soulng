#ifndef ProjectFileGrammar_hpp_8893
#define ProjectFileGrammar_hpp_8893

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/parsergen/ProjectFile.hpp>

namespace soulng { namespace parsergen {

class ProjectFileGrammar : public soulng::parsing::Grammar
{
public:
    static ProjectFileGrammar* Create();
    static ProjectFileGrammar* Create(soulng::parsing::ParsingDomain* parsingDomain);
    ProjectFile* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName);
private:
    ProjectFileGrammar(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class ProjectFileRule;
    class ProjectFileContentRule;
    class SourceFileRule;
    class FilePathRule;
};

} } // namespace soulng.parsergen

#endif // ProjectFileGrammar_hpp_8893
