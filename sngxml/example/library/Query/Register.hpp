#ifndef QUERY_REGISTER_INCLUDED
#define QUERY_REGISTER_INCLUDED
#include <Query/Api.hpp>

namespace query {

const int queryExprNodeClassId = 200;
const int unaryQueryExprNodeClassId = 201;
const int binaryQueryExprNodeClassId = 202;
const int stringConversionQueryExprNodeClassId = 203;
const int getQueryExprNodeClassId = 204;
const int orQueryExprNodeClassId = 205;
const int andQueryExprNodeClassId = 206;
const int matchQueryExprNodeClassId = 207;
const int relationalQueryExprNodeClassId = 208;
const int notQueryExprNodeClassId = 209;
const int memberSelectionQueryExprNodeClassId = 210;
const int parenthesizedQueryExprNodeClassId = 211;
const int booleanLiteralQueryExprNodeClassId = 212;
const int integerLiteralQueryExprNodeClassId = 213;
const int stringLiteralQueryExprNodeClassId = 214;
const int identifierQueryExprNodeClassId = 215;

QUERY_API void Register();

} // query

#endif // QUERY_REGISTER_INCLUDED
