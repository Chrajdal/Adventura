#pragma once
#include "IPrikaz.h"
#include "HerniPlan.h"

#include "PrikazyFWD.h"
#include "HraFWD.h"

class PrikazJdi : public IPrikaz
{
public:
	PrikazJdi(const std::string & nazev, Hra * hra, HerniPlan * herni_plan);
	~PrikazJdi();

	void proved(const std::vector<std::string>& parametry);
	std::string nazev(void) const;

private:
	Hra * odkaz_na_hru;
	HerniPlan * odkaz_na_plan;
};
