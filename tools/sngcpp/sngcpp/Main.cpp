// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/project/Project.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace sngcpp::project;
using namespace soulng::util;

int main(int argc, const char** argv)
{
    try
    {
        std::string patterns = "*.cpp;*.hpp;*.ixx";
        std::vector<std::string> paths;
        bool makeXml = false;
        bool verbose = false;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (arg.starts_with("--"))
            {
                if (arg.find('=') != std::string::npos)
                {
                    std::vector<std::string> components = Split(arg, '=');
                    if (components.size() == 2)
                    {
                        if (components[0] == "--patterns")
                        {
                            patterns = components[1];
                        }
                        else
                        {
                            throw std::runtime_error("unknown option '" + arg + "'");
                        }
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '" + arg + "'");
                    }
                }
                else
                {
                    if (arg == "--makexml")
                    {
                        makeXml = true;
                    }
                    if (arg == "--verbose")
                    {
                        verbose = true;
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '" + arg + "'");
                    }
                }
            }
            else if (arg.starts_with("-"))
            {
                if (arg.find('=') != std::string::npos)
                {
                    std::vector<std::string> components = Split(arg, '=');
                    if (components.size() == 2)
                    {
                        if (components[0] == "-p")
                        {
                            patterns = components[1];
                        }
                        else
                        {
                            throw std::runtime_error("unknown option '" + arg + "'");
                        }
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '" + arg + "'");
                    }
                }
                else
                {
                    std::string options = arg.substr(1);
                    for (char o : options)
                    {
                        switch (o)
                        {
                            case 'm':
                            {
                                makeXml = true;
                                break;
                            }
                            case 'v':
                            {
                                verbose = true;
                                break;
                            }
                            default:
                            {
                                throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                            }
                        }
                    }
                }
            }
            else
            {
                paths.push_back(GetFullPath(arg));
            }
        }
        if (paths.empty())
        {
            paths.push_back(GetFullPath("."));
        }
        if (makeXml)
        {
            if (paths.size() != 1)
            {
                throw std::runtime_error("--makexml expects zero or one paths");
            }
            MakeProjectFile(paths[0], patterns, verbose);
        }
        else
        {
            for (const std::string& path : paths)
            {
                Project project(path, verbose);
            }
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << "error: " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
