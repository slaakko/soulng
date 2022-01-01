// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SNGCPP_PARSER_PARSING_CONTEXT_INCLUDED
#define SNGCPP_PARSER_PARSING_CONTEXT_INCLUDED
#include <sngcpp/parser/ParserApi.hpp>
#include <sngcpp/ast/SourceFile.hpp>
#include <stack>

namespace sngcpp { namespace cppparser {

using namespace sngcpp::ast;

class SNGCPP_PARSER_API ParsingContext
{
public:
    ParsingContext();
    bool ParsingTemplateId() const { return parsingTemplateId; }
    void BeginParsingTemplateId();
    void EndParsingTemplateId();
    bool InFunctionBody() const { return inFunctionBody; }
    void BeginFunctionBody();
    void EndFunctionBody();
    bool ParsingLvalue() const { return parsingLvalue; }
    void BeginParsingLvalue();
    void EndParsingLvalue();
    bool ParsingArguments() const { return parsingArguments; }
    void BeginParsingArguments();
    void EndParsingArguments();
    bool ParsingTemplateIdOrLvalue() const { return parsingTemplateId || parsingLvalue; }
    bool ParsingTemplateIdOrLvalueAndNotArguments() const { return (parsingTemplateId || parsingLvalue) && !parsingArguments; }
    bool ParsingLvalueAndNotArguments() const { return parsingLvalue && !parsingArguments; }
    void SetSourceFileNode(SourceFileNode* sourceFileNode_) { sourceFileNode = sourceFileNode_; }
    SourceFileNode* GetSourceFileNode() { return sourceFileNode; }
private:
    bool parsingTemplateId;
    std::stack<bool> parsingTemplateIdStack;
    bool inFunctionBody;
    std::stack<bool> inFunctionBodyStack;
    bool parsingLvalue;
    std::stack<bool> parsingLvalueStack;
    bool parsingArguments;
    std::stack<bool> parsingArgumentsStack;
    SourceFileNode* sourceFileNode;
};

} } // namespace sngcpp::cppparser

#endif // SNGCPP_PARSER_PARSING_CONTEXT_INCLUDED
