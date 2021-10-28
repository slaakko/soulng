#ifndef QUERY_QUERY_EXPR_PARSER
#define QUERY_QUERY_EXPR_PARSER
#include <Query/QueryExpr.hpp>

namespace query {

QUERY_API std::unique_ptr<QueryExprNode> ParseQuery(const std::string& query, sngxml::xmlser::XmlContainer& container);

} // query

#endif // QUERY_QUERY_EXPR_PARSER
