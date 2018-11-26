#pragma once

#include <string>
#include <vector>

#include "Vec.h"
#include "Osoba.h"

class Prostor
{
public:
	Prostor(const std::string & nazev_prostoru, const std::string & popis_prostoru, bool je_prostor_obchod)
		: nazev(nazev), popis(popis_prostoru), je_obchod(je_prostor_obchod)
	{

	}
	~Prostor()
	{

	}

	void pridej_vychod(const Prostor & p);
	void pridej_vec(const Vec & v);
	void pridej_osoby(const Osoba & o);

	inline std::string get_popis(void) const
	{
		return popis;
	}

private:
	std::string nazev;
	std::string popis;
	std::vector<Prostor> vychody;
	std::vector<Vec> veci;
	std::vector<Osoba> osoby;
	bool je_obchod;
	std::vector <std::pair<Vec, int>> polozene_veci;
};
