// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_SOLUTION_INCLUDED
#define SNGCPP_AST_SOLUTION_INCLUDED
#include <sngcpp/ast/AstApi.hpp>
#include <stdint.h>
#include <memory>
#include <vector>
#include <string>
#include <unordered_map>

namespace sngcpp { namespace ast {

struct SNGCPP_AST_API Version
{
    Version();
    Version(uint32_t major_, uint32_t minor_, uint32_t revision_, uint32_t build_);
    uint32_t major;
    uint32_t minor;
    uint32_t revision;
    uint32_t build;
};

class SNGCPP_AST_API Project
{
public:
    Project(const std::u32string& languageGuid_, const std::u32string& name_, const std::string filePath_, std::u32string guid_);
    Project(const Project&) = delete;
    Project(Project&&) = delete;
    Project& operator=(const Project&) = delete;
    Project&& operator=(Project&&) = delete;
    void AddDependency(const std::u32string& dependency);
    const std::u32string& LanguageGuid() const { return languageGuid; }
    const std::u32string& Name() const { return name; }
    const std::string& FilePath() const { return filePath; }
    const std::u32string& Guid() const { return guid; }
    const std::vector<std::u32string>& Dependencies() const { return dependencies; }
private:
    std::u32string languageGuid;
    std::u32string name;
    std::string filePath;
    std::u32string guid;
    std::vector<std::u32string> dependencies;
};

class SNGCPP_AST_API Solution
{
public:
    Solution(const std::string& filePath_, const Version& formatVersion_, const Version& visualStudioVersion_, const Version& minimumVisualStudioVersion_);
    Solution(const Solution&) = delete;
    Solution(Solution&&) = delete;
    Solution& operator=(const Solution&) = delete;
    Solution&& operator=(Solution&&) = delete;
    void AddProject(Project* project);
    Project* GetProject(const std::u32string& guid) const;
    std::vector<Project*> BuildOrder();
    const std::string& BasePath() const { return basePath; }
private:
    std::string filePath;
    std::string basePath;
    Version formatVersion;
    Version visualStudioVersion;
    Version minimumVisualStudioVersion;
    std::vector<std::unique_ptr<Project>> projects;
    std::unordered_map<std::u32string, Project*> projectMap;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_SOLUTION_INCLUDED
