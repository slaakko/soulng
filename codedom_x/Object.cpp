// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/codedom/Object.hpp>
#include <soulng/util/Unicode.hpp>

namespace soulng { namespace codedom {

using namespace soulng::util;
using namespace soulng::unicode;

CppObject::CppObject(const std::u32string& name_): name(name_), isOwned(false)
{
}

CppObject::~CppObject()
{
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

} } // namespace soulng::codedom
