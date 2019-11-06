#ifndef CLASS_HPP
#define CLASS_HPP
#include <sngcm/parser/ParserApi.hpp>
#include <sngcm/ast/Class.hpp>
#include <sngcm/parser/ParsingContext.hpp>
#include <soulng/lexer/Token.hpp>
#include <soulng/parser/Match.hpp>
#include <soulng/parser/Value.hpp>

// this file has been automatically generated from 'D:/work/soulng-project/sngcm/parser/Class.parser' using soulng parser generator spg version 2.0.0

class CmajorLexer;

struct SNGCM_PARSER_API ClassParser
{
    static soulng::parser::Match Class(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match InheritanceAndInterfaces(CmajorLexer& lexer, ParsingContext* ctx, sngcm::ast::ClassNode* classNode);
    static soulng::parser::Match BaseClassOrInterface(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match ClassContent(CmajorLexer& lexer, ParsingContext* ctx, sngcm::ast::ClassNode* classNode);
    static soulng::parser::Match ClassMember(CmajorLexer& lexer, ParsingContext* ctx, sngcm::ast::ClassNode* classNode);
    static soulng::parser::Match StaticConstructor(CmajorLexer& lexer, ParsingContext* ctx, sngcm::ast::ClassNode* classNode);
    static soulng::parser::Match Constructor(CmajorLexer& lexer, ParsingContext* ctx, sngcm::ast::ClassNode* classNode);
    static soulng::parser::Match Destructor(CmajorLexer& lexer, ParsingContext* ctx, sngcm::ast::ClassNode* classNode);
    static soulng::parser::Match Initializer(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match MemberFunction(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match ConversionFunction(CmajorLexer& lexer, ParsingContext* ctx);
    static soulng::parser::Match MemberVariable(CmajorLexer& lexer, ParsingContext* ctx);
};

#endif // CLASS_HPP
