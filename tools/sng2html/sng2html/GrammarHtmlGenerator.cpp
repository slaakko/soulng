// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/GrammarHtmlGenerator.hpp>
#include <sng2html/sng2html/Domain.hpp>
#include <sng2html/sng2html/Symbol.hpp>
#include <sng2html/sng2html/RegEx.hpp>
#include <sngxml/dom/Document.hpp>
#include <sngxml/dom/Element.hpp>
#include <sngxml/dom/CharacterData.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/TextUtils.hpp>
#include <fstream>
#include <iostream>

namespace sng2html { namespace sng2html {

using namespace soulng::util;
using namespace soulng::unicode;

void AppendRuleName(sngxml::dom::Element* parent, const std::u32string& name)
{
    for (char32_t c : name)
    {
        switch (c)
        {
            case '-': parent->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::EntityReference(U"#8209"))); break;
            default: parent->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(std::u32string(1, c))));
        }
    }
}

GrammarHtmlGeneratorVisitor::GrammarHtmlGeneratorVisitor(bool verbose_, std::unordered_map<GrammarParser*, Grammar*>& parserGrammarMap_, std::unordered_map<RuleParser*, Rule*>& parserRuleMap_,
    std::unordered_map<LexerFile*, Grammar*>& lexerGrammarMap_, std::unordered_map<Expression*, Rule*>& lexerRuleMap_, 
    std::unordered_map<std::u32string, LexerFile*>& lexerMap_, const std::u32string& styleFilePath_) :
    verbose(verbose_), parserGrammarMap(parserGrammarMap_), parserRuleMap(parserRuleMap_),
    lexerGrammarMap(lexerGrammarMap_), lexerRuleMap(lexerRuleMap_),
    lexerMap(lexerMap_), styleFilePath(styleFilePath_), ruleTable(nullptr), ruleBodyElement(nullptr), currentGrammar(nullptr),
    lexerFile(nullptr)
{
}

void GrammarHtmlGeneratorVisitor::Visit(Char& symbol)
{
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleChar");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(CharStr(symbol.Chr()))));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(Any& symbol)
{
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U".")));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(Range& symbol)
{
    if (symbol.Start() == symbol.End())
    {
        std::unique_ptr<sngxml::dom::Element> startSpanElement(new sngxml::dom::Element(U"span"));
        startSpanElement->SetAttribute(U"class", U"ruleCharSet");
        startSpanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(CharStr(symbol.Start()))));
        ruleBodyElement->AppendChild(std::move(startSpanElement));
    }
    else
    {
        std::unique_ptr<sngxml::dom::Element> startSpanElement(new sngxml::dom::Element(U"span"));
        startSpanElement->SetAttribute(U"class", U"ruleCharSet");
        startSpanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(CharStr(symbol.Start()))));
        ruleBodyElement->AppendChild(std::move(startSpanElement));
        std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
        spanElement->SetAttribute(U"class", U"ruleOp");
        spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::EntityReference(U"#8209")));
        ruleBodyElement->AppendChild(std::move(spanElement));
        std::unique_ptr<sngxml::dom::Element> endSpanElement(new sngxml::dom::Element(U"span"));
        endSpanElement->SetAttribute(U"class", U"ruleCharSet");
        endSpanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(CharStr(symbol.End()))));
        ruleBodyElement->AppendChild(std::move(endSpanElement));
    }
}

void GrammarHtmlGeneratorVisitor::Visit(Class& symbol)
{
    std::unique_ptr<sngxml::dom::Element> leftSpanElement(new sngxml::dom::Element(U"span"));
    leftSpanElement->SetAttribute(U"class", U"ruleOp");
    leftSpanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"[")));
    if (symbol.Inverse())
    {
        leftSpanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"^")));
    }
    ruleBodyElement->AppendChild(std::move(leftSpanElement));
    for (const auto& symbol : symbol.Symbols())
    {
        symbol->Accept(*this);
    }
    std::unique_ptr<sngxml::dom::Element> rightSpanElement(new sngxml::dom::Element(U"span"));
    rightSpanElement->SetAttribute(U"class", U"ruleOp");
    rightSpanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"]")));
    ruleBodyElement->AppendChild(std::move(rightSpanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(Alt& alt)
{
    alt.Left()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" | ")));
    ruleBodyElement->AppendChild(std::move(spanElement));
    alt.Right()->Accept(*this);
}

void GrammarHtmlGeneratorVisitor::Visit(Cat& cat)
{
    bool chars = cat.Left()->IsCharSymbolExpr() && cat.Right()->IsCharSymbolExpr();
    cat.Left()->Accept(*this);
    if (!chars)
    {
        std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
        spanElement->SetAttribute(U"class", U"ruleOp");
        spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" ")));
        ruleBodyElement->AppendChild(std::move(spanElement));
    }
    cat.Right()->Accept(*this);
}

void GrammarHtmlGeneratorVisitor::Visit(Kleene& kleene)
{
    kleene.Child()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"*")));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(Pos& pos)
{
    pos.Child()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"+")));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(Opt& opt)
{
    opt.Child()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"?")));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(ParenExpr& parenExpr)
{
    std::unique_ptr<sngxml::dom::Element> leftSpanElement(new sngxml::dom::Element(U"span"));
    leftSpanElement->SetAttribute(U"class", U"ruleOp");
    leftSpanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"(")));
    ruleBodyElement->AppendChild(std::move(leftSpanElement));
    parenExpr.Child()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> rightSpanElement(new sngxml::dom::Element(U"span"));
    rightSpanElement->SetAttribute(U"class", U"ruleOp");
    rightSpanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U")")));
    ruleBodyElement->AppendChild(std::move(rightSpanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(SymbolExpr& symbolExpr)
{
    symbolExpr.GetSymbol()->Accept(*this);
}

void GrammarHtmlGeneratorVisitor::Visit(RefExpr& refExpr)
{
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"lexerRule");
    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
    linkElement->SetAttribute(U"class", U"lexerRule");
    std::u32string linkText;
    auto grammarIt = lexerGrammarMap.find(lexerFile);
    if (grammarIt != lexerGrammarMap.cend())
    {
        Grammar* grammar = grammarIt->second;
        linkText.append(grammar->HtmlFileName());
    }
    else
    {
        throw std::runtime_error("lexical grammar not found");
    }
    Expression* expression = lexerFile->GetExpressions()->Get(refExpr.ExprId());
    Rule* rule = nullptr;
    auto ruleIt = lexerRuleMap.find(expression);
    if (ruleIt != lexerRuleMap.cend())
    {
        rule = ruleIt->second;
        linkText.append(U"#").append(rule->Name());
    }
    else
    {
        throw std::runtime_error("lexical rule not found");
    }
    linkElement->SetAttribute(U"href", linkText);
    AppendRuleName(linkElement.get(), rule->Name());
    spanElement->AppendChild(std::move(linkElement));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(EmptyParser& parser)
{
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"<empty>")));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(TokenParser& parser)
{
    std::u32string keyword;
    if (lexerFile)
    {
        Keywords* keywords = lexerFile->GetKeywords();
        if (keywords)
        {
            keyword = keywords->GetKeyword(parser.TokenName());
        }
    }
    if (!keyword.empty())
    {
        std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
        spanElement->SetAttribute(U"class", U"ruleKeyword");
        spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(keyword)));
        ruleBodyElement->AppendChild(std::move(spanElement));
    }
    else
    {
        RegExpression* regEx = nullptr;
        if (lexerFile)
        {
            LexerStatement* statement = lexerFile->GetLexer()->GetStatement(parser.TokenName());
            if (statement)
            {
                regEx = statement->RegEx();
            }
        }
        if (regEx)
        {
            regEx->Accept(*this);
        }
        else
        {
            std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
            spanElement->SetAttribute(U"class", U"ruleString");
            spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(parser.TokenName())));
            ruleBodyElement->AppendChild(std::move(spanElement));
        }
    }
}

void GrammarHtmlGeneratorVisitor::Visit(CharParser& parser)
{
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleChar");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(CharStr(parser.Chr()))));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(StringParser& parser)
{
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleString");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(StringStr(parser.Str()))));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(CharSetParser& parser)
{
    std::u32string text = U"[";
    if (parser.Set().Inverse())
    {
        text.append(U"^");
    }
    for (const auto& range : parser.Set().Ranges())
    {
        text.append(CharStr(static_cast<char32_t>(range.first)));
        if (range.last != range.first)
        {
            text.append(1, '-').append(CharStr(static_cast<char32_t>(range.last)));
        }
    }
    text.append(1, ']');
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleCharSet");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(text)));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(OptionalParser& parser)
{
    parser.Child()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"?")));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(KleeneParser& parser)
{
    parser.Child()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"*")));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(PositiveParser& parser)
{
    parser.Child()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"+")));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(ExpectationParser& parser)
{
    parser.Child()->Accept(*this);
}

void GrammarHtmlGeneratorVisitor::Visit(GroupingParser& parser)
{
    if (!parser.Parent() || parser.Parent()->IsAction() || ((parser.Parent()->IsPostfix() || parser.ParentIsList()) && parser.Child()->IsAction()))
    {
        parser.Child()->Accept(*this);
    }
    else
    {
        std::unique_ptr<sngxml::dom::Element> leftSpanElement(new sngxml::dom::Element(U"span"));
        leftSpanElement->SetAttribute(U"class", U"ruleOp");
        leftSpanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U"(")));
        ruleBodyElement->AppendChild(std::move(leftSpanElement));
        parser.Child()->Accept(*this);
        std::unique_ptr<sngxml::dom::Element> rightSpanElement(new sngxml::dom::Element(U"span"));
        rightSpanElement->SetAttribute(U"class", U"ruleOp");
        rightSpanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U")")));
        ruleBodyElement->AppendChild(std::move(rightSpanElement));
    }
}

void GrammarHtmlGeneratorVisitor::Visit(SequenceParser& parser)
{
    if (parser.Left()->IsEmptyOrEmptyActionParser())
    {
        if (!parser.Right()->IsEmptyOrEmptyActionParser())
        {
            parser.Right()->Accept(*this);
        }
    }
    else if (parser.Right()->IsEmptyOrEmptyActionParser())
    {
        if (!parser.Left()->IsEmptyOrEmptyActionParser())
        {
            parser.Left()->Accept(*this);
        }
    }
    else
    {
        parser.Left()->Accept(*this);
        std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
        spanElement->SetAttribute(U"class", U"ruleOp");
        spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" ")));
        ruleBodyElement->AppendChild(std::move(spanElement));
        parser.Right()->Accept(*this);
    }
}

void GrammarHtmlGeneratorVisitor::Visit(AlternativeParser& parser)
{
    parser.Left()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" | ")));
    ruleBodyElement->AppendChild(std::move(spanElement));
    parser.Right()->Accept(*this);
}

void GrammarHtmlGeneratorVisitor::Visit(DifferenceParser& parser)
{
    parser.Left()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" ")));
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::EntityReference(U"minus")));
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" ")));
    ruleBodyElement->AppendChild(std::move(spanElement));
    parser.Right()->Accept(*this);
}

void GrammarHtmlGeneratorVisitor::Visit(ListParser& parser)
{
    parser.Left()->Accept(*this);
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleOp");
    spanElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(U" % ")));
    ruleBodyElement->AppendChild(std::move(spanElement));
    parser.Right()->Accept(*this);
}

void GrammarHtmlGeneratorVisitor::Visit(ActionParser& parser)
{
    parser.Child()->Accept(*this);
}

void GrammarHtmlGeneratorVisitor::Visit(NonterminalParser& parser)
{
    std::unique_ptr<sngxml::dom::Element> spanElement(new sngxml::dom::Element(U"span"));
    spanElement->SetAttribute(U"class", U"ruleLink");
    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"a"));
    linkElement->SetAttribute(U"class", U"ruleLink");
    RuleParser* ruleParser = parser.Rule();
    GrammarParser* grammarParser = ruleParser->GetGrammar();
    Rule* rule = GetRule(ruleParser);
    std::u32string linkText;
    if (grammarParser == currentGrammar)
    {
        linkText.append(U"#").append(rule->Name());
    }
    else
    {
        Grammar* grammar = GetGrammar(grammarParser);
        linkText.append(grammar->HtmlFileName()).append(U"#").append(rule->Name());
    }
    linkElement->SetAttribute(U"href", linkText);
    AppendRuleName(linkElement.get(), rule->Name());
    spanElement->AppendChild(std::move(linkElement));
    ruleBodyElement->AppendChild(std::move(spanElement));
}

void GrammarHtmlGeneratorVisitor::Visit(RuleParser& parser)
{
    std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
    Rule* rule = GetRule(&parser);
    trElement->SetAttribute(U"id", rule->Name());
    std::unique_ptr<sngxml::dom::Element> tdNameElement(new sngxml::dom::Element(U"td"));
    tdNameElement->SetAttribute(U"class", U"grammarFirstCol");
    std::unique_ptr<sngxml::dom::Element> ruleSpanElement(new sngxml::dom::Element(U"span"));
    ruleSpanElement->SetAttribute(U"class", U"rule");
    AppendRuleName(ruleSpanElement.get(), rule->Name());
    tdNameElement->AppendChild(std::move(ruleSpanElement));
    trElement->AppendChild(std::move(tdNameElement));
    std::unique_ptr<sngxml::dom::Element> tdArrowElement(new sngxml::dom::Element(U"td"));
    tdArrowElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::EntityReference(U"rarr")));
    tdArrowElement->SetAttribute(U"class", U"grammarSecondCol");
    trElement->AppendChild(std::move(tdArrowElement));
    std::unique_ptr<sngxml::dom::Element> tdRuleBodyElement(new sngxml::dom::Element(U"td"));
    tdRuleBodyElement->SetAttribute(U"class", U"grammarThirdCol");
    tdRuleBodyElement->SetAttribute(U"xml:space", U"preserve");
    ruleBodyElement = tdRuleBodyElement.get();
    parser.Definition()->Accept(*this);
    trElement->AppendChild(std::move(tdRuleBodyElement));
    ruleTable->AppendChild(std::move(trElement));
}

void GrammarHtmlGeneratorVisitor::Visit(GrammarParser& parser)
{
    Grammar* grammar = GetGrammar(&parser);
    GrammarParser* prevGrammar = currentGrammar;
    currentGrammar = &parser;
    LexerFile* prevLexerFile = lexerFile;
    auto it = lexerMap.find(parser.Lexer());
    if (it != lexerMap.cend())
    {
        lexerFile = it->second;
    }
    std::unique_ptr<sngxml::dom::Document> grammarDoc(new sngxml::dom::Document());
    std::unique_ptr<sngxml::dom::Element> htmlElement(new sngxml::dom::Element(U"html"));
    std::unique_ptr<sngxml::dom::Element> headElement(new sngxml::dom::Element(U"head"));
    std::unique_ptr<sngxml::dom::Element> metaElement(new sngxml::dom::Element(U"meta"));
    metaElement->SetAttribute(U"charset", U"utf-8");
    headElement->AppendChild(std::move(metaElement));
    std::unique_ptr<sngxml::dom::Element> titleElement(new sngxml::dom::Element(U"title"));
    titleElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(grammar->Title())));
    headElement->AppendChild(std::move(titleElement));
    std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"link"));
    linkElement->SetAttribute(U"rel", U"stylesheet");
    linkElement->SetAttribute(U"type", U"text/css");
    linkElement->SetAttribute(U"href", styleFilePath);
    headElement->AppendChild(std::move(linkElement));
    htmlElement->AppendChild(std::move(headElement));
    std::unique_ptr<sngxml::dom::Element> bodyElement(new sngxml::dom::Element(U"body"));
    std::unique_ptr<sngxml::dom::Element> headerElement(new sngxml::dom::Element(U"h1"));
    headerElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(grammar->Title())));
    bodyElement->AppendChild(std::move(headerElement));
    std::unique_ptr<sngxml::dom::Element> tableElement(new sngxml::dom::Element(U"table"));
    tableElement->SetAttribute(U"class", U"grammar");
    ruleTable = tableElement.get();
    int n = parser.Rules().size();
    for (int i = 0; i < n; ++i)
    {
        parser.Rules()[i]->Accept(*this);
    }
    bodyElement->AppendChild(std::move(tableElement));
    htmlElement->AppendChild(std::move(bodyElement));
    grammarDoc->AppendChild(std::move(htmlElement));
    std::ofstream htmlFile(grammar->HtmlFilePath());
    CodeFormatter formatter(htmlFile);
    formatter.SetIndentSize(1);
    grammarDoc->Write(formatter);
    currentGrammar = prevGrammar;
    lexerFile = prevLexerFile;
    if (verbose)
    {
        std::cout << "==> " << grammar->HtmlFilePath() << std::endl;
    }
}

void GrammarHtmlGeneratorVisitor::Visit(ParserFile& parserFile)
{
    for (const auto& grammar : parserFile.Parsers())
    {
        grammar->Accept(*this);
    }
}

void GrammarHtmlGeneratorVisitor::Visit(Domain& domain)
{
    for (const auto& parserFile : domain.ParserFiles())
    {
        parserFile->Accept(*this);
    }
}

void GrammarHtmlGeneratorVisitor::Visit(LexerFile& lexerFile)
{
    this->lexerFile = &lexerFile;
    auto it = lexerGrammarMap.find(this->lexerFile);
    if (it != lexerGrammarMap.cend())
    {
        Grammar* grammar = it->second;
        std::unique_ptr<sngxml::dom::Document> grammarDoc(new sngxml::dom::Document());
        std::unique_ptr<sngxml::dom::Element> htmlElement(new sngxml::dom::Element(U"html"));
        std::unique_ptr<sngxml::dom::Element> headElement(new sngxml::dom::Element(U"head"));
        std::unique_ptr<sngxml::dom::Element> metaElement(new sngxml::dom::Element(U"meta"));
        metaElement->SetAttribute(U"charset", U"utf-8");
        headElement->AppendChild(std::move(metaElement));
        std::unique_ptr<sngxml::dom::Element> titleElement(new sngxml::dom::Element(U"title"));
        titleElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(grammar->Title())));
        headElement->AppendChild(std::move(titleElement));
        std::unique_ptr<sngxml::dom::Element> linkElement(new sngxml::dom::Element(U"link"));
        linkElement->SetAttribute(U"rel", U"stylesheet");
        linkElement->SetAttribute(U"type", U"text/css");
        linkElement->SetAttribute(U"href", styleFilePath);
        headElement->AppendChild(std::move(linkElement));
        htmlElement->AppendChild(std::move(headElement));
        std::unique_ptr<sngxml::dom::Element> bodyElement(new sngxml::dom::Element(U"body"));
        std::unique_ptr<sngxml::dom::Element> headerElement(new sngxml::dom::Element(U"h1"));
        headerElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::Text(grammar->Title())));
        bodyElement->AppendChild(std::move(headerElement));
        std::unique_ptr<sngxml::dom::Element> tableElement(new sngxml::dom::Element(U"table"));
        tableElement->SetAttribute(U"class", U"grammar");
        ruleTable = tableElement.get();
        int n = grammar->Rules().size();
        for (int i = 0; i < n; ++i)
        {
            Rule* rule = grammar->Rules()[i].get();
            std::unique_ptr<sngxml::dom::Element> trElement(new sngxml::dom::Element(U"tr"));
            trElement->SetAttribute(U"id", rule->Name());
            std::unique_ptr<sngxml::dom::Element> tdNameElement(new sngxml::dom::Element(U"td"));
            tdNameElement->SetAttribute(U"class", U"grammarFirstCol");
            std::unique_ptr<sngxml::dom::Element> ruleSpanElement(new sngxml::dom::Element(U"span"));
            ruleSpanElement->SetAttribute(U"class", U"rule");
            AppendRuleName(ruleSpanElement.get(), rule->Name());
            tdNameElement->AppendChild(std::move(ruleSpanElement));
            trElement->AppendChild(std::move(tdNameElement));
            std::unique_ptr<sngxml::dom::Element> tdArrowElement(new sngxml::dom::Element(U"td"));
            tdArrowElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(new sngxml::dom::EntityReference(U"rarr")));
            tdArrowElement->SetAttribute(U"class", U"grammarSecondCol");
            trElement->AppendChild(std::move(tdArrowElement));
            std::unique_ptr<sngxml::dom::Element> tdRuleBodyElement(new sngxml::dom::Element(U"td"));
            tdRuleBodyElement->SetAttribute(U"class", U"grammarThirdCol");
            tdRuleBodyElement->SetAttribute(U"xml:space", U"preserve");
            ruleBodyElement = tdRuleBodyElement.get();
            rule->GetExpression()->RegEx()->Accept(*this);
            trElement->AppendChild(std::move(tdRuleBodyElement));
            ruleTable->AppendChild(std::move(trElement));
        }
        bodyElement->AppendChild(std::move(tableElement));
        htmlElement->AppendChild(std::move(bodyElement));
        grammarDoc->AppendChild(std::move(htmlElement));
        std::ofstream htmlFile(grammar->HtmlFilePath());
        CodeFormatter formatter(htmlFile);
        formatter.SetIndentSize(1);
        grammarDoc->Write(formatter);
        if (verbose)
        {
            std::cout << "==> " << grammar->HtmlFilePath() << std::endl;
        }

    }
    else
    {
        throw std::runtime_error("lexical grammar not found");
    }
}

Grammar* GrammarHtmlGeneratorVisitor::GetGrammar(GrammarParser* parser) const
{
    auto it = parserGrammarMap.find(parser);
    if (it != parserGrammarMap.cend())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("grammar for parser '" + ToUtf8(parser->Name()) + "' not found");
    }
}

Rule* GrammarHtmlGeneratorVisitor::GetRule(RuleParser* parser) const
{
    auto it = parserRuleMap.find(parser);
    if (it != parserRuleMap.cend())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("rule for parser '" + ToUtf8(parser->Name()) + "' not found");
    }
}

} } // namespace sng2html::sng2html
