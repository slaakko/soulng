#ifndef Declaration_hpp_5555
#define Declaration_hpp_5555

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/codedom/Declaration.hpp>

namespace soulng { namespace code {

class Declaration : public soulng::parsing::Grammar
{
public:
    static Declaration* Create();
    static Declaration* Create(soulng::parsing::ParsingDomain* parsingDomain);
    soulng::codedom::CppObject* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName);
private:
    std::vector<std::u32string> keywords0;
    std::vector<std::u32string> keywords1;
    Declaration(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class BlockDeclarationRule;
    class SimpleDeclarationRule;
    class DeclSpecifierSeqRule;
    class DeclSpecifierRule;
    class StorageClassSpecifierRule;
    class TypeSpecifierRule;
    class SimpleTypeSpecifierRule;
    class TypeNameRule;
    class TemplateArgumentListRule;
    class TemplateArgumentRule;
    class TypedefRule;
    class CVQualifierRule;
    class NamespaceAliasDefinitionRule;
    class UsingDeclarationRule;
    class UsingDirectiveRule;
};

} } // namespace soulng.code

#endif // Declaration_hpp_5555
