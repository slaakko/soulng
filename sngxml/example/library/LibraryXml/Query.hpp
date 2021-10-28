#ifndef LIBRARY_XML_QUERY_INCLUDED
#define LIBRARY_XML_QUERY_INCLUDED
#include <LibraryXml/QueryResult.hpp>
#include <Query/QueryExpr.hpp>

namespace library_xml {

class Library;

LIBRARY_XML_API unique_xml_ptr<QueryResult> Execute(query::QueryExprNode* query, Library* library);

} // library_xml

#endif // LIBRARY_XML_QUERY_INCLUDED
