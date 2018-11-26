#include "Hra.h"

Hra::Hra()
{

}

Hra::~Hra()
{

}

void Hra::uvitej(void) const
{
	std::cout <<
	std::string("Vitejte!\n") +
	std::string("Toto je nova adventura, ve ktere bude vasim cilem pripravit co nejlepsi \n") +
	std::string("party pro kamarada. Ovsem nebudete mit prilis mnoho casu. Vice info o \n") +
	std::string("pribehu si muzete precist v manualu. \n") +
	std::string("Napiste 'napoveda', pokud si nevite rady, jak hrat dal nebo potrebujete \n") +
	std::string("pripomenout prikazy. Hru spustite prikazem 'hraj' a ukoncite prikazem 'konec'. \n") +
	std::string("Hodne stesti! \n");
}

void Hra::rozluc(void) const
{
	std::cout << "Dik, ze jste si zahrali. Ahoj.\n";
}

void Hra::zpracuj(const std::string & prikaz)
{
	if (prikaz.empty())
	{
		std::cout << "Nevim co tim myslis, prazdny prikaz nelze provest. O.o \n";
		return;
	}
	std::istringstream iss(prikaz);
	std::vector<std::string> slova
	{
		std::istream_iterator<std::string>{iss},
		std::istream_iterator<std::string>{}
	};

	auto platne_nazvy = platne_prikazy.nazvy_prikazu();
	if (std::find(platne_nazvy.begin(), platne_nazvy.end(), slova[0]) != platne_nazvy.end())
	{
		IPrikaz * p = platne_prikazy.vrat_prikaz(slova[0]);
		slova.erase(slova.begin());
		p->proved(slova);
	}

	else
	{
		std::cout << "Nevim co tim myslis, tento prikaz neznam.\n";
	}
	
}
