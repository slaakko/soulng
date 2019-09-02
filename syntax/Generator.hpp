// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CMAJOR_SYNTAX_COMPILER_INCLUDED
#define CMAJOR_SYNTAX_COMPILER_INCLUDED

#include <string>
#include <vector>

namespace soulng { namespace syntax {

void Generate(const std::string& projectFilePath, const std::vector<std::string>& libraryDirectories);

} } // namespace soulng::syntax

#endif // CMAJOR_SYNTAX_COMPILER_INCLUDED

