// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsergen/CodeEvaluationVisitor.hpp>
#include <soulng/codedom/Expression.hpp>

namespace soulng { namespace parsergen {

CodeEvaluationVisitor::CodeEvaluationVisitor() : hasReturn(false), hasPass(false), hasSpan(false)
{
}

void CodeEvaluationVisitor::Visit(soulng::codedom::ReturnStatement& object)
{
    hasReturn = true;
}

void CodeEvaluationVisitor::Visit(soulng::codedom::IdExpr& object)
{
    if (object.Name() == U"pass")
    {
        hasPass = true;
    }
    else if (object.Name() == U"span")
    {
        hasSpan = true;
    }
}

} } // namespae soulng::parsergen
