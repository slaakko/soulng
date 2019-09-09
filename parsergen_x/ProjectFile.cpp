// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsergen/ProjectFile.hpp>
#include <soulng/util/Path.hpp>

namespace soulng { namespace parsergen {

using namespace soulng::util;

ProjectFile::ProjectFile(const std::string& fileName_, const std::u32string& projectName_) : fileName(fileName_), projectName(projectName_), basePath(GetFullPath(Path::GetDirectoryName(fileName)))
{
}

void ProjectFile::AddSourceFile(const std::u32string& sourceFile)
{
    sourceFiles.push_back(sourceFile);
}

} } // namespae soulng::parsergen
