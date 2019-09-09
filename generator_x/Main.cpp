// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/syntax/Generator.hpp>
#include <soulng/syntax/CodeGenerator.hpp>
#include <soulng/parsing/InitDone.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/InitDone.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <stdlib.h>

#if defined(_MSC_VER) && !defined(NDEBUG)
    #define _CRTDBG_MAP_ALLOC
    #include <stdlib.h>
    #include <crtdbg.h>
#endif

class InitDone
{
public:
    InitDone()
    {
        soulng::parsing::Init();
        soulng::util::Init();
    }
    ~InitDone()
    {
        soulng::util::Done();
        soulng::parsing::Done();
    }
};

using soulng::util::Split;

void AddToLibraryDirectories(const std::string& libraryPath, std::vector<std::string>& libraryDirectories)
{
    std::vector<std::string> dirs = Split(libraryPath, ';');
    int n = int(dirs.size());
    for (int i = 0; i < n; ++i)
    {
        std::string dir = dirs[i];
        libraryDirectories.push_back(dir);
    }
}

const char* version = "3.0";

int main(int argc, const char** argv)
{
#if defined(_MSC_VER) && !defined(NDEBUG)
    int dbgFlags = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    dbgFlags |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(dbgFlags);
    //_CrtSetBreakAlloc(40183);
#endif // defined(_MSC_VER) && !defined(NDEBUG)
    try
    {
        std::cout << "Cmajor Parser Generator version " << version << std::endl;
        if (argc < 2)
        {
            std::cout << "Usage: cmpg [options] {<file>.pp}\n" << "Compile Cmajor parsing project file(s) <file>.pp..." << std::endl;
            std::cout << "options:\n";
            std::cout << "-L <dir1>;<dir2>;...: add <dir1>, <dir2>, ... to library reference directories" << std::endl;
            std::cout << "-F                  : force code generation" << std::endl;
            return 1;
        }
        std::vector<std::string> projectFilePaths;
        std::vector<std::string> libraryDirectories;
        std::string soulng_root;
        const char* soulng_root_env = getenv("SOULNG_ROOT");
        if (soulng_root_env)
        {
            soulng_root = soulng_root_env;
        }
        if (soulng_root.empty())
        {
            std::cerr << "please set 'SOULNG_ROOT' environment variable to contain /path/to/soulng directory." << std::endl;
            return 2;
        }
        std::string libraryPath = (boost::filesystem::path(soulng_root) / boost::filesystem::path("parsing")).generic_string();
        AddToLibraryDirectories(libraryPath, libraryDirectories);
        bool prevWasL = false;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (arg == "-L")
            {
                prevWasL = true;
            }
            else if (arg == "-F")
            {
                soulng::syntax::SetForceCodeGen(true);
            }
            else if (prevWasL)
            {
                prevWasL = false;
                AddToLibraryDirectories(arg, libraryDirectories);
            }
            else
            {
                projectFilePaths.push_back(arg);
            }
        }
        InitDone initDone;
        int n = int(projectFilePaths.size());
        for (int i = 0; i < n; ++i)
        {
            const std::string& projectFilePath = projectFilePaths[i];
            soulng::syntax::Generate(projectFilePath, libraryDirectories);
        }
    }
    catch (std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 3;
    }
    catch (...)
    {
        std::cerr << "unknown exception" << std::endl;
        return 4;
    }
    return 0;
}
