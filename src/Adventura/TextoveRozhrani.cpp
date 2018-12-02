#include "TextoveRozhrani.h"

TextoveRozhrani::TextoveRozhrani(void)
{
	hra.uvitej();
}

TextoveRozhrani::~TextoveRozhrani(void)
{
	hra.rozluc();
}

void TextoveRozhrani::hraj(void)
{
	while (!hra.konec_hry())
	{
		if (hra.probehl_zacatek_hry() == true)
			hra.dej_hraci_info();
		std::string prikaz = "";
		std::getline(std::cin, prikaz);

		hra.zpracuj(prikaz);
		
	}
	if (hra.konec_hry() == true)
		hra.rozluc();
}