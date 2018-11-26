#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

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

	void zpracuj(const std::string & prikaz);
private:
	bool je_konec;

	SeznamPrikazu platne_prikazy;
	Batoh batoh;
	HerniPlan herni_plan;
};


