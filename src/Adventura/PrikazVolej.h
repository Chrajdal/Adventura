#pragma once
#include "IPrikaz.h"
#include "HerniPlan.h"

#include "PrikazyFWD.h"
#include "HraFWD.h"
#include "Prostor.h"
#include "Batoh.h"

class PrikazVolej : public IPrikaz
{
public:
	PrikazVolej(const std::string & nazev, Hra * h, HerniPlan * p, Batoh * batoh);
	~PrikazVolej();

	void proved(const std::vector<std::string>& parametry);
	std::string nazev(void) const;
	virtual std::string pouziti(void)const
	{
		return "volej <koho>";
	}

private:
	Hra * odkaz_na_hru;
	HerniPlan * odkaz_na_plan;
	Batoh * odkaz_na_batoh;

	Prostor telefonni_seznam;
};

