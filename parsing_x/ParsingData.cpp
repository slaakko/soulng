// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsing/ParsingData.hpp>

namespace soulng { namespace parsing {

Context::Context()
{
}

Context::~Context()
{
}

ContextStack::ContextStack()
{
}

RuleData::RuleData()
{
}

ParsingData::ParsingData(int numRules) 
{
    ruleData.resize(numRules);
    for (int i = 0; i < numRules; ++i)
    {
        ruleData[i].reset(new RuleData());
    }
}

} } // namespace soulng::parsing
