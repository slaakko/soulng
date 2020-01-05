// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef GENDOC_HTML_CONTENT_FILE_PATH_RESOLVER_INCLUDED
#define GENDOC_HTML_CONTENT_FILE_PATH_RESOLVER_INCLUDED
#include <gendoc/html/HtmlApi.hpp>
#include <string>

namespace gendoc { namespace html {

class GENDOC_HTML_API HtmlContentFilePathResolver
{
public:
    virtual ~HtmlContentFilePathResolver();
    virtual std::string ResolveContentFilePath(const std::u32string& currentProjectName, const std::u32string& projectName, const std::string& relativeContentDirPath,
        const std::u32string& symbolId) = 0;
};

} } // namespace gendoc::html

#endif // GENDOC_HTML_CONTENT_FILE_PATH_RESOLVER_INCLUDED
