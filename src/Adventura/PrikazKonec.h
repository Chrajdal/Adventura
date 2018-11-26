#pragma once

class Hra;

#include "Hra.h"
#include "IPrikaz.h"

class PrikazKonec : public IPrikaz
{
public:
	PrikazKonec(const std::string & jmeno, const Hra * hra);
	PrikazKonec(const PrikazKonec & src);
	~PrikazKonec();

	virtual void proved(const std::vector<std::string> & parametry = {})
	{

	}
	virtual std::string nazev(void) const
	{
		return jmeno_prikazu;
	}
	
private:
	const Hra * odkaz_na_hru;
};

