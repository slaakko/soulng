namespace soulng.lexergen
{
    grammar LexerGrammar
    {
        LexerFile: LexerFile*;
        Declaration: Declaration*;
        ClassMap: ClassMap*;
        Prefix: Prefix*;
        Include: Include*;
        Tokens: Tokens*;
        Token: Token;
        Keywords: Keywords*;
        Keyword: Keyword*;
        Expressions(var int index): Expressions*;
        Expression(int index): Expression*;
        Expr: std::u32string;
        Variable: Variable*;
        Lexer: Lexer*;
        LexerClause(Lexer* lexer);
        Variables(Lexer* lexer);
        Identifier: std::u32string;
        Api: std::u32string;
        LexerKeyword;
        Actions(Lexer* lexer);
        Action: int;
    }
    grammar RegExGrammar
    {
        RegEx(LexerContext* lexerContext): Nfa;
        Alternative(LexerContext* lexerContext): Nfa;
        Catenation(LexerContext* lexerContext): Nfa;
        Repetition(LexerContext* lexerContext): Nfa;
        Primary(LexerContext* lexerContext): Nfa;
        Class(LexerContext* lexerContext): Class*;
        Range(LexerContext* lexerContext): Symbol*;
        Char: char32_t;
        Escape: char32_t;
    }
}
