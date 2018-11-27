#include "PrikazJdi.h"

#include "Hra.h"

PrikazJdi::PrikazJdi(const std::string & nazev, Hra * hra, HerniPlan * herni_plan)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan)
{
}

PrikazJdi::~PrikazJdi()
{
}

void PrikazJdi::proved(const std::vector<std::string> & parametry)
{
	if (parametry.size() == 1)
	{

	}
	else
	{
		if (parametry.size() == 0)
		{
			std::cout <<
				std::string("+-----------------------------------------------------------------------------+\n") +
				std::string("|                Kam mam jit? Musis zadat jmeno mistnosti                     |\n") +
				std::string("+-----------------------------------------------------------------------------+\n");
		}
		if (parametry.size() > 1)
		{
			std::cout <<
				std::string("+-----------------------------------------------------------------------------+\n") +
				std::string("|                Nemuzes jit do vice mistnosti najednou                       |\n") +
				std::string("+-----------------------------------------------------------------------------+\n");
		}
	}
}

std::string PrikazJdi::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}
