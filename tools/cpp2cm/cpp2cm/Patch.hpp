// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CPP2CM_CPP2CM_PATCH_INCLUDED
#define CPP2CM_CPP2CM_PATCH_INCLUDED
#include <string>
#include <vector>
#include <memory>

namespace cpp2cm {

class Patch
{
public:
    enum class Kind { insert_, delete_, modify_ };
    Patch(Kind kind_);
    virtual ~Patch();
    Kind GetKind() const { return kind; }
    void SetFileName(const std::u32string& fileName_);
    const std::u32string& FileName() const { return fileName; }
    void SetLineNumber(const std::u32string& lineNumber_);
    int LineNumber() const;
private:
    Kind kind;
    std::u32string fileName;
    std::u32string lineNumber;
};

class InsertPatch : public Patch
{
public:
    InsertPatch(const std::u32string& text_);
    const std::u32string& Text() const { return text; }
private:
    std::u32string text;
};

class DeletePatch : public Patch
{
public:
    DeletePatch();
};

class ModifyPatch : public Patch
{
public:
    ModifyPatch(const std::u32string& oldText_, const std::u32string& newText_);
    const std::u32string& OldText() const { return oldText; }
    const std::u32string& NewText() const { return newText; }
private:
    std::u32string oldText;
    std::u32string newText;
};

class PatchFile
{
public:
    PatchFile(const std::string& path_);
    const std::string& Path() const { return path; }
    void AddPatch(Patch* patch);
    const std::vector<std::unique_ptr<Patch>>& Patches() const { return patches; }
private:
    std::string path;
    std::vector<std::unique_ptr<Patch>> patches;
};

} // namespace cpp2cm

#endif // CPP2CM_CPP2CM_PATCH_INCLUDED
