#pragma once

#include <vector>

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
private:
	std::vector<Prostor> mapa_prostoru;
	Prostor * aktualni_prostor;
};
