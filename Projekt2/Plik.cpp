#include "Plik.h"
#include <iostream>
#include <fstream>
using namespace std;

Plik::Plik()
{
}
Plik::Plik(const Plik & pl)
{
    nazwa = pl.nazwa;
	tresc = pl.tresc;
	plikuchwyt.open(nazwa, ios::in);

}
Plik::Plik(std::string name, std::string tr)
{
	nazwa = name;
	tresc = tr;
	plikuchwyt.open(name, ios::in);
}

Plik::~Plik()
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
