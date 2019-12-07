// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CPP2CM_CPP2CM_CONVERTER_INCLUDED
#define CPP2CM_CPP2CM_CONVERTER_INCLUDED
#include <cpp2cm/cpp2cm/Context.hpp>
#include <cpp2cm/cpp2cm/Map.hpp>
#include <cpp2cm/cpp2cm/SourceFile.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/symbols/SymbolTable.hpp>
#include <sngcm/ast/CompileUnit.hpp>
#include <sngcm/ast/Parameter.hpp>
#include <sngcm/ast/Statement.hpp>
#include <sngcm/ast/Class.hpp>
#include <sngcm/ast/Enumeration.hpp>
#include <unordered_map>

namespace cpp2cm {

const char* Cpp2CmVersion();

class Converter : public sngcpp::ast::Visitor
{
public:
    enum class StatementContainer
    {
        statements, latestCase, latestDefault
    };
    Converter(bool verbose_, const std::string& targetDir_, sngcpp::symbols::SymbolTable& symbolTable_, Map& map_,
        const std::set<std::u32string>& excludedClasses_, const std::set<std::u32string>& excludedFunctions_);
    void Write();
    SourceFiles& GetSourceFiles() { return sourceFiles; }
    void InsertNamespaceImports(sngcm::ast::CompileUnitNode* cu);
    void AddToContainer(int line, sngcm::ast::Node* node);
    void AddStatement(int line, sngcm::ast::StatementNode* statement);
    void WriteWarning(int line, const std::string& message);
    void ConvertIdExpr(sngcpp::ast::Node* idExprNode);
    void ConvertExpression(sngcpp::ast::Node* exprNode);
    void ConvertBooleanExpression(sngcpp::ast::Node* exprNode);
    void ConvertTypeExpression(sngcpp::ast::Node* typeExprNode);
    void NotConverted(int line, const std::string& message);
    sngcm::ast::NodeList<sngcm::ast::Node> ConvertExpressionList(sngcpp::ast::Node* expressions);
    sngcpp::symbols::TypeSymbol* MakeCommonType(sngcpp::symbols::TypeSymbol* leftType, sngcpp::symbols::TypeSymbol* rightType);
    sngcpp::symbols::TypeSymbol* AddPointer(sngcpp::symbols::TypeSymbol* pointeeType);
    sngcpp::symbols::TypeSymbol* RemovePointer(sngcpp::symbols::TypeSymbol* ptrType);
    sngcpp::symbols::TypeSymbol* MakeElementType(sngcpp::symbols::TypeSymbol* arrayType);
    void Visit(sngcpp::ast::BaseClassSpecifierNode& baseClassSpecifierNode) override;
    void Visit(sngcpp::ast::BaseClassSpecifierSequenceNode& baseClassSpecifierSequenceNode) override;
    void Visit(sngcpp::ast::ForwardClassDeclarationNode& forwardClassDeclarationNode) override;
    void Visit(sngcpp::ast::ElaborateClassNameNode& elaborateClassNameNode) override;
    void Visit(sngcpp::ast::ClassNode& classNode) override;
    void Visit(sngcpp::ast::MemberAccessDeclarationNode& memberAccessDeclarationNode) override;
    void Visit(sngcpp::ast::MemberDeclarationNode& memberDeclarationNode) override;
    void Visit(sngcpp::ast::SpecialMemberFunctionNode& specialMemberFunctionNode) override;
    void Visit(sngcpp::ast::CtorInitializerNode& ctorInitializerNode) override;
    void Visit(sngcpp::ast::MemberInitializerNode& memberInitializerNode) override;
    void Visit(sngcpp::ast::MemberInitializerSequenceNode& memberInitializerSequenceNode) override;
    void Visit(sngcpp::ast::SourceFileNode& sourceFileNode) override;
    void Visit(sngcpp::ast::SourceFileSequenceNode& sourceFileSequenceNode) override;
    void Visit(sngcpp::ast::SimpleDeclarationNode& simpleDeclarationNode) override;
    void Visit(sngcpp::ast::AliasDeclarationNode& aliasDeclarationNode) override;
    void Visit(sngcpp::ast::UsingDirectiveNode& usingDirectiveNode) override;
    void Visit(sngcpp::ast::UsingDeclarationNode& usingDeclarationNode) override;
    void Visit(sngcpp::ast::TypedefNode& typedefNode) override;
    void Visit(sngcpp::ast::DeclarationSequenceNode& declarationSequenceNode) override;
    void Visit(sngcpp::ast::LinkageSpecificationNode& linkageSpecificationNode) override;
    void Visit(sngcpp::ast::IdDeclaratorNode& idDeclaratorNode) override;
    void Visit(sngcpp::ast::ArrayDeclaratorNode& arrayDeclaratorNode) override;
    void Visit(sngcpp::ast::FunctionDeclaratorNode& functionDeclaratorNode) override;
    void Visit(sngcpp::ast::FunctionPtrIdNode& functionPtrIdNode) override;
    void Visit(sngcpp::ast::MemberFunctionPtrIdNode& memberFunctionPtrIdNode) override;
    void Visit(sngcpp::ast::InitDeclaratorNode& initDeclaratorNode) override;
    void Visit(sngcpp::ast::AssignmentInitializerNode& assignmentInitializerNode) override;
    void Visit(sngcpp::ast::ExpressionListInitializerNode& expressionListInitializerNode) override;
    void Visit(sngcpp::ast::ExpressionInitializerNode& expressionInitializerNode) override;
    void Visit(sngcpp::ast::BracedInitializerListNode& bracedInitializerListNode) override;
    void Visit(sngcpp::ast::EnumTypeNode& enumTypeNode) override;
    void Visit(sngcpp::ast::EnumeratorNode& enumeratorNode) override;
    void Visit(sngcpp::ast::EnumeratorSequenceNode& enumeratorSequenceNode) override;
    void Visit(sngcpp::ast::ExpressionSequenceNode& expressionSequenceNode) override;
    void Visit(sngcpp::ast::CommaExpressionNode& commaExpressionNode) override;
    void Visit(sngcpp::ast::AssignmentExpressionNode& assignmentExpressionNode) override;
    void Visit(sngcpp::ast::ConditionalExpressionNode& conditionalExpressionNode) override;
    void Visit(sngcpp::ast::ThrowExpressionNode& throwExpressionNode) override;
    void Visit(sngcpp::ast::LogicalOrExpressionNode& logicalOrExpressionNode) override;
    void Visit(sngcpp::ast::LogicalAndExpressionNode& logicalAndExpressionNode) override;
    void Visit(sngcpp::ast::InclusiveOrExpressionNode& inclusiveOrExpressionNode) override;
    void Visit(sngcpp::ast::ExclusiveOrExpressionNode& exclusiveOrExpressionNode) override;
    void Visit(sngcpp::ast::AndExpressionNode& andExpressionNode) override;
    void Visit(sngcpp::ast::EqualityExpressionNode& equalityExpressionNode) override;
    void Visit(sngcpp::ast::RelationalExpressionNode& relationalExpressionNode) override;
    void Visit(sngcpp::ast::ShiftExpressionNode& shiftExpressionNode) override;
    void Visit(sngcpp::ast::AdditiveExpressionNode& additiveExpressionNode) override;
    void Visit(sngcpp::ast::MultiplicativeExpressionNode& multiplicativeExpressionNode) override;
    void Visit(sngcpp::ast::PMExpressionNode& pmExpressionNode) override;
    void Visit(sngcpp::ast::CastExpressionNode& castExpressionNode) override;
    void Visit(sngcpp::ast::UnaryExpressionNode& unaryExpressionNode) override;
    void Visit(sngcpp::ast::NewExpressionNode& newExpressionNode) override;
    void Visit(sngcpp::ast::DeleteExpressionNode& deleteExpressionNode) override;
    void Visit(sngcpp::ast::SubscriptExpressionNode& subscriptExpressionNode) override;
    void Visit(sngcpp::ast::InvokeExpressionNode& invokeExpressionNode) override;
    void Visit(sngcpp::ast::DotNode& dotNode) override;
    void Visit(sngcpp::ast::ArrowNode& arrowNode) override;
    void Visit(sngcpp::ast::PostfixIncNode& postfixIncNode) override;
    void Visit(sngcpp::ast::PostfixDecNode& postfixDecNode) override;
    void Visit(sngcpp::ast::CppCastExpressionNode& cppCastExpressionNode) override;
    void Visit(sngcpp::ast::TypeIdExpressionNode& typeIdExpressionNode) override;
    void Visit(sngcpp::ast::ThisNode& thisNode) override;
    void Visit(sngcpp::ast::ParenthesizedExprNode& parenthesizedExprNode) override;
    void Visit(sngcpp::ast::LambdaExpressionNode& lambdaExpressionNode) override;
    void Visit(sngcpp::ast::IdentifierNode& identifierNode) override;
    void Visit(sngcpp::ast::OperatorFunctionIdNode& operatorFunctionIdNode) override;
    void Visit(sngcpp::ast::ConversionFunctionIdNode& conversionFunctionIdNode) override;
    void Visit(sngcpp::ast::DtorIdNode& dDtorIdNode) override;
    void Visit(sngcpp::ast::NestedIdNode& nestedIdNode) override;
    void Visit(sngcpp::ast::ParameterNode& parameterNode) override;
    void Visit(sngcpp::ast::ParameterSequenceNode& parameterSequenceNode) override;
    void Visit(sngcpp::ast::FunctionNode& functionNode) override;
    void Visit(sngcpp::ast::FloatingLiteralNode& floatingLiteralNode) override;
    void Visit(sngcpp::ast::IntegerLiteralNode& integerLiteralNode) override;
    void Visit(sngcpp::ast::CharacterLiteralNode& characterLiteralNode) override;
    void Visit(sngcpp::ast::StringLiteralNode& stringLiteralNode) override;
    void Visit(sngcpp::ast::BooleanLiteralNode& booleanLiteralNode) override;
    void Visit(sngcpp::ast::NullPtrLiteralNode& nullPtrLiteralNode) override;
    void Visit(sngcpp::ast::NamespaceNode& namespaceNode) override;
    void Visit(sngcpp::ast::SimpleTypeNode& simpleTypeNode) override;
    void Visit(sngcpp::ast::LabeledStatementNode& labeledStatementNode) override;
    void Visit(sngcpp::ast::CaseStatementNode& caseStatementNode) override;
    void Visit(sngcpp::ast::DefaultStatementNode& defaultStatementNode) override;
    void Visit(sngcpp::ast::ExpressionStatementNode& expressionStatementNode) override;
    void Visit(sngcpp::ast::CompoundStatementNode& compoundStatementNode) override;
    void Visit(sngcpp::ast::StatementSequenceNode& statementSequenceNode) override;
    void Visit(sngcpp::ast::IfStatementNode& ifStatementNode) override;
    void Visit(sngcpp::ast::SwitchStatementNode& switchStatementNode) override;
    void Visit(sngcpp::ast::WhileStatementNode& whileStatementNode) override;
    void Visit(sngcpp::ast::DoStatementNode& doStatementNode) override;
    void Visit(sngcpp::ast::RangeForStatementNode& rangeForStatementNode) override;
    void Visit(sngcpp::ast::ForStatementNode& forStatementNode) override;
    void Visit(sngcpp::ast::BreakStatementNode& breakStatementNode) override;
    void Visit(sngcpp::ast::ContinueStatementNode& continueStatementNode) override;
    void Visit(sngcpp::ast::ReturnStatementNode& returnStatementNode) override;
    void Visit(sngcpp::ast::GotoStatementNode& gotoStatementNode) override;
    void Visit(sngcpp::ast::DeclarationStatementNode& declarationStatementNode) override;
    void Visit(sngcpp::ast::TryStatementNode& tryStatementNode) override;
    void Visit(sngcpp::ast::HandlerNode& handlerNode) override;
    void Visit(sngcpp::ast::HandlerSequenceNode& handlerSequenceNode) override;
    void Visit(sngcpp::ast::CatchAllNode& catchAllNode) override;
    void Visit(sngcpp::ast::TypeParameterNode& typeParameterNode) override;
    void Visit(sngcpp::ast::TemplateParameterSequenceNode& templateParameterSequenceNode) override;
    void Visit(sngcpp::ast::TemplateDeclarationNode& templateDeclarationNode) override;
    void Visit(sngcpp::ast::TemplateArgumentSequenceNode& templateArgumentSequenceNode) override;
    void Visit(sngcpp::ast::TemplateIdNode& templateIdNode) override;
    void Visit(sngcpp::ast::TemplateArgumentNode& templateArgumentNode) override;
    void Visit(sngcpp::ast::ExplicitInstantiationNode& explicitInstantiationNode) override;
    void Visit(sngcpp::ast::ExplicitSpecializationNode& explicitSpecializationNode) override;
    void Visit(sngcpp::ast::ConstNode& constNode) override;
    void Visit(sngcpp::ast::VolatileNode& volatileNode) override;
    void Visit(sngcpp::ast::PointerNode& pointerNode) override;
    void Visit(sngcpp::ast::RValueRefNode& rValueRefNode) override;
    void Visit(sngcpp::ast::LValueRefNode& lValueRefNode) override;
private:
    bool verbose;
    std::string targetDir;
    sngcpp::symbols::SymbolTable& symbolTable;
    std::string currentSourceFileName;
    std::vector<std::unique_ptr<sngcm::ast::CompileUnitNode>> compileUnits;
    sngcm::ast::CompileUnitNode* currentCompileUnit;
    sngcm::ast::NamespaceNode* currentNamespace;
    sngcm::ast::EnumTypeNode* currentEnumType;
    Context* currentContext;
    sngcm::ast::Node* currentContainerNode;
    std::unordered_map<std::string, sngcm::ast::CompileUnitNode*> compileUnitMap;
    std::unordered_map<sngcm::ast::CompileUnitNode*, Context> contextMap;
    std::unordered_map<sngcpp::symbols::ClassTypeSymbol*, sngcm::ast::ClassNode*> classMap;
    Map& map;
    std::vector<sngcpp::symbols::Symbol*> mappedSymbolSequence;
    std::unique_ptr<sngcm::ast::Node> node;
    std::vector<std::unique_ptr<sngcm::ast::ParameterNode>> parameterNodes;
    StatementContainer statementContainer;
    std::vector<std::unique_ptr<sngcm::ast::StatementNode>> statementNodes;
    sngcm::ast::CaseStatementNode* parentCaseStatementNode;
    std::vector<std::unique_ptr<sngcm::ast::CaseStatementNode>> caseStatementNodes;
    std::unique_ptr<sngcm::ast::DefaultStatementNode> defaultStatement;
    std::vector<std::unique_ptr<sngcm::ast::CatchNode>> catchNodes;
    std::vector<std::unique_ptr<sngcm::ast::TemplateParameterNode>> templateParameterNodes;
    sngcm::ast::NodeList<sngcm::ast::Node> nodes;
    bool addToNodes;
    sngcpp::symbols::TypeSymbol* type;
    sngcpp::symbols::ClassTypeSymbol* currentClassType;
    std::unique_ptr<sngcm::ast::ClassNode> cls;
    std::unique_ptr<sngcm::ast::Node> declarator;
    std::unique_ptr<sngcm::ast::Node> initializer;
    bool assignment;
    bool empty;
    bool inFunctionBody;
    bool assignmentStatement;
    bool rangeFor;
    bool catchDecl;
    std::unique_ptr<sngcm::ast::Node> rangeForType;
    std::unique_ptr<sngcm::ast::IdentifierNode> rangeForId;
    std::unique_ptr<sngcm::ast::Node> catchType;
    std::unique_ptr<sngcm::ast::IdentifierNode> catchId;
    sngcpp::symbols::CallableSymbol* calledFunction;
    std::u32string args;
    SourceFiles sourceFiles;
    const std::set<std::u32string>& excludedClasses;
    const std::set<std::u32string>& excludedFunctions;
};

} // namespace cpp2cm

#endif // CPP2CM_CPP2CM_CONVERTER_INCLUDED
