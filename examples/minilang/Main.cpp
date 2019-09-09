#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>
#include <minilang/ConsoleUnicode.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Path.hpp>
#include <iostream>
#include <stdexcept>

void TestMinilangLexer(const std::string& minilangFilePath)
{
    std::cout << "> " << minilangFilePath << std::endl;
    std::string s = soulng::util::ReadFile(minilangFilePath);
    std::u32string content = soulng::unicode::ToUtf32(s);
    MinilangLexer lexer(content, minilangFilePath, 0);
    ++lexer;
    while (*lexer != MinilangTokens::END)
    {
        std::u32string match = lexer.token.match.ToString();
        std::cout << MinilangTokens::GetTokenName(*lexer) << "(" << match << ")" << std::endl;
        ++lexer;
    }
    std::cout << "end of file '" << minilangFilePath << "' reached" << std::endl;
}

struct Initializer
{
    Initializer()
    {
        soulng::util::Init();
    }
    ~Initializer()
    {
        soulng::util::Done();
    }
};

int main(int argc, const char** argv)
{
    Initializer initializer;
    try
    {
        if (argc < 3)
        {
            throw std::runtime_error("usage: minilang <command> <file.minilang>\ncommand: test-lexer");
        }
        std::string command = argv[1];
        std::string filePath = soulng::util::GetFullPath(soulng::util::Path::MakeCanonical(argv[2]));
        if (command == "test-lexer")
        {
            TestMinilangLexer(filePath);
        }
        else
        {
            throw std::runtime_error("unknown command: '" + command + "'");
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << soulng::unicode::ToUtf32(ex.what()) << std::endl;
        return 1;
    }
    return 0;
}
