// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef TOKENS_HPP
#define TOKENS_HPP
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace soulng { namespace spg {

const int nullTokenId = 0;

struct Token
{
    Token(const std::string& name_, int id_);
    std::string name;
    int id;
};

class TokenSet
{
public:
    TokenSet();
    const std::vector<Token*>& Tokens() const { return  tokens; }
    bool AddToken(Token* token);
    bool RemoveToken(Token* token);
    bool Member(Token* token) const;
    bool IsEmpty() const { return tokens.empty(); }
    int Count() const { return tokens.size(); }
    std::string ToString() const;
private:
    std::vector<Token*> tokens;
};

bool operator==(const TokenSet& left, const TokenSet& right);
inline bool operator!=(const TokenSet& left, const TokenSet& right)
{
    return  !(left == right);
}

TokenSet operator+(const TokenSet& left, const TokenSet& right);
TokenSet operator-(const TokenSet& left, const TokenSet& right);

class Tokens
{
public:
    Tokens();
    Tokens(const std::string& filePath);
    void AddToken(Token* token);
    bool HasToken(int id) const;
    Token* GetToken(int id) const;
    Token* GetToken(const std::string& name) const;
    TokenSet GetAll() const;
private:
    std::map<int, Token*> idTokenMap;
    std::map<std::string, Token*> nameTokenMap;
    std::vector<std::unique_ptr<Token>> tokens;
};

} } // namespapce soulng::spg

#endif // TOKENS_HPP
