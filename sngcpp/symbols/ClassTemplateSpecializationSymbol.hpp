// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_SYMBOLS_CLASS_TEMPLATE_SPECIALIZATION_SYMBOL_INCLUDED
#define SNGCPP_SYMBOLS_CLASS_TEMPLATE_SPECIALIZATION_SYMBOL_INCLUDED
#include <sngcpp/symbols/ClassTypeSymbol.hpp>
#include <sngcpp/ast/Template.hpp>

namespace sngcpp { namespace symbols {

SNGCPP_SYMBOLS_API std::u32string MakeClassTemplateSpecializationId(TypeSymbol* primaryClassTemplateSymbol, const std::vector<TypeSymbol*>& templateArgumentSymbols);
SNGCPP_SYMBOLS_API std::u32string MakeClassTemplateSpecializationName(TypeSymbol* primaryClassTemplateSymbol, const std::vector<TypeSymbol*>& templateArgumentSymbols);

class SNGCPP_SYMBOLS_API ClassTemplateSpecializationSymbol : public ClassTypeSymbol
{
public:
    ClassTemplateSpecializationSymbol(const Span& span_, const std::u32string& name_, TypeSymbol* primaryClassTemplateSymbol_, const std::vector<TypeSymbol*>& templateArgumentSymbols_,
        const std::u32string& id_);
    bool IsClassTemplateSpecializationSymbol() const override { return true; }
    bool HasBaseClass(TypeSymbol* type, int& distance) override;
    ClassKey GetClassKey() const override { return primaryClassTemplateSymbol->GetClassKey(); }
    TypeSymbol* PrimaryClassTemplateSymbol() { return primaryClassTemplateSymbol; }
    const std::vector<TypeSymbol*>& TemplateArgumentSymbols() const { return templateArgumentSymbols; }
    std::unique_ptr<sngxml::dom::Element> CreateElement() override;
    std::u32string Id() override { return id; }
private:
    std::u32string id;
    TypeSymbol* primaryClassTemplateSymbol;
    std::vector<TypeSymbol*> templateArgumentSymbols;
};

} } // namespace sngcpp::symbols

#endif // SNGCPP_SYMBOLS_CLASS_TEMPLATE_SPECIALIZATION_SYMBOL_INCLUDED
