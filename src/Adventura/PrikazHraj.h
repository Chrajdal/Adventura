#pragma once

#include "IPrikaz.h"
#include "HerniPlan.h"

#include "PrikazyFWD.h"
#include "HraFWD.h"

class PrikazHraj : public IPrikaz
{
public:
	PrikazHraj(const std::string & jmeno, Hra * hra, HerniPlan * herni_plan);
	~PrikazHraj();

	virtual void proved(const std::vector<std::string> & parametry = {});
	virtual std::string nazev(void) const;
private:
	Hra * odkaz_na_hru;
	HerniPlan * odkaz_na_plan;
};
