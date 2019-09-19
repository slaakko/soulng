#ifndef EXAMPLEAST_HPP
#define EXAMPLEAST_HPP
#include <string>

class Node
{
    // ...
};

class WhileStatementNode : public Node
{
public:
    WhileStatementNode(Node* cond_, Node* stmt_);
    // ...
};

class EmptyStatementNode : public Node
{
    // ...
};

class IdentifierNode : public Node
{
public:
    IdentifierNode(const std::u32string& str_);
};

class SymbolTable
{
    // ...
};

#endif // EXAMPLEAST_HPP
