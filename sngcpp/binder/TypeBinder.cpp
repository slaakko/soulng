// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/binder/TypeBinder.hpp>
#include <sngcpp/binder/TypeResolver.hpp>
#include <sngcpp/symbols/TypedefSymbol.hpp>
#include <sngcpp/symbols/ParameterSymbol.hpp>
#include <sngcpp/symbols/VariableSymbol.hpp>
#include <sngcpp/symbols/ClassTemplateSpecializationSymbol.hpp>
#include <sngcpp/ast/SourceFile.hpp>
#include <sngcpp/ast/Template.hpp>
#include <sngcpp/ast/TypeExpr.hpp>

namespace sngcpp { namespace binder {

TypeBinder::TypeBinder(SymbolTable& symbolTable_, SourceFileResolver* sourceFileResolver_) :
    sourceFileResolver(sourceFileResolver_), symbolTable(symbolTable_), containerScope(nullptr), currentSourceFile(nullptr), currentClass(nullptr), currentFunction(nullptr),
    currentFunctionDeclaration(nullptr), currentAccessSpecifier(Specifier::public_), conversionFunctionType(nullptr)
{
}

void TypeBinder::ResolveIdSequence()
{
    ClassTypeSymbol* curClass = currentClass;
    if (!curClass)
    {
        if (currentFunction && currentFunction->Parent() && currentFunction->Parent()->IsClassTypeSymbol())
        {
            curClass = static_cast<ClassTypeSymbol*>(currentFunction->Parent());
        }
        else if (currentFunctionDeclaration && currentFunctionDeclaration->Parent() && currentFunctionDeclaration->Parent()->IsClassTypeSymbol())
        {
            curClass = static_cast<ClassTypeSymbol*>(currentFunctionDeclaration->Parent());
        }
    }
    int n = idSequence.size();
    bool classResolved = false;
    bool functionResolved = false;
    for (int i = 0; i < n; ++i)
    {
        IdentifierNode* id = idSequence[i];
        if (n > 1 && !classResolved && curClass && id->Identifier() == curClass->Name())
        {
            classResolved = true;
            symbolTable.MapNode(id, curClass);
        }
        else if (!functionResolved && currentFunction && id->Identifier() == currentFunction->Name())
        {
            functionResolved = true;
            symbolTable.MapNode(id, currentFunction);
        }
        else if (!functionResolved && currentFunctionDeclaration && id->Identifier() == currentFunctionDeclaration->Name())
        {
            functionResolved = true;
            symbolTable.MapNode(id, currentFunctionDeclaration);
        }
    }
}

void TypeBinder::Visit(SourceFileNode& sourceFileNode)
{
    Specifier prevAccessSpecifier = currentAccessSpecifier;
    currentAccessSpecifier = Specifier::public_;
    std::unique_ptr<BoundSourceFile> sourceFile(new BoundSourceFile(sourceFileNode));
    sourceFile->AddFileScope();
    BoundSourceFile* prevSourceFile = currentSourceFile;
    currentSourceFile = sourceFile.get();
    containerScope = symbolTable.GlobalNs()->GetContainerScope();
    for (const auto& headerFilePath : sourceFileNode.HeaderFilePaths())
    {
        SourceFileNode* headerFileNode = sourceFileResolver->GetSourceFile(headerFilePath);
        if (headerFileNode)
        {
            for (Node* usingDirectiveOrDeclaration : headerFileNode->UsingDirectivesAndDeclarations())
            {
                usingDirectiveOrDeclaration->Accept(*this);
            }
            if (!headerFileNode->Processed())
            {
                headerFileNode->Accept(*this);
            }
        }
    }
    if (!sourceFileNode.Processed())
    {
        fileId = sourceFileNode.Id();
        fileName = sourceFileNode.RelativeSourceFilePath();
        sourceFileNode.GlobalNs()->Accept(*this);
        sourceFileNode.SetProcessed();
        sourceFileMap[&sourceFileNode] = currentSourceFile;
        sourceFiles.push_back(std::move(sourceFile));
    }
    currentSourceFile = prevSourceFile;
    currentAccessSpecifier = prevAccessSpecifier;
}

void TypeBinder::Visit(SourceFileSequenceNode& sourceFileSequenceNode)
{
    sourceFileSequenceNode.Left()->Accept(*this);
    sourceFileSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(SimpleDeclarationNode& simpleDeclarationNode)
{
    simpleDeclarationNode.TypeExpr()->Accept(*this);
    if (simpleDeclarationNode.Declarator())
    {
        idSequence.clear();
        simpleDeclarationNode.Declarator()->Accept(*this);
        ResolveIdSequence();
    }
    Symbol* symbol = symbolTable.GetSymbolNothrow(&simpleDeclarationNode);
    if (symbol && symbol->IsVariableSymbol())
    {
        sngcpp::symbols::TypeSymbol* type = ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::none, currentClass,
            simpleDeclarationNode.TypeExpr());
        VariableSymbol* variableSymbol = static_cast<VariableSymbol*>(symbol);
        variableSymbol->SetAccess(currentAccessSpecifier);
        variableSymbol->SetType(type);
    }
}

void TypeBinder::Visit(AliasDeclarationNode& aliasDeclarationNode)
{
    aliasDeclarationNode.TypeExpr()->Accept(*this);
}

void TypeBinder::Visit(UsingDirectiveNode& usingDirectiveNode)
{
    currentSourceFile->FileScopes().back()->Install(containerScope, usingDirectiveNode);
}

void TypeBinder::Visit(UsingDeclarationNode& usingDeclarationNode)
{
    currentSourceFile->FileScopes().back()->Install(containerScope, usingDeclarationNode);
}

void TypeBinder::Visit(NamespaceNode& namespaceNode)
{
    Specifier prevAccessSpecifier = currentAccessSpecifier;
    currentAccessSpecifier = Specifier::public_;
    symbolTable.BeginNamespace(namespaceNode.NamespaceName(), std::u32string());
    ContainerScope* prevContainerScope = containerScope;
    containerScope = symbolTable.GetContainerScope();
    if (namespaceNode.Child())
    {
        namespaceNode.Child()->Accept(*this);
    }
    symbolTable.EndNamespace();
    containerScope = prevContainerScope;
    currentAccessSpecifier = prevAccessSpecifier;
}

void TypeBinder::Visit(DeclarationSequenceNode& declarationSequenceNode)
{
    declarationSequenceNode.Left()->Accept(*this);
    declarationSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(LinkageSpecificationNode& linkageSpecificationNode)
{
    linkageSpecificationNode.Declarations()->Accept(*this);
}

void TypeBinder::Visit(TypedefNode& typedefNode)
{
    Symbol* symbol = symbolTable.GetSymbolNothrow(&typedefNode);
    if (symbol)
    {
        if (symbol->IsTypedefSymbol())
        {
            TypedefSymbol* typedefSymbol = static_cast<TypedefSymbol*>(symbol);
            typedefSymbol->SetAccess(currentAccessSpecifier);
            sngcpp::symbols::TypeSymbol* type = ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::none , currentClass,
                typedefNode.TypeExpr());
            typedefSymbol->SetType(type);
        }
        else
        {
            throw std::runtime_error("typedef symbol expected");
        }
    }
}

void TypeBinder::Visit(EnumTypeNode& enumTypeNode)
{
    Symbol* symbol = symbolTable.GetSymbol(&enumTypeNode);
    if (symbol->IsEnumTypeSymbol())
    {
        EnumTypeSymbol* enumTypeSymbol = static_cast<EnumTypeSymbol*>(symbol);
        enumTypeSymbol->SetAccess(currentAccessSpecifier);
        enumTypeSymbol->SetFileId(fileId);
        enumTypeSymbol->SetFileName(fileName);
        if (enumTypeNode.EnumBase())
        {
            sngcpp::symbols::TypeSymbol* baseType = ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::none, currentClass,
                enumTypeNode.EnumBase());
            enumTypeSymbol->SetBaseType(baseType);
        }
        ContainerScope* prevContainerScope = containerScope;
        containerScope = enumTypeSymbol->GetContainerScope();
        if (enumTypeNode.Enumerators())
        {
            enumTypeNode.Enumerators()->Accept(*this);
        }
        containerScope = prevContainerScope;
    }
    else
    {
        throw std::runtime_error("enumeration type symbol expected");
    }
}

void TypeBinder::Visit(EnumeratorNode& enumeratorNode)
{
    Symbol* symbol = symbolTable.GetSymbol(&enumeratorNode);
    if (symbol->IsEnumeratorSymbol())
    {
        EnumeratorSymbol* enumeratorSymbol = static_cast<EnumeratorSymbol*>(symbol);
        enumeratorSymbol->SetAccess(Specifier::public_);
    }
    else
    {
        throw std::runtime_error("enumeration constant symbol expected");
    }
}

void TypeBinder::Visit(EnumeratorSequenceNode& enumeratorSequenceNode)
{
    enumeratorSequenceNode.Left()->Accept(*this);
    enumeratorSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(TemplateDeclarationNode& templateDeclarationNode)
{
    templateDeclarationNode.Declaration()->Accept(*this);
}

void TypeBinder::Visit(ForwardClassDeclarationNode& forwardClassDeclarationNode)
{
    ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::nothrow, currentClass, forwardClassDeclarationNode.ClassName());
}

void TypeBinder::Visit(ElaborateClassNameNode& elaborateClassNameNode)
{
    ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::nothrow, currentClass, elaborateClassNameNode.ClassName());
}

void TypeBinder::Visit(ClassNode& classNode)
{
    Symbol* symbol = symbolTable.GetSymbol(&classNode);
    if (symbol->IsClassTypeSymbol())
    {
        ClassTypeSymbol* classTypeSymbol = static_cast<ClassTypeSymbol*>(symbol);
        symbolTable.MapNode(classNode.ClassName(), classTypeSymbol);
        classTypeSymbol->SetAccess(currentAccessSpecifier);
        classTypeSymbol->SetFileId(fileId);
        classTypeSymbol->SetFileName(fileName);
        ContainerScope* prevContainerScope = containerScope;
        containerScope = classTypeSymbol->GetContainerScope();
        ClassTypeSymbol* prevClass = currentClass;
        currentClass = classTypeSymbol;
        if (classNode.BaseClasses())
        {
            classNode.BaseClasses()->Accept(*this);
        }
        if (classNode.Declarations())
        {
            classNode.Declarations()->Accept(*this);
        }
        containerScope = prevContainerScope;
        currentClass = prevClass;
    }
    else
    {
        throw std::runtime_error("class type symbol expected");
    }
}

void TypeBinder::Visit(BaseClassSpecifierSequenceNode& baseClassSpecifierSequenceNode)
{
    baseClassSpecifierSequenceNode.Left()->Accept(*this);
    baseClassSpecifierSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(BaseClassSpecifierNode& baseClassSpecifierNode)
{
    sngcpp::symbols::TypeSymbol* baseClass = ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::notSelf, currentClass,
        baseClassSpecifierNode.ClassName());
    symbolTable.MapNode(&baseClassSpecifierNode, baseClass);
    currentClass->AddBaseClass(baseClass);
    if (baseClass->IsClassTypeSymbol())
    {
        ClassTypeSymbol* base = static_cast<ClassTypeSymbol*>(baseClass);
        if (base->IsClassTemplateSpecializationSymbol())
        {
            ClassTemplateSpecializationSymbol* specialization = static_cast<ClassTemplateSpecializationSymbol*>(base);
            sngcpp::symbols::TypeSymbol* primaryType = specialization->PrimaryClassTemplateSymbol();
            if (primaryType->IsClassTypeSymbol())
            {
                base = static_cast<ClassTypeSymbol*>(primaryType);
            }
        }
        base->AddDerivedClass(currentClass);
    }
}

void TypeBinder::Visit(MemberAccessDeclarationNode& memberAccessDeclarationNode)
{
    Specifier prevAccessSpecifier = currentAccessSpecifier;
    currentAccessSpecifier = memberAccessDeclarationNode.AccessSpecifier();
    memberAccessDeclarationNode.Declaration()->Accept(*this);
    currentAccessSpecifier = prevAccessSpecifier;
}

void TypeBinder::Visit(MemberDeclarationNode& memberDeclarationNode)
{
    FunctionSymbol* prevFunction = currentFunction;
    FunctionDeclarationSymbol* prevFunctionDeclaration = currentFunctionDeclaration;
    if (memberDeclarationNode.Declarator())
    {
        memberDeclarationNode.Declarator()->Accept(*this);
        ResolveIdSequence();
    }
    if (currentFunction && (currentFunction->Specifiers() & Specifier::virtuality) != Specifier::none)
    {
        Symbol* parent = currentFunction->Parent();
        if (parent->IsClassTypeSymbol())
        {
            ClassTypeSymbol* cls = static_cast<ClassTypeSymbol*>(parent);
            cls->AddVirtualFunction(currentFunction);
            classesHavingVirtualFunctions.insert(cls);
        }
    }
    if (memberDeclarationNode.TypeExpr())
    {
        sngcpp::symbols::TypeSymbol* type = ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::none, currentClass,
            memberDeclarationNode.TypeExpr());
        Symbol* symbol = symbolTable.GetSymbolNothrow(&memberDeclarationNode);
        if (symbol && symbol->IsVariableSymbol())
        {
            VariableSymbol* variableSymbol = static_cast<VariableSymbol*>(symbol);
            variableSymbol->SetAccess(currentAccessSpecifier);
            variableSymbol->AddSpecifiers(memberDeclarationNode.Specifiers());
            variableSymbol->SetType(type);
        }
        else
        {
            if (currentFunction)
            {
                currentFunction->SetReturnType(type);
            }
            if (currentFunctionDeclaration)
            {
                currentFunctionDeclaration->SetReturnType(type);
            }
        }
    }
    currentFunctionDeclaration = prevFunctionDeclaration;
    currentFunction = prevFunction;
}

void TypeBinder::Visit(FunctionNode& functionNode)
{
    FunctionSymbol* prevFunction = currentFunction;
    ContainerScope* prevContainserScope = containerScope;
    functionNode.Declarator()->Accept(*this);
    ResolveIdSequence();
    if (currentFunction && currentFunction->FunctionGroup())
    {
        symbolTable.MapNode(&functionNode, currentFunction);
        FunctionDeclarationSymbol* functionDeclaration = currentFunction->FunctionGroup()->GetFunctionDeclaration(currentFunction->Parameters(), currentFunction->Specifiers());
        if (functionDeclaration)
        {
            currentFunction->AddSpecifiers(functionDeclaration->Specifiers());
            currentFunction->SetDeclarationSpan(functionDeclaration->GetSpan());
            currentFunction->SetDeclarationFileId(functionDeclaration->FileId());
            currentFunction->SetDeclarationFileName(functionDeclaration->FileName());
            functionDeclaration->SetFunctionDefinition(currentFunction);
        }
        if ((currentFunction->Specifiers() & Specifier::virtuality) != Specifier::none)
        {
            Symbol* parent = currentFunction->Parent();
            if (parent->IsClassTypeSymbol())
            {
                ClassTypeSymbol* cls = static_cast<ClassTypeSymbol*>(parent);
                cls->AddVirtualFunction(currentFunction);
                classesHavingVirtualFunctions.insert(cls);
            }
        }
        containerScope = currentFunction->GetContainerScope();
        if (functionNode.TypeExpr())
        {
            sngcpp::symbols::TypeSymbol* returnType = ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::none, currentClass,
                functionNode.TypeExpr());
            currentFunction->SetReturnType(returnType);
        }
        if (functionNode.Body())
        {
            functionNode.Body()->Accept(*this);
        }
    }
    else
    {
        if (functionNode.Body())
        {
            functionNode.Body()->Accept(*this);
        }
    }
    currentFunction = prevFunction;
    containerScope = prevContainserScope;
}

void TypeBinder::Visit(SpecialMemberFunctionNode& specialMemberFunctionNode)
{
    FunctionSymbol* prevFunction = currentFunction;
    ContainerScope* prevContainserScope = containerScope;
    specialMemberFunctionNode.Declarator()->Accept(*this);
    ResolveIdSequence();
    if (specialMemberFunctionNode.CtorInitializer())
    {
        specialMemberFunctionNode.CtorInitializer()->Accept(*this);
    }
    if (currentFunction && currentFunction->FunctionGroup())
    {
        symbolTable.MapNode(&specialMemberFunctionNode, currentFunction);
        FunctionDeclarationSymbol* functionDeclaration = currentFunction->FunctionGroup()->GetFunctionDeclaration(currentFunction->Parameters(), currentFunction->Specifiers());
        if (functionDeclaration)
        {
            currentFunction->AddSpecifiers(functionDeclaration->Specifiers());
            currentFunction->SetDeclarationSpan(functionDeclaration->GetSpan());
            currentFunction->SetDeclarationFileId(functionDeclaration->FileId());
            currentFunction->SetDeclarationFileName(functionDeclaration->FileName());
            functionDeclaration->SetFunctionDefinition(currentFunction);
        }
        containerScope = currentFunction->GetContainerScope();
        if (specialMemberFunctionNode.FunctionBody())
        {
            specialMemberFunctionNode.FunctionBody()->Accept(*this);
        }
    }
    else
    {
        if (specialMemberFunctionNode.FunctionBody())
        {
            specialMemberFunctionNode.FunctionBody()->Accept(*this);
        }
    }
    currentFunction = prevFunction;
    containerScope = prevContainserScope;
}

void TypeBinder::Visit(ArrayDeclaratorNode& arrayDeclaratorNode)
{
    arrayDeclaratorNode.Declarator()->Accept(*this);
    if (arrayDeclaratorNode.Size())
    {
        arrayDeclaratorNode.Size()->Accept(*this);
    }
}

void TypeBinder::Visit(InitDeclaratorNode& initDeclaratorNode)
{
    initDeclaratorNode.Declarator()->Accept(*this);
    initDeclaratorNode.Initializer()->Accept(*this);
}

void TypeBinder::Visit(FunctionDeclaratorNode& functionDeclaratorNode)
{
    conversionFunctionType = nullptr;
    functionDeclaratorNode.Declarator()->Accept(*this);
    Symbol* symbol = symbolTable.GetSymbolNothrow(&functionDeclaratorNode);
    if (symbol)
    {
        if (symbol->IsFunctionSymbol())
        {
            FunctionSymbol* functionSymbol = static_cast<FunctionSymbol*>(symbol);
            if (conversionFunctionType)
            {
                functionSymbol->SetName(U"operator " + conversionFunctionType->Name());
            }
            currentFunction = functionSymbol;
            currentFunction->SetFileId(fileId);
            currentFunction->SetFileName(fileName);
            currentFunction->AddSpecifiers(functionDeclaratorNode.CVSpecifiers());
            currentFunctionDeclaration = nullptr;
            ContainerScope* prevContainserScope = containerScope;
            containerScope = functionSymbol->GetContainerScope();
            functionSymbol->SetAccess(currentAccessSpecifier);
            if (functionDeclaratorNode.Parameters())
            {
                functionDeclaratorNode.Parameters()->Accept(*this);
            }
            containerScope = prevContainserScope;
        }
        else if (symbol->IsFunctionDeclarationSymbol())
        {
            FunctionDeclarationSymbol* functionDeclarationSymbol = static_cast<FunctionDeclarationSymbol*>(symbol);
            if (conversionFunctionType)
            {
                functionDeclarationSymbol->SetName(U"operator " + conversionFunctionType->Name());
            }
            currentFunction = nullptr;
            currentFunctionDeclaration = functionDeclarationSymbol;
            currentFunctionDeclaration->SetFileId(fileId);
            currentFunctionDeclaration->SetFileName(fileName);
            currentFunctionDeclaration->AddSpecifiers(functionDeclaratorNode.CVSpecifiers());
            ContainerScope* prevContainserScope = containerScope;
            containerScope = functionDeclarationSymbol->GetContainerScope();
            if (functionDeclaratorNode.Parameters())
            {
                functionDeclaratorNode.Parameters()->Accept(*this);
            }
            containerScope = prevContainserScope;
        }
        else
        {
            throw std::runtime_error("function or function declaration symbol expected");
        }
    }
    else
    {
        currentFunction = nullptr;
        currentFunctionDeclaration = nullptr;
    }
}

void TypeBinder::Visit(ParameterNode& parameterNode)
{
    Symbol* symbol = symbolTable.GetSymbol(&parameterNode);
    if (symbol->IsParameterSymbol())
    {
        sngcpp::symbols::ParameterSymbol* parameterSymbol = static_cast<sngcpp::symbols::ParameterSymbol*>(symbol);
        sngcpp::symbols::TypeSymbol* type = ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::none, currentClass,
            parameterNode.TypeExpr());
        parameterSymbol->SetType(type);
    }
    else
    {
        throw std::runtime_error("parameter symbol expected");
    }
}

void TypeBinder::Visit(ParameterSequenceNode& parameterSequenceNode)
{
    parameterSequenceNode.Left()->Accept(*this);
    parameterSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(IdDeclaratorNode& idDeclaratorNode)
{
    idSequence.clear();
    idDeclaratorNode.IdNode()->Accept(*this);
}

void TypeBinder::Visit(ConversionFunctionIdNode& conversionFunctionIdNode)
{
    conversionFunctionType = ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::none , currentClass,
        conversionFunctionIdNode.TypeExpr());
}

void TypeBinder::Visit(LambdaExpressionNode& lambdaExpressionNode)
{
    if (lambdaExpressionNode.Parameters())
    {
        lambdaExpressionNode.Parameters()->Accept(*this);
    }
    lambdaExpressionNode.Body()->Accept(*this);
}

void TypeBinder::Visit(NestedIdNode& nestedIdNode)
{
    if (nestedIdNode.Left())
    {
        nestedIdNode.Left()->Accept(*this);
    }
    nestedIdNode.Right()->Accept(*this);
}

void TypeBinder::Visit(IdentifierNode& identifierNode)
{
    idSequence.push_back(&identifierNode);
}

void TypeBinder::Visit(DtorIdNode& dtorIdNode)
{
    idSequence.push_back(&dtorIdNode);
}

void TypeBinder::Visit(LabeledStatementNode& labeledStatementNode)
{
    labeledStatementNode.Child()->Accept(*this);
}

void TypeBinder::Visit(CaseStatementNode& caseStatementNode)
{
    caseStatementNode.CaseExpr()->Accept(*this);
    caseStatementNode.Child()->Accept(*this);
}

void TypeBinder::Visit(DefaultStatementNode& defaultStatementNode)
{
    defaultStatementNode.Child()->Accept(*this);
}

void TypeBinder::Visit(ExpressionStatementNode& expressionStatementNode)
{
    if (expressionStatementNode.Child())
    {
        expressionStatementNode.Child()->Accept(*this);
    }
}

void TypeBinder::Visit(CompoundStatementNode& compoundStatementNode)
{
    if (compoundStatementNode.Child())
    {
        compoundStatementNode.Child()->Accept(*this);
    }
}

void TypeBinder::Visit(StatementSequenceNode& statementSequenceNode)
{
    statementSequenceNode.Left()->Accept(*this);
    statementSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(IfStatementNode& ifStatementNode)
{
    ifStatementNode.Condition()->Accept(*this);
    ifStatementNode.ThenS()->Accept(*this);
    if (ifStatementNode.ElseS())
    {
        ifStatementNode.ElseS()->Accept(*this);
    }
}

void TypeBinder::Visit(SwitchStatementNode& switchStatementNode)
{
    switchStatementNode.Condition()->Accept(*this);
    switchStatementNode.Statement()->Accept(*this);
}

void TypeBinder::Visit(WhileStatementNode& whileStatementNode)
{
    whileStatementNode.Condition()->Accept(*this);
    whileStatementNode.Statement()->Accept(*this);
}

void TypeBinder::Visit(DoStatementNode& doStatementNode)
{
    doStatementNode.Statement()->Accept(*this);
    doStatementNode.Condition()->Accept(*this);
}

void TypeBinder::Visit(RangeForStatementNode& rangeForStatementNode)
{
    rangeForStatementNode.ForRangeDeclaration()->Accept(*this);
    rangeForStatementNode.ForRangeInitializer()->Accept(*this);
    rangeForStatementNode.Statement()->Accept(*this);
}

void TypeBinder::Visit(ForStatementNode& forStatementNode)
{
    if (forStatementNode.InitS())
    {
        forStatementNode.InitS()->Accept(*this);
    }
    if (forStatementNode.Condition())
    {
        forStatementNode.Condition()->Accept(*this);
    }
    if (forStatementNode.LoopExpr())
    {
        forStatementNode.LoopExpr()->Accept(*this);
    }
    forStatementNode.ActionS()->Accept(*this);
}

void TypeBinder::Visit(ReturnStatementNode& returnStatementNode)
{
    if (returnStatementNode.ReturnExpr())
    {
        returnStatementNode.ReturnExpr()->Accept(*this);
    }
}

void TypeBinder::Visit(DeclarationStatementNode& declarationStatementNode)
{
    declarationStatementNode.Child()->Accept(*this);
}

void TypeBinder::Visit(TryStatementNode& tryStatementNode)
{
    tryStatementNode.TryBlock()->Accept(*this);
    tryStatementNode.Handlers()->Accept(*this);
}

void TypeBinder::Visit(HandlerNode& handlerNode)
{
    handlerNode.ExceptionDeclaration()->Accept(*this);
    handlerNode.CatchBlock()->Accept(*this);
}

void TypeBinder::Visit(HandlerSequenceNode& handlerSequenceNode)
{
    handlerSequenceNode.Left()->Accept(*this);
    handlerSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(ExpressionSequenceNode& expressionSequenceNode)
{
    expressionSequenceNode.Left()->Accept(*this);
    expressionSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(ExpressionListInitializerNode& expressionListInitializer)
{
    if (expressionListInitializer.Child())
    {
        expressionListInitializer.Child()->Accept(*this);
    }
}

void TypeBinder::Visit(AssignmentInitializerNode& assignmentInitializerNode)
{
    assignmentInitializerNode.Child()->Accept(*this);
}

void TypeBinder::Visit(ExpressionInitializerNode& expressionInitializerNode)
{
    if (expressionInitializerNode.Child())
    {
        expressionInitializerNode.Child()->Accept(*this);
    }
}

void TypeBinder::Visit(CommaExpressionNode& commaExpressionNode)
{
    commaExpressionNode.Left()->Accept(*this);
    commaExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(AssignmentExpressionNode& assignmentExpressionNode)
{
    assignmentExpressionNode.Left()->Accept(*this);
    assignmentExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(ConditionalExpressionNode& conditionalExpressionNode)
{
    conditionalExpressionNode.Condition()->Accept(*this);
    conditionalExpressionNode.ThenExpr()->Accept(*this);
    conditionalExpressionNode.ElseExpr()->Accept(*this);
}

void TypeBinder::Visit(ThrowExpressionNode& throwExpressionNode)
{
    if (throwExpressionNode.Child())
    {
        throwExpressionNode.Child()->Accept(*this);
    }
}

void TypeBinder::Visit(LogicalOrExpressionNode& logicalOrExpressionNode)
{
    logicalOrExpressionNode.Left()->Accept(*this);
    logicalOrExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(LogicalAndExpressionNode& logicalAndExpressionNode)
{
    logicalAndExpressionNode.Left()->Accept(*this);
    logicalAndExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(InclusiveOrExpressionNode& inclusiveOrExpressionNode)
{
    inclusiveOrExpressionNode.Left()->Accept(*this);
    inclusiveOrExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(ExclusiveOrExpressionNode& exclusiveOrExpressionNode)
{
    exclusiveOrExpressionNode.Left()->Accept(*this);
    exclusiveOrExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(AndExpressionNode& andExpressionNode)
{
    andExpressionNode.Left()->Accept(*this);
    andExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(EqualityExpressionNode& equalityExpressionNode)
{
    equalityExpressionNode.Left()->Accept(*this);
    equalityExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(RelationalExpressionNode& relationalExpressionNode)
{
    relationalExpressionNode.Left()->Accept(*this);
    relationalExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(ShiftExpressionNode& shiftExpressionNode)
{
    shiftExpressionNode.Left()->Accept(*this);
    shiftExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(AdditiveExpressionNode& additiveExpressionNode)
{
    additiveExpressionNode.Left()->Accept(*this);
    additiveExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(MultiplicativeExpressionNode& multiplicativeExpressionNode)
{
    multiplicativeExpressionNode.Left()->Accept(*this);
    multiplicativeExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(PMExpressionNode& pmExpressionNode)
{
    pmExpressionNode.Left()->Accept(*this);
    pmExpressionNode.Right()->Accept(*this);
}

void TypeBinder::Visit(CastExpressionNode& castExpressionNode)
{
    castExpressionNode.TypeExpr()->Accept(*this);
    castExpressionNode.Expr()->Accept(*this);
}

void TypeBinder::Visit(UnaryExpressionNode& unaryExpressionNode)
{
    unaryExpressionNode.Child()->Accept(*this);
}

void TypeBinder::Visit(NewExpressionNode& newExpressionNode)
{
    if (newExpressionNode.Placement())
    {
        newExpressionNode.Placement()->Accept(*this);
    }
    newExpressionNode.TypeExpr()->Accept(*this);
    if (newExpressionNode.Initializer())
    {
        newExpressionNode.Initializer()->Accept(*this);
    }
}

void TypeBinder::Visit(SubscriptExpressionNode& subscriptExpressionNode)
{
    subscriptExpressionNode.Child()->Accept(*this);
    subscriptExpressionNode.Index()->Accept(*this);
}

void TypeBinder::Visit(InvokeExpressionNode& invokeExpressionNode)
{
    invokeExpressionNode.Child()->Accept(*this);
    if (invokeExpressionNode.Arguments())
    {
        invokeExpressionNode.Arguments()->Accept(*this);
    }
}

void TypeBinder::Visit(DotNode& dotNode)
{
    dotNode.Child()->Accept(*this);
    dotNode.Id()->Accept(*this);
}

void TypeBinder::Visit(ArrowNode& arrowNode)
{
    arrowNode.Child()->Accept(*this);
    arrowNode.Id()->Accept(*this);
}

void TypeBinder::Visit(PostfixIncNode& postfixIncNode)
{
    postfixIncNode.Child()->Accept(*this);
}

void TypeBinder::Visit(PostfixDecNode& postfixDecNode)
{
    postfixDecNode.Child()->Accept(*this);
}

void TypeBinder::Visit(CppCastExpressionNode& cppCastExpressionNode)
{
    cppCastExpressionNode.TypeExpr()->Accept(*this);
    cppCastExpressionNode.Expr()->Accept(*this);
}

void TypeBinder::Visit(TypeIdExpressionNode& typeIdExpressionNode)
{
    typeIdExpressionNode.Child()->Accept(*this);
}

void TypeBinder::Visit(TypeParameterNode& typeParameterNode)
{
    if (typeParameterNode.DefaultTemplateParameter())
    {
        typeParameterNode.DefaultTemplateParameter()->Accept(*this);
    }
}

void TypeBinder::Visit(TemplateParameterSequenceNode& templateParameterSequenceNode)
{
    templateParameterSequenceNode.Left()->Accept(*this);
    templateParameterSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(TemplateArgumentSequenceNode& templateArgumentSequenceNode)
{
    templateArgumentSequenceNode.Left()->Accept(*this);
    templateArgumentSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(TemplateIdNode& templateIdNode)
{
    templateIdNode.Id()->Accept(*this);
    if (templateIdNode.TemplateArguments())
    {
        templateIdNode.TemplateArguments()->Accept(*this);
    }
}

void TypeBinder::Visit(TemplateArgumentNode& templateArgumentNode)
{
    if (templateArgumentNode.Arg())
    {
        templateArgumentNode.Arg()->Accept(*this);
    }
}

void TypeBinder::Visit(CtorInitializerNode& ctorInitializerNode)
{
    if (ctorInitializerNode.Child())
    {
        ctorInitializerNode.Child()->Accept(*this);
    }
}

void TypeBinder::Visit(ParenthesizedExprNode& parenthesizedExprNode)
{
    parenthesizedExprNode.Child()->Accept(*this);
}

void TypeBinder::Visit(BracedInitializerListNode& bracedInitializerListNode)
{
    if (bracedInitializerListNode.Child())
    {
        bracedInitializerListNode.Child()->Accept(*this);
    }
}

void TypeBinder::Visit(MemberInitializerNode& memberInitializerNode)
{
    sngcpp::symbols::TypeSymbol* type = ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::nothrow | TypeResolverFlags::noExternalTypes, currentClass,
        memberInitializerNode.Id());
    memberInitializerNode.Id()->Accept(*this);
    if (memberInitializerNode.Initializer())
    {
        memberInitializerNode.Initializer()->Accept(*this);
    }
}

void TypeBinder::Visit(MemberInitializerSequenceNode& memberInitializerSequenceNode)
{
    memberInitializerSequenceNode.Left()->Accept(*this);
    memberInitializerSequenceNode.Right()->Accept(*this);
}

void TypeBinder::Visit(StringLiteralNode& stringLiteralNode)
{
    sngcpp::symbols::TypeSymbol* type = ResolveType(symbolTable, containerScope, std::vector<ContainerScope*>(), *currentSourceFile, TypeResolverFlags::nothrow | TypeResolverFlags::noExternalTypes, currentClass,
        &stringLiteralNode);
}

} } // namespace sngcpp::binder
