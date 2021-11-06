// object: main.cpp:

#include <book.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/Parser.hpp>
#include <sngxml/serialization/InitDone.hpp>
#include <sngxml/xpath/InitDone.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/Unicode.hpp>
#include <iostream>

void InitApplication()
{
    soulng::util::Init();
    sngxml::xpath::Init();
    sngxml::xmlser::Init();
}

void DoneApplication()
{
    sngxml::xmlser::Done();
    sngxml::xpath::Done();
    soulng::util::Done();
}

int main()
{
    try
    {
        InitApplication();

        Book book;
        book.name = "The C++ Programming Language, 4th Edition";
        book.isbn = "0-321-56384-0";
        book.author = "Bjarne Stroustrup";
        book.published = 2013;
        book.publisher = "Pearson Education";
        book.price = 61.88f;
        book.color = Color::blue;

        std::unique_ptr<sngxml::dom::Element> element = book.ToXml("book");
        sngxml::dom::Document doc;
        doc.AppendChild(std::unique_ptr<sngxml::dom::Node>(element.release()));
        std::stringstream strStream;
        soulng::util::CodeFormatter formatter(strStream);
        doc.Write(formatter);
        std::string str = strStream.str();
        std::cout << str << std::endl;

        std::u32string content = soulng::unicode::ToUtf32(str);
        std::unique_ptr<sngxml::dom::Document> docRead = sngxml::dom::ParseDocument(content, "string");

        Book bookRead;
        bookRead.FromXml(docRead->DocumentElement());
        std::cout << bookRead.name << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    DoneApplication();
    return 0;
}