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

	// meeting set requirements
	bool operator < (const Osoba & rhs) const
	{
		return jmeno < rhs.jmeno;
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

