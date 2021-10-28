#include <Query/QueryValue.hpp>

namespace query
{
    std::string QueryValueKindStr(QueryValueKind kind)
    {
        switch (kind)
        {
            case QueryValueKind::boolean: return "boolean";
            case QueryValueKind::integer: return "integer";
            case QueryValueKind::string: return "string";
            case QueryValueKind::date: return "date";
            case QueryValueKind::list: return "list";
        }
        return std::string();
    }

    QueryValue::QueryValue(QueryValueKind kind_) : kind(kind_)
    {
    }

    QueryValue::~QueryValue()
    {
    }

    BooleanQueryValue::BooleanQueryValue(bool value_) : QueryValue(QueryValueKind::boolean), value(value_)
    {
    }

    IntegerQueryValue::IntegerQueryValue(int value_) : QueryValue(QueryValueKind::integer), value(value_)
    {
    }

    StringQueryValue::StringQueryValue(const std::u32string& value_) : QueryValue(QueryValueKind::string), value(value_)
    {
    }

    DateQueryValue::DateQueryValue(const soulng::util::Date& value_) : QueryValue(QueryValueKind::date), value(value_)
    { 
    }

    TargetQueryValue::TargetQueryValue(QueryTarget* target_) : QueryValue(QueryValueKind::target), target(target_)
    {
    }

    ListQueryValue::ListQueryValue(const std::vector<QueryTarget*>& list_) : QueryValue(QueryValueKind::list), list(list_)
    {
    }

    QueryValueStack::QueryValueStack()
    {
    }

    void QueryValueStack::Push(QueryValue* value) 
    {
        stack.push(std::unique_ptr<QueryValue>(value));
    }

    std::unique_ptr<QueryValue> QueryValueStack::Pop()
    {
        if (stack.empty())
        {
            throw std::runtime_error("query evaluation stack is empty");
        }
        std::unique_ptr<QueryValue> top(std::move(stack.top()));
        stack.pop();
        return top;
    }

    QueryContext::QueryContext() : stack()
    {
    }

    void QueryContext::SetVariable(const std::u32string& name, QueryTarget* value)
    {
        variableMap[name] = value;
    }

    QueryTarget* QueryContext::GetVariable(const std::u32string& name) const
    {
        auto it = variableMap.find(name);
        if (it != variableMap.cend())
        {
            return it->second;
        }
        else
        {
            return nullptr;
        }
    }
}