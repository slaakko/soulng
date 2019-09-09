namespace soulng.code
{
    grammar Declaration
    {
        BlockDeclaration: soulng::codedom::CppObject*;
        SimpleDeclaration(var std::unique_ptr<SimpleDeclaration> sd): soulng::codedom::SimpleDeclaration*;
        DeclSpecifierSeq(soulng::codedom::SimpleDeclaration* declaration);
        DeclSpecifier: soulng::codedom::DeclSpecifier*;
        StorageClassSpecifier: soulng::codedom::StorageClassSpecifier*;
        TypeSpecifier: soulng::codedom::TypeSpecifier*;
        SimpleTypeSpecifier: soulng::codedom::TypeSpecifier*;
        TypeName: soulng::codedom::TypeName*;
        TemplateArgumentList(soulng::codedom::TypeName* typeName);
        TemplateArgument: soulng::codedom::CppObject*;
        Typedef: soulng::codedom::DeclSpecifier*;
        CVQualifier: soulng::codedom::TypeSpecifier*;
        NamespaceAliasDefinition: soulng::codedom::UsingObject*;
        UsingDeclaration: soulng::codedom::UsingObject*;
        UsingDirective: soulng::codedom::UsingObject*;
    }
    grammar Statement
    {
        Statement: soulng::codedom::Statement*;
        LabeledStatement: soulng::codedom::Statement*;
        Label: std::u32string;
        EmptyStatement: soulng::codedom::Statement*;
        ExpressionStatement: soulng::codedom::Statement*;
        CompoundStatement(var std::unique_ptr<CompoundStatement> cs): soulng::codedom::CompoundStatement*;
        SelectionStatement: soulng::codedom::Statement*;
        IfStatement: soulng::codedom::Statement*;
        SwitchStatement: soulng::codedom::Statement*;
        IterationStatement: soulng::codedom::Statement*;
        WhileStatement: soulng::codedom::Statement*;
        DoStatement: soulng::codedom::Statement*;
        ForStatement: soulng::codedom::Statement*;
        ForInitStatement: soulng::codedom::CppObject*;
        JumpStatement: soulng::codedom::Statement*;
        BreakStatement: soulng::codedom::Statement*;
        ContinueStatement: soulng::codedom::Statement*;
        ReturnStatement: soulng::codedom::Statement*;
        GotoStatement: soulng::codedom::Statement*;
        GotoTarget: std::u32string;
        DeclarationStatement: soulng::codedom::Statement*;
        Condition(var std::unique_ptr<TypeId> ti): soulng::codedom::CppObject*;
        TryStatement: soulng::codedom::TryStatement*;
        HandlerSeq(TryStatement* st);
        Handler: soulng::codedom::Handler*;
        ExceptionDeclaration(var std::unique_ptr<ExceptionDeclaration> ed): soulng::codedom::ExceptionDeclaration*;
    }
    grammar Declarator
    {
        InitDeclaratorList(var std::unique_ptr<InitDeclaratorList> idl): soulng::codedom::InitDeclaratorList*;
        InitDeclarator: soulng::codedom::InitDeclarator*;
        Declarator: std::u32string;
        DirectDeclarator(var std::unique_ptr<CppObject> o);
        DeclaratorId(var std::unique_ptr<CppObject> o);
        TypeId(var std::unique_ptr<TypeId> ti): soulng::codedom::TypeId*;
        Type(var std::unique_ptr<Type> t): soulng::codedom::Type*;
        TypeSpecifierSeq(soulng::codedom::TypeId* typeId);
        AbstractDeclarator: std::u32string;
        DirectAbstractDeclarator(var std::unique_ptr<CppObject> o);
        PtrOperator;
        CVQualifierSeq(var std::unique_ptr<CppObject> o);
        Initializer: soulng::codedom::Initializer*;
        InitializerClause: soulng::codedom::AssignInit*;
        InitializerList(soulng::codedom::AssignInit* init);
    }
    grammar Expression
    {
        Expression: soulng::codedom::CppObject*;
        ConstantExpression: soulng::codedom::CppObject*;
        AssignmentExpression(var std::unique_ptr<CppObject> lor): soulng::codedom::CppObject*;
        AssingmentOp: Operator;
        ThrowExpression: soulng::codedom::CppObject*;
        ConditionalExpression: soulng::codedom::CppObject*;
        LogicalOrExpression: soulng::codedom::CppObject*;
        LogicalAndExpression: soulng::codedom::CppObject*;
        InclusiveOrExpression: soulng::codedom::CppObject*;
        ExclusiveOrExpression: soulng::codedom::CppObject*;
        AndExpression: soulng::codedom::CppObject*;
        EqualityExpression: soulng::codedom::CppObject*;
        EqOp: Operator;
        RelationalExpression: soulng::codedom::CppObject*;
        RelOp: Operator;
        ShiftExpression: soulng::codedom::CppObject*;
        ShiftOp: Operator;
        AdditiveExpression: soulng::codedom::CppObject*;
        AddOp: Operator;
        MultiplicativeExpression: soulng::codedom::CppObject*;
        MulOp: Operator;
        PmExpression: soulng::codedom::CppObject*;
        PmOp: Operator;
        CastExpression(var std::unique_ptr<CppObject> ce, var std::unique_ptr<CppObject> ti): soulng::codedom::CppObject*;
        UnaryExpression(var std::unique_ptr<CppObject> ue): soulng::codedom::CppObject*;
        UnaryOperator: Operator;
        NewExpression(var bool global, var TypeId* typeId, var bool parens): soulng::codedom::CppObject*;
        NewTypeId(var std::unique_ptr<TypeId> ti): soulng::codedom::TypeId*;
        NewDeclarator: std::u32string;
        DirectNewDeclarator(var std::unique_ptr<CppObject> e);
        NewPlacement: std::vector<soulng::codedom::CppObject*>;
        NewInitializer: std::vector<soulng::codedom::CppObject*>;
        DeleteExpression(var bool global, var bool array): soulng::codedom::CppObject*;
        PostfixExpression(var std::unique_ptr<CppObject> pe): soulng::codedom::CppObject*;
        TypeSpecifierOrTypeName: soulng::codedom::CppObject*;
        PostCastExpression: soulng::codedom::CppObject*;
        ExpressionList: std::vector<soulng::codedom::CppObject*>;
        PrimaryExpression(var std::unique_ptr<CppObject> pe): soulng::codedom::CppObject*;
        IdExpression: soulng::codedom::IdExpr*;
        OperatorFunctionId;
        Operator;
    }
    grammar Literal
    {
        Literal: soulng::codedom::Literal*;
        IntegerLiteral: soulng::codedom::Literal*;
        DecimalLiteral;
        OctalLiteral;
        OctalDigit;
        HexadecimalLiteral;
        IntegerSuffix;
        UnsignedSuffix;
        LongLongSuffix;
        LongSuffix;
        CharacterLiteral: soulng::codedom::Literal*;
        NarrowCharacterLiteral;
        UniversalCharacterLiteral;
        WideCharacterLiteral;
        CCharSequence: std::u32string;
        CChar;
        EscapeSequence;
        SimpleEscapeSequence;
        OctalEscapeSequence;
        HexadecimalEscapeSequence;
        FloatingLiteral: soulng::codedom::Literal*;
        FractionalConstant;
        DigitSequence;
        ExponentPart;
        Sign;
        FloatingSuffix;
        StringLiteral: soulng::codedom::Literal*;
        EncodingPrefix;
        SCharSequence;
        SChar;
        BooleanLiteral: soulng::codedom::Literal*;
        PointerLiteral: soulng::codedom::Literal*;
    }
    grammar Identifier
    {
        Identifier: std::u32string;
        QualifiedId: std::u32string;
    }
    grammar Keyword
    {
        Keyword;
    }
}
