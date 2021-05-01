// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/ast/Literal.hpp>

namespace sngcpp::ast {

LiteralNode::LiteralNode(NodeKind kind_, const SourcePos& sourcePos_, const std::u32string& rep_) : Node(kind_, sourcePos_), rep(rep_)
{
}

IntegerLiteralNode::IntegerLiteralNode(const SourcePos& sourcePos_, uint64_t value_, Suffix suffix_, Base base_, const std::u32string& rep_) : 
    LiteralNode(NodeKind::integerLiteralNode, sourcePos_, rep_), value(value_), suffix(suffix_), base(base_)
{
}

FloatingLiteralNode::FloatingLiteralNode(const SourcePos& sourcePos_, double value_, Suffix suffix_, Base base_, const std::u32string& rep_) :
    LiteralNode(NodeKind::floatingLiteralNode, sourcePos_, rep_), value(value_), suffix(suffix_), base(base_)
{
}

CharacterLiteralNode::CharacterLiteralNode(const SourcePos& sourcePos_, char32_t value_, EncodingPrefix encodingPrefix_, const std::u32string& rep_) : 
    LiteralNode(NodeKind::characterLiteralNode, sourcePos_, rep_), value(value_), encodingPrefix(encodingPrefix_)
{
}

StringLiteralNode::StringLiteralNode(const SourcePos& sourcePos_, const std::u32string& value_, EncodingPrefix encodingPrefix_, const std::u32string& rep_) : 
    LiteralNode(NodeKind::stringLiteralNode, sourcePos_, rep_), value(value_), encodingPrefix(encodingPrefix_)
{
}

BooleanLiteralNode::BooleanLiteralNode(const SourcePos& sourcePos_, bool value_, const std::u32string& rep_) :
    LiteralNode(NodeKind::booleanLiteralNode, sourcePos_, rep_), value(value_)
{
}

NullPtrLiteralNode::NullPtrLiteralNode(const SourcePos& sourcePos_, const std::u32string& rep_) : 
    LiteralNode(NodeKind::nullPtrLiteralNode, sourcePos_, rep_)
{
}

UserDefinedLiteraNode::UserDefinedLiteraNode(const SourcePos& sourcePos_, Node* literalNode_, Node* udSuffix_) :
    BinaryNode(NodeKind::userDefinedLiteralNode, sourcePos_, literalNode_, udSuffix_)
{
}

LiteralOperatorIdNode::LiteralOperatorIdNode(const SourcePos& sourcePos_, Node* id_) :
    UnaryNode(NodeKind::literalOperatorIdNode, sourcePos_, id_)
{
}

} // namespace sngcpp::ast
