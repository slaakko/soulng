// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_LEXER_FILE_SOURCE_LINE_PARSER_INCLUDED
#define GENDOC_LEXER_FILE_SOURCE_LINE_PARSER_INCLUDED

#include <gendoc/html/HtmlApi.hpp>
#include <sngcpp/ast/SourceCodeWriter.hpp>

GENDOC_HTML_API void ParseLexerFileSourceLine(const std::u32string& sourceLine, sngcpp::ast::SourceCodeWriter& sourceCodeWriter);

#endif // GENDOC_LEXER_FILE_SOURCE_LINE_PARSER_INCLUDED
