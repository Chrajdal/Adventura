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

	// todo
	// pridat veci k nakupu do obchodu

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

	//std::cout << "----------------------------DEBUG--------------------\n";
	//for (const auto & i : mapa_prostoru)
	//{
	//	std::cout << i.get_popis() << " vychody : ";
	//	i.vypis_vychody();
	//	std::cout << '\n';
	//}
	//std::cout << "----------------------------DEBUG--------------------\n";

	aktualni_prostor = &mapa_prostoru[0];

	std::vector<std::string> bezdakovi_texty_pred =
	{
		std::string("Bezdomovec: 'Hele, kamo, mam tady mobil, nechces? Dam ti ho za dve krabicky.' \n")
		+ "Ty: 'To bude urcite ten muj, co sem ho vcera zratil. No co, asi mi nezbyde nez pro ty cigarety zajit.'",
		std::string("Bezdomovec: 'Pst, pod sem' \n") + "Ty: 'Promin, specham, mozna potom.'"
	};
	std::vector<std::string> bezdakovi_texty_po = { "Bezdomovec: 'dik za ty cigara, kamo'" };
	Osoba bezdomovec("bezdomovec", "pachnouci bezdak", bezdakovi_texty_pred, bezdakovi_texty_po);
	bezdomovec.nastav_kyzenou_vec("cigarety", 2);

	mapa_prostoru[5].pridej_osoby(bezdomovec); // bezdomovec 'parkuje' v parku
	
	std::string divkaKvetina, divkaHudba, divkaObleceni, divkaSperky, divkaAlkohol;
	{
		auto kvetiny = { "ruze", "lilie", "orchidej" };
		divkaKvetina = *(kvetiny.begin() + rand() % kvetiny.size());
	}
	{
		auto hudba = { "Eminem","Offspring","blink-182","Madonna","Marpo","VypsanaFixa" };
		divkaHudba = *(hudba.begin() + rand() % hudba.size());
	}
	{
		auto obleceni = { "triko","kalhoty","mikina","spodnipradlo","kostym" };
		divkaObleceni = *(obleceni.begin() + rand() % obleceni.size());
	}
	{
		auto sperky = { "zlateNausnice","stribrneNausnice","nausnice","zlatyPrstynek","stribrnyPrstynek","prstynek" };
		divkaSperky = *(sperky.begin() + rand() % sperky.size());		
	}
	{
		auto alkohol = { "rum","vodka","basapiva","vino" };
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
		"Paja: 'No, vzdyt vis, ze moc nepiju, ale kdyz uz, tak bych jedine " + divkaAlkohol + ".'",
		"Paja: 'Segra je ted nejaka nemocna, snad to nechytnu od ni.'",
		"Paja: 'Vis, ze budeme mit pejska? To je super, vid?'" 
	};
	std::vector<std::string> paja_texty_po =
	{
		
	};

	Osoba divka("Paja", "tvoje divka", paja_texty_pred, paja_texty_po);
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

void HerniPlan::pozvi_cloveka(const Osoba & o)
{

}
