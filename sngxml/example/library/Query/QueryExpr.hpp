#ifndef QUERYEXPR_HPP_0BD750C11930791DDFD166D67FDED0959AE65793
#define QUERYEXPR_HPP_0BD750C11930791DDFD166D67FDED0959AE65793
#include <Query/Api.hpp>
#include <Query/QueryValue.hpp>
#include <sngxml/serialization/XmlPtr.hpp>
#include <soulng/util/Time.hpp>
#include <chrono>
#include <memory>
#include <stdint.h>

namespace query {

using date = soulng::util::Date;
using datetime = soulng::util::DateTime;
using timestamp = soulng::util::Timestamp;
using time_point = std::chrono::steady_clock::time_point;
using duration = std::chrono::steady_clock::duration;
using uuid = boost::uuids::uuid;
template<class T> using xml_ptr = sngxml::xmlser::XmlPtr<T>;
template<class T> using unique_xml_ptr = sngxml::xmlser::UniqueXmlPtr<T>;

enum class Operator
{
    eq
    , ne
    , lt
    , gt
    , le
    , ge
};

enum class QueryExprNodeKind
{
    stringConv
    , get
    , or_
    , and_
    , match
    , relational
    , not_
    , member
    , paren
    , booleanLiteral
    , integerLiteral
    , stringLiteral
    , identifier
};

class QUERY_API QueryExprNode : public sngxml::xmlser::XmlSerializable
{
public:
    QueryExprNode();
    virtual ~QueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    const boost::uuids::uuid& ObjectId() const override { return objectId; }
    void SetObjectId(const boost::uuids::uuid& objectId_) override { objectId = objectId_; }
    int ClassId() const override { return classId; }
    bool IsOwned() const override { return isOwned; }
    void SetOwned() override { isOwned = true; }
    void ResetOwned() override { isOwned = false; }
    std::string ClassName() const override;
    sngxml::xmlser::XmlContainer* Container() const override { return container; }
    void SetContainer(sngxml::xmlser::XmlContainer* container_) override { container = container_; }
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    virtual void SetObjectXmlAttributes(sngxml::dom::Element* element) const;
public:
virtual void Evaluate(QueryContext& context) {}
QueryExprNodeKind Kind() const { return kind; }
    QueryExprNodeKind kind;
    void* dataPtr;
private:
    static int classId;
    boost::uuids::uuid objectId;
    sngxml::xmlser::XmlContainer* container;
    bool isOwned;
};

class QUERY_API UnaryQueryExprNode : public QueryExprNode
{
public:
    UnaryQueryExprNode();
    UnaryQueryExprNode(const UnaryQueryExprNode&) = delete;
    UnaryQueryExprNode(UnaryQueryExprNode&&) = delete;
    UnaryQueryExprNode& operator=(const UnaryQueryExprNode&) = delete;
    UnaryQueryExprNode& operator=(UnaryQueryExprNode&&) = delete;
    virtual ~UnaryQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
QueryExprNode* Child() const { return child.Get(); }
    unique_xml_ptr<QueryExprNode> child;
private:
    static int classId;
};

class QUERY_API BinaryQueryExprNode : public QueryExprNode
{
public:
    BinaryQueryExprNode();
    BinaryQueryExprNode(const BinaryQueryExprNode&) = delete;
    BinaryQueryExprNode(BinaryQueryExprNode&&) = delete;
    BinaryQueryExprNode& operator=(const BinaryQueryExprNode&) = delete;
    BinaryQueryExprNode& operator=(BinaryQueryExprNode&&) = delete;
    virtual ~BinaryQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
QueryExprNode* Left() const { return left.Get(); }
QueryExprNode* Right() const { return right.Get(); }
    unique_xml_ptr<QueryExprNode> left;
    unique_xml_ptr<QueryExprNode> right;
private:
    static int classId;
};

class QUERY_API StringConversionQueryExprNode : public UnaryQueryExprNode
{
public:
    StringConversionQueryExprNode();
    virtual ~StringConversionQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
private:
    static int classId;
};

class QUERY_API GetQueryExprNode : public QueryExprNode
{
public:
    GetQueryExprNode();
    GetQueryExprNode(const GetQueryExprNode&) = delete;
    GetQueryExprNode(GetQueryExprNode&&) = delete;
    GetQueryExprNode& operator=(const GetQueryExprNode&) = delete;
    GetQueryExprNode& operator=(GetQueryExprNode&&) = delete;
    virtual ~GetQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
    void Select(QueryTarget* object, QueryContext& context, std::vector<QueryTarget*>& result);
    std::u32string cls;
    unique_xml_ptr<QueryExprNode> cond;
private:
    static int classId;
};

class QUERY_API OrQueryExprNode : public BinaryQueryExprNode
{
public:
    OrQueryExprNode();
    virtual ~OrQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
private:
    static int classId;
};

class QUERY_API AndQueryExprNode : public BinaryQueryExprNode
{
public:
    AndQueryExprNode();
    virtual ~AndQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
private:
    static int classId;
};

class QUERY_API MatchQueryExprNode : public BinaryQueryExprNode
{
public:
    MatchQueryExprNode();
    virtual ~MatchQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
private:
    static int classId;
};

class QUERY_API RelationalQueryExprNode : public BinaryQueryExprNode
{
public:
    RelationalQueryExprNode();
    virtual ~RelationalQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
    Operator op;
private:
    static int classId;
};

class QUERY_API NotQueryExprNode : public UnaryQueryExprNode
{
public:
    NotQueryExprNode();
    virtual ~NotQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
private:
    static int classId;
};

class QUERY_API MemberSelectionQueryExprNode : public UnaryQueryExprNode
{
public:
    MemberSelectionQueryExprNode();
    virtual ~MemberSelectionQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
    std::u32string id;
private:
    static int classId;
};

class QUERY_API ParenthesizedQueryExprNode : public UnaryQueryExprNode
{
public:
    ParenthesizedQueryExprNode();
    virtual ~ParenthesizedQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
private:
    static int classId;
};

class QUERY_API BooleanLiteralQueryExprNode : public QueryExprNode
{
public:
    BooleanLiteralQueryExprNode();
    virtual ~BooleanLiteralQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
    bool value;
private:
    static int classId;
};

class QUERY_API IntegerLiteralQueryExprNode : public QueryExprNode
{
public:
    IntegerLiteralQueryExprNode();
    virtual ~IntegerLiteralQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
    int32_t value;
private:
    static int classId;
};

class QUERY_API StringLiteralQueryExprNode : public QueryExprNode
{
public:
    StringLiteralQueryExprNode();
    virtual ~StringLiteralQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
const std::u32string& Value() const { return value; }
    std::u32string value;
private:
    static int classId;
};

class QUERY_API IdentifierQueryExprNode : public QueryExprNode
{
public:
    IdentifierQueryExprNode();
    virtual ~IdentifierQueryExprNode();
    static void* Create();
    static std::string StaticClassName();
    static void Register(int classId_);
    void DestroyObject() override { delete this; }
    int ClassId() const override { return classId; }
    std::string ClassName() const override;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName) const;
    std::unique_ptr<sngxml::dom::Element> ToXml(const std::string& fieldName, sngxml::xmlser::XmlSerializationContext& ctx) const override;
    void FromXml(sngxml::dom::Element* element) override;
    std::vector<sngxml::xmlser::XmlPtrBase*> GetPtrs() const override;
    void SetObjectXmlAttributes(sngxml::dom::Element* element) const override;
public:
    void Evaluate(QueryContext& context) override;
    std::u32string value;
private:
    static int classId;
};

} // namespace  query


#endif // QUERYEXPR_HPP_0BD750C11930791DDFD166D67FDED0959AE65793
