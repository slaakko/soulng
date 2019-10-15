// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/pp/File.hpp>

namespace sngcpp { namespace pp {

File::File(const std::u32string& content_) : content(content_)
{
}

File::File(const std::u32string&& content_) : content(std::move(content_))
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

} } // namespace sngcpp::pp
