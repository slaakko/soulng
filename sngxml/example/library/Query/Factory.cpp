#include <Query/Factory.hpp>
#include <soulng/util/Unicode.hpp>
#include <boost/lexical_cast.hpp>

namespace query {

using namespace soulng::unicode;

StringConversionQueryExprNode* MakeStringConversionQueryExprNode(QueryExprNode* child, sngxml::xmlser::XmlContainer* container)
{
    StringConversionQueryExprNode* node = new StringConversionQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::stringConv;
    node->child = child;
    container->Add(node);
    return node;
}

GetQueryExprNode* MakeGetQueryExprNode(const std::u32string& cls, QueryExprNode* cond, sngxml::xmlser::XmlContainer* container)
{
    GetQueryExprNode* node = new GetQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::get;
    node->cls = cls;
    node->cond = cond;
    container->Add(node);
    return node;
}

OrQueryExprNode* MakeOrQueryExprNode(QueryExprNode* left, QueryExprNode* right, sngxml::xmlser::XmlContainer* container)
{
    OrQueryExprNode* node = new OrQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::or_;
    node->left = left;
    node->right = right;
    container->Add(node);
    return node;
}

AndQueryExprNode* MakeAndQueryExprNode(QueryExprNode* left, QueryExprNode* right, sngxml::xmlser::XmlContainer* container)
{
    AndQueryExprNode* node = new AndQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::and_;
    node->left = left;
    node->right = right;
    container->Add(node);
    return node;
}

MatchQueryExprNode* MakeMatchQueryExprNode(QueryExprNode* left, QueryExprNode* right, sngxml::xmlser::XmlContainer* container)
{
    MatchQueryExprNode* node = new MatchQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::match;
    node->left = MakeStringConversionQueryExprNode(left, container);
    node->right = right;
    container->Add(node);
    return node;
}

RelationalQueryExprNode* MakeRelationalQueryExprNode(QueryExprNode* left, QueryExprNode* right, Operator op, sngxml::xmlser::XmlContainer* container)
{
    RelationalQueryExprNode* node = new RelationalQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::relational;
    node->left = left;
    node->right = right;
    node->op = op;
    container->Add(node);
    return node;
}

NotQueryExprNode* MakeNotQueryExprNode(QueryExprNode* child, sngxml::xmlser::XmlContainer* container)
{
    NotQueryExprNode* node = new NotQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::not_;
    node->child = child;
    container->Add(node);
    return node;
}

MemberSelectionQueryExprNode* MakeMemberSelectionQueryExprNode(QueryExprNode* child, const std::u32string& id, sngxml::xmlser::XmlContainer* container)
{
    MemberSelectionQueryExprNode* node = new MemberSelectionQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::member;
    node->child = child;
    node->id = id;
    container->Add(node);
    return node;
}

ParenthesizedQueryExprNode* MakeParenthesizedQueryExprNode(QueryExprNode* child, sngxml::xmlser::XmlContainer* container)
{
    ParenthesizedQueryExprNode* node = new ParenthesizedQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::paren;
    node->child = child;
    container->Add(node);
    return node;
}

BooleanLiteralQueryExprNode* MakeBooleanLiteralQueryExprNode(bool value, sngxml::xmlser::XmlContainer* container)
{
    BooleanLiteralQueryExprNode* node = new BooleanLiteralQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::booleanLiteral;
    node->value = value;
    container->Add(node);
    return node;
}

IntegerLiteralQueryExprNode* MakeIntegerLiteralQueryExprNode(const std::u32string& value, sngxml::xmlser::XmlContainer* container)
{
    IntegerLiteralQueryExprNode* node = new IntegerLiteralQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::integerLiteral;
    node->value = boost::lexical_cast<int>(ToUtf8(value));
    container->Add(node);
    return node;
}

StringLiteralQueryExprNode* MakeStringLiteralQueryExprNode(const std::u32string& value, sngxml::xmlser::XmlContainer* container)
{
    StringLiteralQueryExprNode* node = new StringLiteralQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::stringLiteral;
    node->value = value;
    container->Add(node);
    return node;
}

IdentifierQueryExprNode* MakeIdentifierQueryExprNode(const std::u32string& value, sngxml::xmlser::XmlContainer* container)
{
    IdentifierQueryExprNode* node = new IdentifierQueryExprNode();
    node->SetRandomObjectId();
    node->kind = QueryExprNodeKind::identifier;
    node->value = value;
    container->Add(node);
    return node;
}

} // namespace query
