// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Solution.hpp>
#include <soulng/util/Path.hpp>
#include <unordered_set>
#ifndef _WIN32
#undef major
#undef minor
#endif

namespace sngcpp { namespace ast {

using namespace soulng::util;

Version::Version() : major(0), minor(0), revision(0), build(0)
{
}

Version::Version(uint32_t major_, uint32_t minor_, uint32_t revision_, uint32_t build_) : major(major_), minor(minor_), revision(revision_), build(build_)
{
}

Project::Project(const std::u32string& languageGuid_, const std::u32string& name_, const std::string filePath_, std::u32string guid_) :
    languageGuid(languageGuid_), name(name_), filePath(filePath_), guid(guid_)
{
}

void Project::AddDependency(const std::u32string& dependency)
{
    dependencies.push_back(dependency);
}

Solution::Solution(const std::string& filePath_, const Version& formatVersion_, const Version& visualStudioVersion_, const Version& minimumVisualStudioVersion_) :
    filePath(filePath_), formatVersion(formatVersion_), visualStudioVersion(visualStudioVersion_), minimumVisualStudioVersion(minimumVisualStudioVersion_)
{
    basePath = Path::GetDirectoryName(Path::MakeCanonical(filePath));
}

void Solution::AddProject(Project* project)
{
    projects.push_back(std::unique_ptr<Project>(project));
    projectMap[project->Guid()] = project;
}

Project* Solution::GetProject(const std::u32string& guid) const
{
    auto it = projectMap.find(guid);
    if (it != projectMap.cend())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

void Visit(std::vector<Project*>& buildOrder, Project* project, std::unordered_set<Project*>& visited, std::unordered_set<Project*>& tempVisit, Solution* solution)
{
    if (tempVisit.find(project) == tempVisit.cend())
    {
        if (visited.find(project) == visited.cend())
        {
            tempVisit.insert(project);
            for (const std::u32string& dependsOnProjectGuid : project->Dependencies())
            {
                Project* dependsOnProject = solution->GetProject(dependsOnProjectGuid);
                Visit(buildOrder, dependsOnProject, visited, tempVisit, solution);
            }
            tempVisit.erase(project);
            visited.insert(project);
            buildOrder.push_back(project);
        }
    }
}

std::vector<Project*> Solution::BuildOrder()
{
    std::vector<Project*> buildOrder;
    std::unordered_set<Project*> visited;
    std::unordered_set<Project*> tempVisit;
    for (const std::unique_ptr<Project>& project : projects)
    {
        if (visited.find(project.get()) == visited.cend())
        {
            Visit(buildOrder, project.get(), visited, tempVisit, this);
        }
    }
    return buildOrder;
}

} } // namespace sngcpp::ast
