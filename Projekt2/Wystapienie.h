#pragma once
#include <string>
#include "Plik.h"
class Wystapienie
{
	
public:
	int ilosc;
	std::string nazwa;
	Plik *plikwsk;

	Wystapienie(std::string n, Plik *wsk);
	~Wystapienie();
};

