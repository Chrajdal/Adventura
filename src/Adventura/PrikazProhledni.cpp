#include "PrikazProhledni.h"

#include "Hra.h"

PrikazProhledni::PrikazProhledni(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan), odkaz_na_batoh(batoh)
{
}

PrikazProhledni::~PrikazProhledni()
{
}

void PrikazProhledni::proved(const std::vector<std::string> & parametry)
{
	if (parametry.size() == 1)
	{
		auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor();

		auto prohlizena_vec = aktualni_prostor->vyber_vec(parametry[0]);

		std::cout << prohlizena_vec << '\n';
	}
	else if (parametry.empty())
	{
		std::cout << "Nevim co si mam prohlednout.\n";
	}
	else
	{
		std::cout << "Nelze prohlizet vice veci najednou.\n";
	}
}

std::string PrikazProhledni::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}

std::string PrikazProhledni::pouziti(void)const
{
	return "prohledni <co>";
}