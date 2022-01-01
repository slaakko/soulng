// =================================
// Copyright (c) 2022 Seppo Laakko
// Distributed under the MIT license
// =================================

#ifndef SOULNG_SLG_VISITOR_INCLUDED
#define SOULNG_SLG_VISITOR_INCLUDED

namespace soulng { namespace slg {

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

} } // namespace soulng::slg

#endif // SOULNG_SLG_VISITOR_INCLUDED
