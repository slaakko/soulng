// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SPG_CODE_EVALUATION_VISITOR_INCLUDED
#define SOULNG_SPG_CODE_EVALUATION_VISITOR_INCLUDED
#include <soulng/cppcode/Visitor.hpp>

namespace soulng { namespace spg {

class CodeEvaluationVisitor : public soulng::cppcode::Visitor
{
public:
    CodeEvaluationVisitor();
    bool HasReturn() const { return hasReturn; }
    bool HasPass() const { return hasPass; }
    bool HasSpan() const { return hasSpan; }
    void Visit(soulng::cppcode::ReturnStatement& object) override;
    void Visit(soulng::cppcode::IdExpr& object) override;
private:
    bool hasReturn;
    bool hasPass;
    bool hasSpan;
};

} } // namespae soulng::spg

#endif // SOULNG_SPG_CODE_EVALUATION_VISITOR_INCLUDED
