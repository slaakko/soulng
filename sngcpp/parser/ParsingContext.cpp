// =================================
// Copyright (c) 2020 Seppo Laakko
// Distributed under the MIT license
// =================================

#include <sngcpp/parser/ParsingContext.hpp>

namespace sngcpp { namespace cppparser {

ParsingContext::ParsingContext() : parsingTemplateId(false), inFunctionBody(false), sourceFileNode(nullptr), parsingLvalue(false), parsingArguments(false)
{
}

void ParsingContext::BeginParsingTemplateId()
{
    parsingTemplateIdStack.push(parsingTemplateId);
    parsingTemplateId = true;
}

void ParsingContext::EndParsingTemplateId()
{
    parsingTemplateId = parsingTemplateIdStack.top();
    parsingTemplateIdStack.pop();
}

void ParsingContext::BeginFunctionBody()
{
    inFunctionBodyStack.push(inFunctionBody);
    inFunctionBody = true;
}

void ParsingContext::EndFunctionBody()
{
    inFunctionBody = inFunctionBodyStack.top();
    inFunctionBodyStack.pop();
}

void ParsingContext::BeginParsingLvalue()
{
    parsingLvalueStack.push(parsingLvalue);
    parsingLvalue = true;
}

void ParsingContext::EndParsingLvalue()
{
    parsingLvalue = parsingLvalueStack.top();
    parsingLvalueStack.pop();
}

void ParsingContext::BeginParsingArguments()
{
    parsingArgumentsStack.push(parsingArguments);
    parsingArguments = true;
}

void ParsingContext::EndParsingArguments()
{
    parsingArguments = parsingArgumentsStack.top();
    parsingArgumentsStack.pop();
}

} } // namespace sngcpp::cppparser
