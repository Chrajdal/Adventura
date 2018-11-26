#pragma once

#include <string>
#include <vector>

class IPrikaz
{
public:
	IPrikaz(const std::string & jmeno);
	virtual ~IPrikaz();

	virtual void proved(const std::vector<std::string> & parametry = {}) = 0;
	virtual std::string nazev(void) const = 0;
	virtual bool operator == (const std::string & prikaz) const 
	{
		return prikaz == jmeno_prikazu;
	}
protected:
	std::string jmeno_prikazu;
};

