#pragma once

#include <vector>
#include <set>

#include "Prostor.h"

class HerniPlan
{
public:
	HerniPlan();
	~HerniPlan();

	inline Prostor * get_aktualni_prostor(void) const
	{
		return aktualni_prostor;
	}

	bool jdi(const std::string & kam);

	bool pozvi_cloveka(const Osoba & o);

private:
	std::vector<Prostor> mapa_prostoru;
	Prostor * aktualni_prostor;

	std::set<Osoba> pozvani_lide;
};
