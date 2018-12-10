#include "Osoba.h"

Osoba::Osoba(const std::string jmeno, const std::string popis, std::vector<std::string> pred, std::vector<std::string> po)
	: jmeno(jmeno), popis(popis), hlasky_pred(pred), hlasky_po(po)
{
	event_hotov = false;
}

Osoba::~Osoba()
{
}
