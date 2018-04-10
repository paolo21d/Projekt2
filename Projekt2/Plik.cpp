#include "Plik.h"
#include <iostream>
#include <fstream>
using namespace std;

Plik::Plik()
{
}

std::string Plik::getNazwa()
{
	return nazwa;
}

std::string Plik::getTresc()
{
	return tresc;
}


Plik::Plik(std::string name, std::string tr)
{
	nazwa = name;
	tresc = tr;
	plikuchwyt.open(name, ios::in)
}

Plik::~Plik()
{
}
