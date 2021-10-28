#include <Query/QueryExprParser.hpp>
#include <Query/QueryLexer.hpp>
#include <Query/QueryParser.hpp>
#include <soulng/util/Unicode.hpp>

namespace query {

using namespace soulng::unicode;

std::unique_ptr<QueryExprNode> ParseQuery(const std::string& query, sngxml::xmlser::XmlContainer& container)
{
    std::u32string content = ToUtf32(query);
    content.append(1, ';');
    QueryLexer lexer(content, "", 0);
    return QueryParser::Parse(lexer, &container);
}

} // query