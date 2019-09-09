// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cmajor/ast/CompileUnit.hpp>
#include <cmajor/ast/Identifier.hpp>
#include <cmajor/ast/Visitor.hpp>
#include <soulng/util/Sha1.hpp>
#include <algorithm>

namespace cmajor { namespace ast {

CompileUnitNode::CompileUnitNode(const Span& span_) : Node(NodeType::compileUnitNode, span_), globalNs(), isSynthesizedUnit(false)
{
}

CompileUnitNode::CompileUnitNode(const Span& span_, const std::string& filePath_) : 
    Node(NodeType::compileUnitNode, span_), filePath(filePath_), globalNs(new NamespaceNode(span_, new IdentifierNode(span_, U""))), isSynthesizedUnit(false)
{
}

Node* CompileUnitNode::Clone(CloneContext& cloneContext) const
{
    CompileUnitNode* clone = new CompileUnitNode(GetSpan(), filePath);
    clone->globalNs.reset(static_cast<NamespaceNode*>(globalNs->Clone(cloneContext)));
    return clone;
}

void CompileUnitNode::Accept(Visitor& visitor)
{
    visitor.Visit(*this);
}

void CompileUnitNode::ComputeLineStarts(const std::u32string& sourceFileContent)
{
    int32_t index = 0;
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

const std::string& CompileUnitNode::Id() 
{
    if (id.empty())
    {
        id = GetSha1MessageDigest(filePath);
    }
    return id;
}

} } // namespace cmajor::ast
