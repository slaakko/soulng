namespace soulng.code
{
    grammar Declaration
    {
        BlockDeclaration: soulng::cppcode::CppObject*;
        SimpleDeclaration(var std::unique_ptr<SimpleDeclaration> sd): soulng::cppcode::SimpleDeclaration*;
        DeclSpecifierSeq(soulng::cppcode::SimpleDeclaration* declaration);
        DeclSpecifier: soulng::cppcode::DeclSpecifier*;
        StorageClassSpecifier: soulng::cppcode::StorageClassSpecifier*;
        TypeSpecifier: soulng::cppcode::TypeSpecifier*;
        SimpleTypeSpecifier: soulng::cppcode::TypeSpecifier*;
        TypeName: soulng::cppcode::TypeName*;
        TemplateArgumentList(soulng::cppcode::TypeName* typeName);
        TemplateArgument: soulng::cppcode::CppObject*;
        Typedef: soulng::cppcode::DeclSpecifier*;
        CVQualifier: soulng::cppcode::TypeSpecifier*;
        NamespaceAliasDefinition: soulng::cppcode::UsingObject*;
        UsingDeclaration: soulng::cppcode::UsingObject*;
        UsingDirective: soulng::cppcode::UsingObject*;
    }
    grammar Statement
    {
        Statement: soulng::cppcode::Statement*;
        LabeledStatement: soulng::cppcode::Statement*;
        Label: std::u32string;
        EmptyStatement: soulng::cppcode::Statement*;
        ExpressionStatement: soulng::cppcode::Statement*;
        CompoundStatement(var std::unique_ptr<CompoundStatement> cs): soulng::cppcode::CompoundStatement*;
        SelectionStatement: soulng::cppcode::Statement*;
        IfStatement: soulng::cppcode::Statement*;
        SwitchStatement: soulng::cppcode::Statement*;
        IterationStatement: soulng::cppcode::Statement*;
        WhileStatement: soulng::cppcode::Statement*;
        DoStatement: soulng::cppcode::Statement*;
        ForStatement: soulng::cppcode::Statement*;
        ForInitStatement: soulng::cppcode::CppObject*;
        JumpStatement: soulng::cppcode::Statement*;
        BreakStatement: soulng::cppcode::Statement*;
        ContinueStatement: soulng::cppcode::Statement*;
        ReturnStatement: soulng::cppcode::Statement*;
        GotoStatement: soulng::cppcode::Statement*;
        GotoTarget: std::u32string;
        DeclarationStatement: soulng::cppcode::Statement*;
        Condition(var std::unique_ptr<TypeId> ti): soulng::cppcode::CppObject*;
        TryStatement: soulng::cppcode::TryStatement*;
        HandlerSeq(TryStatement* st);
        Handler: soulng::cppcode::Handler*;
        ExceptionDeclaration(var std::unique_ptr<ExceptionDeclaration> ed): soulng::cppcode::ExceptionDeclaration*;
    }
    grammar Declarator
    {
        InitDeclaratorList(var std::unique_ptr<InitDeclaratorList> idl): soulng::cppcode::InitDeclaratorList*;
        InitDeclarator: soulng::cppcode::InitDeclarator*;
        Declarator: std::u32string;
        DirectDeclarator(var std::unique_ptr<CppObject> o);
        DeclaratorId(var std::unique_ptr<CppObject> o);
        TypeId(var std::unique_ptr<TypeId> ti): soulng::cppcode::TypeId*;
        Type(var std::unique_ptr<Type> t): soulng::cppcode::Type*;
        TypeSpecifierSeq(soulng::cppcode::TypeId* typeId);
        AbstractDeclarator: std::u32string;
        DirectAbstractDeclarator(var std::unique_ptr<CppObject> o);
        PtrOperator;
        CVQualifierSeq(var std::unique_ptr<CppObject> o);
        Initializer: soulng::cppcode::Initializer*;
        InitializerClause: soulng::cppcode::AssignInit*;
        InitializerList(soulng::cppcode::AssignInit* init);
    }
    grammar Expression
    {
        Expression: soulng::cppcode::CppObject*;
        ConstantExpression: soulng::cppcode::CppObject*;
        AssignmentExpression(var std::unique_ptr<CppObject> lor): soulng::cppcode::CppObject*;
        AssingmentOp: Operator;
        ThrowExpression: soulng::cppcode::CppObject*;
        ConditionalExpression: soulng::cppcode::CppObject*;
        LogicalOrExpression: soulng::cppcode::CppObject*;
        LogicalAndExpression: soulng::cppcode::CppObject*;
        InclusiveOrExpression: soulng::cppcode::CppObject*;
        ExclusiveOrExpression: soulng::cppcode::CppObject*;
        AndExpression: soulng::cppcode::CppObject*;
        EqualityExpression: soulng::cppcode::CppObject*;
        EqOp: Operator;
        RelationalExpression: soulng::cppcode::CppObject*;
        RelOp: Operator;
        ShiftExpression: soulng::cppcode::CppObject*;
        ShiftOp: Operator;
        AdditiveExpression: soulng::cppcode::CppObject*;
        AddOp: Operator;
        MultiplicativeExpression: soulng::cppcode::CppObject*;
        MulOp: Operator;
        PmExpression: soulng::cppcode::CppObject*;
        PmOp: Operator;
        CastExpression(var std::unique_ptr<CppObject> ce, var std::unique_ptr<CppObject> ti): soulng::cppcode::CppObject*;
        UnaryExpression(var std::unique_ptr<CppObject> ue): soulng::cppcode::CppObject*;
        UnaryOperator: Operator;
        NewExpression(var bool global, var TypeId* typeId, var bool parens): soulng::cppcode::NewExpr*;
        NewTypeId(var std::unique_ptr<TypeId> ti): soulng::cppcode::TypeId*;
        NewDeclarator: std::u32string;
        DirectNewDeclarator(var std::unique_ptr<CppObject> e);
        NewPlacement(soulng::cppcode::CppObject* owner);
        NewInitializer(soulng::cppcode::CppObject* owner);
        DeleteExpression(var bool global, var bool array): soulng::cppcode::CppObject*;
        PostfixExpression(var std::unique_ptr<CppObject> pe): soulng::cppcode::CppObject*;
        TypeSpecifierOrTypeName: soulng::cppcode::CppObject*;
        PostCastExpression: soulng::cppcode::CppObject*;
        ExpressionList(soulng::cppcode::CppObject* owner);
        PrimaryExpression(var std::unique_ptr<CppObject> pe): soulng::cppcode::CppObject*;
        IdExpression: soulng::cppcode::IdExpr*;
        OperatorFunctionId;
        Operator;
    }
    grammar Literal
    {
        Literal: soulng::cppcode::Literal*;
        IntegerLiteral: soulng::cppcode::Literal*;
        DecimalLiteral;
        OctalLiteral;
        OctalDigit;
        HexadecimalLiteral;
        IntegerSuffix;
        UnsignedSuffix;
        LongLongSuffix;
        LongSuffix;
        CharacterLiteral: soulng::cppcode::Literal*;
        NarrowCharacterLiteral;
        UniversalCharacterLiteral;
        WideCharacterLiteral;
        CCharSequence: std::u32string;
        CChar;
        EscapeSequence;
        SimpleEscapeSequence;
        OctalEscapeSequence;
        HexadecimalEscapeSequence;
        FloatingLiteral: soulng::cppcode::Literal*;
        FractionalConstant;
        DigitSequence;
        ExponentPart;
        Sign;
        FloatingSuffix;
        StringLiteral: soulng::cppcode::Literal*;
        EncodingPrefix;
        SCharSequence;
        SChar;
        BooleanLiteral: soulng::cppcode::Literal*;
        PointerLiteral: soulng::cppcode::Literal*;
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
