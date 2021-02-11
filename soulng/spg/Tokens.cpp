// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <soulng/spg/Tokens.hpp>
#include <soulng/util/TextUtils.hpp>
#include <boost/lexical_cast.hpp>
#include <algorithm>
#include <fstream>

namespace soulng { namespace spg {

using namespace soulng::util;

Token::Token(const std::string& name_, int id_) : name(name_), id(id_)
{
}

TokenSet::TokenSet() : tokens()
{
}

std::string TokenSet::ToString() const
{
    std::string s("[");
    bool first = true;
    for (Token* token : tokens)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            s.append(", ");
        }
        s.append(token->name);
    }
    s.append("]");
    return s;
}

bool TokenSet::AddToken(Token* token)
{
    for (Token* t : tokens)
    {
        if (t == token) return false;
    }
    tokens.push_back(token);
    return true;
}

bool TokenSet::RemoveToken(Token* token)
{
    std::vector<Token*>::iterator it = std::remove(tokens.begin(), tokens.end(), token);
    if (it == tokens.cend()) return false;
    tokens.erase(it, tokens.cend());
    return true;
}

bool TokenSet::Member(Token* token) const
{
    for (Token* t : tokens)
    {
        if (t == token) return true;
    }
    return false;
}

TokenSet operator+(const TokenSet& left, const TokenSet& right)
{
    TokenSet unionSet = left;
    for (Token* t : right.Tokens())
    {
        unionSet.AddToken(t);
    }
    return unionSet;
}

bool operator==(const TokenSet& left, const TokenSet& right)
{
    if (left.Count() != right.Count()) return false;
    for (Token* t : left.Tokens())
    {
        if (!right.Member(t)) return  false;
    }
    for (Token* t : right.Tokens())
    {
        if (!left.Member(t)) return  false;
    }
    return true;
}

TokenSet operator-(const TokenSet& left, const TokenSet& right)
{
    TokenSet differenceSet = left;
    for (Token* t : right.Tokens())
    {
        differenceSet.RemoveToken(t);
    }
    return differenceSet;
}

void Tokens::AddToken(Token* token)
{
    idTokenMap[token->id] = token;
    nameTokenMap[token->name] = token; 
    tokens.push_back(std::unique_ptr<Token>(token));
}

bool Tokens::HasToken(int id) const
{
    return idTokenMap.find(id) != idTokenMap.cend();
}

Tokens::Tokens()
{
}

Tokens::Tokens(const std::string& filePath)
{
    std::ifstream tokenFile(filePath);
    if (!tokenFile)
    {
        throw std::runtime_error("token file '" + filePath + " not found");
    }
    std::string line;
    while (std::getline(tokenFile, line))
    {
        std::vector<std::string> components = Split(line, ':');
        if (components.size() == 2)
        {
            std::string tokenName = components[0];
            int tokenId = boost::lexical_cast<int>(components[1]);
            Token* token = new Token(tokenName, tokenId);
            idTokenMap[token->id] = token;
            nameTokenMap[token->name] = token;
            tokens.push_back(std::unique_ptr<Token>(token));
        }
        else
        {
            throw std::runtime_error("invalid token line in token file '" + filePath + "'");
        }
    }
}

Token* Tokens::GetToken(int id) const
{
    auto it = idTokenMap.find(id);
    if (it != idTokenMap.cend())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("token id " + std::to_string(id) + " not found");
    }
}

Token* Tokens::GetToken(const std::string& name) const
{
    auto it = nameTokenMap.find(name);
    if (it != nameTokenMap.cend())
    {
        return it->second;
    }
    else
    {
        throw std::runtime_error("token name '" + name + "' not found");
    }
}

TokenSet Tokens::GetAll() const
{
    TokenSet all;
    for (const std::unique_ptr<Token>& token : tokens)
    {
        all.AddToken(token.get());
    }
    return all;
}

} } // namespapce soulng::spg
