#ifndef RULES_H
#define RULES_H
#include <Query/Api.hpp>
#include <Query/QueryExpr.hpp>
#include <vector>

QUERY_API std::vector<const char*>* GetRuleNameVecPtr();

const int QueryParser_Query = 0;
const int QueryParser_GetQuery = 1;
const int QueryParser_BooleanExpr = 2;
const int QueryParser_OrExpr = 3;
const int QueryParser_AndExpr = 4;
const int QueryParser_MatchExpr = 5;
const int QueryParser_RelationalExpr = 6;
const int QueryParser_RelOp = 7;
const int QueryParser_PrefixExpr = 8;
const int QueryParser_PostfixExpr = 9;
const int QueryParser_PrimaryExpr = 10;
const int QueryParser_LiteralExpr = 11;
const int QueryParser_BooleanLiteralExpr = 12;
const int QueryParser_IntegerLiteralExpr = 13;
const int QueryParser_StringLiteralExpr = 14;

#endif // RULES_H
