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

	inline Prostor * get_byt(void)
	{
		return &mapa_prostoru[0];
	}

	inline Osoba * get_divka(void)
	{
		return mapa_prostoru[7].get_osoba("paja");
	}

private:
	std::vector<Prostor> mapa_prostoru;
	Prostor * aktualni_prostor;

	std::set<Osoba> pozvani_lide;
};
