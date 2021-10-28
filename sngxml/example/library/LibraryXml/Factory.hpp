#ifndef LIBRARY_XML_FACTORY_INCLUDED
#define LIBRARY_XML_FACTORY_INCLUDED
#include <LibraryXml/Api.hpp>
#include <soulng/util/Time.hpp>
#include <boost/uuid/uuid.hpp>
#include <string>

namespace library_xml
{
    class Library;
    class Book;
    class Author;
    class Film;
    class Group;
    class Person;
    class Piece;
    class Record;

    using date = soulng::util::Date;

    LIBRARY_XML_API Library* MakeLibrary(const std::string& name, const boost::uuids::uuid& id);
    LIBRARY_XML_API Book* MakeBook(const std::string& name, date created, Author* author, const boost::uuids::uuid& id);
    LIBRARY_XML_API Film* MakeFilm(const std::string& name, date created, Author* author, const boost::uuids::uuid& id);
    LIBRARY_XML_API Group* MakeGroup(const std::string& name, const boost::uuids::uuid& id);
    LIBRARY_XML_API Person* MakePerson(const std::string& name, date dateOfBirth, const boost::uuids::uuid& id);
    LIBRARY_XML_API Piece* MakePiece(const std::string& name, date created, Author* author, Record* record, const boost::uuids::uuid& id);
    LIBRARY_XML_API Record* MakeRecord(const std::string name, date created, Author* author, const boost::uuids::uuid& id);
}

#endif // LIBRARY_XML_FACTORY_INCLUDED
