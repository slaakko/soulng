// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_FUNDAMENTAL_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_FUNDAMENTAL_TYPE_SYMBOL_INCLUDED
#include <sngcpp20/symbols/TypeSymbol.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/symbols/Declaration.hpp>

namespace sngcpp::symbols {

using namespace soulng::lexer;

enum class FundamentalTypeKind : int
{
    none, charType, char8Type, char16Type, char32Type, wcharType, boolType, shortIntType, intType, longIntType, longLongIntType, floatType, doubleType, voidType,
    signedCharType, unsignedCharType, unsignedShortIntType, unsignedIntType, unsignedLongIntType, unsignedLongLongIntType, longDoubleType, autoType
};

class SYMBOLS_API FundamentalTypeSymbol : public TypeSymbol
{
public:
    FundamentalTypeSymbol(FundamentalTypeKind kind_);
    FundamentalTypeKind Kind() const { return kind; }
    std::string SymbolKindStr() const override { return "fundamental type symbol"; }
private:
    FundamentalTypeKind kind;
};

SYMBOLS_API TypeSymbol* GetFundamentalType(DeclarationFlags fundamentalTypeFlags, const SourcePos& sourcePos, Context* context);

SYMBOLS_API void InitFundamentalTypeSymbol();
SYMBOLS_API void DoneFundamentalTypeSymbol();

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_FUNDAMENTAL_TYPE_SYMBOL_INCLUDED
