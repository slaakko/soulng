// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/symbols/DeclarationProcessor.hpp>
#include <sngcpp20/symbols/DeclTypeEvaluator.hpp>
#include <sngcpp20/symbols/AliasGroupSymbol.hpp>
#include <sngcpp20/symbols/AliasTypeSymbol.hpp>
#include <sngcpp20/symbols/VariableGroupSymbol.hpp>
#include <sngcpp20/symbols/VariableSymbol.hpp>
#include <sngcpp20/symbols/FunctionTypeSymbol.hpp>
#include <sngcpp20/symbols/Class.hpp>
#include <sngcpp20/symbols/ClassGroupSymbol.hpp>
#include <sngcpp20/symbols/ClassTypeSymbol.hpp>
#include <sngcpp20/symbols/EnumTypeSymbol.hpp>
#include <sngcpp20/symbols/Exception.hpp>
#include <sngcpp20/symbols/FundamentalTypeSymbol.hpp>
#include <sngcpp20/symbols/ScopeResolver.hpp>
#include <sngcpp20/symbols/SymbolTable.hpp>
#include <sngcpp20/symbols/Value.hpp>
#include <sngcpp20/ast/Visitor.hpp>
#include <sngcpp20/ast/Declaration.hpp>
#include <sngcpp20/ast/Expression.hpp>
#include <sngcpp20/ast/Class.hpp>
#include <sngcpp20/ast/Enum.hpp>
#include <sngcpp20/ast/Literal.hpp>
#include <sngcpp20/ast/SimpleType.hpp>
#include <sngcpp20/ast/Qualifier.hpp>
#include <sngcpp20/ast/Template.hpp>
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
    parameter = 1 << 5,
    skip  = 1 << 6
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
    Declaration(DeclarationKind kind_, DeclarationFlags flags_, Symbol* typeOrValue_, Id id_, Value* initializer_, Scope* scope_, Node* node_, std::vector<std::unique_ptr<ParameterSymbol>>&& parameters_);
    DeclarationKind kind;
    DeclarationFlags flags;
    Symbol* typeOrValue;
    Id id;
    Value* initializer;
    Scope* scope;
    Node* node;
    std::vector<std::unique_ptr<ParameterSymbol>> parameters;
};

Declaration::Declaration(DeclarationKind kind_, DeclarationFlags flags_, Symbol* typeOrValue_, Id id_, Value* initializer_, Scope* scope_, Node* node_, std::vector<std::unique_ptr<ParameterSymbol>>&& parameters_) :
    kind(kind_), flags(flags_), typeOrValue(typeOrValue_), id(id_), initializer(initializer_), scope(scope_), node(node_), parameters(std::move(parameters_))
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

    void SetKind(DeclarationKind kind_) { kind = kind_; }

    void Visit(SimpleDeclarationNode& node) override;

    void Visit(MemberDeclarationNode& node) override;

    void Visit(TypeIdNode& node) override;
    void Visit(TypeSpecifierSequenceNode& node) override;
    void Visit(DefiningTypeIdNode& node) override;
    void Visit(TemplateIdNode& node) override;
    void Visit(InvokeExprNode& node) override;

    void Visit(ClassSpecifierNode& node);
    void Visit(EnumSpecifierNode& node);
    void Visit(ElaboratedTypeSpecifierNode& node);
    void Visit(DeclTypeSpecifierNode& node) override;
    void Visit(TypenameSpecifierNode& node) override;

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
    void Visit(DeclSpecNode& node) override;

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
    void Visit(Int64Node& node) override;
    void Visit(Int32Node& node) override;
    void Visit(Int16Node& node) override;
    void Visit(Int8Node& node) override;

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
    void Visit(TrailingFunctionDeclaratorNode& node) override;
    void Visit(ArrayDeclaratorNode& node) override;
    void Visit(IntegerLiteralNode& node) override;
    void Visit(BooleanLiteralNode& node) override;
    void Visit(ParenthesizedDeclaratorNode& node) override;
    void Visit(ParameterNode& node) override;
    void Visit(EllipsisNode& node) override;
    void Visit(PlaceholderTypeSpecifierNode& node) override;

    void Visit(NoexceptSpecifierNode& node) override;
    void Visit(CppCastExprNode& node) override;
    void Visit(AlignOfExprNode& node) override;
    void Visit(ConditionalExprNode& node) override;

    void Visit(DestructorIdNode& node) override;
    void Visit(OperatorFunctionIdNode& node);
    void Visit(ConversionFunctionIdNode& node) override;
    void Visit(ConversionDeclaratorNode& node) override;
    void Visit(NewArrayOpNode& node) override;
    void Visit(NewOpNode& node) override;
    void Visit(DeleteArrayOpNode& node) override;
    void Visit(DeleteOpNode& node) override;
    void Visit(CoAwaitOpNode& node) override;
    void Visit(InvokeOpNode& node) override;
    void Visit(SubscriptOpNode& node) override;
    void Visit(ArrowNode& node) override;
    void Visit(ArrowStarNode& node) override;
    void Visit(ComplementNode& node) override;
    void Visit(NotNode& node) override;
    void Visit(PlusNode& node) override;
    void Visit(MinusNode& node) override;
    void Visit(MulNode& node) override;
    void Visit(DivNode& node) override;
    void Visit(ModNode& node) override;
    void Visit(ExclusiveOrNode& node) override;
    void Visit(AndNode& node) override;
    void Visit(InclusiveOrNode& node) override;
    void Visit(AssignNode& node) override;
    void Visit(PlusAssignNode& node) override;
    void Visit(MinusAssignNode& node) override;
    void Visit(MulAssignNode& node) override;
    void Visit(DivAssignNode& node) override;
    void Visit(ModAssignNode& node) override;
    void Visit(XorAssignNode& node) override;
    void Visit(AndAssignNode& node) override;
    void Visit(OrAssignNode& node) override;
    void Visit(ShiftLeftAssignNode& node) override;
    void Visit(ShiftRightAssignNode& node) override;
    void Visit(EqualNode& node) override;
    void Visit(NotEqualNode& node) override;
    void Visit(LessOrEqualNode& node) override;
    void Visit(GreaterOrEqualNode& node) override;
    void Visit(CompareNode& node) override;
    void Visit(LessNode& node) override;
    void Visit(GreaterNode& node) override;
    void Visit(ConjunctionNode& node) override;
    void Visit(DisjunctionNode& node) override;
    void Visit(ShiftLeftNode& node) override;
    void Visit(ShiftRightNode& node) override;
    void Visit(PrefixIncNode& node) override;
    void Visit(PrefixDecNode& node) override;
    void Visit(CommaNode& node) override;

    void ProcessDeclSpecifiers(Node* declSpecifiers);
    void ProcessDeclarator(Node* declarator);
    void ResolveBaseType(Node* node);
    Symbol* TypeOrValue() const { return typeOrValue; }
    TypeSymbol* GetBaseType() const;
    void SetBaseTypeOrValue(Symbol* baseTypeOrValue_);
private:
    void ProcesInitDeclarators(Node* initDeclaratorList);
    void ProcessMemberDeclarators(Node* memberDeclarators);
    DeclarationKind kind;
    Stage stage;
    DeclarationFlags flags;
    Context* context;
    Symbol* baseTypeOrValue;
    Symbol* typeOrValue;
    TypeSymbol* functionType;
    Id id;
    Value* initializer;
    Scope* scope;
    Node* node;
    uint64_t dimension;
    std::u32string typeName;
    std::vector<std::unique_ptr<ParameterSymbol>> parameters;
    std::vector<Declaration> declarations;
    std::vector<Symbol*> templateArguments;
    std::stack<std::vector<Symbol*>> templateArgumentsStack;
    bool getDimension;
    bool extractDestructorName;
    bool extractOperatorFunctionId;
};

DeclarationProcessorVisitor::DeclarationProcessorVisitor(Context* context_) : 
    kind(DeclarationKind::none), stage(Stage::processDeclSpecifiers), flags(), context(context_), baseTypeOrValue(nullptr), typeOrValue(nullptr), functionType(nullptr), id(), initializer(nullptr),
    scope(context->GetSymbolTable()->CurrentScope()), node(nullptr), dimension(0), getDimension(false), extractDestructorName(false), extractOperatorFunctionId(false)
{
}

TypeSymbol* DeclarationProcessorVisitor::GetBaseType() const
{ 
    if (baseTypeOrValue->IsTypeSymbol())
    {
        return static_cast<TypeSymbol*>(baseTypeOrValue);
    }
    else
    {
        throw std::runtime_error("type expected");
    }
}

void DeclarationProcessorVisitor::SetBaseTypeOrValue(Symbol* baseTypeOrValue_)
{ 
    baseTypeOrValue = baseTypeOrValue_;
}

Declaration DeclarationProcessorVisitor::GetDeclaration()
{
    if (kind == DeclarationKind::none)
    {
        kind = DeclarationKind::objectDeclaration;
    }
    return Declaration(kind, flags, typeOrValue, id, initializer, scope, node, std::move(parameters));
}

std::vector<Declaration> DeclarationProcessorVisitor::GetDeclarations()
{
    return std::move(declarations);
}

void DeclarationProcessorVisitor::Visit(SimpleDeclarationNode& node)
{
    this->node = &node;
    ProcessDeclSpecifiers(node.DeclarationSpecifiers());
    if (node.InitDeclaratorList())
    {
        ProcesInitDeclarators(node.InitDeclaratorList());
    }
    else
    {
        typeOrValue = baseTypeOrValue;
        id = Id();
        scope = context->GetSymbolTable()->CurrentScope();
        declarations.push_back(GetDeclaration());
    }
}

void DeclarationProcessorVisitor::Visit(MemberDeclarationNode& node)
{
    try
    {
        this->node = &node;
        ProcessDeclSpecifiers(node.DeclSpecifiers());
        ProcessMemberDeclarators(node.MemberDeclarators());
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(TypeIdNode& node)
{
    try
    {
        if (stage == Stage::processInitializer) return;
        node.TypeSpecifiers()->Accept(*this);
        ProcessDeclarator(node.Declarator());
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(TypeSpecifierSequenceNode& node)
{
    try
    {
        if (stage == Stage::processInitializer) return;
        if (!this->node)
        {
            this->node = &node;
        }
        stage = Stage::processDeclSpecifiers;
        VisitSequenceContent(node);
        ResolveBaseType(&node);
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(DefiningTypeIdNode& node)
{
    try
    {
        node.DefiningTypeSpecifiers()->Accept(*this);
        ResolveBaseType(&node);
        typeOrValue = baseTypeOrValue;
        node.AbstractDeclarator()->Accept(*this);
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(TemplateIdNode& node)
{
    try
    {
        if (stage == Stage::processInitializer) return;
        Stage prevStage = stage;
        templateArgumentsStack.push(templateArguments);
        templateArguments.clear();
        for (Node* itemNode : node.Items())
        {
            baseTypeOrValue = nullptr;
            typeOrValue = nullptr;
            flags = DeclarationFlags();
            stage = Stage::processDeclSpecifiers;
            itemNode->Accept(*this);
            if (!typeOrValue)
            {
                typeOrValue = baseTypeOrValue;
            }
            templateArguments.push_back(typeOrValue);
        }
        stage = prevStage;
        baseTypeOrValue = nullptr;
        flags = DeclarationFlags();
        if (stage == Stage::processDeclarators)
        {
            id = Id();
        }
        node.TemplateName()->Accept(*this);
        templateArguments = templateArgumentsStack.top();
        templateArgumentsStack.pop();
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(InvokeExprNode& node)
{
    try
    {
        throw Exception("unknown compiler intrinsic", node.GetSourcePos(), context);
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
        typeOrValue = baseTypeOrValue;
    }
}

void DeclarationProcessorVisitor::Visit(ClassSpecifierNode& node)
{
    try
    {
        kind = kind | DeclarationKind::classDeclaration;
        Symbol* symbol = context->GetSymbolTable()->GetSymbol(&node);
        if (symbol->Kind() == SymbolKind::classTypeSymbol)
        {
            baseTypeOrValue = static_cast<TypeSymbol*>(symbol);
        }
        else
        {
            throw Exception("class type symbol expected", node.GetSourcePos(), context);
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(EnumSpecifierNode& node)
{
    try
    {
        kind = kind | DeclarationKind::enumDeclaration;
        Symbol* symbol = context->GetSymbolTable()->GetSymbol(&node);
        if (symbol->Kind() == SymbolKind::enumTypeSymbol)
        {
            baseTypeOrValue = static_cast<TypeSymbol*>(symbol);
        }
        else
        {
            throw Exception("enum type symbol expected", node.GetSourcePos(), context);
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(ElaboratedTypeSpecifierNode& node)
{
    try
    {
        kind = kind | DeclarationKind::classDeclaration;
        Symbol* symbol = context->GetSymbolTable()->GetSymbol(&node);
        if (symbol->Kind() == SymbolKind::classTypeSymbol)
        {
            baseTypeOrValue = static_cast<TypeSymbol*>(symbol);
        }
        else
        {
            throw Exception("class type symbol expected", node.GetSourcePos(), context);
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(DeclTypeSpecifierNode& node)
{
    try
    {
        baseTypeOrValue = EvaluateDeclTypeNode(&node, context);
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(TypenameSpecifierNode& node)
{
    try
    {
        baseTypeOrValue = context->GetSymbolTable()->MakeGenericTypeSymbol();
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(AliasDeclarationNode& node)
{
    try
    {
        kind = kind | DeclarationKind::aliasDeclararation;
        if (!this->node)
        {
            this->node = &node;
        }
        stage = Stage::processDeclarators;
        node.Identifier()->Accept(*this);
        Id prevId = id;
        stage = Stage::processDeclSpecifiers;;
        node.DefiningTypeId()->Accept(*this);
        id = prevId;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::ProcessDeclSpecifiers(Node* declSpecifiers)
{
    if (!node)
    {
        node = declSpecifiers;
    }
    stage = Stage::processDeclSpecifiers;
    if (declSpecifiers)
    {
        declSpecifiers->Accept(*this);
    }
    ResolveBaseType(declSpecifiers);
}

void DeclarationProcessorVisitor::ResolveBaseType(Node* node)
{
    try
    {
        if (!node) return;
        DeclarationFlags fundamentalTypeFlags = flags & DeclarationFlags::fundamentalTypeFlags;
        if (fundamentalTypeFlags != DeclarationFlags::none)
        {
            if (baseTypeOrValue)
            {
                throw Exception("duplicate type symbol in declaration specifier sequence", node->GetSourcePos(), context);
            }
            baseTypeOrValue = GetFundamentalType(fundamentalTypeFlags, node->GetSourcePos(), context);
        }
        else
        {
            if (!baseTypeOrValue)
            {
                baseTypeOrValue = GetFundamentalType(DeclarationFlags::voidFlag, node->GetSourcePos(), context);
            }
        }
        if ((flags & DeclarationFlags::constFlag) != DeclarationFlags::none)
        {
            if (baseTypeOrValue->IsTypeSymbol())
            {
                baseTypeOrValue = context->GetSymbolTable()->MakeConstType(static_cast<TypeSymbol*>(baseTypeOrValue));
            }
            else
            {
                throw Exception("type symbol expected", node->GetSourcePos(), context);
            }
        }
        if ((flags & DeclarationFlags::volatileFlag) != DeclarationFlags::none)
        {
            if (baseTypeOrValue->IsTypeSymbol())
            {
                baseTypeOrValue = context->GetSymbolTable()->MakeVolatileType(static_cast<TypeSymbol*>(baseTypeOrValue));
            }
            else
            {
                throw Exception("type symbol expected", node->GetSourcePos(), context);
            }
        }
        if ((flags & DeclarationFlags::typedefFlag) != DeclarationFlags::none)
        {
            if ((flags & DeclarationFlags::typedefFlagMask) != DeclarationFlags::none)
            {
                throw Exception("invalid declaration specifier sequence: typedef cannot be combined with these specifiers", node->GetSourcePos(), context);
            }
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
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
    typeOrValue = baseTypeOrValue;
    id = Id();
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
    if (memberDeclarators)
    {
        stage = Stage::processDeclarators;
        flags = flags & ~DeclarationFlags::cvQualifierFlagMask;
        memberDeclarators->Accept(*this);
    }
    else
    {
        typeOrValue = baseTypeOrValue;
        id = Id();
        scope = context->GetSymbolTable()->CurrentScope();
        declarations.push_back(GetDeclaration());
    }
}

void DeclarationProcessorVisitor::Visit(StaticNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::staticFlag, "static", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::staticFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(ThreadLocalNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::threadLocalFlag, "thread_local", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::threadLocalFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(ExternNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::externFlag, "extern", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::externFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(MutableNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::mutableFlag, "mutable", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::mutableFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(VirtualNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::virtualFlag, "virtual", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::virtualFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(ExplicitNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::explicitFlag, "explicit", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::explicitFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(ConditionalExplicitNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::explicitFlag, "explicit", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::explicitFlag;
        // todo
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(InlineNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::inlineFlag, "inline", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::inlineFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(FriendNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::friendFlag, "friend", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::friendFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(TypedefNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::typedefFlag, "typedef", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::typedefFlag;
        this->node = &node;
        kind = kind | DeclarationKind::aliasDeclararation;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(ConstExprNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::constrExprFlag, "constexpr", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::constrExprFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(ConstEvalNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::constEvalFlag, "consteval", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::constEvalFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(ConstInitNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::constInitFlag, "constinit", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::constInitFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(DeclSpecNode& node)
{
    // skip
}

void DeclarationProcessorVisitor::Visit(CharNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::charFlag, "char", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::charFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(Char8Node& node) 
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::char8Flag, "char8_t", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::char8Flag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(Char16Node& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::char16Flag, "char16_t", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::char16Flag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(Char32Node& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::char32Flag, "char32_t", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::char32Flag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(WCharNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::wcharFlag, "wchar_t", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::wcharFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(BoolNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::boolFlag, "bool", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::boolFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(ShortNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::shortFlag, "short", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::shortFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(IntNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::intFlag, "int", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::intFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(LongNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::longLongFlag, "long long", node.GetSourcePos(), context);
        if ((flags & DeclarationFlags::longFlag) != DeclarationFlags::none)
        {
            flags = (flags | DeclarationFlags::longLongFlag) & ~DeclarationFlags::longFlag;
        }
        else
        {
            flags = flags | DeclarationFlags::longFlag;
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(SignedNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::signedFlag, "signed", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::signedFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(UnsignedNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::unsignedFlag, "unsigned", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::unsignedFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(FloatNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::floatFlag, "float", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::floatFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(DoubleNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::doubleFlag, "double", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::doubleFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(VoidNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::voidFlag, "void", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::voidFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(Int64Node& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::int64Flag, "__int64", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::int64Flag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(Int32Node& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::int32Flag, "__int32", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::int32Flag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(Int16Node& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::int16Flag, "__int16", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::int16Flag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(Int8Node& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::int8Flag, "__int8", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::int8Flag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(IdentifierNode& node)
{
    try
    {
        if (getDimension)
        {
            return;
        }
        if (stage == Stage::processDeclSpecifiers)
        {
            Symbol* symbol = context->GetSymbolTable()->GetSymbolNothrow(&node);
            if (!symbol)
            {
                symbol = scope->Lookup(node.Str(), SymbolGroupKind::typeSymbolGroup | SymbolGroupKind::variableSymbolGroup, ScopeLookup::allScopes, node.GetSourcePos(), context);
            }
            if (symbol)
            {
                if (symbol->IsTypeSymbol())
                {
                    if (baseTypeOrValue)
                    {
                        throw Exception("duplicate type symbol in declaration specifier sequence", node.GetSourcePos(), context);
                    }
                    else
                    {
                        if (symbol->Kind() == SymbolKind::aliasGroupSymbol)
                        {
                            AliasGroupSymbol* aliasGroupSymbol = static_cast<AliasGroupSymbol*>(symbol);
                            bool exact = false;
                            symbol = aliasGroupSymbol->GetAliasTypeSymbol(templateArguments, MatchKind::exact, exact);
                            if (!symbol)
                            {
                                AliasTypeSymbol* aliasTemplate = aliasGroupSymbol->AliasTypeTemplate();
                                if (aliasTemplate)
                                {
                                    symbol = context->GetSymbolTable()->Instantiate(aliasTemplate, templateArguments);
                                }
                            }
                        }
                        else if (symbol->Kind() == SymbolKind::classGroupSymbol)
                        {
                            ClassGroupSymbol* classGroupSymbol = static_cast<ClassGroupSymbol*>(symbol);
                            bool exact = false;
                            symbol = classGroupSymbol->GetClass(templateArguments, MatchKind::partial, exact);
                            if (!symbol)
                            {
                                ClassTypeSymbol* classTemplate = classGroupSymbol->GetClassTemplate();
                                if (classTemplate)
                                {
                                    symbol = context->GetSymbolTable()->Instantiate(classTemplate, templateArguments);
                                }
                            }
                        }
                        if (!symbol)
                        {
                            throw Exception("symbol '" + ToUtf8(node.Str()) + "' not found", node.GetSourcePos(), context);
                        }
                        if (symbol->IsTypeSymbol())
                        {
                            baseTypeOrValue = static_cast<TypeSymbol*>(symbol);
                        }
                        else
                        {
                            throw Exception("type symbol expected", node.GetSourcePos(), context);
                        }
                    }
                }
                else if (symbol->Kind() == SymbolKind::variableGroupSymbol)
                {
                    VariableGroupSymbol* variableGroupSymbol = static_cast<VariableGroupSymbol*>(symbol);
                    bool exact = false;
                    symbol = variableGroupSymbol->GetVariable(templateArguments, MatchKind::exact, exact);
                    if (!symbol)
                    {
                        VariableSymbol* variableTemplate = variableGroupSymbol->GetVariableTemplate();
                        if (variableTemplate)
                        {
                            symbol = context->GetSymbolTable()->Instantiate(variableTemplate, templateArguments);
                        }
                    }
                }
                if (!symbol)
                {
                    throw Exception("symbol '" + ToUtf8(node.Str()) + "' not found", node.GetSourcePos(), context);
                }
                if (!baseTypeOrValue)
                {
                    baseTypeOrValue = symbol;
                }
            }
            else
            {
                throw Exception("symbol '" + ToUtf8(node.Str()) + "' not found", node.GetSourcePos(), context);
            }
        }
        else if (stage == Stage::processDeclarators)
        {
            if (id.idNode)
            {
                throw Exception("duplicate identifier in declarator list", node.GetSourcePos(), context);
            }
            id = Id(&node, templateArguments);
            if (extractDestructorName)
            {
                id.idNode = &node;
                id.functionName = U"~" + node.Str();
            }
            else
            {
                id.functionName = node.Str();
                Scope* classScope = context->GetSymbolTable()->CurrentScope()->GetClassScope();
                if (classScope)
                {
                    Symbol* classTypeSymbol = classScope->GetSymbol();
                    if (id.functionName == classTypeSymbol->Name())
                    {
                        id.functionKind = FunctionKind::constructor;
                    }
                }
            }
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        if (stage == Stage::processDeclSpecifiers)
        {
            baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
        }
    }
}

void DeclarationProcessorVisitor::Visit(QualifiedIdNode& node)
{
    try
    {
        scope = ResolveScope(node.Left(), context);
        node.Right()->Accept(*this);
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(AbstractDeclaratorNode& node)
{
    try
    {
        if (!id.idNode)
        {
            id.idNode = &node;
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(InitDeclaratorListNode& node)
{
    try
    {
        for (Node* item : node.Items())
        {
            typeOrValue = baseTypeOrValue;
            scope = context->GetSymbolTable()->CurrentScope();
            id = Id();
            item->Accept(*this);
            declarations.push_back(GetDeclaration());
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(InitDeclaratorNode& node)
{
    try
    {
        stage = Stage::processDeclarators;
        node.Left()->Accept(*this);
        stage = Stage::processInitializer;
        node.Right()->Accept(*this);
        stage = Stage::processDeclarators;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(MemberDeclaratorListNode& node)
{
    try
    {
        for (Node* item : node.Items())
        {
            typeOrValue = baseTypeOrValue;
            id = Id();
            scope = context->GetSymbolTable()->CurrentScope();
            item->Accept(*this);
            declarations.push_back(GetDeclaration());
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(PtrNode& node)
{
    try
    {
        kind = kind & ~DeclarationKind::classDeclaration;
        if (typeOrValue->IsTypeSymbol())
        {
            typeOrValue = context->GetSymbolTable()->MakePointerType(static_cast<TypeSymbol*>(typeOrValue));
        }
        else
        {
            throw Exception("type expected", node.GetSourcePos(), context);
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        typeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(LvalueRefNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::lvalueRefFlag, "&", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::lvalueRefFlag;
        if (typeOrValue->IsTypeSymbol())
        {
            typeOrValue = context->GetSymbolTable()->MakeLvalueRefType(static_cast<TypeSymbol*>(typeOrValue));
        }
        else
        {
            throw Exception("type expected", node.GetSourcePos(), context);
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        typeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(RvalueRefNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::rvalueRefFlag, "&&", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::rvalueRefFlag;
        if (typeOrValue->IsTypeSymbol())
        {
            typeOrValue = context->GetSymbolTable()->MakeRvalueRefType(static_cast<TypeSymbol*>(typeOrValue));
        }
        else
        {
            throw Exception("type expected", node.GetSourcePos(), context);
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        typeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(ConstNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::constFlag, "const", node.GetSourcePos(), context);
        if (stage == Stage::processDeclSpecifiers)
        {
            flags = flags | DeclarationFlags::constFlag;
        }
        else if (stage == Stage::processDeclarators)
        {
            if (typeOrValue->IsTypeSymbol())
            {
                typeOrValue = context->GetSymbolTable()->MakeConstType(static_cast<TypeSymbol*>(typeOrValue));
            }
            else
            {
                throw Exception("type expected", node.GetSourcePos(), context);
            }
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        typeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(VolatileNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::volatileFlag, "volatile", node.GetSourcePos(), context);
        if (stage == Stage::processDeclSpecifiers)
        {
            flags = flags | DeclarationFlags::volatileFlag;
        }
        else if (stage == Stage::processDeclarators)
        {
            if (typeOrValue->IsTypeSymbol())
            {
                typeOrValue = context->GetSymbolTable()->MakeVolatileType(static_cast<TypeSymbol*>(typeOrValue));
            }
            else
            {
                throw Exception("type expected", node.GetSourcePos(), context);
            }
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        typeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(FunctionDeclaratorNode& node)
{
    try
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
        if (!typeOrValue)
        {
            typeOrValue = GetFundamentalType(DeclarationFlags::voidFlag, node.GetSourcePos(), context);
        }
        Symbol* prevTypeOrValue = typeOrValue;
        if (typeOrValue->IsTypeSymbol())
        {
            typeOrValue = context->GetSymbolTable()->MakeFunctionType(FunctionTypeKey(static_cast<TypeSymbol*>(typeOrValue), parameterTypes));
        }
        else
        {
            throw Exception("type expected", node.GetSourcePos(), context);
        }
        node.Child()->Accept(*this);
        if (typeOrValue->Kind() != SymbolKind::functionTypeSymbol && typeOrValue != prevTypeOrValue)
        {
            typeOrValue = context->GetSymbolTable()->MakeFunctionType(FunctionTypeKey(static_cast<TypeSymbol*>(typeOrValue), parameterTypes));
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        typeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(TrailingFunctionDeclaratorNode& node)
{
    try
    {
        if (kind == DeclarationKind::none)
        {
            kind = DeclarationKind::functionDeclaration;
        }
        parameters.clear();
        node.Parameters()->Accept(*this);
        std::vector<TypeSymbol*> parameterTypes;
        for (const auto& param : parameters)
        {
            parameterTypes.push_back(param->Type());
        }
        ProcessDeclarator(node.Declarator());
        if (baseTypeOrValue && baseTypeOrValue->Kind() == SymbolKind::fundamentalTypeSymbol && baseTypeOrValue->Name() == U"auto")
        {
            baseTypeOrValue = nullptr;
            flags = DeclarationFlags();
        }
        ProcessDeclSpecifiers(node.TrailingReturnType());
        if (typeOrValue->IsTypeSymbol())
        {
            typeOrValue = context->GetSymbolTable()->MakeFunctionType(FunctionTypeKey(static_cast<TypeSymbol*>(typeOrValue), parameterTypes));
        }
        else
        {
            throw Exception("type expected", node.GetSourcePos(), context);
        }
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        typeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(ArrayDeclaratorNode& node)
{
    try
    {
        dimension = 0;
        if (node.Dimension())
        {
            getDimension = true;
            node.Dimension()->Accept(*this);
            getDimension = false;
        }
        if (typeOrValue->IsTypeSymbol())
        {
            typeOrValue = context->GetSymbolTable()->MakeArrayType(ArrayTypeKey(static_cast<TypeSymbol*>(typeOrValue), dimension));
        }
        else
        {
            throw Exception("type expected", node.GetSourcePos(), context);
        }
        node.Child()->Accept(*this);
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        typeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
    }
}

void DeclarationProcessorVisitor::Visit(IntegerLiteralNode& node)
{
    try
    {
        if (getDimension)
        {
            dimension = node.Value();
        }
        else if (stage == Stage::processInitializer)
        {
            initializer = GetEvaluationContext().GetIntegerValue(node.Value(), node.Rep());
        }
        else
        {
            typeOrValue = GetEvaluationContext().GetIntegerValue(node.Value(), node.Rep());
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(BooleanLiteralNode& node)
{
    try
    {
        if (stage == Stage::processInitializer)
        {
            initializer = GetEvaluationContext().GetBoolValue(node.Value());
        }
        else
        {
            typeOrValue = GetEvaluationContext().GetBoolValue(node.Value());
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(ParenthesizedDeclaratorNode& node)
{
    try
    {
        bool alias = false;
        bool param = false;
        if (kind == DeclarationKind::aliasDeclararation)
        {
            alias = true;
        }
        else if (kind == DeclarationKind::parameter)
        {
            param = true;
        }
        ProcessParenthesizedDeclarator(node.Declarator(), typeOrValue, alias, param, context);
        if (alias || param)
        {
            kind = DeclarationKind::skip;
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(ParameterNode& node)
{
    try
    {
        ParameterSymbol* parameterSymbol = ProcessParameter(&node, context);
        parameters.push_back(std::unique_ptr<ParameterSymbol>(parameterSymbol));
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(PlaceholderTypeSpecifierNode& node)
{
    try
    {
        CheckDuplicateSpecifier(flags, DeclarationFlags::autoFlag, "auto", node.GetSourcePos(), context);
        flags = flags | DeclarationFlags::autoFlag;
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(NoexceptSpecifierNode& node)
{
    // skip
}

void DeclarationProcessorVisitor::Visit(CppCastExprNode& node)
{
    try
    {
        throw Exception("cast expression not implemented in declaration processor", node.GetSourcePos(), context);
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
        typeOrValue = baseTypeOrValue;
    }
}

void DeclarationProcessorVisitor::Visit(AlignOfExprNode& node)
{
    try
    {
        throw Exception("alignof expression not implemented in declaration processor", node.GetSourcePos(), context);
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
        typeOrValue = baseTypeOrValue;
    }
}

void DeclarationProcessorVisitor::Visit(ConditionalExprNode& node)
{
    try
    {
        throw Exception("conditional expression processing not implemented in declaration processor", node.GetSourcePos(), context);
    }
    catch (const std::exception& ex)
    {
        int errorIndex = context->GetSymbolTable()->AddError(ex);
        baseTypeOrValue = context->GetSymbolTable()->MakeErrorSymbol(errorIndex);
        typeOrValue = baseTypeOrValue;
    }
}

void DeclarationProcessorVisitor::Visit(EllipsisNode& node)
{
    try
    {
        if (kind == DeclarationKind::parameter)
        {
            ParameterSymbol* parameterSymbol = new ParameterSymbol(U"...");
            parameterSymbol->SetType(context->GetSymbolTable()->MakeVarArgTypeSymbol());
            parameters.push_back(std::unique_ptr<ParameterSymbol>(parameterSymbol));
        }
        else
        {
            baseTypeOrValue = context->GetSymbolTable()->MakeVarArgTypeSymbol();
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void DeclarationProcessorVisitor::Visit(DestructorIdNode& node)
{
    id.functionKind = FunctionKind::destructor;
    extractDestructorName = true;
    node.Child()->Accept(*this);
    extractDestructorName = false;
}

void DeclarationProcessorVisitor::Visit(OperatorFunctionIdNode& node)
{
    id.functionKind = FunctionKind::operatorFn;
    extractOperatorFunctionId = true;
    node.Right()->Accept(*this);
    extractOperatorFunctionId = false;
}

void DeclarationProcessorVisitor::Visit(ConversionFunctionIdNode& node)
{
    id.functionKind = FunctionKind::conversionFn;
    baseTypeOrValue = ProcessTypeSpecifierSequence(node.Right(), context);
    typeOrValue = baseTypeOrValue;
    id.idNode = &node;
    id.functionName = U"operator " + typeOrValue->Name();
}

void DeclarationProcessorVisitor::Visit(ConversionDeclaratorNode& node)
{
    typeOrValue = baseTypeOrValue;
    DefaultVisitor::Visit(node);
}

void DeclarationProcessorVisitor::Visit(NewArrayOpNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator new[]";
    }
}

void DeclarationProcessorVisitor::Visit(NewOpNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator new";
    }
}

void DeclarationProcessorVisitor::Visit(DeleteArrayOpNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator delete[]";
    }
}

void DeclarationProcessorVisitor::Visit(DeleteOpNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator delete";
    }
}

void DeclarationProcessorVisitor::Visit(CoAwaitOpNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator coawait";
    }
}

void DeclarationProcessorVisitor::Visit(InvokeOpNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator()";
    }
}

void DeclarationProcessorVisitor::Visit(SubscriptOpNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator[]";
    }
}

void DeclarationProcessorVisitor::Visit(ArrowNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator->";
    }
}

void DeclarationProcessorVisitor::Visit(ArrowStarNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator->*";
    }
}

void DeclarationProcessorVisitor::Visit(ComplementNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator~";
    }
}

void DeclarationProcessorVisitor::Visit(NotNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator!";
    }
}

void DeclarationProcessorVisitor::Visit(PlusNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator+";
    }
}

void DeclarationProcessorVisitor::Visit(MinusNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator-";
    }
}

void DeclarationProcessorVisitor::Visit(MulNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator*";
    }
}

void DeclarationProcessorVisitor::Visit(DivNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator/";
    }
}

void DeclarationProcessorVisitor::Visit(ModNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator%";
    }
}

void DeclarationProcessorVisitor::Visit(ExclusiveOrNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator^";
    }
}

void DeclarationProcessorVisitor::Visit(AndNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator&";
    }
}

void DeclarationProcessorVisitor::Visit(InclusiveOrNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator|";
    }
}

void DeclarationProcessorVisitor::Visit(AssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator=";
    }
}

void DeclarationProcessorVisitor::Visit(PlusAssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator+=";
    }
}

void DeclarationProcessorVisitor::Visit(MinusAssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator-=";
    }
}

void DeclarationProcessorVisitor::Visit(MulAssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator*=";
    }
}

void DeclarationProcessorVisitor::Visit(DivAssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator/=";
    }
}

void DeclarationProcessorVisitor::Visit(ModAssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator%=";
    }
}

void DeclarationProcessorVisitor::Visit(XorAssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator^=";
    }
}

void DeclarationProcessorVisitor::Visit(AndAssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator&=";
    }
}

void DeclarationProcessorVisitor::Visit(OrAssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator|=";
    }
}

void DeclarationProcessorVisitor::Visit(ShiftLeftAssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator<<=";
    }
}

void DeclarationProcessorVisitor::Visit(ShiftRightAssignNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator>>=";
    }

}

void DeclarationProcessorVisitor::Visit(EqualNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator==";
    }
}

void DeclarationProcessorVisitor::Visit(NotEqualNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator!=";
    }

}

void DeclarationProcessorVisitor::Visit(LessOrEqualNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator<=";
    }
}

void DeclarationProcessorVisitor::Visit(GreaterOrEqualNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator>=";
    }
}

void DeclarationProcessorVisitor::Visit(CompareNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator<=>";
    }
}

void DeclarationProcessorVisitor::Visit(LessNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator<";
    }
}

void DeclarationProcessorVisitor::Visit(GreaterNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator>";
    }
}

void DeclarationProcessorVisitor::Visit(ConjunctionNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator&&";
    }
}

void DeclarationProcessorVisitor::Visit(DisjunctionNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator||";
    }
}

void DeclarationProcessorVisitor::Visit(ShiftLeftNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator<<";
    }
}

void DeclarationProcessorVisitor::Visit(ShiftRightNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator>>";
    }
}

void DeclarationProcessorVisitor::Visit(PrefixIncNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator++";
    }
}

void DeclarationProcessorVisitor::Visit(PrefixDecNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator--";
    }
}

void DeclarationProcessorVisitor::Visit(CommaNode& node)
{
    if (extractOperatorFunctionId)
    {
        id.idNode = &node;
        id.functionName = U"operator,";
    }
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
    try
    {
        if ((declaration.kind & DeclarationKind::classDeclaration) != DeclarationKind::none)
        {
            if (declaration.typeOrValue->Kind() == SymbolKind::classTypeSymbol)
            {
                ClassTypeSymbol* classTypeSymbol = static_cast<ClassTypeSymbol*>(declaration.typeOrValue);
                if (classTypeSymbol->Level() == 0 && !context->GetFlag(ContextFlags::parsingTemplateDeclaration))
                {
                    Node* classSpecifierNode = context->GetSymbolTable()->GetNode(classTypeSymbol);
                    ParseInlineMemberFunctions(classSpecifierNode, context);
                }
            }
        }
        if ((declaration.kind & DeclarationKind::aliasDeclararation) != DeclarationKind::none)
        {
            if (!declaration.id.idNode)
            {
                throw Exception("no declarators specified for an alias type", declaration.node->GetSourcePos(), context);
            }
            if (declaration.typeOrValue->IsTypeSymbol())
            {
                context->GetSymbolTable()->AddAliasType(declaration.id.idNode, declaration.scope, static_cast<TypeSymbol*>(declaration.typeOrValue), context);
            }
            else
            {
                throw Exception("type expected", declaration.node->GetSourcePos(), context);
            }
        }
        if ((declaration.kind & DeclarationKind::objectDeclaration) != DeclarationKind::none)
        {
            if (!declaration.id.idNode)
            {
                throw Exception("no declarators specified for a variable", declaration.node->GetSourcePos(), context);
            }
            if (declaration.typeOrValue->IsTypeSymbol())
            {
                context->GetSymbolTable()->AddVariable(declaration.id.idNode, declaration.id.templateArguments, declaration.initializer, declaration.scope, static_cast<TypeSymbol*>(declaration.typeOrValue),
                    SymbolKind::variableSymbol, context);
            }
            else
            {
                throw Exception("type expected", declaration.node->GetSourcePos(), context);
            }
        }
        if (declaration.id.idNode && (declaration.kind & DeclarationKind::functionDeclaration) != DeclarationKind::none)
        {
            Scope* scope = declaration.scope;
            if (declaration.typeOrValue->Kind() == SymbolKind::functionTypeSymbol)
            {
                FunctionTypeSymbol* functionType = static_cast<FunctionTypeSymbol*>(declaration.typeOrValue);
                SourcePos sourcePos = declaration.id.idNode->GetSourcePos();
                context->GetSymbolTable()->BeginFunction(declaration.id.idNode, scope, functionType, std::move(declaration.parameters), false, sourcePos, declaration.id.functionName, context);
                context->GetSymbolTable()->EndFunction();
            }
            else
            {
                throw Exception("function type symbol expected", declaration.node->GetSourcePos(), context);
            }
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void ProcessSimpleDeclaration(Node* declaration, Context* context)
{
    try
    {
        DeclarationProcessorVisitor visitor(context);
        declaration->Accept(visitor);
        std::vector<Declaration> declarations = visitor.GetDeclarations();
        for (Declaration& declaration : declarations)
        {
            ProcessDeclaration(declaration, context);
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

void ProcessMemberDeclaration(Node* memberDeclaration, Context* context)
{
    try
    {
        DeclarationProcessorVisitor visitor(context);
        memberDeclaration->Accept(visitor);
        std::vector<Declaration> declarations = visitor.GetDeclarations();
        for (Declaration& declaration : declarations)
        {
            ProcessDeclaration(declaration, context);
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

class ContainsFunctionDeclaratorNodeVisitor : public DefaultVisitor
{
public:
    ContainsFunctionDeclaratorNodeVisitor() : value(false) {}
    void Visit(FunctionDeclaratorNode& node) override { value = true; }
    void Visit(TrailingFunctionDeclaratorNode& node) override { value = true; }
    bool Value() const { return value; }
private:
    bool value;
};

bool ContainsFunctionDeclarator(Node* declarator)
{
    ContainsFunctionDeclaratorNodeVisitor visitor;
    declarator->Accept(visitor);
    return visitor.Value();
}

void ProcessAliasDeclaration(Node* usingNode, Context* context)
{
    try
    {
        DeclarationProcessorVisitor visitor(context);
        usingNode->Accept(visitor);
        Declaration declaration = visitor.GetDeclaration();
        ProcessDeclaration(declaration, context);
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
}

ParameterSymbol* ProcessParameter(ParameterNode* parameterNode, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    visitor.SetKind(DeclarationKind::parameter);
    visitor.ProcessDeclSpecifiers(parameterNode->DeclSpecifiers());
    visitor.ProcessDeclarator(parameterNode->Declarator());
    Declaration declaration = visitor.GetDeclaration();
    std::u32string paramName;
    if (declaration.id.idNode)
    {
        paramName = declaration.id.idNode->Str();
    }
    ParameterSymbol* parameterSymbol = new ParameterSymbol(paramName);
    if (declaration.typeOrValue->IsTypeSymbol())
    {
        parameterSymbol->SetType(static_cast<TypeSymbol*>(declaration.typeOrValue));
    }
    else
    {
        throw Exception("type expected", parameterNode->GetSourcePos(), context);
    }
    return parameterSymbol;
}

void ProcessParenthesizedDeclarator(Node* declarator, Symbol* baseTypeOrValue, bool alias, bool param, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    if (alias)
    {
        visitor.SetKind(DeclarationKind::aliasDeclararation);
    }
    if (param)
    {
        visitor.SetKind(DeclarationKind::parameter);
    }
    visitor.SetBaseTypeOrValue(baseTypeOrValue);
    visitor.ProcessDeclarator(declarator);
    Declaration declaration = visitor.GetDeclaration();
    ProcessDeclaration(declaration, context);
}

TypeSymbol* ProcessTypeSpecifierSequence(Node* typeSpecifierSequence, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    typeSpecifierSequence->Accept(visitor);
    Symbol* tov = visitor.TypeOrValue();
    TypeSymbol* type = nullptr;
    if (tov && tov->IsTypeSymbol())
    {
        type = static_cast<TypeSymbol*>(tov);
    }
    else
    {
        type = visitor.GetBaseType();
    }
    if (!type)
    {
        throw Exception("type expected", typeSpecifierSequence->GetSourcePos(), context);
    }
    return type;
}

Symbol* ProcessTypeIdOrValue(Node* typeIdNode, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    typeIdNode->Accept(visitor);
    Declaration declaration = visitor.GetDeclaration();
    return declaration.typeOrValue;
}

TypeSymbol* ProcessTypeTemplateId(Node* templateIdNode, Context* context)
{
    DeclarationProcessorVisitor visitor(context);
    templateIdNode->Accept(visitor);
    return visitor.GetBaseType();
}

bool BeginFunctionDefinition(Node* declSpecifierSeq, Node* declarator, Context* context)
{
    try
    {
        DeclarationProcessorVisitor visitor(context);

        SourcePos sourcePos;
        visitor.ProcessDeclSpecifiers(declSpecifierSeq);
        if (declSpecifierSeq)
        {
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
            if (declaration.typeOrValue->Kind() == SymbolKind::functionTypeSymbol)
            {
                FunctionTypeSymbol* functionType = static_cast<FunctionTypeSymbol*>(declaration.typeOrValue);
                if (declaration.id.idNode)
                {
                    sourcePos = declaration.id.idNode->GetSourcePos();
                }
                context->GetSymbolTable()->BeginFunction(declaration.id.idNode, declaration.scope, functionType, std::move(declaration.parameters), definition, sourcePos, declaration.id.functionName, context);
            }
            else
            {
                throw Exception("function type symbol expected", sourcePos, context);
            }
            return true;
        }
    }
    catch (const std::exception& ex)
    {
        context->GetSymbolTable()->AddError(ex);
    }
    return false;
}

void EndFunctionDefinition(Context* context)
{
    context->GetSymbolTable()->EndFunction();
}

void RemoveFunctionDefinition(Context* context)
{
    context->GetSymbolTable()->RemoveFunction();
}

} // sngcpp::symbols
