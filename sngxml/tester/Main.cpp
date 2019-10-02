#include <sngxml/xml/XmlParserInterface.hpp>
#include <sngxml/xml/XmlContentHandler.hpp>
#include <sngxml/dom/Parser.hpp>
#include <sngxml/xpath/InitDone.hpp>
#include <sngxml/xpath/XPathEvaluate.hpp>
#include <sngxml/xpath/XPathDebug.hpp>
#include <soulng/lexer/TrivialLexer.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <soulng/util/TextUtils.hpp>
#include <soulng/util/InitDone.hpp>
#include <iostream>

using namespace soulng::unicode;

class ContentHandler : public sngxml::xml::XmlContentHandler
{
public:
    ContentHandler();
    void StartDocument() override
    {
        formatter.WriteLine("*** start document ***");
    }
    void EndDocument() override
    {
        formatter.WriteLine("*** end document ***");
    }
    void Version(const std::u32string& xmlVersion) override
    {
        formatter.WriteLine("version: " + ToUtf8(xmlVersion));
    }
    void Standalone(bool standalone) override
    {
        std::string sd = "true";
        if (!standalone)
        {
            sd = "false";
        }
        formatter.WriteLine("standalone: " + sd);
    }
    void Encoding(const std::u32string& encoding)
    {
        formatter.WriteLine("encoding: " + ToUtf8(encoding));
    }
    void Text(const std::u32string& text)
    {
        formatter.WriteLine("text: " + ToUtf8(text));
    }
    void Comment(const std::u32string& comment) override
    {
        formatter.WriteLine("comment: " + ToUtf8(comment));
    }
    void PI(const std::u32string& target, const std::u32string& data) override
    {
        formatter.WriteLine("PI: " + ToUtf8(target) + ": " + ToUtf8(data));
    }
    void CDataSection(const std::u32string& cdata) override
    {
        formatter.WriteLine("CDATA: " + ToUtf8(cdata));
    }
    void StartElement(const std::u32string& namespaceUri, const std::u32string& localName, const std::u32string& qualifiedName, const sngxml::xml::Attributes& attributes) override
    {
        formatter.WriteLine("start element:");
        formatter.IncIndent();
        formatter.WriteLine("ns: " + ToUtf8(namespaceUri));
        formatter.WriteLine("local name: " + ToUtf8(localName));
        formatter.WriteLine("qualified name: " + ToUtf8(qualifiedName));
        formatter.WriteLine("attributes:");
        formatter.IncIndent();
        for (const sngxml::xml::Attribute& attr : attributes)
        {
            formatter.WriteLine("ns: " + ToUtf8(attr.NamespaceUri()));
            formatter.WriteLine("local name: " + ToUtf8(attr.LocalName()));
            formatter.WriteLine("qualified name: " + ToUtf8(attr.QualifiedName()));
            formatter.WriteLine("value: " + ToUtf8(attr.Value()));
            formatter.WriteLine("---");
        }
        formatter.DecIndent();
        formatter.DecIndent();
    }
    void EndElement(const std::u32string& namespaceUri, const std::u32string& localName, const std::u32string& qualifiedName) override
    {
        formatter.WriteLine("end element:");
        formatter.IncIndent();
        formatter.WriteLine("ns: " + ToUtf8(namespaceUri));
        formatter.WriteLine("local name: " + ToUtf8(localName));
        formatter.WriteLine("qualified name: " + ToUtf8(qualifiedName));
        formatter.DecIndent();
    }
    void SkippedEntity(const std::u32string& entityName)
    {
        formatter.WriteLine("skipped entity:" + ToUtf8(entityName));
    }
private:
    CodeFormatter formatter;
};

ContentHandler::ContentHandler() : formatter(std::cout)
{
}

void PrintUsage()
{
    std::cout << "Usage: sngxmltester [options] ARGS..." << std::endl;
    std::cout << "options:" << std::endl;
    std::cout << "--help | -h" << std::endl;
    std::cout << "  Print help and exit." << std::endl;
    std::cout << "--content <FILE.xml>| -c <FILE.xml>" << std::endl;
    std::cout << "  Parse given FILE.xml and print its contents to stdout using a content handler." << std::endl;
    std::cout << "--dom <FILE.xml> | -m <FILE.xml>" << std::endl;
    std::cout << "  Read given FILE.xml into DOM document and then print the DOM document to stdout." << std::endl;
    std::cout << "--xpath \"QUERY\" <FILE.xml> | -x \"QUERY\" <FILE.xml>" << std::endl;
    std::cout << "  Run given XPath query against FILE.xml and print the result." << std::endl;
    std::cout << "--debug | -d" << std::endl;
    std::cout << "  Debug parsing and print parser debug XML log to stderr." << std::endl;
    std::cout << "  Note: parser debugging is enabled by default for debug build, sngxmltesterd.exe, only." << std::endl;
}

enum class Command
{
    none, content, dom, xpath
};

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

int main(int argc, const char** argv)
{
    Initializer initializer;
    try
    {
        std::vector<std::string> args;
        bool debug = false;
        Command command = Command::none;
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
                else if (arg == "--content")
                {
                    command = Command::content;
                }
                else if (arg == "--dom")
                {
                    command = Command::dom;
                }
                else if (arg == "--xpath")
                {
                    command = Command::xpath;
                }
                else if (arg == "--debug")
                {
                    debug = true;
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
                    throw std::runtime_error("unknown option '-" + arg + "'");
                }
                for (char o : options)
                {
                    if (o == 'h')
                    {
                        PrintUsage();
                        return 1;
                    }
                    else if (o == 'c')
                    {
                        command = Command::content;
                    }
                    else if (o == 'm')
                    {
                        command = Command::dom;
                    }
                    else if (o == 'x')
                    {
                        command = Command::xpath;
                    }
                    else if (o == 'd')
                    {
                        debug = true;
                    }
                    else
                    {
                        throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                    }
                }
            }
            else
            {
                args.push_back(arg);
            }
        }
        if (args.empty() || command == Command::none)
        {
            PrintUsage();
            return 1;
        }
        if (command == Command::content)
        {
            sngxml::xml::Flags flags = sngxml::xml::Flags::none;
            if (debug)
            {
                flags = flags | sngxml::xml::Flags::debug;
            }
            for (const std::string& xmlFileName : args)
            {
                std::cout << "> " << xmlFileName << std::endl;
                ContentHandler contentHandler;
                sngxml::xml::ParseXmlFile(xmlFileName, &contentHandler, flags);
            }
        }
        else if (command == Command::dom)
        {
            sngxml::dom::Flags flags = sngxml::dom::Flags::none;
            if (debug)
            {
                flags = flags | sngxml::dom::Flags::debug;
            }
            for (const std::string& xmlFileName : args)
            {
                std::cout << "> " << xmlFileName << std::endl;
                std::unique_ptr<sngxml::dom::Document> doc = sngxml::dom::ReadDocument(xmlFileName, flags);
                CodeFormatter formatter(std::cout);
                doc->Write(formatter);
            }
        }
        else if (command == Command::xpath)
        {
            if (args.size() != 2)
            {
                throw std::runtime_error("wrong number of args");
            }
            if (debug)
            {
                sngxml::xpath::SetXPathDebugParsing();
                sngxml::xpath::SetXPathDebugQuery();
            }
            std::string query = args[0];
            std::string xmlFileName = args[1];
            std::cout << "> " << xmlFileName << std::endl;
            std::unique_ptr<sngxml::dom::Document> doc = sngxml::dom::ReadDocument(xmlFileName);
            std::unique_ptr<sngxml::xpath::XPathObject> xpathObject = sngxml::xpath::Evaluate(soulng::unicode::ToUtf32(query), doc.get());
            if (debug)
            {
                std::unique_ptr<sngxml::dom::Node> queryNode = sngxml::xpath::GetXPathQueryDom();
                if (queryNode)
                {
                    CodeFormatter formatter(std::cerr);
                    formatter.SetIndentSize(1);
                    formatter.WriteLine("query:");
                    queryNode->Write(formatter);
                }
            }
            if (xpathObject)
            {
                std::unique_ptr<sngxml::dom::Node> resultNode = xpathObject->ToDom();
                if (resultNode)
                {
                    CodeFormatter formatter(std::cout);
                    formatter.SetIndentSize(1);
                    resultNode->Write(formatter);
                }
            }
        }
        else
        {
            throw std::runtime_error("unknown command");
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
