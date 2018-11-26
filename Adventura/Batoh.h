#pragma once

#include <vector>
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
	}
	~Batoh()
	{

	}

	std::vector<Vec> seznam_veci(void) const
	{
		return veci;
	}

private:
	std::vector<Vec> veci;
	int max_veci;
	int max_vaha;
	int pocet_veci;
	int vaha;
	int penize;
	int pozvanych_lidi;
};

