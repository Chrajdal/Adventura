#include "SeznamPrikazu.h"

SeznamPrikazu::SeznamPrikazu()
{
}

SeznamPrikazu::~SeznamPrikazu()
{
	for (auto & i : seznam)
	{
		delete i;
	}
	seznam.clear();
}
