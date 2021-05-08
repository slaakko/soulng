// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PROJECT_PROJECT_INCLUDED
#define SNGCPP_PROJECT_PROJECT_INCLUDED
#include <sngcpp20/project/ProjectApi.hpp>
#include <memory>
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
    Project(const std::string& dirPath_, bool verbose);
    Project(const Project&) = delete;
    Project& operator=(const Project&) = delete;
    const std::string& DirPath() const { return dirPath; }
    const std::string& RootPath() const { return rootPath; }
    const std::string& FilePath() const { return filePath; }
    const std::string& Name() const { return name; }
    const std::vector<std::unique_ptr<Project>>& ChildProjects() const { return childProjects; }
    const std::vector<File>& Files() const { return files; }
private:
    std::string dirPath;
    std::string rootPath;
    std::string filePath;
    std::string name;
    std::vector<std::unique_ptr<Project>> childProjects;
    std::vector<File> files;
};

PROJECT_API void MakeProjectFile(const std::string& sourceDirPath, const std::string& projectDirPath, const std::string& patterns, int level, bool recursive, bool verbose);

} // namespace sngcpp::project

#endif // SNGCPP_PROJECT_PROJECT_INCLUDED
