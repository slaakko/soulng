// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_ENUMERATION_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_ENUMERATION_SYMBOL_INCLUDED
#include <sngcpp/symbols/TypeSymbol.hpp>
#include <sngcpp/ast/Enumeration.hpp>

namespace sngcpp { namespace symbols {

using namespace sngcpp::ast;

class SNGCPP_SYMBOLS_API EnumTypeSymbol : public TypeSymbol
{
public:
    EnumTypeSymbol(const Span& span_, const std::u32string& name_, EnumKey enumKey_);
    std::u32string KindStr() override { return U"enum"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    bool IsEnumTypeSymbol() const override { return true; }
    bool IsParentSymbol() const override { return true; }
    TypeSymbol* BaseType() { return baseType; }
    void SetBaseType(TypeSymbol* baseType_) { baseType = baseType_; }
    void SetFileId(const std::u32string& fileId_) { fileId = fileId_; }
    const std::u32string& FileId() const { return fileId; }
    void SetFileName(const std::string& fileName_) { fileName = fileName_; }
    const std::string& FileName() const { return fileName; }
private:
    EnumKey enumKey;
    TypeSymbol* baseType;
    std::u32string fileId;
    std::string fileName;
};

class SNGCPP_SYMBOLS_API EnumeratorSymbol : public Symbol
{
public:
    EnumeratorSymbol(const Span& span_, const std::u32string& name_, const std::u32string& value_);
    TypeSymbol* GetType() override { return Parent()->GetType(); }
    std::u32string KindStr() override { return U"enumerator"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    bool IsEnumeratorSymbol() const override { return true; }
    const std::u32string& Value() const { return value; }
private:
    std::u32string value;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_ENUMERATION_SYMBOL_INCLUDED
