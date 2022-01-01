// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/parser/InitDone.hpp>
#include <sngcpp20/parser/CompoundStatementRecorder.hpp>
#include <sngcpp20/symbols/Class.hpp>

namespace sngcpp::par {

void Init()
{
    sngcpp::symbols::SetRecordedParseFn(RecordedParse);
}

void Done()
{
}

} // namespace sngcpp::par
