#include <LibraryXml/Register.hpp>
#include <LibraryXml/Factory.hpp>
#include <LibraryXml/Library.hpp>
#include <LibraryXml/Person.hpp>
#include <LibraryXml/Group.hpp>
#include <LibraryXml/Query.hpp>
#include <Query/Register.hpp>
#include <Config/InitDone.hpp>
#include <Config/Config.hpp>
#include <sngxml/serialization/InitDone.hpp>
#include <sngxml/xpath/InitDone.hpp>
#include <soulng/util/InitDone.hpp>
#include <soulng/util/CodeFormatter.hpp>
#include <soulng/util/Unicode.hpp>
#include <iostream>
#include <fstream>

void InitApplication()
{
    soulng::util::Init();
    sngxml::xpath::Init();
    sngxml::xmlser::Init();
    config::Init();
}

using soulng::util::CodeFormatter;

using namespace library_xml;
using namespace sngxml::xmlser;
using namespace config;

const int helsinki_id = 0;
const int tampere_id = 1;
const int oulu_id = 2;

const int bjarne_stroustrup_id = 3;
const int erich_gamma_id = 4;
const int richard_helm_id = 5;
const int ralph_johnson_id = 6;
const int john_vlissides_id = 7;
const int donald_knuth_id = 8;

const int gof_id = 9;

const int the_cpp_programming_language_id = 10;
const int design_patterns_id = 11;
const int the_art_of_programming_id = 12;

const int alfred_aho_id = 13;
const int monica_lam_id = 14;
const int ravi_sethi_id = 15;
const int jeffrey_ullman_id = 16;

const int compilers_writers_id = 17;

const int compilers_id = 18;

const int eagles_id = 19;
const int glenn_frey_id = 20;
const int don_henley_id = 21;
const int joe_walsh_id = 22;
const int timothy_schmit_id = 23;

const int hotel_california_record_id = 24;

const int raid_team_id = 25;
const int raid_id = 26;
const int kai_lehtinen_id = 27;
const int tapio_piirainen_id = 28;
const int oiva_lohtander_id = 29;

const int forrest_gump_id = 30;
const int forrest_gump_team_id = 31;
const int tom_hanks_id = 32;
const int hanna_hall_id = 33;
const int gary_sinise_id = 34;

const int hotel_california_piece_id = 35;
const int new_kid_in_town_id = 36;
const int life_in_the_fast_lane_id = 37;
const int wasted_time_id = 38;

const int programming_principles_and_practice_id = 39;
const int tour_of_cpp_id = 40;

void MakeHelsinki()
{
    unique_xml_ptr<Library> library(MakeLibrary("helsinki", GetId(helsinki_id)));

    library->Add(MakePerson("Bjarne Stroustrup", soulng::util::ParseDate("19501230"), GetId(bjarne_stroustrup_id)));
    library->Add(MakePerson("Eric Gamma", soulng::util::ParseDate("19610101"), GetId(erich_gamma_id)));
    library->Add(MakePerson("Richard Helm", soulng::util::ParseDate("19010101"), GetId(richard_helm_id)));
    library->Add(MakePerson("Ralph Johnson", soulng::util::ParseDate("19550710"), GetId(ralph_johnson_id)));
    library->Add(MakePerson("John Vlissides", soulng::util::ParseDate("19610802"), GetId(john_vlissides_id)));
    library->Add(MakePerson("Donald Knuth", soulng::util::ParseDate("19380110"), GetId(donald_knuth_id)));

    Group* gof = MakeGroup("GoF", GetId(gof_id));
    gof->AddMember(library->GetPerson(GetId(erich_gamma_id)));
    gof->AddMember(library->GetPerson(GetId(richard_helm_id)));
    gof->AddMember(library->GetPerson(GetId(ralph_johnson_id)));
    gof->AddMember(library->GetPerson(GetId(john_vlissides_id)));
    library->Add(gof);

    library->Add(MakeBook("The C++ Programming Language", soulng::util::ParseDate("20130101"), library->GetPerson(GetId(bjarne_stroustrup_id)), GetId(the_cpp_programming_language_id)));
    library->Add(MakeBook("Programming: Principles and Pactice Using C++", soulng::util::ParseDate("20090101"), library->GetPerson(GetId(bjarne_stroustrup_id)), GetId(programming_principles_and_practice_id)));
    library->Add(MakeBook("Design Patterns", soulng::util::ParseDate("19950101"), gof, GetId(design_patterns_id)));
    library->Add(MakeBook("The Art of Computer Programming", soulng::util::ParseDate("19970101"), library->GetPerson(GetId(donald_knuth_id)), GetId(the_art_of_programming_id)));

    std::unique_ptr<XmlBundle> bundle = library->Container()->CreateBundle(library.Get(), XmlBundleKind::deep);
    std::unique_ptr<sngxml::dom::Document> bundleDoc = bundle->ToXmlDocument();

    std::string helsinkiFilePath = GetLibraryFilePath("helsinki");
    std::ofstream helsinkiFile(helsinkiFilePath);
    CodeFormatter formatter(helsinkiFile);
    formatter.SetIndentSize(1);
    bundleDoc->Write(formatter);

    AddLibrary("helsinki");
}

void MakeTampere()
{
    unique_xml_ptr<Library> library(MakeLibrary("tampere", GetId(tampere_id)));

    library->Add(MakePerson("Bjarne Stroustrup", soulng::util::ParseDate("19501230"), GetId(bjarne_stroustrup_id)));
    library->Add(MakePerson("Alfred V. Aho", soulng::util::ParseDate("19410809"), GetId(alfred_aho_id)));
    library->Add(MakePerson("Monica S. Lam", soulng::util::ParseDate("19000101"), GetId(monica_lam_id)));
    library->Add(MakePerson("Ravi Sethi", soulng::util::ParseDate("19470101"), GetId(ravi_sethi_id)));
    library->Add(MakePerson("Jeffrey D. Ullman", soulng::util::ParseDate("19421022"), GetId(jeffrey_ullman_id)));

    library->Add(MakeGroup("compilers writers", GetId(compilers_writers_id)));
    Group* compilersWritersGroup = library->GetGroup(GetId(compilers_writers_id));
    compilersWritersGroup->AddMember(library->GetPerson(GetId(alfred_aho_id)));
    compilersWritersGroup->AddMember(library->GetPerson(GetId(monica_lam_id)));
    compilersWritersGroup->AddMember(library->GetPerson(GetId(ravi_sethi_id)));
    compilersWritersGroup->AddMember(library->GetPerson(GetId(jeffrey_ullman_id)));

    library->Add(MakeBook("The C++ Programming Language", soulng::util::ParseDate("20130101"), library->GetPerson(GetId(bjarne_stroustrup_id)), GetId(the_cpp_programming_language_id)));
    library->Add(MakeBook("A Tour of C++", soulng::util::ParseDate("20180101"), library->GetPerson(GetId(bjarne_stroustrup_id)), GetId(tour_of_cpp_id)));

    library->Add(MakeBook("Compilers: Principles, Techniques & Tools", soulng::util::ParseDate("19860101"), compilersWritersGroup, GetId(compilers_id)));

    library->Add(MakePerson("Glenn Frey", soulng::util::ParseDate("19481106"), GetId(glenn_frey_id)));
    library->Add(MakePerson("Don Henley", soulng::util::ParseDate("19470822"), GetId(don_henley_id)));
    library->Add(MakePerson("Joe Walsh", soulng::util::ParseDate("19471120"), GetId(joe_walsh_id)));
    library->Add(MakePerson("Timothy B. Schmit", soulng::util::ParseDate("19471030"), GetId(timothy_schmit_id)));

    library->Add(MakeGroup("Eagles", GetId(eagles_id)));
    Group* eagles = library->GetGroup(GetId(eagles_id));
    eagles->AddMember(library->GetPerson(GetId(glenn_frey_id)));
    eagles->AddMember(library->GetPerson(GetId(don_henley_id)));
    eagles->AddMember(library->GetPerson(GetId(joe_walsh_id)));
    eagles->AddMember(library->GetPerson(GetId(timothy_schmit_id)));

    library->Add(MakeRecord("Hotel California", soulng::util::ParseDate("19760101"), eagles, GetId(hotel_california_record_id)));
    Record* hotelCalifornia = library->GetRecord(GetId(hotel_california_record_id));
    library->Add(MakePiece("Hotel California", soulng::util::ParseDate("19760101"), eagles, hotelCalifornia, GetId(hotel_california_piece_id)));
    library->Add(MakePiece("New Kid in Town", soulng::util::ParseDate("19760101"), eagles, hotelCalifornia, GetId(new_kid_in_town_id)));
    library->Add(MakePiece("Life in the Fast Lane", soulng::util::ParseDate("19760101"), eagles, hotelCalifornia, GetId(life_in_the_fast_lane_id)));
    library->Add(MakePiece("Wasted Time", soulng::util::ParseDate("19760101"), eagles, hotelCalifornia, GetId(wasted_time_id)));

    std::unique_ptr<XmlBundle> bundle = library->Container()->CreateBundle(library.Get(), XmlBundleKind::deep);
    std::unique_ptr<sngxml::dom::Document> bundleDoc = bundle->ToXmlDocument();

    std::string tampereFilePath = GetLibraryFilePath("tampere");
    std::ofstream tampereFile(tampereFilePath);
    CodeFormatter formatter(tampereFile);
    formatter.SetIndentSize(1);
    bundleDoc->Write(formatter);

    AddLibrary("tampere");
}

void MakeOulu()
{
    unique_xml_ptr<Library> library(MakeLibrary("oulu", GetId(oulu_id)));

    library->Add(MakePerson("Donald Knuth", soulng::util::ParseDate("19380110"), GetId(donald_knuth_id)));

    library->Add(MakeBook("The Art of Computer Programming", soulng::util::ParseDate("19970101"), library->GetPerson(GetId(donald_knuth_id)), GetId(the_art_of_programming_id)));

    library->Add(MakePerson("Kai Lehtinen", soulng::util::ParseDate("19580731"), GetId(kai_lehtinen_id)));
    library->Add(MakePerson("Oiva Lohtander", soulng::util::ParseDate("19420415"), GetId(oiva_lohtander_id)));
    library->Add(MakePerson("Tapio Piirainen", soulng::util::ParseDate("19540101"), GetId(tapio_piirainen_id)));

    library->Add(MakeGroup("Raid team", GetId(raid_team_id)));
    Group* raidTeam = library->GetGroup(GetId(raid_team_id));
    raidTeam->AddMember(library->GetPerson(GetId(kai_lehtinen_id)));
    raidTeam->AddMember(library->GetPerson(GetId(oiva_lohtander_id)));
    raidTeam->AddMember(library->GetPerson(GetId(tapio_piirainen_id)));

    library->Add(MakeFilm("Raid", soulng::util::ParseDate("20000101"), raidTeam, GetId(raid_id)));

    library->Add(MakePerson("Tom Hanks", soulng::util::ParseDate("19560709"), GetId(tom_hanks_id)));
    library->Add(MakePerson("Hanna R. Hall", soulng::util::ParseDate("19840709"), GetId(hanna_hall_id)));
    library->Add(MakePerson("Gary Sinise", soulng::util::ParseDate("19550317"), GetId(gary_sinise_id)));

    library->Add(MakeGroup("Forrest Gump team", GetId(forrest_gump_team_id)));
    Group* forrestGumpTeam = library->GetGroup(GetId(forrest_gump_team_id));
    forrestGumpTeam->AddMember(library->GetPerson(GetId(tom_hanks_id)));
    forrestGumpTeam->AddMember(library->GetPerson(GetId(hanna_hall_id)));
    forrestGumpTeam->AddMember(library->GetPerson(GetId(gary_sinise_id)));

    library->Add(MakeFilm("Forrest Gump", soulng::util::ParseDate("19940706"), forrestGumpTeam, GetId(forrest_gump_id)));

    std::unique_ptr<XmlBundle> bundle = library->Container()->CreateBundle(library.Get(), XmlBundleKind::deep);
    std::unique_ptr<sngxml::dom::Document> bundleDoc = bundle->ToXmlDocument();

    std::string ouluFilePath = GetLibraryFilePath("oulu");
    std::ofstream ouluFile(ouluFilePath);
    CodeFormatter formatter(ouluFile);
    formatter.SetIndentSize(1);
    bundleDoc->Write(formatter);

    AddLibrary("oulu");
}

void MakeLibraries()
{
    ClearLibraries();
    MakeHelsinki();
    MakeTampere();
    MakeOulu();
}

int main()
{
    try
    {
        InitApplication();
        library_xml::Register();
        query::Register();
        MakeLibraries();
        config::SaveIds();
        config::SaveConfiguration();
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}

