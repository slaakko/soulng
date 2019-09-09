// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/CodeModifyVisitor.hpp>
#include <soulng/cppcode/Expression.hpp>
#include <soulng/cppcode/Statement.hpp>
#include <soulng/cppcode/Literal.hpp>

namespace soulng { namespace spg {

CodeModifyVisitor::CodeModifyVisitor(bool valueOfPtrType_, const std::u32string& nonterminalName_, const std::vector<NonterminalInfo>& nonterminalInfos_,
    soulng::cppcode::TypeId* returnType_) : valueOfPtrType(valueOfPtrType_), nonterminalName(nonterminalName_), nonterminalInfos(nonterminalInfos_), returnType(returnType_)
{
}

void CodeModifyVisitor::Visit(soulng::cppcode::ReturnStatement& object)
{
    std::vector<soulng::cppcode::CppObject*> matchArgs;
    matchArgs.push_back(new soulng::cppcode::Literal(U"true"));
    soulng::cppcode::CppObject* value = object.GetExpression();
    if (!valueOfPtrType)
    {
        soulng::cppcode::TypeId* typeId = new soulng::cppcode::TypeId();
        typeId->Add(new soulng::cppcode::TypeSpecifier(U"soulng::parser::Value<" + returnType->ToString() + U">"));
        soulng::cppcode::NewExpr* newExpr = new soulng::cppcode::NewExpr(false);
        newExpr->SetTypeId(typeId);
        newExpr->BeginAddInitializer();
        newExpr->AddExpr(value);
        newExpr->EndAddInitializer();
        value = newExpr;
    }
    matchArgs.push_back(value);
    soulng::cppcode::InvokeExpr* invokeExpr = new soulng::cppcode::InvokeExpr(new soulng::cppcode::IdExpr(U"soulng::parser::Match"));
    for (const auto& arg : matchArgs)
    {
        invokeExpr->AddExpr(arg);
    }
    object.SetExpression(invokeExpr);
}

void CodeModifyVisitor::Visit(soulng::cppcode::IdExpr& object)
{
    for (auto& info : nonterminalInfos)
    {
        if (object.Name() == info.name)
        {
            if (info.ptrType)
            {
                object.SetName(info.name + U".release()");
            }
            else
            {
                object.SetName(info.name + U"->value");
            }
        }
    }
}

} } // namespae soulng::spg
