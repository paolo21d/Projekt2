#include "Wystapienie.h"


Wystapienie::Wystapienie(std::string n, Plik * wsk)
{
	ilosc = 1;
	nazwa = n;
	plikwsk = wsk;
}

Wystapienie::~Wystapienie()
{
}
