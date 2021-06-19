
// this file has been automatically generated from 'C:/work/soulng/sngcpp20/lexer/CppTokenLexer.lexer' using soulng lexer generator slg version 4.0.0

#include <sngcpp20/lexer/CppTokenLexerKeywords.hpp>
#include <sngcpp20/lexer/CppTokenLexerTokens.hpp>

namespace CppTokenLexerKeywords
{
    using namespace CppTokenLexerTokens;

    Keyword keywords[] =
    {
        {U"alignas", ALIGNAS}, 
        {U"alignof", ALIGNOF}, 
        {U"asm", ASM}, 
        {U"auto", AUTO}, 
        {U"bool", BOOL}, 
        {U"break", BREAK}, 
        {U"case", CASE}, 
        {U"catch", CATCH}, 
        {U"char", CHAR}, 
        {U"char8_t", CHAR8_T}, 
        {U"char16_t", CHAR16_T}, 
        {U"char32_t", CHAR32_T}, 
        {U"class", CLASS}, 
        {U"concept", CONCEPT}, 
        {U"const", CONST}, 
        {U"consteval", CONSTEVAL}, 
        {U"constexpr", CONSTEXPR}, 
        {U"constinit", CONSTINIT}, 
        {U"const_cast", CONST_CAST}, 
        {U"continue", CONTINUE}, 
        {U"co_await", CO_AWAIT}, 
        {U"co_return", CO_RETURN}, 
        {U"co_yield", CO_YIELD}, 
        {U"decltype", DECLTYPE}, 
        {U"default", DEFAULT}, 
        {U"delete", DELETE}, 
        {U"do", DO}, 
        {U"double", DOUBLE}, 
        {U"dynamic_cast", DYNAMIC_CAST}, 
        {U"else", ELSE}, 
        {U"enum", ENUM}, 
        {U"explicit", EXPLICIT}, 
        {U"export", EXPORT}, 
        {U"extern", EXTERN}, 
        {U"false", FALSE}, 
        {U"float", FLOAT}, 
        {U"for", FOR}, 
        {U"friend", FRIEND}, 
        {U"goto", GOTO}, 
        {U"if", IF}, 
        {U"inline", INLINE}, 
        {U"int", INT}, 
        {U"long", LONG}, 
        {U"mutable", MUTABLE}, 
        {U"namespace", NAMESPACE}, 
        {U"new", NEW}, 
        {U"noexcept", NOEXCEPT}, 
        {U"nullptr", NULLPTR}, 
        {U"operator", OPERATOR}, 
        {U"private", PRIVATE}, 
        {U"protected", PROTECTED}, 
        {U"public", PUBLIC}, 
        {U"register", REGISTER}, 
        {U"reinterpret_cast", REINTERPRET_CAST}, 
        {U"requires", REQUIRES}, 
        {U"return", RETURN}, 
        {U"short", SHORT}, 
        {U"signed", SIGNED}, 
        {U"sizeof", SIZEOF}, 
        {U"static", STATIC}, 
        {U"static_assert", STATIC_ASSERT}, 
        {U"static_cast", STATIC_CAST}, 
        {U"struct", STRUCT}, 
        {U"switch", SWITCH}, 
        {U"template", TEMPLATE}, 
        {U"this", THIS}, 
        {U"thread_local", THREAD_LOCAL}, 
        {U"throw", THROW}, 
        {U"true", TRUE}, 
        {U"try", TRY}, 
        {U"typedef", TYPEDEF}, 
        {U"typeid", TYPEID}, 
        {U"typename", TYPENAME}, 
        {U"union", UNION}, 
        {U"unsigned", UNSIGNED}, 
        {U"using", USING}, 
        {U"virtual", VIRTUAL}, 
        {U"void", VOID}, 
        {U"volatile", VOLATILE}, 
        {U"wchar_t", WCHAR_T}, 
        {U"while", WHILE}, 
        {U"__thread", __THREAD}, 
        {U"__declspec", __DECLSPEC}, 
        {U"__cdecl", __CDECL}, 
        {U"__fastcall", __FASTCALL}, 
        {U"__stdcall", __STDCALL}, 
        {U"__int64", __INT64}, 
        {U"__unaligned", __UNALIGNED},
        {nullptr, -1}
    };

    KeywordMap keywordMap(keywords);

    KeywordMap* GetKeywordMap()
    {
        return &keywordMap;
    }
}
