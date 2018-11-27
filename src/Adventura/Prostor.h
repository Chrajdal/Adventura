#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

#include "Vec.h"
#include "Osoba.h"

class Prostor
{
public:
	Prostor(const std::string & nazev_prostoru, const std::string & popis_prostoru, bool je_prostor_obchod)
		: nazev(nazev_prostoru), popis(popis_prostoru), je_obchod(je_prostor_obchod)
	{
		std::transform(nazev.begin(), nazev.end(), nazev.begin(), ::tolower);
	}

	//Prostor(const Prostor & src)
	//{
	//	nazev = src.nazev;
	//	popis = src.popis;
	//	vychody = src.vychody;
	//	osoby = src.osoby;
	//	je_obchod = src.je_obchod;
	//	veci = src.veci;
	//}

	~Prostor()
	{

	}

	void pridej_vec(const Vec & v);
	void pridej_osoby(const Osoba & o);
	void pridej_vychod(const Prostor & p);

	bool je_vychod(const std::string & vychod)const;
	

	void vypis_veci(void)const;
	void vypis_osoby(void)const;
	void vypis_vychody(void)const;


	inline std::string get_jmeno(void) const
	{
		return nazev;
	}
	inline std::string get_popis(void) const
	{
		return popis;
	}

	// just to satisfy std::set requirements
	bool operator < (const Prostor & src) const
	{
		return nazev < src.nazev;
	}	
private:
	std::string nazev;
	std::string popis;
	std::set<Prostor> vychody;
	std::vector<Osoba> osoby;
	bool je_obchod;
	std::map<Vec, int> veci;
};

void spoj_sousedy(Prostor & a, Prostor & b);