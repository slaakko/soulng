// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_PARSERGEN_HAS_PASS_VISITOR_INCLUDED
#define SOULNG_PARSERGEN_HAS_PASS_VISITOR_INCLUDED
#include <soulng/codedom/Visitor.hpp>

namespace soulng {  namespace parsergen {

class CodeEvaluationVisitor : public soulng::codedom::Visitor
{
public:
    CodeEvaluationVisitor();
    bool HasReturn() const { return hasReturn; }
    bool HasPass() const { return hasPass; }
    bool HasSpan() const { return hasSpan; }
    void Visit(soulng::codedom::ReturnStatement& object) override;
    void Visit(soulng::codedom::IdExpr& object) override;
private:
    bool hasReturn;
    bool hasPass;
    bool hasSpan;
};

} } // namespae soulng::parsergen

#endif // SOULNG_PARSERGEN_HAS_PASS_VISITOR_INCLUDED
