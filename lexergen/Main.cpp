// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/lexergen/LexerContext.hpp>
#include <soulng/lexergen/Lexer.hpp>
#include <soulng/lexergen/RegExParser.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/codedom/InitDone.hpp>
#include <soulng/parsing/InitDone.hpp>
#include <iostream>
#include <stdexcept>
#include <fstream>

void PrintUsage() 
{
    std::cout << "Usage: lexergen [options] <file.lexer>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "--help | -h" << std::endl;
    std::cout << "  Print help and exit." << std::endl;
    std::cout << "--verbose | -v" << std::endl;
    std::cout << "  Be verbose." << std::endl;
    std::cout << "--use-ascii-identifier-classes | -a" << std::endl;
    std::cout << "  Use smaller ASCII identifier classes." << std::endl;
    std::cout << "  By default uses bigger Unicode identifier classes." << std::endl;
}

struct InitDone
{
    InitDone()
    {
        soulng::util::Init();
        soulng::codedom::Init();
        soulng::parsing::Init();
    }
    ~InitDone()
    {
        soulng::parsing::Done();
        soulng::codedom::Done();
        soulng::util::Done();
    }
};

using namespace soulng::util;

int main(int argc, const char** argv)
{
    InitDone initDone;
    try
    {
        bool verbose = false;
        bool useAsciiIdentifierClasses = false;
        std::string fileName;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (StartsWith(arg, "--"))
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
                else if (arg == "--use-ascii-identifier-classes")
                {
                    useAsciiIdentifierClasses = true;
                }
                else
                {
                    throw std::runtime_error("unknown option '" + arg + "'");
                }
            }
            else if (StartsWith(arg, "-"))
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
                    else if (o == 'a')
                    {
                        useAsciiIdentifierClasses = true;
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                    }
                }
            }
            else
            { 
                fileName = argv[i];
            }
        }
        if (fileName.empty())
        {
            PrintUsage();
            return 1;
        }
        soulng::lexergen::LexerContext lexerContext(useAsciiIdentifierClasses);
        soulng::lexergen::RegExParser parser;
        lexerContext.SetParser(&parser);
        soulng::lexergen::LexerGrammar* grammar = soulng::lexergen::LexerGrammar::Create();
        soulng::util::MappedInputFile file(fileName);
        std::string s(file.Begin(), file.End());
        std::u32string content = soulng::unicode::ToUtf32(s);
        lexerContext.SetFileName(fileName);
        std::unique_ptr<soulng::lexergen::LexerFile> lexerFile(grammar->Parse(content.c_str(), content.c_str() + content.length(), 0, fileName));
        std::string root = soulng::util::GetFullPath(soulng::util::Path::GetDirectoryName(Path::MakeCanonical(fileName)));
        lexerFile->Process(root, verbose, lexerContext);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
