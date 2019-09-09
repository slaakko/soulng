// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_CODE_MODIFY_VISITOR_INCLUDED
#define SOULNG_SPG_CODE_MODIFY_VISITOR_INCLUDED
#include <soulng/spg/NonterminalInfo.hpp>
#include <soulng/cppcode/Type.hpp>
#include <vector>
#include <string>

namespace soulng { namespace spg {

class CodeModifyVisitor : public soulng::cppcode::Visitor
{
public:
    CodeModifyVisitor(bool valueOfPtrType_, const std::u32string& nonterminalName_, const std::vector<NonterminalInfo>& nonterminalInfos_, soulng::cppcode::TypeId* returnType_);
    void Visit(soulng::cppcode::ReturnStatement& object) override;
    void Visit(soulng::cppcode::IdExpr& object);
private:
    bool valueOfPtrType;
    std::u32string nonterminalName;
    std::vector<NonterminalInfo> nonterminalInfos;
    std::vector<int> nonterminalCounts;
    soulng::cppcode::TypeId* returnType;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_CODE_MODIFY_VISITOR_INCLUDED
