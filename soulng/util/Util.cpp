// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/util/Util.hpp>
#include <soulng/util/BinaryReader.hpp>
#include <boost/filesystem.hpp>

namespace soulng { namespace util {

bool FileContentsEqual(const std::string& filePath1, const std::string& filePath2)
{
    if (!boost::filesystem::exists(filePath1) || !boost::filesystem::exists(filePath2))
    {
        return false;
    }
    int64_t fileSize1 = boost::filesystem::file_size(filePath1);
    int64_t fileSize2 = boost::filesystem::file_size(filePath2);
    if (fileSize1 != fileSize2)
    {
        return false;
    }
    BinaryReader fileReader1(filePath1);
    BinaryReader fileReader2(filePath2);
    for (int64_t i = 0; i < fileSize1; ++i)
    {
        uint8_t x1 = fileReader1.ReadByte();
        uint8_t x2 = fileReader2.ReadByte();
        if (x1 != x2)
        {
            return false;
        }
    }
    return true;
}

} } // namespace soulng::util
