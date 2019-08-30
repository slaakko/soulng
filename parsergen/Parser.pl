namespace soulng.parsergen
{
    grammar ParserFileGrammar
    {
        ParserFile: ParserFile*;
        Declaration(ParserFile* parserFile);
        IncludeDeclaration(var std::u32string include): Include*;
        IncludePrefix: bool;
        UsingNamespaceDeclaration: std::u32string;
        GrammarDeclaration: soulng::parsergen::GrammarParser*;
        GrammarStatement(soulng::parsergen::GrammarParser* grammar);
        MainStatement(soulng::parsergen::GrammarParser* grammar);
        UsingStatement(soulng::parsergen::GrammarParser* grammar);
        LexerStatement(soulng::parsergen::GrammarParser* grammar);
        RuleInfoStatement(soulng::parsergen::GrammarParser* grammar);
        RuleInfo(soulng::parsergen::GrammarParser* grammar);
        RuleStatement(soulng::parsergen::GrammarParser* grammar);
        RuleBody: soulng::parsergen::Parser*;
        Alternative: soulng::parsergen::Parser*;
        Sequence: soulng::parsergen::Parser*;
        Difference: soulng::parsergen::Parser*;
        List: soulng::parsergen::Parser*;
        Postfix: soulng::parsergen::Parser*;
        Primary: soulng::parsergen::Parser*;
        RuleCall: soulng::parsergen::Parser*;
        Primitive: soulng::parsergen::Parser*;
        Grouping: soulng::parsergen::Parser*;
        Expectation(soulng::parsergen::Parser* parser): soulng::parsergen::Parser*;
        Action(soulng::parsergen::Parser* parser): soulng::parsergen::Parser*;
        Nonterminal: std::u32string;
        ParameterList: std::vector<soulng::parsergen::Parameter*>;
        Parameter: soulng::parsergen::Parameter*;
        ReturnType: soulng::codedom::TypeId*;
        Keyword;
        Identifier: std::u32string;
        UsingQualifiedId: std::u32string;
    }
    grammar ProjectFileGrammar
    {
        ProjectFile: ProjectFile*;
        ProjectFileContent(ProjectFile* projectFile);
        SourceFile(ProjectFile* projectFile);
        FilePath: std::u32string;
    }
}
