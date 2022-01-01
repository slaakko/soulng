// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_NONTERMINAL_INFO_INCLUDED
#define SOULNG_SPG_NONTERMINAL_INFO_INCLUDED
#include <soulng/cppcode/Visitor.hpp>
#include <string>
#include <vector>

namespace soulng { namespace spg {

struct NonterminalInfo
{
    NonterminalInfo(const std::u32string& name_, bool ptrType_);
    std::u32string name;
    bool ptrType;
    int count;
};

class NonterminalCountingVisitor : public soulng::cppcode::Visitor
{
public:
    NonterminalCountingVisitor(std::vector<NonterminalInfo>& nonterminalInfos_) : nonterminalInfos(nonterminalInfos_) {}
    void Visit(soulng::cppcode::IdExpr& object);
private:
    std::vector<NonterminalInfo>& nonterminalInfos;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_NONTERMINAL_INFO_INCLUDED
