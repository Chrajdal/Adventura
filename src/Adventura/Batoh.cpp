#include "Batoh.h"

bool Batoh::mam_vec(const std::string & jmeno_veci) const
{
	for (const auto & i : veci)
	{
		if (i.first.jmeno() == jmeno_veci)
			return true;
	}
	return false;
}
