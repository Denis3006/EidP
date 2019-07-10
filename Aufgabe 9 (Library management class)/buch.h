#ifndef BUCH_H_
#define BUCH_H_
#include<string>
#include<iostream>

using namespace std;

class Buch{
private:
	string Autor, Titel;
	unsigned int Inventarnummer, Mitgliedsnummer;
public:
	Buch(string Aut, string Tit, unsigned int Inv);
	bool istVerliehen();
	unsigned int inventarNummer();
	unsigned int ausgeliehenVon();
	bool verlieheAn(unsigned int mitglied);
	void rueckgabe();
	void print();
	~Buch(){};
};




#endif /* BUCH_H_ */
