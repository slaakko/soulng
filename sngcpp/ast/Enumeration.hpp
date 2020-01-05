// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_ENUMERATION_INCLUDED
#define SNGCPP_AST_ENUMERATION_INCLUDED
#include <sngcpp/ast/Node.hpp>
#include <string>

namespace sngcpp { namespace ast {

enum class EnumKey : uint8_t
{
    enum_, enumClass_, enumStruct_
};

SNGCPP_AST_API std::u32string ToString(EnumKey enumKey);

class SNGCPP_AST_API EnumTypeNode : public Node
{
public:
    EnumTypeNode();
    EnumTypeNode(const Span& span_, EnumKey enumKey_, Node* enumName_, Node* enumBase_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    void AddEnumerator(const Span& span_, Node* enumerator_);
    EnumKey GetEnumKey() const { return enumKey; }
    Node* EnumName() { return enumName.get(); }
    Node* EnumBase() { return enumBase.get(); }
    Node* Enumerators() { return enumerators.get(); }
    void SetOpenBraceSpan(const Span& openBraceSpan_) { openBraceSpan = openBraceSpan_; }
    const Span& OpenBraceSpan() const { return openBraceSpan; }
    void SetCloseBraceSpan(const Span& closeBraceSpan_) { closeBraceSpan = closeBraceSpan_; }
    const Span& CloseBraceSpan() const { return closeBraceSpan; }
private:
    EnumKey enumKey;
    std::unique_ptr<Node> enumName;
    std::unique_ptr<Node> enumBase;
    std::unique_ptr<Node> enumerators;
    Span openBraceSpan;
    Span closeBraceSpan;
};

class SNGCPP_AST_API EnumeratorNode : public Node
{
public:
    EnumeratorNode();
    EnumeratorNode(const Span& span_, const std::u32string& enumerator_, Node* value_, const std::u32string& valueStr_);
    void Accept(Visitor& visitor) override;
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    const std::u32string& Enumerator() const { return enumerator; }
    Node* Value() { return value.get(); }
    const std::u32string& ValueStr() const { return valueStr; }
    void SetAssignmentSignSpan(const Span& assignmentSignSpan_) { assignmentSignSpan = assignmentSignSpan_; }
    const Span& AssignmentSignSpan() const { return assignmentSignSpan; }
private:
    std::u32string enumerator;
    std::unique_ptr<Node> value;
    std::u32string valueStr;
    Span assignmentSignSpan;
};

class SNGCPP_AST_API EnumeratorSequenceNode : public BinaryNode
{
public:
    EnumeratorSequenceNode();
    EnumeratorSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_ENUMERATION_INCLUDED
