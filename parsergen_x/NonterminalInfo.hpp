// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSERGEN_NONTERMINAL_INFO_INCLUDED
#define SOULNG_PARSERGEN_NONTERMINAL_INFO_INCLUDED
#include <soulng/codedom/Visitor.hpp>
#include <string>
#include <vector>

namespace soulng { namespace parsergen {

struct NonterminalInfo
{
    NonterminalInfo(const std::u32string& name_, bool ptrType_);
    std::u32string name;
    bool ptrType;
    int count;
};

class NonterminalCountingVisitor : public soulng::codedom::Visitor
{
public:
    NonterminalCountingVisitor(std::vector<NonterminalInfo>& nonterminalInfos_) : nonterminalInfos(nonterminalInfos_) {}
    void Visit(soulng::codedom::IdExpr& object);
private:
    std::vector<NonterminalInfo>& nonterminalInfos;
};

} } // namespae soulng::parsergen

#endif // SOULNG_PARSERGEN_NONTERMINAL_INFO_INCLUDED
