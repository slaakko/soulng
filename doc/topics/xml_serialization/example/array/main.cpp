// array: main.cpp:

#include <bookshelf.hpp>
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

        Book anotherBook;
        anotherBook.name = "The Art of Computer Programming";
        anotherBook.isbn = "0-201-89683-4";
        anotherBook.author = "Donald E. Knuth";
        anotherBook.published = 1997;
        anotherBook.publisher = "Addison Wesley";
        anotherBook.price = 187.99f;
        anotherBook.color = Color::white;

        Bookshelf bookshelf;
        bookshelf.AddBook(book);
        bookshelf.AddBook(anotherBook);

        std::unique_ptr<sngxml::dom::Element> element = bookshelf.ToXml("bookshelf");
        sngxml::dom::Document doc;
        doc.AppendChild(std::unique_ptr<sngxml::dom::Node>(element.release()));
        std::stringstream strStream;
        soulng::util::CodeFormatter formatter(strStream);
        doc.Write(formatter);
        std::string str = strStream.str();
        std::cout << str << std::endl;

        std::u32string content = soulng::unicode::ToUtf32(str);
        std::unique_ptr<sngxml::dom::Document> docRead = sngxml::dom::ParseDocument(content, "string");

        Bookshelf bookshelfRead;
        bookshelfRead.FromXml(docRead->DocumentElement());
        std::cout << bookshelfRead.BookCount() << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    DoneApplication();
    return 0;
}