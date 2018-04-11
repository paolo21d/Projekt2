#pragma once
#include <vector>
#include "Wystapienie.h"
class Slowo
{
public:
	std::string slowo;
	int ilosc;
	std::vector <Wystapienie> wyst;
	Slowo(std::string word);
	~Slowo();
};

