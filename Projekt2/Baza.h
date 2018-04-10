#pragma once
#include "Slowo.h"
#include "Plik.h"
#include "Slowo.h"
#include <vector>
#include <fstream>
class Baza
{
private:
	std::vector <Slowo> lista;
	std::vector <Plik> pliki;
public:
	Baza();
	int wprowadzPlik(std::string name);
	int slowaZPliku(Plik file);
	~Baza();
};

