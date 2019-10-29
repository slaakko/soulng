#include <sngxml/xpath/XPathEvaluate.hpp>
#include <sngxml/xpath/InitDone.hpp>
#include <sngxml/dom/Parser.hpp>
#include <sngxml/dom/Element.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <iostream>
#include <stdexcept>
#include <stdlib.h>

using namespace soulng::util;
using namespace soulng::unicode;

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
        sngxml::xpath::Init();
    }
    ~Initializer()
    {
        sngxml::xpath::Done();
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
    Initializer initializer; // performs dynamic library initialization
    try
    {
        std::unique_ptr<sngxml::dom::Document> xmlDoc = sngxml::dom::ReadDocument(GetFullPath(Path::Combine(GetSoulNGRootDir(), "examples/sngxml/foo.xml")));
        std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/doc/foo", xmlDoc.get());
        if (result)
        {
            if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
            {
                sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
                for (int i = 0; i < nodeSet->Length(); ++i)
                {
                    sngxml::dom::Node* node = (*nodeSet)[i];
                    if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                        soulng::util::WriteUtf8(std::cout, ToUtf8(element->Name()));
                        std::cout << std::endl;
                    }
                }
            }
        }
    }
    catch (const std::exception & ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
