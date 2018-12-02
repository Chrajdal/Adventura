#pragma once

#include <Windows.h> // gonna try to play with console size and output in general
#include <iostream>
#include <string>

#include "Hra.h"

class TextoveRozhrani
{
public:
	TextoveRozhrani(void);
	~TextoveRozhrani(void);

	void hraj(void);

private:
	Hra hra;
};

