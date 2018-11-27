#include "HerniPlan.h"

HerniPlan::HerniPlan()
{
	 mapa_prostoru.push_back(Prostor( /* 0  */ "byt", "Zde muzes vydelavat a telefonovat", false));
	 mapa_prostoru.push_back(Prostor( /* 1  */ "hrackarstvi", "Zde koupis plysaky, balonky a dalsi hracky", true));
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

	// todo
	// spojit sousedy
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
