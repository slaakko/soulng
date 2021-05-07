// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/DeclarationProcessor.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Declaration.hpp>
#include <sngcpp20/ast/Class.hpp>
#include <sngcpp20/ast/SimpleType.hpp>
#include <stdexcept>

namespace sngcpp::symbols {

class DeclarationProcessorVisitor : public DefaultVisitor
{
public:
    DeclarationProcessorVisitor(Context* context_);
    DeclarationFlags Flags() const { return flags; }
    void Visit(StaticNode& node) override;
    void Visit(ThreadLocalNode& node) override;
    void Visit(ExternNode& node) override;
    void Visit(MutableNode& node) override;
    void Visit(VirtualNode& node) override;
    void Visit(ExplicitNode& node) override;
    void Visit(ConditionalExplicitNode& node) override;
    void Visit(InlineNode& node) override;
    void Visit(FriendNode& node) override;
    void Visit(TypedefNode& node) override;
    void Visit(ConstExprNode& node) override;
    void Visit(ConstEvalNode& node) override;
    void Visit(ConstInitNode& node) override;

    void Visit(CharNode& node) override;
    void Visit(Char8Node& node) override;
    void Visit(Char16Node& node) override;
    void Visit(Char32Node& node) override;
    void Visit(WCharNode& node) override;
    void Visit(BoolNode& node) override;
    void Visit(ShortNode& node) override;
    void Visit(IntNode& node) override;
    void Visit(LongNode& node) override;
    void Visit(SignedNode& node) override;
    void Visit(UnsignedNode& node) override;
    void Visit(FloatNode& node) override;
    void Visit(DoubleNode& node) override;
    void Visit(VoidNode& node) override;

    void Visit(IdentifierNode& node) override;
    void Visit(QualifiedIdNode& node) override;

    void Visit(PtrDeclaratorNode& node) override;
    void Visit(PtrNode& node) override;
    void Visit(LvalueRefNode& node) override;
    void Visit(RvalueRefNode& node) override;
    void Visit(ConstNode& node) override;
    void Visit(VolatileNode& node) override;

    void Visit(InitDeclaratorNode& node) override;

private:
    Context* context;
    DeclarationFlags flags;
};

DeclarationProcessorVisitor::DeclarationProcessorVisitor(Context* context_) : flags(), context(context_)
{
}

void DeclarationProcessorVisitor::Visit(StaticNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::staticFlag, "static", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::staticFlag;
}

void DeclarationProcessorVisitor::Visit(ThreadLocalNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::threadLocalFlag, "thread_local", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::threadLocalFlag;
}

void DeclarationProcessorVisitor::Visit(ExternNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::externFlag, "extern", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::externFlag;
}

void DeclarationProcessorVisitor::Visit(MutableNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::mutableFlag, "mutable", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::mutableFlag;
}

void DeclarationProcessorVisitor::Visit(VirtualNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::virtualFlag, "virtual", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::virtualFlag;
}

void DeclarationProcessorVisitor::Visit(ExplicitNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::explicitFlag, "explicit", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::explicitFlag;
}

void DeclarationProcessorVisitor::Visit(ConditionalExplicitNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::explicitFlag, "explicit", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::explicitFlag;
    // todo
}

void DeclarationProcessorVisitor::Visit(InlineNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::inlineFlag, "inline", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::inlineFlag;
}

void DeclarationProcessorVisitor::Visit(FriendNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::friendFlag, "friend", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::friendFlag;
}

void DeclarationProcessorVisitor::Visit(TypedefNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::typedefFlag, "typedef", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::typedefFlag;
}

void DeclarationProcessorVisitor::Visit(ConstExprNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::constrExprFlag, "constexpr", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::constrExprFlag;
}

void DeclarationProcessorVisitor::Visit(ConstEvalNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::constEvalFlag, "consteval", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::constEvalFlag;
}

void DeclarationProcessorVisitor::Visit(ConstInitNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::constInitFlag, "constinit", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::constInitFlag;
}

void DeclarationProcessorVisitor::Visit(CharNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::charFlag, "char", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::charFlag;
}

void DeclarationProcessorVisitor::Visit(Char8Node& node) 
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::char8Flag, "char8_t", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::char8Flag;
}

void DeclarationProcessorVisitor::Visit(Char16Node& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::char16Flag, "char16_t", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::char16Flag;
}

void DeclarationProcessorVisitor::Visit(Char32Node& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::char32Flag, "char32_t", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::char32Flag;
}

void DeclarationProcessorVisitor::Visit(WCharNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::wcharFlag, "wchar_t", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::wcharFlag;
}

void DeclarationProcessorVisitor::Visit(BoolNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::boolFlag, "bool", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::boolFlag;
}

void DeclarationProcessorVisitor::Visit(ShortNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::shortFlag, "short", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::shortFlag;
}

void DeclarationProcessorVisitor::Visit(IntNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::intFlag, "int", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::intFlag;
}

void DeclarationProcessorVisitor::Visit(LongNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::longLongFlag, "long long", node.GetSourcePos(), context);
    if ((flags & DeclarationFlags::longFlag) != DeclarationFlags::none)
    {
        flags = flags | DeclarationFlags::longLongFlag;
    }
    else
    {
        flags = flags | DeclarationFlags::longFlag;
    }
}

void DeclarationProcessorVisitor::Visit(SignedNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::signedFlag, "signed", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::signedFlag;
}

void DeclarationProcessorVisitor::Visit(UnsignedNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::unsignedFlag, "unsigned", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::unsignedFlag;
}

void DeclarationProcessorVisitor::Visit(FloatNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::floatFlag, "float", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::floatFlag;
}

void DeclarationProcessorVisitor::Visit(DoubleNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::doubleFlag, "double", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::doubleFlag;
}

void DeclarationProcessorVisitor::Visit(VoidNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::voidFlag, "void", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::voidFlag;
}

void DeclarationProcessorVisitor::Visit(IdentifierNode& node)
{
    // todo
}

void DeclarationProcessorVisitor::Visit(QualifiedIdNode& node)
{
    // todo
}

void DeclarationProcessorVisitor::Visit(InitDeclaratorNode& node)
{
    // todo
}

void DeclarationProcessorVisitor::Visit(PtrDeclaratorNode& node)
{
    // todo
}

void DeclarationProcessorVisitor::Visit(PtrNode& node)
{
    // todo
}

void DeclarationProcessorVisitor::Visit(LvalueRefNode& node)
{
    // todo
}

void DeclarationProcessorVisitor::Visit(RvalueRefNode& node)
{
    // todo
}

void DeclarationProcessorVisitor::Visit(ConstNode& node)
{
    // todo
}

void DeclarationProcessorVisitor::Visit(VolatileNode& node)
{
    // todo
}

void CheckDuplicateSpecifier(DeclarationFlags flags, DeclarationFlags flag, const std::string& specifierStr, const SourcePos& sourcePos, Context* context)
{
    if ((flags & flag) != DeclarationFlags::none)
    {
        throw Exception("duplicate '" + specifierStr + "'", sourcePos, context);
    }
}

void ProcessSimpleDeclaration(Node* declaration, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    declaration->Accept(visitor);
    DeclarationFlags fundamentalTypeFlags = visitor.Flags() & DeclarationFlags::fundamentalTypeFlags;
    if (fundamentalTypeFlags != DeclarationFlags::none)
    {

    }
}

} // sngcpp::symbols
