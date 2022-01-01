// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/CodeEvaluationVisitor.hpp>
#include <soulng/cppcode/Expression.hpp>

namespace soulng { namespace spg {

CodeEvaluationVisitor::CodeEvaluationVisitor() : hasReturn(false), hasPass(false), hasSpan(false), hasSourcePos(false)
{
}

void CodeEvaluationVisitor::Visit(soulng::cppcode::ReturnStatement& object)
{
    hasReturn = true;
}

void CodeEvaluationVisitor::Visit(soulng::cppcode::IdExpr& object)
{
    if (object.Name() == U"pass")
    {
        hasPass = true;
    }
    else if (object.Name() == U"span")
    {
        hasSpan = true;
    }
    else if (object.Name() == U"sourcePos")
    {
        hasSourcePos = true;
    }
}

} } // namespae soulng::spg
