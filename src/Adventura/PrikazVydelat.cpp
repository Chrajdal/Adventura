#include "PrikazVydelat.h"

#include "Hra.h"

PrikazVydelat::PrikazVydelat(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh)
	: IPrikaz(nazev),
	odkaz_na_hru(hra),
	odkaz_na_plan(herni_plan),
	odkaz_na_batoh(batoh)
{

}

PrikazVydelat::~PrikazVydelat()
{

}

void PrikazVydelat::proved(const std::vector<std::string> & parametry)
{
	if (parametry.size() == 0)
	{
		auto aktualni_prostor = odkaz_na_plan->get_aktualni_prostor();
		if (aktualni_prostor->get_jmeno() == "byt")
		{
			odkaz_na_batoh->pridej_penize(150);
			std::cout << "Odpracoval sis 30 minut a vydelal 150,-\n";
		}
		else
		{
			std::cout << "Abys mohl vydelavat musis byt doma, potrebujes k tomu pocitac.\n";
		}
	}
	else
	{
		std::cout << "Prikaz 'vydelat' se zadava bez parametru.\n";
	}
}

std::string PrikazVydelat::nazev(void) const
{
	return IPrikaz::jmeno_prikazu;
}

std::string PrikazVydelat::pouziti(void)const
{
	return IPrikaz::jmeno_prikazu;
}