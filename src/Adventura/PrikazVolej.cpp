#include "PrikazVolej.h"

#include "Hra.h"

PrikazVolej::PrikazVolej(const std::string & nazev, Hra * hra, HerniPlan * herni_plan)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan)
{
}

PrikazVolej::~PrikazVolej()
{
}

void PrikazVolej::proved(const std::vector<std::string>& parametry)
{
	if (parametry.empty())
	{
		std::cout << "Musis zadat komu volat. Pokud ani sam nevis, komu muzes zavolat, napis 'volej koho'.\n";
	}
	else if (parametry.size() > 1)
	{
		std::cout << "Nelze volat vice lidem najednou.\n";
	}
	else
	{
		if (parametry[0] == "koho")
		{
			
		}
	}
}

std::string PrikazVolej::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}