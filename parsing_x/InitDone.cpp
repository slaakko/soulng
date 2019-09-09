// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsing/InitDone.hpp>
#include <soulng/parsing/ParsingDomain.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/codedom/InitDone.hpp>

namespace soulng { namespace parsing {

void Init()
{
    soulng::codedom::Init();
    ParsingDomainInit();
    KeywordInit();
}

void Done()
{
    KeywordDone();
    ParsingDomainDone();
    soulng::codedom::Done();
}

} } // namespace soulng::parsing

