// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_GENDOC_FILE_INCLUDED
#define GENDOC_GENDOC_FILE_INCLUDED
#include <string>

namespace cpp2cm {

class File
{
public:
    File(const std::u32string& name_, const std::string& path_);
    const std::u32string& Name() const { return name; }
    const std::string& Path() const { return path; }
    bool Included() const { return included; }
    void SetIncluded(bool included_) { included = included_; }
private:
    std::u32string name;
    std::string path;
    bool included;
};

} // namespace cpp2cm

#endif // GENDOC_GENDOC_FILE_INCLUDED

