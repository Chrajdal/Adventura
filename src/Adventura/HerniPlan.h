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
private:
	std::vector<Prostor> mapa_prostoru;
	Prostor * aktualni_prostor;
};
