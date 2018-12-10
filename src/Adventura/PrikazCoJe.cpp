#include "PrikazCoJe.h"

#include "Hra.h"

PrikazCoJe::PrikazCoJe(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan), odkaz_na_batoh(batoh)
{
}

PrikazCoJe::~PrikazCoJe()
{
}

void PrikazCoJe::proved(const std::vector<std::string> & parametry)
{
	if (parametry.size() == 1)
	{
		if (parametry[0] == "tady")
		{
			auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor();
			aktualni_prostor->vypis_osoby();
			aktualni_prostor->vypis_veci();
			return;
		}
		if (parametry[0] == "batoh")
		{
			auto seznam_veci = odkaz_na_batoh->seznam_veci();
			if (seznam_veci.empty())
				std::cout << "V batohu nemas zadne veci.\n";
			else
			{
				for (const auto & i : seznam_veci)
				{
					std::cout << i.first.jmeno() << " - " << i.second << "x, ";
				}
				std::cout << '\n';
			}
			
			std::cout << "Mas " << odkaz_na_batoh->get_penize() << " korun.\n";
			return;
		}
	}
	
	std::cout << "Prikaz coje musi mit prave jeden parametr.\n";
}

std::string PrikazCoJe::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}

std::string PrikazCoJe::pouziti(void)const
{
	return "coje <tady|batoh>";
}