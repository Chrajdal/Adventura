#include "Vec.h"

Vec::Vec(std::string _nazev, std::string _popis, int _vaha, int _cena, bool _prenosna)
	: nazev(_nazev),
	popis(_popis),
	vaha(_vaha),
	cena(_cena),
	prenosna(_prenosna)
{
}

Vec::~Vec()
{
}