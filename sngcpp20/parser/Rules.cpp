#include "Rules.hpp"

std::vector<const char*> rules = {
"AttributeParser.AttributeSpecifierSeq"
, "AttributeParser.AttributeSpecifier"
, "AttributeParser.AttributeList"
, "AttributeParser.AttributeUsingPrefix"
, "AttributeParser.AttributeNamespace"
, "AttributeParser.Attribute"
, "AttributeParser.AttributeToken"
, "AttributeParser.AttributeScopedToken"
, "AttributeParser.AttributeArgumentClause"
, "AttributeParser.BalancedTokenSeq"
, "AttributeParser.BalancedToken"
, "AttributeParser.AlignmentSpecifier"
, "AttributeParser.LParen"
, "AttributeParser.RParen"
, "AttributeParser.LBracket"
, "AttributeParser.RBracket"
, "AttributeParser.LBrace"
, "AttributeParser.RBrace"
, "ClassParser.ClassSpecifier"
, "ClassParser.ClassHead"
, "ClassParser.ClassHeadName"
, "ClassParser.ClassName"
, "ClassParser.ClassKey"
, "ClassParser.BaseClause"
, "ClassParser.BaseSpecifierList"
, "ClassParser.BaseSpecifier"
, "ClassParser.ClassOrDeclType"
, "ClassParser.AccessSpecifier"
, "ClassParser.Private"
, "ClassParser.VirtualSpecifier"
, "ClassParser.ClassVirtSpecifier"
, "ClassParser.VirtSpecifierSeq"
, "ClassParser.VirtSpecifier"
, "ClassParser.OverrideKeyword"
, "ClassParser.FinalKeyword"
, "ClassParser.PureSpecifier"
, "ClassParser.MemberSpecification"
, "ClassParser.MemberDeclaration"
, "ClassParser.MemberDeclaratorList"
, "ClassParser.MemberDeclarator"
, "ClassParser.CtorInitializer"
, "ClassParser.MemberInitializerList"
, "ClassParser.MemberInitializer"
, "ClassParser.MemberInitializerId"
, "ConceptParser.ConceptDefinition"
, "ConceptParser.ConceptName"
, "ConceptParser.RequiresExpression"
, "ConceptParser.RequirementParameterList"
, "ConceptParser.RequirementBody"
, "ConceptParser.RequirementSeq"
, "ConceptParser.Requirement"
, "ConceptParser.SimpleRequirement"
, "ConceptParser.TypeRequirement"
, "ConceptParser.CompoundRequirement"
, "ConceptParser.ReturnTypeRequirement"
, "ConceptParser.NestedRequirement"
, "ConceptParser.TypeConstraint"
, "ConceptParser.ConstraintExpression"
, "ConceptParser.RequiresClause"
, "ConceptParser.ConstraintLogicalOrExpression"
, "ConceptParser.ConstraintLogicalAndExpression"
, "DeclarationParser.DeclarationSeq"
, "DeclarationParser.Declaration"
, "DeclarationParser.BlockDeclaration"
, "DeclarationParser.SimpleDeclaration"
, "DeclarationParser.AsmDeclaration"
, "DeclarationParser.Asm"
, "DeclarationParser.LinkageSpecification"
, "DeclarationParser.NamespaceDefinition"
, "DeclarationParser.NamedNamespaceDefinition"
, "DeclarationParser.UnnamedNamespaceDefinition"
, "DeclarationParser.NestedNamespaceDefinition"
, "DeclarationParser.NamespaceBody"
, "DeclarationParser.NestedNamespaceSpecifier"
, "DeclarationParser.NamespaceAliasDefinition"
, "DeclarationParser.Namespace"
, "DeclarationParser.QualifiedNamespaceSpecifier"
, "DeclarationParser.UsingDeclaration"
, "DeclarationParser.Using"
, "DeclarationParser.UsingDeclaratorList"
, "DeclarationParser.UsingDeclarator"
, "DeclarationParser.UsingEnumDeclaration"
, "DeclarationParser.UsingDirective"
, "DeclarationParser.NamespaceName"
, "DeclarationParser.StaticAssertDeclaration"
, "DeclarationParser.StaticAssert"
, "DeclarationParser.AliasDeclaration"
, "DeclarationParser.EmptyDeclaration"
, "DeclarationParser.AttributeDeclaration"
, "DeclarationParser.DeclSpecifierSeq"
, "DeclarationParser.Inline"
, "DeclarationParser.DeclSpecifier"
, "DeclarationParser.MSDeclSpecifier"
, "DeclarationParser.CDecl"
, "DeclarationParser.FastCall"
, "DeclarationParser.StdCall"
, "DeclarationParser.Unaligned"
, "DeclarationParser.DeclSpec"
, "DeclarationParser.DeclSpecDeprecated"
, "DeclarationParser.StorageClassSpecifier"
, "DeclarationParser.FunctionSpecifier"
, "DeclarationParser.ExplicitSpecifier"
, "DeclarationParser.InitDeclaratorList"
, "DeclarationParser.InitDeclarator"
, "DeclarationParser.Declarator"
, "DeclarationParser.PtrDeclarator"
, "DeclarationParser.NoPtrDeclarator"
, "DeclarationParser.ParametersAndQualifiers"
, "DeclarationParser.TrailingReturnType"
, "DeclarationParser.PtrOperator"
, "DeclarationParser.AbstractDeclarator"
, "DeclarationParser.NoPtrAbstractDeclarator"
, "DeclarationParser.PtrAbstractDeclarator"
, "DeclarationParser.AbstractPackDeclarator"
, "DeclarationParser.NoPtrAbstractPackDeclarator"
, "DeclarationParser.DeclaratorId"
, "DeclarationParser.Ptr"
, "DeclarationParser.LvalueRef"
, "DeclarationParser.RvalueRef"
, "DeclarationParser.RefQualifier"
, "DeclarationParser.CVQualifierSeq"
, "DeclarationParser.CVQualifier"
, "DeclarationParser.NoexceptSpecifier"
, "DeclarationParser.ThrowSpecifier"
, "EnumParser.EnumName"
, "EnumParser.EnumSpecifier"
, "EnumParser.EnumHead"
, "EnumParser.EnumKey"
, "EnumParser.EnumHeadName"
, "EnumParser.EnumBase"
, "EnumParser.EnumeratorList"
, "EnumParser.EnumeratorDefinition"
, "EnumParser.Enumerator"
, "EnumParser.ElaboratedEnumSpecifier"
, "EnumParser.OpaqueEnumDeclaration"
, "ExpressionParser.Expression"
, "ExpressionParser.ConstantExpression"
, "ExpressionParser.AssignmentExpression"
, "ExpressionParser.AssignmentOp"
, "ExpressionParser.ConditionalExpression"
, "ExpressionParser.Quest"
, "ExpressionParser.Colon"
, "ExpressionParser.YieldExpression"
, "ExpressionParser.ThrowExpression"
, "ExpressionParser.LogicalOrExpression"
, "ExpressionParser.LogicalAndExpression"
, "ExpressionParser.InclusiveOrExpression"
, "ExpressionParser.ExclusiveOrExpression"
, "ExpressionParser.AndExpression"
, "ExpressionParser.EqualityExpression"
, "ExpressionParser.EqualityOp"
, "ExpressionParser.RelationalExpression"
, "ExpressionParser.RelationalOp"
, "ExpressionParser.CompareExpression"
, "ExpressionParser.ShiftExpression"
, "ExpressionParser.ShiftOp"
, "ExpressionParser.AdditiveExpression"
, "ExpressionParser.AdditiveOp"
, "ExpressionParser.MultiplicativeExpression"
, "ExpressionParser.MultiplicativeOp"
, "ExpressionParser.PmExpression"
, "ExpressionParser.PmOp"
, "ExpressionParser.CastExpression"
, "ExpressionParser.UnaryExpression"
, "ExpressionParser.UnaryOp"
, "ExpressionParser.AwaitExpression"
, "ExpressionParser.SizeOfExpression"
, "ExpressionParser.AlignOfExpression"
, "ExpressionParser.NoexceptEpression"
, "ExpressionParser.NewExpression"
, "ExpressionParser.NewPlacement"
, "ExpressionParser.NewTypeId"
, "ExpressionParser.DeleteExpression"
, "ExpressionParser.PostfixExpression"
, "ExpressionParser.DotOp"
, "ExpressionParser.ArrowOp"
, "ExpressionParser.TypeIdExpression"
, "ExpressionParser.CppCastExpression"
, "ExpressionParser.PrimaryExpression"
, "ExpressionParser.ParenthesizedExpression"
, "ExpressionParser.IdExpression"
, "ExpressionParser.FoldExpression"
, "ExpressionParser.Ellipsis"
, "ExpressionParser.FoldOp"
, "ExpressionParser.NewDeclarator"
, "ExpressionParser.NoPtrNewDeclarator"
, "ExpressionParser.NewInitializer"
, "ExpressionParser.ExpressionList"
, "FunctionParser.FunctionDefinition"
, "FunctionParser.FunctionBody"
, "FunctionParser.Default"
, "FunctionParser.Delete"
, "FunctionParser.NoDeclSpecFunctionDeclaration"
, "FunctionParser.ParameterDeclarationClause"
, "FunctionParser.ParameterDeclarationList"
, "FunctionParser.Comma"
, "FunctionParser.ParameterDeclaration"
, "FunctionParser.Assign"
, "FunctionParser.OperatorFunctionId"
, "FunctionParser.ConversionFunctionId"
, "FunctionParser.DestructorId"
, "FunctionParser.ConversionTypeId"
, "FunctionParser.ConversionDeclarator"
, "FunctionParser.OperatorKw"
, "FunctionParser.Operator"
, "FunctionParser.Noexcept"
, "FunctionParser.FunctionTryBlock"
, "GuardParser.MemberFunctionTemplateGuard"
, "GuardParser.SavedMemberFunctionBodyGuard"
, "GuardParser.AssumeTypeGuard"
, "GuardParser.NotDefiningTypeSpecifierGuard"
, "GuardParser.MSVCModeGuard"
, "IdentifierParser.Identifier"
, "IdentifierParser.TypeIdentifier"
, "IdentifierParser.TypeIdentifierUnchecked"
, "IdentifierParser.TypeIdentifierChecked"
, "IdentifierParser.UnqualifiedId"
, "IdentifierParser.QualifiedId"
, "IdentifierParser.Template"
, "IdentifierParser.NestedNameSpecifier"
, "IdentifierParser.IdentifierList"
, "IdentifierParser.Unnamed"
, "IdentifierParser.Dot"
, "IdentifierParser.ColonColon"
, "InitializationParser.Initializer"
, "InitializationParser.InitializerClause"
, "InitializationParser.DesignatedInitializerClause"
, "InitializationParser.Designator"
, "InitializationParser.InitializerList"
, "InitializationParser.DesignatedInitializerList"
, "InitializationParser.ExprOrBracedInitList"
, "InitializationParser.BraceOrEqualInitializer"
, "InitializationParser.BracedInitList"
, "LambdaParser.LambdaExpression"
, "LambdaParser.LambdaIntroducer"
, "LambdaParser.LambdaCapture"
, "LambdaParser.CaptureDefault"
, "LambdaParser.CaptureList"
, "LambdaParser.Capture"
, "LambdaParser.InitCapture"
, "LambdaParser.SimpleCapture"
, "LambdaParser.LambdaDeclarator"
, "LambdaParser.LambdaSpecifiers"
, "LambdaParser.LambdaTemplateParams"
, "LiteralParser.Literal"
, "LiteralParser.UserDefinedLiteral"
, "LiteralParser.UdSuffix"
, "LiteralParser.LiteralOperatorId"
, "LiteralParser.StringLiteral"
, "ModuleParser.ModuleDeclaration"
, "ModuleParser.ExportDeclaration"
, "ModuleParser.ExportKeyword"
, "ModuleParser.ImportKeyword"
, "ModuleParser.ModuleKeyword"
, "ModuleParser.ImportDeclaration"
, "ModuleParser.ModuleName"
, "ModuleParser.ModulePartition"
, "ModuleParser.GlobalModuleFragment"
, "ModuleParser.PrivateModuleFragment"
, "ModuleParser.HeaderName"
, "SimpleTypeParser.SimpleType"
, "StatementParser.Statement"
, "StatementParser.LabeledStatement"
, "StatementParser.CompoundStatementUnguarded"
, "StatementParser.CompoundStatementGuarded"
, "StatementParser.CompoundStatementSaved"
, "StatementParser.CompoundStatement"
, "StatementParser.SelectionStatement"
, "StatementParser.IfStatement"
, "StatementParser.SwitchStatement"
, "StatementParser.IterationStatement"
, "StatementParser.WhileStatement"
, "StatementParser.DoStatement"
, "StatementParser.RangeForStatement"
, "StatementParser.ForRangeDeclaration"
, "StatementParser.ForRangeInitializer"
, "StatementParser.ForStatement"
, "StatementParser.JumpStatement"
, "StatementParser.BreakStatement"
, "StatementParser.ContinueStatement"
, "StatementParser.ReturnStatement"
, "StatementParser.CoroutineReturnStatement"
, "StatementParser.GotoStatement"
, "StatementParser.TryStatement"
, "StatementParser.HandlerSeq"
, "StatementParser.Handler"
, "StatementParser.ExceptionDeclaration"
, "StatementParser.DeclarationStatement"
, "StatementParser.ExpressionStatement"
, "StatementParser.InitStatement"
, "StatementParser.Condition"
, "StatementParser.Semicolon"
, "TemplateParser.TemplateDeclaration"
, "TemplateParser.TemplateHead"
, "TemplateParser.TemplateParameterList"
, "TemplateParser.TemplateParameter"
, "TemplateParser.TypeParameter"
, "TemplateParser.TypeParameterKey"
, "TemplateParser.Typename"
, "TemplateParser.TemplateId"
, "TemplateParser.SimpleTemplateId"
, "TemplateParser.TemplateName"
, "TemplateParser.TemplateArgumentList"
, "TemplateParser.TemplateArgument"
, "TemplateParser.DeductionGuide"
, "TemplateParser.Arrow"
, "TemplateParser.ExplicitInstantiation"
, "TemplateParser.Extern"
, "TemplateParser.Template"
, "TemplateParser.ExplicitSpecialization"
, "TranslationUnitParser.TranslationUnit"
, "TranslationUnitParser.ModuleUnit"
, "TypeParser.TypeSpecifierSeq"
, "TypeParser.DefiningTypeId"
, "TypeParser.DefiningTypeSpecifierSeq"
, "TypeParser.DefiningTypeSpecifier"
, "TypeParser.TypeSpecifier"
, "TypeParser.ElaboratedTypeSpecifier"
, "TypeParser.SimpleTypeSpecifier"
, "TypeParser.TypeName"
, "TypeParser.TypeId"
, "TypeParser.TypenameSpecifier"
, "TypeParser.DeclTypeSpecifier"
, "TypeParser.PlaceholderTypeSpecifier"
};

std::vector<const char*>* GetRuleNameVecPtr()
{
    return &rules;
}
