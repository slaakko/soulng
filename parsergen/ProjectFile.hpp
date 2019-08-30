// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSERGEN_PROJECT_FILE_INCLUDED
#define SOULNG_PARSERGEN_PROJECT_FILE_INCLUDED
#include <vector>
#include <string>

namespace soulng { namespace parsergen {

class ProjectFile
{
public:
    ProjectFile(const std::string& fileName_, const std::u32string& projectName_);
    const std::string& BasePath() const { return basePath; }
    void AddSourceFile(const std::u32string& sourceFile);
    const std::vector<std::u32string>& SourceFiles() const { return sourceFiles; }
private:
    std::string fileName;
    std::string basePath;
    std::u32string projectName;
    std::vector<std::u32string> sourceFiles;
};

} } // namespae soulng::parsergen

#endif // SOULNG_PARSERGEN_PROJECT_FILE_INCLUDED
