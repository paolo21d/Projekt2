#pragma once
#include <string>
#include <fstream>
class Plik
{
private:
	std::string nazwa;
	std::string tresc;
public:
	std::fstream plikuchwyt;
	Plik();
	Plik(const Plik & pl);
	~Plik();

	std::string getNazwa();
	std::string getTresc();
	Plik(std::string name, std::string tr);
};

