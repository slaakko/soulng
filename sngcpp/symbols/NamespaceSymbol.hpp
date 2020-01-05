// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_NAMESPACE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_NAMESPACE_SYMBOL_INCLUDED
#include <sngcpp/symbols/ContainerSymbol.hpp>
#include <set>

namespace sngcpp { namespace symbols {

class SNGCPP_SYMBOLS_API NamespaceSymbol : public ContainerSymbol
{
public:
    NamespaceSymbol(const Span& span_, const std::u32string& name_);
    std::u32string KindStr() override { return U"namespace"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    bool IsNamespaceSymbol() const override { return true; }
    bool IsParentSymbol() const override { return true; }
    void AddProject(const std::u32string& projectName);
    bool HasProject(const std::u32string& projectName) const;
    std::u32string FirstProject() const;
private:
    std::set<std::u32string> projects;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_NAMESPACE_SYMBOL_INCLUDED
