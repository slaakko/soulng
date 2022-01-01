// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================


#include <cpp2cm/cpp2cm/System.hpp>
#include <cpp2cm/cpp2cm/Project.hpp>
#include <cpp2cm/cpp2cm/Converter.hpp>
#include <sngcpp/pp/InitDone.hpp>
#include <sngcpp/ast/InitDone.hpp>
#include <sngcm/ast/InitDone.hpp>
#include <sngxml/xpath/InitDone.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/System.hpp>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

using namespace soulng::util;

void PrintHelp()
{
    std::cout << "C++ to Cmajor converter version " << cpp2cm::Cpp2CmVersion() << std::endl;
    std::cout << "usage: cpp2cm [options] [ [PATH/]PROJECT.xml ]" << std::endl;
    std::cout << "options:" << std::endl;
    std::cout << "--help | -h" << std::endl;
    std::cout << "  Print help and exit." << std::endl;
    std::cout << "--verbose | -v" << std::endl;
    std::cout << "  Be verbose." << std::endl;
    std::cout << "--install | -i" << std::endl;
    std::cout << "  Install to installation directory defined in the PROJECT.xml." << std::endl;
    std::cout << "--system | -s" << std::endl;
    std::cout << "  Build system XML's." << std::endl;
    std::cout << "--nothrow-info | -n" << std::endl;
    std::cout << "  Print nothrow status for each file, class and function." << std::endl;
}

std::string SystemDirectoryPath()
{
    std::string soulngRootDir;
    const char* soulngRootEnv = std::getenv("SOULNG_ROOT");
    if (soulngRootEnv)
    {
        soulngRootDir = soulngRootEnv;
    }
    if (soulngRootDir.empty())
    {
        throw std::runtime_error("please set SOULNG_ROOT environment variable to point to /path/to/soulng-2.0.0 directory");
    }
    return GetFullPath(Path::Combine(soulngRootDir, "tools/cpp2cm/system"));
}

void InitApplication()
{
    soulng::util::Init();
    sngxml::xpath::Init();
    sngcpp::pp::Init();
    sngcpp::ast::Init();
    sngcm::ast::Init();
}

void DoneApplication()
{
    sngcm::ast::Done();
    sngcpp::ast::Done();
    sngcpp::pp::Done();
    sngxml::xpath::Done();
    soulng::util::Done();
}

int main(int argc, const char** argv)
{
    try
    {
        InitApplication();
        bool verbose = false;
        bool system = false;
        cpp2cm::ProcessType processType = cpp2cm::ProcessType::stage;
        std::string projectXmlFilePath;
        bool nothrowStatus = false;
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
                else if (arg == "--system")
                {
                    system = true;
                }
                else if (arg == "--install")
                {
                    processType = cpp2cm::ProcessType::install;
                }
                else if (arg == "--nothrow-info")
                {
                    nothrowStatus = true;
                }
                else
                {
                    throw std::runtime_error("unknown option '" + arg + "'");
                }
            }
            else if (StartsWith(arg, "-"))
            {
                std::string options = arg.substr(1);
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
                    else if (o == 's')
                    {
                        system = true;
                    }
                    else if (o == 'i')
                    {
                        processType = cpp2cm::ProcessType::install;
                    }
                    else if (o == 'n')
                    {
                        nothrowStatus = true;
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                    }
                }
            }
            else
            {
                projectXmlFilePath = GetFullPath(arg);
            }
        }
        std::string systemXmlFilePath = GetFullPath(Path::Combine(SystemDirectoryPath(), "system.xml"));
        if (system)
        {
            cpp2cm::ProcessSystemXml(systemXmlFilePath, verbose);
        }
        else
        {
            cpp2cm::Project project(systemXmlFilePath, projectXmlFilePath, nothrowStatus);
            project.Process(verbose, processType);
        }
    }
    catch (const std::exception & ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    DoneApplication();
    return 0;
}
