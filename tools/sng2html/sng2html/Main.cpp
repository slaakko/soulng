#include <sng2html/sng2html/Project.hpp>
#include <soulng/cppcode/InitDone.hpp>
#include <soulng/util/InitDone.hpp>
#include <sngxml/xpath/InitDone.hpp>
#include <soulng/util/TextUtils.hpp>
#include <iostream>
#include <stdexcept>

void InitApplication()
{
    soulng::util::Init();
    soulng::cppcode::Init();
    sngxml::xpath::Init();
}

void DoneApplication()
{
    sngxml::xpath::Done();
    soulng::cppcode::Done();
    soulng::util::Done();
}

using namespace soulng::util;

int main(int argc, const char** argv)
{
    try
    {
        InitApplication();
        bool verbose = false;
        std::vector<std::string> xmlFilePaths;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (StartsWith(arg, "--"))
            {
                if (arg == "--verbose")
                {
                    verbose = true;
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
                    if (o == 'v')
                    {
                        verbose = true;
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                    }
                }
            }
            else
            {
                xmlFilePaths.push_back(arg);
            }
        }
        for (const std::string& xmlFilePath : xmlFilePaths)
        {
            sng2html::sng2html::Project project(verbose, xmlFilePath);
            project.Process();
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
