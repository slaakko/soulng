#ifndef Expression_hpp_5555
#define Expression_hpp_5555

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/codedom/Expression.hpp>

namespace soulng { namespace code {

class Expression : public soulng::parsing::Grammar
{
public:
    static Expression* Create();
    static Expression* Create(soulng::parsing::ParsingDomain* parsingDomain);
    soulng::codedom::CppObject* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName);
private:
    Expression(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class ExpressionRule;
    class ConstantExpressionRule;
    class AssignmentExpressionRule;
    class AssingmentOpRule;
    class ThrowExpressionRule;
    class ConditionalExpressionRule;
    class LogicalOrExpressionRule;
    class LogicalAndExpressionRule;
    class InclusiveOrExpressionRule;
    class ExclusiveOrExpressionRule;
    class AndExpressionRule;
    class EqualityExpressionRule;
    class EqOpRule;
    class RelationalExpressionRule;
    class RelOpRule;
    class ShiftExpressionRule;
    class ShiftOpRule;
    class AdditiveExpressionRule;
    class AddOpRule;
    class MultiplicativeExpressionRule;
    class MulOpRule;
    class PmExpressionRule;
    class PmOpRule;
    class CastExpressionRule;
    class UnaryExpressionRule;
    class UnaryOperatorRule;
    class NewExpressionRule;
    class NewTypeIdRule;
    class NewDeclaratorRule;
    class DirectNewDeclaratorRule;
    class NewPlacementRule;
    class NewInitializerRule;
    class DeleteExpressionRule;
    class PostfixExpressionRule;
    class TypeSpecifierOrTypeNameRule;
    class PostCastExpressionRule;
    class ExpressionListRule;
    class PrimaryExpressionRule;
    class IdExpressionRule;
};

} } // namespace soulng.code

#endif // Expression_hpp_5555
