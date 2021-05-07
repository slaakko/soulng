// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_DECLARATION_INCLUDED
#define SNGCPP_SYMBOLS_DECLARATION_INCLUDED
#include <sngcpp20/symbols/SymbolsApi.hpp>
#include <stdint.h>

namespace sngcpp::symbols {

enum class DeclarationFlags : int
{
    none = 0, 
    staticFlag = 1 << 0,
    threadLocalFlag = 1 << 1,
    externFlag = 1 << 2,
    mutableFlag = 1 << 3,
    virtualFlag = 1 << 4,
    explicitFlag = 1 << 5,
    inlineFlag = 1 << 6,
    friendFlag = 1 << 7,
    typedefFlag = 1 << 8,
    constrExprFlag = 1 << 9,
    constEvalFlag = 1 << 10,
    constInitFlag = 1 << 11,

    charFlag = 1 << 12,
    char8Flag = 1 << 13,
    char16Flag = 1 << 14,
    char32Flag = 1 << 15,
    wcharFlag = 1 << 16,
    boolFlag = 1 << 17,
    shortFlag = 1 << 18,
    intFlag = 1 << 19,
    longFlag = 1 << 20,
    longLongFlag = 1 << 21,
    signedFlag = 1 << 22,
    unsignedFlag = 1 << 23,
    floatFlag = 1 << 24,
    doubleFlag = 1 << 25,
    longDoubleFlag = 1 << 26,
    voidFlag = 1 << 27,

    fundamentalTypeFlags = 
        charFlag | char8Flag | char16Flag | char32Flag | wcharFlag | boolFlag | shortFlag | intFlag | longFlag | longLongFlag | signedFlag | unsignedFlag | floatFlag | doubleFlag | voidFlag
};

inline DeclarationFlags operator|(DeclarationFlags left, DeclarationFlags right)
{
    return DeclarationFlags(int(left) | int(right));
}

inline DeclarationFlags operator&(DeclarationFlags left, DeclarationFlags right)
{
    return DeclarationFlags(int(left) & int(right));
}

inline DeclarationFlags operator~(DeclarationFlags flags)
{
    return DeclarationFlags(~int(flags));
}

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_DECLARATION_INCLUDED
