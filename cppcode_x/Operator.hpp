// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_CPPCODE_OPERATOR_INCLUDED
#define SOULNG_CPPCODE_OPERATOR_INCLUDED
#include <soulng/cppcode/CppCodeApi.hpp>
#include <string>

namespace soulng { namespace cppcode  {

enum class Operator 
{  
    deref, addrOf, plus, minus, and_, or_, not_, cpl, dotStar, arrowStar, bitand_, bitxor, bitor_, mul, div, rem, shiftLeft, shiftRight, 
    less, greater, lessOrEq, greaterOrEq, eq, notEq, comma,
    assign, mulAssign, divAssign, remAssign, plusAssign, minusAssign, shiftLeftAssign, shiftRightAssign, andAssign, xorAssign, orAssign
};

CPPCODE_API Operator GetOperator(const std::u32string& operatorName);
CPPCODE_API std::u32string GetOperatorStr(Operator op);
CPPCODE_API void OperatorInit();
CPPCODE_API void OperatorDone();

} } // namespace soulng::cppcode

#endif // SOULNG_CPPCODE_OPERATOR_INCLUDED
