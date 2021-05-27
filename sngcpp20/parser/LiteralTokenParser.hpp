// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef PARSER_LITERAL_TOKEN_PARSER_INCLUDED
#define PARSER_LITERAL_TOKEN_PARSER_INCLUDED
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/ast/Literal.hpp>
#include <soulng/lexer/Lexer.hpp>

namespace sngcpp::par {

using namespace sngcpp::ast;

PARSER_API bool IsHexChar(char32_t c);
PARSER_API uint64_t ParseHexChar(char32_t c);
PARSER_API EncodingPrefix ParseEncodingPrefix(const char32_t*& p, const char32_t* e);
PARSER_API IntegerLiteralNode* ParseIntegerLiteral(const SourcePos& sourcePos, const std::string& fileName, const std::u32string& rep);
PARSER_API FloatingLiteralNode* ParseFloatingLiteral(const SourcePos& sourcePos, const std::string& fileName, const std::u32string& rep);
PARSER_API CharacterLiteralNode* ParseCharacterLiteral(const SourcePos& sourcePos, const std::string& fileName, const std::u32string& rep);
PARSER_API RawStringLiteralNode* ParseRawStringLiteral(const SourcePos& sourcePos, soulng::lexer::Lexer& lexer);
PARSER_API StringLiteralNode* ParseStringLiteral(const SourcePos& sourcePos, const std::string& fileName, const std::u32string& rep);

} // namespace sngcpp::par

#endif // PARSER_LITERAL_TOKEN_PARSER_INCLUDED
