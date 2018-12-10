#pragma once
#include "IPrikaz.h"

#include "PrikazyFWD.h"
#include "HraFWD.h"

#include "HerniPlan.h"
#include "Batoh.h"

class PrikazCoJe : public IPrikaz
{
public:
	PrikazCoJe(const std::string & nazev, Hra * hra, HerniPlan * herni_plan, Batoh * batoh);
	~PrikazCoJe();

	virtual void proved(const std::vector<std::string> & parametry = {});
	virtual std::string nazev(void) const;
	virtual std::string pouziti(void)const;

private:
	Hra * odkaz_na_hru;
	HerniPlan * odkaz_na_plan;
	Batoh * odkaz_na_batoh;
};

