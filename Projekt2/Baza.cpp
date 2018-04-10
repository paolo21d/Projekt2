#include "Baza.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Baza::Baza()
{
}

int Baza::wprowadzPlik(std::string name) { 
	//return 1-udalo sie, 0-niepowodzenie
	for (auto i = 0; i < pliki.size(); ++i) { //sprawdzenie czy juz nie otworzylismy pliku o podanej nazwie
		if (pliki[i].getNazwa() == name)
			return 0;
	}
	string tresc, tmp;
	fstream plik;
	plik.open(name, ios::in);
	if (!plik.good()) {
		return 0;
	}
	while (getline(plik, tmp)) {
		tmp += "\n";
		tresc += tmp;
	}
	Plik file(name, tresc);
	this->pliki.push_back(file);
	plik.close();
	return 1;
}

int Baza::slowaZPliku(Plik file)
{
	string tresc = file.getTresc();
	string word="";
	bool wystapilo = false;
	for (auto i = 0; i < tresc.size(); ++i) {
		if (tresc[i] == ' ' || tresc[i] == '\n') {
			if (!word.empty()) { //jesli slowo nie jest puste
				for (auto k = 0; k < lista.size(); ++k) {
					wystapilo = false;
					if (lista[k].slowo == word) //slowo juz jest w bazie
					{
						wystapilo = true;
						lista[k].ilosc++;
						bool bylo = false;
						for (auto l = 0; l < lista[k].wyst.size(); ++l) //sprawdzenie czy juz w tym pliku wystapilo
						{
							if (lista[k].wyst[l].nazwa == file.getNazwa()) //to slowo juz bylo w tym pliku i tylko zwiekszamy ilosc wystapien
							{
								lista[k].wyst[l].ilosc++;
								bylo = true;
								break;
							}
						}
						if (!bylo) //nie wystapilo to slowo w tym pliku jeszcze
						{
							Wystapienie w(file.getNazwa(), &file);
							lista[k].wyst.push_back(w);
						}
					}
					else //slowa jeszcze nie bylo w bazie
					{
						Slowo s(word);
						Wystapienie w(file.getNazwa(), &file);
						s.wyst.push_back(w);
						lista.push_back(s);
					}
				}
			}
		}
		else { //dokladamy litery az do spacji lub endl
			word += tresc[i];
		}
	}
	return 1;
}


Baza::~Baza()
{
}
