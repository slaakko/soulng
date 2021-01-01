// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/CodeModifyVisitor.hpp>
#include <soulng/cppcode/Expression.hpp>
#include <soulng/cppcode/Statement.hpp>
#include <soulng/cppcode/Literal.hpp>

namespace soulng { namespace spg {

CodeModifyVisitor::CodeModifyVisitor(bool valueOfPtrType_, const std::u32string& nonterminalName_, const std::vector<NonterminalInfo>& nonterminalInfos_,
    soulng::cppcode::TypeId* returnType_, bool noParserDebugSupport_, const std::u32string& parserName_) :
    valueOfPtrType(valueOfPtrType_), nonterminalName(nonterminalName_), nonterminalInfos(nonterminalInfos_), returnType(returnType_), noParserDebugSupport(noParserDebugSupport_),
    parserName(parserName_)
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
    if (!noParserDebugSupport)
    {
        soulng::cppcode::Statement* parent = object.Parent();
        soulng::cppcode::CompoundStatement* debugBlock = new soulng::cppcode::CompoundStatement();
        debugBlock->Add(new soulng::cppcode::IfDefStatement(new soulng::cppcode::Literal(U"SOULNG_PARSER_DEBUG_SUPPORT")));
        soulng::cppcode::InvokeExpr* writeSuccessToLogCall = new soulng::cppcode::InvokeExpr(new soulng::cppcode::IdExpr(U"soulng::lexer::WriteSuccessToLog"));
        writeSuccessToLogCall->AddExpr(new soulng::cppcode::IdExpr(U"lexer"));
        writeSuccessToLogCall->AddExpr(new soulng::cppcode::IdExpr(U"parser_debug_match_span"));
        soulng::cppcode::InvokeExpr* parserNameToUtf32 = new soulng::cppcode::InvokeExpr(new soulng::cppcode::IdExpr(U"soulng::unicode::ToUtf32")); 
        parserNameToUtf32->AddExpr(new soulng::cppcode::Literal(U"\"" + parserName + U"\""));
        writeSuccessToLogCall->AddExpr(parserNameToUtf32);
        soulng::cppcode::ExpressionStatement* writeSuccessToLogCallStatement = new soulng::cppcode::ExpressionStatement(writeSuccessToLogCall);
        soulng::cppcode::IfStatement* ifS = new soulng::cppcode::IfStatement(new soulng::cppcode::Literal(U"parser_debug_write_to_log"), writeSuccessToLogCallStatement, nullptr);
        debugBlock->Add(ifS);
        debugBlock->Add(new soulng::cppcode::EndIfStatement(new soulng::cppcode::Literal(U"// SOULNG_PARSER_DEBUG_SUPPORT")));
        debugBlock->Add(&object);
        parent->Replace(&object, debugBlock);
    }
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
