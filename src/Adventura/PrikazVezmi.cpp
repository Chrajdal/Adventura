#include "PrikazVezmi.h"

#include "Hra.h"

PrikazVezmi::PrikazVezmi(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan), odkaz_na_batoh(batoh)
{
}

PrikazVezmi::~PrikazVezmi()
{
}

void PrikazVezmi::proved(const std::vector<std::string> & parametry)
{ 
	if (parametry.size() == 0)
	{
		std::cout << "Nevim co mam vzit.\n";
	}
	else if (parametry.size() == 1)
	{
		auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor();
		
		auto vec = aktualni_prostor->vyber_vec(parametry[0]);
		if (vec.jmeno() == "")
		{
			std::cout << "Tato vec v prostoru neni.\n";
			return;
		}

		if (aktualni_prostor->je_obchod())
		{
			std::cout << "V obchode nemuzes veci jen tak brat, to by byla kradez! Pouzij prikaz kup.\n";
			return;
		}

		aktualni_prostor->odeber_vec(vec.jmeno());
		odkaz_na_batoh->pridej_vec(vec);

		std::cout << "Vec '" << parametry[0] << "' se nyni nachazi ve tvem batohu.\n";
	}
	else
	{
		std::cout << "Nelze vzit vice veci najednou.\n";
	}
}

std::string PrikazVezmi::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}

std::string PrikazVezmi::pouziti(void)const
{
	return "vezmi <co>";
}