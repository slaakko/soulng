#include "Rules.hpp"

std::vector<const char*> rules = {
"QueryParser.Query"
, "QueryParser.GetQuery"
, "QueryParser.BooleanExpr"
, "QueryParser.OrExpr"
, "QueryParser.AndExpr"
, "QueryParser.MatchExpr"
, "QueryParser.RelationalExpr"
, "QueryParser.RelOp"
, "QueryParser.PrefixExpr"
, "QueryParser.PostfixExpr"
, "QueryParser.PrimaryExpr"
, "QueryParser.LiteralExpr"
, "QueryParser.BooleanLiteralExpr"
, "QueryParser.IntegerLiteralExpr"
, "QueryParser.StringLiteralExpr"
};

std::vector<const char*>* GetRuleNameVecPtr()
{
    return &rules;
}
