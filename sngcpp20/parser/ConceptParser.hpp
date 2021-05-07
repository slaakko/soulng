#ifndef CONCEPTPARSER_HPP
#define CONCEPTPARSER_HPP
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Concept.hpp>
#include <sngcpp20/ast/Function.hpp>
#include <sngcpp20/ast/Statement.hpp>
#include <sngcpp20/parser/FunctionParser.hpp>
#include <sngcpp20/parser/IdentifierParser.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'C:/work/soulng/sngcpp20/parser/ConceptParser.parser' using soulng parser generator spg version 4.0.0

class CppLexer;

struct PARSER_API ConceptParser
{
    static soulng::parser::Match ConceptDefinition(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ConceptName(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match RequiresExpression(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match RequirementParameterList(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match RequirementBody(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match RequirementSeq(CppLexer& lexer, sngcpp::symbols::Context* ctx, sngcpp::ast::Node* requirementBody);
    static soulng::parser::Match Requirement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match SimpleRequirement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TypeRequirement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match CompoundRequirement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ReturnTypeRequirement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match NestedRequirement(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match TypeConstraint(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ConstraintExpression(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match RequiresClause(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ConstraintLogicalOrExpression(CppLexer& lexer, sngcpp::symbols::Context* ctx);
    static soulng::parser::Match ConstraintLogicalAndExpression(CppLexer& lexer, sngcpp::symbols::Context* ctx);
};

#endif // CONCEPTPARSER_HPP
