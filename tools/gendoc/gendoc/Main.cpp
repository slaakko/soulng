// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <iostream>
#include <stdexcept>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Unicode.hpp>
#include <sngxml/xpath/InitDone.hpp>
#include <sngcpp/pp/InitDone.hpp>
#include <sngcpp/ast/InitDone.hpp>
#include <gendoc/gendoc/Project.hpp>
#include <gendoc/html/Html.hpp>

using namespace soulng::util;

const char* Version()
{
    return "1.0.0";
}

void PrintUsage()
{
    std::cout << "gendoc version " << Version() << std::endl;
    std::cout << "Reverse engineering tool for Windows x64." << std::endl;
    std::cout << "Usage: gendoc [options] [[PATH\\]gendoc.xml]" << std::endl;
    std::cout << "Generate HTML content for a Visual C++ project defined in the gendoc.xml." << std::endl;
    std::cout << "If no gendoc.xml parameter is given, assumes that the current working directory contains gendoc.xml." << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "--help | -h" << std::endl;
    std::cout << "  Print help and exit." << std::endl;
    std::cout << "--verbose | -v" << std::endl;
    std::cout << "  Be verbose." << std::endl;
    std::cout << "--rebuild | -r" << std::endl;
    std::cout << "  Rebuild everything." << std::endl;
    std::cout << "--clean | -l" << std::endl;
    std::cout << "  Clean everything." << std::endl;
    std::cout << "--ast | -a" << std::endl;
    std::cout << "  Generate just ASTs." << std::endl;
    std::cout << "--content | -c" << std::endl;
    std::cout << "  Generate content when ASTS are already generated." << std::endl;
    std::cout << "--end-message | -e" << std::endl;
    std::cout << "  Generate status.msg in the same directory (used when executed recursively from the parent directory)." << std::endl;
    std::cout << "--single-process | -s" << std::endl;
    std::cout << "  Run in single process." << std::endl;
}

void InitApplication()
{
    soulng::util::Init();
    sngxml::xpath::Init();
    sngcpp::pp::Init();
    sngcpp::ast::Init();
    gendoc::html::InitHeaderElementNames();
}

void DoneApplication()
{
    sngcpp::ast::Done();
    sngcpp::pp::Done();
    sngxml::xpath::Done();
    soulng::util::Done();
};

int main(int argc, const char** argv)
{
    try
    {
        InitApplication();
        bool verbose = false;
        bool rebuild = false;
        bool clean = false;
        bool ast = false;
        bool content = false;
        bool endMessage = false;
        bool single = false;
        std::vector<std::string> docFilePaths;
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
                else if (arg == "--rebuild")
                {
                    rebuild = true;
                }
                else if (arg == "--clean")
                {
                    clean = true;
                }
                else if (arg == "--ast")
                {
                    ast = true;
                }
                else if (arg == "--content")
                {
                    content = true;
                }
                else if (arg == "--end-message")
                {
                    endMessage = true;
                }
                else if (arg == "--single-process")
                {
                    single = true;
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
                    else if (o == 'r')
                    {
                        rebuild = true;
                    }
                    else if (o == 'l')
                    {
                        clean = true;
                    }
                    else if (o == 'a')
                    {
                        ast = true;
                    }
                    else if (o == 'c')
                    {
                        content = true;
                    }
                    else if (o == 'e')
                    {
                        endMessage = true;
                    }
                    else if (o == 's')
                    {
                        single = true;
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                    }
                }
            }
            else
            {
                docFilePaths.push_back(GetFullPath(arg));
            }
        }
        if (docFilePaths.empty())
        {
            std::string docFilePath = GetFullPath(Path::Combine(GetCurrentWorkingDirectory(), "gendoc.xml"));
            docFilePaths.push_back(docFilePath);
        }
        for (const std::string& docFilePath : docFilePaths)
        {
            if (verbose && !ast && !content)
            {
                std::cout << "> " << docFilePath << std::endl;
            }
            gendoc::Project project(docFilePath);
            if (clean)
            {
                project.Clean(verbose, single);
            }
            else if (ast)
            {
                project.GenerateAst(verbose, rebuild, false);
            }
            else if (content)
            {
                project.GenerateContent(verbose, rebuild, endMessage, single);
            }
            else
            {
                project.Process(verbose, rebuild, single);
            }
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    DoneApplication();
    return 0;
}
