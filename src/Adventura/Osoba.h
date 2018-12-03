#pragma once

#include <string>
#include <vector>
#include <map>
#include <utility>

#include "Vec.h"

class Osoba
{
public:
	Osoba(const std::string jmeno, const std::string popis, std::vector<std::string> pred, std::vector<std::string> po);
	~Osoba();

	inline void nastav_kyzenou_vec(const std::string & vec, int pocet)
	{
		vec_co_chci = make_pair(vec, pocet);
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

