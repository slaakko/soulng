// =================================
// Copyright (c) 2020 Seppo Laakko
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

class SNGCPP_AST_API SourceFileNode : public Node
{
public:
    SourceFileNode();
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
    void Write(Writer& writer) override;
    void Read(Reader& reader) override;
    NamespaceNode* GlobalNs() { return globalNs.get(); }
    void AddUsingDirectiveOrDeclaration(Node* usingDirectivesAndDeclaration);
    const std::vector<Node*>& UsingDirectivesAndDeclarations() const { return usingDirectivesAndDeclarations; }
    bool Processed() const { return processed; }
    void SetProcessed() { processed = true; }
    void ComputeLineStarts();
    std::vector<int>* LineStarts() { return &lineStarts; }
    void SetContent(std::unique_ptr<std::u32string>&& content_) { content = std::move(content_); }
    void SetHeaderFilePaths(std::vector<std::string>&& headerFilePaths_) { headerFilePaths = std::move(headerFilePaths_); }
    const std::vector<std::string>& HeaderFilePaths() const { return headerFilePaths; }
    void SetText(std::u32string&& text_) { text = std::move(text_); }
    const std::u32string& Text() const { return text; }
private:
    std::string sourceFilePath;
    std::string relativeSourceFilePath;
    std::u32string projectName;
    std::string htmlSourceFilePath;
    std::u32string id;
    int sourceFileIndex;
    std::unique_ptr<NamespaceNode> globalNs;
    std::vector<Node*> usingDirectivesAndDeclarations;
    bool processed;
    std::vector<int> lineStarts;
    std::unique_ptr<std::u32string> content;
    std::vector<std::string> headerFilePaths;
    std::u32string text;
};

class SNGCPP_AST_API SourceFileSequenceNode : public BinaryNode
{
public:
    SourceFileSequenceNode();
    SourceFileSequenceNode(const Span& span_, Node* left_, Node* right_);
    void Accept(Visitor& visitor) override;
};

SNGCPP_AST_API void ResolveSourceFiles(Node* ast, std::vector<SourceFileNode*>& sourceFiles);

} } // namespace sngcpp::ast

#endif // SNGCPP_AST_SOURCE_FILE_INCLUDED
