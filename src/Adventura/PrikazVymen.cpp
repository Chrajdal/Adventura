#include "PrikazVymen.h"

#include "Hra.h"

PrikazVymen::PrikazVymen(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan), odkaz_na_batoh(batoh)
{
}

PrikazVymen::~PrikazVymen()
{
}

void PrikazVymen::proved(const std::vector<std::string> & parametry)
{
	if (parametry.size() == 0)
	{
		std::cout << "Nevim s kym ani co mam vymenit.\n";
	}
	else if (parametry.size() == 1)
	{
		std::cout << "Nevim co mam vymenit.\n";
	}
	else if (parametry.size() == 2)
	{
		std::cout << "Nevim za co mam vymenit vec.\n";
	}
	else if (parametry.size() == 3)
	{
		auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor();

		auto osoba = aktualni_prostor->get_osoba(parametry[0]);
		if (osoba == nullptr)
		{
			std::cout << "Tato osoba v prostoru neni.\n";
			return;
		}

		auto moje_vec = odkaz_na_batoh->vrat_vec(parametry[1]);
		if (moje_vec.jmeno() == "")
		{
			std::cout << "Tuto vec v batohu nemam.\n";
			return;
		}

		auto cizi_vec = osoba->vrat_vec(parametry[2]);
		if (cizi_vec.jmeno() == "")
		{
			std::cout << "Po teto veci osoba netouzi, zkus vymenit za jinou.\n";
			return;
		}

		int kyzeny_pocet = osoba->vec_kterou_chci().begin()->second;
		if (odkaz_na_batoh->pocet_veci(moje_vec.jmeno()) < kyzeny_pocet)
		{
			std::cout << "Nemas dostatecny pocet veci, ktere chces vymenit.\n";
			return;
		}

		for (int i = 0; i < kyzeny_pocet; ++i)
		{
			odkaz_na_batoh->odeber_vec(moje_vec.jmeno());
			osoba->pridej_vec(moje_vec);
		}
		
		osoba->odeber_vec(cizi_vec.jmeno());
		odkaz_na_batoh->pridej_vec(cizi_vec);
		
		std::cout << "Vec '" << cizi_vec.jmeno() << "' se nyni nachazi ve tvem batohu.\n";
	}
	else
	{
		std::cout << "Nelze vymenovat vice veci najednou.\n";
	}
}

std::string PrikazVymen::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}

std::string PrikazVymen::pouziti(void)const
{
	return "vezmi <s_kym> <vec_osoby> <tvoje_vec>";
}