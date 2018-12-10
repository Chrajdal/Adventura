#pragma once

#include <string>

#include "IPrikaz.h"

#include "PrikazyFWD.h"
#include "HraFWD.h"
#include "HerniPlan.h"
#include "Batoh.h"

class PrikazVydelat : public IPrikaz
{
public:
	PrikazVydelat(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh);
	~PrikazVydelat();

	virtual void proved(const std::vector<std::string> & parametry = {});
	virtual std::string nazev(void) const;
	virtual std::string pouziti(void)const;
private:
	Hra * odkaz_na_hru;
	HerniPlan * odkaz_na_plan;
	Batoh * odkaz_na_batoh;
};

