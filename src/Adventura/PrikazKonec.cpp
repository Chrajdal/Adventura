#include "PrikazKonec.h"

PrikazKonec::PrikazKonec(const std::string & jmeno, const Hra * hra)
	: IPrikaz(jmeno),
	odkaz_na_hru (hra)
{
}

PrikazKonec::PrikazKonec(const PrikazKonec & src)
	: IPrikaz(src.jmeno_prikazu),
	odkaz_na_hru(src.odkaz_na_hru)
{
}


PrikazKonec::~PrikazKonec()
{
}
