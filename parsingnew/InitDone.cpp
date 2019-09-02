// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsing/InitDone.hpp>
#include <soulng/parsing/ParsingDomain.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/cppcode/InitDone.hpp>

namespace soulng { namespace parsing {

void Init()
{
    soulng::cppcode::Init();
    ParsingDomainInit();
    KeywordInit();
}

void Done()
{
    KeywordDone();
    ParsingDomainDone();
    soulng::cppcode::Done();
}

} } // namespace soulng::parsing

