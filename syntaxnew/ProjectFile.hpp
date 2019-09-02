#ifndef ProjectFile_hpp_5581
#define ProjectFile_hpp_5581

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/syntax/Project.hpp>

namespace soulng { namespace syntax {

class ProjectFile : public soulng::parsing::Grammar
{
public:
    static ProjectFile* Create();
    static ProjectFile* Create(soulng::parsing::ParsingDomain* parsingDomain);
    Project* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName);
private:
    ProjectFile(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class ProjectFileRule;
    class ProjectFileContentRule;
    class SourceRule;
    class ReferenceRule;
    class FilePathRule;
};

} } // namespace soulng.syntax

#endif // ProjectFile_hpp_5581
