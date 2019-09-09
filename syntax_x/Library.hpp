/*========================================================================
    Copyright (c) 2012-2016 Seppo Laakko
    http://sourceforge.net/projects/cmajor/
 
    Distributed under the GNU General Public License, version 3 (GPLv3).
    (See accompanying LICENSE.txt or http://www.gnu.org/licenses/gpl.html)

 ========================================================================*/

#ifndef CMAJOR_SYNTAX_LIBRARY_INCLUDED
#define CMAJOR_SYNTAX_LIBRARY_INCLUDED

#include <soulng/syntax/Project.hpp>
#include <soulng/parsing/ParsingDomain.hpp>

namespace soulng { namespace syntax {

void GenerateLibraryFile(Project* project, soulng::parsing::ParsingDomain* parsingDomain);

} } // namespace cpg::syntax

#endif // CMAJOR_SYNTAX_LIBRARY_INCLUDED
