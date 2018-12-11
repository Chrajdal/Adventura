#include "Vec.h"

Vec::Vec(std::string _nazev, std::string _popis, int _vaha, int _cena, bool _prenosna)
	: nazev(_nazev),
	popis(_popis),
	vaha(_vaha),
	cena(_cena),
	prenosna(_prenosna)
{
}

Vec::Vec(const Vec & src)
	: nazev(src.nazev),
	popis(src.popis),
	vaha(src.vaha),
	cena(src.cena),
	prenosna(src.prenosna)
{	
}

Vec::~Vec()
{
}