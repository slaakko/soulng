// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/symbols/ClassTemplateSpecializationSymbol.hpp>

namespace sngcpp { namespace symbols {

std::u32string MakeClassTemplateSpecializationId(TypeSymbol* primaryClassTemplateSymbol, const std::vector<TypeSymbol*>& templateArgumentSymbols)
{
    std::u32string id = primaryClassTemplateSymbol->Id();
    for (TypeSymbol* templateArgument : templateArgumentSymbols)
    {
        id.append(U".").append(templateArgument->Id());
    }
    return id;
}

std::u32string MakeClassTemplateSpecializationName(TypeSymbol* primaryClassTemplateSymbol, const std::vector<TypeSymbol*>& templateArgumentSymbols)
{
    std::u32string name = primaryClassTemplateSymbol->Name();
    name.append(1, '<');
    bool first = true;
    for (TypeSymbol* templateArgument : templateArgumentSymbols)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            name.append(U", ");
        }
        name.append(templateArgument->Name());
    }
    name.append(1, '>');
    return name;
}

ClassTemplateSpecializationSymbol::ClassTemplateSpecializationSymbol(const Span& span_, const std::u32string& name_, TypeSymbol* primaryClassTemplateSymbol_,
    TemplateIdNode* templateIdNode_, const std::vector<TypeSymbol*>& templateArgumentSymbols_, const std::vector<Node*>& templateArgumentNodes_, const std::u32string& id_) :
    ClassTypeSymbol(span_, name_, primaryClassTemplateSymbol_->GetClassKey()), primaryClassTemplateSymbol(primaryClassTemplateSymbol_), templateIdNode(templateIdNode_),
    templateArgumentSymbols(templateArgumentSymbols_), templateArgumentNodes(templateArgumentNodes_), id(id_)
{
}

bool ClassTemplateSpecializationSymbol::HasBaseClass(TypeSymbol* type, int& distance)
{
    return primaryClassTemplateSymbol->HasBaseClass(type, distance);
}

std::unique_ptr<sngxml::dom::Element> ClassTemplateSpecializationSymbol::CreateElement()
{
    std::unique_ptr<sngxml::dom::Element> typeElement(new sngxml::dom::Element(U"specialization"));
    typeElement->SetAttribute(U"primaryTypeId", primaryClassTemplateSymbol->Id());
    std::unique_ptr<sngxml::dom::Element> templateArgumentsElement(new sngxml::dom::Element(U"templateArguments"));
    for (TypeSymbol* templateArgument : templateArgumentSymbols)
    {
        std::unique_ptr<sngxml::dom::Element> templateArgumentElement(new sngxml::dom::Element(U"templateArgument"));
        templateArgumentElement->SetAttribute(U"typeId", templateArgument->Id());
        templateArgumentsElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(templateArgumentElement.release()));
    }
    typeElement->AppendChild(std::unique_ptr<sngxml::dom::Node>(templateArgumentsElement.release()));
    return typeElement;
}

} } // namespace sngcpp::symbols
