#include "PrikazVolej.h"

#include "Hra.h"

PrikazVolej::PrikazVolej(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh)
	: IPrikaz(nazev), odkaz_na_hru(hra), odkaz_na_plan(herni_plan), odkaz_na_batoh(batoh),
	telefonni_seznam("seznam", "seznam", false)
{
	telefonni_seznam.pridej_osoby(Osoba("michal", "kamarad"));
	telefonni_seznam.pridej_osoby(Osoba("roman", "kamarad"));
	telefonni_seznam.pridej_osoby(Osoba("tomas", "kamarad"));
	telefonni_seznam.pridej_osoby(Osoba("lubor", "kamarad"));
	telefonni_seznam.pridej_osoby(Osoba("petr", "kamarad"));
	telefonni_seznam.pridej_osoby(Osoba("erik", "kamarad"));
	telefonni_seznam.pridej_osoby(Osoba("bohous", "kamarad"));
	telefonni_seznam.pridej_osoby(Osoba("josef", "kamarad"));
	telefonni_seznam.pridej_osoby(Osoba("karel", "kamarad"));
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
			telefonni_seznam.vypis_osoby();
		}
		else
		{
			auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor();
			bool mam_mobil = odkaz_na_batoh->mam_vec("mobil");

			// bud jsem doma nebo mam mobil
			if (aktualni_prostor->get_jmeno() == "byt" or mam_mobil == true)
			{
				bool mam_v_seznamu = telefonni_seznam.je_osoba_v_prostoru(parametry[0]);
				if (mam_v_seznamu == true)
				{
					bool result = odkaz_na_plan->pozvi_cloveka(Osoba(parametry[0], "kamarad"));
					if (result == true)
					{
						std::cout << "Osoba " << parametry[0] << " byla pozvana na party.\n";
					}
					else
					{
						std::cout << "Tato osoba je jiz pozvana.\n";
					}
				}
				else
				{
					std::cout << "Teto osobe nemuzes volat, protoze neni v tvem telefonnim seznamu."
						<< "Pokud ani sam nevis, komu muzes zavolat, napis 'volej koho'\n";
				}
			}
			else
			{
				std::cout << "Abys mohl volat, musis byt bud doma nebo mit mobil.\n";
			}
		}
	}
}

std::string PrikazVolej::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}