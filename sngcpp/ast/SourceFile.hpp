// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_SOURCE_FILE_INCLUDED
#define SNGCPP_AST_SOURCE_FILE_INCLUDED
#include <sngcpp/ast/Namespace.hpp>
#include <string>
#include <vector>
#include <memory>

namespace sngcpp { namespace ast {

class SourceFileNode;

class SNGCPP_AST_API IncludeDirectiveNode : public Node
{
public:
    IncludeDirectiveNode(const Span& span_, const std::string& includeFilePath_);
    const std::string& IncludeFilePath() const { return includeFilePath; }
    void Accept(Visitor& visitor) override;
    void SetSourceFileNode(SourceFileNode* sourceFileNode_) { sourceFileNode = sourceFileNode_; }
    SourceFileNode* GetSourceFileNode() { return sourceFileNode; }
private:
    std::string includeFilePath;
    SourceFileNode* sourceFileNode;
};

class SNGCPP_AST_API IncludeDirectiveSequenceNode : public BinaryNode
{
public:
    IncludeDirectiveSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

class SNGCPP_AST_API SourceFileNode : public Node
{
public:
    SourceFileNode(const Span& span_, const std::string& sourceFilePath_, const std::string& relativeSourceFilePath_, const std::u32string& projectName_);
    const std::string& SourceFilePath() const { return sourceFilePath; }
    const std::string& RelativeSourceFilePath() { return relativeSourceFilePath; }
    const std::u32string& ProjectName() const { return projectName; }
    void SetHtmlSourceFilePath(const std::string& htmlSourceFilePath_) { htmlSourceFilePath = htmlSourceFilePath_; }
    const std::string& HtmlSourceFilePath() const { return htmlSourceFilePath; }
    const std::u32string& Id() const { return id; }
    void SetSourceFileIndex(int sourceFileIndex_) { sourceFileIndex = sourceFileIndex_; }
    int SourceFileIndex() const { return sourceFileIndex; }
    void Accept(Visitor& visitor) override;
    Node* IncludeDirectives() { return includeDirectives.get(); }
    void AddIncludeDirective(IncludeDirectiveNode* includeDirective);
    NamespaceNode* GlobalNs() { return globalNs.get(); }
    void AddUsingDirectiveOrDeclaration(Node* usingDirectivesAndDeclaration);
    const std::vector<Node*>& UsingDirectivesAndDeclarations() const { return usingDirectivesAndDeclarations; }
    bool Processed() const { return processed; }
    void SetProcessed() { processed = true; }
    void ComputeLineStarts(const std::u32string& sourceFileContent);
    std::vector<int>* LineStarts() { return &lineStarts; }
private:
    std::string sourceFilePath;
    std::string relativeSourceFilePath;
    std::u32string projectName;
    std::string htmlSourceFilePath;
    std::u32string id;
    int sourceFileIndex;
    std::unique_ptr<Node> includeDirectives;
    std::unique_ptr<NamespaceNode> globalNs;
    std::vector<Node*> usingDirectivesAndDeclarations;
    bool processed;
    std::vector<int> lineStarts;
};

class SNGCPP_AST_API SourceFileSequenceNode : public BinaryNode
{
public:
    SourceFileSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_SOURCE_FILE_INCLUDED
