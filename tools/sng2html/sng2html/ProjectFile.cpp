// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/ProjectFile.hpp>
#include <soulng/util/Path.hpp>

namespace sng2html { namespace sng2html {

using namespace soulng::util;

ProjectFile::ProjectFile(const std::string& fileName_, const std::u32string& projectName_) : fileName(fileName_), projectName(projectName_),
    basePath(Path::GetDirectoryName(GetFullPath(fileName)))
{
}

void ProjectFile::AddSourceFile(const std::string& sourceFile)
{
    sourceFiles.push_back(sourceFile);
}

} } // namespace sng2html::sng2html
