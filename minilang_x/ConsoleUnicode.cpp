#include <soulng/minilang/ConsoleUnicode.hpp>
#include <soulng/util/Unicode.hpp>
#include <iostream>

#ifdef _WIN32
#include <io.h>
#include <fcntl.h>
#endif 

#ifdef _WIN32

void SetStdHandlesToUtf16Mode()
{
    _setmode(0, _O_U16TEXT);
    _setmode(1, _O_U16TEXT);
    _setmode(2, _O_U16TEXT);
}

void SetStdHandlesToNarrowMode()
{
    _setmode(0, _O_TEXT);
    _setmode(1, _O_TEXT);
    _setmode(2, _O_TEXT);
}

bool IsHandleRedirected(int handle)
{
    return !_isatty(handle);
}

struct UnicodeWriteGuard
{
    UnicodeWriteGuard()
    {
        SetStdHandlesToUtf16Mode();
    }
    ~UnicodeWriteGuard()
    {
        SetStdHandlesToNarrowMode();
    }
};

void WriteUtf16StrToStdOutOrStdErr(const std::u16string& str, FILE* file)
{
    //  precondition: file must be stdout or stderr
    if (file != stdout && file != stderr)
    {
        throw std::runtime_error("WriteUtf16StrToStdOutOrStdErr: precondition violation: file must be stdout or stderr");
    }
    UnicodeWriteGuard unicodeWriteGuard;
    size_t result = std::fwrite(str.c_str(), sizeof(char16_t), str.length(), file);
    if (result != str.length())
    {
        throw std::runtime_error("could not write Unicode text");
    }
}

std::ostream& operator<<(std::ostream& s, const std::u32string& utf32Str)
{
    if (&s == &std::cout && !IsHandleRedirected(1))
    {
        std::u16string utf16Str = soulng::unicode::ToUtf16(utf32Str);
        WriteUtf16StrToStdOutOrStdErr(utf16Str, stdout);
        return s;
    }
    else if (&s == &std::cerr && !IsHandleRedirected(2))
    {
        std::u16string utf16Str = soulng::unicode::ToUtf16(utf32Str);
        WriteUtf16StrToStdOutOrStdErr(utf16Str, stderr);
        return s;
    }
    else
    {
        return s << soulng::unicode::ToUtf8(utf32Str);
    }
}

#else // !_WIN32

std::ostream& operator<<(std::ostream& s, const std::u32string& utf32Str)
{
    return s << soulng::unicode::ToUtf8(utf32Str);
}

#endif
