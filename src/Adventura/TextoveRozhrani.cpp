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

		// <help box>
		{
			{
				COORD c = { 0, hra.wnd_h - 2 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				std::cout << '+' << std::string(hra.wnd_w - 2, '-') << '+';
			}
			{
				COORD c = { 0, hra.wnd_h - 1 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				hra.napoveda();
			}
			{
				COORD c = { 0, hra.wnd_h };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				std::cout << '+' << std::string(hra.wnd_w-2, '-') << '+';
			}
		}
		// </help box>

		std::string prikaz = "";
		// <command box>
		{
			{
				COORD c = { 0, hra.wnd_h - 5 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				std::cout << std::string(hra.wnd_w, '=');
				std::cout << '\n';
			}
			{
				COORD c = { 0, hra.wnd_h - 3 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				std::cout << std::string(hra.wnd_w, '=');
			}
			{
				COORD c = { 0, hra.wnd_h - 4 };
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				std::cout << ">>> ";
				std::getline(std::cin, prikaz);
			}
		}
		// </command box>

		system("CLS"); // clears the screen
		
		// <text box>
		{
			COORD c = { 0,0 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

			hra.zpracuj(prikaz);
		}
		// </text box>

		
	}
	if (hra.konec_hry() == true)
		hra.rozluc();
}