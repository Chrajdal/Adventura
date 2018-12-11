#include "HerniPlan.h"

HerniPlan::HerniPlan()
{
	mapa_prostoru.push_back(Prostor( /* 0  */ "byt", "Zde muzes vydelavat a telefonovat", false));
	mapa_prostoru.push_back(Prostor( /* 1  */ "hrackarstvi", "Zde muzes koupitruzne hracky", true));
	mapa_prostoru.push_back(Prostor( /* 2  */ "musicShop", "Zde muzes koupit hudebni CD", true));
	mapa_prostoru.push_back(Prostor( /* 3  */ "kvetinarstvi", "Zde muzes koupit kvetiny", true));
	mapa_prostoru.push_back(Prostor( /* 4  */ "obchodSOblecenim", "Zde muzes koupit obleceni", true));
	mapa_prostoru.push_back(Prostor( /* 5  */ "park", "Tady se muzes prochazet", false));
	mapa_prostoru.push_back(Prostor( /* 6  */ "superMarket", "Zde koupis temer vsechno", true));
	mapa_prostoru.push_back(Prostor( /* 7  */ "bytDivky", "Zde bydli tvoje pritelkyne", false));
	mapa_prostoru.push_back(Prostor( /* 8  */ "SeifertovaUlice", "Tady se muzes prochazet", false)); // ulice 1
	mapa_prostoru.push_back(Prostor( /* 9  */ "PalackehoUlice", "Tady se muzes prochazet", false));  // ulice 2
	mapa_prostoru.push_back(Prostor( /* 10 */ "ViklefovaUlice", "Tady se muzes prochazet", false));  // ulice 3
	mapa_prostoru.push_back(Prostor( /* 11 */ "zlatnictvi", "Zde muzes koupit sperky", true));


	spoj_sousedy(mapa_prostoru[0], mapa_prostoru[8]); // byt --- seifertova

	spoj_sousedy(mapa_prostoru[8], mapa_prostoru[1]);  // seifertova --- hrackarstvi
	spoj_sousedy(mapa_prostoru[8], mapa_prostoru[2]);  // seifertova --- musicShop
	spoj_sousedy(mapa_prostoru[8], mapa_prostoru[3]);  // seifertova --- kvetinarstvi
	spoj_sousedy(mapa_prostoru[8], mapa_prostoru[5]);  // seifertova --- park
	spoj_sousedy(mapa_prostoru[8], mapa_prostoru[10]); // seifertova --- viklefova
	spoj_sousedy(mapa_prostoru[8], mapa_prostoru[11]); // seifertova --- zlatnictvi

	spoj_sousedy(mapa_prostoru[2], mapa_prostoru[10]); // music --- viklefova

	spoj_sousedy(mapa_prostoru[10], mapa_prostoru[9]); // viklefova --- palackeho
	spoj_sousedy(mapa_prostoru[10], mapa_prostoru[7]); // viklefova --- bytdivky
	spoj_sousedy(mapa_prostoru[10], mapa_prostoru[4]); // viklefova --- obleceni

	spoj_sousedy(mapa_prostoru[9], mapa_prostoru[5]);  // palackeho --- park
	spoj_sousedy(mapa_prostoru[9], mapa_prostoru[4]);  // palackeho --- obleceni
	spoj_sousedy(mapa_prostoru[9], mapa_prostoru[6]);  // palackeho --- supermarket

	spoj_sousedy(mapa_prostoru[5], mapa_prostoru[3]);  // park --- kvetinarstvi
	spoj_sousedy(mapa_prostoru[5], mapa_prostoru[6]);  // park --- supermarket

	// pridani veci k nakupu do obchodu
	// hrackarstvi
	mapa_prostoru[1].pridej_vec(Vec("balonky", "nafukovaci balonky", 20, 50, true));
	mapa_prostoru[1].pridej_vec(Vec("balonky", "nafukovaci balonky", 20, 50, true));
	mapa_prostoru[1].pridej_vec(Vec("maly_plysak", "maly plysovy medvidek", 180, 120, true));
	mapa_prostoru[1].pridej_vec(Vec("velky_plysak", "velky plysovy medvidek", 500, 300, true));
	mapa_prostoru[1].pridej_vec(Vec("auticko", "maly anglicak", 250, 60, true));
	// hudebniny
	mapa_prostoru[2].pridej_vec(Vec("eminem", "nejnovejsi cd Eminema", 100, 350, true));
	mapa_prostoru[2].pridej_vec(Vec("offspring", "nejnovejsi cd Offspring", 100, 330, true));
	mapa_prostoru[2].pridej_vec(Vec("blink-182", "starsi cd blink-182", 100, 300, true));
	mapa_prostoru[2].pridej_vec(Vec("madonna", "nejnovejsi cd Madonny", 100, 380, true));
	mapa_prostoru[2].pridej_vec(Vec("marpo", "nejnovejsi cd Marpa", 100, 150, true));
	mapa_prostoru[2].pridej_vec(Vec("vypsana_fixa", "nejnovejsi cd Vypsane Fixy", 100, 250, true));
	mapa_prostoru[2].pridej_vec(Vec("evaavasek", "bila orchidej od Evy a Vaska", 100, 220, true));
	// kvetinarstvi
	mapa_prostoru[3].pridej_vec(Vec("ruze", "krasna cervena ruze", 70, 50, true));
	mapa_prostoru[3].pridej_vec(Vec("lilie", "krasna zluta lilie", 70, 70, true));
	mapa_prostoru[3].pridej_vec(Vec("orchidej", "krasna bila orchidej", 70, 60, true));
	mapa_prostoru[3].pridej_vec(Vec("listy", "listy jako ozdoba ke kytce", 20, 30, true));
	// obchod s oblecenim
	mapa_prostoru[4].pridej_vec(Vec("triko", "pekne znackove tricko", 90, 250, true));
	mapa_prostoru[4].pridej_vec(Vec("kalhoty", "pekne znackove kalhoty", 160, 690, true));
	mapa_prostoru[4].pridej_vec(Vec("mikina", "pekna znackova mikina", 150, 500, true));
	mapa_prostoru[4].pridej_vec(Vec("spodni_pradlo", "pekne znackove spodni pradlo", 10, 420, true));
	mapa_prostoru[4].pridej_vec(Vec("kostym", "zabavny kostym", 180, 350, true));
	// supermarket
	mapa_prostoru[6].pridej_vec(Vec("chipsy", "dobre bramburky", 120, 29, true));
	mapa_prostoru[6].pridej_vec(Vec("rum", "neco silnejsiho k piti", 550, 120, true));
	mapa_prostoru[6].pridej_vec(Vec("vodka", "neco silnejsiho k piti", 550, 80, true));
	mapa_prostoru[6].pridej_vec(Vec("vino", "neco lehciho k piti", 550, 180, true));
	mapa_prostoru[6].pridej_vec(Vec("cigareta", "levne cigarety", 50, 60, true));
	mapa_prostoru[6].pridej_vec(Vec("chlebicek", "vsechno, co je potreba k priprave chlebicku", 800, 130, true));
	// zlatnictvi
	mapa_prostoru[11].pridej_vec(Vec("zlate_nausnice", "nausnice vyrobene ze zlata", 5, 2800, true));
	mapa_prostoru[11].pridej_vec(Vec("stribrne_nausnice", "nausnice vyrobene ze stribra", 4, 600, true));
	mapa_prostoru[11].pridej_vec(Vec("nausnice", "levna bizuterie z Jablonce", 2, 230, true));
	mapa_prostoru[11].pridej_vec(Vec("zlaty_prstynek", "prstynek vyrobeny ze zlata", 5, 1900, true));
	mapa_prostoru[11].pridej_vec(Vec("stribrny_prstynek", "prstynek vyrobeny ze stribra", 3, 5250, true));
	mapa_prostoru[11].pridej_vec(Vec("prstynek", "bizuterie", 1, 30, true));
	
	aktualni_prostor = &mapa_prostoru[0];

	std::vector<std::string> bezdakovi_texty_pred =
	{
		std::string("Bezdomovec: 'Hele, kamo, mam tady mobil, nechces? Dam ti ho za dve krabicky.' \n")
		+ "Ty: 'To bude urcite ten muj, co sem ho vcera zratil. No co, asi mi nezbyde nez pro ty cigarety zajit.'",
		std::string("Bezdomovec: 'Pst, pod sem' \n") + "Ty: 'Promin, specham, mozna potom.'"
	};
	std::vector<std::string> bezdakovi_texty_po = { "Bezdomovec: 'dik za ty cigara, kamo'" };
	Osoba bezdomovec("bezdomovec", "pachnouci bezdak", bezdakovi_texty_pred, bezdakovi_texty_po);
	bezdomovec.nastav_kyzenou_vec("cigareta", 2);
	bezdomovec.pridej_vec(Vec("mobil", "tvuj ztraceny mobil", 350, 5000, true));

	mapa_prostoru[5].pridej_osoby(bezdomovec); // bezdomovec 'parkuje' v parku
	
	std::string divkaKvetina, divkaHudba, divkaObleceni, divkaSperky, divkaAlkohol;
	{
		auto kvetiny = { "ruze", "lilie", "orchidej" };
		divkaKvetina = *(kvetiny.begin() + rand() % kvetiny.size());
	}
	{
		auto hudba = { "eminem","offspring","blink-182","madonna","marpo","vypsana_fixa" };
		divkaHudba = *(hudba.begin() + rand() % hudba.size());
	}
	{
		auto obleceni = { "triko","kalhoty","mikina","spodni_pradlo","kostym" };
		divkaObleceni = *(obleceni.begin() + rand() % obleceni.size());
	}
	{
		auto sperky = { "zlate_nausnice","stribrne_nausnice","nausnice","zlaty_prstynek","stribrny_prstynek","prstynek" };
		divkaSperky = *(sperky.begin() + rand() % sperky.size());		
	}
	{
		auto alkohol = { "rum","vodka","basa_piva","vino" };
		divkaAlkohol = *(alkohol.begin() + rand() % alkohol.size());
	}

	std::vector<std::string> paja_texty_pred =
	{
		"Paja: 'Moc se tesim na vecer.'",
		"Paja: 'Vcera jsem byla s kamaradkou venku, bylo to super.'",
		"Paja: 'Slusi mi to dneska? Co myslis?'",
		"Paja: 'Moje nejoblibenejsi kytka je rozhodne " + divkaKvetina + "'",
		"Paja: 'Nejradsi si pustim " + divkaHudba + "'",
		"Paja: 'Docela by se mi ted hodilo nejaky obleceni, treba " + divkaObleceni + ".'",
		"Paja: 'Hrozne bych si prala " + divkaSperky + ".'",
		"Paja: 'No, vzdyt vis, ze moc nepiju, ale kdyz uz, tak bych si dala jedine " + divkaAlkohol + ".'",
		"Paja: 'Segra je ted nejaka nemocna, snad to nechytnu od ni.'",
		"Paja: 'Vis, ze budeme mit pejska? To je super, vid?'"
	};
	std::vector<std::string> paja_texty_po =
	{
		
	};

	Osoba divka("paja", "tvoje divka", paja_texty_pred, paja_texty_po);
	mapa_prostoru[7].pridej_osoby(divka);
}

HerniPlan::~HerniPlan()
{
}

bool HerniPlan::jdi(const std::string & kam)
{
	if (aktualni_prostor->je_vychod(kam) == true)
	{
		for(auto & i : mapa_prostoru)
			if (i.get_jmeno() == kam)
			{
				aktualni_prostor = &i;
				return true;
			}
	}
	return false;
}

bool HerniPlan::pozvi_cloveka(const Osoba & o)
{
	auto result = pozvani_lide.insert(o);
	return result.second;
}
