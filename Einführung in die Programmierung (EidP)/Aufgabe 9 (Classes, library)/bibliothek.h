/*
 * bibliothek.h
 *
 *  Created on: 09.12.2014
 *      Author: quad
 */

#ifndef BIBLIOTHEK_H_
#define BIBLIOTHEK_H_

#include "buch.h"
#include "mitglied.h"
#include "eidpliste.h"

class Bibliothek{

public:
	enum Resultat{AUSLEIHE_OK, BUCH_AUSGELIEHEN, BUCH_NICHT_VORHANDEN, MITGLIED_NICHT_VORHANDEN, AUSLEIH_LIMIT_ERREICHT};

	Bibliothek();
	~Bibliothek();
	void erfasse(std::string author, std::string title);
	void anmelden(std::string name);
	void listeBuecherAuf();
	void listeBenutzerAuf();
	Resultat ausleihe(unsigned int buch, unsigned int mitglied);
	bool rueckgabe(unsigned int buch);
private:
	Liste<Buch*> _buecher;
	Liste<Mitglied*> _benutzer;
	unsigned int _nextInvNr;
	unsigned int _nextUserNr;

};

#endif /* BIBLIOTHEK_H_ */
