// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/ast/Statement.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/lexer/CppLexer.hpp>
#include <sngcpp20/lexer/CppTokens.hpp>
#include <soulng/lexer/Lexer.hpp>

namespace sngcpp::par {

using namespace sngcpp::ast;

PARSER_API soulng::lexer::LexerPosPair RecordCompoundStatement(CppLexer& lexer);
PARSER_API void PushSavedCompoundStatementNode(CompoundStatementNode* node, sngcpp::symbols::Context* context);
PARSER_API void PopSavedCompoundStatementNode(sngcpp::symbols::Context* context);
PARSER_API CompoundStatementNode* GetSavedCompoundStatementNode(sngcpp::symbols::Context* context);

} // namespace sngcpp::par
