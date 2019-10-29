// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <gendoc/gendoc/File.hpp>

namespace gendoc {

File::File(const std::u32string& name_, const std::string& path_) : name(name_), path(path_), included(true)
{
}

} // namespace gendoc
