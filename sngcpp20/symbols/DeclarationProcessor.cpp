// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/DeclarationProcessor.hpp>
#include <sngcpp20/symbols/AliasTypeSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/FundamentalTypeSymbol.hpp>
#include <sngcpp20/symbols/ScopeResolver.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Declaration.hpp>
#include <sngcpp20/ast/Class.hpp>
#include <sngcpp20/ast/SimpleType.hpp>
#include <sngcpp20/ast/Qualifier.hpp>
#include <soulng/util/Unicode.hpp>
#include <stdexcept>

namespace sngcpp::symbols {

using namespace soulng::unicode;

class DeclarationProcessorVisitor : public DefaultVisitor
{
public:
    enum class Stage
    {
        processDeclSpecifiers, processInitDeclarators
    };
    DeclarationProcessorVisitor(Context* context_);
    void Visit(SimpleDeclarationNode& node) override;
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

    void Visit(PtrNode& node) override;
    void Visit(LvalueRefNode& node) override;
    void Visit(RvalueRefNode& node) override;
    void Visit(ConstNode& node) override;
    void Visit(VolatileNode& node) override;

    void Visit(InitDeclaratorListNode& node);
    void Visit(InitDeclaratorNode& node) override;

    void Visit(FunctionDeclaratorNode& node) override;

private:
    void ProcessDeclSpecifiers(Node* declSpecifiers);
    void ProcesInitDeclarators(Node* initDeclaratorList);
    void AddSymbol();
    void AddTypedef();
    Stage stage;
    DeclarationFlags flags;
    Context* context;
    TypeSymbol* baseTypeSymbol;
    TypeSymbol* type;
    Node* idNode;
    Scope* scope;
    Node* typedefNode;
};

DeclarationProcessorVisitor::DeclarationProcessorVisitor(Context* context_) : 
    stage(Stage::processDeclSpecifiers), flags(), context(context_), baseTypeSymbol(nullptr), type(nullptr), idNode(nullptr), scope(nullptr), typedefNode(nullptr)
{
}

void DeclarationProcessorVisitor::Visit(SimpleDeclarationNode& node)
{
    ProcessDeclSpecifiers(node.DeclarationSpecifiers());
    ProcesInitDeclarators(node.InitDeclaratorList());
}

void DeclarationProcessorVisitor::ProcessDeclSpecifiers(Node* declSpecifiers)
{
    stage = Stage::processDeclSpecifiers;
    declSpecifiers->Accept(*this);
    DeclarationFlags fundamentalTypeFlags = flags & DeclarationFlags::fundamentalTypeFlags;
    if (fundamentalTypeFlags != DeclarationFlags::none)
    {
        if (baseTypeSymbol)
        {
            throw Exception("duplicate type symbol in declaration specifier sequence", declSpecifiers->GetSourcePos(), context);
        }
        baseTypeSymbol = GetFundamentalType(fundamentalTypeFlags, declSpecifiers->GetSourcePos(), context);
    }
    else
    {
        if (!baseTypeSymbol)
        {
            throw Exception("declaration specifier sequence does not contain a type symbol", declSpecifiers->GetSourcePos(), context);
        }
    }
    if ((flags & DeclarationFlags::constFlag) != DeclarationFlags::none)
    {
        baseTypeSymbol = context->GetSymbolTable()->MakeConstType(baseTypeSymbol);
    }
    if ((flags & DeclarationFlags::volatileFlag) != DeclarationFlags::none)
    {
        baseTypeSymbol = context->GetSymbolTable()->MakeVolatileType(baseTypeSymbol);
    }
    if ((flags & DeclarationFlags::typedefFlag) != DeclarationFlags::none)
    {
        if ((flags & DeclarationFlags::typedefFlagMask) != DeclarationFlags::none)
        {
            throw Exception("invalid declaration specifier sequence: typedef cannot be combined with these specifiers", declSpecifiers->GetSourcePos(), context);
        }
    }
}

void DeclarationProcessorVisitor::ProcesInitDeclarators(Node* initDeclaratorList)
{
    stage = Stage::processInitDeclarators;
    flags = flags & ~DeclarationFlags::cvQualifierFlagMask;
    initDeclaratorList->Accept(*this);
}

void DeclarationProcessorVisitor::AddSymbol()
{
    if ((flags & DeclarationFlags::typedefFlag) != DeclarationFlags::none)
    {
        AddTypedef();
    }
}

void DeclarationProcessorVisitor::AddTypedef()
{
    if (!idNode)
    {
        throw Exception("no declarators specified for a typedef", typedefNode->GetSourcePos(), context);
    }
    Symbol* typedefSymbol = new AliasTypeSymbol(idNode->Str(), type); 
    scope->AddSymbol(typedefSymbol, typedefNode->GetSourcePos(), context);
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
    typedefNode = &node;
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
    if (stage == Stage::processDeclSpecifiers)
    {
        Symbol* symbol = context->GetSymbolTable()->GetSymbolNothrow(&node);
        if (symbol)
        {
            if (symbol->IsTypeSymbol())
            {
                if (baseTypeSymbol)
                {
                    throw Exception("duplicate type symbol in declaration specifier sequence", node.GetSourcePos(), context);
                }
                else
                {
                    baseTypeSymbol = static_cast<TypeSymbol*>(symbol);
                }
            }
            else
            {
                throw Exception("symbol '" + ToUtf8(node.Str()) + "' does not denote a type", node.GetSourcePos(), context);
            }
        }
        else
        {
            throw Exception("symbol '" + ToUtf8(node.Str()) + "' not found", node.GetSourcePos(), context);
        }
    }
    else if (stage == Stage::processInitDeclarators)
    {
        if (idNode)
        {
            throw Exception("duplicate identifier in declarator list", node.GetSourcePos(), context);
        }
        idNode = &node;
    }
}

void DeclarationProcessorVisitor::Visit(QualifiedIdNode& node)
{
    scope = ResolveScope(node.Left(), context);
    node.Right()->Accept(*this);
}

void DeclarationProcessorVisitor::Visit(InitDeclaratorListNode& node)
{
    for (Node* item : node.Items())
    {
        type = baseTypeSymbol;
        idNode = nullptr;
        scope = context->GetSymbolTable()->CurrentScope();
        item->Accept(*this);
        AddSymbol();
    }
}

void DeclarationProcessorVisitor::Visit(InitDeclaratorNode& node)
{
    // todo
}

void DeclarationProcessorVisitor::Visit(PtrNode& node)
{
    type = context->GetSymbolTable()->MakePointerType(type);
}

void DeclarationProcessorVisitor::Visit(LvalueRefNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::lvalueRefFlag, "&", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::lvalueRefFlag;
    type = context->GetSymbolTable()->MakeLvalueRefType(type);
}

void DeclarationProcessorVisitor::Visit(RvalueRefNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::rvalueRefFlag, "&&", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::rvalueRefFlag;
    type = context->GetSymbolTable()->MakeRvalueRefType(type);
}

void DeclarationProcessorVisitor::Visit(ConstNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::constFlag, "const", node.GetSourcePos(), context);
    if (stage == Stage::processDeclSpecifiers)
    {
        flags = flags | DeclarationFlags::constFlag;
    }
}

void DeclarationProcessorVisitor::Visit(VolatileNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::volatileFlag, "volatile", node.GetSourcePos(), context);
    if (stage == Stage::processDeclSpecifiers)
    {
        flags = flags | DeclarationFlags::volatileFlag;
    }
}

void DeclarationProcessorVisitor::Visit(FunctionDeclaratorNode& node)
{
    node.Child()->Accept(*this);
    if (idNode && scope)
    {
        context->GetSymbolTable()->BeginScope(*scope);
        context->GetSymbolTable()->BeginFunction(idNode, type, context);
        node.Params()->Accept(*this);
        context->GetSymbolTable()->EndFunction();
        context->GetSymbolTable()->EndScope();
    }
    else
    {
        // todo
    }
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
}

} // sngcpp::symbols
