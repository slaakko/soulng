// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_AST_NODE_LIST_INCLUDED
#define SNGCPP_AST_NODE_LIST_INCLUDED
#include <memory>
#include <vector>

namespace sngcpp::ast {

template<typename T>
class NodeList
{
public:
    NodeList() {}
    NodeList(const NodeList&) = delete;
    NodeList& operator=(const NodeList&) = delete;
    int Count() const { return nodes.size(); }
    bool IsEmpty() const { return nodes.empty(); }
    void Clear() { nodes.clear(); }
    T* operator[](int index) const { return nodes[index].get(); }
    void Add(T* node)
    {
        nodes.push_back(std::unique_ptr<T>(node));
    }
    T* Release(int index)
    {
        return nodes[index].release();
    }
    std::vector<std::unique_ptr<T>>& Nodes() { return nodes; }
private:
    std::vector<std::unique_ptr<T>> nodes;
};

} // namespace sngcpp::ast

#endif // SNGCPP_AST_NODE_LIST_INCLUDED
