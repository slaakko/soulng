// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/util/InitDone.hpp>
#include <soulng/util/Time.hpp>
#include <soulng/util/Unicode.hpp>

namespace soulng { namespace util {

void Init()
{
    soulng::unicode::UnicodeInit();
    soulng::util::TimeInit();
}

void Done()
{
    soulng::util::TimeDone();
    soulng::unicode::UnicodeDone();
}

} } // namespace soulng::util

