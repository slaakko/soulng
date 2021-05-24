// =================================
// Copyright (c) 2021 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp20/pp/Macro.hpp>
#include <sngcpp20/pp/PPTokens.hpp>
#include <sngcpp20/pp/TextTokens.hpp>
#include <sngcpp20/pp/Util.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/util/TextUtils.hpp>

namespace sngcpp::pp {

using namespace soulng::unicode;

int GetMacroArguments(FunctionMacro* macro, int i, int e, const std::vector<Token>& tokens, soulng::lexer::Lexer* lexer, std::vector<MacroArgument>& arguments, PP* pp, bool& end)
{
    MacroArgument argument;
    int parenCount = 0;
    while (lexer != nullptr && !end || i != e)
    {
        Token token;
        if (lexer)
        {
            token = lexer->GetToken(i);
        }
        else
        {
            token = tokens[i];
        }
        switch (token.id)
        {
            case TextTokens::LPAREN:
            {
                if (parenCount > 0)
                {
                    argument.tokens.push_back(token);
                }
                ++parenCount;
                break;
            }
            case TextTokens::RPAREN:
            {
                if (parenCount > 0)
                {
                    --parenCount;
                    if (parenCount == 0)
                    {
                        if (!argument.tokens.empty())
                        {
                            argument.tokens = TrimTextTokens(argument.tokens);
                            arguments.push_back(argument);
                        }
                        return i;
                    }
                    else
                    {
                        argument.tokens.push_back(token);
                    }
                }
                else
                {
                    std::string error = "error: invalid invocation of function macro '" + ToUtf8(macro->Name().ToString()) + "': unexpected right parenthesis in '" +
                        pp->FileName() + ":" + std::to_string(pp->GetLineIndex() + 1) + "'";
                    pp->AddError(error);
                    return e;
                }
                break;
            }
            case TextTokens::COMMA:
            {
                if (parenCount == 1)
                {
                    argument.tokens = TrimTextTokens(argument.tokens);
                    arguments.push_back(argument);
                    argument = MacroArgument();
                }
                else if (parenCount > 1)
                {
                    argument.tokens.push_back(token);
                }
                else
                {
                    std::string error = "error: invalid invocation of function macro '" + ToUtf8(macro->Name().ToString()) + "': unexpected comma in '" +
                        pp->FileName() + ":" + std::to_string(pp->GetLineIndex() + 1) + "'";
                    pp->AddError(error);
                    return e;
                }
                break;
            }
            case TextTokens::NEWLINE:
            {
                pp->SetLineNumber(pp->LineNumber() + 1);
                pp->SetLineIndex(pp->GetLineIndex() + 1);
                break;
            }
            case TextTokens::END:
            {
                end = true;
                break;
            }
            default:
            {
                if (parenCount > 0)
                {
                    argument.tokens.push_back(token);
                }
                else if (macro->IsVariableArgs())
                {
                    argument.tokens.push_back(token);
                }
                else
                {
                    std::string error = "error: invalid invocation of function macro '" + ToUtf8(macro->Name().ToString()) + "': unexpected token in '" +
                        pp->FileName() + ":" + std::to_string(pp->GetLineIndex() + 1) + "'";
                    pp->AddError(error);
                    return e;
                }
                break;
            }
        }
        if (!end)
        {
            ++i;
            if (lexer)
            {
                ++(*lexer);
            }
        }
    }
    return e;
}

Macro::Macro(const Lexeme& name_, const std::string& fileName_, int lineNumber_, const std::u32string& defitionStr_) : 
    name(name_), fileName(fileName_), lineNumber(lineNumber_),  definitionStr(defitionStr_)
{
}

Macro::~Macro()
{
}

int Macro::Expand(int i, int e, const std::vector<Token>& tokens, soulng::lexer::Lexer* lexer, std::vector<Token>& expandedTokens, PP* pp, bool& end)
{
    return i;
}

ObjectMacro::ObjectMacro(const Lexeme& name_, const std::string& fileName_, int lineNumber_, const std::vector<Token>& replacementList_, const std::u32string& definitionStr_) :
    Macro(name_, fileName_, lineNumber_, definitionStr_), replacementList(replacementList_)
{
}

void ObjectMacro::SetValue(const Token& value)
{
    std::vector<Token> rl;
    rl.push_back(value);
    SetReplacementList(rl);
}

void ObjectMacro::SetReplacementList(const std::vector<Token>& replacementList_)
{
    replacementList = replacementList_;
}

int ObjectMacro::Expand(int i, int e, const std::vector<Token>& tokens, soulng::lexer::Lexer* lexer, std::vector<Token>& expandedTokens, PP* pp, bool& end)
{
    for (const Token& token : replacementList)
    {
        expandedTokens.push_back(token);
    }
    return i;
}

std::string ObjectMacro::ToString() const
{
    std::string s = ToUtf8(Name().ToString());
    s.append(1, '=');
    for (const Token& token : replacementList)
    {
        s.append(ToUtf8(token.match.ToString()));
    }
    return s;
}

FunctionMacro::FunctionMacro(const Lexeme& name_, const std::string& fileName_, int lineNumber_, const std::vector<Token>& paramList_, const std::vector<Token>& replacementList_,
    const std::u32string& definitionStr_, PP* pp) :
    Macro(name_, fileName_, lineNumber_, definitionStr_), paramList(paramList_), replacementList(replacementList_), variableArgs(false)
{
    int n = paramList.size();
    for (int i = 0; i < n; ++i)
    {
        const Token& param = paramList[i];
        if (param.id == PPTokens::ELLIPSES)
        {
            variableArgs = true;
            for (int j = i + 1; j < n; ++j)
            {
                if (paramList[j].id == PPTokens::ELLIPSES)
                {
                    std::string error = "error: multiple ellipses parameter in variable argument function macro definition '" + ToUtf8(Name().ToString());
                    pp->AddError(error);
                    return;
                }
                else 
                {
                    std::string error = "error: ellipses is not last parameter in variable argument function macro definition '" + ToUtf8(Name().ToString());
                    pp->AddError(error);
                    return;
                }
            }
            paramList.erase(paramList.begin() + i, paramList.end());
        }
    }
}

bool FunctionMacro::MakeParamIndexMap()
{
    int n = paramList.size();
    for (int i = 0; i < n; ++i)
    {
        Token param = paramList[i];
        if (paramIndexMap.find(param.match) != paramIndexMap.cend())
        {
            return false;
        }
        paramIndexMap[param.match] = i;
    }
    return true;
}

int FunctionMacro::GetParamIndex(const Lexeme& id) const
{
    auto it = paramIndexMap.find(id);
    if (it != paramIndexMap.cend())
    {
        return it->second;
    }
    else
    {
        return -1;
    }
}

int FunctionMacro::Expand(int i, int e, const std::vector<Token>& tokens, soulng::lexer::Lexer* lexer, std::vector<Token>& expandedTokens, PP* pp, bool& end)
{
    if (lexer)
    {
        ++(*lexer);
        ++i;
    }
    else if (i != e)
    {
        ++i;
    }
    if (i != e || lexer != nullptr)
    {
        std::vector<MacroArgument> args;
        std::vector<MacroArgument> variableArgs;
        i = GetMacroArguments(this, i, e, tokens, lexer, args, pp, end);
        if (end)
        {
            return e;
        }
        if (IsVariableArgs())
        {
            if (args.size() < paramList.size())
            {
                std::string error = "invalid invocation of variable argument function macro '" + ToUtf8(Name().ToString()) + "' in '" + pp->FileName() + ":" + std::to_string(pp->GetLineIndex() + 1) +
                    "': too few arguments: note: definition in '" + FileName() + ":" + std::to_string(LineNumber()) + "'";
                pp->AddError(error);
                return e;
            }
            else
            {
                for (int i = paramList.size(); i < args.size(); ++i)
                {
                    variableArgs.push_back(args[i]);
                }
                args.erase(args.begin() + paramList.size(), args.end());
            }
        }
        else
        {
            if (args.size() != paramList.size())
            {
                std::string error = "invalid invocation of function macro '" + ToUtf8(Name().ToString()) + "' in '" + pp->FileName() + ":" + std::to_string(pp->GetLineIndex() + 1) +
                    "': wrong number of arguments: note: definition in '" + FileName() + ":" + std::to_string(LineNumber()) + "'";
                pp->AddError(error);
                return e;
            }
        }
        std::vector<Token>::const_iterator ri = replacementList.cbegin();
        std::vector<Token>::const_iterator re = replacementList.cend();
        bool prevWasHash = false;
        bool prevWasHashHash = false;
        while (ri != re)
        {
            Token token = *ri;
            switch (token.id)
            {
                case TextTokens::HASH:
                {
                    if (prevWasHash)
                    {
                        std::string error = "two concecutive separate # operators in a replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " + 
                            FileName() + ":" + std::to_string(LineNumber());
                        pp->AddError(error);
                        return e;
                    }
                    else if (prevWasHashHash)
                    {
                        std::string error = "## operator cannot be followed by a # operator: see replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " +
                            FileName() + ":" + std::to_string(LineNumber());
                        pp->AddError(error);
                        return e;
                    }
                    prevWasHash = true;
                    break;
                }
                case TextTokens::HASHHASH:
                {
                    if (prevWasHash)
                    {
                        std::string error = "# operator cannot be followed by a ## operator: see replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " +
                            FileName() + ":" + std::to_string(LineNumber());
                        pp->AddError(error);
                        return e;
                    }
                    else if (prevWasHashHash)
                    {
                        std::string error = "two concecutive ## operators in a replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " +
                            FileName() + ":" + std::to_string(LineNumber());
                        pp->AddError(error);
                        return e;
                    }
                    expandedTokens.push_back(token);
                    prevWasHashHash = true;
                    break;
                }
                case TextTokens::ID:
                {
                    if (token.match == Name())
                    {
                        if (prevWasHash)
                        {
                            std::string error = "# operator must be followed by a parameter: see replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " +
                                FileName() + ":" + std::to_string(LineNumber());
                            pp->AddError(error);
                            return e;
                        }
                        else
                        {
                            expandedTokens.push_back(token);
                        }
                    }
                    else
                    {
                        if (token.match.ToString() == U"__VA_ARGS__")
                        {
                            if (IsVariableArgs())
                            {
                                for (const MacroArgument& arg : variableArgs)
                                {
                                    for (const Token& t : arg.tokens)
                                    {
                                        expandedTokens.push_back(t);
                                    }
                                }
                            }
                            else
                            {
                                std::string error = "__VA_ARGS__ used in non-variable-argument function macro: see replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " +
                                    FileName() + ":" + std::to_string(LineNumber());
                                pp->AddError(error);
                                return e;
                            }
                        }
                        else
                        {
                            int index = GetParamIndex(token.match);
                            if (index == -1)
                            {
                                if (prevWasHash)
                                {
                                    std::string error = "# operator must be followed by a parameter: see replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " +
                                        FileName() + ":" + std::to_string(LineNumber());
                                    pp->AddError(error);
                                    return e;
                                }
                                expandedTokens.push_back(token);
                            }
                            else
                            {
                                if (index >= 0 && index < args.size())
                                {
                                    MacroArgument arg = args[index];
                                    if (prevWasHash)
                                    {
                                        arg.tokens = std::vector<Token>(1, Stringize(TrimTextTokens(arg.tokens), pp));
                                    }
                                    if (arg.tokens.empty())
                                    {
                                        arg.tokens.push_back(Token(TextTokens::PLACEMARKER, Lexeme(), pp->GetLineIndex() + 1));
                                    }
                                    for (const Token& t : arg.tokens)
                                    {
                                        expandedTokens.push_back(t);
                                    }
                                }
                                else
                                {
                                    std::string error = "invalid invocation of function macro '" + ToUtf8(Name().ToString()) + "' in '" + pp->FileName() + ":" + std::to_string(pp->GetLineIndex() + 1) +
                                        "': invalid argument index " + std::to_string(index) + ": note: definition in '" + FileName() + ":" + std::to_string(LineNumber()) + "'";
                                    pp->AddError(error);
                                    return e;
                                }
                            }
                        }
                    }
                    prevWasHash = false;
                    prevWasHashHash = false;
                    break;
                }
                case TextTokens::WS:
                {
                    expandedTokens.push_back(token);
                    break;
                }
                default:
                {
                    if (prevWasHash)
                    {
                        std::string error = "# operator must be followed by a parameter: see replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " +
                            FileName() + ":" + std::to_string(LineNumber());
                        pp->AddError(error);
                        return e;
                    }
                    if (prevWasHashHash)
                    {
                        std::string error = "## operator must be followed by a parameter: see replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " +
                            FileName() + ":" + std::to_string(LineNumber());
                        pp->AddError(error);
                        return e;
                    }
                    expandedTokens.push_back(token);
                    prevWasHash = false;
                    prevWasHashHash = false;
                    break;
                }
            }
            ++ri;
        }
        if (prevWasHash)
        {
            std::string error = "# operator must be followed by a parameter: see replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " +
                FileName() + ":" + std::to_string(LineNumber());
            pp->AddError(error);
            return e;
        }
        if (prevWasHashHash)
        {
            std::string error = "## operator must be followed by a parameter: see replacement list of function macro '" + ToUtf8(Name().ToString()) + "': " +
                FileName() + ":" + std::to_string(LineNumber());
            pp->AddError(error);
            return e;
        }
    }
    return i;
}

std::string FunctionMacro::ToString() const
{
    std::string s = ToUtf8(Name().ToString());
    s.append(1, '(');
    bool first = true;
    for (const Token& param : paramList)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            s.append(", ");
        }
        s.append(ToUtf8(param.match.ToString()));
    }
    s.append(1, ')');
    s.append(1, '=');
    for (const Token& token : replacementList)
    {
        s.append(ToUtf8(token.match.ToString()));
    }
    return s;
}


std::u32string ToString(const std::vector<Token>& replacementList)
{
    std::u32string s;
    for (const Token& token : replacementList)
    {
        s.append(token.match.ToString());
    }
    return s;
}

std::u32string NoCommentString(const std::vector<Token>& replacementList)
{
    std::u32string s;
    for (const Token& token : replacementList)
    {
        if (token.id == TextTokens::LINECOMMENT || token.id == TextTokens::BLOCKCOMMENT) continue;
        s.append(token.match.ToString());
    }
    return Trim(s);
}

} // namespace sngcpp::pp
