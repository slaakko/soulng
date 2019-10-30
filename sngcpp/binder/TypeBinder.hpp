// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_BINDER_TYPE_BINDER_INCLUDED
#define SNGCPP_BINDER_TYPE_BINDER_INCLUDED
#include <sngcpp/binder/BoundSourceFile.hpp>
#include <sngcpp/symbols/Scope.hpp>
#include <sngcpp/symbols/SymbolTable.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <unordered_set>

namespace sngcpp { namespace binder {

class SNGCPP_BINDER_API SourceFileResolver
{
public:
    virtual SourceFileNode* GetSourceFile(const std::string& sourceFilePath) const = 0;
};

class SNGCPP_BINDER_API TypeBinder : public sngcpp::ast::Visitor
{
public:
    TypeBinder(SymbolTable& symbolTable_, SourceFileResolver* sourceFileResolver_);
    TypeBinder(const TypeBinder&) = delete;
    TypeBinder(TypeBinder&&) = delete;
    TypeBinder& operator=(const TypeBinder&) = delete;
    TypeBinder& operator=(TypeBinder&&) = delete;
    std::vector<std::unique_ptr<BoundSourceFile>> SourceFiles() { return std::move(sourceFiles); }
    std::unordered_map<SourceFileNode*, BoundSourceFile*> SourceFileMap() { return std::move(sourceFileMap); }
    void ResolveIdSequence();
    void Visit(SourceFileNode& sourceFileNode) override;
    void Visit(SourceFileSequenceNode& sourceFileSequenceNode) override;
    void Visit(SimpleDeclarationNode& simpleDeclarationNode) override;
    void Visit(AliasDeclarationNode& aliasDeclarationNode) override;
    void Visit(UsingDirectiveNode& usingDirectiveNode) override;
    void Visit(UsingDeclarationNode& usingDeclarationNode) override;
    void Visit(NamespaceNode& namespaceNode) override;
    void Visit(DeclarationSequenceNode& declarationSequenceNode) override;
    void Visit(TypedefNode& typedefNode) override;
    void Visit(EnumTypeNode& enumTypeNode) override;
    void Visit(EnumeratorNode& enumeratorNode) override;
    void Visit(EnumeratorSequenceNode& enumeratorSequenceNode) override;
    void Visit(TemplateDeclarationNode& templateDeclarationNode) override;
    void Visit(ForwardClassDeclarationNode& forwardClassDeclarationNode) override;
    void Visit(ElaborateClassNameNode& elaborateClassNameNode) override;
    void Visit(ClassNode& classNode) override;
    void Visit(BaseClassSpecifierSequenceNode& baseClassSpecifierSequenceNode) override;
    void Visit(BaseClassSpecifierNode& baseClassSpecifierNode) override;
    void Visit(MemberAccessDeclarationNode& memberAccessDeclarationNode) override;
    void Visit(MemberDeclarationNode& memberDeclarationNode) override;
    void Visit(FunctionNode& functionNode) override;
    void Visit(FunctionDeclaratorNode& functionDeclaratorNode) override;
    void Visit(SpecialMemberFunctionNode& specialMemberFunctionNode) override;
    void Visit(ArrayDeclaratorNode& arrayDeclaratorNode) override;
    void Visit(InitDeclaratorNode& initDeclaratorNode) override;
    void Visit(ParameterNode& parameterNode) override;
    void Visit(ParameterSequenceNode& parameterSequenceNode) override;
    void Visit(IdDeclaratorNode& idDeclaratorNode) override;
    void Visit(ConversionFunctionIdNode& conversionFunctionIdNode) override;
    void Visit(LambdaExpressionNode& lambdaExpressionNode) override;
    void Visit(NestedIdNode& nestedIdNode) override;
    void Visit(IdentifierNode& identifierNode) override;
    void Visit(LabeledStatementNode& labeledStatementNode) override;
    void Visit(CaseStatementNode& caseStatementNode) override;
    void Visit(DefaultStatementNode& defaultStatementNode) override;
    void Visit(ExpressionStatementNode& expressionStatementNode) override;
    void Visit(CompoundStatementNode& compoundStatementNode) override;
    void Visit(StatementSequenceNode& statementSequenceNode) override;
    void Visit(IfStatementNode& ifStatementNode) override;
    void Visit(SwitchStatementNode& switchStatementNode) override;
    void Visit(WhileStatementNode& whileStatementNode) override;
    void Visit(DoStatementNode& doStatementNode) override;
    void Visit(RangeForStatementNode& rangeForStatementNode) override;
    void Visit(ForStatementNode& forStatementNode) override;
    void Visit(ReturnStatementNode& returnStatementNode) override;
    void Visit(DeclarationStatementNode& declarationStatementNode) override;
    void Visit(TryStatementNode& tryStatementNode) override;
    void Visit(HandlerNode& handlerNode) override;
    void Visit(HandlerSequenceNode& handlerSequenceNode) override;
    void Visit(ExpressionListInitializerNode& expressionListInitializer) override;
    void Visit(AssignmentInitializerNode& assignmentInitializerNode) override;
    void Visit(ExpressionInitializerNode& expressionInitializerNode) override;
    void Visit(ExpressionSequenceNode& expressionSequenceNode) override;
    void Visit(CommaExpressionNode& commaExpressionNode) override;
    void Visit(AssignmentExpressionNode& assignmentExpressionNode) override;
    void Visit(ConditionalExpressionNode& conditionalExpressionNode) override;
    void Visit(ThrowExpressionNode& throwExpressionNode) override;
    void Visit(LogicalOrExpressionNode& logicalOrExpressionNode) override;
    void Visit(LogicalAndExpressionNode& logicalAndExpressionNode) override;
    void Visit(InclusiveOrExpressionNode& inclusiveOrExpressionNode) override;
    void Visit(ExclusiveOrExpressionNode& exclusiveOrExpressionNode) override;
    void Visit(AndExpressionNode& andExpressionNode) override;
    void Visit(EqualityExpressionNode& equalityExpressionNode) override;
    void Visit(RelationalExpressionNode& relationalExpressionNode) override;
    void Visit(ShiftExpressionNode& shiftExpressionNode) override;
    void Visit(AdditiveExpressionNode& additiveExpressionNode) override;
    void Visit(MultiplicativeExpressionNode& multiplicativeExpressionNode) override;
    void Visit(PMExpressionNode& pmExpressionNode) override;
    void Visit(CastExpressionNode& castExpressionNode) override;
    void Visit(UnaryExpressionNode& unaryExpressionNode) override;
    void Visit(NewExpressionNode& newExpressionNode) override;
    void Visit(SubscriptExpressionNode& subscriptExpressionNode) override;
    void Visit(InvokeExpressionNode& invokeExpressionNode) override;
    void Visit(DotNode& dotNode) override;
    void Visit(ArrowNode& arrowNode) override;
    void Visit(PostfixIncNode& postfixIncNode) override;
    void Visit(PostfixDecNode& postfixDecNode) override;
    void Visit(CppCastExpressionNode& cppCastExpressionNode) override;
    void Visit(TypeIdExpressionNode& typeIdExpressionNode) override;
    void Visit(TypeExprNode& typeExprNode) override;
    void Visit(TypeParameterNode& typeParameterNode) override;
    void Visit(TemplateParameterSequenceNode& templateParameterSequenceNode) override;
    void Visit(TemplateArgumentSequenceNode& templateArgumentSequenceNode) override;
    void Visit(TemplateIdNode& templateIdNode) override;
    void Visit(TemplateArgumentNode& templateArgumentNode) override;
    void Visit(CtorInitializerNode& ctorInitializerNode) override;
    void Visit(ParenthesizedExprNode& parenthesizedExprNode) override;
    void Visit(BracedInitializerListNode& bracedInitializerListNode) override;
    void Visit(MemberInitializerNode& memberInitializerNode) override;
    void Visit(MemberInitializerSequenceNode& memberInitializerSequenceNode) override;
    void Visit(StringLiteralNode& stringLiteralNode) override;
    const std::unordered_set<ClassTypeSymbol*>& ClassesHavingVirtualFunctions() const { return classesHavingVirtualFunctions; }
private:
    SourceFileResolver* sourceFileResolver;
    SymbolTable& symbolTable;
    ContainerScope* containerScope;
    std::unordered_map<SourceFileNode*, BoundSourceFile*> sourceFileMap;
    std::vector<std::unique_ptr<BoundSourceFile>> sourceFiles;
    BoundSourceFile* currentSourceFile;
    ClassTypeSymbol* currentClass;
    sngcpp::symbols::FunctionSymbol* currentFunction;
    FunctionDeclarationSymbol* currentFunctionDeclaration;
    Specifier currentAccessSpecifier;
    sngcpp::symbols::TypeSymbol* conversionFunctionType;
    std::u32string fileId;
    std::string fileName;
    std::unordered_set<ClassTypeSymbol*> classesHavingVirtualFunctions;
    std::vector<IdentifierNode*> idSequence;
};

} } // namespace sngcpp::binder

#endif // SNGCPP_BINDER_TYPE_BINDER_INCLUDED
