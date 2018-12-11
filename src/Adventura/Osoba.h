#pragma once

#include <string>
#include <vector>
#include <map>
#include <utility>

#include "Vec.h"

class Osoba
{
public:
	Osoba(const std::string jmeno, const std::string popis, std::vector<std::string> pred = {}, std::vector<std::string> po = {});
	~Osoba();

	inline void nastav_kyzenou_vec(const std::string & vec, int pocet)
	{
		vec_co_chci = make_pair(vec, pocet);
	}

	inline std::string get_jmeno(void)const
	{
		return jmeno;
	}

	void pridej_vec(const std::string & jmeno, int pocet)
	{
		if (jmeno == vec_co_chci.first)
		{
			vec_co_chci.second -= pocet;
			if (vec_co_chci.second <= 0)
				event_hotov = true;
		}

		veci[Vec(jmeno, "", 0, 0, false)] += pocet;
	}

	void pridej_vec(const Vec & v)
	{
		if (v.jmeno() == vec_co_chci.first)
		{
			vec_co_chci.second--;
			if (vec_co_chci.second <= 0)
				event_hotov = true;
		}
		veci[v]++;
	}

	bool odeber_vec(const std::string & vec)
	{
		auto found = veci.find(Vec(vec, "", 0, 0, false));
		if (found == veci.end())
		{
			return false;
		}
		else
		{
			found->second--;
			if (found->second == 0)
				veci.erase(Vec(vec, "", 0, 0, false));
			return true;
		}
	}

	Vec vrat_vec(const std::string & jmeno_veci)
	{
		for (const auto & i : veci)
			if (i.first.jmeno() == jmeno_veci)
				return i.first;
		return Vec("", "", 0, 0, false);
	}

	std::pair<std::string, int> vec_kterou_chci(void)const
	{
		return vec_co_chci;
	}

	// meeting set requirements
	bool operator < (const Osoba & rhs) const
	{
		return jmeno < rhs.jmeno;
	}

	std::string vrat_hlasku(void)const
	{
		if (event_hotov == true)
		{
			return hlasky_po[rand() % hlasky_po.size()];
		}
		else
		{
			return hlasky_pred[rand() % hlasky_pred.size()];
		}
	}
private:
	std::string jmeno;
	std::string popis;

	std::map<Vec, int> veci;
	std::vector<std::string> hlasky_pred;
	std::vector<std::string> hlasky_po;
	bool event_hotov;
	
	std::pair<std::string, int> vec_co_chci;
};
