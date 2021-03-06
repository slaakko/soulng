// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCM_AST_COMPILE_UNIT_INCLUDED
#define SNGCM_AST_COMPILE_UNIT_INCLUDED
#include <sngcm/ast/Namespace.hpp>

namespace sngcm { namespace ast {

class SNGCM_AST_API CompileUnitNode : public Node
{
public:
    CompileUnitNode(const Span& span_);
    CompileUnitNode(const Span& span_, const std::string& filePath_);
    Node* Clone(CloneContext& cloneContext) const override;
    void Accept(Visitor& visitor) override;
    const std::string& FilePath() const { return filePath; }
    const NamespaceNode* GlobalNs() const { return globalNs.get(); }
    NamespaceNode* GlobalNs() { return globalNs.get(); }
    void ResetGlobalNs(NamespaceNode* ns);
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

SNGCM_AST_API void CombineNamespaces(CompileUnitNode& cu);
SNGCM_AST_API void ArrangeClassMembers(CompileUnitNode& cu);
SNGCM_AST_API void AddNamespaceImportsForUnnamedNamespaces(CompileUnitNode& cu);

} } // namespace sngcm::ast

#endif // SNGCM_AST_COMPILE_UNIT_INCLUDED
