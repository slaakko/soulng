#include <sngcpp20/lexer/CppTokenLexer.hpp>
#include <sngcpp20/lexer/CppTokenLexerTokens.hpp>
#include <sngxml/dom/Element.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/CharacterData.hpp>
#include <sngxml/xpath/InitDone.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/MappedInputFile.hpp>
#include <soulng/util/Unicode.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

struct InitDone
{
    InitDone()
    {
        soulng::util::Init();
        sngxml::xpath::Init();
    }
    ~InitDone()
    {
        sngxml::xpath::Done();
        soulng::util::Done();
    }
};

using namespace soulng::unicode;
using namespace soulng::util;
using namespace soulng::lexer;
using namespace CppTokenLexerTokens;

std::vector<std::u32string> GetLines(const std::u32string& text)
{
    std::vector<std::u32string> lines;
    std::u32string line;
    int state = 0;
    for (char32_t c : text)
    {
        switch (state)
        {
            case 0:
            {
                if (c == '\n')
                {
                    lines.push_back(std::move(line));
                    line.clear();
                    state = 1;
                }
                else if (c != '\r')
                {
                    line.append(1, c);
                }
                break;
            }
            case 1:
            {
                if (c == '\n')
                {
                    lines.push_back(std::move(line));
                    line.clear();
                }
                else if (c != '\r')
                {
                    line.append(1, c);
                    state = 0;
                }
                break;
            }
        }
    }
    if (state == 0)
    {
        lines.push_back(std::move(line));
    }
    return lines;
}

void ProcessFile(const std::string& filePath, bool out)
{
    std::ostream* stream = &std::cout;
    std::ofstream file;
    if (out)
    {
        std::string outputFilePath = filePath;
        outputFilePath.append(".html");
        file.open(outputFilePath);
        stream = &file;
    }
    CodeFormatter formatter(*stream);
    formatter.SetIndentSize(1);
    sngxml::dom::Document doc;
    sngxml::dom::Element* topElement = new sngxml::dom::Element(U"span");
    topElement->SetAttribute(U"class", U"cpp");
    sngxml::dom::Element* currentElement = nullptr;
    std::string fileContent = ReadFile(filePath);
    std::vector<std::u32string> inputLines = GetLines(ToUtf32(fileContent));
    for (int i = 0; i < inputLines.size(); ++i)
    {
        std::u32string lineContent = inputLines[i];
        lineContent.append(U"\n\n");
        CppTokenLexer tokenLexer(lineContent, "", 0);
        sngxml::dom::Element* lineElement = new sngxml::dom::Element(U"span");
        lineElement->SetAttribute(U"xml:space", U"preserve");
        currentElement = lineElement;
        ++tokenLexer;
        while (*tokenLexer != END)
        {
            Token token = tokenLexer.GetToken(tokenLexer.GetPos());
            int n = token.match.end - token.match.begin;
            switch (token.id)
            {
                case WS:
                {
                    for (int i = 0; i < n; ++i)
                    {
                        switch (token.match.begin[i])
                        {
                            case ' ':
                            {
                                sngxml::dom::EntityReference* space = new sngxml::dom::EntityReference(U"nbsp");
                                currentElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(space));
                                break;
                            }
                        }
                    }
                    break;
                }
                case KEYWORD:
                {
                    sngxml::dom::Element* span = new sngxml::dom::Element(U"span");
                    span->SetAttribute(U"class", U"kw");
                    sngxml::dom::Text* text = new sngxml::dom::Text(token.match.ToString());
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(text));
                    currentElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span));
                    break;
                }
                case ID:
                {
                    sngxml::dom::Element* span = new sngxml::dom::Element(U"span");
                    span->SetAttribute(U"class", U"id");
                    sngxml::dom::Text* text = new sngxml::dom::Text(token.match.ToString());
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(text));
                    currentElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span));
                    break;
                }
                case NUMBER:
                {
                    sngxml::dom::Element* span = new sngxml::dom::Element(U"span");
                    span->SetAttribute(U"class", U"number");
                    sngxml::dom::Text* text = new sngxml::dom::Text(token.match.ToString());
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(text));
                    currentElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span));
                    break;
                }
                case PP:
                {
                    sngxml::dom::Element* span = new sngxml::dom::Element(U"span");
                    span->SetAttribute(U"class", U"pp");
                    sngxml::dom::Text* text = new sngxml::dom::Text(token.match.ToString());
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(text));
                    currentElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span));
                    break;
                }
                case OTHER:
                {
                    sngxml::dom::Element* span = new sngxml::dom::Element(U"span");
                    span->SetAttribute(U"class", U"other");
                    sngxml::dom::Text* text = new sngxml::dom::Text(token.match.ToString());
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(text));
                    currentElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span));
                    break;
                }
                case LINECOMMENT:
                {
                    sngxml::dom::Element* span = new sngxml::dom::Element(U"span");
                    span->SetAttribute(U"class", U"comment");
                    sngxml::dom::Text* text = new sngxml::dom::Text(token.match.ToString());
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(text));
                    currentElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span));
                    break;
                }
                case BLOCKCOMMENT:
                {
                    sngxml::dom::Element* span = new sngxml::dom::Element(U"span");
                    span->SetAttribute(U"class", U"comment");
                    sngxml::dom::Text* text = new sngxml::dom::Text(token.match.ToString());
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(text));
                    currentElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span));
                    break;
                }
                case BLOCKCOMMENTLINE:
                {
                    sngxml::dom::Element* span = new sngxml::dom::Element(U"span");
                    span->SetAttribute(U"class", U"comment");
                    sngxml::dom::Text* text = new sngxml::dom::Text(token.match.ToString());
                    span->AppendChild(std::unique_ptr<sngxml::dom::Node>(text));
                    currentElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(span));
                    break;
                }
            }
            ++tokenLexer;
        }
        sngxml::dom::Element* brElement = new sngxml::dom::Element(U"br");
        topElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(lineElement));
        topElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(brElement));
    }
    doc.AppendChild(std::unique_ptr<sngxml::dom::Node>(topElement));
    doc.Write(formatter);
}

void PrintHelp()
{
    // todo
}

int main(int argc, const char** argv)
{
    InitDone initDone;
    try
    {
        std::vector<std::string> files;
        bool verbose = false;
        bool out = false;
        for (int i = 1; i < argc; ++i)
        {
            std::string arg = argv[i];
            if (arg.starts_with("--"))
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
                else if (arg == "--out")
                {
                    out = true;
                }
                else
                {
                    throw std::runtime_error("unknown option '" + arg + "'");
                }
            }
            else if (arg.starts_with("-"))
            {
                std::string options = arg.substr(1);
                for (char o : options)
                {
                    switch (o)
                    {
                        case 'h':
                        {
                            PrintHelp();
                            return 1;
                        }
                        case 'v':
                        {
                            verbose = true;
                            break;
                        }
                        case 'o':
                        {
                            out = true;
                            break;
                        }
                        default:
                        {
                            throw std::runtime_error("unknown option '-" + std::string(1, o) + "'");
                        }
                    }
                }
            }
            else
            {
                files.push_back(GetFullPath(arg));
            }
        }
        for (const std::string& file : files)
        {
            ProcessFile(file, out);
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}