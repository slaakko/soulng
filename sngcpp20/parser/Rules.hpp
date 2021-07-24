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
const int ClassParser_MemberDeclaratorList = 40;
const int ClassParser_MemberDeclarator = 41;
const int ClassParser_CtorInitializer = 42;
const int ClassParser_MemberInitializerList = 43;
const int ClassParser_MemberInitializer = 44;
const int ClassParser_MemberInitializerId = 45;
const int ConceptParser_ConceptDefinition = 46;
const int ConceptParser_ConceptName = 47;
const int ConceptParser_RequiresExpression = 48;
const int ConceptParser_RequirementParameterList = 49;
const int ConceptParser_RequirementBody = 50;
const int ConceptParser_RequirementSeq = 51;
const int ConceptParser_Requirement = 52;
const int ConceptParser_SimpleRequirement = 53;
const int ConceptParser_TypeRequirement = 54;
const int ConceptParser_CompoundRequirement = 55;
const int ConceptParser_ReturnTypeRequirement = 56;
const int ConceptParser_NestedRequirement = 57;
const int ConceptParser_TypeConstraint = 58;
const int ConceptParser_ConstraintExpression = 59;
const int ConceptParser_RequiresClause = 60;
const int ConceptParser_ConstraintLogicalOrExpression = 61;
const int ConceptParser_ConstraintLogicalAndExpression = 62;
const int DeclarationParser_DeclarationSeq = 63;
const int DeclarationParser_Declaration = 64;
const int DeclarationParser_BlockDeclaration = 65;
const int DeclarationParser_SimpleDeclaration = 66;
const int DeclarationParser_AsmDeclaration = 67;
const int DeclarationParser_Asm = 68;
const int DeclarationParser_LinkageSpecification = 69;
const int DeclarationParser_NamespaceDefinition = 70;
const int DeclarationParser_NamedNamespaceDefinition = 71;
const int DeclarationParser_UnnamedNamespaceDefinition = 72;
const int DeclarationParser_NestedNamespaceDefinition = 73;
const int DeclarationParser_NamespaceBody = 74;
const int DeclarationParser_NestedNamespaceSpecifier = 75;
const int DeclarationParser_NamespaceAliasDefinition = 76;
const int DeclarationParser_Namespace = 77;
const int DeclarationParser_QualifiedNamespaceSpecifier = 78;
const int DeclarationParser_UsingDeclaration = 79;
const int DeclarationParser_Using = 80;
const int DeclarationParser_UsingDeclaratorList = 81;
const int DeclarationParser_UsingDeclarator = 82;
const int DeclarationParser_UsingEnumDeclaration = 83;
const int DeclarationParser_UsingDirective = 84;
const int DeclarationParser_NamespaceName = 85;
const int DeclarationParser_StaticAssertDeclaration = 86;
const int DeclarationParser_StaticAssert = 87;
const int DeclarationParser_AliasDeclaration = 88;
const int DeclarationParser_EmptyDeclaration = 89;
const int DeclarationParser_AttributeDeclaration = 90;
const int DeclarationParser_DeclSpecifierSeq = 91;
const int DeclarationParser_Inline = 92;
const int DeclarationParser_DeclSpecifier = 93;
const int DeclarationParser_MSDeclSpecifier = 94;
const int DeclarationParser_CDecl = 95;
const int DeclarationParser_FastCall = 96;
const int DeclarationParser_StdCall = 97;
const int DeclarationParser_ThisCall = 98;
const int DeclarationParser_VectorCall = 99;
const int DeclarationParser_Unaligned = 100;
const int DeclarationParser_DeclSpec = 101;
const int DeclarationParser_DeclSpecDeprecated = 102;
const int DeclarationParser_StorageClassSpecifier = 103;
const int DeclarationParser_FunctionSpecifier = 104;
const int DeclarationParser_ExplicitSpecifier = 105;
const int DeclarationParser_InitDeclaratorList = 106;
const int DeclarationParser_InitDeclarator = 107;
const int DeclarationParser_Declarator = 108;
const int DeclarationParser_PtrDeclarator = 109;
const int DeclarationParser_NoPtrDeclarator = 110;
const int DeclarationParser_ParametersAndQualifiers = 111;
const int DeclarationParser_TrailingReturnType = 112;
const int DeclarationParser_PtrOperator = 113;
const int DeclarationParser_AbstractDeclarator = 114;
const int DeclarationParser_NoPtrAbstractDeclarator = 115;
const int DeclarationParser_PtrAbstractDeclarator = 116;
const int DeclarationParser_AbstractPackDeclarator = 117;
const int DeclarationParser_NoPtrAbstractPackDeclarator = 118;
const int DeclarationParser_DeclaratorId = 119;
const int DeclarationParser_Ptr = 120;
const int DeclarationParser_LvalueRef = 121;
const int DeclarationParser_RvalueRef = 122;
const int DeclarationParser_RefQualifier = 123;
const int DeclarationParser_CVQualifierSeq = 124;
const int DeclarationParser_CVQualifier = 125;
const int DeclarationParser_NoexceptSpecifier = 126;
const int DeclarationParser_ThrowSpecifier = 127;
const int EnumParser_EnumName = 128;
const int EnumParser_EnumSpecifier = 129;
const int EnumParser_EnumHead = 130;
const int EnumParser_EnumKey = 131;
const int EnumParser_EnumHeadName = 132;
const int EnumParser_EnumBase = 133;
const int EnumParser_EnumeratorList = 134;
const int EnumParser_EnumeratorDefinition = 135;
const int EnumParser_Enumerator = 136;
const int EnumParser_ElaboratedEnumSpecifier = 137;
const int EnumParser_OpaqueEnumDeclaration = 138;
const int ExpressionParser_Expression = 139;
const int ExpressionParser_ConstantExpression = 140;
const int ExpressionParser_AssignmentExpression = 141;
const int ExpressionParser_AssignmentOp = 142;
const int ExpressionParser_ConditionalExpression = 143;
const int ExpressionParser_Quest = 144;
const int ExpressionParser_Colon = 145;
const int ExpressionParser_YieldExpression = 146;
const int ExpressionParser_ThrowExpression = 147;
const int ExpressionParser_LogicalOrExpression = 148;
const int ExpressionParser_LogicalAndExpression = 149;
const int ExpressionParser_InclusiveOrExpression = 150;
const int ExpressionParser_ExclusiveOrExpression = 151;
const int ExpressionParser_AndExpression = 152;
const int ExpressionParser_EqualityExpression = 153;
const int ExpressionParser_EqualityOp = 154;
const int ExpressionParser_RelationalExpression = 155;
const int ExpressionParser_RelationalOp = 156;
const int ExpressionParser_CompareExpression = 157;
const int ExpressionParser_ShiftExpression = 158;
const int ExpressionParser_ShiftOp = 159;
const int ExpressionParser_AdditiveExpression = 160;
const int ExpressionParser_AdditiveOp = 161;
const int ExpressionParser_MultiplicativeExpression = 162;
const int ExpressionParser_MultiplicativeOp = 163;
const int ExpressionParser_PmExpression = 164;
const int ExpressionParser_PmOp = 165;
const int ExpressionParser_CastExpression = 166;
const int ExpressionParser_UnaryExpression = 167;
const int ExpressionParser_UnaryOp = 168;
const int ExpressionParser_AwaitExpression = 169;
const int ExpressionParser_SizeOfExpression = 170;
const int ExpressionParser_AlignOfExpression = 171;
const int ExpressionParser_NoexceptEpression = 172;
const int ExpressionParser_NewExpression = 173;
const int ExpressionParser_NewPlacement = 174;
const int ExpressionParser_NewTypeId = 175;
const int ExpressionParser_DeleteExpression = 176;
const int ExpressionParser_PostfixExpression = 177;
const int ExpressionParser_DotOp = 178;
const int ExpressionParser_ArrowOp = 179;
const int ExpressionParser_TypeIdExpression = 180;
const int ExpressionParser_CppCastExpression = 181;
const int ExpressionParser_PrimaryExpression = 182;
const int ExpressionParser_ParenthesizedExpression = 183;
const int ExpressionParser_IdExpression = 184;
const int ExpressionParser_IdExpr = 185;
const int ExpressionParser_FoldExpression = 186;
const int ExpressionParser_Ellipsis = 187;
const int ExpressionParser_FoldOp = 188;
const int ExpressionParser_NewDeclarator = 189;
const int ExpressionParser_NoPtrNewDeclarator = 190;
const int ExpressionParser_NewInitializer = 191;
const int ExpressionParser_ExpressionList = 192;
const int FunctionParser_FunctionDefinition = 193;
const int FunctionParser_FunctionBody = 194;
const int FunctionParser_Default = 195;
const int FunctionParser_Delete = 196;
const int FunctionParser_NoDeclSpecFunctionDeclaration = 197;
const int FunctionParser_ParameterDeclarationClause = 198;
const int FunctionParser_ParameterDeclarationList = 199;
const int FunctionParser_Comma = 200;
const int FunctionParser_ParameterDeclaration = 201;
const int FunctionParser_Assign = 202;
const int FunctionParser_OperatorFunctionId = 203;
const int FunctionParser_ConversionFunctionId = 204;
const int FunctionParser_DestructorId = 205;
const int FunctionParser_ConversionTypeId = 206;
const int FunctionParser_ConversionDeclarator = 207;
const int FunctionParser_OperatorKw = 208;
const int FunctionParser_Operator = 209;
const int FunctionParser_Noexcept = 210;
const int FunctionParser_FunctionTryBlock = 211;
const int GuardParser_MemberFunctionTemplateGuard = 212;
const int GuardParser_SavedMemberFunctionBodyGuard = 213;
const int GuardParser_AssumeTypeGuard = 214;
const int GuardParser_NotDefiningTypeSpecifierGuard = 215;
const int GuardParser_MSVCModeGuard = 216;
const int IdentifierParser_Identifier = 217;
const int IdentifierParser_TypeIdentifier = 218;
const int IdentifierParser_TypeIdentifierUnchecked = 219;
const int IdentifierParser_TypeIdentifierChecked = 220;
const int IdentifierParser_UnqualifiedId = 221;
const int IdentifierParser_QualifiedId = 222;
const int IdentifierParser_Template = 223;
const int IdentifierParser_NestedNameSpecifier = 224;
const int IdentifierParser_IdentifierList = 225;
const int IdentifierParser_Unnamed = 226;
const int IdentifierParser_Dot = 227;
const int IdentifierParser_ColonColon = 228;
const int InitializationParser_Initializer = 229;
const int InitializationParser_InitializerClause = 230;
const int InitializationParser_DesignatedInitializerClause = 231;
const int InitializationParser_Designator = 232;
const int InitializationParser_InitializerList = 233;
const int InitializationParser_DesignatedInitializerList = 234;
const int InitializationParser_ExprOrBracedInitList = 235;
const int InitializationParser_BraceOrEqualInitializer = 236;
const int InitializationParser_BracedInitList = 237;
const int LambdaParser_LambdaExpression = 238;
const int LambdaParser_LambdaIntroducer = 239;
const int LambdaParser_LambdaCapture = 240;
const int LambdaParser_CaptureDefault = 241;
const int LambdaParser_CaptureList = 242;
const int LambdaParser_Capture = 243;
const int LambdaParser_InitCapture = 244;
const int LambdaParser_SimpleCapture = 245;
const int LambdaParser_LambdaDeclarator = 246;
const int LambdaParser_LambdaSpecifiers = 247;
const int LambdaParser_LambdaTemplateParams = 248;
const int LiteralParser_Literal = 249;
const int LiteralParser_UserDefinedLiteral = 250;
const int LiteralParser_UdSuffix = 251;
const int LiteralParser_LiteralOperatorId = 252;
const int LiteralParser_StringLiteral = 253;
const int ModuleParser_ModuleDeclaration = 254;
const int ModuleParser_ExportDeclaration = 255;
const int ModuleParser_ExportKeyword = 256;
const int ModuleParser_ImportKeyword = 257;
const int ModuleParser_ModuleKeyword = 258;
const int ModuleParser_ImportDeclaration = 259;
const int ModuleParser_ModuleName = 260;
const int ModuleParser_ModulePartition = 261;
const int ModuleParser_GlobalModuleFragment = 262;
const int ModuleParser_PrivateModuleFragment = 263;
const int ModuleParser_HeaderName = 264;
const int SimpleTypeParser_SimpleType = 265;
const int StatementParser_Statement = 266;
const int StatementParser_LabeledStatement = 267;
const int StatementParser_CompoundStatementUnguarded = 268;
const int StatementParser_CompoundStatementGuarded = 269;
const int StatementParser_CompoundStatementSaved = 270;
const int StatementParser_CompoundStatement = 271;
const int StatementParser_SelectionStatement = 272;
const int StatementParser_IfStatement = 273;
const int StatementParser_SwitchStatement = 274;
const int StatementParser_IterationStatement = 275;
const int StatementParser_WhileStatement = 276;
const int StatementParser_DoStatement = 277;
const int StatementParser_RangeForStatement = 278;
const int StatementParser_ForRangeDeclaration = 279;
const int StatementParser_ForRangeInitializer = 280;
const int StatementParser_ForStatement = 281;
const int StatementParser_JumpStatement = 282;
const int StatementParser_BreakStatement = 283;
const int StatementParser_ContinueStatement = 284;
const int StatementParser_ReturnStatement = 285;
const int StatementParser_CoroutineReturnStatement = 286;
const int StatementParser_GotoStatement = 287;
const int StatementParser_TryStatement = 288;
const int StatementParser_HandlerSeq = 289;
const int StatementParser_Handler = 290;
const int StatementParser_ExceptionDeclaration = 291;
const int StatementParser_DeclarationStatement = 292;
const int StatementParser_ExpressionStatement = 293;
const int StatementParser_InitStatement = 294;
const int StatementParser_Condition = 295;
const int StatementParser_Semicolon = 296;
const int TemplateParser_TemplateDeclaration = 297;
const int TemplateParser_TemplateHead = 298;
const int TemplateParser_TemplateParameterList = 299;
const int TemplateParser_TemplateParameter = 300;
const int TemplateParser_TypeParameter = 301;
const int TemplateParser_TypeParameterKey = 302;
const int TemplateParser_Typename = 303;
const int TemplateParser_TemplateId = 304;
const int TemplateParser_SimpleTemplateId = 305;
const int TemplateParser_TemplateName = 306;
const int TemplateParser_TemplateArgumentList = 307;
const int TemplateParser_TemplateArgument = 308;
const int TemplateParser_DeductionGuide = 309;
const int TemplateParser_Arrow = 310;
const int TemplateParser_ExplicitInstantiation = 311;
const int TemplateParser_Extern = 312;
const int TemplateParser_Template = 313;
const int TemplateParser_ExplicitSpecialization = 314;
const int TranslationUnitParser_TranslationUnit = 315;
const int TranslationUnitParser_ModuleUnit = 316;
const int TypeParser_TypeSpecifierSeq = 317;
const int TypeParser_DefiningTypeId = 318;
const int TypeParser_DefiningTypeSpecifierSeq = 319;
const int TypeParser_DefiningTypeSpecifierReset = 320;
const int TypeParser_DefiningTypeSpecifier = 321;
const int TypeParser_TypeSpecifier = 322;
const int TypeParser_ElaboratedTypeSpecifier = 323;
const int TypeParser_SimpleTypeSpecifier = 324;
const int TypeParser_TypeName = 325;
const int TypeParser_QualifiedTypeName = 326;
const int TypeParser_TypeId = 327;
const int TypeParser_TypenameSpecifier = 328;
const int TypeParser_DeclTypeSpecifier = 329;
const int TypeParser_PlaceholderTypeSpecifier = 330;

#endif // RULES_H
