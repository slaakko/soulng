#include <Query/QueryTarget.hpp>
#include <soulng/util/Unicode.hpp>
#include <stdexcept>

namespace query
{
    using namespace soulng::unicode;

    QueryTarget::~QueryTarget()
    {
    }

    void QueryTarget::Select(QueryContext& context, const std::u32string& cls) const
    {
        context.Stack().Push(new BooleanQueryValue(false));
    }

    void QueryTarget::Member(QueryContext& context, const std::u32string& memberId) const
    {
        throw std::runtime_error(QueryClassName() + " does not have '" + ToUtf8(memberId) + "' member");
    }
}
