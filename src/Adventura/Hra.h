#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

#include "HraFWD.h"
#include "PrikazyFWD.h"

#include "SeznamPrikazu.h"
#include "Batoh.h"
#include "HerniPlan.h"

class Hra
{
public:
	Hra();
	~Hra();

	void uvitej(void)const;
	void rozluc(void)const;
	inline bool konec_hry(void)const
	{
		return je_konec;
	}
	inline void ukonci_hru(void)
	{
		je_konec = true;
	}

	void zpracuj(std::string prikaz);
private:
	bool je_konec;

	SeznamPrikazu platne_prikazy;
	Batoh batoh;
	HerniPlan herni_plan;
};


