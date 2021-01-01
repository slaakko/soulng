// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/ProjectFileParser.hpp>
#include <soulng/spg/ProjectFileLexer.hpp>
#include <soulng/spg/ParserFileParser.hpp>
#include <soulng/spg/ParserFileLexer.hpp>
#include <soulng/spg/Domain.hpp>
#include <soulng/spg/LinkerVisitor.hpp>
#include <soulng/spg/CodeGeneratorVisitor.hpp>
#include <soulng/cppcode/InitDone.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <iostream>
#include <stdexcept>

void PrintHelp()
{
    std::cout << "Soul NG Parser Generator version " << soulng::spg::ParserGeneratorVersionStr() << std::endl;
    std::cout << "Usage: spg [options] <file.spg>" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "--help | -h" << std::endl;
    std::cout << "  Print help and exit." << std::endl;
    std::cout << "--verbose | -v" << std::endl;
    std::cout << "  Be verbose." << std::endl;
    std::cout << "--no-parser-debug-support | -n" << std::endl;
    std::cout << "  Do not generate parser debug support code to the generated parsers." << std::endl;
}

using namespace soulng::unicode;
using namespace soulng::util;

struct Initializer
{
    Initializer()
    {
        soulng::util::Init();
        soulng::cppcode::Init();
    }
    ~Initializer()
    {
        soulng::cppcode::Done();
        soulng::util::Done();
    }
};

int main(int argc, const char** argv)
{
    Initializer initializer;
    try
    {
        bool verbose = false;
        bool noParserDebugSupport = false;
        std::string projectFilePath;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (StartsWith(arg, "--"))
            {
                if (arg == "--help")
                {
                    PrintHelp();
                    return 1;
                }
                else if (arg == "--verbose")
                {
                    verbose = true;
                }
                else if (arg == "--no-parser-debug-support")
                {
                    noParserDebugSupport = true;
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
                    throw std::runtime_error("unknown option '" + arg + "'");
                }
                else
                {
                    for (char o : options)
                    {
                        if (o == 'h')
                        {
                            PrintHelp();
                            return 1;
                        }
                        else if (o == 'v')
                        {
                            verbose = true;
                        }
                        else if (o == 'n')
                        {
                            noParserDebugSupport = true;
                        }
                        else
                        {
                            throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                        }
                    }
                }
            }
            else
            {
                std::string filePath = GetFullPath(arg);
                if (Path::GetExtension(filePath) != ".spg")
                {
                    throw std::runtime_error("unknown project file extension '" + Path::GetExtension(filePath) + "'");
                }
                projectFilePath = filePath;
            }
        }
        if (projectFilePath.empty())
        {
            PrintHelp();
            return 1;
        }
        if (verbose)
        {
            std::cout << "> " << projectFilePath << std::endl;
        }
        std::string s = ReadFile(projectFilePath);
        std::u32string content = ToUtf32(s);
        ProjectFileLexer lexer(content, projectFilePath, 0);
        std::unique_ptr<soulng::spg::ProjectFile> projectFile = ProjectFileParser::Parse(lexer);
        int index = 1;
        std::vector<std::unique_ptr<soulng::spg::ParserFile>> parserFiles;
        for (const std::string& sourceFileName : projectFile->SourceFiles())
        {
            std::string sourceFilePath = Path::Combine(projectFile->BasePath(), sourceFileName);
            std::string s = ReadFile(sourceFilePath);
            std::u32string content = ToUtf32(s);
            ParserFileLexer lexer(content, sourceFilePath, index);
            std::unique_ptr<soulng::spg::ParserFile> parserFile = ParserFileParser::Parse(lexer);
            ++index;
            parserFiles.push_back(std::move(parserFile));
        }
        soulng::spg::Domain domain;
        for (const auto& parserFile : parserFiles)
        {
            domain.AddParserFile(parserFile.get());
        }
        soulng::spg::LinkerVisitor linkerVisitor;
        domain.Accept(linkerVisitor);
        soulng::spg::CodeGeneratorVisitor codeGeneratorVisitor(verbose, noParserDebugSupport);
        domain.Accept(codeGeneratorVisitor);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
