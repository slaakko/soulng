#include <Query/Register.hpp>
#include <Query/QueryExpr.hpp>

namespace query {

void Register()
{
    QueryExprNode::Register(queryExprNodeClassId);
    UnaryQueryExprNode::Register(unaryQueryExprNodeClassId);
    BinaryQueryExprNode::Register(binaryQueryExprNodeClassId);
    StringConversionQueryExprNode::Register(stringConversionQueryExprNodeClassId);
    GetQueryExprNode::Register(getQueryExprNodeClassId);
    OrQueryExprNode::Register(orQueryExprNodeClassId);
    AndQueryExprNode::Register(andQueryExprNodeClassId);
    MatchQueryExprNode::Register(matchQueryExprNodeClassId);
    RelationalQueryExprNode::Register(relationalQueryExprNodeClassId);
    NotQueryExprNode::Register(notQueryExprNodeClassId);
    MemberSelectionQueryExprNode::Register(memberSelectionQueryExprNodeClassId);
    ParenthesizedQueryExprNode::Register(parenthesizedQueryExprNodeClassId);
    BooleanLiteralQueryExprNode::Register(booleanLiteralQueryExprNodeClassId);
    IntegerLiteralQueryExprNode::Register(integerLiteralQueryExprNodeClassId);
    StringLiteralQueryExprNode::Register(stringLiteralQueryExprNodeClassId);
    IdentifierQueryExprNode::Register(identifierQueryExprNodeClassId);
}

} // query
