#include <cstdlib>
#include <ctime>

#include "TextoveRozhrani.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main(void)
{
	srand(unsigned(time(nullptr)));

	if (!ShowWindow(GetConsoleWindow(), SW_MAXIMIZE))
	{
		std::cout << "ShowWindow failed with error: " << GetLastError() << '\n';
	}

	if (!SetConsoleTitle("Adventura"))
	{
		std::cout << "SetConsoleTitle failt with error: " << GetLastError() << '\n';
	}

	if (!SetConsoleOutputCP(65001))
	{
		std::cout << "SetConsoleOutputCP failt with error: " << GetLastError() << '\n';
	}

	TextoveRozhrani tr;
	tr.hraj();
	
	system("PAUSE");
	return 0;
}