#include <sngxml/dom/Parser.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Path.hpp>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

using namespace soulng::util;

std::string GetSoulNGRootDir()
{
    const char* soulngRootEnv = getenv("SOULNG_ROOT");
    std::string soulngRootDir;
    if (soulngRootEnv)
    {
        soulngRootDir = soulngRootEnv;
    }
    if (soulngRootDir.empty())
    {
        throw std::runtime_error("please set SOULNG_ROOT environment variable to point to /path/to/soulng directory");
    }
    return soulngRootDir;
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

// contents of foo.xml:
// <?xml version="1.0" encoding="utf-8"?>
// <doc>
//   <foo bar="baz">
//   </foo>
// </doc>

int main()
{
    Initializer initializer; // performs dynamic library initialiation
    try
    {
        std::unique_ptr<sngxml::dom::Document> xmlDoc = sngxml::dom::ReadDocument(GetFullPath(Path::Combine(GetSoulNGRootDir(), "examples/sngxml/foo.xml")));
        CodeFormatter formatter(std::cout);
        xmlDoc->Write(formatter);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
