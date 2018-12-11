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
		: nazev(nazev_prostoru), popis(popis_prostoru), obchod(je_prostor_obchod)
	{
		std::transform(nazev.begin(), nazev.end(), nazev.begin(), ::tolower);
	}

	~Prostor()
	{

	}

	void pridej_vec(const Vec & v);
	void pridej_osoby(const Osoba & o);
	void pridej_vychod(const Prostor & p);

	void poloz_vec(const Vec & v);

	bool je_vychod(const std::string & vychod)const;
	bool je_osoba_v_prostoru(const std::string & jmeno_osoby) const;
	bool je_vec_v_prostoru(const std::string & jmeno_veci) const;

	bool je_vec_na_zemi(const std::string & jmeno_veci) const;
	void vypis_veci_na_zemi(void) const;

	Vec vyber_vec(const std::string & jmeno_veci) const
	{
		for (const auto & i : veci)
			if (i.first.jmeno() == jmeno_veci)
				return i.first;

		for(const auto & i : veci_na_zemi)
			if (i.first.jmeno() == jmeno_veci)
				return i.first;

		return Vec("", "", 0, 0, false);
	}

	auto get_polozene_veci(void)const
	{
		return veci_na_zemi;
	}

	bool odeber_vec(const std::string & vec)
	{
		auto found = veci_na_zemi.find(Vec(vec, "", 0, 0, false));
		if (found == veci_na_zemi.end())
		{
			return false;
		}
		else
		{
			found->second--;
			if (found->second == 0)
				veci_na_zemi.erase(Vec(vec, "", 0, 0, false));
			return true;
		}
	}

	inline bool je_obchod(void) const
	{
		return this->obchod;
	}

	void vypis_veci(void)const;
	void vypis_osoby(void)const;
	void vypis_vychody(void)const;
	
	int pocet_pozvanych(void)const;

	inline int get_cena(const std::string & nazev) const
	{
		auto found = veci.find(Vec(nazev, "", 0, 0, true));
		return found->first.cena_veci();
	}

	bool prodej_vec(const std::string & nazev)
	{
		auto found = veci.find(Vec(nazev, "", 0, 0, false));
		if (found == veci.end())
		{
			return false;
		}
		else
		{
			found->second--;
			if (found->second == 0)
				veci.erase(Vec(nazev, "", 0, 0, false));
			return true;
		}
	}

	inline std::string get_jmeno(void) const
	{
		return nazev;
	}
	inline std::string get_popis(void) const
	{
		return popis;
	}
	std::vector<std::string> get_dlouhy_popis(void) const
	{
		std::vector<std::string> res;
		res.push_back(std::string("Jsi v prostoru ") + nazev + std::string(". ") + popis + std::string(" a muzes jit:"));
		for (const auto & i : vychody)
		{
			res.push_back(i.get_jmeno());
		}
		return res;
	}

	Osoba * get_osoba(const std::string  & osoba)
	{
		for (auto & i : osoby)
		{
			if (i.get_jmeno() == osoba)
				return &i;
		}
		return nullptr;
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
	bool obchod;
	std::map<Vec, int> veci;
	std::map<Vec, int> veci_na_zemi;
};

void spoj_sousedy(Prostor & a, Prostor & b);
