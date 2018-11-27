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
		//std::cout << "----------------------------DEBUG--------------------\n";
		//std::cout << odkaz_na_plan->get_aktualni_prostor()->get_jmeno() << std::endl;
		//odkaz_na_plan->get_aktualni_prostor()->vypis_vychody();
		//std::cout << "----------------------------DEBUG--------------------\n";
		if (odkaz_na_plan->jdi(parametry[0]) == true)
		{
			auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor()->get_jmeno();
			int mezer = 36 - aktualni_prostor.size();
			std::cout <<
				std::string("+-----------------------------------------------------------------------------+\n") +
				std::string("|                          Jsi v prostoru ") + 
				                                 aktualni_prostor + std::string(mezer, ' ') + std::string("|\n") +
				std::string("+-----------------------------------------------------------------------------+\n");
		}
		else
		{
			std::cout <<
				std::string("+-----------------------------------------------------------------------------+\n") +
				std::string("|                          Tam se odsud jit neda                              |\n") +
				std::string("+-----------------------------------------------------------------------------+\n");
		}
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
