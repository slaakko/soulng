namespace soulng { namespace unicode {

std::u32string ToUtf32(const std::string&);
std::u32string ToUtf32(const std::u16string&);
std::u16string ToUtf16(const std::u32string&);
std::u16string ToUtf16(const std::string&);
std::string ToUtf8(const std::u32string&);
std::string ToUtf8(const std::u16string&);
    
} } // soulng::unicode
