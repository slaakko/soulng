// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNG2HTML_SNG2HTML_PROJECT_FILE_INCLUDED
#define SNG2HTML_SNG2HTML_PROJECT_FILE_INCLUDED
#include <vector>
#include <string>

namespace sng2html { namespace sng2html {

class ProjectFile
{
public:
    ProjectFile(const std::string& fileName_, const std::u32string& projectName_);
    const std::string& BasePath() const { return basePath; }
    void AddSourceFile(const std::string& sourceFile);
    const std::vector<std::string>& SourceFiles() const { return sourceFiles; }
private:
    std::string fileName;
    std::string basePath;
    std::u32string projectName;
    std::vector<std::string> sourceFiles;
};

} } // namespace sng2html::sng2html

#endif // SNG2HTML_SNG2HTML_PROJECT_FILE_INCLUDED
