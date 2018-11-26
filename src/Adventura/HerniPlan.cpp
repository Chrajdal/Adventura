#include "HerniPlan.h"



HerniPlan::HerniPlan()
{
	mapa_prostoru.push_back(Prostor("byt", "Zde muzes vydelavat a telefonovat", false));
	aktualni_prostor = &mapa_prostoru[0];

	mapa_prostoru.push_back(Prostor("hrackarstvi", "Zde koupis plysaky, balonky a dalsi hracky", true));
	mapa_prostoru.push_back(Prostor("musicShop", "Zde muzes koupit hudebni CD", true));
	mapa_prostoru.push_back(Prostor("kvetinarstvi", "Zde muzes koupit kvetiny", true));
	mapa_prostoru.push_back(Prostor("obchodSOblecenim", "Zde muzes koupit obleceni", true));
	mapa_prostoru.push_back(Prostor("park", "Tady se muzes prochazet", false));
	mapa_prostoru.push_back(Prostor("superMarket", "Zde koupis temer vsechno", true));
	mapa_prostoru.push_back(Prostor("bytDivky", "Zde bydli tvoje pritelkyne", false));
	mapa_prostoru.push_back(Prostor("SeifertovaUlice", "Tady se muzes prochazet", false));
	mapa_prostoru.push_back(Prostor("PalackehoUlice", "Tady se muzes prochazet", false));
	mapa_prostoru.push_back(Prostor("ViklefovaUlice", "Tady se muzes prochazet", false));
	mapa_prostoru.push_back(Prostor("zlatnictvi", "Zde muzes koupit sperky", true));

	// todo
	// pridat veci k nakupu do obchodu

	// todo
	// spojit sousedy
}


HerniPlan::~HerniPlan()
{
}
