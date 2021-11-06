#include "rules.hpp"

std::vector<const char*> rules = {
"minixml.document"
, "minixml.element"
, "minixml.spaces"
, "minixml.name"
, "minixml.name_start_char"
, "minixml.name_char"
, "minixml.element_content"
, "minixml.text"
};

std::vector<const char*>* GetRuleNameVecPtr()
{
    return &rules;
}
