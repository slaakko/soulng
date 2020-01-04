// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_BINDER_STATEMENT_BINDER_INCLUDED
#define SNGCPP_BINDER_STATEMENT_BINDER_INCLUDED
#include <sngcpp/binder/BoundSourceFile.hpp>
#include <sngcpp/symbols/SymbolTable.hpp>
#include <sngcpp/ast/Visitor.hpp>

namespace sngcpp { namespace binder {

class SNGCPP_BINDER_API StatementBinder : public sngcpp::ast::Visitor
{
public:
    StatementBinder(SymbolTable& symbolTable_, const std::unordered_map<SourceFileNode*, BoundSourceFile*>& sourceFileMap_);
    void Visit(SourceFileNode& sourceFileNode) override;
    void Visit(SourceFileSequenceNode& sourceFileSequenceNode) override;
    void Visit(SimpleDeclarationNode& simpleDeclarationNode) override;
    void Visit(NamespaceNode& namespaceNode) override;
    void Visit(MemberAccessDeclarationNode& memberAccessDeclarationNode) override;
    void Visit(MemberDeclarationNode& memberDeclarationNode) override;
    void Visit(DeclarationSequenceNode& declarationSequenceNode) override;
    void Visit(LinkageSpecificationNode& linkageSpecificationNode) override;
    void Visit(TemplateDeclarationNode& templateDeclarationNode) override;
    void Visit(ClassNode& classNode) override;
    void Visit(FunctionNode& functionNode) override;
    void Visit(SpecialMemberFunctionNode& specialMemberFunctionNode) override;
    void Visit(CompoundStatementNode& compoundStatementNode) override;
    void Visit(StatementSequenceNode& statementSequenceNode) override;
    void Visit(LabeledStatementNode& labeledStatementNode) override;
    void Visit(IfStatementNode& ifStatementNode) override;
    void Visit(SwitchStatementNode& switchStatementNode) override;
    void Visit(CaseStatementNode& caseStatementNode) override;
    void Visit(DefaultStatementNode& defaultStatementNode) override;
    void Visit(ExpressionStatementNode& expressionStatementNode) override;
    void Visit(WhileStatementNode& whileStatementNode) override;
    void Visit(DoStatementNode& doStatementNode) override;
    void Visit(RangeForStatementNode& rangeForStatementNode) override;
    void Visit(ForStatementNode& forStatementNode) override;
    void Visit(ReturnStatementNode& returnStatementNode) override;
    void Visit(DeclarationStatementNode& declarationStatementNode) override;
    void Visit(TryStatementNode& tryStatementNode) override;
    void Visit(HandlerNode& handlerNode) override;
    void Visit(HandlerSequenceNode& handlerSequenceNode) override;
private:
    SymbolTable& symbolTable;
    const std::unordered_map<SourceFileNode*, BoundSourceFile*>& sourceFileMap;
    ContainerScope* containerScope;
    BoundSourceFile* currentSourceFile;
    FunctionSymbol* currentFunction;
};

} } // namespace sngcpp::binder

#endif // SNGCPP_BINDER_STATEMENT_BINDER_INCLUDED
