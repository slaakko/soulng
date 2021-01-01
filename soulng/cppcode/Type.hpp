// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_CPPCODE_TYPE_INCLUDED
#define SOULNG_CPPCODE_TYPE_INCLUDED
#include <soulng/cppcode/Object.hpp>

namespace soulng { namespace cppcode  {

class CPPCODE_API DeclSpecifier : public CppObject
{
public:
    DeclSpecifier(const std::u32string& name_);
};

class CPPCODE_API Typedef : public DeclSpecifier
{
public:
    Typedef();
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API TypeSpecifier : public DeclSpecifier
{
public:
    TypeSpecifier(const std::u32string& name_);
    void Accept(Visitor& visitor) override;
};

class CPPCODE_API Const : public TypeSpecifier
{
public:
    Const();
};

class CPPCODE_API Volatile: public TypeSpecifier
{
public:
    Volatile();
};

class CPPCODE_API TypeName : public TypeSpecifier
{
public:
    TypeName(const std::u32string& name_);
    void AddTemplateArgument(CppObject* templateArgument);
    bool IsTemplate() const { return isTemplate; }
    bool& IsTemplate() { return isTemplate; }
    std::u32string ToString() const override;
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    bool isTemplate;
    std::vector<CppObject*> templateArguments;
};

class CPPCODE_API Type : public CppObject
{
public:
    Type();
    void Add(TypeSpecifier* typeSpecifier);
    std::u32string ToString() const override;
    void Print(CodeFormatter& formatter) override;
    void Accept(Visitor& visitor) override;
private:
    std::vector<TypeSpecifier*> typeSpecifiers;
};

typedef std::shared_ptr<Type> TypePtr;

class CPPCODE_API TypeId : public CppObject
{
public:
    typedef std::vector<TypeSpecifier*> TypeSpecifierVec;
    TypeId();
    void Add(TypeSpecifier* typeSpecifier);
    const TypeSpecifierVec& TypeSpecifiers() const { return typeSpecifiers; }
    TypeSpecifierVec& TypeSpecifiers() { return typeSpecifiers; }
    const std::u32string& Declarator() const { return declarator; }
    std::u32string& Declarator() { return declarator; }
    std::u32string ToString() const override;
    void Print(CodeFormatter& formatter) override;
    void PrintNonPtrType(CodeFormatter& formatter);
    void Accept(Visitor& visitor) override;
    bool IsPtrType() const;
private:
    TypeSpecifierVec typeSpecifiers;
    std::u32string declarator;
};

class CPPCODE_API StorageClassSpecifier : public DeclSpecifier
{
public:
    StorageClassSpecifier(const std::u32string& name_): DeclSpecifier(name_) {}
    void Accept(Visitor& visitor) override;
};

} } // namespace soulng::cppcode

#endif // SOULNG_CPPCODE_TYPE_INCLUDED
