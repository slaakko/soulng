#ifndef QUERY_QUERY_TARGET_INCLUDED
#define QUERY_QUERY_TARGET_INCLUDED
#include <Query/QueryValue.hpp>
#include <string>

namespace query
{
    class QUERY_API QueryTarget
    {
    public:
        virtual ~QueryTarget();
        virtual std::string QueryClassName() const = 0;
        virtual void Select(QueryContext& context, const std::u32string& cls) const;
        virtual void Member(QueryContext& context, const std::u32string& memberId) const;
    };
}

#endif // QUERY_QUERY_TARGET_INCLUDED
