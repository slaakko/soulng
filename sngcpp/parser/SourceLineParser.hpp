// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/SourceCodeWriter.hpp>
#include <sngcpp/parser/ParserApi.hpp>

SNGCPP_PARSER_API void ParseSourceLine(const std::u32string& sourceLine, sngcpp::ast::SourceCodeWriter& sourceCodeWriter, bool& inBlockComment);
