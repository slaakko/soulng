#include <sngcpp/pp/InitDone.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <sngcpp/pp/PP.hpp>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace soulng::util;
using namespace soulng::unicode;
using namespace sngcpp::pp;

struct Initializer
{
    Initializer()
    {
        soulng::util::Init();
        sngcpp::pp::Init();
    }
    ~Initializer()
    {
        sngcpp::pp::Done();
        soulng::util::Done();
    }
};

void PrintUsage()
{
    std::cout << "sngcpp preprocessor tester" << std::endl;
    std::cout << "usage: pptester [options] { <file.cpp> | <file.hpp> }" << std::endl;
}

int main(int argc, const char** argv)
{
    Initializer initializer;
    try
    {
        std::vector<std::string> fileNames;
        std::string root;
        std::string includePath;
        bool verbose = false;
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
                else if (arg == "--root")
                {
                    ++i;
                    if (i < argc)
                    {
                        arg = argv[i];
                        root = GetFullPath(arg);
                    }
                    else
                    {
                        throw std::runtime_error("too few arguments");
                    }
                }
                else if (arg == "--include")
                {
                    ++i;
                    if (i < argc)
                    {
                        arg = argv[i];
                        includePath = GetFullPath(arg);
                    }
                    else
                    {
                        throw std::runtime_error("too few arguments");
                    }
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
                    else
                    {
                        throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                    }
                }
            }
            else
            {
                fileNames.push_back(GetFullPath(arg));
            }
        }
        EvaluationContext evaluationContext;
        for (const std::string& fileName : fileNames)
        {
            PP pp(evaluationContext);
            if (!root.empty())
            {
                pp.root = root;
                pp.rootMode = true;
            }
            if (!includePath.empty())
            {
                pp.includePath = Split(includePath, ';');
            }
            pp.Define(sngcpp::pp::ndebug);
            if (verbose)
            {
                pp.verbose = true;
            }
            Preprocess(fileName, &pp);
            WriteUtf8(std::cout, ToUtf8(pp.text));
            std::cout << std::endl;
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
