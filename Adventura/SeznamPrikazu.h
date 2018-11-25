#pragma once

#include <vector>
#include <string>
#include "IPrikaz.h"

class SeznamPrikazu
{
public:
	SeznamPrikazu();
	~SeznamPrikazu();

	std::vector<std::string> nazvy_prikazu(void) const;
	bool je_platny(const std::string & prikaz) const;
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

