#include <minilang/MinilangLexer.hpp>
#include <minilang/MinilangTokens.hpp>
#include <minilang/ConsoleUnicode.hpp>
#include <minilang/PrinterVisitor.hpp>
#include <minilang/SourceFileParser.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
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

void TestMinilangParser(const std::string& minilangFilePath, bool debug)
{
	std::cout << "> " << minilangFilePath << std::endl;
	std::string s = soulng::util::ReadFile(minilangFilePath);
	std::u32string content = soulng::unicode::ToUtf32(s);
    soulng::lexer::XmlParsingLog debugLog(std::cerr);
    MinilangLexer lexer(content, minilangFilePath, 0);
    if (debug)
    {
        lexer.SetLog(&debugLog);
    }
	SourceFileParser::Parse(lexer);
	std::cout << "end of file '" << minilangFilePath << "' reached" << std::endl;
}

void PrintMinilangCode(const std::string& minilangFilePath)
{
    std::cout << "> " << minilangFilePath << std::endl;
	std::string s = soulng::util::ReadFile(minilangFilePath);
	std::u32string content = soulng::unicode::ToUtf32(s);
	MinilangLexer lexer(content, minilangFilePath, 0);
	std::unique_ptr<minilang::SourceFileNode> sourceFile = SourceFileParser::Parse(lexer);
	soulng::util::CodeFormatter formatter(std::cout);
	minilang::PrinterVisitor visitor(formatter);
	sourceFile->Accept(visitor);
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

void PrintUsage()
{
    std::cout << "Usage: minilang [options] { file.minilang }" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "--help | -h:" << std::endl;
    std::cout << "  Print help and exit." << std::endl;
    std::cout << "--lexer-test | -l" << std::endl;
    std::cout << "  Test lexical analyzer with <file.minilang>." << std::endl;
	std::cout << "--parser-test | -p" << std::endl;
	std::cout << "  Test parser with <file.minilang>." << std::endl;
    std::cout << "--debug | -d" << std::endl;
    std::cout << "  Debug parsing and print debug log to stderr." << std::endl;
}

enum class Command
{
    none, lexerTest, parserTest, print
};

int main(int argc, const char** argv)
{
    Initializer initializer;
    try
    {
        std::vector<std::string> files;
		Command command = Command::print;
        bool debug = false;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (soulng::util::StartsWith(arg, "--"))
            {
                if (arg == "--help")
                {
                    PrintUsage();
                    return 1;
                }
                else if (arg == "--lexer-test")
                {
                    command = Command::lexerTest;
                }
				else if (arg == "--parser-test")
				{
					command = Command::parserTest;
				}
                else if (arg == "--debug")
                {
                    debug = true;
                }
                else
                {
                    throw std::runtime_error("unknown argument '" + arg + "'");
                }
            }
            else if (soulng::util::StartsWith(arg, "-"))
            {
                std::string options = arg.substr(1);
                if (options.empty())
                {
                    throw std::runtime_error("unknown argument '" + arg + "'");
                }
                for (char o : options)
                {
                    if (o == 'h')
                    {
                        PrintUsage();
                        return 1;
                    }
                    else if (o == 'l')
                    {
                        command = Command::lexerTest;
                    }
					else if (o == 'p')
					{
						command = Command::parserTest;
					}
                    else if (o == 'd')
                    {
                        debug = true;
                    }
                    else
                    {
                        throw std::runtime_error("unknown argument '-" + std::string(1, o) + "'");
                    }
                }
            }
            else
            {
                files.push_back(soulng::util::GetFullPath(arg));
            }
        }
        if (files.empty() || command == Command::none)
        {
            PrintUsage();
            return 1;
        }
        for (const std::string& filePath : files)
        {
            if (command == Command::lexerTest)
            {
                TestMinilangLexer(filePath);
            }
			else if (command == Command::parserTest)
			{
				TestMinilangParser(filePath, debug);
			}
			else if (command == Command::print)
			{
				PrintMinilangCode(filePath);
			}
            else
            {
                PrintUsage();
                throw std::runtime_error("minilang: unknown command");
            }
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << soulng::unicode::ToUtf32(ex.what()) << std::endl;
        return 1;
    }
    return 0;
}
