// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/NonterminalInfo.hpp>
#include <soulng/cppcode/Expression.hpp>

namespace soulng { namespace spg {

NonterminalInfo::NonterminalInfo(const std::u32string& name_, bool ptrType_) : name(name_), ptrType(ptrType_), count(0)
{
}

void NonterminalCountingVisitor::Visit(soulng::cppcode::IdExpr& object)
{
    for (auto& info : nonterminalInfos)
    {
        if (object.Name() == info.name)
        {
            ++info.count;
        }
    }
}

} } // namespae soulng::spg
