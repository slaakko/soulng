// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef CMAJOR_AST_COMPILE_UNIT_INCLUDED
#define CMAJOR_AST_COMPILE_UNIT_INCLUDED
#include <cmajor/ast/Namespace.hpp>

namespace cmajor { namespace ast {

class CMAJOR_AST_API CompileUnitNode : public Node
{
public:
    CompileUnitNode(const Span& span_);
    CompileUnitNode(const Span& span_, const std::string& filePath_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    const std::string& FilePath() const { return filePath; }
    const NamespaceNode* GlobalNs() const { return globalNs.get(); }
    NamespaceNode* GlobalNs() { return globalNs.get(); }
    void ComputeLineStarts(const std::u32string& sourceFileContent);
    const std::vector<int32_t>& LineStarts() { return lineStarts; }
    void SetSynthesizedUnit() { isSynthesizedUnit = true; }
    bool IsSynthesizedUnit() const { return isSynthesizedUnit; }
    const std::string& Id();
private:
    std::string filePath;
    std::unique_ptr<NamespaceNode> globalNs;
    std::vector<int32_t> lineStarts;
    bool isSynthesizedUnit;
    std::string id;
};

} } // namespace cmajor::ast

#endif // CMAJOR_AST_COMPILE_UNIT_INCLUDED
