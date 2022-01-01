// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CPP2CM_CPP2CM_ARGS_INCLUDED
#define CPP2CM_CPP2CM_ARGS_INCLUDED
#include <vector>
#include <string>

std::vector<int> ParseArgs(const std::u32string& args);
int ParseInt(const std::u32string& s);

#endif // CPP2CM_CPP2CM_ARGS_INCLUDED
