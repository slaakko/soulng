// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cpp2cm/cpp2cm/SourceFile.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Unicode.hpp>
#include <algorithm>
#include <stdexcept>
#include <fstream>

namespace cpp2cm {

SourceFile::SourceFile(const std::u32string& name_, const std::string& path_) : name(name_), path(path_), inMemory(false)
{
}

void SourceFile::Read()
{
    inMemory = true;
    std::string content = soulng::util::ReadFile(path);
    std::u32string text = soulng::unicode::ToUtf32(content);
    std::u32string line;
    int state = 0;
    int lineNumber = 1;
    for (char32_t c : text)
    {
        switch (state)
        {
        case 0:
        {
            if (c == '\n')
            {
                std::list<std::u32string>::iterator it = lines.insert(lines.cend(), line);
                lineIteratorMap[lineNumber++] = it;
                line.clear();
                state = 1;
            }
            else if (c != '\r')
            {
                line.append(1, c);
            }
            break;
        }
        case 1:
        {
            if (c == '\n')
            {
                std::list<std::u32string>::iterator it = lines.insert(lines.cend(), line);
                lineIteratorMap[lineNumber++] = it;
                line.clear();
            }
            else if (c != '\r')
            {
                line.append(1, c);
                state = 0;
            }
            break;
        }
        }
    }
    if (state == 0)
    {
        std::list<std::u32string>::iterator it = lines.insert(lines.cend(), line);
        lineIteratorMap[lineNumber++] = it;
    }
}

void SourceFile::Write()
{
    inMemory = false;
    std::ofstream file(path);
    soulng::util::CodeFormatter formatter(file);
    for (const auto& line : lines)
    {
        formatter.WriteLine(soulng::unicode::ToUtf8(line));
    }
}

void SourceFile::Apply(Patch* patch)
{
    std::list<std::u32string>::iterator lineIt = std::list<std::u32string>::iterator();
    int lineNumber = patch->LineNumber();
    auto it = lineIteratorMap.find(lineNumber);
    if (it != lineIteratorMap.cend())
    {
        lineIt = it->second;
    }
    else
    {
        switch (patch->GetKind())
        {
            case Patch::Kind::insert_:
            {
                throw std::runtime_error("cannot insert: line number " + std::to_string(lineNumber) + " not found from file '" + path + "'");
            }
            case Patch::Kind::delete_:
            {
                throw std::runtime_error("cannot delete: line number " + std::to_string(lineNumber) + " not found from file '" + path + "'");
            }
            case Patch::Kind::modify_:
            {
                throw std::runtime_error("cannot modify: line number " + std::to_string(lineNumber) + " not found from file '" + path + "'");
            }
        }
    }
    switch (patch->GetKind())
    {
        case Patch::Kind::insert_:
        {
            InsertPatch* insertPatch = static_cast<InsertPatch*>(patch);
            lines.insert(lineIt, insertPatch->Text());
            break;
        }
        case Patch::Kind::delete_:
        {
            lines.erase(lineIt);
            break;
        }
        case Patch::Kind::modify_:
        {
            ModifyPatch* modifyPatch = static_cast<ModifyPatch*>(patch);
            std::u32string line = *lineIt;
            std::u32string::size_type pos = line.find(modifyPatch->OldText());
            if (pos != std::u32string::npos)
            {
                line.replace(pos, modifyPatch->OldText().size(), modifyPatch->NewText());
                *lineIt = line;
            }
            else
            {
                throw std::runtime_error("cannot modify: text '" + soulng::unicode::ToUtf8(modifyPatch->OldText()) + "' not found from file '" + path + "' line " + std::to_string(lineNumber));
            }
            break;
        }
    }
}

struct ByName
{
    bool operator()(std::unique_ptr<SourceFile>& left, std::unique_ptr<SourceFile>& right) const 
    {
        return left->Name() < right->Name();
    }
};

SourceFiles::SourceFiles()
{
}

void SourceFiles::Sort()
{
    std::sort(sourceFiles.begin(), sourceFiles.end(), ByName());
}

void SourceFiles::Add(SourceFile* sourceFile)
{
    sourceFileMap[sourceFile->Name()] = sourceFile;
    sourceFiles.push_back(std::unique_ptr<SourceFile>(sourceFile));
}

void SourceFiles::Apply(PatchFile* patches)
{
    for (const auto& patch : patches->Patches())
    {
        const std::u32string& fileName = patch->FileName();
        auto it = sourceFileMap.find(fileName);
        if (it != sourceFileMap.cend())
        {
            SourceFile* sourceFile = it->second;
            if (!sourceFile->InMemory())
            {
                sourceFile->Read();
            }
            sourceFile->Apply(patch.get());
        }
        else
        {
            throw std::runtime_error("source file '" + soulng::unicode::ToUtf8(fileName) + "' not found");
        }
    }
}

void SourceFiles::Write()
{
    for (const auto& sourceFile : sourceFiles)
    {
        if (sourceFile->InMemory())
        {
            sourceFile->Write();
        }
    }
}

} // namespace cpp2cm
