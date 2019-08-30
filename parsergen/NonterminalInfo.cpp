// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsergen/NonterminalInfo.hpp>
#include <soulng/codedom/Expression.hpp>

namespace soulng {  namespace parsergen {

NonterminalInfo::NonterminalInfo(const std::u32string& name_, bool ptrType_) : name(name_), ptrType(ptrType_), count(0)
{
}

void NonterminalCountingVisitor::Visit(soulng::codedom::IdExpr& object)
{
    for (auto& info : nonterminalInfos)
    {
        if (object.Name() == info.name)
        {
            ++info.count;
        }
    }
}

} } // namespae soulng::parsergen
