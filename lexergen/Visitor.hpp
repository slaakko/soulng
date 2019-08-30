// =================================
// Copyright (c) 2019 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_LEXERGEN_VISITOR_INCLUDED
#define SOULNG_LEXERGEN_VISITOR_INCLUDED

namespace soulng { namespace lexergen {

class Char;
class Any;
class Range;
class Class;

class Visitor
{
public:
    virtual void Visit(Char& c);
    virtual void Visit(Any& a);
    virtual void Visit(Range& r);
    virtual void Visit(Class& c);
};

} } // namespace soulng::lexergen

#endif // SOULNG_LEXERGEN_VISITOR_INCLUDED
