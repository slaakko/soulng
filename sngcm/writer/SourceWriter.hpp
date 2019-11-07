// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCM_WRITER_SOURCE_WRITER_INCLUDED
#define SNGCM_WRITER_SOURCE_WRITER_INCLUDED
#include <sngcm/writer/WriterApi.hpp>
#include <sngcm/ast/Visitor.hpp>
#include <soulng/util/CodeFormatter.hpp>

namespace sngcm { namespace writer {

class SNGCM_WRITER_API SourceWriter : public sngcm::ast::Visitor
{
public:
    SourceWriter(soulng::util::CodeFormatter& formatter_);
    void Visit(sngcm::ast::BoolNode& boolNode) override;
    void Visit(sngcm::ast::SByteNode& sbyteNode) override;
    void Visit(sngcm::ast::ByteNode& byteNode) override;
    void Visit(sngcm::ast::ShortNode& shortNode) override;
    void Visit(sngcm::ast::UShortNode& ushortNode) override;
    void Visit(sngcm::ast::IntNode& intNode) override;
    void Visit(sngcm::ast::UIntNode& uintNode) override;
    void Visit(sngcm::ast::LongNode& longNode) override;
    void Visit(sngcm::ast::ULongNode& ulongNode) override;
    void Visit(sngcm::ast::FloatNode& floatNode) override;
    void Visit(sngcm::ast::DoubleNode& doubleNode) override;
    void Visit(sngcm::ast::CharNode& charNode) override;
    void Visit(sngcm::ast::WCharNode& wcharNode) override;
    void Visit(sngcm::ast::UCharNode& ucharNode) override;
    void Visit(sngcm::ast::VoidNode& voidNode) override;

    void Visit(sngcm::ast::BooleanLiteralNode& booleanLiteralNode) override;
    void Visit(sngcm::ast::SByteLiteralNode& sbyteLiteralNode) override;
    void Visit(sngcm::ast::ByteLiteralNode& byteLiteralNode) override;
    void Visit(sngcm::ast::ShortLiteralNode& shortLiteralNode) override;
    void Visit(sngcm::ast::UShortLiteralNode& ushortLiteralNode) override;
    void Visit(sngcm::ast::IntLiteralNode& intLiteralNode) override;
    void Visit(sngcm::ast::UIntLiteralNode& uintLiteralNode) override;
    void Visit(sngcm::ast::LongLiteralNode& longLiteralNode) override;
    void Visit(sngcm::ast::ULongLiteralNode& ulongLiteralNode) override;
    void Visit(sngcm::ast::FloatLiteralNode& floatLiteralNode) override;
    void Visit(sngcm::ast::DoubleLiteralNode& doubleLiteralNode) override;
    void Visit(sngcm::ast::CharLiteralNode& charLiteralNode) override;
    void Visit(sngcm::ast::WCharLiteralNode& wcharLiteralNode) override;
    void Visit(sngcm::ast::UCharLiteralNode& ucharLiteralNode) override;
    void Visit(sngcm::ast::StringLiteralNode& stringLiteralNode) override;
    void Visit(sngcm::ast::WStringLiteralNode& wstringLiteralNode) override;
    void Visit(sngcm::ast::UStringLiteralNode& ustringLiteralNode) override;
    void Visit(sngcm::ast::NullLiteralNode& nullLiteralNode) override;
    void Visit(sngcm::ast::ArrayLiteralNode& arrayLiteralNode) override;
    void Visit(sngcm::ast::StructuredLiteralNode& structuredLiteralNode) override;
    void Visit(sngcm::ast::UuidLiteralNode& uuidLiteralNode) override;

    void Visit(sngcm::ast::CompileUnitNode& compileUnitNode) override;
    void Visit(sngcm::ast::NamespaceNode& namespaceNode) override;
    void Visit(sngcm::ast::AliasNode& aliasNode) override;
    void Visit(sngcm::ast::NamespaceImportNode& namespaceImportNode) override;
    void Visit(sngcm::ast::IdentifierNode& identifierNode) override;
    void Visit(sngcm::ast::CursorIdNode& cursorIdNode) override;
    void Visit(sngcm::ast::TemplateIdNode& templateIdNode) override;
    void Visit(sngcm::ast::FunctionNode& functionNode) override;
    void Visit(sngcm::ast::ClassNode& classNode) override;
    void Visit(sngcm::ast::ThisInitializerNode& thisInitializerNode) override;
    void Visit(sngcm::ast::BaseInitializerNode& baseInitializerNode) override;
    void Visit(sngcm::ast::MemberInitializerNode& memberInitializerNode) override;
    void Visit(sngcm::ast::StaticConstructorNode& staticConstructorNode) override;
    void Visit(sngcm::ast::ConstructorNode& constructorNode) override;
    void Visit(sngcm::ast::DestructorNode& destructorNode) override;
    void Visit(sngcm::ast::MemberFunctionNode& memberFunctionNode) override;
    void Visit(sngcm::ast::ConversionFunctionNode& conversionFunctionNode) override;
    void Visit(sngcm::ast::MemberVariableNode& memberVariableNode) override;
    void Visit(sngcm::ast::InterfaceNode& interfaceNode) override;
    void Visit(sngcm::ast::DelegateNode& delegateNode) override;
    void Visit(sngcm::ast::ClassDelegateNode& classDelegateNode) override;

    void Visit(sngcm::ast::ParenthesizedConstraintNode& parenthesizedConstraintNode) override;
    void Visit(sngcm::ast::DisjunctiveConstraintNode& disjunctiveConstraintNode) override;
    void Visit(sngcm::ast::ConjunctiveConstraintNode& conjunctiveConstraintNode) override;
    void Visit(sngcm::ast::WhereConstraintNode& whereConstraintNode) override;
    void Visit(sngcm::ast::PredicateConstraintNode& predicateConstraintNode) override;
    void Visit(sngcm::ast::IsConstraintNode& isConstraintNode) override;
    void Visit(sngcm::ast::MultiParamConstraintNode& multiParamConstraintNode) override;
    void Visit(sngcm::ast::TypeNameConstraintNode& typeNameConstraintNode) override;
    void Visit(sngcm::ast::ConstructorConstraintNode& constructorConstraintNode) override;
    void Visit(sngcm::ast::DestructorConstraintNode& destructorConstraintNode) override;
    void Visit(sngcm::ast::MemberFunctionConstraintNode& memberFunctionConstraintNode) override;
    void Visit(sngcm::ast::FunctionConstraintNode& functionConstraintNode) override;
    void Visit(sngcm::ast::AxiomStatementNode& axiomStatementNode) override;
    void Visit(sngcm::ast::AxiomNode& axiomNode) override;
    void Visit(sngcm::ast::ConceptIdNode& conceptIdNode) override;
    void Visit(sngcm::ast::ConceptNode& conceptNode) override;

    void Visit(sngcm::ast::LabelNode& labelNode) override;
    void Visit(sngcm::ast::LabeledStatementNode& labeledStatementNode) override;
    void Visit(sngcm::ast::CompoundStatementNode& compoundStatementNode) override;
    void Visit(sngcm::ast::ReturnStatementNode& returnStatementNode) override;
    void Visit(sngcm::ast::IfStatementNode& ifStatementNode) override;
    void Visit(sngcm::ast::WhileStatementNode& whileStatementNode) override;
    void Visit(sngcm::ast::DoStatementNode& doStatementNode) override;
    void Visit(sngcm::ast::ForStatementNode& forStatementNode) override;
    void Visit(sngcm::ast::BreakStatementNode& breakStatementNode) override;
    void Visit(sngcm::ast::ContinueStatementNode& continueStatementNode) override;
    void Visit(sngcm::ast::GotoStatementNode& gotoStatementNode) override;
    void Visit(sngcm::ast::ConstructionStatementNode& constructionStatementNode) override;
    void Visit(sngcm::ast::DeleteStatementNode& deleteStatementNode) override;
    void Visit(sngcm::ast::DestroyStatementNode& destroyStatementNode) override;
    void Visit(sngcm::ast::AssignmentStatementNode& assignmentStatementNode) override;
    void Visit(sngcm::ast::ExpressionStatementNode& expressionStatementNode) override;
    void Visit(sngcm::ast::EmptyStatementNode& emptyStatementNode) override;
    void Visit(sngcm::ast::RangeForStatementNode& rangeForStatementNode) override;
    void Visit(sngcm::ast::SwitchStatementNode& switchStatementNode) override;
    void Visit(sngcm::ast::CaseStatementNode& caseStatementNode) override;
    void Visit(sngcm::ast::DefaultStatementNode& defaultStatementNode) override;
    void Visit(sngcm::ast::GotoCaseStatementNode& gotoCaseStatementNode) override;
    void Visit(sngcm::ast::GotoDefaultStatementNode& gotoDefaultStatementNode) override;
    void Visit(sngcm::ast::ThrowStatementNode& throwStatementNode) override;
    void Visit(sngcm::ast::TryStatementNode& tryStatementNode) override;
    void Visit(sngcm::ast::CatchNode& catchNode) override;
    void Visit(sngcm::ast::AssertStatementNode& assertStatementNode) override;
    void Visit(sngcm::ast::ConditionalCompilationPartNode& conditionalCompilationPartNode) override;
    void Visit(sngcm::ast::ConditionalCompilationDisjunctionNode& conditionalCompilationDisjunctionNode) override;
    void Visit(sngcm::ast::ConditionalCompilationConjunctionNode& conditionalCompilationConjunctionNode) override;
    void Visit(sngcm::ast::ConditionalCompilationNotNode& conditionalCompilationNotNode) override;
    void Visit(sngcm::ast::ConditionalCompilationPrimaryNode& conditionalCompilationPrimaryNode) override;
    void Visit(sngcm::ast::ParenthesizeConditionalCompilationExpressionNode& parenthesizeCondCompExprNode) override;
    void Visit(sngcm::ast::ConditionalCompilationStatementNode& conditionalCompilationStatementNode) override;

    void Visit(sngcm::ast::TypedefNode& typedefNode) override;
    void Visit(sngcm::ast::ConstantNode& constantNode) override;
    void Visit(sngcm::ast::EnumTypeNode& enumTypeNode) override;
    void Visit(sngcm::ast::EnumConstantNode& enumConstantNode) override;
    void Visit(sngcm::ast::ParameterNode& parameterNode) override;
    void Visit(sngcm::ast::TemplateParameterNode& templateParameterNode) override;

    void Visit(sngcm::ast::ConstNode& constNode) override;
    void Visit(sngcm::ast::LValueRefNode& lvalueRefNode) override;
    void Visit(sngcm::ast::RValueRefNode& rvalueRefNode) override;
    void Visit(sngcm::ast::PointerNode& pointerNode) override;
    void Visit(sngcm::ast::ArrayNode& arrayNode) override;

    void Visit(sngcm::ast::DotNode& dotNode) override;
    void Visit(sngcm::ast::ArrowNode& arrowNode) override;
    void Visit(sngcm::ast::EquivalenceNode& equivalenceNode) override;
    void Visit(sngcm::ast::ImplicationNode& implicationNode) override;
    void Visit(sngcm::ast::DisjunctionNode& disjunctionNode) override;
    void Visit(sngcm::ast::ConjunctionNode& conjunctionNode) override;
    void Visit(sngcm::ast::BitOrNode& bitOrNode) override;
    void Visit(sngcm::ast::BitXorNode& bitXorNode) override;
    void Visit(sngcm::ast::BitAndNode& bitAndNode) override;
    void Visit(sngcm::ast::EqualNode& equalNode) override;
    void Visit(sngcm::ast::NotEqualNode& notEqualNode) override;
    void Visit(sngcm::ast::LessNode& lessNode) override;
    void Visit(sngcm::ast::GreaterNode& greaterNode) override;
    void Visit(sngcm::ast::LessOrEqualNode& lessOrEqualNode) override;
    void Visit(sngcm::ast::GreaterOrEqualNode& greaterOrEqualNode) override;
    void Visit(sngcm::ast::ShiftLeftNode& shiftLeftNode) override;
    void Visit(sngcm::ast::ShiftRightNode& shiftRightNode) override;
    void Visit(sngcm::ast::AddNode& addNode) override;
    void Visit(sngcm::ast::SubNode& subNode) override;
    void Visit(sngcm::ast::MulNode& mulNode) override;
    void Visit(sngcm::ast::DivNode& divNode) override;
    void Visit(sngcm::ast::RemNode& remNode) override;
    void Visit(sngcm::ast::NotNode& notNode) override;
    void Visit(sngcm::ast::UnaryPlusNode& unaryPlusNode) override;
    void Visit(sngcm::ast::UnaryMinusNode& unaryMinusNode) override;
    void Visit(sngcm::ast::PrefixIncrementNode& prefixIncrementNode) override;
    void Visit(sngcm::ast::PrefixDecrementNode& prefixDecrementNode) override;
    void Visit(sngcm::ast::DerefNode& derefNode) override;
    void Visit(sngcm::ast::AddrOfNode& addrOfNode) override;
    void Visit(sngcm::ast::ComplementNode& complementNode) override;
    void Visit(sngcm::ast::IsNode& isNode) override;
    void Visit(sngcm::ast::AsNode& asNode) override;
    void Visit(sngcm::ast::IndexingNode& indexingNode) override;
    void Visit(sngcm::ast::InvokeNode& invokeNode) override;
    void Visit(sngcm::ast::PostfixIncrementNode& postfixIncrementNode) override;
    void Visit(sngcm::ast::PostfixDecrementNode& postfixDecrementNode) override;
    void Visit(sngcm::ast::SizeOfNode& sizeOfNode) override;
    void Visit(sngcm::ast::TypeNameNode& typeNameNode) override;
    void Visit(sngcm::ast::TypeIdNode& typeIdNode) override;
    void Visit(sngcm::ast::CastNode& castNode) override;
    void Visit(sngcm::ast::ConstructNode& constructNode) override;
    void Visit(sngcm::ast::NewNode& newNode) override;
    void Visit(sngcm::ast::ThisNode& thisNode) override;
    void Visit(sngcm::ast::BaseNode& baseNode) override;
    void Visit(sngcm::ast::ParenthesizedExpressionNode& parenthesizedExpressionNode) override;
    void Visit(sngcm::ast::GlobalVariableNode& globalVariableNode) override;
    void Visit(sngcm::ast::Attribute& attribute) override;
    void Visit(sngcm::ast::Attributes& attributes) override;
    void WriteWarning(const std::string& message);
private:
    soulng::util::CodeFormatter& formatter;
    bool omitNewLine;
    bool omitSemicolon;
};

} } // sngcm::writer

#endif // SNGCM_WRITER_SOURCE_WRITER_INCLUDED
