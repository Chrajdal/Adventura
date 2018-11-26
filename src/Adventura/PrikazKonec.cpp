#include "PrikazKonec.h"

#include "Hra.h"


PrikazKonec::PrikazKonec(const std::string & jmeno, Hra * hra)
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

void PrikazKonec::proved(const std::vector<std::string> & parametry)
{
	odkaz_na_hru->ukonci_hru();
}