// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_DECLARATION_PROCESSOR_INCLUDED
#define SNGCPP_SYMBOLS_DECLARATION_PROCESSOR_INCLUDED
#include <sngcpp20/symbols/Declaration.hpp>
#include <sngcpp20/ast/Node.hpp>
#include <sngcpp20/symbols/Context.hpp>

namespace sngcpp::symbols {

using namespace sngcpp::ast;

SYMBOLS_API void ProcessSimpleDeclaration(Node* declaration, Context* context);
SYMBOLS_API void CheckDuplicateSpecifier(DeclarationFlags flags, DeclarationFlags flag, const std::string& specifierStr, const SourcePos& sourcePos, Context* context);

} // sngcpp::symbols

#endif // SNGCPP_SYMBOLS_DECLARATION_PROCESSOR_INCLUDED
