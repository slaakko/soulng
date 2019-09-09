#include "Primitive.hpp"
#include <soulng/parsing/Action.hpp>
#include <soulng/parsing/Rule.hpp>
#include <soulng/parsing/ParsingDomain.hpp>
#include <soulng/parsing/Primitive.hpp>
#include <soulng/parsing/Composite.hpp>
#include <soulng/parsing/Nonterminal.hpp>
#include <soulng/parsing/Exception.hpp>
#include <soulng/parsing/StdLib.hpp>
#include <soulng/parsing/XmlLog.hpp>
#include <soulng/util/Unicode.hpp>
#include <soulng/syntax/Element.hpp>

namespace soulng { namespace syntax {

using namespace soulng::parsing;
using namespace soulng::util;
using namespace soulng::unicode;

Primitive* Primitive::Create()
{
    return Create(new soulng::parsing::ParsingDomain());
}

Primitive* Primitive::Create(soulng::parsing::ParsingDomain* parsingDomain)
{
    RegisterParsingDomain(parsingDomain);
    Primitive* grammar(new Primitive(parsingDomain));
    parsingDomain->AddGrammar(grammar);
    grammar->CreateRules();
    grammar->Link();
    return grammar;
}

Primitive::Primitive(soulng::parsing::ParsingDomain* parsingDomain_): soulng::parsing::Grammar(ToUtf32("Primitive"), parsingDomain_->GetNamespaceScope(ToUtf32("soulng.syntax")), parsingDomain_)
{
    SetOwner(0);
}

soulng::parsing::Parser* Primitive::Parse(const char32_t* start, const char32_t* end, int fileIndex, const std::string& fileName)
{
    soulng::parsing::Scanner scanner(start, end, fileName, fileIndex, SkipRule());
    std::unique_ptr<soulng::parsing::XmlLog> xmlLog;
    if (Log())
    {
        xmlLog.reset(new soulng::parsing::XmlLog(*Log(), MaxLogLineLength()));
        scanner.SetLog(xmlLog.get());
        xmlLog->WriteBeginRule("parse");
    }
    soulng::parsing::ObjectStack stack;
    std::unique_ptr<soulng::parsing::ParsingData> parsingData(new soulng::parsing::ParsingData(GetParsingDomain()->GetNumRules()));
    scanner.SetParsingData(parsingData.get());
    soulng::parsing::Match match = soulng::parsing::Grammar::Parse(scanner, stack, parsingData.get());
    soulng::parsing::Span stop = scanner.GetSpan();
    if (Log())
    {
        xmlLog->WriteEndRule("parse");
    }
    if (!match.Hit() || stop.Start() != int(end - start))
    {
        if (StartRule())
        {
            throw soulng::parsing::ExpectationFailure(StartRule()->Info(), fileName, stop, start, end);
        }
        else
        {
            throw soulng::parsing::ParsingException("grammar '" + ToUtf8(Name()) + "' has no start rule", fileName, scanner.GetSpan(), start, end);
        }
    }
    std::unique_ptr<soulng::parsing::Object> value = std::move(stack.top());
    soulng::parsing::Parser* result = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(value.get());
    stack.pop();
    return result;
}

class Primitive::PrimitiveRule : public soulng::parsing::Rule
{
public:
    PrimitiveRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A2Action));
        soulng::parsing::ActionParser* a3ActionParser = GetAction(ToUtf32("A3"));
        a3ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A3Action));
        soulng::parsing::ActionParser* a4ActionParser = GetAction(ToUtf32("A4"));
        a4ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A4Action));
        soulng::parsing::ActionParser* a5ActionParser = GetAction(ToUtf32("A5"));
        a5ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A5Action));
        soulng::parsing::ActionParser* a6ActionParser = GetAction(ToUtf32("A6"));
        a6ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A6Action));
        soulng::parsing::ActionParser* a7ActionParser = GetAction(ToUtf32("A7"));
        a7ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A7Action));
        soulng::parsing::ActionParser* a8ActionParser = GetAction(ToUtf32("A8"));
        a8ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A8Action));
        soulng::parsing::ActionParser* a9ActionParser = GetAction(ToUtf32("A9"));
        a9ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A9Action));
        soulng::parsing::ActionParser* a10ActionParser = GetAction(ToUtf32("A10"));
        a10ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A10Action));
        soulng::parsing::ActionParser* a11ActionParser = GetAction(ToUtf32("A11"));
        a11ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A11Action));
        soulng::parsing::ActionParser* a12ActionParser = GetAction(ToUtf32("A12"));
        a12ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A12Action));
        soulng::parsing::ActionParser* a13ActionParser = GetAction(ToUtf32("A13"));
        a13ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A13Action));
        soulng::parsing::ActionParser* a14ActionParser = GetAction(ToUtf32("A14"));
        a14ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A14Action));
        soulng::parsing::ActionParser* a15ActionParser = GetAction(ToUtf32("A15"));
        a15ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A15Action));
        soulng::parsing::ActionParser* a16ActionParser = GetAction(ToUtf32("A16"));
        a16ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A16Action));
        soulng::parsing::ActionParser* a17ActionParser = GetAction(ToUtf32("A17"));
        a17ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A17Action));
        soulng::parsing::ActionParser* a18ActionParser = GetAction(ToUtf32("A18"));
        a18ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A18Action));
        soulng::parsing::ActionParser* a19ActionParser = GetAction(ToUtf32("A19"));
        a19ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A19Action));
        soulng::parsing::ActionParser* a20ActionParser = GetAction(ToUtf32("A20"));
        a20ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A20Action));
        soulng::parsing::ActionParser* a21ActionParser = GetAction(ToUtf32("A21"));
        a21ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A21Action));
        soulng::parsing::ActionParser* a22ActionParser = GetAction(ToUtf32("A22"));
        a22ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A22Action));
        soulng::parsing::ActionParser* a23ActionParser = GetAction(ToUtf32("A23"));
        a23ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A23Action));
        soulng::parsing::ActionParser* a24ActionParser = GetAction(ToUtf32("A24"));
        a24ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A24Action));
        soulng::parsing::ActionParser* a25ActionParser = GetAction(ToUtf32("A25"));
        a25ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A25Action));
        soulng::parsing::ActionParser* a26ActionParser = GetAction(ToUtf32("A26"));
        a26ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A26Action));
        soulng::parsing::ActionParser* a27ActionParser = GetAction(ToUtf32("A27"));
        a27ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A27Action));
        soulng::parsing::ActionParser* a28ActionParser = GetAction(ToUtf32("A28"));
        a28ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A28Action));
        soulng::parsing::ActionParser* a29ActionParser = GetAction(ToUtf32("A29"));
        a29ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A29Action));
        soulng::parsing::ActionParser* a30ActionParser = GetAction(ToUtf32("A30"));
        a30ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A30Action));
        soulng::parsing::ActionParser* a31ActionParser = GetAction(ToUtf32("A31"));
        a31ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A31Action));
        soulng::parsing::ActionParser* a32ActionParser = GetAction(ToUtf32("A32"));
        a32ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A32Action));
        soulng::parsing::ActionParser* a33ActionParser = GetAction(ToUtf32("A33"));
        a33ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A33Action));
        soulng::parsing::ActionParser* a34ActionParser = GetAction(ToUtf32("A34"));
        a34ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A34Action));
        soulng::parsing::ActionParser* a35ActionParser = GetAction(ToUtf32("A35"));
        a35ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A35Action));
        soulng::parsing::ActionParser* a36ActionParser = GetAction(ToUtf32("A36"));
        a36ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A36Action));
        soulng::parsing::ActionParser* a37ActionParser = GetAction(ToUtf32("A37"));
        a37ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A37Action));
        soulng::parsing::ActionParser* a38ActionParser = GetAction(ToUtf32("A38"));
        a38ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A38Action));
        soulng::parsing::ActionParser* a39ActionParser = GetAction(ToUtf32("A39"));
        a39ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A39Action));
        soulng::parsing::ActionParser* a40ActionParser = GetAction(ToUtf32("A40"));
        a40ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A40Action));
        soulng::parsing::ActionParser* a41ActionParser = GetAction(ToUtf32("A41"));
        a41ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A41Action));
        soulng::parsing::ActionParser* a42ActionParser = GetAction(ToUtf32("A42"));
        a42ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A42Action));
        soulng::parsing::ActionParser* a43ActionParser = GetAction(ToUtf32("A43"));
        a43ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A43Action));
        soulng::parsing::ActionParser* a44ActionParser = GetAction(ToUtf32("A44"));
        a44ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A44Action));
        soulng::parsing::ActionParser* a45ActionParser = GetAction(ToUtf32("A45"));
        a45ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A45Action));
        soulng::parsing::ActionParser* a46ActionParser = GetAction(ToUtf32("A46"));
        a46ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A46Action));
        soulng::parsing::ActionParser* a47ActionParser = GetAction(ToUtf32("A47"));
        a47ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A47Action));
        soulng::parsing::ActionParser* a48ActionParser = GetAction(ToUtf32("A48"));
        a48ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A48Action));
        soulng::parsing::ActionParser* a49ActionParser = GetAction(ToUtf32("A49"));
        a49ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A49Action));
        soulng::parsing::ActionParser* a50ActionParser = GetAction(ToUtf32("A50"));
        a50ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A50Action));
        soulng::parsing::ActionParser* a51ActionParser = GetAction(ToUtf32("A51"));
        a51ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A51Action));
        soulng::parsing::ActionParser* a52ActionParser = GetAction(ToUtf32("A52"));
        a52ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A52Action));
        soulng::parsing::ActionParser* a53ActionParser = GetAction(ToUtf32("A53"));
        a53ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrimitiveRule>(this, &PrimitiveRule::A53Action));
        soulng::parsing::NonterminalParser* charNonterminalParser = GetNonterminal(ToUtf32("Char"));
        charNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostChar));
        soulng::parsing::NonterminalParser* stringNonterminalParser = GetNonterminal(ToUtf32("String"));
        stringNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostString));
        soulng::parsing::NonterminalParser* charSetNonterminalParser = GetNonterminal(ToUtf32("CharSet"));
        charSetNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostCharSet));
        soulng::parsing::NonterminalParser* keywordNonterminalParser = GetNonterminal(ToUtf32("Keyword"));
        keywordNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostKeyword));
        soulng::parsing::NonterminalParser* keywordListNonterminalParser = GetNonterminal(ToUtf32("KeywordList"));
        keywordListNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostKeywordList));
        soulng::parsing::NonterminalParser* rangeNonterminalParser = GetNonterminal(ToUtf32("Range"));
        rangeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostRange));
        soulng::parsing::NonterminalParser* emptyNonterminalParser = GetNonterminal(ToUtf32("Empty"));
        emptyNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostEmpty));
        soulng::parsing::NonterminalParser* spaceNonterminalParser = GetNonterminal(ToUtf32("Space"));
        spaceNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostSpace));
        soulng::parsing::NonterminalParser* anyCharNonterminalParser = GetNonterminal(ToUtf32("AnyChar"));
        anyCharNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostAnyChar));
        soulng::parsing::NonterminalParser* letterNonterminalParser = GetNonterminal(ToUtf32("Letter"));
        letterNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostLetter));
        soulng::parsing::NonterminalParser* digitNonterminalParser = GetNonterminal(ToUtf32("Digit"));
        digitNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostDigit));
        soulng::parsing::NonterminalParser* hexDigitNonterminalParser = GetNonterminal(ToUtf32("HexDigit"));
        hexDigitNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostHexDigit));
        soulng::parsing::NonterminalParser* upperLetterNonterminalParser = GetNonterminal(ToUtf32("UpperLetter"));
        upperLetterNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostUpperLetter));
        soulng::parsing::NonterminalParser* lowerLetterNonterminalParser = GetNonterminal(ToUtf32("LowerLetter"));
        lowerLetterNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostLowerLetter));
        soulng::parsing::NonterminalParser* titleLetterNonterminalParser = GetNonterminal(ToUtf32("TitleLetter"));
        titleLetterNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostTitleLetter));
        soulng::parsing::NonterminalParser* modifierLetterNonterminalParser = GetNonterminal(ToUtf32("ModifierLetter"));
        modifierLetterNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostModifierLetter));
        soulng::parsing::NonterminalParser* otherLetterNonterminalParser = GetNonterminal(ToUtf32("OtherLetter"));
        otherLetterNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostOtherLetter));
        soulng::parsing::NonterminalParser* casedLetterNonterminalParser = GetNonterminal(ToUtf32("CasedLetter"));
        casedLetterNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostCasedLetter));
        soulng::parsing::NonterminalParser* markNonterminalParser = GetNonterminal(ToUtf32("Mark"));
        markNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostMark));
        soulng::parsing::NonterminalParser* nonspacingMarkNonterminalParser = GetNonterminal(ToUtf32("NonspacingMark"));
        nonspacingMarkNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostNonspacingMark));
        soulng::parsing::NonterminalParser* enclosingMarkNonterminalParser = GetNonterminal(ToUtf32("EnclosingMark"));
        enclosingMarkNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostEnclosingMark));
        soulng::parsing::NonterminalParser* spacingMarkNonterminalParser = GetNonterminal(ToUtf32("SpacingMark"));
        spacingMarkNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostSpacingMark));
        soulng::parsing::NonterminalParser* numberNonterminalParser = GetNonterminal(ToUtf32("Number"));
        numberNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostNumber));
        soulng::parsing::NonterminalParser* decimalNumberNonterminalParser = GetNonterminal(ToUtf32("DecimalNumber"));
        decimalNumberNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostDecimalNumber));
        soulng::parsing::NonterminalParser* letterNumberNonterminalParser = GetNonterminal(ToUtf32("LetterNumber"));
        letterNumberNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostLetterNumber));
        soulng::parsing::NonterminalParser* otherNumberNonterminalParser = GetNonterminal(ToUtf32("OtherNumber"));
        otherNumberNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostOtherNumber));
        soulng::parsing::NonterminalParser* punctuationNonterminalParser = GetNonterminal(ToUtf32("Punctuation"));
        punctuationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostPunctuation));
        soulng::parsing::NonterminalParser* connectorPunctuationNonterminalParser = GetNonterminal(ToUtf32("ConnectorPunctuation"));
        connectorPunctuationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostConnectorPunctuation));
        soulng::parsing::NonterminalParser* dashPunctuationNonterminalParser = GetNonterminal(ToUtf32("DashPunctuation"));
        dashPunctuationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostDashPunctuation));
        soulng::parsing::NonterminalParser* openPunctuationNonterminalParser = GetNonterminal(ToUtf32("OpenPunctuation"));
        openPunctuationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostOpenPunctuation));
        soulng::parsing::NonterminalParser* closePunctuationNonterminalParser = GetNonterminal(ToUtf32("ClosePunctuation"));
        closePunctuationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostClosePunctuation));
        soulng::parsing::NonterminalParser* initialPunctuationNonterminalParser = GetNonterminal(ToUtf32("InitialPunctuation"));
        initialPunctuationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostInitialPunctuation));
        soulng::parsing::NonterminalParser* finalPunctuationNonterminalParser = GetNonterminal(ToUtf32("FinalPunctuation"));
        finalPunctuationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostFinalPunctuation));
        soulng::parsing::NonterminalParser* otherPunctuationNonterminalParser = GetNonterminal(ToUtf32("OtherPunctuation"));
        otherPunctuationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostOtherPunctuation));
        soulng::parsing::NonterminalParser* symbolNonterminalParser = GetNonterminal(ToUtf32("Symbol"));
        symbolNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostSymbol));
        soulng::parsing::NonterminalParser* mathSymbolNonterminalParser = GetNonterminal(ToUtf32("MathSymbol"));
        mathSymbolNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostMathSymbol));
        soulng::parsing::NonterminalParser* currencySymbolNonterminalParser = GetNonterminal(ToUtf32("CurrencySymbol"));
        currencySymbolNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostCurrencySymbol));
        soulng::parsing::NonterminalParser* modifierSymbolNonterminalParser = GetNonterminal(ToUtf32("ModifierSymbol"));
        modifierSymbolNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostModifierSymbol));
        soulng::parsing::NonterminalParser* otherSymbolNonterminalParser = GetNonterminal(ToUtf32("OtherSymbol"));
        otherSymbolNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostOtherSymbol));
        soulng::parsing::NonterminalParser* separatorNonterminalParser = GetNonterminal(ToUtf32("Separator"));
        separatorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostSeparator));
        soulng::parsing::NonterminalParser* spaceSeparatorNonterminalParser = GetNonterminal(ToUtf32("SpaceSeparator"));
        spaceSeparatorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostSpaceSeparator));
        soulng::parsing::NonterminalParser* lineSeparatorNonterminalParser = GetNonterminal(ToUtf32("LineSeparator"));
        lineSeparatorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostLineSeparator));
        soulng::parsing::NonterminalParser* paragraphSeparatorNonterminalParser = GetNonterminal(ToUtf32("ParagraphSeparator"));
        paragraphSeparatorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostParagraphSeparator));
        soulng::parsing::NonterminalParser* otherNonterminalParser = GetNonterminal(ToUtf32("Other"));
        otherNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostOther));
        soulng::parsing::NonterminalParser* controlNonterminalParser = GetNonterminal(ToUtf32("Control"));
        controlNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostControl));
        soulng::parsing::NonterminalParser* formatNonterminalParser = GetNonterminal(ToUtf32("Format"));
        formatNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostFormat));
        soulng::parsing::NonterminalParser* surrogateNonterminalParser = GetNonterminal(ToUtf32("Surrogate"));
        surrogateNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostSurrogate));
        soulng::parsing::NonterminalParser* privateUseNonterminalParser = GetNonterminal(ToUtf32("PrivateUse"));
        privateUseNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostPrivateUse));
        soulng::parsing::NonterminalParser* unassignedNonterminalParser = GetNonterminal(ToUtf32("Unassigned"));
        unassignedNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostUnassigned));
        soulng::parsing::NonterminalParser* graphicNonterminalParser = GetNonterminal(ToUtf32("Graphic"));
        graphicNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostGraphic));
        soulng::parsing::NonterminalParser* baseCharNonterminalParser = GetNonterminal(ToUtf32("BaseChar"));
        baseCharNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostBaseChar));
        soulng::parsing::NonterminalParser* alphabeticNonterminalParser = GetNonterminal(ToUtf32("Alphabetic"));
        alphabeticNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostAlphabetic));
        soulng::parsing::NonterminalParser* idStartNonterminalParser = GetNonterminal(ToUtf32("IdStart"));
        idStartNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostIdStart));
        soulng::parsing::NonterminalParser* idContNonterminalParser = GetNonterminal(ToUtf32("IdCont"));
        idContNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<PrimitiveRule>(this, &PrimitiveRule::PostIdCont));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromChar;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromString;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromCharSet;
    }
    void A3Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromKeyword;
    }
    void A4Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromKeywordList;
    }
    void A5Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromRange;
    }
    void A6Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromEmpty;
    }
    void A7Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromSpace;
    }
    void A8Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromAnyChar;
    }
    void A9Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromLetter;
    }
    void A10Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromDigit;
    }
    void A11Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromHexDigit;
    }
    void A12Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromUpperLetter;
    }
    void A13Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromLowerLetter;
    }
    void A14Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromTitleLetter;
    }
    void A15Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromModifierLetter;
    }
    void A16Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromOtherLetter;
    }
    void A17Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromCasedLetter;
    }
    void A18Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromMark;
    }
    void A19Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromNonspacingMark;
    }
    void A20Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromEnclosingMark;
    }
    void A21Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromSpacingMark;
    }
    void A22Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromNumber;
    }
    void A23Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromDecimalNumber;
    }
    void A24Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromLetterNumber;
    }
    void A25Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromOtherNumber;
    }
    void A26Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromPunctuation;
    }
    void A27Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromConnectorPunctuation;
    }
    void A28Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromDashPunctuation;
    }
    void A29Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromOpenPunctuation;
    }
    void A30Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromClosePunctuation;
    }
    void A31Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromInitialPunctuation;
    }
    void A32Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromFinalPunctuation;
    }
    void A33Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromOtherPunctuation;
    }
    void A34Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromSymbol;
    }
    void A35Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromMathSymbol;
    }
    void A36Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromCurrencySymbol;
    }
    void A37Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromModifierSymbol;
    }
    void A38Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromOtherSymbol;
    }
    void A39Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromSeparator;
    }
    void A40Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromSpaceSeparator;
    }
    void A41Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromLineSeparator;
    }
    void A42Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromParagraphSeparator;
    }
    void A43Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromOther;
    }
    void A44Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromControl;
    }
    void A45Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromFormat;
    }
    void A46Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromSurrogate;
    }
    void A47Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromPrivateUse;
    }
    void A48Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromUnassigned;
    }
    void A49Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromGraphic;
    }
    void A50Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromBaseChar;
    }
    void A51Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromAlphabetic;
    }
    void A52Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromIdStart;
    }
    void A53Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromIdCont;
    }
    void PostChar(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromChar_value = std::move(stack.top());
            context->fromChar = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromChar_value.get());
            stack.pop();
        }
    }
    void PostString(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromString_value = std::move(stack.top());
            context->fromString = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromString_value.get());
            stack.pop();
        }
    }
    void PostCharSet(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromCharSet_value = std::move(stack.top());
            context->fromCharSet = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromCharSet_value.get());
            stack.pop();
        }
    }
    void PostKeyword(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromKeyword_value = std::move(stack.top());
            context->fromKeyword = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromKeyword_value.get());
            stack.pop();
        }
    }
    void PostKeywordList(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromKeywordList_value = std::move(stack.top());
            context->fromKeywordList = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromKeywordList_value.get());
            stack.pop();
        }
    }
    void PostRange(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromRange_value = std::move(stack.top());
            context->fromRange = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromRange_value.get());
            stack.pop();
        }
    }
    void PostEmpty(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromEmpty_value = std::move(stack.top());
            context->fromEmpty = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromEmpty_value.get());
            stack.pop();
        }
    }
    void PostSpace(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromSpace_value = std::move(stack.top());
            context->fromSpace = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromSpace_value.get());
            stack.pop();
        }
    }
    void PostAnyChar(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAnyChar_value = std::move(stack.top());
            context->fromAnyChar = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromAnyChar_value.get());
            stack.pop();
        }
    }
    void PostLetter(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromLetter_value = std::move(stack.top());
            context->fromLetter = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromLetter_value.get());
            stack.pop();
        }
    }
    void PostDigit(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromDigit_value = std::move(stack.top());
            context->fromDigit = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromDigit_value.get());
            stack.pop();
        }
    }
    void PostHexDigit(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromHexDigit_value = std::move(stack.top());
            context->fromHexDigit = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromHexDigit_value.get());
            stack.pop();
        }
    }
    void PostUpperLetter(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromUpperLetter_value = std::move(stack.top());
            context->fromUpperLetter = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromUpperLetter_value.get());
            stack.pop();
        }
    }
    void PostLowerLetter(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromLowerLetter_value = std::move(stack.top());
            context->fromLowerLetter = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromLowerLetter_value.get());
            stack.pop();
        }
    }
    void PostTitleLetter(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromTitleLetter_value = std::move(stack.top());
            context->fromTitleLetter = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromTitleLetter_value.get());
            stack.pop();
        }
    }
    void PostModifierLetter(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromModifierLetter_value = std::move(stack.top());
            context->fromModifierLetter = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromModifierLetter_value.get());
            stack.pop();
        }
    }
    void PostOtherLetter(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromOtherLetter_value = std::move(stack.top());
            context->fromOtherLetter = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromOtherLetter_value.get());
            stack.pop();
        }
    }
    void PostCasedLetter(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromCasedLetter_value = std::move(stack.top());
            context->fromCasedLetter = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromCasedLetter_value.get());
            stack.pop();
        }
    }
    void PostMark(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromMark_value = std::move(stack.top());
            context->fromMark = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromMark_value.get());
            stack.pop();
        }
    }
    void PostNonspacingMark(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromNonspacingMark_value = std::move(stack.top());
            context->fromNonspacingMark = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromNonspacingMark_value.get());
            stack.pop();
        }
    }
    void PostEnclosingMark(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromEnclosingMark_value = std::move(stack.top());
            context->fromEnclosingMark = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromEnclosingMark_value.get());
            stack.pop();
        }
    }
    void PostSpacingMark(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromSpacingMark_value = std::move(stack.top());
            context->fromSpacingMark = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromSpacingMark_value.get());
            stack.pop();
        }
    }
    void PostNumber(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromNumber_value = std::move(stack.top());
            context->fromNumber = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromNumber_value.get());
            stack.pop();
        }
    }
    void PostDecimalNumber(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromDecimalNumber_value = std::move(stack.top());
            context->fromDecimalNumber = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromDecimalNumber_value.get());
            stack.pop();
        }
    }
    void PostLetterNumber(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromLetterNumber_value = std::move(stack.top());
            context->fromLetterNumber = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromLetterNumber_value.get());
            stack.pop();
        }
    }
    void PostOtherNumber(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromOtherNumber_value = std::move(stack.top());
            context->fromOtherNumber = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromOtherNumber_value.get());
            stack.pop();
        }
    }
    void PostPunctuation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromPunctuation_value = std::move(stack.top());
            context->fromPunctuation = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromPunctuation_value.get());
            stack.pop();
        }
    }
    void PostConnectorPunctuation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromConnectorPunctuation_value = std::move(stack.top());
            context->fromConnectorPunctuation = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromConnectorPunctuation_value.get());
            stack.pop();
        }
    }
    void PostDashPunctuation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromDashPunctuation_value = std::move(stack.top());
            context->fromDashPunctuation = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromDashPunctuation_value.get());
            stack.pop();
        }
    }
    void PostOpenPunctuation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromOpenPunctuation_value = std::move(stack.top());
            context->fromOpenPunctuation = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromOpenPunctuation_value.get());
            stack.pop();
        }
    }
    void PostClosePunctuation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromClosePunctuation_value = std::move(stack.top());
            context->fromClosePunctuation = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromClosePunctuation_value.get());
            stack.pop();
        }
    }
    void PostInitialPunctuation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromInitialPunctuation_value = std::move(stack.top());
            context->fromInitialPunctuation = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromInitialPunctuation_value.get());
            stack.pop();
        }
    }
    void PostFinalPunctuation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromFinalPunctuation_value = std::move(stack.top());
            context->fromFinalPunctuation = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromFinalPunctuation_value.get());
            stack.pop();
        }
    }
    void PostOtherPunctuation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromOtherPunctuation_value = std::move(stack.top());
            context->fromOtherPunctuation = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromOtherPunctuation_value.get());
            stack.pop();
        }
    }
    void PostSymbol(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromSymbol_value = std::move(stack.top());
            context->fromSymbol = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromSymbol_value.get());
            stack.pop();
        }
    }
    void PostMathSymbol(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromMathSymbol_value = std::move(stack.top());
            context->fromMathSymbol = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromMathSymbol_value.get());
            stack.pop();
        }
    }
    void PostCurrencySymbol(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromCurrencySymbol_value = std::move(stack.top());
            context->fromCurrencySymbol = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromCurrencySymbol_value.get());
            stack.pop();
        }
    }
    void PostModifierSymbol(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromModifierSymbol_value = std::move(stack.top());
            context->fromModifierSymbol = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromModifierSymbol_value.get());
            stack.pop();
        }
    }
    void PostOtherSymbol(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromOtherSymbol_value = std::move(stack.top());
            context->fromOtherSymbol = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromOtherSymbol_value.get());
            stack.pop();
        }
    }
    void PostSeparator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromSeparator_value = std::move(stack.top());
            context->fromSeparator = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromSeparator_value.get());
            stack.pop();
        }
    }
    void PostSpaceSeparator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromSpaceSeparator_value = std::move(stack.top());
            context->fromSpaceSeparator = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromSpaceSeparator_value.get());
            stack.pop();
        }
    }
    void PostLineSeparator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromLineSeparator_value = std::move(stack.top());
            context->fromLineSeparator = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromLineSeparator_value.get());
            stack.pop();
        }
    }
    void PostParagraphSeparator(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromParagraphSeparator_value = std::move(stack.top());
            context->fromParagraphSeparator = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromParagraphSeparator_value.get());
            stack.pop();
        }
    }
    void PostOther(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromOther_value = std::move(stack.top());
            context->fromOther = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromOther_value.get());
            stack.pop();
        }
    }
    void PostControl(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromControl_value = std::move(stack.top());
            context->fromControl = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromControl_value.get());
            stack.pop();
        }
    }
    void PostFormat(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromFormat_value = std::move(stack.top());
            context->fromFormat = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromFormat_value.get());
            stack.pop();
        }
    }
    void PostSurrogate(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromSurrogate_value = std::move(stack.top());
            context->fromSurrogate = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromSurrogate_value.get());
            stack.pop();
        }
    }
    void PostPrivateUse(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromPrivateUse_value = std::move(stack.top());
            context->fromPrivateUse = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromPrivateUse_value.get());
            stack.pop();
        }
    }
    void PostUnassigned(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromUnassigned_value = std::move(stack.top());
            context->fromUnassigned = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromUnassigned_value.get());
            stack.pop();
        }
    }
    void PostGraphic(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromGraphic_value = std::move(stack.top());
            context->fromGraphic = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromGraphic_value.get());
            stack.pop();
        }
    }
    void PostBaseChar(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromBaseChar_value = std::move(stack.top());
            context->fromBaseChar = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromBaseChar_value.get());
            stack.pop();
        }
    }
    void PostAlphabetic(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromAlphabetic_value = std::move(stack.top());
            context->fromAlphabetic = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromAlphabetic_value.get());
            stack.pop();
        }
    }
    void PostIdStart(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIdStart_value = std::move(stack.top());
            context->fromIdStart = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromIdStart_value.get());
            stack.pop();
        }
    }
    void PostIdCont(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromIdCont_value = std::move(stack.top());
            context->fromIdCont = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromIdCont_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromChar(), fromString(), fromCharSet(), fromKeyword(), fromKeywordList(), fromRange(), fromEmpty(), fromSpace(), fromAnyChar(), fromLetter(), fromDigit(), fromHexDigit(), fromUpperLetter(), fromLowerLetter(), fromTitleLetter(), fromModifierLetter(), fromOtherLetter(), fromCasedLetter(), fromMark(), fromNonspacingMark(), fromEnclosingMark(), fromSpacingMark(), fromNumber(), fromDecimalNumber(), fromLetterNumber(), fromOtherNumber(), fromPunctuation(), fromConnectorPunctuation(), fromDashPunctuation(), fromOpenPunctuation(), fromClosePunctuation(), fromInitialPunctuation(), fromFinalPunctuation(), fromOtherPunctuation(), fromSymbol(), fromMathSymbol(), fromCurrencySymbol(), fromModifierSymbol(), fromOtherSymbol(), fromSeparator(), fromSpaceSeparator(), fromLineSeparator(), fromParagraphSeparator(), fromOther(), fromControl(), fromFormat(), fromSurrogate(), fromPrivateUse(), fromUnassigned(), fromGraphic(), fromBaseChar(), fromAlphabetic(), fromIdStart(), fromIdCont() {}
        soulng::parsing::Parser* value;
        soulng::parsing::Parser* fromChar;
        soulng::parsing::Parser* fromString;
        soulng::parsing::Parser* fromCharSet;
        soulng::parsing::Parser* fromKeyword;
        soulng::parsing::Parser* fromKeywordList;
        soulng::parsing::Parser* fromRange;
        soulng::parsing::Parser* fromEmpty;
        soulng::parsing::Parser* fromSpace;
        soulng::parsing::Parser* fromAnyChar;
        soulng::parsing::Parser* fromLetter;
        soulng::parsing::Parser* fromDigit;
        soulng::parsing::Parser* fromHexDigit;
        soulng::parsing::Parser* fromUpperLetter;
        soulng::parsing::Parser* fromLowerLetter;
        soulng::parsing::Parser* fromTitleLetter;
        soulng::parsing::Parser* fromModifierLetter;
        soulng::parsing::Parser* fromOtherLetter;
        soulng::parsing::Parser* fromCasedLetter;
        soulng::parsing::Parser* fromMark;
        soulng::parsing::Parser* fromNonspacingMark;
        soulng::parsing::Parser* fromEnclosingMark;
        soulng::parsing::Parser* fromSpacingMark;
        soulng::parsing::Parser* fromNumber;
        soulng::parsing::Parser* fromDecimalNumber;
        soulng::parsing::Parser* fromLetterNumber;
        soulng::parsing::Parser* fromOtherNumber;
        soulng::parsing::Parser* fromPunctuation;
        soulng::parsing::Parser* fromConnectorPunctuation;
        soulng::parsing::Parser* fromDashPunctuation;
        soulng::parsing::Parser* fromOpenPunctuation;
        soulng::parsing::Parser* fromClosePunctuation;
        soulng::parsing::Parser* fromInitialPunctuation;
        soulng::parsing::Parser* fromFinalPunctuation;
        soulng::parsing::Parser* fromOtherPunctuation;
        soulng::parsing::Parser* fromSymbol;
        soulng::parsing::Parser* fromMathSymbol;
        soulng::parsing::Parser* fromCurrencySymbol;
        soulng::parsing::Parser* fromModifierSymbol;
        soulng::parsing::Parser* fromOtherSymbol;
        soulng::parsing::Parser* fromSeparator;
        soulng::parsing::Parser* fromSpaceSeparator;
        soulng::parsing::Parser* fromLineSeparator;
        soulng::parsing::Parser* fromParagraphSeparator;
        soulng::parsing::Parser* fromOther;
        soulng::parsing::Parser* fromControl;
        soulng::parsing::Parser* fromFormat;
        soulng::parsing::Parser* fromSurrogate;
        soulng::parsing::Parser* fromPrivateUse;
        soulng::parsing::Parser* fromUnassigned;
        soulng::parsing::Parser* fromGraphic;
        soulng::parsing::Parser* fromBaseChar;
        soulng::parsing::Parser* fromAlphabetic;
        soulng::parsing::Parser* fromIdStart;
        soulng::parsing::Parser* fromIdCont;
    };
};

class Primitive::CharRule : public soulng::parsing::Rule
{
public:
    CharRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharRule>(this, &CharRule::A0Action));
        soulng::parsing::NonterminalParser* chrNonterminalParser = GetNonterminal(ToUtf32("chr"));
        chrNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CharRule>(this, &CharRule::Postchr));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new CharParser(context->fromchr);
    }
    void Postchr(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromchr_value = std::move(stack.top());
            context->fromchr = *static_cast<soulng::parsing::ValueObject<char32_t>*>(fromchr_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromchr() {}
        soulng::parsing::Parser* value;
        char32_t fromchr;
    };
};

class Primitive::StringRule : public soulng::parsing::Rule
{
public:
    StringRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<StringRule>(this, &StringRule::A0Action));
        soulng::parsing::NonterminalParser* strNonterminalParser = GetNonterminal(ToUtf32("str"));
        strNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<StringRule>(this, &StringRule::Poststr));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new StringParser(context->fromstr);
    }
    void Poststr(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromstr_value = std::move(stack.top());
            context->fromstr = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromstr_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromstr() {}
        soulng::parsing::Parser* value;
        std::u32string fromstr;
    };
};

class Primitive::CharSetRule : public soulng::parsing::Rule
{
public:
    CharSetRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("bool"), ToUtf32("inverse")));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::u32string"), ToUtf32("s")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharSetRule>(this, &CharSetRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharSetRule>(this, &CharSetRule::A1Action));
        soulng::parsing::ActionParser* a2ActionParser = GetAction(ToUtf32("A2"));
        a2ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharSetRule>(this, &CharSetRule::A2Action));
        soulng::parsing::NonterminalParser* charSetRangeNonterminalParser = GetNonterminal(ToUtf32("CharSetRange"));
        charSetRangeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CharSetRule>(this, &CharSetRule::PostCharSetRange));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new CharSetParser(context->s, context->inverse);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->inverse = true;
    }
    void A2Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->s.append(context->fromCharSetRange);
    }
    void PostCharSetRange(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromCharSetRange_value = std::move(stack.top());
            context->fromCharSetRange = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromCharSetRange_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), inverse(), s(), fromCharSetRange() {}
        soulng::parsing::Parser* value;
        bool inverse;
        std::u32string s;
        std::u32string fromCharSetRange;
    };
};

class Primitive::CharSetRangeRule : public soulng::parsing::Rule
{
public:
    CharSetRangeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("std::u32string"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<std::u32string>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharSetRangeRule>(this, &CharSetRangeRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharSetRangeRule>(this, &CharSetRangeRule::A1Action));
        soulng::parsing::NonterminalParser* firstNonterminalParser = GetNonterminal(ToUtf32("first"));
        firstNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CharSetRangeRule>(this, &CharSetRangeRule::Postfirst));
        soulng::parsing::NonterminalParser* lastNonterminalParser = GetNonterminal(ToUtf32("last"));
        lastNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CharSetRangeRule>(this, &CharSetRangeRule::Postlast));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value.append(1, context->fromfirst);
        context->value.append(1, '-');
        context->value.append(1, context->fromlast);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value.append(1, context->fromfirst);
    }
    void Postfirst(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromfirst_value = std::move(stack.top());
            context->fromfirst = *static_cast<soulng::parsing::ValueObject<char32_t>*>(fromfirst_value.get());
            stack.pop();
        }
    }
    void Postlast(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromlast_value = std::move(stack.top());
            context->fromlast = *static_cast<soulng::parsing::ValueObject<char32_t>*>(fromlast_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromfirst(), fromlast() {}
        std::u32string value;
        char32_t fromfirst;
        char32_t fromlast;
    };
};

class Primitive::CharSetCharRule : public soulng::parsing::Rule
{
public:
    CharSetCharRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("char32_t"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<char32_t>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharSetCharRule>(this, &CharSetCharRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CharSetCharRule>(this, &CharSetCharRule::A1Action));
        soulng::parsing::NonterminalParser* escapeNonterminalParser = GetNonterminal(ToUtf32("escape"));
        escapeNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CharSetCharRule>(this, &CharSetCharRule::Postescape));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = *matchBegin;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromescape;
    }
    void Postescape(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromescape_value = std::move(stack.top());
            context->fromescape = *static_cast<soulng::parsing::ValueObject<char32_t>*>(fromescape_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromescape() {}
        char32_t value;
        char32_t fromescape;
    };
};

class Primitive::KeywordRule : public soulng::parsing::Rule
{
public:
    KeywordRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<KeywordRule>(this, &KeywordRule::A0Action));
        soulng::parsing::NonterminalParser* keywordBodyNonterminalParser = GetNonterminal(ToUtf32("KeywordBody"));
        keywordBodyNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<KeywordRule>(this, &KeywordRule::PostKeywordBody));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromKeywordBody;
    }
    void PostKeywordBody(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromKeywordBody_value = std::move(stack.top());
            context->fromKeywordBody = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromKeywordBody_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromKeywordBody() {}
        soulng::parsing::Parser* value;
        soulng::parsing::Parser* fromKeywordBody;
    };
};

class Primitive::KeywordBodyRule : public soulng::parsing::Rule
{
public:
    KeywordBodyRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<KeywordBodyRule>(this, &KeywordBodyRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<KeywordBodyRule>(this, &KeywordBodyRule::A1Action));
        soulng::parsing::NonterminalParser* strNonterminalParser = GetNonterminal(ToUtf32("str"));
        strNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<KeywordBodyRule>(this, &KeywordBodyRule::Poststr));
        soulng::parsing::NonterminalParser* continuationNonterminalParser = GetNonterminal(ToUtf32("continuation"));
        continuationNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<KeywordBodyRule>(this, &KeywordBodyRule::Postcontinuation));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new KeywordParser(context->fromstr, context->fromcontinuation);
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new KeywordParser(context->fromstr);
    }
    void Poststr(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromstr_value = std::move(stack.top());
            context->fromstr = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromstr_value.get());
            stack.pop();
        }
    }
    void Postcontinuation(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromcontinuation_value = std::move(stack.top());
            context->fromcontinuation = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromcontinuation_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromstr(), fromcontinuation() {}
        soulng::parsing::Parser* value;
        std::u32string fromstr;
        std::u32string fromcontinuation;
    };
};

class Primitive::KeywordListRule : public soulng::parsing::Rule
{
public:
    KeywordListRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<KeywordListRule>(this, &KeywordListRule::A0Action));
        soulng::parsing::NonterminalParser* keywordListBodyNonterminalParser = GetNonterminal(ToUtf32("KeywordListBody"));
        keywordListBodyNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<KeywordListRule>(this, &KeywordListRule::PostKeywordListBody));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromKeywordListBody;
    }
    void PostKeywordListBody(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromKeywordListBody_value = std::move(stack.top());
            context->fromKeywordListBody = *static_cast<soulng::parsing::ValueObject<soulng::parsing::Parser*>*>(fromKeywordListBody_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromKeywordListBody() {}
        soulng::parsing::Parser* value;
        soulng::parsing::Parser* fromKeywordListBody;
    };
};

class Primitive::KeywordListBodyRule : public soulng::parsing::Rule
{
public:
    KeywordListBodyRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
        AddLocalVariable(AttrOrVariable(ToUtf32("std::vector<std::u32string>"), ToUtf32("keywords")));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<KeywordListBodyRule>(this, &KeywordListBodyRule::A0Action));
        soulng::parsing::NonterminalParser* selectorNonterminalParser = GetNonterminal(ToUtf32("selector"));
        selectorNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<KeywordListBodyRule>(this, &KeywordListBodyRule::Postselector));
        soulng::parsing::NonterminalParser* stringArrayNonterminalParser = GetNonterminal(ToUtf32("StringArray"));
        stringArrayNonterminalParser->SetPreCall(new soulng::parsing::MemberPreCall<KeywordListBodyRule>(this, &KeywordListBodyRule::PreStringArray));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new KeywordListParser(context->fromselector, context->keywords);
    }
    void Postselector(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromselector_value = std::move(stack.top());
            context->fromselector = *static_cast<soulng::parsing::ValueObject<std::u32string>*>(fromselector_value.get());
            stack.pop();
        }
    }
    void PreStringArray(soulng::parsing::ObjectStack& stack, ParsingData* parsingData)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<std::vector<std::u32string>*>(&context->keywords)));
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), keywords(), fromselector() {}
        soulng::parsing::Parser* value;
        std::vector<std::u32string> keywords;
        std::u32string fromselector;
    };
};

class Primitive::RangeRule : public soulng::parsing::Rule
{
public:
    RangeRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<RangeRule>(this, &RangeRule::A0Action));
        soulng::parsing::NonterminalParser* sNonterminalParser = GetNonterminal(ToUtf32("s"));
        sNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RangeRule>(this, &RangeRule::Posts));
        soulng::parsing::NonterminalParser* eNonterminalParser = GetNonterminal(ToUtf32("e"));
        eNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<RangeRule>(this, &RangeRule::Poste));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new RangeParser(context->froms, context->frome);
    }
    void Posts(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> froms_value = std::move(stack.top());
            context->froms = *static_cast<soulng::parsing::ValueObject<uint32_t>*>(froms_value.get());
            stack.pop();
        }
    }
    void Poste(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> frome_value = std::move(stack.top());
            context->frome = *static_cast<soulng::parsing::ValueObject<uint32_t>*>(frome_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), froms(), frome() {}
        soulng::parsing::Parser* value;
        uint32_t froms;
        uint32_t frome;
    };
};

class Primitive::CodePointRule : public soulng::parsing::Rule
{
public:
    CodePointRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("uint32_t"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<uint32_t>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CodePointRule>(this, &CodePointRule::A0Action));
        soulng::parsing::ActionParser* a1ActionParser = GetAction(ToUtf32("A1"));
        a1ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CodePointRule>(this, &CodePointRule::A1Action));
        soulng::parsing::NonterminalParser* xNonterminalParser = GetNonterminal(ToUtf32("x"));
        xNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CodePointRule>(this, &CodePointRule::Postx));
        soulng::parsing::NonterminalParser* dNonterminalParser = GetNonterminal(ToUtf32("d"));
        dNonterminalParser->SetPostCall(new soulng::parsing::MemberPostCall<CodePointRule>(this, &CodePointRule::Postd));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromx;
    }
    void A1Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = context->fromd;
    }
    void Postx(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromx_value = std::move(stack.top());
            context->fromx = *static_cast<soulng::parsing::ValueObject<uint32_t>*>(fromx_value.get());
            stack.pop();
        }
    }
    void Postd(soulng::parsing::ObjectStack& stack, ParsingData* parsingData, bool matched)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            std::unique_ptr<soulng::parsing::Object> fromd_value = std::move(stack.top());
            context->fromd = *static_cast<soulng::parsing::ValueObject<uint32_t>*>(fromd_value.get());
            stack.pop();
        }
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value(), fromx(), fromd() {}
        uint32_t value;
        uint32_t fromx;
        uint32_t fromd;
    };
};

class Primitive::EmptyRule : public soulng::parsing::Rule
{
public:
    EmptyRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<EmptyRule>(this, &EmptyRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new EmptyParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::SpaceRule : public soulng::parsing::Rule
{
public:
    SpaceRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SpaceRule>(this, &SpaceRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new SpaceParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::AnyCharRule : public soulng::parsing::Rule
{
public:
    AnyCharRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AnyCharRule>(this, &AnyCharRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new AnyCharParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::LetterRule : public soulng::parsing::Rule
{
public:
    LetterRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LetterRule>(this, &LetterRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new LetterParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::DigitRule : public soulng::parsing::Rule
{
public:
    DigitRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DigitRule>(this, &DigitRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new DigitParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::HexDigitRule : public soulng::parsing::Rule
{
public:
    HexDigitRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<HexDigitRule>(this, &HexDigitRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new HexDigitParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::UpperLetterRule : public soulng::parsing::Rule
{
public:
    UpperLetterRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UpperLetterRule>(this, &UpperLetterRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new UpperLetterParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::LowerLetterRule : public soulng::parsing::Rule
{
public:
    LowerLetterRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LowerLetterRule>(this, &LowerLetterRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new LowerLetterParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::TitleLetterRule : public soulng::parsing::Rule
{
public:
    TitleLetterRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<TitleLetterRule>(this, &TitleLetterRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new TitleLetterParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::ModifierLetterRule : public soulng::parsing::Rule
{
public:
    ModifierLetterRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ModifierLetterRule>(this, &ModifierLetterRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ModifierLetterParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::OtherLetterRule : public soulng::parsing::Rule
{
public:
    OtherLetterRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<OtherLetterRule>(this, &OtherLetterRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new OtherLetterParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::CasedLetterRule : public soulng::parsing::Rule
{
public:
    CasedLetterRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CasedLetterRule>(this, &CasedLetterRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new CasedLetterParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::MarkRule : public soulng::parsing::Rule
{
public:
    MarkRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<MarkRule>(this, &MarkRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new MarkParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::NonspacingMarkRule : public soulng::parsing::Rule
{
public:
    NonspacingMarkRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NonspacingMarkRule>(this, &NonspacingMarkRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new NonspacingMarkParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::SpacingMarkRule : public soulng::parsing::Rule
{
public:
    SpacingMarkRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SpacingMarkRule>(this, &SpacingMarkRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new SpacingMarkParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::EnclosingMarkRule : public soulng::parsing::Rule
{
public:
    EnclosingMarkRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<EnclosingMarkRule>(this, &EnclosingMarkRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new EnclosingMarkParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::NumberRule : public soulng::parsing::Rule
{
public:
    NumberRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<NumberRule>(this, &NumberRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new NumberParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::DecimalNumberRule : public soulng::parsing::Rule
{
public:
    DecimalNumberRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DecimalNumberRule>(this, &DecimalNumberRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new DecimalNumberParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::LetterNumberRule : public soulng::parsing::Rule
{
public:
    LetterNumberRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LetterNumberRule>(this, &LetterNumberRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new LetterNumberParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::OtherNumberRule : public soulng::parsing::Rule
{
public:
    OtherNumberRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<OtherNumberRule>(this, &OtherNumberRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new OtherNumberParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::PunctuationRule : public soulng::parsing::Rule
{
public:
    PunctuationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PunctuationRule>(this, &PunctuationRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new PunctuationParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::ConnectorPunctuationRule : public soulng::parsing::Rule
{
public:
    ConnectorPunctuationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ConnectorPunctuationRule>(this, &ConnectorPunctuationRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ConnectorPunctuationParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::DashPunctuationRule : public soulng::parsing::Rule
{
public:
    DashPunctuationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<DashPunctuationRule>(this, &DashPunctuationRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new DashPunctuationParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::OpenPunctuationRule : public soulng::parsing::Rule
{
public:
    OpenPunctuationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<OpenPunctuationRule>(this, &OpenPunctuationRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new OpenPunctuationParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::ClosePunctuationRule : public soulng::parsing::Rule
{
public:
    ClosePunctuationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ClosePunctuationRule>(this, &ClosePunctuationRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ClosePunctuationParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::InitialPunctuationRule : public soulng::parsing::Rule
{
public:
    InitialPunctuationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<InitialPunctuationRule>(this, &InitialPunctuationRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new InitialPunctuationParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::FinalPunctuationRule : public soulng::parsing::Rule
{
public:
    FinalPunctuationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<FinalPunctuationRule>(this, &FinalPunctuationRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new FinalPunctuationParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::OtherPunctuationRule : public soulng::parsing::Rule
{
public:
    OtherPunctuationRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<OtherPunctuationRule>(this, &OtherPunctuationRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new OtherPunctuationParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::SymbolRule : public soulng::parsing::Rule
{
public:
    SymbolRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SymbolRule>(this, &SymbolRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new SymbolParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::MathSymbolRule : public soulng::parsing::Rule
{
public:
    MathSymbolRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<MathSymbolRule>(this, &MathSymbolRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new MathSymbolParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::CurrencySymbolRule : public soulng::parsing::Rule
{
public:
    CurrencySymbolRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<CurrencySymbolRule>(this, &CurrencySymbolRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new CurrencySymbolParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::ModifierSymbolRule : public soulng::parsing::Rule
{
public:
    ModifierSymbolRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ModifierSymbolRule>(this, &ModifierSymbolRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ModifierSymbolParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::OtherSymbolRule : public soulng::parsing::Rule
{
public:
    OtherSymbolRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<OtherSymbolRule>(this, &OtherSymbolRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new OtherSymbolParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::SeparatorRule : public soulng::parsing::Rule
{
public:
    SeparatorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SeparatorRule>(this, &SeparatorRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new SeparatorParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::SpaceSeparatorRule : public soulng::parsing::Rule
{
public:
    SpaceSeparatorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SpaceSeparatorRule>(this, &SpaceSeparatorRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new SpaceSeparatorParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::LineSeparatorRule : public soulng::parsing::Rule
{
public:
    LineSeparatorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<LineSeparatorRule>(this, &LineSeparatorRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new LineSeparatorParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::ParagraphSeparatorRule : public soulng::parsing::Rule
{
public:
    ParagraphSeparatorRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ParagraphSeparatorRule>(this, &ParagraphSeparatorRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ParagraphSeparatorParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::OtherRule : public soulng::parsing::Rule
{
public:
    OtherRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<OtherRule>(this, &OtherRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new OtherParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::ControlRule : public soulng::parsing::Rule
{
public:
    ControlRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<ControlRule>(this, &ControlRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new ControlParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::FormatRule : public soulng::parsing::Rule
{
public:
    FormatRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<FormatRule>(this, &FormatRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new FormatParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::SurrogateRule : public soulng::parsing::Rule
{
public:
    SurrogateRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<SurrogateRule>(this, &SurrogateRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new SurrogateParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::PrivateUseRule : public soulng::parsing::Rule
{
public:
    PrivateUseRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<PrivateUseRule>(this, &PrivateUseRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new PrivateUseParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::UnassignedRule : public soulng::parsing::Rule
{
public:
    UnassignedRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<UnassignedRule>(this, &UnassignedRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new UnassignedParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::GraphicRule : public soulng::parsing::Rule
{
public:
    GraphicRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<GraphicRule>(this, &GraphicRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new GraphicParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::BaseCharRule : public soulng::parsing::Rule
{
public:
    BaseCharRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<BaseCharRule>(this, &BaseCharRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new BaseCharParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::AlphabeticRule : public soulng::parsing::Rule
{
public:
    AlphabeticRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<AlphabeticRule>(this, &AlphabeticRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new AlphabeticParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::IdStartRule : public soulng::parsing::Rule
{
public:
    IdStartRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IdStartRule>(this, &IdStartRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new IdStartParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

class Primitive::IdContRule : public soulng::parsing::Rule
{
public:
    IdContRule(const std::u32string& name_, Scope* enclosingScope_, int id_, Parser* definition_):
        soulng::parsing::Rule(name_, enclosingScope_, id_, definition_)
    {
        SetValueTypeName(ToUtf32("soulng::parsing::Parser*"));
    }
    void Enter(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData) override
    {
        parsingData->PushContext(Id(), new Context());
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
    }
    void Leave(soulng::parsing::ObjectStack& stack, soulng::parsing::ParsingData* parsingData, bool matched) override
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        if (matched)
        {
            stack.push(std::unique_ptr<soulng::parsing::Object>(new soulng::parsing::ValueObject<soulng::parsing::Parser*>(context->value)));
        }
        parsingData->PopContext(Id());
    }
    void Link() override
    {
        soulng::parsing::ActionParser* a0ActionParser = GetAction(ToUtf32("A0"));
        a0ActionParser->SetAction(new soulng::parsing::MemberParsingAction<IdContRule>(this, &IdContRule::A0Action));
    }
    void A0Action(const char32_t* matchBegin, const char32_t* matchEnd, const Span& span, const std::string& fileName, ParsingData* parsingData, bool& pass)
    {
        Context* context = static_cast<Context*>(parsingData->GetContext(Id()));
        context->value = new IdContParser;
    }
private:
    struct Context : soulng::parsing::Context
    {
        Context(): value() {}
        soulng::parsing::Parser* value;
    };
};

void Primitive::GetReferencedGrammars()
{
    soulng::parsing::ParsingDomain* pd = GetParsingDomain();
    soulng::parsing::Grammar* grammar0 = pd->GetGrammar(ToUtf32("soulng.syntax.Element"));
    if (!grammar0)
    {
        grammar0 = soulng::syntax::Element::Create(pd);
    }
    AddGrammarReference(grammar0);
    soulng::parsing::Grammar* grammar1 = pd->GetGrammar(ToUtf32("soulng.parsing.stdlib"));
    if (!grammar1)
    {
        grammar1 = soulng::parsing::stdlib::Create(pd);
    }
    AddGrammarReference(grammar1);
}

void Primitive::CreateRules()
{
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("QualifiedId"), this, ToUtf32("Element.QualifiedId")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("hexuint"), this, ToUtf32("soulng.parsing.stdlib.hexuint")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("char"), this, ToUtf32("soulng.parsing.stdlib.char")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("string"), this, ToUtf32("soulng.parsing.stdlib.string")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("escape"), this, ToUtf32("soulng.parsing.stdlib.escape")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("uint"), this, ToUtf32("soulng.parsing.stdlib.uint")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("int"), this, ToUtf32("soulng.parsing.stdlib.int")));
    AddRuleLink(new soulng::parsing::RuleLink(ToUtf32("StringArray"), this, ToUtf32("Element.StringArray")));
    AddRule(new PrimitiveRule(ToUtf32("Primitive"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::AlternativeParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::AlternativeParser(
                        new soulng::parsing::AlternativeParser(
                            new soulng::parsing::AlternativeParser(
                                new soulng::parsing::AlternativeParser(
                                    new soulng::parsing::AlternativeParser(
                                        new soulng::parsing::AlternativeParser(
                                            new soulng::parsing::AlternativeParser(
                                                new soulng::parsing::AlternativeParser(
                                                    new soulng::parsing::AlternativeParser(
                                                        new soulng::parsing::AlternativeParser(
                                                            new soulng::parsing::AlternativeParser(
                                                                new soulng::parsing::AlternativeParser(
                                                                    new soulng::parsing::AlternativeParser(
                                                                        new soulng::parsing::AlternativeParser(
                                                                            new soulng::parsing::AlternativeParser(
                                                                                new soulng::parsing::AlternativeParser(
                                                                                    new soulng::parsing::AlternativeParser(
                                                                                        new soulng::parsing::AlternativeParser(
                                                                                            new soulng::parsing::AlternativeParser(
                                                                                                new soulng::parsing::AlternativeParser(
                                                                                                    new soulng::parsing::AlternativeParser(
                                                                                                        new soulng::parsing::AlternativeParser(
                                                                                                            new soulng::parsing::AlternativeParser(
                                                                                                                new soulng::parsing::AlternativeParser(
                                                                                                                    new soulng::parsing::AlternativeParser(
                                                                                                                        new soulng::parsing::AlternativeParser(
                                                                                                                            new soulng::parsing::AlternativeParser(
                                                                                                                                new soulng::parsing::AlternativeParser(
                                                                                                                                    new soulng::parsing::AlternativeParser(
                                                                                                                                        new soulng::parsing::AlternativeParser(
                                                                                                                                            new soulng::parsing::AlternativeParser(
                                                                                                                                                new soulng::parsing::AlternativeParser(
                                                                                                                                                    new soulng::parsing::AlternativeParser(
                                                                                                                                                        new soulng::parsing::AlternativeParser(
                                                                                                                                                            new soulng::parsing::AlternativeParser(
                                                                                                                                                                new soulng::parsing::AlternativeParser(
                                                                                                                                                                    new soulng::parsing::AlternativeParser(
                                                                                                                                                                        new soulng::parsing::AlternativeParser(
                                                                                                                                                                            new soulng::parsing::AlternativeParser(
                                                                                                                                                                                new soulng::parsing::AlternativeParser(
                                                                                                                                                                                    new soulng::parsing::AlternativeParser(
                                                                                                                                                                                        new soulng::parsing::AlternativeParser(
                                                                                                                                                                                            new soulng::parsing::AlternativeParser(
                                                                                                                                                                                                new soulng::parsing::AlternativeParser(
                                                                                                                                                                                                    new soulng::parsing::AlternativeParser(
                                                                                                                                                                                                        new soulng::parsing::AlternativeParser(
                                                                                                                                                                                                            new soulng::parsing::AlternativeParser(
                                                                                                                                                                                                                new soulng::parsing::AlternativeParser(
                                                                                                                                                                                                                    new soulng::parsing::AlternativeParser(
                                                                                                                                                                                                                        new soulng::parsing::AlternativeParser(
                                                                                                                                                                                                                            new soulng::parsing::ActionParser(ToUtf32("A0"),
                                                                                                                                                                                                                                new soulng::parsing::NonterminalParser(ToUtf32("Char"), ToUtf32("Char"), 0)),
                                                                                                                                                                                                                            new soulng::parsing::ActionParser(ToUtf32("A1"),
                                                                                                                                                                                                                                new soulng::parsing::NonterminalParser(ToUtf32("String"), ToUtf32("String"), 0))),
                                                                                                                                                                                                                        new soulng::parsing::ActionParser(ToUtf32("A2"),
                                                                                                                                                                                                                            new soulng::parsing::NonterminalParser(ToUtf32("CharSet"), ToUtf32("CharSet"), 0))),
                                                                                                                                                                                                                    new soulng::parsing::ActionParser(ToUtf32("A3"),
                                                                                                                                                                                                                        new soulng::parsing::NonterminalParser(ToUtf32("Keyword"), ToUtf32("Keyword"), 0))),
                                                                                                                                                                                                                new soulng::parsing::ActionParser(ToUtf32("A4"),
                                                                                                                                                                                                                    new soulng::parsing::NonterminalParser(ToUtf32("KeywordList"), ToUtf32("KeywordList"), 0))),
                                                                                                                                                                                                            new soulng::parsing::ActionParser(ToUtf32("A5"),
                                                                                                                                                                                                                new soulng::parsing::NonterminalParser(ToUtf32("Range"), ToUtf32("Range"), 0))),
                                                                                                                                                                                                        new soulng::parsing::ActionParser(ToUtf32("A6"),
                                                                                                                                                                                                            new soulng::parsing::NonterminalParser(ToUtf32("Empty"), ToUtf32("Empty"), 0))),
                                                                                                                                                                                                    new soulng::parsing::ActionParser(ToUtf32("A7"),
                                                                                                                                                                                                        new soulng::parsing::NonterminalParser(ToUtf32("Space"), ToUtf32("Space"), 0))),
                                                                                                                                                                                                new soulng::parsing::ActionParser(ToUtf32("A8"),
                                                                                                                                                                                                    new soulng::parsing::NonterminalParser(ToUtf32("AnyChar"), ToUtf32("AnyChar"), 0))),
                                                                                                                                                                                            new soulng::parsing::ActionParser(ToUtf32("A9"),
                                                                                                                                                                                                new soulng::parsing::NonterminalParser(ToUtf32("Letter"), ToUtf32("Letter"), 0))),
                                                                                                                                                                                        new soulng::parsing::ActionParser(ToUtf32("A10"),
                                                                                                                                                                                            new soulng::parsing::NonterminalParser(ToUtf32("Digit"), ToUtf32("Digit"), 0))),
                                                                                                                                                                                    new soulng::parsing::ActionParser(ToUtf32("A11"),
                                                                                                                                                                                        new soulng::parsing::NonterminalParser(ToUtf32("HexDigit"), ToUtf32("HexDigit"), 0))),
                                                                                                                                                                                new soulng::parsing::ActionParser(ToUtf32("A12"),
                                                                                                                                                                                    new soulng::parsing::NonterminalParser(ToUtf32("UpperLetter"), ToUtf32("UpperLetter"), 0))),
                                                                                                                                                                            new soulng::parsing::ActionParser(ToUtf32("A13"),
                                                                                                                                                                                new soulng::parsing::NonterminalParser(ToUtf32("LowerLetter"), ToUtf32("LowerLetter"), 0))),
                                                                                                                                                                        new soulng::parsing::ActionParser(ToUtf32("A14"),
                                                                                                                                                                            new soulng::parsing::NonterminalParser(ToUtf32("TitleLetter"), ToUtf32("TitleLetter"), 0))),
                                                                                                                                                                    new soulng::parsing::ActionParser(ToUtf32("A15"),
                                                                                                                                                                        new soulng::parsing::NonterminalParser(ToUtf32("ModifierLetter"), ToUtf32("ModifierLetter"), 0))),
                                                                                                                                                                new soulng::parsing::ActionParser(ToUtf32("A16"),
                                                                                                                                                                    new soulng::parsing::NonterminalParser(ToUtf32("OtherLetter"), ToUtf32("OtherLetter"), 0))),
                                                                                                                                                            new soulng::parsing::ActionParser(ToUtf32("A17"),
                                                                                                                                                                new soulng::parsing::NonterminalParser(ToUtf32("CasedLetter"), ToUtf32("CasedLetter"), 0))),
                                                                                                                                                        new soulng::parsing::ActionParser(ToUtf32("A18"),
                                                                                                                                                            new soulng::parsing::NonterminalParser(ToUtf32("Mark"), ToUtf32("Mark"), 0))),
                                                                                                                                                    new soulng::parsing::ActionParser(ToUtf32("A19"),
                                                                                                                                                        new soulng::parsing::NonterminalParser(ToUtf32("NonspacingMark"), ToUtf32("NonspacingMark"), 0))),
                                                                                                                                                new soulng::parsing::ActionParser(ToUtf32("A20"),
                                                                                                                                                    new soulng::parsing::NonterminalParser(ToUtf32("EnclosingMark"), ToUtf32("EnclosingMark"), 0))),
                                                                                                                                            new soulng::parsing::ActionParser(ToUtf32("A21"),
                                                                                                                                                new soulng::parsing::NonterminalParser(ToUtf32("SpacingMark"), ToUtf32("SpacingMark"), 0))),
                                                                                                                                        new soulng::parsing::ActionParser(ToUtf32("A22"),
                                                                                                                                            new soulng::parsing::NonterminalParser(ToUtf32("Number"), ToUtf32("Number"), 0))),
                                                                                                                                    new soulng::parsing::ActionParser(ToUtf32("A23"),
                                                                                                                                        new soulng::parsing::NonterminalParser(ToUtf32("DecimalNumber"), ToUtf32("DecimalNumber"), 0))),
                                                                                                                                new soulng::parsing::ActionParser(ToUtf32("A24"),
                                                                                                                                    new soulng::parsing::NonterminalParser(ToUtf32("LetterNumber"), ToUtf32("LetterNumber"), 0))),
                                                                                                                            new soulng::parsing::ActionParser(ToUtf32("A25"),
                                                                                                                                new soulng::parsing::NonterminalParser(ToUtf32("OtherNumber"), ToUtf32("OtherNumber"), 0))),
                                                                                                                        new soulng::parsing::ActionParser(ToUtf32("A26"),
                                                                                                                            new soulng::parsing::NonterminalParser(ToUtf32("Punctuation"), ToUtf32("Punctuation"), 0))),
                                                                                                                    new soulng::parsing::ActionParser(ToUtf32("A27"),
                                                                                                                        new soulng::parsing::NonterminalParser(ToUtf32("ConnectorPunctuation"), ToUtf32("ConnectorPunctuation"), 0))),
                                                                                                                new soulng::parsing::ActionParser(ToUtf32("A28"),
                                                                                                                    new soulng::parsing::NonterminalParser(ToUtf32("DashPunctuation"), ToUtf32("DashPunctuation"), 0))),
                                                                                                            new soulng::parsing::ActionParser(ToUtf32("A29"),
                                                                                                                new soulng::parsing::NonterminalParser(ToUtf32("OpenPunctuation"), ToUtf32("OpenPunctuation"), 0))),
                                                                                                        new soulng::parsing::ActionParser(ToUtf32("A30"),
                                                                                                            new soulng::parsing::NonterminalParser(ToUtf32("ClosePunctuation"), ToUtf32("ClosePunctuation"), 0))),
                                                                                                    new soulng::parsing::ActionParser(ToUtf32("A31"),
                                                                                                        new soulng::parsing::NonterminalParser(ToUtf32("InitialPunctuation"), ToUtf32("InitialPunctuation"), 0))),
                                                                                                new soulng::parsing::ActionParser(ToUtf32("A32"),
                                                                                                    new soulng::parsing::NonterminalParser(ToUtf32("FinalPunctuation"), ToUtf32("FinalPunctuation"), 0))),
                                                                                            new soulng::parsing::ActionParser(ToUtf32("A33"),
                                                                                                new soulng::parsing::NonterminalParser(ToUtf32("OtherPunctuation"), ToUtf32("OtherPunctuation"), 0))),
                                                                                        new soulng::parsing::ActionParser(ToUtf32("A34"),
                                                                                            new soulng::parsing::NonterminalParser(ToUtf32("Symbol"), ToUtf32("Symbol"), 0))),
                                                                                    new soulng::parsing::ActionParser(ToUtf32("A35"),
                                                                                        new soulng::parsing::NonterminalParser(ToUtf32("MathSymbol"), ToUtf32("MathSymbol"), 0))),
                                                                                new soulng::parsing::ActionParser(ToUtf32("A36"),
                                                                                    new soulng::parsing::NonterminalParser(ToUtf32("CurrencySymbol"), ToUtf32("CurrencySymbol"), 0))),
                                                                            new soulng::parsing::ActionParser(ToUtf32("A37"),
                                                                                new soulng::parsing::NonterminalParser(ToUtf32("ModifierSymbol"), ToUtf32("ModifierSymbol"), 0))),
                                                                        new soulng::parsing::ActionParser(ToUtf32("A38"),
                                                                            new soulng::parsing::NonterminalParser(ToUtf32("OtherSymbol"), ToUtf32("OtherSymbol"), 0))),
                                                                    new soulng::parsing::ActionParser(ToUtf32("A39"),
                                                                        new soulng::parsing::NonterminalParser(ToUtf32("Separator"), ToUtf32("Separator"), 0))),
                                                                new soulng::parsing::ActionParser(ToUtf32("A40"),
                                                                    new soulng::parsing::NonterminalParser(ToUtf32("SpaceSeparator"), ToUtf32("SpaceSeparator"), 0))),
                                                            new soulng::parsing::ActionParser(ToUtf32("A41"),
                                                                new soulng::parsing::NonterminalParser(ToUtf32("LineSeparator"), ToUtf32("LineSeparator"), 0))),
                                                        new soulng::parsing::ActionParser(ToUtf32("A42"),
                                                            new soulng::parsing::NonterminalParser(ToUtf32("ParagraphSeparator"), ToUtf32("ParagraphSeparator"), 0))),
                                                    new soulng::parsing::ActionParser(ToUtf32("A43"),
                                                        new soulng::parsing::NonterminalParser(ToUtf32("Other"), ToUtf32("Other"), 0))),
                                                new soulng::parsing::ActionParser(ToUtf32("A44"),
                                                    new soulng::parsing::NonterminalParser(ToUtf32("Control"), ToUtf32("Control"), 0))),
                                            new soulng::parsing::ActionParser(ToUtf32("A45"),
                                                new soulng::parsing::NonterminalParser(ToUtf32("Format"), ToUtf32("Format"), 0))),
                                        new soulng::parsing::ActionParser(ToUtf32("A46"),
                                            new soulng::parsing::NonterminalParser(ToUtf32("Surrogate"), ToUtf32("Surrogate"), 0))),
                                    new soulng::parsing::ActionParser(ToUtf32("A47"),
                                        new soulng::parsing::NonterminalParser(ToUtf32("PrivateUse"), ToUtf32("PrivateUse"), 0))),
                                new soulng::parsing::ActionParser(ToUtf32("A48"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("Unassigned"), ToUtf32("Unassigned"), 0))),
                            new soulng::parsing::ActionParser(ToUtf32("A49"),
                                new soulng::parsing::NonterminalParser(ToUtf32("Graphic"), ToUtf32("Graphic"), 0))),
                        new soulng::parsing::ActionParser(ToUtf32("A50"),
                            new soulng::parsing::NonterminalParser(ToUtf32("BaseChar"), ToUtf32("BaseChar"), 0))),
                    new soulng::parsing::ActionParser(ToUtf32("A51"),
                        new soulng::parsing::NonterminalParser(ToUtf32("Alphabetic"), ToUtf32("Alphabetic"), 0))),
                new soulng::parsing::ActionParser(ToUtf32("A52"),
                    new soulng::parsing::NonterminalParser(ToUtf32("IdStart"), ToUtf32("IdStart"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A53"),
                new soulng::parsing::NonterminalParser(ToUtf32("IdCont"), ToUtf32("IdCont"), 0)))));
    AddRule(new CharRule(ToUtf32("Char"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::NonterminalParser(ToUtf32("chr"), ToUtf32("char"), 0))));
    AddRule(new StringRule(ToUtf32("String"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::NonterminalParser(ToUtf32("str"), ToUtf32("string"), 0))));
    AddRule(new CharSetRule(ToUtf32("CharSet"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::TokenParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::CharParser('['),
                            new soulng::parsing::OptionalParser(
                                new soulng::parsing::GroupingParser(
                                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                                        new soulng::parsing::CharParser('^'))))),
                        new soulng::parsing::KleeneStarParser(
                            new soulng::parsing::GroupingParser(
                                new soulng::parsing::ActionParser(ToUtf32("A2"),
                                    new soulng::parsing::NonterminalParser(ToUtf32("CharSetRange"), ToUtf32("CharSetRange"), 0))))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(']')))))));
    AddRule(new CharSetRangeRule(ToUtf32("CharSetRange"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::NonterminalParser(ToUtf32("first"), ToUtf32("CharSetChar"), 0),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser('-'),
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::NonterminalParser(ToUtf32("last"), ToUtf32("CharSetChar"), 0))),
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::EmptyParser()))))));
    AddRule(new CharSetCharRule(ToUtf32("CharSetChar"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::CharSetParser(ToUtf32("\\]"), true)),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::NonterminalParser(ToUtf32("escape"), ToUtf32("escape"), 0)))));
    AddRule(new KeywordRule(ToUtf32("Keyword"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::KeywordParser(ToUtf32("keyword")),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('('))),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("KeywordBody"), ToUtf32("KeywordBody"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::CharParser(')'))))));
    AddRule(new KeywordBodyRule(ToUtf32("KeywordBody"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::NonterminalParser(ToUtf32("str"), ToUtf32("string"), 0),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::AlternativeParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::CharParser(','),
                        new soulng::parsing::ActionParser(ToUtf32("A0"),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::NonterminalParser(ToUtf32("continuation"), ToUtf32("QualifiedId"), 0)))),
                    new soulng::parsing::ActionParser(ToUtf32("A1"),
                        new soulng::parsing::EmptyParser()))))));
    AddRule(new KeywordListRule(ToUtf32("KeywordList"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::KeywordParser(ToUtf32("keyword_list")),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser('('))),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("KeywordListBody"), ToUtf32("KeywordListBody"), 0))),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::CharParser(')'))))));
    AddRule(new KeywordListBodyRule(ToUtf32("KeywordListBody"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::SequenceParser(
            new soulng::parsing::SequenceParser(
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("selector"), ToUtf32("QualifiedId"), 0)),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::CharParser(','))),
            new soulng::parsing::ActionParser(ToUtf32("A0"),
                new soulng::parsing::ExpectationParser(
                    new soulng::parsing::NonterminalParser(ToUtf32("StringArray"), ToUtf32("StringArray"), 1))))));
    AddRule(new RangeRule(ToUtf32("Range"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::GroupingParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::SequenceParser(
                        new soulng::parsing::SequenceParser(
                            new soulng::parsing::SequenceParser(
                                new soulng::parsing::SequenceParser(
                                    new soulng::parsing::KeywordParser(ToUtf32("range")),
                                    new soulng::parsing::ExpectationParser(
                                        new soulng::parsing::CharParser('('))),
                                new soulng::parsing::ExpectationParser(
                                    new soulng::parsing::NonterminalParser(ToUtf32("s"), ToUtf32("CodePoint"), 0))),
                            new soulng::parsing::ExpectationParser(
                                new soulng::parsing::CharParser(','))),
                        new soulng::parsing::ExpectationParser(
                            new soulng::parsing::NonterminalParser(ToUtf32("e"), ToUtf32("CodePoint"), 0))),
                    new soulng::parsing::ExpectationParser(
                        new soulng::parsing::CharParser(')')))))));
    AddRule(new CodePointRule(ToUtf32("CodePoint"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::AlternativeParser(
            new soulng::parsing::TokenParser(
                new soulng::parsing::SequenceParser(
                    new soulng::parsing::CharParser('x'),
                    new soulng::parsing::ActionParser(ToUtf32("A0"),
                        new soulng::parsing::NonterminalParser(ToUtf32("x"), ToUtf32("hexuint"), 0)))),
            new soulng::parsing::ActionParser(ToUtf32("A1"),
                new soulng::parsing::NonterminalParser(ToUtf32("d"), ToUtf32("uint"), 0)))));
    AddRule(new EmptyRule(ToUtf32("Empty"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("empty")))));
    AddRule(new SpaceRule(ToUtf32("Space"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("space")))));
    AddRule(new AnyCharRule(ToUtf32("AnyChar"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("anychar")))));
    AddRule(new LetterRule(ToUtf32("Letter"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("letter")))));
    AddRule(new DigitRule(ToUtf32("Digit"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("digit")))));
    AddRule(new HexDigitRule(ToUtf32("HexDigit"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("hexdigit")))));
    AddRule(new UpperLetterRule(ToUtf32("UpperLetter"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("upper_letter")))));
    AddRule(new LowerLetterRule(ToUtf32("LowerLetter"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("lower_letter")))));
    AddRule(new TitleLetterRule(ToUtf32("TitleLetter"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("title_letter")))));
    AddRule(new ModifierLetterRule(ToUtf32("ModifierLetter"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("modifier_letter")))));
    AddRule(new OtherLetterRule(ToUtf32("OtherLetter"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("other_letter")))));
    AddRule(new CasedLetterRule(ToUtf32("CasedLetter"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("cased_letter")))));
    AddRule(new MarkRule(ToUtf32("Mark"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("mark")))));
    AddRule(new NonspacingMarkRule(ToUtf32("NonspacingMark"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("nonspacing_mark")))));
    AddRule(new SpacingMarkRule(ToUtf32("SpacingMark"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("spacing_mark")))));
    AddRule(new EnclosingMarkRule(ToUtf32("EnclosingMark"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("enclosing_mark")))));
    AddRule(new NumberRule(ToUtf32("Number"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("number")))));
    AddRule(new DecimalNumberRule(ToUtf32("DecimalNumber"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("decimal_number")))));
    AddRule(new LetterNumberRule(ToUtf32("LetterNumber"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("letter_number")))));
    AddRule(new OtherNumberRule(ToUtf32("OtherNumber"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("other_number")))));
    AddRule(new PunctuationRule(ToUtf32("Punctuation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("punctuation")))));
    AddRule(new ConnectorPunctuationRule(ToUtf32("ConnectorPunctuation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("connector_punctuation")))));
    AddRule(new DashPunctuationRule(ToUtf32("DashPunctuation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("dash_punctuation")))));
    AddRule(new OpenPunctuationRule(ToUtf32("OpenPunctuation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("open_punctuation")))));
    AddRule(new ClosePunctuationRule(ToUtf32("ClosePunctuation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("close_punctuation")))));
    AddRule(new InitialPunctuationRule(ToUtf32("InitialPunctuation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("initial_punctuation")))));
    AddRule(new FinalPunctuationRule(ToUtf32("FinalPunctuation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("final_punctuation")))));
    AddRule(new OtherPunctuationRule(ToUtf32("OtherPunctuation"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("other_punctuation")))));
    AddRule(new SymbolRule(ToUtf32("Symbol"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("symbol")))));
    AddRule(new MathSymbolRule(ToUtf32("MathSymbol"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("math_symbol")))));
    AddRule(new CurrencySymbolRule(ToUtf32("CurrencySymbol"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("currency_symbol")))));
    AddRule(new ModifierSymbolRule(ToUtf32("ModifierSymbol"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("modifier_symbol")))));
    AddRule(new OtherSymbolRule(ToUtf32("OtherSymbol"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("other_symbol")))));
    AddRule(new SeparatorRule(ToUtf32("Separator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("separator")))));
    AddRule(new SpaceSeparatorRule(ToUtf32("SpaceSeparator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("space_separator")))));
    AddRule(new LineSeparatorRule(ToUtf32("LineSeparator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("line_separator")))));
    AddRule(new ParagraphSeparatorRule(ToUtf32("ParagraphSeparator"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("paragraph_separator")))));
    AddRule(new OtherRule(ToUtf32("Other"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("other")))));
    AddRule(new ControlRule(ToUtf32("Control"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("control")))));
    AddRule(new FormatRule(ToUtf32("Format"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("format")))));
    AddRule(new SurrogateRule(ToUtf32("Surrogate"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("surrogate")))));
    AddRule(new PrivateUseRule(ToUtf32("PrivateUse"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("private_use")))));
    AddRule(new UnassignedRule(ToUtf32("Unassigned"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("unassigned")))));
    AddRule(new GraphicRule(ToUtf32("Graphic"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("graphic")))));
    AddRule(new BaseCharRule(ToUtf32("BaseChar"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("basechar")))));
    AddRule(new AlphabeticRule(ToUtf32("Alphabetic"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("alphabetic")))));
    AddRule(new IdStartRule(ToUtf32("IdStart"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("idstart")))));
    AddRule(new IdContRule(ToUtf32("IdCont"), GetScope(), GetParsingDomain()->GetNextRuleId(),
        new soulng::parsing::ActionParser(ToUtf32("A0"),
            new soulng::parsing::KeywordParser(ToUtf32("idcont")))));
}

} } // namespace soulng.syntax
