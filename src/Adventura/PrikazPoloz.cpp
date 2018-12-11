#include "PrikazPoloz.h"

#include "Hra.h"

PrikazPoloz::PrikazPoloz(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan), odkaz_na_batoh(batoh)
{
}


PrikazPoloz::~PrikazPoloz()
{
}

void PrikazPoloz::proved(const std::vector<std::string> & parametry)
{
	if (parametry.size() == 0)
	{
		std::cout << "Nevim co mam polozit.\n";
	}
	else if (parametry.size() == 1)
	{
		auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor();

		auto vec = odkaz_na_batoh->vrat_vec(parametry[0]);
		if (vec.jmeno() == "")
		{
			std::cout << "Tato vec v batohu neni.\n";
			return;
		}

		if (aktualni_prostor->je_obchod() == true)
		{
			std::cout << "Vec " << vec.jmeno() 
				<< " byla polozena, ovsem pracovnici obchodu ji rychle uklidili, proto uz nebude nadale dostupna.\n";

			odkaz_na_batoh->odeber_vec(vec.jmeno());
		}
		else
		{
			std::cout << "Vec " << vec.jmeno() << " byla polozena a zustane v prostoru.\n";

			aktualni_prostor->poloz_vec(vec);
			odkaz_na_batoh->odeber_vec(vec.jmeno());
		}
	}
	else
	{
		std::cout << "Nelze polozit vice veci najednou.\n";
	}
}

std::string PrikazPoloz::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}

std::string PrikazPoloz::pouziti(void)const
{
	return "poloz <co>";
}