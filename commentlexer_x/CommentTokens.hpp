#ifndef CommentTokens_HPP
#define CommentTokens_HPP

#undef NULL

namespace CommentTokens
{
    const int END = 0;
    const int ID = 1;

    int GetTokenId(const std::u32string& tokenName);
    const char* GetTokenName(int tokenId);
    const char* GetTokenInfo(int tokenId);
}
#endif
