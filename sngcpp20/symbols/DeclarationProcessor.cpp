
// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/DeclarationProcessor.hpp>
#include <sngcpp20/symbols/AliasTypeSymbol.hpp>
#include <sngcpp20/symbols/FunctionTypeSymbol.hpp>
#include <sngcpp20/symbols/Class.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/EnumTypeSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/FundamentalTypeSymbol.hpp>
#include <sngcpp20/symbols/ScopeResolver.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Declaration.hpp>
#include <sngcpp20/ast/Class.hpp>
#include <sngcpp20/ast/Enum.hpp>
#include <sngcpp20/ast/Literal.hpp>
#include <sngcpp20/ast/SimpleType.hpp>
#include <sngcpp20/ast/Qualifier.hpp>
#include <sngcpp20/ast/Type.hpp>
#include <soulng/util/Unicode.hpp>
#include <stdexcept>

namespace sngcpp::symbols {

using namespace soulng::unicode;

enum class DeclarationKind : int
{
    none, 
    classDeclaration = 1 << 0, 
    enumDeclaration = 1 << 1,
    aliasDeclararation = 1 << 2,
    objectDeclaration = 1 << 3, 
    functionDeclaration = 1 << 4, 
};

inline DeclarationKind operator|(DeclarationKind left, DeclarationKind right)
{
    return DeclarationKind(int(left) | int(right));
}

inline DeclarationKind operator&(DeclarationKind left, DeclarationKind right)
{
    return DeclarationKind(int(left) & int(right));
}

inline DeclarationKind operator~(DeclarationKind operand)
{
    return DeclarationKind(~int(operand));
}

struct Declaration
{
    Declaration(DeclarationKind kind_, DeclarationFlags flags_, TypeSymbol* type_, Node* idNode_, Scope* scope_, Node* node_, std::vector<std::unique_ptr<ParameterSymbol>>&& parameters_);
    DeclarationKind kind;
    DeclarationFlags flags;
    TypeSymbol* type;
    Node* idNode;
    Scope* scope;
    Node* node;
    std::vector<std::unique_ptr<ParameterSymbol>> parameters;
};

Declaration::Declaration(DeclarationKind kind_, DeclarationFlags flags_, TypeSymbol* type_, Node* idNode_, Scope* scope_, Node* node_, std::vector<std::unique_ptr<ParameterSymbol>>&& parameters_) :
    kind(kind_), flags(flags_), type(type_), idNode(idNode_), scope(scope_), node(node_), parameters(std::move(parameters_))
{
}

class DeclarationProcessorVisitor : public DefaultVisitor
{
public:
    enum class Stage
    {
        processDeclSpecifiers, processDeclarators, processInitializer
    };
    DeclarationProcessorVisitor(Context* context_);

    Declaration GetDeclaration();
    std::vector<Declaration> GetDeclarations();

    void Visit(SimpleDeclarationNode& node) override;

    void Visit(MemberDeclarationNode& node) override;

    void Visit(TypeSpecifierSequenceNode& node) override;
    void Visit(DefiningTypeIdNode& node) override;

    void Visit(ClassSpecifierNode& node);
    void Visit(EnumSpecifierNode& node);

    void Visit(AliasDeclarationNode& node);

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
    void Visit(AbstractDeclaratorNode& node) override;

    void Visit(PtrNode& node) override;
    void Visit(LvalueRefNode& node) override;
    void Visit(RvalueRefNode& node) override;
    void Visit(ConstNode& node) override;
    void Visit(VolatileNode& node) override;

    void Visit(InitDeclaratorListNode& node) override;
    void Visit(InitDeclaratorNode& node) override;
    void Visit(MemberDeclaratorListNode& node) override;

    void Visit(FunctionDeclaratorNode& node) override;
    void Visit(ArrayDeclaratorNode& node) override;
    void Visit(IntegerLiteralNode& node) override;
    void Visit(ParenthesizedDeclaratorNode& node) override;
    void Visit(ParameterNode& node) override;
    void Visit(PlaceholderTypeSpecifierNode& node) override;

    void ProcessDeclSpecifiers(Node* declSpecifiers);
    void ProcessDeclarator(Node* declarator);
    void ResolveBaseType(Node* node);
    TypeSymbol* GetBaseType() const { return baseTypeSymbol; }
    void SetBaseType(TypeSymbol* baseType_) { baseTypeSymbol = baseType_; }
private:
    void ProcesInitDeclarators(Node* initDeclaratorList);
    void ProcessMemberDeclarators(Node* memberDeclarators);
    DeclarationKind kind;
    Stage stage;
    DeclarationFlags flags;
    Context* context;
    TypeSymbol* baseTypeSymbol;
    TypeSymbol* type;
    TypeSymbol* functionType;
    Node* idNode;
    Scope* scope;
    Node* node;
    uint64_t dimension;
    std::vector<std::unique_ptr<ParameterSymbol>> parameters;
    std::vector<Declaration> declarations;
};

DeclarationProcessorVisitor::DeclarationProcessorVisitor(Context* context_) : 
    kind(DeclarationKind::none), stage(Stage::processDeclSpecifiers), flags(), context(context_), baseTypeSymbol(nullptr), type(nullptr), functionType(nullptr), idNode(nullptr),
    scope(context->GetSymbolTable()->CurrentScope()), node(nullptr), dimension(0)
{
}

Declaration DeclarationProcessorVisitor::GetDeclaration()
{
    if (kind == DeclarationKind::none)
    {
        kind = DeclarationKind::objectDeclaration;
    }
    return Declaration(kind, flags, type, idNode, scope, node, std::move(parameters));
}

std::vector<Declaration> DeclarationProcessorVisitor::GetDeclarations()
{
    return std::move(declarations);
}

void DeclarationProcessorVisitor::Visit(SimpleDeclarationNode& node)
{
    kind = DeclarationKind::none;
    this->node = &node;
    ProcessDeclSpecifiers(node.DeclarationSpecifiers());
    if (node.InitDeclaratorList())
    {
        ProcesInitDeclarators(node.InitDeclaratorList());
    }
    else
    {
        type = baseTypeSymbol;
        idNode = nullptr;
        scope = context->GetSymbolTable()->CurrentScope();
        declarations.push_back(GetDeclaration());
    }
}

void DeclarationProcessorVisitor::Visit(MemberDeclarationNode& node)
{
    kind = DeclarationKind::none;
    this->node = &node;
    ProcessDeclSpecifiers(node.DeclSpecifiers());
    ProcessMemberDeclarators(node.MemberDeclarators());
}

void DeclarationProcessorVisitor::Visit(TypeSpecifierSequenceNode& node)
{
    if (!this->node)
    {
        this->node = &node;
    }
    stage = Stage::processDeclSpecifiers;
    VisitSequenceContent(node);
    ResolveBaseType(&node);
}

void DeclarationProcessorVisitor::Visit(DefiningTypeIdNode& node)
{
    node.DefiningTypeSpecifiers()->Accept(*this);
    ResolveBaseType(&node);
    type = baseTypeSymbol;
    node.AbstractDeclarator()->Accept(*this);
}

void DeclarationProcessorVisitor::Visit(ClassSpecifierNode& node)
{
    kind = kind | DeclarationKind::classDeclaration;
    Symbol* symbol = context->GetSymbolTable()->GetSymbol(&node);
    if (symbol->IsClassTypeSymbol())
    {
        baseTypeSymbol = static_cast<TypeSymbol*>(symbol);
    }
}

void DeclarationProcessorVisitor::Visit(EnumSpecifierNode& node)
{
    kind = kind | DeclarationKind::enumDeclaration;
    Symbol* symbol = context->GetSymbolTable()->GetSymbol(&node);
    if (symbol->IsEnumTypeSymbol())
    {
        baseTypeSymbol = static_cast<TypeSymbol*>(symbol);
    }
}

void DeclarationProcessorVisitor::Visit(AliasDeclarationNode& node)
{
    kind = kind | DeclarationKind::aliasDeclararation;
    if (!this->node)
    {
        this->node = &node;
    }
    stage = Stage::processDeclarators;
    node.Identifier()->Accept(*this);
    stage = Stage::processDeclSpecifiers;;
    node.DefiningTypeId()->Accept(*this);
}

void DeclarationProcessorVisitor::ProcessDeclSpecifiers(Node* declSpecifiers)
{
    if (!node)
    {
        node = declSpecifiers;
    }
    stage = Stage::processDeclSpecifiers;
    declSpecifiers->Accept(*this);
}

void DeclarationProcessorVisitor::ResolveBaseType(Node* node)
{
    DeclarationFlags fundamentalTypeFlags = flags & DeclarationFlags::fundamentalTypeFlags;
    if (fundamentalTypeFlags != DeclarationFlags::none)
    {
        if (baseTypeSymbol)
        {
            throw Exception("duplicate type symbol in declaration specifier sequence", node->GetSourcePos(), context);
        }
        baseTypeSymbol = GetFundamentalType(fundamentalTypeFlags, node->GetSourcePos(), context);
    }
    else
    {
        if (!baseTypeSymbol)
        {
            throw Exception("declaration specifier sequence does not contain a type symbol", node->GetSourcePos(), context);
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
            throw Exception("invalid declaration specifier sequence: typedef cannot be combined with these specifiers", node->GetSourcePos(), context);
        }
    }
}

void DeclarationProcessorVisitor::ProcessDeclarator(Node* declarator)
{
    if (!node)
    {
        node = declarator;
    }
    stage = Stage::processDeclarators;
    flags = flags & ~DeclarationFlags::cvQualifierFlagMask;
    type = baseTypeSymbol;
    idNode = nullptr;
    declarator->Accept(*this);
}

void DeclarationProcessorVisitor::ProcesInitDeclarators(Node* initDeclaratorList)
{
    stage = Stage::processDeclarators;
    flags = flags & ~DeclarationFlags::cvQualifierFlagMask;
    initDeclaratorList->Accept(*this);
}

void DeclarationProcessorVisitor::ProcessMemberDeclarators(Node* memberDeclarators)
{
    stage = Stage::processDeclarators;
    flags = flags & ~DeclarationFlags::cvQualifierFlagMask;
    memberDeclarators->Accept(*this);
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
    this->node = &node;
    kind = kind | DeclarationKind::aliasDeclararation;
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
    else if (stage == Stage::processDeclarators)
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

void DeclarationProcessorVisitor::Visit(AbstractDeclaratorNode& node)
{
    if (!idNode)
    {
        idNode = &node;
    }
}

void DeclarationProcessorVisitor::Visit(InitDeclaratorListNode& node)
{
    for (Node* item : node.Items())
    {
        type = baseTypeSymbol;
        idNode = nullptr;
        scope = context->GetSymbolTable()->CurrentScope();
        item->Accept(*this);
        declarations.push_back(GetDeclaration());
    }
}

void DeclarationProcessorVisitor::Visit(InitDeclaratorNode& node)
{
    stage = Stage::processDeclarators;
    node.Left()->Accept(*this);
    stage = Stage::processInitializer;
    node.Right()->Accept(*this);
    stage = Stage::processDeclarators;
}

void DeclarationProcessorVisitor::Visit(MemberDeclaratorListNode& node)
{
    for (Node* item : node.Items())
    {
        type = baseTypeSymbol;
        idNode = nullptr;
        scope = context->GetSymbolTable()->CurrentScope();
        item->Accept(*this);
        declarations.push_back(GetDeclaration());
    }
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
    else if (stage == Stage::processDeclarators)
    {
        type = context->GetSymbolTable()->MakeConstType(type);
    }
}

void DeclarationProcessorVisitor::Visit(VolatileNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::volatileFlag, "volatile", node.GetSourcePos(), context);
    if (stage == Stage::processDeclSpecifiers)
    {
        flags = flags | DeclarationFlags::volatileFlag;
    }
    else if (stage == Stage::processDeclarators)
    {
        type = context->GetSymbolTable()->MakeVolatileType(type);
    }
}

void DeclarationProcessorVisitor::Visit(FunctionDeclaratorNode& node)
{
    if (kind == DeclarationKind::none)
    {
        kind = DeclarationKind::functionDeclaration;
    }
    parameters.clear();
    node.Params()->Accept(*this);
    std::vector<TypeSymbol*> parameterTypes;
    for (const auto& param : parameters)
    {
        parameterTypes.push_back(param->Type());
    }
    type = context->GetSymbolTable()->MakeFunctionType(FunctionTypeKey(type, parameterTypes));
    node.Child()->Accept(*this);
}

void DeclarationProcessorVisitor::Visit(ArrayDeclaratorNode& node)
{
    dimension = 0;
    if (node.Dimension())
    {
        node.Dimension()->Accept(*this);
    }
    type = context->GetSymbolTable()->MakeArrayType(ArrayTypeKey(type, dimension));
    node.Child()->Accept(*this);
}

void DeclarationProcessorVisitor::Visit(IntegerLiteralNode& node)
{
    dimension = node.Value();
}

void DeclarationProcessorVisitor::Visit(ParenthesizedDeclaratorNode& node)
{
    ProcessParenthesizedDeclarator(node.Declarator(), type, context);
}

void DeclarationProcessorVisitor::Visit(ParameterNode& node)
{
    ParameterSymbol* parameterSymbol = ProcessParameter(&node, context);
    parameters.push_back(std::unique_ptr<ParameterSymbol>(parameterSymbol));
}

void DeclarationProcessorVisitor::Visit(PlaceholderTypeSpecifierNode& node)
{
    CheckDuplicateSpecifier(flags, DeclarationFlags::autoFlag, "auto", node.GetSourcePos(), context);
    flags = flags | DeclarationFlags::autoFlag;
}

void CheckDuplicateSpecifier(DeclarationFlags flags, DeclarationFlags flag, const std::string& specifierStr, const SourcePos& sourcePos, Context* context)
{
    if ((flags & flag) != DeclarationFlags::none)
    {
        throw Exception("duplicate '" + specifierStr + "'", sourcePos, context);
    }
}

void ProcessDeclaration(Declaration& declaration, Context* context)
{
    if ((declaration.kind & DeclarationKind::classDeclaration) != DeclarationKind::none)
    {
        ClassTypeSymbol* classTypeSymbol = static_cast<ClassTypeSymbol*>(declaration.type);
        if (classTypeSymbol->Level() == 0)
        {
            Node* classSpecifierNode = context->GetSymbolTable()->GetNode(classTypeSymbol);
            ParseInlineMemberFunctions(classSpecifierNode, context);
        }
    }
    if ((declaration.kind & DeclarationKind::aliasDeclararation) != DeclarationKind::none)
    {
        if (!declaration.idNode)
        {
            throw Exception("no declarators specified for a typedef", declaration.node->GetSourcePos(), context);
        }
        Symbol* aliasTypeSymbol = new AliasTypeSymbol(declaration.idNode->Str(), declaration.type);
        declaration.scope->AddSymbol(aliasTypeSymbol, declaration.node->GetSourcePos(), context);
    }
    if ((declaration.kind & DeclarationKind::objectDeclaration) != DeclarationKind::none)
    {
        if (!declaration.idNode)
        {
            throw Exception("no declarators specified for a variable", declaration.node->GetSourcePos(), context);
        }
        VariableSymbol* variableSymbol = new VariableSymbol(declaration.idNode->Str());
        variableSymbol->SetType(declaration.type);
        declaration.scope->AddSymbol(variableSymbol, declaration.idNode->GetSourcePos(), context);
    }
    if (declaration.idNode && (declaration.kind & DeclarationKind::functionDeclaration) != DeclarationKind::none)
    {
        Scope* scope = declaration.scope;
        if (declaration.type->IsFunctionTypeSymbol())
        {
            FunctionTypeSymbol* functionType = static_cast<FunctionTypeSymbol*>(declaration.type);
            context->GetSymbolTable()->BeginFunction(declaration.idNode, scope, functionType, std::move(declaration.parameters), false, context);
            context->GetSymbolTable()->EndFunction();
        }
        else
        {
            throw Exception("function type symbol expected", declaration.node->GetSourcePos(), context);
        }
    }
}

void ProcessSimpleDeclaration(Node* declaration, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    declaration->Accept(visitor);
    std::vector<Declaration> declarations = visitor.GetDeclarations();
    for (Declaration& declaration : declarations)
    {
        ProcessDeclaration(declaration, context);
    }
}

void ProcessMemberDeclaration(Node* memberDeclaration, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    memberDeclaration->Accept(visitor);
    std::vector<Declaration> declarations = visitor.GetDeclarations();
    for (Declaration& declaration : declarations)
    {
        ProcessDeclaration(declaration, context);
    }
}

void BeginFunctionDefinition(Node* declSpecifierSeq, Node* declarator, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    SourcePos sourcePos;
    if (declSpecifierSeq)
    {
        visitor.ProcessDeclSpecifiers(declSpecifierSeq);
        sourcePos = declSpecifierSeq->GetSourcePos();
    }
    if (declarator)
    {
        visitor.ProcessDeclarator(declarator);
        sourcePos = declarator->GetSourcePos();
    }
    Declaration declaration = visitor.GetDeclaration();
    if ((declaration.kind & DeclarationKind::functionDeclaration) != DeclarationKind::none)
    {
        bool definition = true;
        if (context->GetFlag(ContextFlags::parseMemberFunction))
        {
            definition = false;
        }
        if (declaration.type->IsFunctionTypeSymbol())
        {
            FunctionTypeSymbol* functionType = static_cast<FunctionTypeSymbol*>(declaration.type);
            context->GetSymbolTable()->BeginFunction(declaration.idNode, declaration.scope, functionType, std::move(declaration.parameters), definition, context);
        }
        else
        {
            throw Exception("function type symbol expected", sourcePos, context);
        }
    }
    else
    {
        throw Exception("function declaration expected", sourcePos, context);
    }
}

void EndFunctionDefinition(Context* context)
{
    context->GetSymbolTable()->EndFunction();
}

void RemoveFunctionDefinition(Context* context)
{
    context->GetSymbolTable()->RemoveFunction();
}

void ProcessAliasDeclaration(Node* usingNode, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    usingNode->Accept(visitor);
    Declaration declaration = visitor.GetDeclaration();
    ProcessDeclaration(declaration, context);
}

ParameterSymbol* ProcessParameter(ParameterNode* parameterNode, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    visitor.ProcessDeclSpecifiers(parameterNode->DeclSpecifiers());
    visitor.ProcessDeclarator(parameterNode->Declarator());
    Declaration declaration = visitor.GetDeclaration();
    ParameterSymbol* parameterSymbol = new ParameterSymbol(declaration.idNode->Str());
    parameterSymbol->SetType(declaration.type);
    return parameterSymbol;
}

void ProcessParenthesizedDeclarator(Node* declarator, TypeSymbol* baseType, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    visitor.SetBaseType(baseType);
    visitor.ProcessDeclarator(declarator);
    Declaration declaration = visitor.GetDeclaration();
    ProcessDeclaration(declaration, context);
}

TypeSymbol* ProcessTypeSpecifierSequence(Node* typeSpecifierSequence, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    typeSpecifierSequence->Accept(visitor);
    TypeSymbol* type = visitor.GetBaseType();
    if (!type)
    {
        throw Exception("type expected", typeSpecifierSequence->GetSourcePos(), context);
    }
    return type;
}

} // sngcpp::symbols
