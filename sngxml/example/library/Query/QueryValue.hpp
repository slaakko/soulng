#ifndef QUERY_QUERY_VALUE_INCLUDED
#define QUERY_QUERY_VALUE_INCLUDED
#include <Query/Api.hpp>
#include <soulng/rex/Context.hpp>
#include <soulng/util/Time.hpp>
#include <string>
#include <stack>
#include <memory>

namespace query
{
    class QueryTarget;

    enum class QueryValueKind
    {
        boolean, integer, string, date, target, list
    };

    QUERY_API std::string QueryValueKindStr(QueryValueKind kind);

    class QUERY_API QueryValue
    {
    public:
        QueryValue(QueryValueKind kind_);
        virtual ~QueryValue();
        QueryValueKind Kind() const { return kind; }
    private:
        QueryValueKind kind;
    };
    
    class QUERY_API BooleanQueryValue : public QueryValue
    {
    public:
        BooleanQueryValue(bool value_);
        bool Value() const { return value; }
    private:
        bool value;
    };

    class QUERY_API IntegerQueryValue : public QueryValue
    {
    public:
        IntegerQueryValue(int value_);
        int Value() const { return value; }
    private:
        int value;
    };

    class QUERY_API StringQueryValue : public QueryValue
    {
    public:
        StringQueryValue(const std::u32string& value_);
        const std::u32string& Value()  const { return value; }
    private:
        std::u32string value;
    };

    class QUERY_API DateQueryValue : public QueryValue
    {
    public:
        DateQueryValue(const soulng::util::Date& value_);
        const soulng::util::Date& Value()  const { return value; }
    private:
        soulng::util::Date value;
    };

    class QUERY_API TargetQueryValue : public QueryValue
    {
    public:
        TargetQueryValue(QueryTarget* target_);
        QueryTarget* Value() const { return target; }
    private:
        QueryTarget* target;
    };

    class QUERY_API ListQueryValue : public QueryValue
    {
    public:
        ListQueryValue(const std::vector<QueryTarget*>& list_);
        const std::vector<QueryTarget*>& Value() const { return list; }
    private:
        std::vector<QueryTarget*> list;
    };

    class QUERY_API QueryValueStack
    {
    public:
        QueryValueStack();
        QueryValueStack(const QueryValueStack&) = delete;
        QueryValueStack& operator=(const QueryValueStack&) = delete;
        void Push(QueryValue* value);
        std::unique_ptr<QueryValue> Pop();
    private:
        std::stack<std::unique_ptr<QueryValue>> stack;
    };

    class QUERY_API QueryContext
    {
    public:
        QueryContext();
        soulng::rex::Context& RexContext() { return rexContext; }
        QueryValueStack& Stack() { return stack; }
        void SetVariable(const std::u32string& name, QueryTarget* value);
        QueryTarget* GetVariable(const std::u32string& name) const;
    private:
        QueryValueStack stack;
        soulng::rex::Context rexContext;
        std::map<std::u32string, QueryTarget*> variableMap;
    };

}

#endif // QUERY_QUERY_VALUE_INCLUDED
