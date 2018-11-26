#pragma once


#include "IPrikaz.h"

#include "PrikazKonecFWD.h"
#include "HraFWD.h"

class PrikazKonec : public IPrikaz
{
public:
	PrikazKonec(const std::string & jmeno, Hra * hra);
	PrikazKonec(const PrikazKonec & src);
	~PrikazKonec();

	virtual void proved(const std::vector<std::string> & parametry = {});
	virtual std::string nazev(void) const
	{
		return jmeno_prikazu;
	}
	
private:
	Hra * odkaz_na_hru;
};

