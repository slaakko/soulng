// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Enumeration.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace ast {

std::u32string ToString(EnumKey enumKey)
{
    switch (enumKey)
    {
        case EnumKey::enumClass_: return U"enum class";
        case EnumKey::enumStruct_: return U"enum struct";
        case EnumKey::enum_: return U"enum";
    }
    return std::u32string();
}

EnumTypeNode::EnumTypeNode(const Span& span_, EnumKey enumKey_, Node* enumName_, Node* enumBase_) : Node(span_), enumKey(enumKey_), enumName(enumName_), enumBase(enumBase_)
{
}

void EnumTypeNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void EnumTypeNode::AddEnumerator(const Span& span_, Node* enumerator_)
{
    if (enumerators)
    {
        enumerators.reset(new EnumeratorSequenceNode(span_, enumerators.release(), enumerator_));
    }
    else
    {
        enumerators.reset(enumerator_);
    }
}

EnumeratorNode::EnumeratorNode(const Span& span_, const std::u32string& enumerator_, Node* value_, const std::u32string& valueStr_) : 
    Node(span_), enumerator(enumerator_), value(value_), valueStr(valueStr_)
{
}

void EnumeratorNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

EnumeratorSequenceNode::EnumeratorSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void EnumeratorSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
