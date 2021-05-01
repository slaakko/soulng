// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_FILE_INCLUDED
#define SNGCPP_PP_FILE_INCLUDED
#include <sngcpp20/pp/PPApi.hpp>
#include <set>
#include <string>

namespace sngcpp::pp {

struct PP_API File
{
    File(const std::u32string& content_);
    File(std::u32string&& content_);
    File(const File&) = default;
    File(File&&) = default;
    File& operator=(const File& file) = default;
    File& operator=(File&& file) = default;
    std::u32string content;
};

class PP_API ProjectHeaderFileSet
{
public:
    void AddProjectHeaderFile(const std::string& headerFilePath);
    bool IsProjectHeaderFile(const std::string& headerFilePath) const;
private:
    std::set<std::string> headerFileSet;
};

} // namespace sngcpp::pp

#endif // SNGCPP_PP_FILE_INCLUDED
