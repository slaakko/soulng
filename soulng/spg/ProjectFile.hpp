// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_PROJECT_FILE_INCLUDED
#define SOULNG_SPG_PROJECT_FILE_INCLUDED
#include <vector>
#include <string>

namespace soulng { namespace spg {

class ProjectFile
{
public:
    ProjectFile(const std::string& fileName_, const std::u32string& projectName_);
    const std::string& BasePath() const { return basePath; }
    void AddSourceFile(const std::string& sourceFile);
    const std::vector<std::string>& SourceFiles() const { return sourceFiles; }
    void AddTokenFile(const std::string& tokenFile);
    const std::vector<std::string>& TokenFiles() const { return tokenFiles; }
    const std::u32string& ProjectName() const { return projectName; }
    void SetRecovery() { recovery = true; }
    bool Recovery() const { return recovery; }
private:
    std::string fileName;
    std::string basePath;
    std::u32string projectName;
    std::vector<std::string> sourceFiles;
    std::vector<std::string> tokenFiles;
    bool recovery;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_PROJECT_FILE_INCLUDED
