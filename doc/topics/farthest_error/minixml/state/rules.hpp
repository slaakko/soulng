#ifndef RULES_H
#define RULES_H
#include <vector>

std::vector<const char*>* GetRuleNameVecPtr();

const int minixml_document = 0;
const int minixml_element = 1;
const int minixml_spaces = 2;
const int minixml_name = 3;
const int minixml_name_start_char = 4;
const int minixml_name_char = 5;
const int minixml_element_content = 6;
const int minixml_text = 7;

#endif // RULES_H
