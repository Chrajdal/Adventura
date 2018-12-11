#pragma once

#include <iostream>
#include <string>

class Vec
{
public:
	Vec(std::string _nazev, std::string _popis, int _vaha, int _cena, bool _prenosna);
	Vec(const Vec & src);
	~Vec();

	// meeting std::map requirements from class Prostor
	bool operator < (const Vec & src) const
	{
		return nazev < src.nazev;
	}

	inline std::string jmeno(void)const
	{
		return nazev;
	}

	inline int cena_veci(void)const
	{
		return cena;
	}

	friend std::ostream & operator << (std::ostream & os, const Vec & src)
	{
		return os << src.nazev << " - " << src.popis << ", vazi:" << src.vaha << ", stoji: " << src.cena;
	}
private:
	std::string nazev;
	std::string popis;
	int vaha;
	int cena;
	bool prenosna;
};
