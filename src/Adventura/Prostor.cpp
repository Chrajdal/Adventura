#include "Prostor.h"

void Prostor::pridej_vec(const Vec & v)
{
	veci[v]++;
}

void Prostor::poloz_vec(const Vec & v)
{
	veci_na_zemi[v]++;
}

bool Prostor::je_vec_na_zemi(const std::string & jmeno_veci) const
{
	for (const auto & i : veci_na_zemi)
		if (i.first.jmeno() == jmeno_veci)
			return true;
	return false;
}

void Prostor::vypis_veci_na_zemi(void)const
{
	if (veci.empty())
	{
		std::cout << "V tomto prostoru se nenachazi zadne veci.\n";
		return;
	}
	for (const auto & i : veci_na_zemi)
		std::cout << i.first.jmeno() << " - " << i.second << "x, ";
	std::cout << '\n';
}

void Prostor::pridej_osoby(const Osoba & o)
{
	osoby.push_back(o);
}

void Prostor::pridej_vychod(const Prostor & p)
{
	vychody.insert(p);
}

bool Prostor::je_vychod(const std::string & vychod)const
{
	return (vychody.find(Prostor(vychod, "", false)) != vychody.end());
}

bool Prostor::je_osoba_v_prostoru(const std::string & jmeno_osoby) const
{
	for (const auto & i : osoby)
		if (i.get_jmeno() == jmeno_osoby)
			return true;
	return false;
}

bool Prostor::je_vec_v_prostoru(const std::string & jmeno_veci) const
{
	for (const auto & i : veci)
		if (i.first.jmeno() == jmeno_veci)
			return true;
	return false;
}

void spoj_sousedy(Prostor & a, Prostor & b)
{
	a.pridej_vychod(b);
	b.pridej_vychod(a);
}

void Prostor::vypis_veci(void)const
{
	if (veci.empty())
	{
		std::cout << "V tomto prostoru se nenachazi zadne veci na prodej.\n";
	}
	else
	{
		std::cout << "Veci na prodej: \n";
		for (const auto & i : veci)
			std::cout << i.first.jmeno() << " - " << i.second << "x, ";
		std::cout << '\n';
	}
	if (veci_na_zemi.empty())
	{
		std::cout << "V tomto prostoru se na zemi nenachazi zadne veci.\n";
	}
	else
	{
		std::cout << "Veci na zemi: \n";
		for (const auto & i : veci_na_zemi)
			std::cout << i.first.jmeno() << " - " << i.second << "x, ";
		std::cout << '\n';
	}
}

void Prostor::vypis_osoby(void)const
{
	if (osoby.empty())
		std::cout << "V tomto prostoru se nenachazi zadna osoba.";
	for (const auto & i : osoby)
	{
		std::cout << i.get_jmeno() << ", ";
	}
	std::cout << '\n';
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
