// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/SourceFile.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <sngcpp/ast/Writer.hpp>
#include <sngcpp/ast/Reader.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Sha1.hpp>

namespace sngcpp { namespace ast {

using namespace soulng::unicode;
using namespace soulng::util;

SourceFileNode::SourceFileNode() : Node(NodeType::sourceFileNode), sourceFileIndex(-1), processed()
{
}

SourceFileNode::SourceFileNode(const Span& span_, const std::string& sourceFilePath_, const std::string& relativeSourceFilePath_, const std::u32string& projectName_) :
    Node(NodeType::sourceFileNode, span_), globalNs(new NamespaceNode(span_)), sourceFilePath(sourceFilePath_), relativeSourceFilePath(relativeSourceFilePath_), projectName(projectName_),
    sourceFileIndex(-1), processed(false)
{
    std::string fileName = relativeSourceFilePath;
    for (char& c : fileName)
    {
        if (c == '/' || c == '\\' || c == ':')
        {
            c = '_';
        }
    }
    fileName.append(1, '_').append(GetSha1MessageDigest(sourceFilePath));
    fileName.append(".html");
    id = U"file/" + ToUtf32(fileName);
}

void SourceFileNode::AddUsingDirectiveOrDeclaration(Node* usingDirectivesAndDeclaration)
{
    usingDirectivesAndDeclarations.push_back(usingDirectivesAndDeclaration);
}

void SourceFileNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SourceFileNode::Write(Writer& writer)
{
    Node::Write(writer);
    writer.GetBinaryWriter().Write(sourceFilePath);
    writer.GetBinaryWriter().Write(relativeSourceFilePath);
    writer.GetBinaryWriter().Write(projectName);
    writer.GetBinaryWriter().Write(htmlSourceFilePath);
    writer.GetBinaryWriter().Write(id);
    globalNs->Write(writer);
    int32_t n = lineStarts.size();
    writer.GetBinaryWriter().Write(n);
    for (int32_t i = 0; i < n; ++i)
    {
        writer.GetBinaryWriter().Write(int32_t(lineStarts[i]));
    }
    int32_t numHeaderfiles = headerFilePaths.size();
    writer.GetBinaryWriter().Write(numHeaderfiles);
    for (int32_t i = 0; i < numHeaderfiles; ++i)
    {
        writer.GetBinaryWriter().Write(headerFilePaths[i]);
    }
    writer.GetBinaryWriter().Write(text);
}

void SourceFileNode::Read(Reader& reader)
{
    Node::Read(reader);
    sourceFilePath = reader.GetBinaryReader().ReadUtf8String();
    relativeSourceFilePath = reader.GetBinaryReader().ReadUtf8String();
    projectName = reader.GetBinaryReader().ReadUtf32String();
    htmlSourceFilePath = reader.GetBinaryReader().ReadUtf8String();
    id = reader.GetBinaryReader().ReadUtf32String();
    globalNs.reset(reader.ReadNamespaceNode());
    int32_t n = reader.GetBinaryReader().ReadInt();
    for (int32_t i = 0; i < n; ++i)
    {
        lineStarts.push_back(reader.GetBinaryReader().ReadInt());
    }
    int32_t numHeaderfiles = reader.GetBinaryReader().ReadInt();
    for (int32_t i = 0; i < numHeaderfiles; ++i)
    {
        headerFilePaths.push_back(reader.GetBinaryReader().ReadUtf8String());
    }
    text = reader.GetBinaryReader().ReadUtf32String();
}

void SourceFileNode::ComputeLineStarts()
{
    int index = 0;
    bool startOfLine = true;
    for (char32_t c : text)
    {
        if (startOfLine)
        {
            lineStarts.push_back(index);
            startOfLine = false;
        }
        if (c == U'\n')
        {
            startOfLine = true;
        }
        ++index;
    }
}

SourceFileSequenceNode::SourceFileSequenceNode() : BinaryNode(NodeType::sourceFileSequenceNode)
{
}

SourceFileSequenceNode::SourceFileSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(NodeType::sourceFileSequenceNode, span_, left_, right_)
{
}

void SourceFileSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

class SourceFileResolverVisitor : public Visitor
{
public:
    SourceFileResolverVisitor(std::vector<SourceFileNode*>& sourceFiles_) : sourceFiles(sourceFiles_)
    {
    }
    void Visit(SourceFileNode& sourceFileNode) override
    {
        sourceFiles.push_back(&sourceFileNode);
    }
    void Visit(SourceFileSequenceNode& sourceFileSequenceNode) override
    {
        sourceFileSequenceNode.Left()->Accept(*this);
        sourceFileSequenceNode.Right()->Accept(*this);
    }
private:
    std::vector<SourceFileNode*>& sourceFiles;
};

void ResolveSourceFiles(Node* ast, std::vector<SourceFileNode*>& sourceFiles)
{
    SourceFileResolverVisitor resolver(sourceFiles);
    ast->Accept(resolver);
}

} } // namespace sngcpp::ast
