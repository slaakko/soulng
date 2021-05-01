// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PROJECT_PROJECT_INCLUDED
#define SNGCPP_PROJECT_PROJECT_INCLUDED
#include <sngcpp20/project/ProjectApi.hpp>
#include <string>
#include <vector>

namespace sngcpp::project {

struct PROJECT_API File
{
    std::string name;
    std::string path;
};

class PROJECT_API Project
{
public:
    Project(const std::string& path_, bool verbose);
private:
    std::string dirPath;
    std::string rootPath;
    std::string filePath;
    std::string name;
    std::vector<File> files;
};

PROJECT_API void MakeProjectFile(const std::string& path, const std::string& patterns, bool verbose);

} // namespace sngcpp::project

#endif // SNGCPP_PROJECT_PROJECT_INCLUDED
