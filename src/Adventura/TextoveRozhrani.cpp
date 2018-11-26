#include "TextoveRozhrani.h"

#include <iostream>
#include <string>

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
		std::string prikaz = "";
		std::getline(std::cin, prikaz);

		hra.zpracuj(prikaz);
	}
	if (hra.konec_hry() == true)
		hra.rozluc();
}