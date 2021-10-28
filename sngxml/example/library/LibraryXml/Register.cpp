#include <LibraryXml/Register.hpp>
#include <LibraryXml/Artwork.hpp>
#include <LibraryXml/Author.hpp>
#include <LibraryXml/Book.hpp>
#include <LibraryXml/Film.hpp>
#include <LibraryXml/Group.hpp>
#include <LibraryXml/Library.hpp>
#include <LibraryXml/Person.hpp>
#include <LibraryXml/Piece.hpp>
#include <LibraryXml/QueryResult.hpp>
#include <LibraryXml/Record.hpp>

namespace library_xml
{
    void Register()
    {
        Artwork::Register(artworkClassId);
        Author::Register(authorClassId);
        Book::Register(bookClassId);
        Film::Register(filmClassId);
        Library::Register(libraryClassId);
        Person::Register(personClassId);
        Group::Register(groupClassId);
        Piece::Register(pieceClassId);
        Record::Register(recordClassId);
        QueryResult::Register(queryResultClassId);
    }
}
