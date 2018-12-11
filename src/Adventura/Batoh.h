#pragma once

#include <vector>
#include <map>
#include <string>

#include "Vec.h"

class Batoh
{
public:
	Batoh()
	{
		max_veci = 5;
		max_vaha = 10000;
		pocet_veci = 0;
		vaha = 0;
		penize = 2000;
		pozvanych_lidi = 0;

		veci[Vec("cigareta", "", 1, 1, true)]++;
		veci[Vec("cigareta", "", 1, 1, true)]++;
		veci[Vec("cigareta", "", 1, 1, true)]++;
		veci[Vec("cigareta", "", 1, 1, true)]++;
	}
	~Batoh()
	{

	}

	std::map<Vec,int> seznam_veci(void) const
	{
		return veci;
	}

	inline void pridej_penize(int castka)
	{
		penize += castka;
	}

	inline int get_penize(void)const
	{
		return penize;
	}

	void pridej_vec(const std::string & vec)
	{
		veci[Vec(vec, "", 1, 1, true)]++;
	}

	Vec vrat_vec(const std::string & vec)
	{
		for (const auto & i : veci)
			if (i.first.jmeno() == vec)
				return i.first;
		return Vec("", "", 0, 0, false);
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

	bool mam_vec(const std::string & jmeno_veci) const;
private:
	std::map<Vec, int> veci;
	int max_veci;
	int max_vaha;
	int pocet_veci;
	int vaha;
	int penize;
	int pozvanych_lidi;
};
