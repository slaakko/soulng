// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/FundamentalTypeSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

class FundamentalTypeFlagMapper
{
public:
    static void Init();
    static void Done();
    static FundamentalTypeFlagMapper& Instance() { return *instance; }
    FundamentalTypeKind GetFundamentalTypeKind(DeclarationFlags flags) const;
private:
    FundamentalTypeFlagMapper();
    static std::unique_ptr<FundamentalTypeFlagMapper> instance;
    std::map<DeclarationFlags, FundamentalTypeKind> flagMap;
};

std::unique_ptr<FundamentalTypeFlagMapper> FundamentalTypeFlagMapper::instance;

void FundamentalTypeFlagMapper::Init()
{
    instance.reset(new FundamentalTypeFlagMapper());
}

void FundamentalTypeFlagMapper::Done()
{
    instance.reset();
}

FundamentalTypeFlagMapper::FundamentalTypeFlagMapper()
{
    flagMap[DeclarationFlags::voidFlag] = FundamentalTypeKind::voidType;
    flagMap[DeclarationFlags::charFlag] = FundamentalTypeKind::charType;
    flagMap[DeclarationFlags::char8Flag] = FundamentalTypeKind::char8Type;
    flagMap[DeclarationFlags::char16Flag] = FundamentalTypeKind::char16Type;
    flagMap[DeclarationFlags::char32Flag] = FundamentalTypeKind::char32Type;
    flagMap[DeclarationFlags::wcharFlag] = FundamentalTypeKind::wcharType;
    flagMap[DeclarationFlags::boolFlag] = FundamentalTypeKind::boolType;
    flagMap[DeclarationFlags::shortFlag] = FundamentalTypeKind::shortIntType;
    flagMap[DeclarationFlags::shortFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::shortIntType;
    flagMap[DeclarationFlags::intFlag] = FundamentalTypeKind::intType;
    flagMap[DeclarationFlags::longFlag] = FundamentalTypeKind::longIntType;
    flagMap[DeclarationFlags::longFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::longIntType;
    flagMap[DeclarationFlags::longLongFlag] = FundamentalTypeKind::longLongIntType;
    flagMap[DeclarationFlags::longLongFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::longLongIntType;
    flagMap[DeclarationFlags::signedFlag] = FundamentalTypeKind::intType;
    flagMap[DeclarationFlags::signedFlag | DeclarationFlags::charFlag] = FundamentalTypeKind::signedCharType;
    flagMap[DeclarationFlags::signedFlag | DeclarationFlags::longFlag] = FundamentalTypeKind::longIntType;
    flagMap[DeclarationFlags::signedFlag | DeclarationFlags::shortFlag] = FundamentalTypeKind::shortIntType;
    flagMap[DeclarationFlags::signedFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::intType;
    flagMap[DeclarationFlags::signedFlag | DeclarationFlags::longLongFlag] = FundamentalTypeKind::longLongIntType;
    flagMap[DeclarationFlags::signedFlag | DeclarationFlags::int64Flag] = FundamentalTypeKind::longLongIntType;
    flagMap[DeclarationFlags::signedFlag | DeclarationFlags::longFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::longIntType;
    flagMap[DeclarationFlags::signedFlag | DeclarationFlags::longLongFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::longLongIntType;
    flagMap[DeclarationFlags::signedFlag | DeclarationFlags::shortFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::shortIntType;
    flagMap[DeclarationFlags::unsignedFlag] = FundamentalTypeKind::unsignedIntType;
    flagMap[DeclarationFlags::unsignedFlag | DeclarationFlags::charFlag] = FundamentalTypeKind::unsignedCharType;
    flagMap[DeclarationFlags::unsignedFlag | DeclarationFlags::longFlag] = FundamentalTypeKind::unsignedLongIntType;
    flagMap[DeclarationFlags::unsignedFlag | DeclarationFlags::shortFlag] = FundamentalTypeKind::unsignedShortIntType;
    flagMap[DeclarationFlags::unsignedFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::unsignedIntType;
    flagMap[DeclarationFlags::unsignedFlag | DeclarationFlags::shortFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::unsignedIntType;
    flagMap[DeclarationFlags::unsignedFlag | DeclarationFlags::longFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::unsignedLongIntType;
    flagMap[DeclarationFlags::unsignedFlag | DeclarationFlags::longLongFlag] = FundamentalTypeKind::unsignedLongLongIntType;
    flagMap[DeclarationFlags::unsignedFlag | DeclarationFlags::longLongFlag | DeclarationFlags::intFlag] = FundamentalTypeKind::unsignedLongLongIntType;
    flagMap[DeclarationFlags::unsignedFlag | DeclarationFlags::int64Flag] = FundamentalTypeKind::unsignedLongLongIntType;
    flagMap[DeclarationFlags::floatFlag] = FundamentalTypeKind::floatType;
    flagMap[DeclarationFlags::doubleFlag] = FundamentalTypeKind::doubleType;
    flagMap[DeclarationFlags::longFlag | DeclarationFlags::doubleFlag] = FundamentalTypeKind::longDoubleType;
    flagMap[DeclarationFlags::int64Flag] = FundamentalTypeKind::longLongIntType;
    flagMap[DeclarationFlags::autoFlag] = FundamentalTypeKind::autoType;
}

FundamentalTypeKind FundamentalTypeFlagMapper::GetFundamentalTypeKind(DeclarationFlags flags) const
{
    auto it = flagMap.find(flags);
    if (it != flagMap.cend())
    {
        return it->second;
    }
    else
    {
        return FundamentalTypeKind::none;
    }
}

const char* fundamentalTypeNames[] =
{
    "none", "char", "char8_t", "char16_t", "char32_t", "wchar_t", "bool", "short int", "int", "long int", "long long int", "float", "double", "void",
    "signed char", "unsigned char", "unsigned short int", "unsigned int", "unsigned long int", "unsigned long long int", "long double", "auto"
};

std::u32string MakeFundamentalTypeName(FundamentalTypeKind kind)
{
    return ToUtf32(fundamentalTypeNames[static_cast<int>(kind)]);
}

FundamentalTypeSymbol::FundamentalTypeSymbol(FundamentalTypeKind kind_) : TypeSymbol(MakeFundamentalTypeName(kind_), SymbolKind::fundamentalTypeSymbol), kind(kind_)
{
}

TypeSymbol* GetFundamentalType(DeclarationFlags fundamentalTypeFlags, const SourcePos& sourcePos, Context* context)
{
    FundamentalTypeKind fundamentalTypeKind = FundamentalTypeFlagMapper::Instance().GetFundamentalTypeKind(fundamentalTypeFlags);
    if (fundamentalTypeKind != FundamentalTypeKind::none)
    {
        return context->GetSymbolTable()->GetFundamentalTypeSymbol(fundamentalTypeKind);
    }
    else
    {
        throw Exception("invalid combination of fundamental type specifiers", sourcePos, context);
    }
}

void InitFundamentalTypeSymbol()
{
    FundamentalTypeFlagMapper::Init();
}

void DoneFundamentalTypeSymbol()
{
    FundamentalTypeFlagMapper::Done();
}

} // sngcpp::symbols
