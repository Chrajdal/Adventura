#include "PrikazKup.h"

#include "Hra.h"

PrikazKup::PrikazKup(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan), odkaz_na_batoh(batoh)
{
}

PrikazKup::~PrikazKup()
{
}


void PrikazKup::proved(const std::vector<std::string> & parametry)
{
	if(parametry.empty())
	{
		std::cout << "Nevim co mam koupit.\n";
	}
	else if (parametry.size() == 1)
	{
		auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor();
		if (aktualni_prostor->je_obchod() == true)
		{
			if (aktualni_prostor->je_vec_v_prostoru(parametry[0]) == false)
			{
				std::cout << "Tato vec v obchodu neni, pokud je na zemi neco polozeno, pouzij prikaz 'vezmi'.\n";
				return;
			}

			int cena = aktualni_prostor->get_cena(parametry[0]);
			if (cena > odkaz_na_batoh->get_penize())
			{
				std::cout << "Na tuto vec nemas dostatek penez.\n";
				return;
			}
			else
			{
				aktualni_prostor->prodej_vec(parametry[0]);
				odkaz_na_batoh->pridej_vec(parametry[0]);
				odkaz_na_batoh->pridej_penize(-cena);

				std::cout << "Vec " << parametry[0] << " byla koupena a nachazi se nyni ve tvem batohu.\n";
				return;
			}
		}
		else
		{
			std::cout << "Tento prostor neni obchod, pokud je na zemi neco polozeno, pouzij prikaz 'vezmi'.\n";
			return;
		}
	}
	else
	{
		std::cout << "Neni mozne koupit dve veci zaroven.\n";
	}
}

std::string PrikazKup::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}

std::string PrikazKup::pouziti(void)const
{
	return "kup <co>";
}