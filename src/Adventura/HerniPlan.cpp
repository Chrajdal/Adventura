#include "HerniPlan.h"



HerniPlan::HerniPlan()
{
	mapa_prostoru.push_back(Prostor("byt", "Zde muzes vydelavat a telefonovat", false));
	aktualni_prostor = &mapa_prostoru[0];
}


HerniPlan::~HerniPlan()
{
}
