#ifndef Statement_hpp_5555
#define Statement_hpp_5555

#include <soulng/parsing/Grammar.hpp>
#include <soulng/parsing/Keyword.hpp>
#include <soulng/cppcode/Statement.hpp>

namespace soulng { namespace code {

class Statement : public soulng::parsing::Grammar
{
public:
    static Statement* Create();
    static Statement* Create(soulng::parsing::ParsingDomain* parsingDomain);
    soulng::cppcode::CompoundStatement* Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName);
private:
    Statement(soulng::parsing::ParsingDomain* parsingDomain_);
    void CreateRules() override;
    void GetReferencedGrammars() override;
    class StatementRule;
    class LabeledStatementRule;
    class LabelRule;
    class EmptyStatementRule;
    class ExpressionStatementRule;
    class CompoundStatementRule;
    class SelectionStatementRule;
    class IfStatementRule;
    class SwitchStatementRule;
    class IterationStatementRule;
    class WhileStatementRule;
    class DoStatementRule;
    class ForStatementRule;
    class ForInitStatementRule;
    class JumpStatementRule;
    class BreakStatementRule;
    class ContinueStatementRule;
    class ReturnStatementRule;
    class GotoStatementRule;
    class GotoTargetRule;
    class DeclarationStatementRule;
    class ConditionRule;
    class TryStatementRule;
    class HandlerSeqRule;
    class HandlerRule;
    class ExceptionDeclarationRule;
};

} } // namespace soulng.code

#endif // Statement_hpp_5555
