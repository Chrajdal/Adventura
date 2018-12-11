#include "PrikazDej.h"

#include "Hra.h"

PrikazDej::PrikazDej(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan), odkaz_na_batoh(batoh)
{
}

PrikazDej::~PrikazDej()
{
}

void PrikazDej::proved(const std::vector<std::string> & parametry)
{
	if (parametry.size() == 0)
	{
		std::cout << "Nevim komu a co mam dat.\n";
	}
	else if (parametry.size() == 1)
	{
		std::cout << "Nevim co mam dat.\n";
	}
	else if (parametry.size() == 2)
	{
		auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor();
		if (aktualni_prostor->je_osoba_v_prostoru(parametry[0]) == false)
		{
			std::cout << "Nelze predat veci osobe, ktera neni v prostoru.\n";
			return;
		}
		
		bool je_v_batohu = odkaz_na_batoh->mam_vec(parametry[1]);
		if (je_v_batohu == false)
		{
			std::cout << "Nelze predat vec, kterou nemas v batohu.\n";
			return;
		}

		auto osoba = aktualni_prostor->get_osoba(parametry[0]);
		osoba->pridej_vec(parametry[1], 1);
		odkaz_na_batoh->odeber_vec(parametry[1]);

		std::cout << "Dal jsi vec " << parametry[1] << " osobe " << parametry[0] << '\n';
	}
	else
	{
		std::cout << "Nelze dat vice veci najednou.\n";
	}
}

std::string PrikazDej::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}

std::string PrikazDej::pouziti(void)const
{
	return "dej <komu> <co>";
}