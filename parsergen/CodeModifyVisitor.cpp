// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/parsergen/CodeModifyVisitor.hpp>
#include <soulng/codedom/Expression.hpp>
#include <soulng/codedom/Statement.hpp>
#include <soulng/codedom/Literal.hpp>

namespace soulng { namespace parsergen {

CodeModifyVisitor::CodeModifyVisitor(bool valueOfPtrType_, const std::u32string& nonterminalName_, const std::vector<NonterminalInfo>& nonterminalInfos_,
    soulng::codedom::TypeId* returnType_) :  valueOfPtrType(valueOfPtrType_), nonterminalName(nonterminalName_), nonterminalInfos(nonterminalInfos_), returnType(returnType_)
{
}

void CodeModifyVisitor::Visit(soulng::codedom::ReturnStatement& object)
{
    std::vector<soulng::codedom::CppObject*> matchArgs;
    matchArgs.push_back(new soulng::codedom::Literal(U"true"));
    soulng::codedom::CppObject* value = object.GetExpression();
    if (!valueOfPtrType)
    {
        soulng::codedom::TypeId* typeId = new soulng::codedom::TypeId();
        typeId->Add(new soulng::codedom::TypeSpecifier(U"soulng::parser::Value<" + returnType->Str() + U">"));
        value = new soulng::codedom::NewExpr(false, std::vector<::soulng::codedom::CppObject*>(), typeId, false, std::vector<soulng::codedom::CppObject*>(1, value));
    }
    matchArgs.push_back(value);
    object.SetExpression(new soulng::codedom::InvokeExpr(new soulng::codedom::IdExpr(U"soulng::parser::Match"), matchArgs));
}

void CodeModifyVisitor::Visit(soulng::codedom::IdExpr& object)
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

} } // namespae soulng::parsergen
