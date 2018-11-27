#include "Prostor.h"

void Prostor::pridej_vec(const Vec & v)
{
	veci[v]++;
}

void Prostor::pridej_osoby(const Osoba & o)
{
	osoby.push_back(o);
}

void Prostor::pridej_vychod(const Prostor & p)
{
	vychody.insert(p);
}

void spoj_sousedy(Prostor & a, Prostor & b)
{
	a.pridej_vychod(b);
	b.pridej_vychod(a);
}

void Prostor::vypis_veci(void)const
{
	for (const auto & i : veci)
	{
		std::cout << i.first << " - " << i.second << std::endl;
	}
}

void Prostor::vypis_osoby(void)const
{

}

void Prostor::vypis_vychody(void)const
{
	int n = (int)vychody.size();
	for (const auto & i : vychody)
	{
		if (n-- != 0)
			std::cout << i.nazev << ", ";
		else
			std::cout << i.nazev << '\n';
	}
}