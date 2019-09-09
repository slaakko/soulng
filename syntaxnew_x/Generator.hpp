// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SYNTAX_COMPILER_INCLUDED
#define SOULNG_SYNTAX_COMPILER_INCLUDED

#include <string>
#include <vector>

namespace soulng { namespace syntax {

void Generate(const std::string& projectFilePath, const std::vector<std::string>& libraryDirectories);

} } // namespace soulng::syntax

#endif // SOULNG_SYNTAX_COMPILER_INCLUDED

