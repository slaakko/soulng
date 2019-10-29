#include <sngxml/xml/XmlParserInterface.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Path.hpp>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

using namespace soulng::util;

// contents of foo.xml:
// <?xml version="1.0" encoding="utf-8"?>
// <doc>
//   <foo bar="baz">
//   </foo>
// </doc>

struct MyContentHandler : public sngxml::xml::XmlContentHandler
{
    void StartElement(const std::u32string& namespaceUri, const std::u32string& localName, const std::u32string& qualifiedName, const sngxml::xml::Attributes& attributes) override
    {
        if (localName == U"foo")
        {
            std::cout << "foo found" << std::endl;
        }
    }
};

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

int main()
{
    Initializer initializer; // performs dynamic library initialization
    try
    {
        MyContentHandler contentHandler;
        sngxml::xml::ParseXmlFile(Path::Combine(GetSoulNGRootDir(), "examples/sngxml/foo.xml"), &contentHandler);
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
