#ifndef QUERYPARSER_HPP
#define QUERYPARSER_HPP
#include <Query/Api.hpp>
#include <Query/QueryExpr.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngxml/example/library/Query/QueryParser.parser' using soulng parser generator spg version 3.1.0

class QueryLexer;

struct QUERY_API QueryParser
{
    static std::unique_ptr<query::QueryExprNode> Parse(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match Query(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match GetQuery(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match BooleanExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match OrExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match AndExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match MatchExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match RelationalExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match RelOp(QueryLexer& lexer);
    static soulng::parser::Match PrefixExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match PostfixExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match PrimaryExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match LiteralExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match BooleanLiteralExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match IntegerLiteralExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
    static soulng::parser::Match StringLiteralExpr(QueryLexer& lexer, sngxml::xmlser::XmlContainer* container);
};

#endif // QUERYPARSER_HPP
