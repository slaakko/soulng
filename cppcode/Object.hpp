// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_CPPCODE_OBJECT_INCLUDED
#define SOULNG_CPPCODE_OBJECT_INCLUDED
#include <soulng/cppcode/CppCodeApi.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <string>
#include <vector>
#include <memory>

namespace soulng { namespace cppcode  {

using soulng::util::CodeFormatter;
class Visitor;

class CPPCODE_API CppObject
{
public:
    CppObject(const std::u32string& name_);
    CppObject(const CppObject&) = delete;
    CppObject& operator=(const CppObject&) = delete;
    virtual ~CppObject();
    virtual void AddExpr(CppObject* expr);
    const std::u32string& Name() const { return name; }
    void SetName(const std::u32string& newName) { name = newName; }
    void Own(CppObject* object);
    bool IsOwned() const { return isOwned; }
    void SetOwned() { isOwned = true; }
    void ResetOwned() { isOwned = false; }
    virtual std::u32string ToString() const;
    virtual void Print(CodeFormatter& formatter) ;
    virtual void Accept(Visitor& visitor) = 0;
private:
    std::u32string name;
    bool isOwned;
    std::vector<std::unique_ptr<CppObject>> ownedObjects;
};

} } // namespace soulng::cppcode

#endif // SOULNG_CPPCODE_OBJECT_INCLUDED
