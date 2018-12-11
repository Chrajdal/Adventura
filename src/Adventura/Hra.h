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
#include "PrikazProhledni.h"
#include "PrikazMluv.h"
#include "PrikazPoloz.h"
#include "PrikazVezmi.h"
#include "PrikazVymen.h"

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

		float pocet_bodu = 0.0;

		auto byt = herni_plan.get_byt();
		int pocet_osob = byt->pocet_pozvanych();
		pocet_bodu += (pocet_osob + 2) * 10;
		auto polozene_veci = byt->get_polozene_veci();
		for (const auto & i : polozene_veci)
		{
			pocet_bodu *= i.second + ((float)pocet_osob / i.second);
		}

		std::cout << "Konecne zacala party, ktera se nakonec protahla do velmi brzkych rannich hodin.\n";
		std::cout << "Hodnoceni vasi party je nasledujici: " << pocet_bodu << " bodu!\n";
		std::cout << "Vase divka vas ohodnotila na " << herni_plan.get_divka()->get_body() << " bodu!\n";
		std::cout << "Timto hra konci. Doufame, ze jste si ji uzili. Nyni muzete hru ukoncit,\n";
		std::cout << "anebo pokracovat v hrani jen tak. Ahoj!\n";
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
