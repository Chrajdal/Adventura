#include "PrikazHraj.h"

#include "Hra.h"

PrikazHraj::PrikazHraj(const std::string & jmeno, Hra * hra, HerniPlan * herni_plan)
	: IPrikaz(jmeno), odkaz_na_hru(hra), odkaz_na_plan(herni_plan)
{
}

PrikazHraj::~PrikazHraj()
{
}

void PrikazHraj::proved(const std::vector<std::string>& parametry)
{
	if (parametry.empty())
	{
		if (odkaz_na_hru->probehl_zacatek_hry() == false)
		{
			std::string curr_prostor = odkaz_na_plan->get_aktualni_prostor()->get_popis();
			int mezerL = 78/2 - 2 - (int)curr_prostor.size() / 2;
			int mezerR = 78/2 - 2 - (int)curr_prostor.size() / 2;
			if ((mezerL + mezerR) != 80)
				mezerR++;
			std::cout <<
				std::string("+-----------------------------------------------------------------------------+\n") +
				std::string("| *Crrrrrrrr*                                                                 |\n") +
				std::string("| *Crrrrrrrr*                                                                 |\n") +
				std::string("| Ty: 'Halo?'                                                                 |\n") +
				std::string("| Pavel: 'Cus, tady Pavel, ty mas prej dneska volnej byt?'                    |\n") +
				std::string("| Ty: 'No, to mam, ale... Pockej, proc?'                                      |\n") +
				std::string("| Pavel: 'Super, hele, Roman ma narozky, bude to u tebe doma,                 |\n") +
				std::string("| priprav mu poradnou party, darky koupime, bude to dneska vecer,             |\n") +
				std::string("| v osm zaciname, dik, musim, mej se.'                                        |\n") +
				std::string("| Ty: 'Ne, pockej, Paja ma dneska taky narozky, musim bejt s ni'              |\n") +
				std::string("| Pavel: 'V pohode, je pozvana, bude tam, ahoj.' *klap*                       |\n") +
				std::string("| Ty: 'Parada, takze mam pet hodin. A jeste musim koupit darek Paje           |\n") +
				std::string("| a najit svuj ztraceny mobil. Tak do toho!'                                  |\n") +
				std::string("| ") + std::string(mezerL, ' ') + curr_prostor + std::string(mezerL, ' ') + std::string(" |\n") +
				std::string("+-----------------------------------------------------------------------------+\n");

			odkaz_na_hru->zacni_hru();
		}
		else
		{
			std::cout <<
				std::string("+-----------------------------------------------------------------------------+\n") +
				std::string("|                            Hraj uz davno bezi.                              |\n") +
				std::string("+-----------------------------------------------------------------------------+\n");
		}
	}
	else
	{
		std::cout <<
			std::string("+-----------------------------------------------------------------------------+\n") +
			std::string("|             Hraj co? Nechapu, proc jsi zadal druhe slovo.                   |\n") +
			std::string("+-----------------------------------------------------------------------------+\n");

	}
}

std::string PrikazHraj::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}
