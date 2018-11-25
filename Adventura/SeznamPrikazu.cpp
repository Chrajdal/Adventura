#include "SeznamPrikazu.h"



SeznamPrikazu::SeznamPrikazu()
{
}


SeznamPrikazu::~SeznamPrikazu()
{
}

std::vector<std::string> SeznamPrikazu::nazvy_prikazu(void) const
{
	return std::vector<std::string>();
}

bool SeznamPrikazu::je_platny(const std::string & prikaz) const
{
	return false;
}
