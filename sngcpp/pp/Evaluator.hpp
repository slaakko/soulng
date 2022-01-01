// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PP_EVALUATOR_INCLUDED
#define SNGCPP_PP_EVALUATOR_INCLUDED
#include <sngcpp/pp/PPApi.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <string>
#include <map>
#include <memory>
#include <vector>
#include <stdint.h>

namespace sngcpp { namespace pp {

enum class ValueType
{
    none, boolValue, intValue, doubleValue
};

SNGCPP_PP_API ValueType CommonType(ValueType left, ValueType right);

class EvaluationContext;
class BoolValue;
class IntValue;
class DoubleValue;

class SNGCPP_PP_API Value
{
public:
    Value(ValueType valueType_);
    virtual ~Value();
    ValueType Type() const { return valueType; }
    virtual BoolValue* ToBool(EvaluationContext& context) = 0;
    virtual IntValue* ToInt(EvaluationContext& context) = 0;
    virtual DoubleValue* ToDouble(EvaluationContext& context) = 0;
    virtual std::string TypeName() const = 0;
private:
    ValueType valueType;
};

class SNGCPP_PP_API BoolValue : public Value
{
public:
    using operandType = bool;
    BoolValue(bool value_);
    bool GetValue() const { return value;  }
    BoolValue* ToBool(EvaluationContext& context) override;
    IntValue* ToInt(EvaluationContext& context) override;
    DoubleValue* ToDouble(EvaluationContext& context) override;
    std::string TypeName() const override { return "bool"; }
private:
    bool value;
};

class SNGCPP_PP_API IntValue : public Value
{
public:
    using operandType = int64_t;
    IntValue(int64_t value_);
    int64_t GetValue() const { return value; }
    BoolValue* ToBool(EvaluationContext& context) override;
    IntValue* ToInt(EvaluationContext& context) override;
    DoubleValue* ToDouble(EvaluationContext& context) override;
    std::string TypeName() const override { return "int"; }
private:
    int64_t value;
};

class SNGCPP_PP_API DoubleValue : public Value
{
public:
    using operandType = double;
    DoubleValue(double value_);
    double GetValue() const { return value; }
    BoolValue* ToBool(EvaluationContext& context) override;
    IntValue* ToInt(EvaluationContext& context) override;
    DoubleValue* ToDouble(EvaluationContext& context) override;
    std::string TypeName() const override { return "double"; }
private:
    double value;
};

class SNGCPP_PP_API EvaluationContext
{
public:
    EvaluationContext();
    ~EvaluationContext();
    BoolValue* MakeValue(bool value);
    IntValue* MakeValue(int64_t value);
    DoubleValue* MakeValue(double value);
private:
    BoolValue trueValue;
    BoolValue falseValue;
    IntValue intZero;
    IntValue intOne;
    DoubleValue doubleZero;
    DoubleValue doubleOne;
    std::map<int64_t, IntValue*> intValueMap;
    std::map<double, DoubleValue*> doubleValueMap;
    std::vector<Value*> values;
};

using namespace sngcpp::ast;

SNGCPP_PP_API void ThrowCannotEvaluateStatically(const std::string& fileName, int line);
SNGCPP_PP_API void ThrowInvalidOperation(const std::string& fileName, int line);

class SNGCPP_PP_API Evaluator : public sngcpp::ast::Visitor
{
public:
    Evaluator(const std::string& fileName_, int line_, EvaluationContext& context_);
    Value* GetValue();
    void Visit(BaseClassSpecifierNode& baseClassSpecifierNode) override;
    void Visit(BaseClassSpecifierSequenceNode& baseClassSpecifierSequenceNode) override;
    void Visit(ForwardClassDeclarationNode& forwardClassDeclarationNode) override;
    void Visit(ElaborateClassNameNode& elaborateClassNameNode) override;
    void Visit(ClassNode& classNode) override;
    void Visit(MemberAccessDeclarationNode& memberAccessDeclarationNode) override;
    void Visit(MemberDeclarationNode& memberDeclarationNode) override;
    void Visit(SpecialMemberFunctionNode& specialMemberFunctionNode) override;
    void Visit(CtorInitializerNode& ctorInitializerNode) override;
    void Visit(MemberInitializerNode& memberInitializerNode) override;
    void Visit(MemberInitializerSequenceNode& memberInitializerSequenceNode) override;
    void Visit(SourceFileNode& sourceFileNode) override;
    void Visit(SourceFileSequenceNode& sourceFileSequenceNode) override;
    void Visit(SimpleDeclarationNode& simpleDeclarationNode) override;
    void Visit(AliasDeclarationNode& aliasDeclarationNode) override;
    void Visit(UsingDirectiveNode& usingDirectiveNode) override;
    void Visit(UsingDeclarationNode& usingDeclarationNode) override;
    void Visit(TypedefNode& typedefNode) override;
    void Visit(DeclarationSequenceNode& declarationSequenceNode) override;
    void Visit(LinkageSpecificationNode& linkageSpecificationNode) override;
    void Visit(IdDeclaratorNode& idDeclaratorNode) override;
    void Visit(ArrayDeclaratorNode& arrayDeclaratorNode) override;
    void Visit(FunctionDeclaratorNode& functionDeclaratorNode) override;
    void Visit(FunctionPtrIdNode& functionPtrIdNode) override;
    void Visit(MemberFunctionPtrIdNode& memberFunctionPtrIdNode) override;
    void Visit(InitDeclaratorNode& initDeclaratorNode) override;
    void Visit(AssignmentInitializerNode& assignmentInitializerNode) override;
    void Visit(ExpressionListInitializerNode& expressionListInitializerNode) override;
    void Visit(ExpressionInitializerNode& expressionInitializerNode) override;
    void Visit(BracedInitializerListNode& bracedInitializerListNode) override;
    void Visit(EnumTypeNode& enumTypeNode) override;
    void Visit(EnumeratorNode& enumeratorNode) override;
    void Visit(EnumeratorSequenceNode& enumeratorSequenceNode) override;
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
    void Visit(DeleteExpressionNode& deleteExpressionNode) override;
    void Visit(SubscriptExpressionNode& subscriptExpressionNode) override;
    void Visit(InvokeExpressionNode& invokeExpressionNode) override;
    void Visit(DotNode& dotNode) override;
    void Visit(ArrowNode& arrowNode) override;
    void Visit(PostfixIncNode& postfixIncNode) override;
    void Visit(PostfixDecNode& postfixDecNode) override;
    void Visit(CppCastExpressionNode& cppCastExpressionNode) override;
    void Visit(TypeIdExpressionNode& typeIdExpressionNode) override;
    void Visit(ThisNode& thisNode) override;
    void Visit(ParenthesizedExprNode& parenthesizedExprNode) override;
    void Visit(LambdaExpressionNode& lambdaExpressionNode) override;
    void Visit(CaptureSequenceNode& captureSequenceNode) override;
    void Visit(AssignCaptureNode& assignCaptureNode) override;
    void Visit(RefCaptureNode& refCaptureNode) override;
    void Visit(ThisCaptureNode& thisCaptureNode) override;
    void Visit(IdentifierCaptureNode& identifierCaptureNode) override;
    void Visit(IdentifierNode& identifierNode) override;
    void Visit(OperatorFunctionIdNode& operatorFunctionIdNode) override;
    void Visit(ConversionFunctionIdNode& conversionFunctionIdNode) override;
    void Visit(DtorIdNode& dDtorIdNode) override;
    void Visit(NestedIdNode& nestedIdNode) override;
    void Visit(ParameterNode& parameterNode) override;
    void Visit(ParameterSequenceNode& parameterSequenceNode) override;
    void Visit(FunctionNode& functionNode) override;
    void Visit(FloatingLiteralNode& floatingLiteralNode) override;
    void Visit(IntegerLiteralNode& integerLiteralNode) override;
    void Visit(CharacterLiteralNode& characterLiteralNode) override;
    void Visit(StringLiteralNode& stringLiteralNode) override;
    void Visit(BooleanLiteralNode& booleanLiteralNode) override;
    void Visit(NullPtrLiteralNode& nullPtrLiteralNode) override;
    void Visit(NamespaceNode& namespaceNode) override;
    void Visit(SimpleTypeNode& simpleTypeNode) override;
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
    void Visit(BreakStatementNode& breakStatementNode) override;
    void Visit(ContinueStatementNode& continueStatementNode) override;
    void Visit(ReturnStatementNode& returnStatementNode) override;
    void Visit(GotoStatementNode& gotoStatementNode) override;
    void Visit(DeclarationStatementNode& declarationStatementNode) override;
    void Visit(TryStatementNode& tryStatementNode) override;
    void Visit(HandlerNode& handlerNode) override;
    void Visit(HandlerSequenceNode& handlerSequenceNode) override;
    void Visit(CatchAllNode& catchAllNode) override;
    void Visit(TypeParameterNode& typeParameterNode) override;
    void Visit(TemplateParameterSequenceNode& templateParameterSequenceNode) override;
    void Visit(TemplateDeclarationNode& templateDeclarationNode) override;
    void Visit(TemplateArgumentSequenceNode& templateArgumentSequenceNode) override;
    void Visit(TemplateIdNode& templateIdNode) override;
    void Visit(TemplateArgumentNode& templateArgumentNode) override;
    void Visit(ExplicitInstantiationNode& explicitInstantiationNode) override;
    void Visit(ExplicitSpecializationNode& explicitSpecializationNode) override;
    void Visit(ConstNode& constNode) override;
    void Visit(VolatileNode& volatileNode) override;
    void Visit(PointerNode& pointerNode) override;
    void Visit(RValueRefNode& rValueRefNode) override;
    void Visit(LValueRefNode& lValueRefNode) override;
private:
    std::string fileName;
    int line;
    EvaluationContext& context;
    Value* value;
};

} } // namespace sngcpp::pp

#endif // SNGCPP_PP_EVALUATOR_INCLUDED
