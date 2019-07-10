//recreated 08.07.2019
#pragma once
#include <boost\dynamic_bitset\dynamic_bitset.hpp> // ich habe erst später kennengelernt, dass vector<bool> sehr blöd ist, und dass es weitere Bibliotheken außer STL existieren.
#include <string>
using namespace std;


class PBMException {
private:
	string message;
public:
	PBMException(string msg) : message(msg) {};
	string getMessage() const;
};

class PortableBitmap
{
public:
	PortableBitmap(string const& textDatei, char nullZeichen, char einsZeichen);
	bool getPixel(unsigned int x, unsigned int y);
	void setPixel(bool wert, unsigned int x, unsigned int y);
	void save(string const& dateiName);
private:
	unsigned int hoehe, breite;
	boost::dynamic_bitset<> bildDaten;
};


