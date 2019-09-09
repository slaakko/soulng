namespace soulng.syntax
{
    grammar Composite
    {
        Alternative(soulng::parsing::Scope* enclosingScope): soulng::parsing::Parser*;
        Sequence(soulng::parsing::Scope* enclosingScope): soulng::parsing::Parser*;
        Difference(soulng::parsing::Scope* enclosingScope): soulng::parsing::Parser*;
        ExclusiveOr(soulng::parsing::Scope* enclosingScope): soulng::parsing::Parser*;
        Intersection(soulng::parsing::Scope* enclosingScope): soulng::parsing::Parser*;
        List(soulng::parsing::Scope* enclosingScope): soulng::parsing::Parser*;
        Postfix(soulng::parsing::Scope* enclosingScope): soulng::parsing::Parser*;
    }
    grammar Rule
    {
        Rule(soulng::parsing::Scope* enclosingScope): soulng::parsing::Rule*;
        RuleHeader(soulng::parsing::Scope* enclosingScope): soulng::parsing::Rule*;
        RuleBody(soulng::parsing::Rule* rule);
    }
    grammar Element
    {
        RuleLink(soulng::parsing::Grammar* grammar);
        Signature(soulng::parsing::Rule* rule);
        ParameterList(soulng::parsing::Rule* rule);
        Variable(soulng::parsing::Rule* rule);
        Parameter(soulng::parsing::Rule* rule);
        ReturnType(soulng::parsing::Rule* rule);
        Keyword;
        Identifier: std::u32string;
        QualifiedId: std::u32string;
        StringArray(std::vector<std::u32string>* array);
    }
    grammar GrammarGrammar
    {
        Grammar(soulng::parsing::Scope* enclosingScope): soulng::parsing::Grammar*;
        GrammarContent(soulng::parsing::Grammar* grammar);
        StartClause(soulng::parsing::Grammar* grammar);
        SkipClause(soulng::parsing::Grammar* grammar);
    }
    grammar Primitive
    {
        Primitive: soulng::parsing::Parser*;
        Char: soulng::parsing::Parser*;
        String: soulng::parsing::Parser*;
        CharSet(var bool inverse, var std::u32string s): soulng::parsing::Parser*;
        CharSetRange: std::u32string;
        CharSetChar: char32_t;
        Keyword: soulng::parsing::Parser*;
        KeywordBody: soulng::parsing::Parser*;
        KeywordList: soulng::parsing::Parser*;
        KeywordListBody(var std::vector<std::u32string> keywords): soulng::parsing::Parser*;
        Range: soulng::parsing::Parser*;
        CodePoint: uint32_t;
        Empty: soulng::parsing::Parser*;
        Space: soulng::parsing::Parser*;
        AnyChar: soulng::parsing::Parser*;
        Letter: soulng::parsing::Parser*;
        Digit: soulng::parsing::Parser*;
        HexDigit: soulng::parsing::Parser*;
        UpperLetter: soulng::parsing::Parser*;
        LowerLetter: soulng::parsing::Parser*;
        TitleLetter: soulng::parsing::Parser*;
        ModifierLetter: soulng::parsing::Parser*;
        OtherLetter: soulng::parsing::Parser*;
        CasedLetter: soulng::parsing::Parser*;
        Mark: soulng::parsing::Parser*;
        NonspacingMark: soulng::parsing::Parser*;
        SpacingMark: soulng::parsing::Parser*;
        EnclosingMark: soulng::parsing::Parser*;
        Number: soulng::parsing::Parser*;
        DecimalNumber: soulng::parsing::Parser*;
        LetterNumber: soulng::parsing::Parser*;
        OtherNumber: soulng::parsing::Parser*;
        Punctuation: soulng::parsing::Parser*;
        ConnectorPunctuation: soulng::parsing::Parser*;
        DashPunctuation: soulng::parsing::Parser*;
        OpenPunctuation: soulng::parsing::Parser*;
        ClosePunctuation: soulng::parsing::Parser*;
        InitialPunctuation: soulng::parsing::Parser*;
        FinalPunctuation: soulng::parsing::Parser*;
        OtherPunctuation: soulng::parsing::Parser*;
        Symbol: soulng::parsing::Parser*;
        MathSymbol: soulng::parsing::Parser*;
        CurrencySymbol: soulng::parsing::Parser*;
        ModifierSymbol: soulng::parsing::Parser*;
        OtherSymbol: soulng::parsing::Parser*;
        Separator: soulng::parsing::Parser*;
        SpaceSeparator: soulng::parsing::Parser*;
        LineSeparator: soulng::parsing::Parser*;
        ParagraphSeparator: soulng::parsing::Parser*;
        Other: soulng::parsing::Parser*;
        Control: soulng::parsing::Parser*;
        Format: soulng::parsing::Parser*;
        Surrogate: soulng::parsing::Parser*;
        PrivateUse: soulng::parsing::Parser*;
        Unassigned: soulng::parsing::Parser*;
        Graphic: soulng::parsing::Parser*;
        BaseChar: soulng::parsing::Parser*;
        Alphabetic: soulng::parsing::Parser*;
        IdStart: soulng::parsing::Parser*;
        IdCont: soulng::parsing::Parser*;
    }
    grammar ParserFile
    {
        ParserFile(int id_, soulng::parsing::ParsingDomain* parsingDomain_): ParserFileContent*;
        IncludeDirectives(ParserFileContent* parserFileContent);
        IncludeDirective(ParserFileContent* parserFileContent);
        FileAttribute: std::u32string;
        IncludeFileName: std::u32string;
        NamespaceContent(ParserFileContent* parserFileContent);
        Namespace(ParserFileContent* parserFileContent);
    }
    grammar LibraryFile
    {
        LibraryFile(soulng::parsing::ParsingDomain* parsingDomain);
        NamespaceContent(soulng::parsing::ParsingDomain* parsingDomain);
        Namespace(soulng::parsing::ParsingDomain* parsingDomain);
        Grammar(soulng::parsing::Scope* enclosingScope): soulng::parsing::Grammar*;
        GrammarContent(soulng::parsing::Grammar* grammar);
        Rule(soulng::parsing::Scope* enclosingScope): soulng::parsing::Rule*;
    }
    grammar Primary
    {
        Primary(soulng::parsing::Scope* enclosingScope): soulng::parsing::Parser*;
        RuleCall: soulng::parsing::Parser*;
        Nonterminal: std::u32string;
        Alias: std::u32string;
        Grouping(soulng::parsing::Scope* enclosingScope): soulng::parsing::Parser*;
        Token(soulng::parsing::Scope* enclosingScope): soulng::parsing::Parser*;
        Expectation(soulng::parsing::Parser* child): soulng::parsing::Parser*;
        Action(soulng::parsing::Parser* child): soulng::parsing::Parser*;
    }
    grammar ProjectFile
    {
        ProjectFile: Project*;
        ProjectFileContent(Project* project);
        Source: std::u32string;
        Reference: std::u32string;
        FilePath: std::u32string;
    }
}
