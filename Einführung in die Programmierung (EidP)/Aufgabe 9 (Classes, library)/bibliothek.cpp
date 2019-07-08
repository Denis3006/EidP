/*
 * bibliothek.cpp
 *
 *  Created on: 09.12.2014
 *      Author: quad
 */

#include "buch.h"
#include "mitglied.h"
#include "eidpliste.h"

#include "bibliothek.h"
#include <iostream>
#include<string>

using namespace std;


Bibliothek::Bibliothek() :
		_nextInvNr(1), _nextUserNr(1) {
}

Bibliothek::~Bibliothek() {
	for (unsigned int i = 0; i < _buecher.size(); ++i) {
		delete _buecher.elementAt(i);
	}
	for (unsigned int i = 0; i < _benutzer.size(); ++i) {
		delete _benutzer.elementAt(i);
	}
}

void Bibliothek::erfasse(std::string author, std::string title) {
	Buch* neu = new Buch(author, title, _nextInvNr);
	_buecher.append(neu);
	++_nextInvNr;
}

void Bibliothek::anmelden(std::string name) {
	Mitglied* m = new Mitglied(name, _nextUserNr);
	_benutzer.append(m);
	++_nextUserNr;
}

void Bibliothek::listeBuecherAuf() {
	for (unsigned int i = 0; i < _buecher.size(); ++i) {
		_buecher.elementAt(i)->print();
	}
}

void Bibliothek::listeBenutzerAuf() {
	for (unsigned int i = 0; i < _benutzer.size(); ++i) {
		_benutzer.elementAt(i)->print();
	}
}

Bibliothek::Resultat Bibliothek::ausleihe(unsigned int buchnr, unsigned int mitglied){
	bool mitgliedschaft = false;
	for(unsigned int i = 0; i < _benutzer.size(); i++){
		if(mitglied == _benutzer.elementAt(i)->mitgliedsNummer())
			mitgliedschaft = true;
	}
	if(!mitgliedschaft)
		return MITGLIED_NICHT_VORHANDEN;
	bool buch = false;
	unsigned int count = 0;
	for(unsigned int i = 0; i < _buecher.size(); i++){
			if(_buecher.elementAt(i)->ausgeliehenVon() == mitglied)
						count++;
			if(buchnr == _buecher.elementAt(i)->inventarNummer()){
							buch = true;
			}
}
	if (!buch)
		return BUCH_NICHT_VORHANDEN;
	if(count >=3){
		return AUSLEIH_LIMIT_ERREICHT;
	}
	for(unsigned int i = 0; i < _buecher.size(); i++){
			if(buchnr == _buecher.elementAt(i)->inventarNummer()){
				if(_buecher.elementAt(i)->ausgeliehenVon() != 0)
					return BUCH_AUSGELIEHEN;
				else {
					_buecher.elementAt(i)->verlieheAn(mitglied);
					return AUSLEIHE_OK;
				}
}
}
}

bool Bibliothek::rueckgabe(unsigned int buch) {
	for(unsigned int i = 0; i < _buecher.size(); i++){
		if(buch == _buecher.elementAt(i)->inventarNummer()){
		_buecher.elementAt(i)->rueckgabe();
		return true;
		}
	}
	return false;
}
