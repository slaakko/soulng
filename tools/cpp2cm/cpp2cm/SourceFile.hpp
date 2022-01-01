// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CPP2CM_CPP2CM_SOURCE_FILE_INCLUDED
#define CPP2CM_CPP2CM_SOURCE_FILE_INCLUDED
#include <cpp2cm/cpp2cm/Patch.hpp>
#include <list>
#include <unordered_map>

namespace cpp2cm {

class SourceFile
{
public:
    SourceFile(const std::u32string& name_, const std::string& path_);
    bool InMemory() const { return inMemory; }
    void Read();
    void Write();
    void Apply(Patch* patch);
    const std::u32string& Name() const { return name; }
    const std::string& Path() const { return path; }
private:
    std::u32string name;
    std::string path;
    bool inMemory;
    std::list<std::u32string> lines;
    std::unordered_map<int, std::list<std::u32string>::iterator> lineIteratorMap;
};

class SourceFiles
{
public:
    SourceFiles();
    void Sort();
    void Add(SourceFile* sourceFile);
    void Apply(PatchFile* patches);
    void Write();
    const std::vector<std::unique_ptr<SourceFile>>& Get() const { return sourceFiles; }
private:
    std::vector<std::unique_ptr<SourceFile>> sourceFiles;
    std::unordered_map<std::u32string, SourceFile*> sourceFileMap;
};

} // namespace cpp2cm

#endif // CPP2CM_CPP2CM_SOURCE_FILE_INCLUDED
