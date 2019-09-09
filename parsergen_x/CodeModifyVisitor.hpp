// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSERGEN_SUCCESS_CODE_MODIFY_VISITOR_INCLUDED
#define SOULNG_PARSERGEN_SUCCESS_CODE_MODIFY_VISITOR_INCLUDED
#include <soulng/parsergen/NonterminalInfo.hpp>
#include <soulng/codedom/Type.hpp>
#include <vector>
#include <string>

namespace soulng { namespace parsergen {

class CodeModifyVisitor : public soulng::codedom::Visitor
{
public:
    CodeModifyVisitor(bool valueOfPtrType_, const std::u32string& nonterminalName_, const std::vector<NonterminalInfo>& nonterminalInfos_, soulng::codedom::TypeId* returnType_);
    void Visit(soulng::codedom::ReturnStatement& object) override;
    void Visit(soulng::codedom::IdExpr& object);
private:
    bool valueOfPtrType;
    std::u32string nonterminalName;
    std::vector<NonterminalInfo> nonterminalInfos;
    std::vector<int> nonterminalCounts;
    soulng::codedom::TypeId* returnType;
};

} } // namespae soulng::parsergen

#endif // SOULNG_PARSERGEN_SUCCESS_CODE_MODIFY_VISITOR_INCLUDED
