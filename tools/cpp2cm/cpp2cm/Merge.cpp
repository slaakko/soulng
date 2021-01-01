// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <cpp2cm/cpp2cm/Merge.hpp>
#include <sngxml/xpath/XPathEvaluate.hpp>
#include <sngxml/dom/Element.hpp>

namespace cpp2cm {

sngxml::dom::Node* AddElement(sngxml::dom::Element* sourceElement, sngxml::dom::Element* parentElement, sngxml::dom::Document* targetDoc, bool deep, const std::u32string& container)
{
    sngxml::dom::Element* originalParent = parentElement;
    if (parentElement == nullptr)
    {
        if (sourceElement->Parent() && sourceElement->Parent()->GetNodeType() == sngxml::dom::NodeType::elementNode)
        {
            parentElement = static_cast<sngxml::dom::Element*>(sourceElement->Parent());
        }
    }
    else
    {
        if (parentElement->Parent() && parentElement->Parent()->GetNodeType() == sngxml::dom::NodeType::elementNode)
        {
            parentElement = static_cast<sngxml::dom::Element*>(parentElement->Parent());
        }
    }
    if (parentElement)
    {
        std::u32string parentId = parentElement->GetAttribute(U"id");
        if (!parentId.empty())
        {
            sngxml::dom::Element* targetParentElement = targetDoc->GetElementById(parentId);
            if (!targetParentElement)
            {
                sngxml::dom::Node* newNode = AddElement(parentElement, parentElement, targetDoc, false, container);
                if (newNode)
                {
                    if (newNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                    {
                        targetParentElement = static_cast<sngxml::dom::Element*>(newNode);
                    }
                }
            }
            if (targetParentElement)
            {
                if (originalParent && originalParent->Name() == container)
                {
                    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(container, targetParentElement);
                    if (result)
                    {
                        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
                        {
                            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
                            int n = nodeSet->Length();
                            if (n == 0)
                            {
                                sngxml::dom::Node* parentNode = targetParentElement->AppendChild(originalParent->CloneNode(false));
                                if (parentNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                {
                                    targetParentElement = static_cast<sngxml::dom::Element*>(parentNode);
                                }
                            }
                            else if (n == 1)
                            {
                                sngxml::dom::Node* node = (*nodeSet)[0];
                                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                                {
                                    targetParentElement = static_cast<sngxml::dom::Element*>(node);
                                }
                            }
                        }
                    }
                }
                return targetParentElement->AppendChild(sourceElement->CloneNode(deep));
            }
        }
        else
        {
            return AddElement(sourceElement, parentElement, targetDoc, deep, container);
        }
    }
    return nullptr;
}

void RemoveElement(sngxml::dom::Element* element)
{
    if (element->Parent() && element->Parent()->GetNodeType() == sngxml::dom::NodeType::elementNode)
    {
        sngxml::dom::Element* parentElement = static_cast<sngxml::dom::Element*>(element->Parent());
        parentElement->RemoveChild(element);
    }
}

void MergeConstructors(sngxml::dom::Element* sourceElement, sngxml::dom::Document* targetDoc)
{
    std::vector<sngxml::dom::Element*> elementsToRemove;
    std::vector<sngxml::dom::Element*> elementsToAdd;
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"constructors/constructor", sourceElement);
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* constructorElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string constructorId = constructorElement->GetAttribute(U"id");
                    if (!constructorId.empty())
                    {
                        sngxml::dom::Element* targetConstructorElement = targetDoc->GetElementById(constructorId);
                        if (targetConstructorElement)
                        {
                            std::u32string targetAttr = targetConstructorElement->GetAttribute(U"target");
                            if (targetAttr.empty())
                            {
                                elementsToRemove.push_back(targetConstructorElement);
                                elementsToAdd.push_back(constructorElement);
                            }
                        }
                        else
                        {
                            elementsToAdd.push_back(constructorElement);
                        }
                    }
                }
            }
        }
    }
    for (sngxml::dom::Element* elementToRemove : elementsToRemove)
    {
        RemoveElement(elementToRemove);
    }
    for (sngxml::dom::Element* elementToAdd : elementsToAdd)
    {
        AddElement(elementToAdd, nullptr, targetDoc, true, U"constructors");
    }
}

void MergeFunctions(sngxml::dom::Element* sourceElement, sngxml::dom::Document* targetDoc)
{
    std::vector<sngxml::dom::Element*> elementsToRemove;
    std::vector<sngxml::dom::Element*> elementsToAdd;
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"functions/function", sourceElement);
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* functionElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string functionId = functionElement->GetAttribute(U"id");
                    if (!functionId.empty())
                    {
                        sngxml::dom::Element* targetFunctionElement = targetDoc->GetElementById(functionId);
                        if (targetFunctionElement)
                        {
                            std::u32string targetAttr = targetFunctionElement->GetAttribute(U"target");
                            if (targetAttr.empty())
                            {
                                elementsToRemove.push_back(targetFunctionElement);
                                elementsToAdd.push_back(functionElement);
                            }
                        }
                        else
                        {
                            elementsToAdd.push_back(functionElement);
                        }
                    }
                }
            }
        }
    }
    for (sngxml::dom::Element* elementToRemove : elementsToRemove)
    {
        RemoveElement(elementToRemove);
    }
    for (sngxml::dom::Element* elementToAdd : elementsToAdd)
    {
        AddElement(elementToAdd, nullptr, targetDoc, true, U"functions");
    }
}

void MergeTypedefs(sngxml::dom::Element* sourceElement, sngxml::dom::Document* targetDoc)
{
    std::vector<sngxml::dom::Element*> elementsToRemove;
    std::vector<sngxml::dom::Element*> elementsToAdd;
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"typedefs/typedef", sourceElement);
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* typedefElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string typedefId = typedefElement->GetAttribute(U"id");
                    if (!typedefId.empty())
                    {
                        sngxml::dom::Element* targetTypedefElement = targetDoc->GetElementById(typedefId);
                        if (targetTypedefElement)
                        {
                            std::u32string targetAttr = targetTypedefElement->GetAttribute(U"target");
                            if (targetAttr.empty())
                            {
                                elementsToRemove.push_back(targetTypedefElement);
                                elementsToAdd.push_back(typedefElement);
                            }
                        }
                        else
                        {
                            elementsToAdd.push_back(typedefElement);
                        }
                    }
                }
            }
        }
    }
    for (sngxml::dom::Element* elementToRemove : elementsToRemove)
    {
        RemoveElement(elementToRemove);
    }
    for (sngxml::dom::Element* elementToAdd : elementsToAdd)
    {
        AddElement(elementToAdd, nullptr, targetDoc, true, U"typedefs");
    }
}

void MergeClasses(sngxml::dom::Element* sourceElement, sngxml::dom::Document* targetDoc)
{
    std::vector<sngxml::dom::Element*> elementsToRemove;
    std::vector<sngxml::dom::Element*> elementsToAdd;
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"classes/class", sourceElement);
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* classElement = static_cast<sngxml::dom::Element*>(node);
                    std::u32string classId = classElement->GetAttribute(U"id");
                    if (!classId.empty())
                    {
                        sngxml::dom::Element* targetClassElement = targetDoc->GetElementById(classId);
                        if (targetClassElement)
                        {
                            std::u32string targetAttr = targetClassElement->GetAttribute(U"target");
                            if (targetAttr.empty())
                            {
                                elementsToRemove.push_back(targetClassElement);
                                elementsToAdd.push_back(classElement);
                            }
                        }
                        else
                        {
                            elementsToAdd.push_back(classElement);
                        }
                    }
                    MergeClasses(classElement, targetDoc);
                    MergeConstructors(classElement, targetDoc);
                    MergeFunctions(classElement, targetDoc);
                    MergeTypedefs(classElement, targetDoc);
                }
            }
        }
    }
    for (sngxml::dom::Element* elementToRemove : elementsToRemove)
    {
        RemoveElement(elementToRemove);
    }
    for (sngxml::dom::Element* elementToAdd : elementsToAdd)
    {
        AddElement(elementToAdd, nullptr, targetDoc, true, U"classes");
    }
}

void MergeTypes(sngxml::dom::Element* sourceElement, sngxml::dom::Document* targetDoc)
{
    std::vector<sngxml::dom::Element*> elementsToRemove;
    std::vector<sngxml::dom::Element*> elementsToAdd;
    std::unique_ptr<sngxml::xpath::XPathObject> result = sngxml::xpath::Evaluate(U"types", sourceElement);
    if (result)
    {
        if (result->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(result.get());
            int n = nodeSet->Length();
            if (n == 1)
            {
                sngxml::dom::Node* node = (*nodeSet)[0];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* typesElement = static_cast<sngxml::dom::Element*>(node);
                    sngxml::dom::Node* typeNode = typesElement->FirstChild();
                    while (typeNode)
                    {
                        if (typeNode->GetNodeType() == sngxml::dom::NodeType::elementNode)
                        {
                            sngxml::dom::Element* typeElement = static_cast<sngxml::dom::Element*>(typeNode);
                            std::u32string typeId = typeElement->GetAttribute(U"id");
                            if (!typeId.empty())
                            {
                                sngxml::dom::Element* targetTypeElement = targetDoc->GetElementById(typeId);
                                if (targetTypeElement)
                                {
                                    std::u32string targetAttr = targetTypeElement->GetAttribute(U"target");
                                    if (targetAttr.empty())
                                    {
                                        elementsToRemove.push_back(targetTypeElement);
                                        elementsToAdd.push_back(typeElement);
                                    }
                                }
                                else
                                {
                                    elementsToAdd.push_back(typeElement);
                                }
                            }
                        }
                        typeNode = typeNode->NextSibling();
                    }
                }
            }
        }
    }
    for (sngxml::dom::Element* elementToRemove : elementsToRemove)
    {
        RemoveElement(elementToRemove);
    }
    std::unique_ptr<sngxml::xpath::XPathObject> targetResult = sngxml::xpath::Evaluate(U"types", targetDoc->DocumentElement());
    if (targetResult)
    {
        if (targetResult->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(targetResult.get());
            int n = nodeSet->Length();
            if (n == 1)
            {
                sngxml::dom::Node* node = (*nodeSet)[0];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* typesElement = static_cast<sngxml::dom::Element*>(node);
                    for (sngxml::dom::Element* elementToAdd : elementsToAdd)
                    {
                        typesElement->AppendChild(elementToAdd->CloneNode(true));
                    }
                }
            }
        }
    }
}

std::unique_ptr<sngxml::dom::Document> Merge(sngxml::dom::Document* symbolTableXmlDoc, std::unique_ptr<sngxml::dom::Document>& stageSymbolTableXmlDoc)
{
    std::unique_ptr<sngxml::xpath::XPathObject> ns = sngxml::xpath::Evaluate(U"//namespace", symbolTableXmlDoc);
    if (ns)
    {
        if (ns->Type() == sngxml::xpath::XPathObjectType::nodeSet)
        {
            sngxml::xpath::XPathNodeSet* nodeSet = static_cast<sngxml::xpath::XPathNodeSet*>(ns.get());
            int n = nodeSet->Length();
            for (int i = 0; i < n; ++i)
            {
                sngxml::dom::Node* node = (*nodeSet)[i];
                if (node->GetNodeType() == sngxml::dom::NodeType::elementNode)
                {
                    sngxml::dom::Element* element = static_cast<sngxml::dom::Element*>(node);
                    MergeClasses(element, stageSymbolTableXmlDoc.get());
                    MergeFunctions(element, stageSymbolTableXmlDoc.get());
                    MergeTypedefs(element, stageSymbolTableXmlDoc.get());
                }
            }
        }
    }
    MergeTypes(symbolTableXmlDoc->DocumentElement(), stageSymbolTableXmlDoc.get());
    std::unique_ptr<sngxml::dom::Document> result;
    result = std::move(stageSymbolTableXmlDoc);
    return result;
}

} // namespace cpp2cm

