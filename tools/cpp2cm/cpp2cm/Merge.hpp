// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CPP2CM_CPP2CM_MERGE_INCLUDED
#define CPP2CM_CPP2CM_MERGE_INCLUDED
#include <sngxml/dom/Document.hpp>

namespace cpp2cm {

std::unique_ptr<sngxml::dom::Document> Merge(sngxml::dom::Document* symbolTableXmlDoc, std::unique_ptr<sngxml::dom::Document>& stageSymbolTableXmlDoc);

} // namespace cpp2cm

#endif // CPP2CM_CPP2CM_MERGE_INCLUDED
