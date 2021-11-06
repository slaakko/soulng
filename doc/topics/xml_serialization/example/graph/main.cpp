// graph: main.cpp:

#include <person.hpp>
#include <group.hpp>
#include <book.hpp>
#include <bookshelf.hpp>
#include <sngxml/serialization/XmlContainer.hpp>
#include <sngxml/serialization/XmlBundle.hpp>
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

const int bookshelfClassId = 0;
const int personClassId = 1;
const int groupClassId = 2;
const int bookClassId = 3;

int main()
{
    try
    {
        InitApplication();

        Bookshelf::Register(bookshelfClassId);
        Person::Register(personClassId);
        Group::Register(groupClassId);
        Book::Register(bookClassId);

        sngxml::xmlser::XmlContainer container;

        unique_xml_ptr<Bookshelf> bookshelf(new Bookshelf());
        bookshelf->SetRandomObjectId();
        container.Add(bookshelf.Get());

        unique_xml_ptr<Person> person1(new Person());
        person1->name = "Bjarne Stroustrup";
        person1->SetRandomObjectId();
        container.Add(person1.Get());

        unique_xml_ptr<Person> person2(new Person());
        person2->name = "Donald E. Knuth";
        person2->SetRandomObjectId();
        container.Add(person2.Get());

        unique_xml_ptr<Person> person3(new Person());
        person3->name = "Erich Gamma";
        person3->SetRandomObjectId();
        container.Add(person3.Get());

        unique_xml_ptr<Person> person4(new Person());
        person4->name = "Richard Helm";
        person4->SetRandomObjectId();
        container.Add(person4.Get());

        unique_xml_ptr<Person> person5(new Person());
        person5->name = "Ralph Johnson";
        person5->SetRandomObjectId();
        container.Add(person5.Get());

        unique_xml_ptr<Person> person6(new Person());
        person6->name = "John Vlissides";
        person6->SetRandomObjectId();
        container.Add(person6.Get());

        unique_xml_ptr<Group> group1(new Group());
        group1->name = "GoF";
        group1->SetRandomObjectId();
        group1->AddMember(person3.Get());
        group1->AddMember(person4.Get());
        group1->AddMember(person5.Get());
        group1->AddMember(person6.Get());
        container.Add(group1.Get());

        unique_xml_ptr<Book> book1(new Book());
        book1->name = "The C++ Programming Language, 4th Edition";
        book1->SetRandomObjectId();
        book1->isbn = "0-321-56384-0";
        book1->SetAuthor(person1.Get());
        book1->published = 2013;
        book1->publisher = "Pearson Education";
        book1->price = 61.88f;
        book1->color = Color::blue;
        container.Add(book1.Get());

        unique_xml_ptr<Book> book2(new Book());
        book2->name = "The Art of Computer Programming";
        book2->SetRandomObjectId();
        book2->isbn = "0-201-89683-4";
        book2->SetAuthor(person2.Get());
        book2->published = 1997;
        book2->publisher = "Addison Wesley";
        book2->price = 187.99f;
        book2->color = Color::white;
        container.Add(book2.Get());

        unique_xml_ptr<Book> book3(new Book());
        book3->name = "Design Patterns";
        book3->SetRandomObjectId();
        book3->isbn = "0-201-63361-2";
        book3->SetAuthor(group1.Get());
        book3->published = 1995;
        book3->publisher = "Addison Wesley";
        book3->price = 33.0f;
        book3->color = Color::white;
        container.Add(book3.Get());

        bookshelf->AddAuthor(person1.Release());
        bookshelf->AddAuthor(person2.Release());
        bookshelf->AddAuthor(person3.Release());
        bookshelf->AddAuthor(person4.Release());
        bookshelf->AddAuthor(person5.Release());
        bookshelf->AddAuthor(person6.Release());
        bookshelf->AddAuthor(group1.Release());

        bookshelf->AddBook(book1.Release());
        bookshelf->AddBook(book2.Release());
        bookshelf->AddBook(book3.Release());

        std::unique_ptr<sngxml::xmlser::XmlBundle> bundle = container.CreateBundle(bookshelf.Get(), sngxml::xmlser::XmlBundleKind::deep);
        std::string str = bundle->ToXmlString();
        std::cout << str << std::endl;

        std::unique_ptr<sngxml::xmlser::XmlBundle> bundleRead = sngxml::xmlser::ToXmlBundle(str);
        sngxml::xmlser::XmlSerializable* root = bundleRead->Root();

        if (root->ClassId() == bookshelfClassId)
        {
            Bookshelf* bookshelf = static_cast<Bookshelf*>(root);
            std::cout << "bookshelf contains " << bookshelf->books.size() << " books" << std::endl;
            // use bookshelf...
        }
        else
        {
            throw std::runtime_error("Bookshelf expected");
        }
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    DoneApplication();
    return 0;
}