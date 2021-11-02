// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/slg/LexerFileParser.hpp>
#include <soulng/slg/LexerFileLexer.hpp>
#include <soulng/slg/LexerContext.hpp>
#include <soulng/slg/LexerFileTokens.hpp>
#include <soulng/slg/RegularExpressionParser.hpp>
#include <soulng/cppcode/InitDone.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <stdexcept>
#include <iostream>

void PrintUsage()
{
    std::cout << "Soul NG Lexer Generator version " << soulng::slg::LexerGeneratorVersionStr() << std::endl;
    std::cout << "Usage: slg [options] <file.lexer>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "--help | -h" << std::endl;
    std::cout << "  Print help and exit." << std::endl;
    std::cout << "--verbose | -v" << std::endl;
    std::cout << "  Be verbose." << std::endl;
    std::cout << "--debug | -d" << std::endl;
    std::cout << "  Print character class partition and NFAs to stdout" << std::endl;
    std::cout << "--use-ascii-identifier-classes | -a" << std::endl;
    std::cout << "  Use ASCII identifier classes." << std::endl;
    std::cout << "  By default uses Unicode identifier classes." << std::endl;
    std::cout << "--no-identifier-classes | -n" << std::endl;
    std::cout << "  No predefined identifier classes" << std::endl;
}

void InitApplication()
{
    soulng::util::Init();
    soulng::cppcode::Init();
}

void DoneApplication()
{
    soulng::cppcode::Done();
    soulng::util::Done();
}

int main(int argc, const char** argv)
{
    try
    {
        InitApplication();
        bool verbose = false;
        bool debug = false;
        soulng::slg::IdentifierClassKind identifierClassKind = soulng::slg::IdentifierClassKind::unicode;
        std::string fileName;
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
                else if (arg == "--verbose")
                {
                    verbose = true;
                }
                else if (arg == "--debug")
                {
                    debug = true;
                }
                else if (arg == "--use-ascii-identifier-classes")
                {
                    identifierClassKind = soulng::slg::IdentifierClassKind::ascii;
                }
                else if (arg == "--no-identifier-classes")
                {
                    identifierClassKind = soulng::slg::IdentifierClassKind::none;
                }
                else
                {
                    throw std::runtime_error("unknown option '" + arg + "'");
                }
            }
            else if (soulng::util::StartsWith(arg, "-"))
            {
                std::string options = arg.substr(1);
                if (options.empty())
                {
                    throw std::runtime_error("unknown option '-" + arg + "'");
                }
                for (char o : options)
                {
                    if (o == 'h')
                    {
                        PrintUsage();
                        return 1;
                    }
                    else if (o == 'v')
                    {
                        verbose = true;
                    }
                    else if (o == 'd')
                    {
                        debug = true;
                    }
                    else if (o == 'a')
                    {
                        identifierClassKind = soulng::slg::IdentifierClassKind::ascii;
                    }
                    else if (o == 'n')
                    {
                        identifierClassKind = soulng::slg::IdentifierClassKind::none;
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                    }
                }
            }
            else
            {
                fileName = soulng::util::GetFullPath(arg);
            }
        }
        if (fileName.empty())
        {
            PrintUsage();
            return 1;
        }
        if (verbose)
        {
            std::cout << "> " << fileName << std::endl;
        }
        std::string s = soulng::util::ReadFile(fileName);
        std::u32string content = soulng::unicode::ToUtf32(s);
        LexerFileLexer lexer(content, fileName, 0);
        std::unique_ptr<soulng::slg::LexerFile> lexerFile = LexerFileParser::Parse(lexer);
        soulng::slg::LexerContext lexerContext(identifierClassKind);
        lexerContext.SetFileName(fileName);
        soulng::slg::RegularExpressionParser regularExpressionParser;
        lexerContext.SetParser(&regularExpressionParser);
        std::string root = soulng::util::Path::GetDirectoryName(fileName);
        lexerFile->Process(root, verbose, debug, lexerContext);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    DoneApplication();
    return 0;
}
