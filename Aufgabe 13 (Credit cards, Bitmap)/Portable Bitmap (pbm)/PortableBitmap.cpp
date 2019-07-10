//recreated 08.07.2019
#include "PortableBitmap.h"
#include <fstream>
#include <iostream> 

string PBMException::getMessage() const 
{
	return message;
}

PortableBitmap::PortableBitmap(std::string const& textDatei, char nullZeichen, char einsZeichen)
{
	breite = 0;
	hoehe = 0;
	ifstream file(textDatei);
	string str;
	if (getline(file, str)) {
		breite = str.length();
		do {
			hoehe++;
			if (str.length() != breite) throw (PBMException("Ungueltige Anzahl von Zeichen in PBM-Datei"));
			for (size_t i = 0; i < str.length(); i++) {
				if (str[i] == nullZeichen)
					bildDaten.push_back(false);
				else if (str[i] == einsZeichen)
					bildDaten.push_back(true);
				else throw (PBMException("Ungueltige Zeichen in PBM-Datei."));
			}
		} while (getline(file, str));
	}
}

bool PortableBitmap::getPixel(unsigned int x, unsigned int y) 
{
	if (y * breite + x >= bildDaten.size()) throw (PBMException("Vector out of bounds."));
	return bildDaten[y * breite + x];
}

void PortableBitmap::setPixel(bool wert, unsigned int x, unsigned int y) 
{
	if (y * breite + x >= bildDaten.size()) throw (PBMException("Vector out of bounds."));
	bildDaten[y * breite + x] = wert;
}

void PortableBitmap::save(string const& dateiName) {
	ofstream pbm(dateiName + ".pbm");
	if (!pbm.is_open()) {
		throw (PBMException("PortableBitmap.pbm kann nicht angelegt werden"));
	}
	pbm << "P1" << endl;
	pbm << "# EidP Productions 2017 / 18" << endl;
	pbm << breite << " " << hoehe << endl;
	for (size_t i = 0; i < hoehe; i++) {
		for (size_t j = 0; j < breite; j++) {
			pbm << getPixel(j, i);
		}
		pbm << endl;
	}
}