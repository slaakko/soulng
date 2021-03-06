// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
#include <sngcpp/symbols/TypeSymbol.hpp>
#include <unordered_set>

namespace sngcpp { namespace symbols {

class ParameterSymbol;
class FunctionSymbol;

class SNGCPP_SYMBOLS_API CallableSymbol : public ContainerSymbol
{
public:
    CallableSymbol(const Span& span_, const std::u32string& name_);
    bool IsCallableSymbol() const override { return true; }
    virtual const std::vector<ParameterSymbol*>& Parameters() const = 0;
    virtual TypeSymbol* ReturnType() = 0;
    virtual int Arity() const = 0;
    virtual bool IsConst() const { return false; }
    virtual const std::u32string& GroupName() const = 0;
    virtual FunctionGroupSymbol* FunctionGroup() = 0;
    virtual std::u32string FunctionKind() = 0;
    virtual std::u32string FunctionId() = 0;
};

class SNGCPP_SYMBOLS_API FunctionDeclarationSymbol : public CallableSymbol
{
public:
    FunctionDeclarationSymbol(const Span& span_, const std::u32string& groupName_, const std::u32string& name_, Specifier specifiers_);
    bool IsFunctionDeclarationSymbol() const override { return true; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    void AddMember(std::unique_ptr<Symbol>&& member) override;
    void AddSpecifiers(Specifier specifiers_);
    Specifier Specifiers() const { return specifiers; }
    bool IsConst() const override { return (specifiers & Specifier::const_) != Specifier::none; }
    bool IsInstallSymbol() const override { return false; }
    std::u32string KindStr() override { return U"function_declaration"; }
    std::u32string FunctionKind() override { return U"function"; }
    std::u32string IdStr() override;
    void AddTemplateParameter(std::unique_ptr<TypeSymbol>&& templateParameter);
    const std::vector<ParameterSymbol*>& Parameters() const override { return parameters; }
    TypeSymbol* GetType() override { return returnType; }
    TypeSymbol* ReturnType() override { return returnType; }
    void SetReturnType(TypeSymbol* returnType_) { returnType = returnType_; }
    const std::u32string& GroupName() const override { return groupName; }
    int Arity() const { return parameters.size(); }
    FunctionGroupSymbol* FunctionGroup() override { return functionGroup; }
    void SetFileId(const std::u32string& fileId_) { fileId = fileId_; }
    const std::u32string& FileId() const { return fileId; }
    void SetFileName(const std::string& fileName_) { fileName = fileName_; }
    const std::string& FileName() const { return fileName; }
    void SetFunctionGroup(FunctionGroupSymbol* functionGroup_) { functionGroup = functionGroup_; }
    void SetFunctionDefinition(FunctionSymbol* functionDefinition_) { functionDefinition = functionDefinition_; }
    FunctionSymbol* FunctionDefinition() const { return functionDefinition; }
    std::u32string FunctionId() override;
private:
    std::u32string groupName;
    std::vector<ParameterSymbol*> parameters;
    std::vector<std::unique_ptr<TypeSymbol>> templateParameters;
    TypeSymbol* returnType;
    Specifier specifiers;
    FunctionGroupSymbol* functionGroup;
    std::u32string fileId;
    std::string fileName;
    FunctionSymbol* functionDefinition;
};

class SNGCPP_SYMBOLS_API ConstructorDeclarationSymbol : public FunctionDeclarationSymbol
{
public:
    ConstructorDeclarationSymbol(const Span& span_, const std::u32string& name_, Specifier specifiers_);
    bool IsConstructorDeclarationSymbol() const override { return true; }
    std::u32string KindStr() override { return U"constructor_declaration"; }
    std::u32string FunctionKind() override { return U"constructor"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    const std::u32string& SimpleName() const override { return Name(); }
    TypeSymbol* GetType() override { return Parent()->GetType(); }
    TypeSymbol* ReturnType() override { return Parent()->GetType(); }
};

class SNGCPP_SYMBOLS_API FunctionSymbol : public CallableSymbol
{
public:
    FunctionSymbol(const Span& span_, const std::u32string& groupName_, const std::u32string& name_, Specifier specifiers_);
    void AddMember(std::unique_ptr<Symbol>&& member) override;
    bool IsInstallSymbol() const override { return false; }
    bool IsFunctionSymbol() const override { return true; }
    void AddTemplateParameter(std::unique_ptr<TypeSymbol>&& templateParameter);
    std::u32string IdStr() override;
    std::u32string KindStr() override { return U"function"; }
    std::u32string FunctionKind() override { return U"function"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    const std::u32string& GroupName() const override { return groupName; }
    const std::u32string& SimpleName() const override { return groupName; }
    const std::vector<ParameterSymbol*>& Parameters() const override { return parameters; }
    bool NameBefore(Symbol* that) override;
    TypeSymbol* GetType() override { return returnType; }
    TypeSymbol* ReturnType() override { return returnType; }
    void SetReturnType(TypeSymbol* returnType_) { returnType = returnType_; }
    int Index() const { return index; }
    void SetIndex(int index_) { index = index_; }
    void AddSpecifiers(Specifier specifiers_);
    Specifier Specifiers() const { return specifiers; }
    bool IsConst() const override { return (specifiers & Specifier::const_) != Specifier::none; }
    int Arity() const override { return parameters.size(); }
    FunctionGroupSymbol* FunctionGroup() override { return functionGroup; }
    void SetFunctionGroup(FunctionGroupSymbol* functionGroup_) { functionGroup = functionGroup_; }
    void SetFileId(const std::u32string& fileId_) { fileId = fileId_; }
    const std::u32string& FileId() const { return fileId; }
    void SetFileName(const std::string& fileName_) { fileName = fileName_; }
    const std::string& FileName() const { return fileName; }
    void SetDeclarationFileId(const std::u32string& declarationFileId_) { declarationFileId = declarationFileId_; }
    const std::u32string& DeclarationFileId() const { return declarationFileId; }
    void SetDeclarationFileName(const std::string& declarationFileName_) { declarationFileName = declarationFileName_; }
    const std::string& DeclarationFileName() const { return declarationFileName; }
    void SetDeclarationSpan(const Span& declarationSpan_) { declarationSpan = declarationSpan_; }
    const Span& DeclarationSpan() const { return declarationSpan; }
    void AddOverride(FunctionSymbol* override_);
    const std::unordered_set<FunctionSymbol*>& Overrides() const { return overrides; }
    void AddOverridden(FunctionSymbol* overridden_);
    const std::unordered_set<FunctionSymbol*>& Overridden() { return overridden; }
    void AddToCalls(FunctionSymbol* function);
    const std::unordered_set<FunctionSymbol*>& Calls() const { return calls; }
    void AddToCalledBy(FunctionSymbol* function);
    const std::unordered_set<FunctionSymbol*>& CalledBy() const { return calledBy; }
    bool IsPureVirtual() const { return (specifiers & (Specifier::virtual_ | Specifier::pure_)) == (Specifier::virtual_ | Specifier::pure_); }
    std::u32string FunctionId() override { return Id(); }
private:
    std::u32string groupName;
    int index;
    std::vector<ParameterSymbol*> parameters;
    std::vector<std::unique_ptr<TypeSymbol>> templateParameters;
    TypeSymbol* returnType;
    Specifier specifiers;
    FunctionGroupSymbol* functionGroup;
    std::u32string fileId;
    std::string fileName;
    std::u32string declarationFileId;
    std::string declarationFileName;
    Span declarationSpan;
    std::unordered_set<FunctionSymbol*> overrides;
    std::unordered_set<FunctionSymbol*> overridden;
    std::unordered_set<FunctionSymbol*> calls;
    std::unordered_set<FunctionSymbol*> calledBy;
};

class SNGCPP_SYMBOLS_API ConstructorSymbol : public FunctionSymbol
{
public:
    ConstructorSymbol(const Span& span_, const std::u32string& name_, Specifier specifiers_);
    bool IsConstructorSymbol() const override { return true; }
    std::u32string KindStr() override { return U"constructor"; }
    std::u32string FunctionKind() override { return U"constructor"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    const std::u32string& SimpleName() const override { return Name(); }
    TypeSymbol* GetType() override { return Parent()->GetType(); }
    TypeSymbol* ReturnType() override { return Parent()->GetType(); }
};

class SNGCPP_SYMBOLS_API DestructorSymbol : public FunctionSymbol
{
public:
    DestructorSymbol(const Span& span_, const std::u32string& name_, Specifier specifiers_);
    bool IsDestructorSymbol() const override { return true; }
    std::u32string KindStr() override { return U"destructor"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    const std::u32string& SimpleName() const override { return Name(); }
};

class SNGCPP_SYMBOLS_API FunctionGroupSymbol : public Symbol
{
public:
    FunctionGroupSymbol(const Span& span_, const std::u32string& name_);
    bool IsFunctionGroupSymbol() const override { return true; }
    void AddFunction(std::unique_ptr<FunctionSymbol>&& function);
    void AddFunctionDeclaration(std::unique_ptr<FunctionDeclarationSymbol>&& functionDeclaration);
    FunctionDeclarationSymbol* GetFunctionDeclaration(const std::vector<ParameterSymbol*>& parameters, Specifier specifiers);
    CallableSymbol* ResolveOverload(const std::vector<Symbol*>& argumentSymbols, bool subjectIsConst);
    std::u32string KindStr() override { return U"function_group"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    const std::vector<std::unique_ptr<FunctionSymbol>>& Functions() const { return functions; }
    const std::vector<std::unique_ptr<FunctionDeclarationSymbol>>& FunctionDeclarations() const { return functionDeclarations; }
private:
    std::vector<std::unique_ptr<FunctionSymbol>> functions;
    std::vector<std::unique_ptr<FunctionDeclarationSymbol>> functionDeclarations;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_FUNCTION_SYMBOL_INCLUDED
