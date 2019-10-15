// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/SymbolCreator.hpp>
#include <sngcpp/symbols/SymbolTable.hpp>
#include <sngcpp/symbols/TemplateSymbol.hpp>
#include <sngcpp/symbols/ParameterSymbol.hpp>
#include <sngcpp/ast/SourceFile.hpp>
#include <sngcpp/ast/Expression.hpp>
#include <sngcpp/ast/Template.hpp>
#include <sngcpp/ast/Enumeration.hpp>
#include <sngcpp/ast/TypeExpr.hpp>

namespace sngcpp { namespace symbols {

SymbolCreator::SymbolCreator(SymbolTable& symbolTable_, const std::u32string& projectName_) :
    symbolTable(symbolTable_), projectName(projectName_), functionBodyFollowsOrIsPure(false), nameSequenceCount(0), wasFunctionDeclaration(false), wasArrayDeclaration(false),
    specifiers(Specifier::none), skip(false), processingTemplateArguments(false)
{
}

void SymbolCreator::Visit(SourceFileNode& sourceFileNode)
{
    if (sourceFileNode.RelativeSourceFilePath() == "BasicTypeOperation.hpp")
    {
        int x = 0;
    }
    sourceFileNode.GlobalNs()->Accept(*this);
}

void SymbolCreator::Visit(SourceFileSequenceNode& sourceFileSequenceNode)
{
    sourceFileSequenceNode.Left()->Accept(*this);
    sourceFileSequenceNode.Right()->Accept(*this);
}

void SymbolCreator::Visit(NamespaceNode& namespaceNode)
{
    symbolTable.BeginNamespace(namespaceNode.NamespaceName(), projectName);
    if (namespaceNode.Child())
    {
        namespaceNode.Child()->Accept(*this);
    }
    symbolTable.EndNamespace();
}

void SymbolCreator::Visit(DeclarationSequenceNode& declarationSequenceNode)
{
    declarationSequenceNode.Left()->Accept(*this);
    declarationSequenceNode.Right()->Accept(*this);
}

void SymbolCreator::Visit(TypedefNode& typedefNode)
{
    nameSequence.clear();
    typedefNode.Declarator()->Accept(*this);
    if (!nameSequence.empty())
    {
        int n = symbolTable.BeginNameSequence(nameSequence);
        symbolTable.AddTypedef(&typedefNode, nameSequence.back().first, projectName);
        symbolTable.EndNameSequence(n);
    }
}

void SymbolCreator::Visit(TypeParameterNode& typeParameterNode)
{
    std::unique_ptr<TemplateParameterSymbol> templateParameterSymbol(new TemplateParameterSymbol(typeParameterNode.GetSpan(), typeParameterNode.Id()));
    templateParameterSymbol->SetAccess(Specifier::public_);
    templateParameters.push_back(std::move(templateParameterSymbol));
}

void SymbolCreator::Visit(TemplateParameterSequenceNode& templateParameterSequenceNode)
{
    templateParameterSequenceNode.Left()->Accept(*this);
    templateParameterSequenceNode.Right()->Accept(*this);
}

void SymbolCreator::Visit(TemplateDeclarationNode& templateDeclarationNode)
{
    templateParameters.clear();
    if (templateDeclarationNode.TemplateParameters())
    {
        templateDeclarationNode.TemplateParameters()->Accept(*this);
    }
    templateDeclarationNode.Declaration()->Accept(*this);
}

void SymbolCreator::Visit(ClassNode& classNode)
{
    nameSequence.clear();
    classNode.ClassName()->Accept(*this);
    int n = symbolTable.BeginNameSequence(nameSequence);
    symbolTable.BeginClass(&classNode, nameSequence.back().first, templateParameters);
    templateParameters.clear();
    if (classNode.Declarations())
    {
        classNode.Declarations()->Accept(*this);
    }
    symbolTable.EndClass(projectName);
    symbolTable.EndNameSequence(n);
}

void SymbolCreator::Visit(MemberAccessDeclarationNode& memberAccessDeclarationNode)
{
    if (memberAccessDeclarationNode.Declaration())
    {
        memberAccessDeclarationNode.Declaration()->Accept(*this);
    }
}

void SymbolCreator::Visit(MemberDeclarationNode& memberDeclarationNode)
{
    bool prevFunctionBodyFollowsOrIsPure = functionBodyFollowsOrIsPure;
    bool prevWasFunctionDeclaration = wasFunctionDeclaration;
    bool prevWasArrayDeclaration = wasArrayDeclaration;
    wasFunctionDeclaration = false;
    wasArrayDeclaration = false;
    if (memberDeclarationNode.Declarator())
    {
        specifiers = memberDeclarationNode.Specifiers();
        bool wasPure = false;
        if ((specifiers & Specifier::pure_) != Specifier::none)
        {
            wasPure = true;
            functionBodyFollowsOrIsPure = true;
        }
        memberDeclarationNode.Declarator()->Accept(*this);
        if (wasPure)
        {
            symbolTable.EndFunction(projectName);
            symbolTable.EndNameSequence(nameSequenceCount);
        }
        if (!wasFunctionDeclaration && !wasArrayDeclaration)
        {
            int n = symbolTable.BeginNameSequence(nameSequence);
            std::u32string variableName = nameSequence.back().first;
            symbolTable.AddVariable(&memberDeclarationNode, variableName, projectName);
            symbolTable.EndNameSequence(n);
        }
    }
    wasFunctionDeclaration = prevWasFunctionDeclaration;
    wasArrayDeclaration = prevWasArrayDeclaration;
    functionBodyFollowsOrIsPure = prevFunctionBodyFollowsOrIsPure;
}

void SymbolCreator::Visit(ArrayDeclaratorNode& arrayDeclaratorNode)
{
    wasArrayDeclaration = true;
}

void SymbolCreator::Visit(EnumTypeNode& enumTypeNode)
{
    nameSequence.clear();
    enumTypeNode.EnumName()->Accept(*this);
    int n = symbolTable.BeginNameSequence(nameSequence);
    symbolTable.BeginEnumType(&enumTypeNode, nameSequence.back().first);
    if (enumTypeNode.Enumerators())
    {
        enumTypeNode.Enumerators()->Accept(*this);
    }
    symbolTable.EndEnumType(projectName);
    symbolTable.EndNameSequence(n);
}

void SymbolCreator::Visit(EnumeratorNode& enumeratorNode)
{
    symbolTable.AddEnumerator(&enumeratorNode, enumeratorNode.Enumerator(), enumeratorNode.ValueStr());
}

void SymbolCreator::Visit(EnumeratorSequenceNode& enumeratorSequenceNode)
{
    enumeratorSequenceNode.Left()->Accept(*this);
    enumeratorSequenceNode.Right()->Accept(*this);
}

void SymbolCreator::Visit(IdentifierNode& identifierNode)
{
    if (processingTemplateArguments)
    {
        int n = templateParameters.size();
        for (int i = 0; i < n; ++i)
        {
            TypeSymbol* templateParameterSymbol = templateParameters[i].get();
            if (templateParameterSymbol->Name() == identifierNode.Identifier())
            {
                templateParameters.erase(templateParameters.begin() + i);
                break;
            }
        }
    }
    else
    {
        nameSequence.push_back(std::make_pair(identifierNode.Identifier(), 0));
        groupName = identifierNode.Identifier();
    }
}

void SymbolCreator::Visit(TemplateIdNode& templateIdNode)
{
    nameSequence.push_back(std::make_pair(templateIdNode.Id()->Identifier(), templateIdNode.Arity()));
    groupName = templateIdNode.Id()->Identifier();
    if (functionBodyFollowsOrIsPure)
    {
        if (templateIdNode.TemplateArguments())
        {
            bool prevProcessingTemplateArguments = processingTemplateArguments;
            processingTemplateArguments = true;
            templateIdNode.TemplateArguments()->Accept(*this);
            processingTemplateArguments = prevProcessingTemplateArguments;
        }
    }
}

void SymbolCreator::Visit(TemplateArgumentNode& templateArgumentNode)
{
    templateArgumentNode.Arg()->Accept(*this);
}

void SymbolCreator::Visit(TypeExprNode& typerExprNode)
{
    if (processingTemplateArguments && typerExprNode.Child())
    {
        typerExprNode.Child()->Accept(*this);
    }
}

void SymbolCreator::Visit(OperatorFunctionIdNode& operatorFunctionIdNode)
{
    nameSequence.push_back(std::make_pair(operatorFunctionIdNode.Str(), 0));
    groupName = operatorFunctionIdNode.GroupName();
}

void SymbolCreator::Visit(ConversionFunctionIdNode& conversionFunctionIdNode)
{
    nameSequence.push_back(std::make_pair(U"operator_conv", 0));
    groupName = U"operator_conv";
}

void SymbolCreator::Visit(NestedIdNode& nestedIdNode)
{
    if (nestedIdNode.Left())
    {
        nestedIdNode.Left()->Accept(*this);
    }
    else
    {
        nameSequence.push_back(std::make_pair(std::u32string(), 0));
    }
    nestedIdNode.Right()->Accept(*this);
}

void SymbolCreator::Visit(DtorIdNode& dDtorIdNode)
{
    nameSequence.push_back(std::make_pair(U"~" + dDtorIdNode.Identifier(), 0));
    groupName = U"destructor";
}

void SymbolCreator::Visit(SimpleDeclarationNode& simpleDeclarationNode)
{
    bool prevWasFunctionDeclaration = wasFunctionDeclaration;
    bool prevWasArrayDeclaration = wasArrayDeclaration;
    wasFunctionDeclaration = false;
    wasArrayDeclaration = false;
    bool hasDeclarator = true;
    if (simpleDeclarationNode.Declarator())
    {
        simpleDeclarationNode.Declarator()->Accept(*this);
    }
    else
    {
        hasDeclarator = false;
        nameSequence.clear();
    }
    if (!wasFunctionDeclaration && !wasArrayDeclaration)
    {
        int n = symbolTable.BeginNameSequence(nameSequence);
        std::u32string variableName;
        if (hasDeclarator)
        {
            variableName = nameSequence.back().first;
        }
        symbolTable.AddVariable(&simpleDeclarationNode, variableName, projectName);
        symbolTable.EndNameSequence(n);
    }
    wasArrayDeclaration = prevWasArrayDeclaration;
    wasFunctionDeclaration = prevWasFunctionDeclaration;
}

void SymbolCreator::Visit(InitDeclaratorNode& initDeclaratorNode)
{
    initDeclaratorNode.Declarator()->Accept(*this);
}

void SymbolCreator::Visit(FunctionDeclaratorNode& functionDeclaratorNode)
{
    wasFunctionDeclaration = true;
    skip = false;
    if (functionBodyFollowsOrIsPure)
    {
        functionDeclaratorNode.Declarator()->Accept(*this);
        if (!nameSequence.empty())
        {
            if (groupName != U"destructor" && !skip)
            {
                specifiers = specifiers | functionDeclaratorNode.CVSpecifiers();
                nameSequenceCount = symbolTable.BeginNameSequence(nameSequence);
                symbolTable.BeginFunction(&functionDeclaratorNode, groupName, nameSequence.back().first, templateParameters, specifiers);
                templateParameters.clear();
                if (functionDeclaratorNode.Parameters())
                {
                    functionDeclaratorNode.Parameters()->Accept(*this);
                }
            }
        }
    }
    else
    {
        functionDeclaratorNode.Declarator()->Accept(*this);
        if (!nameSequence.empty() && !skip)
        {
            specifiers = specifiers | functionDeclaratorNode.CVSpecifiers();
            int n = symbolTable.BeginNameSequence(nameSequence);
            symbolTable.BeginFunctionDeclaration(&functionDeclaratorNode, groupName, nameSequence.back().first, specifiers);
            templateParameters.clear();
            if (functionDeclaratorNode.Parameters())
            {
                functionDeclaratorNode.Parameters()->Accept(*this);
            }
            symbolTable.EndFunctionDeclaration();
            symbolTable.EndNameSequence(n);
        }
    }
}

void SymbolCreator::Visit(FunctionPtrIdNode& functionPtrIdNode)
{
    skip = true;
}

void SymbolCreator::Visit(MemberFunctionPtrIdNode& memberFunctionPtrIdNode)
{
    skip = true;
}

void SymbolCreator::Visit(FunctionNode& functionNode)
{
    bool prevFunctionBodyFollowsOrIsPure = functionBodyFollowsOrIsPure;
    int prevNameSequenceCount = nameSequenceCount;
    functionBodyFollowsOrIsPure = true;
    specifiers = functionNode.Specifiers();
    functionNode.Declarator()->Accept(*this);
    if (functionNode.Body() && groupName != U"destructor")
    {
        functionNode.Body()->Accept(*this);
        symbolTable.EndFunction(projectName);
        symbolTable.EndNameSequence(nameSequenceCount);
    }
    functionBodyFollowsOrIsPure = prevFunctionBodyFollowsOrIsPure;
    nameSequenceCount = prevNameSequenceCount;
}

void SymbolCreator::Visit(SpecialMemberFunctionNode& specialMemberFunctionNode)
{
    bool prevFunctionBodyFollowsOrIsPure = functionBodyFollowsOrIsPure;
    int prevNameSequenceCount = nameSequenceCount;
    functionBodyFollowsOrIsPure = true;
    specifiers = specialMemberFunctionNode.Specifiers();
    specialMemberFunctionNode.Declarator()->Accept(*this);
    if (specialMemberFunctionNode.FunctionBody() && groupName != U"destructor")
    {
        specialMemberFunctionNode.FunctionBody()->Accept(*this);
        symbolTable.EndFunction(projectName);
        symbolTable.EndNameSequence(nameSequenceCount);
    }
    functionBodyFollowsOrIsPure = prevFunctionBodyFollowsOrIsPure;
    nameSequenceCount = prevNameSequenceCount;
}

void SymbolCreator::Visit(CompoundStatementNode& compoundStatementNode)
{
    symbolTable.BeginDeclarationBlock(&compoundStatementNode);
    if (compoundStatementNode.Child())
    {
        compoundStatementNode.Child()->Accept(*this);
    }
    symbolTable.EndDeclarationBlock();
}

void SymbolCreator::Visit(StatementSequenceNode& statementSequenceNode)
{
    statementSequenceNode.Left()->Accept(*this);
    statementSequenceNode.Right()->Accept(*this);
}

void SymbolCreator::Visit(DeclarationStatementNode& declarationStatementNode)
{
    declarationStatementNode.Child()->Accept(*this);
}

void SymbolCreator::Visit(IfStatementNode& ifStatementNode)
{
    symbolTable.BeginDeclarationBlock(&ifStatementNode);
    ifStatementNode.Condition()->Accept(*this);
    ifStatementNode.ThenS()->Accept(*this);
    if (ifStatementNode.ElseS())
    {
        ifStatementNode.ElseS()->Accept(*this);
    }
    symbolTable.EndDeclarationBlock();
}

void SymbolCreator::Visit(SwitchStatementNode& switchStatementNode)
{
    symbolTable.BeginDeclarationBlock(&switchStatementNode);
    switchStatementNode.Condition()->Accept(*this);
    switchStatementNode.Statement()->Accept(*this);
    symbolTable.EndDeclarationBlock();
}

void SymbolCreator::Visit(CaseStatementNode& caseStatementNode)
{
    caseStatementNode.Child()->Accept(*this);
}

void SymbolCreator::Visit(DefaultStatementNode& defaultStatementNode)
{
    defaultStatementNode.Child()->Accept(*this);
}

void SymbolCreator::Visit(WhileStatementNode& whileStatementNode)
{
    symbolTable.BeginDeclarationBlock(&whileStatementNode);
    whileStatementNode.Condition()->Accept(*this);
    whileStatementNode.Statement()->Accept(*this);
    symbolTable.EndDeclarationBlock();
}

void SymbolCreator::Visit(DoStatementNode& doStatementNode)
{
    doStatementNode.Statement()->Accept(*this);
}

void SymbolCreator::Visit(RangeForStatementNode& rangeForStatementNode)
{
    symbolTable.BeginDeclarationBlock(&rangeForStatementNode);
    rangeForStatementNode.ForRangeDeclaration()->Accept(*this);
    rangeForStatementNode.Statement()->Accept(*this);
    symbolTable.EndDeclarationBlock();
}

void SymbolCreator::Visit(ForStatementNode& forStatementNode)
{
    symbolTable.BeginDeclarationBlock(&forStatementNode);
    if (forStatementNode.InitS())
    {
        forStatementNode.InitS()->Accept(*this);
    }
    if (forStatementNode.Condition())
    {
        forStatementNode.Condition()->Accept(*this);
    }
    forStatementNode.ActionS()->Accept(*this);
    symbolTable.EndDeclarationBlock();
}

void SymbolCreator::Visit(TryStatementNode& tryStatementNode)
{
    tryStatementNode.TryBlock()->Accept(*this);
    tryStatementNode.Handlers()->Accept(*this);
}

void SymbolCreator::Visit(HandlerNode& handlerNode)
{
    symbolTable.BeginDeclarationBlock(&handlerNode);
    handlerNode.ExceptionDeclaration()->Accept(*this);
    handlerNode.CatchBlock()->Accept(*this);
    symbolTable.EndDeclarationBlock();
}

void SymbolCreator::Visit(HandlerSequenceNode& handlerSequenceNode)
{
    handlerSequenceNode.Left()->Accept(*this);
    handlerSequenceNode.Right()->Accept(*this);
}

void SymbolCreator::Visit(IdDeclaratorNode& idDeclaratorNode)
{
    nameSequence.clear();
    idDeclaratorNode.IdNode()->Accept(*this);
}

void SymbolCreator::Visit(ParameterNode& parameterNode)
{
    std::u32string parameterName;
    if (parameterNode.Declarator())
    {
        parameterNode.Declarator()->Accept(*this);
        parameterName = nameSequence.back().first;
    }
    else
    {
        nameSequence.clear();
    }
    int n = symbolTable.BeginNameSequence(nameSequence);
    symbolTable.AddParameter(&parameterNode, parameterName);
    symbolTable.EndNameSequence(n);
}

void SymbolCreator::Visit(ParameterSequenceNode& parameterSequenceNode)
{
    parameterSequenceNode.Left()->Accept(*this);
    parameterSequenceNode.Right()->Accept(*this);
}

} } // namespace sngcpp::symbols
