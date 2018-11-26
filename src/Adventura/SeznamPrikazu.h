#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "IPrikaz.h"
#include "PrikazKonec.h"

class SeznamPrikazu
{
public:
	SeznamPrikazu();
	~SeznamPrikazu();

	std::vector<std::string> nazvy_prikazu(void) const
	{
		std::vector<std::string> res;
		for (auto it = seznam.begin(); it != seznam.end(); ++it)
			res.push_back((*it)->nazev());
		return res;
	}

	bool je_platny(const std::string & prikaz) const
	{
		if (seznam.empty())
			return false;
		for (auto it = seznam.begin(); it != seznam.end(); ++it)
			if (**it == prikaz)
				return true;
		return false;
	}

	void pridej_prikaz(IPrikaz * p)
	{
		//std::cout << "----------------------------DEBUG--------------------\n";
		//std::cout << "pridavam prikaz: " << std::endl;
		//std::cout << p->nazev() << std::endl;
		//std::cout << "----------------------------DEBUG--------------------\n";
		
		
		if (je_platny(p->nazev()) == true)
		{
			return;
		}

		seznam.push_back(p);
	}

	IPrikaz * vrat_prikaz(const std::string prikaz) const
	{
		if (seznam.empty())
			return nullptr;

		for (auto it = seznam.begin(); it != seznam.end(); ++it)
			if (**it == prikaz)
				return *it;
		return nullptr;
	}

private:
	std::vector<IPrikaz *> seznam;
};

