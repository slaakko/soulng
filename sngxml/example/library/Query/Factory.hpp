#ifndef QUERY_FACTORY_INCLUDED
#define QUERY_FACTORY_INCLUDED
#include <Query/QueryExpr.hpp>
#include <sngxml/serialization/XmlContainer.hpp>

namespace query {

QUERY_API StringConversionQueryExprNode* MakeStringConversionQueryExprNode(QueryExprNode* child, sngxml::xmlser::XmlContainer* container);
QUERY_API GetQueryExprNode* MakeGetQueryExprNode(const std::u32string& cls, QueryExprNode* cond, sngxml::xmlser::XmlContainer* container);
QUERY_API OrQueryExprNode* MakeOrQueryExprNode(QueryExprNode* left, QueryExprNode* right, sngxml::xmlser::XmlContainer* container);
QUERY_API AndQueryExprNode* MakeAndQueryExprNode(QueryExprNode* left, QueryExprNode* right, sngxml::xmlser::XmlContainer* container);
QUERY_API MatchQueryExprNode* MakeMatchQueryExprNode(QueryExprNode* left, QueryExprNode* right, sngxml::xmlser::XmlContainer* container);
QUERY_API RelationalQueryExprNode* MakeRelationalQueryExprNode(QueryExprNode* left, QueryExprNode* right, Operator op, sngxml::xmlser::XmlContainer* container);
QUERY_API NotQueryExprNode* MakeNotQueryExprNode(QueryExprNode* child, sngxml::xmlser::XmlContainer* container);
QUERY_API MemberSelectionQueryExprNode* MakeMemberSelectionQueryExprNode(QueryExprNode* child, const std::u32string& id, sngxml::xmlser::XmlContainer* container);
QUERY_API ParenthesizedQueryExprNode* MakeParenthesizedQueryExprNode(QueryExprNode* child, sngxml::xmlser::XmlContainer* container);
QUERY_API BooleanLiteralQueryExprNode* MakeBooleanLiteralQueryExprNode(bool value, sngxml::xmlser::XmlContainer* container);
QUERY_API IntegerLiteralQueryExprNode* MakeIntegerLiteralQueryExprNode(const std::u32string& value, sngxml::xmlser::XmlContainer* container);
QUERY_API StringLiteralQueryExprNode* MakeStringLiteralQueryExprNode(const std::u32string& value, sngxml::xmlser::XmlContainer* container);
QUERY_API IdentifierQueryExprNode* MakeIdentifierQueryExprNode(const std::u32string& value, sngxml::xmlser::XmlContainer* container);

} // query

#endif // QUERY_FACTORY_INCLUDED
