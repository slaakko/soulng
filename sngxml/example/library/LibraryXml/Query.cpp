#include <LibraryXml/Query.hpp>
#include <LibraryXml/Library.hpp>
#include <Query/QueryTarget.hpp>

namespace library_xml
{
    unique_xml_ptr<QueryResult> Execute(query::QueryExprNode* query, Library* library)
    {
        unique_xml_ptr<QueryResult> result(new QueryResult());
        result->SetRandomObjectId();
        try
        {
            query::QueryContext context;
            context.Stack().Push(new query::TargetQueryValue(library));
            query->Evaluate(context);
            std::unique_ptr<query::QueryValue> value = context.Stack().Pop();
            if (value->Kind() == query::QueryValueKind::list)
            {
                query::ListQueryValue* list = static_cast<query::ListQueryValue*>(value.get());
                for (query::QueryTarget* queryTarget : list->Value())
                {
                    if (Object* obj = dynamic_cast<Object*>(queryTarget))
                    {
                        result->objects.push_back(xml_ptr<Object>(obj));
                    }
                }
                result->count = result->objects.size();
            }
            else
            {
                throw std::runtime_error("list expected");
            }
        }
        catch (const std::runtime_error& ex)
        {
            result->error = ex.what();
        }
        return result;
    }
}
