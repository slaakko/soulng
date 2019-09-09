// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/ProjectFile.hpp>
#include <soulng/util/Path.hpp>

namespace soulng { namespace spg {

using namespace soulng::util;

ProjectFile::ProjectFile(const std::string& fileName_, const std::u32string& projectName_) : fileName(fileName_), projectName(projectName_),
    basePath(Path::GetDirectoryName(GetFullPath(fileName)))
{
}

void ProjectFile::AddSourceFile(const std::string& sourceFile)
{
    sourceFiles.push_back(sourceFile);
}

} } // namespae soulng::spg
