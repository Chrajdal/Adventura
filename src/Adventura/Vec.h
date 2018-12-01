#pragma once

#include <iostream>
#include <string>

class Vec
{
public:
	Vec(std::string _nazev, std::string _popis, int _vaha, int _cena, bool _prenosna);
	~Vec();

	// meeting std::map requirements from class Prostor
	bool operator < (const Vec & src) const
	{
		return nazev < src.nazev;
	}

	friend std::ostream & operator << (std::ostream & os, const Vec & src)
	{
		return os << src.nazev;
	}
private:
	std::string nazev;
	std::string popis;
	int vaha;
	int cena;
	bool prenosna;
};
