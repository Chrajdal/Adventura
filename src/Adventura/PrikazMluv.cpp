#include "PrikazMluv.h"

#include "Hra.h"

PrikazMluv::PrikazMluv(const std::string & nazev, Hra * hra, HerniPlan * herni_plan)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan)
{
}

PrikazMluv::~PrikazMluv()
{
}

void PrikazMluv::proved(const std::vector<std::string> & parametry)
{
	if (parametry.empty())
	{
		std::cout << "Nemam s kym mluvit.\n";
	}
	else if(parametry.size() == 1)
	{
		auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor();

		auto osoba = aktualni_prostor->get_osoba(parametry[0]);
		if (osoba == nullptr)
		{
			std::cout << "Tato osoba v prostoru neni.\n";
		}
		else
		{
			std::cout << osoba->vrat_hlasku() << '\n';
		}
	}
	else
	{
		std::cout << "Nelze mluvit s vice lidmi najednou.\n";
	}
}

std::string PrikazMluv::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}

std::string PrikazMluv::pouziti(void)const
{
	return "mluv <s_kym>";
}
