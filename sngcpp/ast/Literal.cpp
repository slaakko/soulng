// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/Literal.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace ast {

std::u32string ToString(Suffix suffix)
{
    std::u32string s;
    if ((suffix & Suffix::u) != Suffix::none)
    {
        s.append(U"u");
    }
    if ((suffix & Suffix::f) != Suffix::none)
    {
        s.append(U"f");
    }
    if ((suffix & Suffix::l) != Suffix::none)
    {
        s.append(U"l");
    }
    if ((suffix & Suffix::ll) != Suffix::none)
    {
        s.append(U"ll");
    }
    return s;
}

LiteralNode::LiteralNode(const Span& span_, const std::u32string& rep_) : Node(span_), rep(rep_)
{
}

FloatingLiteralNode::FloatingLiteralNode(const Span& span_, double value_, Suffix suffix_, const std::u32string& rep_) : LiteralNode(span_, rep_), value(value_), suffix(suffix_)
{
}

void FloatingLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

IntegerLiteralNode::IntegerLiteralNode(const Span& span_, uint64_t value_, Suffix suffix_, Base base_, const std::u32string& rep_) : 
    LiteralNode(span_, rep_), value(value_), suffix(suffix_), base(base_)
{
}

void IntegerLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

CharacterLiteralNode::CharacterLiteralNode(const Span& span_, char32_t prefix_, const std::u32string& chars_, const std::u32string& rep_) : 
    LiteralNode(span_, rep_), prefix(prefix_), chars(chars_)
{
}

void CharacterLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

StringLiteralNode::StringLiteralNode(const Span& span_, const std::u32string& encodingPrefix_, const std::u32string& chars_, const std::u32string& rep_) :
    LiteralNode(span_, rep_), encodingPrefix(encodingPrefix_), chars(chars_)
{
}

void StringLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

BooleanLiteralNode::BooleanLiteralNode(const Span& span_, bool value_, const std::u32string& rep_) : LiteralNode(span_, rep_), value(value_)
{
}

void BooleanLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

NullPtrLiteralNode::NullPtrLiteralNode(const Span& span_, const std::u32string& rep_) : LiteralNode(span_, rep_)
{
}

void NullPtrLiteralNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
