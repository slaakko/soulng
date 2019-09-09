#ifndef CONSOLE_UNICODE_HPP
#define CONSOLE_UNICODE_HPP
#include <ostream>
#include <string>

std::ostream& operator<<(std::ostream& s, const std::u32string& utf32Str);

#endif // CONSOLE_UNICODE_HPP
