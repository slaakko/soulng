#ifndef LIBRARY_XML_REGISTER_INCLUDED
#define LIBRARY_XML_REGISTER_INCLUDED
#include <LibraryXml/Api.hpp>

namespace library_xml {

const int artworkClassId = 1;
const int authorClassId = 2;
const int bookClassId = 3;
const int filmClassId = 4;
const int libraryClassId = 5;
const int personClassId = 6;
const int groupClassId = 7;
const int pieceClassId = 8;
const int recordClassId = 9;
const int queryResultClassId = 10;

LIBRARY_XML_API void Register();

} // library_xml

#endif // LIBRARY_XML_REGISTER_INCLUDED
