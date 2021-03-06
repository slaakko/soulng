// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/cppcode/Object.hpp>
#include <soulng/util/Unicode.hpp>

namespace soulng { namespace cppcode  {

using namespace soulng::util;
using namespace soulng::unicode;

CppObject::CppObject(const std::u32string& name_): name(name_), isOwned(false)
{
}

CppObject::~CppObject()
{
}

void CppObject::AddExpr(CppObject* expr)
{
    throw std::runtime_error("cannot add '" + ToUtf8(expr->Name()) + "' to '" + ToUtf8(name) + "'");
}

void CppObject::Own(CppObject* object)
{
    if (object)
    {
        if (!object->IsOwned())
        {
            object->SetOwned();
            ownedObjects.push_back(std::unique_ptr<CppObject>(object));
        }
    }
}

std::u32string CppObject::ToString() const
{
    return name;
}

void CppObject::Print(CodeFormatter& formatter)
{
    formatter.Write(ToUtf8(name));
}

} } // namespace soulng::cppcode
