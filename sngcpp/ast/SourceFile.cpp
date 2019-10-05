// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/ast/SourceFile.hpp>
#include <sngcpp/ast/Visitor.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/Sha1.hpp>

namespace sngcpp { namespace ast {

using namespace soulng::unicode;
using namespace soulng::util;

IncludeDirectiveNode::IncludeDirectiveNode(const Span& span_, const std::string& includeFilePath_) : Node(span_), includeFilePath(includeFilePath_), sourceFileNode(nullptr)
{
}

void IncludeDirectiveNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

IncludeDirectiveSequenceNode::IncludeDirectiveSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void IncludeDirectiveSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

SourceFileNode::SourceFileNode(const Span& span_, const std::string& sourceFilePath_, const std::string& relativeSourceFilePath_, const std::u32string& projectName_) :
    Node(span_), globalNs(new NamespaceNode(span_)), sourceFilePath(sourceFilePath_), relativeSourceFilePath(relativeSourceFilePath_), projectName(projectName_), 
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
    id = U"file/" + projectName + U"/" + ToUtf32(fileName);
}

void SourceFileNode::AddIncludeDirective(IncludeDirectiveNode* includeDirective)
{
    if (includeDirectives)
    {
        includeDirectives.reset(new IncludeDirectiveSequenceNode(includeDirective->GetSpan(), includeDirectives.release(), includeDirective));
    }
    else
    {
        includeDirectives.reset(includeDirective);
    }
}

void SourceFileNode::AddUsingDirectiveOrDeclaration(Node* usingDirectivesAndDeclaration)
{
    usingDirectivesAndDeclarations.push_back(usingDirectivesAndDeclaration);
}

void SourceFileNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void SourceFileNode::ComputeLineStarts(const std::u32string& sourceFileContent)
{
    int index = 0;
    bool startOfLine = true;
    for (const char32_t& c : sourceFileContent)
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

SourceFileSequenceNode::SourceFileSequenceNode(const Span& span_, Node* left_, Node* right_) : BinaryNode(span_, left_, right_)
{
}

void SourceFileSequenceNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

} } // namespace sngcpp::ast
