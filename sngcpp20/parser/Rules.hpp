#ifndef RULES_H
#define RULES_H
#include <sngcpp20/parser/ParserApi.hpp>
#include <sngcpp20/symbols/Context.hpp>
#include <sngcpp20/ast/Attribute.hpp>
#include <vector>

PARSER_API std::vector<const char*>* GetRuleNameVecPtr();

const int AttributeParser_AttributeSpecifierSeq = 0;
const int AttributeParser_AttributeSpecifier = 1;
const int AttributeParser_AttributeList = 2;
const int AttributeParser_AttributeUsingPrefix = 3;
const int AttributeParser_AttributeNamespace = 4;
const int AttributeParser_Attribute = 5;
const int AttributeParser_AttributeToken = 6;
const int AttributeParser_AttributeScopedToken = 7;
const int AttributeParser_AttributeArgumentClause = 8;
const int AttributeParser_BalancedTokenSeq = 9;
const int AttributeParser_BalancedToken = 10;
const int AttributeParser_AlignmentSpecifier = 11;
const int AttributeParser_LParen = 12;
const int AttributeParser_RParen = 13;
const int AttributeParser_LBracket = 14;
const int AttributeParser_RBracket = 15;
const int AttributeParser_LBrace = 16;
const int AttributeParser_RBrace = 17;
const int ClassParser_ClassSpecifier = 18;
const int ClassParser_ClassHead = 19;
const int ClassParser_ClassHeadName = 20;
const int ClassParser_ClassName = 21;
const int ClassParser_ClassKey = 22;
const int ClassParser_BaseClause = 23;
const int ClassParser_BaseSpecifierList = 24;
const int ClassParser_BaseSpecifier = 25;
const int ClassParser_ClassOrDeclType = 26;
const int ClassParser_AccessSpecifier = 27;
const int ClassParser_Private = 28;
const int ClassParser_VirtualSpecifier = 29;
const int ClassParser_ClassVirtSpecifier = 30;
const int ClassParser_VirtSpecifierSeq = 31;
const int ClassParser_VirtSpecifier = 32;
const int ClassParser_OverrideKeyword = 33;
const int ClassParser_FinalKeyword = 34;
const int ClassParser_PureSpecifier = 35;
const int ClassParser_MemberSpecification = 36;
const int ClassParser_MemberDeclaration = 37;
const int ClassParser_MemberDeclSpecifiers = 38;
const int ClassParser_MemberFunctionDefinition = 39;
const int ClassParser_MemberTemplateDeclaration = 40;
const int ClassParser_MemberDeclaratorList = 41;
const int ClassParser_MemberDeclarator = 42;
const int ClassParser_CtorInitializer = 43;
const int ClassParser_MemberInitializerList = 44;
const int ClassParser_MemberInitializer = 45;
const int ClassParser_MemberInitializerId = 46;
const int ConceptParser_ConceptDefinition = 47;
const int ConceptParser_ConceptName = 48;
const int ConceptParser_RequiresExpression = 49;
const int ConceptParser_RequirementParameterList = 50;
const int ConceptParser_RequirementBody = 51;
const int ConceptParser_RequirementSeq = 52;
const int ConceptParser_Requirement = 53;
const int ConceptParser_SimpleRequirement = 54;
const int ConceptParser_TypeRequirement = 55;
const int ConceptParser_CompoundRequirement = 56;
const int ConceptParser_ReturnTypeRequirement = 57;
const int ConceptParser_NestedRequirement = 58;
const int ConceptParser_TypeConstraint = 59;
const int ConceptParser_ConstraintExpression = 60;
const int ConceptParser_RequiresClause = 61;
const int ConceptParser_ConstraintLogicalOrExpression = 62;
const int ConceptParser_ConstraintLogicalAndExpression = 63;
const int DeclarationParser_DeclarationSeq = 64;
const int DeclarationParser_Declaration = 65;
const int DeclarationParser_BlockDeclaration = 66;
const int DeclarationParser_SimpleDeclaration = 67;
const int DeclarationParser_AsmDeclaration = 68;
const int DeclarationParser_Asm = 69;
const int DeclarationParser_LinkageSpecification = 70;
const int DeclarationParser_NamespaceDefinition = 71;
const int DeclarationParser_NamedNamespaceDefinition = 72;
const int DeclarationParser_UnnamedNamespaceDefinition = 73;
const int DeclarationParser_NestedNamespaceDefinition = 74;
const int DeclarationParser_NamespaceBody = 75;
const int DeclarationParser_NestedNamespaceSpecifier = 76;
const int DeclarationParser_NamespaceAliasDefinition = 77;
const int DeclarationParser_Namespace = 78;
const int DeclarationParser_QualifiedNamespaceSpecifier = 79;
const int DeclarationParser_UsingDeclaration = 80;
const int DeclarationParser_Using = 81;
const int DeclarationParser_UsingDeclaratorList = 82;
const int DeclarationParser_UsingDeclarator = 83;
const int DeclarationParser_UsingEnumDeclaration = 84;
const int DeclarationParser_UsingDirective = 85;
const int DeclarationParser_NamespaceName = 86;
const int DeclarationParser_StaticAssertDeclaration = 87;
const int DeclarationParser_StaticAssert = 88;
const int DeclarationParser_AliasDeclaration = 89;
const int DeclarationParser_DefiningTypeIdOrIntrinsic = 90;
const int DeclarationParser_EmptyDeclaration = 91;
const int DeclarationParser_AttributeDeclaration = 92;
const int DeclarationParser_DeclSpecifierSeq = 93;
const int DeclarationParser_Inline = 94;
const int DeclarationParser_DeclSpecifier = 95;
const int DeclarationParser_MSDeclSpecifier = 96;
const int DeclarationParser_CDecl = 97;
const int DeclarationParser_FastCall = 98;
const int DeclarationParser_StdCall = 99;
const int DeclarationParser_ThisCall = 100;
const int DeclarationParser_VectorCall = 101;
const int DeclarationParser_Unaligned = 102;
const int DeclarationParser_DeclSpec = 103;
const int DeclarationParser_DeclSpecDeprecated = 104;
const int DeclarationParser_StorageClassSpecifier = 105;
const int DeclarationParser_FunctionSpecifier = 106;
const int DeclarationParser_ExplicitSpecifier = 107;
const int DeclarationParser_InitDeclaratorList = 108;
const int DeclarationParser_InitDeclarator = 109;
const int DeclarationParser_Declarator = 110;
const int DeclarationParser_PtrDeclarator = 111;
const int DeclarationParser_NoPtrDeclarator = 112;
const int DeclarationParser_ParametersAndQualifiers = 113;
const int DeclarationParser_TrailingReturnType = 114;
const int DeclarationParser_PtrOperator = 115;
const int DeclarationParser_AbstractDeclarator = 116;
const int DeclarationParser_NoPtrAbstractDeclarator = 117;
const int DeclarationParser_PtrAbstractDeclarator = 118;
const int DeclarationParser_AbstractPackDeclarator = 119;
const int DeclarationParser_NoPtrAbstractPackDeclarator = 120;
const int DeclarationParser_DeclaratorId = 121;
const int DeclarationParser_Ptr = 122;
const int DeclarationParser_LvalueRef = 123;
const int DeclarationParser_RvalueRef = 124;
const int DeclarationParser_RefQualifier = 125;
const int DeclarationParser_CVQualifierSeq = 126;
const int DeclarationParser_CVQualifier = 127;
const int DeclarationParser_NoexceptSpecifier = 128;
const int DeclarationParser_ThrowSpecifier = 129;
const int DeclarationParser_MSPragma = 130;
const int DeclarationParser_ParenthesizedTokens = 131;
const int EnumParser_EnumName = 132;
const int EnumParser_EnumSpecifier = 133;
const int EnumParser_EnumHead = 134;
const int EnumParser_EnumKey = 135;
const int EnumParser_EnumHeadName = 136;
const int EnumParser_EnumBase = 137;
const int EnumParser_EnumeratorList = 138;
const int EnumParser_EnumeratorDefinition = 139;
const int EnumParser_Enumerator = 140;
const int EnumParser_ElaboratedEnumSpecifier = 141;
const int EnumParser_OpaqueEnumDeclaration = 142;
const int ExpressionParser_Expression = 143;
const int ExpressionParser_ConstantExpression = 144;
const int ExpressionParser_AssignmentExpression = 145;
const int ExpressionParser_AssignmentOp = 146;
const int ExpressionParser_ConditionalExpression = 147;
const int ExpressionParser_Quest = 148;
const int ExpressionParser_Colon = 149;
const int ExpressionParser_YieldExpression = 150;
const int ExpressionParser_ThrowExpression = 151;
const int ExpressionParser_LogicalOrExpression = 152;
const int ExpressionParser_LogicalAndExpression = 153;
const int ExpressionParser_InclusiveOrExpression = 154;
const int ExpressionParser_ExclusiveOrExpression = 155;
const int ExpressionParser_AndExpression = 156;
const int ExpressionParser_EqualityExpression = 157;
const int ExpressionParser_EqualityOp = 158;
const int ExpressionParser_RelationalExpression = 159;
const int ExpressionParser_RelationalOp = 160;
const int ExpressionParser_CompareExpression = 161;
const int ExpressionParser_ShiftExpression = 162;
const int ExpressionParser_ShiftOp = 163;
const int ExpressionParser_AdditiveExpression = 164;
const int ExpressionParser_AdditiveOp = 165;
const int ExpressionParser_MultiplicativeExpression = 166;
const int ExpressionParser_MultiplicativeOp = 167;
const int ExpressionParser_PmExpression = 168;
const int ExpressionParser_PmOp = 169;
const int ExpressionParser_CastExpression = 170;
const int ExpressionParser_UnaryExpression = 171;
const int ExpressionParser_UnaryOp = 172;
const int ExpressionParser_AwaitExpression = 173;
const int ExpressionParser_SizeOfExpression = 174;
const int ExpressionParser_AlignOfExpression = 175;
const int ExpressionParser_NoexceptEpression = 176;
const int ExpressionParser_NewExpression = 177;
const int ExpressionParser_NewPlacement = 178;
const int ExpressionParser_NewTypeId = 179;
const int ExpressionParser_DeleteExpression = 180;
const int ExpressionParser_IntrinsicInvokeExpr = 181;
const int ExpressionParser_PostfixExpression = 182;
const int ExpressionParser_DotOp = 183;
const int ExpressionParser_ArrowOp = 184;
const int ExpressionParser_TypeIdExpression = 185;
const int ExpressionParser_CppCastExpression = 186;
const int ExpressionParser_PrimaryExpression = 187;
const int ExpressionParser_ParenthesizedExpression = 188;
const int ExpressionParser_IdExpression = 189;
const int ExpressionParser_IdExpr = 190;
const int ExpressionParser_FoldExpression = 191;
const int ExpressionParser_Ellipsis = 192;
const int ExpressionParser_FoldOp = 193;
const int ExpressionParser_NewDeclarator = 194;
const int ExpressionParser_NoPtrNewDeclarator = 195;
const int ExpressionParser_NewInitializer = 196;
const int ExpressionParser_ExpressionList = 197;
const int FunctionParser_FunctionDefinition = 198;
const int FunctionParser_FunctionBody = 199;
const int FunctionParser_Default = 200;
const int FunctionParser_Delete = 201;
const int FunctionParser_NoDeclSpecFunctionDeclaration = 202;
const int FunctionParser_ParameterDeclarationClause = 203;
const int FunctionParser_ParameterDeclarationList = 204;
const int FunctionParser_Comma = 205;
const int FunctionParser_ParameterDeclaration = 206;
const int FunctionParser_Assign = 207;
const int FunctionParser_OperatorFunctionId = 208;
const int FunctionParser_ConversionFunctionId = 209;
const int FunctionParser_DestructorId = 210;
const int FunctionParser_ConversionTypeId = 211;
const int FunctionParser_ConversionDeclarator = 212;
const int FunctionParser_OperatorKw = 213;
const int FunctionParser_Operator = 214;
const int FunctionParser_Noexcept = 215;
const int FunctionParser_FunctionTryBlock = 216;
const int GuardParser_MemberFunctionTemplateGuard = 217;
const int GuardParser_SavedMemberFunctionBodyGuard = 218;
const int GuardParser_AssumeTypeGuard = 219;
const int GuardParser_NotDefiningTypeSpecifierGuard = 220;
const int GuardParser_MSVCModeGuard = 221;
const int IdentifierParser_Identifier = 222;
const int IdentifierParser_TypeIdentifier = 223;
const int IdentifierParser_TypeIdentifierUnchecked = 224;
const int IdentifierParser_TypeIdentifierChecked = 225;
const int IdentifierParser_UnqualifiedId = 226;
const int IdentifierParser_QualifiedId = 227;
const int IdentifierParser_Template = 228;
const int IdentifierParser_NestedNameSpecifier = 229;
const int IdentifierParser_IdentifierList = 230;
const int IdentifierParser_Unnamed = 231;
const int IdentifierParser_Dot = 232;
const int IdentifierParser_ColonColon = 233;
const int InitializationParser_Initializer = 234;
const int InitializationParser_InitializerClause = 235;
const int InitializationParser_DesignatedInitializerClause = 236;
const int InitializationParser_Designator = 237;
const int InitializationParser_InitializerList = 238;
const int InitializationParser_DesignatedInitializerList = 239;
const int InitializationParser_ExprOrBracedInitList = 240;
const int InitializationParser_BraceOrEqualInitializer = 241;
const int InitializationParser_BracedInitList = 242;
const int LambdaParser_LambdaExpression = 243;
const int LambdaParser_LambdaIntroducer = 244;
const int LambdaParser_LambdaCapture = 245;
const int LambdaParser_CaptureDefault = 246;
const int LambdaParser_CaptureList = 247;
const int LambdaParser_Capture = 248;
const int LambdaParser_InitCapture = 249;
const int LambdaParser_SimpleCapture = 250;
const int LambdaParser_LambdaDeclarator = 251;
const int LambdaParser_LambdaSpecifiers = 252;
const int LambdaParser_LambdaTemplateParams = 253;
const int LiteralParser_Literal = 254;
const int LiteralParser_UserDefinedLiteral = 255;
const int LiteralParser_UdSuffix = 256;
const int LiteralParser_LiteralOperatorId = 257;
const int LiteralParser_StringLiteral = 258;
const int ModuleParser_ModuleDeclaration = 259;
const int ModuleParser_ExportDeclaration = 260;
const int ModuleParser_ExportKeyword = 261;
const int ModuleParser_ImportKeyword = 262;
const int ModuleParser_ModuleKeyword = 263;
const int ModuleParser_ImportDeclaration = 264;
const int ModuleParser_ModuleName = 265;
const int ModuleParser_ModulePartition = 266;
const int ModuleParser_GlobalModuleFragment = 267;
const int ModuleParser_PrivateModuleFragment = 268;
const int ModuleParser_HeaderName = 269;
const int SimpleTypeParser_SimpleType = 270;
const int StatementParser_Statement = 271;
const int StatementParser_LabeledStatement = 272;
const int StatementParser_CompoundStatementUnguarded = 273;
const int StatementParser_CompoundStatementGuarded = 274;
const int StatementParser_CompoundStatementSaved = 275;
const int StatementParser_CompoundStatement = 276;
const int StatementParser_SelectionStatement = 277;
const int StatementParser_IfStatement = 278;
const int StatementParser_SwitchStatement = 279;
const int StatementParser_IterationStatement = 280;
const int StatementParser_WhileStatement = 281;
const int StatementParser_DoStatement = 282;
const int StatementParser_RangeForStatement = 283;
const int StatementParser_ForRangeDeclaration = 284;
const int StatementParser_ForRangeInitializer = 285;
const int StatementParser_ForStatement = 286;
const int StatementParser_JumpStatement = 287;
const int StatementParser_BreakStatement = 288;
const int StatementParser_ContinueStatement = 289;
const int StatementParser_ReturnStatement = 290;
const int StatementParser_CoroutineReturnStatement = 291;
const int StatementParser_GotoStatement = 292;
const int StatementParser_TryStatement = 293;
const int StatementParser_HandlerSeq = 294;
const int StatementParser_Handler = 295;
const int StatementParser_ExceptionDeclaration = 296;
const int StatementParser_DeclarationStatement = 297;
const int StatementParser_ExpressionStatement = 298;
const int StatementParser_InitStatement = 299;
const int StatementParser_Condition = 300;
const int StatementParser_Semicolon = 301;
const int TemplateParser_TemplateDeclaration = 302;
const int TemplateParser_TemplateHead = 303;
const int TemplateParser_TemplateParameterList = 304;
const int TemplateParser_TemplateParameter = 305;
const int TemplateParser_TypeParameter = 306;
const int TemplateParser_TypeParameterKey = 307;
const int TemplateParser_Typename = 308;
const int TemplateParser_TemplateId = 309;
const int TemplateParser_SimpleTemplateId = 310;
const int TemplateParser_TemplateName = 311;
const int TemplateParser_TemplateArgumentList = 312;
const int TemplateParser_TemplateArgument = 313;
const int TemplateParser_TemplateArgNext = 314;
const int TemplateParser_DeductionGuide = 315;
const int TemplateParser_Arrow = 316;
const int TemplateParser_ExplicitInstantiation = 317;
const int TemplateParser_Extern = 318;
const int TemplateParser_Template = 319;
const int TemplateParser_ExplicitSpecialization = 320;
const int TranslationUnitParser_TranslationUnit = 321;
const int TranslationUnitParser_ModuleUnit = 322;
const int TypeParser_TypeSpecifierSeq = 323;
const int TypeParser_DefiningTypeId = 324;
const int TypeParser_DefiningTypeSpecifierSeq = 325;
const int TypeParser_DefiningTypeSpecifierReset = 326;
const int TypeParser_DefiningTypeSpecifier = 327;
const int TypeParser_TypeSpecifier = 328;
const int TypeParser_ElaboratedTypeSpecifier = 329;
const int TypeParser_SimpleTypeSpecifierReset = 330;
const int TypeParser_SimpleTypeSpecifier = 331;
const int TypeParser_TypeName = 332;
const int TypeParser_QualifiedTypeName = 333;
const int TypeParser_TypeId = 334;
const int TypeParser_TypenameSpecifier = 335;
const int TypeParser_DeclTypeSpecifier = 336;
const int TypeParser_PlaceholderTypeSpecifier = 337;

#endif // RULES_H
