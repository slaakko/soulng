// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cpp2cm/cpp2cm/Patch.hpp>
#include <soulng/util/Unicode.hpp>
#include <boost/lexical_cast.hpp>

namespace cpp2cm {

using namespace soulng::unicode;

Patch::Patch(Kind kind_) : kind(kind_)
{
}

Patch::~Patch()
{
}

void Patch::SetFileName(const std::u32string& fileName_)
{
    fileName = fileName_;
}

void Patch::SetLineNumber(const std::u32string& lineNumber_)
{
    lineNumber = lineNumber_;
}

int Patch::LineNumber() const
{
    return boost::lexical_cast<int>(ToUtf8(lineNumber));
}

InsertPatch::InsertPatch(const std::u32string& text_) : Patch(Patch::Kind::insert_), text(text_)
{
}

DeletePatch::DeletePatch() : Patch(Patch::Kind::delete_)
{
}

ModifyPatch::ModifyPatch(const std::u32string& oldText_, const std::u32string& newText_) : Patch(Patch::Kind::modify_), oldText(oldText_), newText(newText_)
{
}

PatchFile::PatchFile(const std::string& path_) : path(path_)
{
}

void PatchFile::AddPatch(Patch* patch)
{
    patches.push_back(std::unique_ptr<Patch>(patch));
}

} // namespace cpp2cm
