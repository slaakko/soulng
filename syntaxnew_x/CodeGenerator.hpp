// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SYNTAX_CODEGENERATOR_INCLUDED
#define SOULNG_SYNTAX_CODEGENERATOR_INCLUDED

#include <soulng/syntax/ParserFileContent.hpp>

namespace soulng { namespace syntax {

void SetForceCodeGen(bool force);
void GenerateCode(const std::vector<std::unique_ptr<ParserFileContent>>& parserFiles);

} } // namespace soulng::syntax

#endif // SOULNG_SYNTAX_CODEGENERATOR_INCLUDED
