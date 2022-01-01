// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef PARSER_IDENTIFIER_TOKEN_PARSER_INCLUDED
#define PARSER_IDENTIFIER_TOKEN_PARSER_INCLUDED
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/ast/Identifier.hpp>

namespace sngcpp::par {

using namespace sngcpp::ast;

PARSER_API IdentifierNode* ParseIdentifier(const SourcePos& sourcePos, const std::string& fileName, const std::u32string& rep);

} // namespace sngcpp::cppparser

#endif // PARSER_IDENTIFIER_TOKEN_PARSER_INCLUDED
