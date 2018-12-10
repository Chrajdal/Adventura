#include "Hra.h"

Hra::Hra(void)
{
	CONSOLE_SCREEN_BUFFER_INFO info = {};
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
	{
		std::cout << "GetConsoleScreenBufferInfo failed with error: " << GetLastError() << '\n';
	}
	else
	{
		wnd_w = std::abs(info.srWindow.Right - info.srWindow.Left);
		wnd_h = std::abs(info.srWindow.Top - info.srWindow.Bottom);

		//std::cout << "----------------------------DEBUG--------------------\n";
		//std::cout << wnd_h << "*" << wnd_w << '\n';
		//std::cout << "----------------------------DEBUG--------------------\n";
	}

	je_konec = 0;
	PrikazKonec * k = new PrikazKonec("konec", this);
	platne_prikazy.pridej_prikaz(k);

	PrikazHraj * hraj = new PrikazHraj("hraj", this, &herni_plan);
	platne_prikazy.pridej_prikaz(hraj);

	//std::cout << "----------------------------DEBUG--------------------\n";
	//std::cout << "Platne prikazy - Hra::Hra(): " << std::endl;
	//auto plat_prik = platne_prikazy.nazvy_prikazu();
	//for (auto & i : plat_prik)
	//	std::cout << i << " ";
	//std::cout << std::endl;
	//std::cout << "----------------------------DEBUG--------------------\n";
}

Hra::~Hra()
{
}

void Hra::uvitej(void) const
{
	std::cout <<
		std::string("+") + std::string(wnd_w - 2, '-') + std::string("+\n") +
		std::string("|") + std::string(wnd_w - 2, ' ') + std::string("|\n") +
		std::string("|                                 Vitejte!                                    |\n") +
		std::string("|") + std::string(wnd_w - 2, ' ') + std::string("|\n") +
		std::string("| Toto je nova adventura, ve ktere bude vasim cilem pripravit co nejlepsi     |\n") +
		std::string("| party pro kamarada. Ovsem nebudete mit prilis mnoho casu. Vice info o       |\n") +
		std::string("| pribehu si muzete precist v manualu.                                        |\n") +
		std::string("|") + std::string(wnd_w - 2, ' ') + std::string("|\n") +
		std::string("| Napiste 'napoveda', pokud si nevite rady, jak hrat dal nebo potrebujete     |\n") +
		std::string("| pripomenout prikazy. Hru spustite prikazem 'hraj'                           |\n") +
		std::string("| a ukoncite prikazem 'konec'.                                                |\n") +
		std::string("|") + std::string(wnd_w - 2, ' ') + std::string("|\n") +
		std::string("|                               Hodne stesti!                                 |\n") +
		std::string("+") + std::string(wnd_w - 2, '-') + std::string("+\n");
}

void Hra::dej_hraci_info(void) const
{
	std::cout <<
		std::string("+") + std::string(wnd_w - 1, '-') + std::string("+\n") +
		std::string("|                                                                             |\n");

	auto dlouhy_popis = herni_plan.get_aktualni_prostor()->get_dlouhy_popis();
	for (const auto & i : dlouhy_popis)
	{
		int mezerL = (75 - (int)i.size()) / 2;
		int mezerR = (75 - (int)i.size()) / 2;
		if ((mezerL + mezerR + i .size()) < 75)
			mezerR++;
		std::cout << "| ";
		std::cout << std::string(mezerL, ' ');
		std::cout << i;
		std::cout << std::string(mezerR, ' ');
		std::cout << " |\n";
	}	

	std::cout <<
		std::string("|                                                                             |\n") +
		std::string("+") + std::string(wnd_w - 1, '-') + std::string("+\n");
}

void Hra::napoveda(void)const
{
	std::cout << "| Platne prikazy: ";
	auto res = platne_prikazy.napoveda();
	for (const auto & i : res)
		std::cout << i << ", ";
}

void Hra::inicializuj_hru(void)
{
	PrikazJdi * jdi = new PrikazJdi("jdi", this, &herni_plan);
	platne_prikazy.pridej_prikaz(jdi);

	PrikazVydelat * vydelej = new PrikazVydelat("vydelat", this, &herni_plan, &batoh);
	platne_prikazy.pridej_prikaz(vydelej);

	PrikazVolej * volej = new PrikazVolej("volej", this, &herni_plan, &batoh);
	platne_prikazy.pridej_prikaz(volej);

	PrikazCoJe * coje = new PrikazCoJe("coje", this, &herni_plan, &batoh);
	platne_prikazy.pridej_prikaz(coje);

	PrikazDej * dej = new PrikazDej("dej", this, &herni_plan, &batoh);
	platne_prikazy.pridej_prikaz(dej);

	PrikazKup * kup = new PrikazKup("kup", this, &herni_plan, &batoh);
	platne_prikazy.pridej_prikaz(kup);

	//std::cout << "----------------------------DEBUG--------------------\n";
	//std::cout << "TODO: NAINICIALIZOVAT HRU\n";
	//std::cout << "----------------------------DEBUG--------------------\n";
}

void Hra::rozluc(void) const
{
	std::cout <<
		std::string("+") + std::string(wnd_w - 1, '-') + std::string("+\n") +
		std::string("| Dik, ze jste si zahrali. Ahoj.\n") +
		std::string("+") + std::string(wnd_w - 1, '-') + std::string("+\n");
}

void Hra::zpracuj(std::string prikaz)
{
	//std::cout << "----------------------------DEBUG--------------------\n";
	//std::cout << "Platne prikazy: " << std::endl;
	//auto plat_prik = platne_prikazy.nazvy_prikazu();
	//for (auto & i : plat_prik)
	//	std::cout << i << " ";
	//std::cout << std::endl;
	//std::cout << "----------------------------DEBUG--------------------\n";

	std::transform(prikaz.begin(), prikaz.end(), prikaz.begin(), ::tolower);

	if (prikaz.empty())
	{
		std::cout <<
			std::string("+-----------------------------------------------------------------------------+\n") +
			std::string("| Nevim co tim myslis, prazdny prikaz nelze provest. O.o                      |\n") +
			std::string("+-----------------------------------------------------------------------------+\n");
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
		std::cout <<
			std::string("+-----------------------------------------------------------------------------+\n") +
			std::string("| Nevim co tim myslis, tento prikaz neznam.                                   |\n") +
			std::string("+-----------------------------------------------------------------------------+\n");
	}
}
