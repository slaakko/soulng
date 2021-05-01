// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/File.hpp>

namespace sngcpp::pp {

File::File(const std::u32string& content_) : content(content_)
{
}

File::File(std::u32string&& content_) : content(std::move(content_))
{
}

void ProjectHeaderFileSet::AddProjectHeaderFile(const std::string& headerFilePath)
{
    headerFileSet.insert(headerFilePath);
}

bool ProjectHeaderFileSet::IsProjectHeaderFile(const std::string& headerFilePath) const
{
    return headerFileSet.find(headerFilePath) != headerFileSet.cend();
}

} // namespace sngcpp::pp
