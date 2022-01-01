// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_HTML_GRAMMAR_INCLUDED
#define GENDOC_HTML_GRAMMAR_INCLUDED
#include <gendoc/html/HtmlApi.hpp>
#include <string>

namespace gendoc { namespace html {

struct GENDOC_HTML_API Grammar
{
    Grammar(const std::u32string& fileName_, const std::u32string& title_);
    std::u32string fileName;
    std::u32string title;
};

} } // namespace gendoc::html

#endif // GENDOC_HTML_GRAMMAR_INCLUDED
