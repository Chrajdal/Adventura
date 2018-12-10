#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <Windows.h>

#include "HraFWD.h"
#include "PrikazyFWD.h"

#include "SeznamPrikazu.h"
#include "Batoh.h"
#include "HerniPlan.h"

#include "PrikazKonec.h"
#include "PrikazHraj.h"
#include "PrikazJdi.h"
#include "PrikazVydelat.h"
#include "PrikazVolej.h"
#include "PrikazCoJe.h"
#include "PrikazDej.h"
#include "PrikazKup.h"

class Hra
{
public:
	Hra();
	~Hra();

	void uvitej(void)const;
	void rozluc(void)const;

	inline void zacni_hru(void)
	{
		je_konec = 1;
	}
	inline bool probehl_zacatek_hry(void) const
	{
		return je_konec != 0;
	}
	inline bool konec_hry(void) const
	{
		return je_konec == 300;
	}
	inline void ukonci_hru(void)
	{
		je_konec = 300;
	}

	void napoveda(void) const;
	void zpracuj(std::string prikaz);
	void dej_hraci_info(void) const;
	void inicializuj_hru(void);


	unsigned wnd_h;
	unsigned wnd_w;
private:
	int je_konec; // 0 je zacatek, 1 az (max_cas - 1) je prubeh, max_cas a vice je konec_hry

	SeznamPrikazu platne_prikazy;
	Batoh batoh;
	HerniPlan herni_plan;
	
};
