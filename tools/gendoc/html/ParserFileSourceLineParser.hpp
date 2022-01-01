// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_PARSER_FILE_SOURCE_LINE_PARSER_INCLUDED
#define GENDOC_PARSER_FILE_SOURCE_LINE_PARSER_INCLUDED
#include <gendoc/html/HtmlApi.hpp>
#include <sngcpp/ast/SourceCodeWriter.hpp>

GENDOC_HTML_API void ParseParserFileSourceLine(const std::u32string& sourceLine, sngcpp::ast::SourceCodeWriter& sourceCodeWriter);

#endif // GENDOC_PARSER_FILE_SOURCE_LINE_PARSER_INCLUDED
