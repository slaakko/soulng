// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_BINDER_BOUND_SOURCE_FILE_INCLUDED
#define SNGCPP_BINDER_BOUND_SOURCE_FILE_INCLUDED
#include <sngcpp/binder/BinderApi.hpp>
#include <sngcpp/symbols/Scope.hpp>
#include <sngcpp/ast/SourceFile.hpp>

namespace sngcpp { namespace binder {

using namespace sngcpp::symbols;

class SNGCPP_BINDER_API BoundSourceFile
{
public:
    BoundSourceFile(SourceFileNode& sourceFileNode_);
    BoundSourceFile(const BoundSourceFile&) = delete;
    BoundSourceFile(BoundSourceFile&&) = delete;
    BoundSourceFile& operator=(const BoundSourceFile&) = delete;
    BoundSourceFile& operator=(BoundSourceFile&&) = delete;
    void AddFileScope();
    std::vector<std::unique_ptr<FileScope>>& FileScopes() { return fileScopes; }
private:
    SourceFileNode& sourceFileNode;
    std::vector<std::unique_ptr<FileScope>> fileScopes;
};

} } // namespace sngcpp::binder

#endif // SNGCPP_BINDER_BOUND_SOURCE_FILE_INCLUDED
