// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/binder/BoundSourceFile.hpp>

namespace sngcpp { namespace binder {

BoundSourceFile::BoundSourceFile(SourceFileNode& sourceFileNode_) : sourceFileNode(sourceFileNode_)
{
}

void BoundSourceFile::AddFileScope()
{
    fileScopes.push_back(std::unique_ptr<FileScope>(new FileScope()));
}

} } // namespace sngcpp::cppbinder
