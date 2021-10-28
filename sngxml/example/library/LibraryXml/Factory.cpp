#include <LibraryXml/Factory.hpp>
#include <LibraryXml/Library.hpp>
#include <LibraryXml/Group.hpp>
#include <LibraryXml/Book.hpp>
#include <LibraryXml/Author.hpp>
#include <LibraryXml/Person.hpp>
#include <LibraryXml/Film.hpp>
#include <LibraryXml/Piece.hpp>
#include <LibraryXml/Record.hpp>

namespace library_xml
{
    Library* MakeLibrary(const std::string& name, const boost::uuids::uuid& id)
    {
        Library* library = new Library();
        library->SetObjectId(id);
        library->name = name;
        library->objectContainer.reset(new soulng::util::Container(library));
        library->xmlContainer.Add(library);
        return library;
    }

    Group* MakeGroup(const std::string& name, const boost::uuids::uuid& id)
    {
        Group* group = new Group();
        group->SetObjectId(id);
        group->name = name;
        return group;
    }

    Book* MakeBook(const std::string& name, date created, Author* author, const boost::uuids::uuid& id)
    {
        Book* book = new Book();
        book->SetObjectId(id);
        book->name = name;
        book->created = created;
        book->SetAuthor(author);
        return book;
    }

    Film* MakeFilm(const std::string& name, date created, Author* author, const boost::uuids::uuid& id)
    {
        Film* film = new Film();
        film->SetObjectId(id);
        film->name = name;
        film->created = created;
        film->SetAuthor(author);
        return film;
    }

    Person* MakePerson(const std::string& name, date dateOfBirth, const boost::uuids::uuid& id)
    {
        Person* person = new Person();
        person->SetObjectId(id);
        person->name = name;
        person->dateOfBirth = dateOfBirth;
        return person;
    }

    Piece* MakePiece(const std::string& name, date created, Author* author, Record* record, const boost::uuids::uuid& id)
    {
        Piece* piece = new Piece();
        piece->SetObjectId(id);
        piece->name = name;
        piece->created = created;
        piece->SetAuthor(author);
        if (record)
        {
            record->AddPiece(piece);
        }
        return piece;
    }

    Record* MakeRecord(const std::string name, date created, Author* author, const boost::uuids::uuid& id)
    {
        Record* record = new Record();
        record->SetObjectId(id);
        record->name = name;
        record->created = created;
        record->SetAuthor(author);
        return record;
    }
}
