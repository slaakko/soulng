// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>

namespace sngcpp::symbols {

TemplateDeclarationSymbol::TemplateDeclarationSymbol() : ContainerSymbol(std::u32string())
{
    GetScope().SetKind(ScopeKind::templateDeclarationScope);
}

TemplateParameterSymbol::TemplateParameterSymbol(const std::u32string& name_) : TypeSymbol(name_)
{
}

} // sngcpp::symbols
