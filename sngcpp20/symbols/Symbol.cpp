// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/Symbol.hpp>
#include <sngcpp20/symbols/CompoundTypeSymbol.hpp>
#include <sngcpp20/symbols/ContainerSymbol.hpp>
#include <sngcpp20/symbols/TemplateDeclarationSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/Value.hpp>
#include <soulng/util/Unicode.hpp>

namespace sngcpp::symbols {

using namespace soulng::unicode;

std::vector<SymbolGroupKind> SymbolGroupKindstoSymbolGroupKindVec(SymbolGroupKind symbolGroupKinds)
{
    std::vector<SymbolGroupKind> symbolGroupKindVec;
    if ((symbolGroupKinds & SymbolGroupKind::functionSymbolGroup) != SymbolGroupKind::none)
    {
        symbolGroupKindVec.push_back(SymbolGroupKind::functionSymbolGroup);
    }
    if ((symbolGroupKinds & SymbolGroupKind::typeSymbolGroup) != SymbolGroupKind::none)
    {
        symbolGroupKindVec.push_back(SymbolGroupKind::typeSymbolGroup);
    }
    if ((symbolGroupKinds & SymbolGroupKind::variableSymbolGroup) != SymbolGroupKind::none)
    {
        symbolGroupKindVec.push_back(SymbolGroupKind::variableSymbolGroup);
    }
    if ((symbolGroupKinds & SymbolGroupKind::conceptSymbolGroup) != SymbolGroupKind::none)
    {
        symbolGroupKindVec.push_back(SymbolGroupKind::conceptSymbolGroup);
    }
    if ((symbolGroupKinds & SymbolGroupKind::blockSymbolGroup) != SymbolGroupKind::none)
    {
        symbolGroupKindVec.push_back(SymbolGroupKind::blockSymbolGroup);
    }
    return symbolGroupKindVec;
}

Symbol::Symbol(const std::u32string& name_, SymbolKind kind_) : kind(kind_), name(name_), parent(nullptr)
{
}

Symbol::~Symbol()
{
}

std::u32string Symbol::FullName() const
{
    std::u32string fullName;
    if (parent)
    {
        fullName = parent->FullName();
    }
    if (!fullName.empty())
    {
        fullName.append(U"::");
    }
    fullName.append(name);
    return fullName;
}

void Symbol::AddSymbol(Symbol* symbol, SymbolGroupKind symbolGroupKind, const SourcePos& sourcePos, Scope* groupScope, Context* context)
{
    throw Exception("cannot add " + symbol->SymbolKindStr() + " '" + ToUtf8(symbol->FullName()) + "' to " + SymbolKindStr() + " '" + ToUtf8(FullName()), sourcePos, context);
}

void Symbol::RemoveSymbol(Symbol* symbol, SymbolGroupKind symbolGroupKind)
{
    throw std::runtime_error("cannot remove symbol");
}

void Symbol::AddToGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context)
{
}

void Symbol::RemoveFromGroup(Scope* groupScope, const SourcePos& sourcePos, Context* context)
{
}

bool SymbolsEqual(Symbol* left, Symbol* right)
{
    if (left->IsTypeSymbol() && right->IsTypeSymbol())
    {
        if (left->Kind() == SymbolKind::templateParameterSymbol && right->Kind() == SymbolKind::templateParameterSymbol)
        {
            TemplateParameterSymbol* leftTemplateParam = static_cast<TemplateParameterSymbol*>(left);
            TemplateParameterSymbol* rightTemplateParam = static_cast<TemplateParameterSymbol*>(right);
            return leftTemplateParam->Index() == rightTemplateParam->Index();
        }
        if (left->IsCompoundTypeSymbol() && right->IsCompoundTypeSymbol())
        {
            if (left->Kind() != right->Kind()) return false;
            CompoundTypeSymbol* leftCompound = static_cast<CompoundTypeSymbol*>(left);
            CompoundTypeSymbol* rightCompound = static_cast<CompoundTypeSymbol*>(right);
            return SymbolsEqual(leftCompound->BaseType(), rightCompound->BaseType());
        }
        return left == right;
    }
    else if (left->Kind() == SymbolKind::valueSymbol && right->Kind() == SymbolKind::valueSymbol)
    {
        Value* leftValue = static_cast<Value*>(left);
        Value* rightValue = static_cast<Value*>(right);
        if (leftValue->GetValueKind() != rightValue->GetValueKind())
        {
            return false;
        }
        switch (leftValue->GetValueKind())
        {
            case ValueKind::boolValue:
            {
                BoolValue* leftBool = static_cast<BoolValue*>(leftValue);
                BoolValue* rightBool = static_cast<BoolValue*>(rightValue);
                return leftBool->GetValue() == rightBool->GetValue();
            }
            case ValueKind::integerValue:
            {
                IntegerValue* leftInteger = static_cast<IntegerValue*>(leftValue);
                IntegerValue* rightInteger = static_cast<IntegerValue*>(rightValue);
                return leftInteger->GetValue() == rightInteger->GetValue();
            }
            default:
            {
                return false;
            }
        }
    }
    else
    {
        return left == right;
    }
}

bool SymbolsEqual(const std::vector<Symbol*>& left, const std::vector<Symbol*>& right)
{
    if (left.size() != right.size()) return false;
    int n = left.size();
    for (int i = 0; i < n; ++i)
    {
        if (!SymbolsEqual(left[i], right[i])) return false;
    }
    return true;
}

int Match(const std::vector<Symbol*>& left, const std::vector<Symbol*>& right)
{
    if (left.size() != right.size()) return -1;
    int totalScore = 0;
    int n = left.size();
    for (int i = 0; i < n; ++i)
    {
        int score = Match(left[i], right[i]);
        if (score == -1) return -1;
        totalScore += score;
    }
    return totalScore;
}

int Match(Symbol* left, Symbol* right)
{
    if (SymbolsEqual(left, right)) return 0;
    if (left->IsCompoundTypeSymbol())
    {
        if (right->IsCompoundTypeSymbol())
        {
            if (left->Kind() == right->Kind())
            {
                CompoundTypeSymbol* leftCompound = static_cast<CompoundTypeSymbol*>(left);
                CompoundTypeSymbol* rightCompound = static_cast<CompoundTypeSymbol*>(right);
                return Match(leftCompound->BaseType(), rightCompound->BaseType());
            }
            else
            {
                return -1;
            }
        }
        else if (right->Kind() == SymbolKind::templateParameterSymbol)
        {
            return 2;
        }
    }
    else if (right->Kind() == SymbolKind::templateParameterSymbol)
    {
        return 1;
    }
    return -1;
}

} // sngcpp::symbols
