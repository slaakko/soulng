// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Symbol.hpp>
#include <sngcpp20/symbols/ContainerSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

Symbol::Symbol(const std::u32string& name_) : name(name_), parent(nullptr)
{
}

Symbol::~Symbol()
{
}

std::u32string Symbol::FullName() const
{
    std::u32string fullName;
    if (parent)
    {
        fullName = parent->FullName();
    }
    if (!fullName.empty())
    {
        fullName.append(U"::");
    }
    fullName.append(name);
    return fullName;
}

void Symbol::AddSymbol(Symbol* symbol, const SourcePos& sourcePos, Context* context)
{
    throw Exception("cannot add " + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "' to " + SymbolKindStr() + " '" + ToUtf8(FullName()), sourcePos, context);
}

void Symbol::AddToGroup(ContainerSymbol* containerSymbol, const SourcePos& sourcePos, Context* context)
{
}

} // sngcpp::symbols
