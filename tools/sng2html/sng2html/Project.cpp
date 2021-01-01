// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sng2html/sng2html/Project.hpp>
#include <sng2html/sng2html/LinkerVisitor.hpp>
#include <sng2html/sng2html/GrammarHtmlGenerator.hpp>
#include <sngxml/xpath/XPathEvaluate.hpp>
#include <sngxml/dom/Element.hpp>
#include <soulng/util/Path.hpp>
#include <soulng/util/Unicode.hpp>
#include <sng2html/sng2html/LexerFileLexer.hpp>
#include <sng2html/sng2html/LexerFileParser.hpp>
#include <sng2html/sng2html/ParserFileLexer.hpp>
#include <sng2html/sng2html/ParserFileParser.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

namespace sng2html { namespace sng2html {

using namespace soulng::unicode;

Project::Project(bool verbose_, const std::string& xmlFilePath_) :
    verbose(verbose_), xmlFilePath(xmlFilePath_), rootDir(Path::GetDirectoryName(GetFullPath(xmlFilePath))), xmlDoc(sngxml::dom::ReadDocument(xmlFilePath)),
    lexerContext(IdentifierClassKind::unicode)
{
}

void Project::Process()
{
    ReadLexerFiles();
    ReadParserFiles();
    ReadOutDir();
    ReadStyleFilePath();
    Link();
    ParseLexerFiles();
    ReadGrammarFiles();
    GenerateHtml();
}

void Project::ReadLexerFiles()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/lexer", xmlDoc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string fileAttribute = element->GetAttribute(U"file");
                    if (!fileAttribute.empty())
                    {
                        std::string lexerFilePath = GetFullPath(Path::Combine(rootDir, Path::MakeCanonical(ToUtf8(fileAttribute))));
                        if (verbose)
                        {
                            std::cout << "> " << lexerFilePath << std::endl;
                        }
                        LexerFileLexer lexerFileLexer(ToUtf32(ReadFile(lexerFilePath)), lexerFilePath, 0);
                        std::unique_ptr<LexerFile> lexerFile = LexerFileParser::Parse(lexerFileLexer);
                        lexerMap[lexerFile->GetLexer()->Name()] = lexerFile.get();
                        lexerFiles.push_back(std::move(lexerFile));
                    }
                }
            }
        }
    }
}

void Project::ReadParserFiles()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/parser", xmlDoc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string fileAttribute = element->GetAttribute(U"file");
                    if (!fileAttribute.empty())
                    {
                        std::string parserFilePath = GetFullPath(Path::Combine(rootDir, Path::MakeCanonical(ToUtf8(fileAttribute))));
                        if (verbose)
                        {
                            std::cout << "> " << parserFilePath << std::endl;
                        }
                        ParserFileLexer parserFileLexer(ToUtf32(ReadFile(parserFilePath)), parserFilePath, 0);
                        std::unique_ptr<ParserFile> parserFile = ParserFileParser::Parse(parserFileLexer);
                        domain.AddParserFile(parserFile.get());
                        parserFiles.push_back(std::move(parserFile));
                    }
                }
            }
        }
    }
}

void Project::ReadOutDir()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/out", xmlDoc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string dirAttribute = element->GetAttribute(U"dir");
                    if (!dirAttribute.empty())
                    {
                        if (outDir.empty())
                        {
                            outDir = GetFullPath(Path::Combine(rootDir, Path::MakeCanonical(ToUtf8(dirAttribute))));
                        }
                        else
                        {
                            throw std::runtime_error("output directory already specified");
                        }
                    }
                }
            }
        }
    }
    if (outDir.empty())
    {
        throw std::runtime_error("output directory not specified");
    }
    boost::filesystem::create_directories(outDir);
}

void Project::ReadStyleFilePath()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/style", xmlDoc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string fileAttribute = element->GetAttribute(U"file");
                    if (!fileAttribute.empty())
                    {
                        if (styleFilePath.empty())
                        {
                            styleFilePath = fileAttribute;
                        }
                        else
                        {
                            throw std::runtime_error("style file path already specified");
                        }
                    }
                    else
                    {
                        throw std::runtime_error("style file path is empty");
                    }
                }
            }
        }
    }
    if (styleFilePath.empty())
    {
        throw std::runtime_error("style file path not specified");
    }
}

void Project::ReadGrammarFiles()
{
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"/project/grammar", xmlDoc.get());
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    std::u32string fileAttribute = element->GetAttribute(U"file");
                    if (!fileAttribute.empty())
                    {
                        std::u32string grammarName = ToUtf32(Path::GetFileNameWithoutExtension(ToUtf8(fileAttribute)));
                        std::string grammarFilePath = GetFullPath(Path::Combine(rootDir, Path::MakeCanonical(ToUtf8(fileAttribute))));
                        std::unique_ptr<sngxml::dom::Document> grammarDoc = sngxml::dom::ReadDocument(grammarFilePath);
                        std::u32string kindAttribute = grammarDoc->DocumentElement()->GetAttribute(U"kind");
                        std::u32string sourceAttribute = grammarDoc->DocumentElement()->GetAttribute(U"source");
                        std::u32string titleAttribute = grammarDoc->DocumentElement()->GetAttribute(U"title");
                        if (sourceAttribute.empty())
                        {
                            throw std::runtime_error("grammar source not specified");
                        }
                        if (titleAttribute.empty())
                        {
                            throw std::runtime_error("grammar title not specified");
                        }
                        std::unique_ptr<Grammar> grammar;
                        GrammarParser* grammarParser = nullptr;
                        LexerFile* lexerFile = nullptr;
                        if (kindAttribute == U"lexical")
                        {
                            auto it = lexerMap.find(sourceAttribute);
                            if (it != lexerMap.cend())
                            {
                                lexerFile = it->second;
                                grammar.reset(new Grammar(grammarName, titleAttribute, GetFullPath(Path::Combine(outDir, ToUtf8(grammarName) + ".html")), lexerFile));
                                lexerGrammarMap[lexerFile] = grammar.get();
                            }
                            else
                            {
                                throw std::runtime_error("lexer '" + ToUtf8(sourceAttribute) + "' not found");
                            }
                        }
                        else
                        {
                            grammarParser = domain.GetParser(sourceAttribute);
                            grammar.reset(new Grammar(grammarName, titleAttribute, GetFullPath(Path::Combine(outDir, ToUtf8(grammarName) + ".html")), grammarParser));
                            parserGrammarMap[grammarParser] = grammar.get();
                        }
                        std::unique_ptr<sngxml::xpath::XPathObject> ruleResult = sngxml::xpath::Evaluate(U"/grammar/rule", grammarDoc.get());
                        if (ruleResult)
                        {
                            if (ruleResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                            {
                                sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(ruleResult.get());
                                int n = nodeSet->Length();
                                for (int i = 0; i < n; ++i)
                                {
                                    sngxml::dom::Node* node = (*nodeSet)[i];
                                    if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                    {
                                        sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                                        std::u32string sourceAttribute = element->GetAttribute(U"source");
                                        std::u32string nameAttribute = element->GetAttribute(U"name");
                                        if (sourceAttribute.empty())
                                        {
                                            throw std::runtime_error("rule source not specified");
                                        }
                                        if (nameAttribute.empty())
                                        {
                                            throw std::runtime_error("rule name not specified");
                                        }
                                        std::unique_ptr<Rule> rule;
                                        if (kindAttribute == U"lexical")
                                        {
                                            Expression* expression = lexerFile->GetExpressions()->Get(sourceAttribute);
                                            rule.reset(new Rule(nameAttribute, expression));
                                            lexerRuleMap[expression] = rule.get();
                                        }
                                        else
                                        {
                                            RuleParser* ruleParser = grammarParser->GetRule(sourceAttribute);
                                            rule.reset(new Rule(nameAttribute, ruleParser));
                                            parserRuleMap[ruleParser] = rule.get();
                                        }
                                        grammar->AddRule(rule.release());
                                    }
                                }
                            }
                        }
                        grammars.push_back(std::move(grammar));
                    }
                }
            }
        }
    }
}

void Project::Link()
{
    LinkerVisitor visitor;
    domain.Accept(visitor);
}

void Project::ParseLexerFiles()
{
    for (auto& lexerFile : lexerFiles)
    {
        lexerFile->Parse(lexerContext);
    }
}

void Project::GenerateHtml()
{
    GrammarHtmlGeneratorVisitor domainVisitor(verbose, parserGrammarMap, parserRuleMap, lexerGrammarMap, lexerRuleMap, lexerMap, styleFilePath);
    domain.Accept(domainVisitor);
    for (auto& lexerFile : lexerFiles)
    {
        auto it = lexerGrammarMap.find(lexerFile.get());
        if (it != lexerGrammarMap.cend())
        {
            Grammar* grammar = it->second;
            Expression* idStartExpression = lexerFile->GetExpressions()->Get(U"idstart");
            Rule* idStartRule = new Rule(U"idstart", idStartExpression);
            grammar->AddRule(idStartRule);
            lexerRuleMap[idStartExpression] = idStartRule;
            Expression* idContExpression = lexerFile->GetExpressions()->Get(U"idcont");
            Rule* idContRule = new Rule(U"idcont", idContExpression);
            grammar->AddRule(idContRule);
            lexerRuleMap[idContExpression] = idContRule;
        }
        GrammarHtmlGeneratorVisitor lexerFileVisitor(verbose, parserGrammarMap, parserRuleMap, lexerGrammarMap, lexerRuleMap, lexerMap, styleFilePath);
        lexerFile->Accept(lexerFileVisitor);
    }
}

} } // namespace sng2html::sng2html
