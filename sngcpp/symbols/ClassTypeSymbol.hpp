// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED
#include <sngcpp/symbols/FunctionSymbol.hpp>
#include <sngcpp/ast/Class.hpp>

namespace sngcpp { namespace symbols {

using namespace sngcpp::ast;

class SNGCPP_SYMBOLS_API ClassTypeSymbol : public TypeSymbol
{
public:
    ClassTypeSymbol(const Span& span_, const std::u32string& name_, ClassKey classKey_);
    bool IsInstallSymbol() const override { return false; }
    bool IsClassTypeSymbol() const override { return true; }
    bool IsParentSymbol() const override { return true; }
    bool HasBaseClass(TypeSymbol* type, int& distance) override;
    int MatchValue(TypeSymbol* argumentType) override;
    bool IsAbstract() const { return isAbstract; }
    void SetAbstract() { isAbstract = true; }
    void AddTemplateParameter(std::unique_ptr<TypeSymbol>&& templateParameter);
    int NumBases() const override { return baseClasses.size(); }
    ContainerSymbol* GetBase(int i) const override;
    void AddBaseClass(TypeSymbol* baseClass);
    const std::vector<TypeSymbol*>& BaseClasses() const { return baseClasses; }
    void AddDerivedClass(TypeSymbol* derivedClass);
    const std::vector<TypeSymbol*>& DerivedClasses() const { return derivedClasses; }
    ClassKey GetClassKey() const override { return classKey; }
    int Arity() const { return templateParameters.size(); }
    std::u32string IdStr() override;
    std::u32string KindStr() override;
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    void SetFileId(const std::u32string& fileId_) { fileId = fileId_; }
    const std::u32string& FileId() const { return fileId; }
    void SetFileName(const std::string& fileName_) { fileName = fileName_; }
    const std::string& FileName() const { return fileName; }
    const std::vector<FunctionSymbol*>& VirtualFunctions() const { return virtualFunctions; }
    void AddVirtualFunction(FunctionSymbol* virtualFunction);
private:
    ClassKey classKey;
    std::vector<TypeSymbol*> baseClasses;
    std::vector<TypeSymbol*> derivedClasses;
    std::vector<std::unique_ptr<TypeSymbol>> templateParameters;
    std::u32string fileId;
    std::string fileName;
    std::vector<FunctionSymbol*> virtualFunctions;
    bool isAbstract;
};

class SNGCPP_SYMBOLS_API ElaborateClassTypeSymbol : public TypeSymbol
{
public:
    ElaborateClassTypeSymbol(const Span& span_, ClassKey classKey_, TypeSymbol* classType_, const std::u32string& id_);
    bool IsElaborateClassTypeSymbol() const override { return true; }
    ClassKey GetClassKey() const { return classKey; }
    TypeSymbol* GetClassType() { return classType; }
    std::u32string Id() override { return id; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
private:
    ClassKey classKey;
    TypeSymbol* classType;
    std::u32string id;
};

class SNGCPP_SYMBOLS_API ClassGroupSymbol : public Symbol
{
public:
    ClassGroupSymbol(const Span& span_, const std::u32string& name_);
    bool IsClassGroupSymbol() const override { return true; }
    void AddClass(std::unique_ptr<ClassTypeSymbol>&& cls);
    ClassTypeSymbol* GetClass(int arity) const;
    std::u32string KindStr() override { return U"class_group"; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    const std::vector<std::unique_ptr<ClassTypeSymbol>>& Classes() const { return classes; }
private:
    std::vector<std::unique_ptr<ClassTypeSymbol>> classes;
    std::unordered_map<int, ClassTypeSymbol*> arityClassMap;
};

class SNGCPP_SYMBOLS_API ClassGroupTypeSymbol : public TypeSymbol
{
public:
    ClassGroupTypeSymbol(ClassGroupSymbol* classGroup_);
    std::u32string Id() override { return classGroup->Id(); }
    bool IsClassGroupTypeSymbol() const override { return true; }
    ClassGroupSymbol* ClassGroup() { return classGroup; }
private:
    ClassGroupSymbol* classGroup;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CLASS_TYPE_SYMBOL_INCLUDED
