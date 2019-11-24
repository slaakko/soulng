// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cpp2cm/cpp2cm/File.hpp>

namespace cpp2cm {

File::File(const std::u32string& name_, const std::string& path_) : name(name_), path(path_), included(true)
{
}

} // namespace cpp2cm
