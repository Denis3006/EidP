/*
 * bibmanager.cpp
 *
 *  Created on: 09.12.2014
 *      Author: quad
 */

#include "bibmanager.h"

#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

template<typename T> T readFromCIN() {
	T r;
	bool tryAgain = true;
	while (tryAgain) {
		string s;
		cin >> s;
		stringstream helper(s);
		helper >> r;
		if (helper.fail()) {
			cout << "Ungueltige Eingabe" << endl;
		} else {
			tryAgain = false;
		}
	}
	return r;
}

BibliotheksManager::BibliotheksManager(Bibliothek* bib) :
		_bib(bib) {
	_bib->erfasse("J.K. Rowling", "Harry Potter 1");
	_bib->erfasse("J.K. Rowling", "Harry Potter 2");
	_bib->erfasse("J.K. Rowling", "Harry Potter 3");
	_bib->erfasse("J.K. Rowling", "Harry Potter 4");
	_bib->erfasse("J.K. Rowling", "Harry Potter 5");
	_bib->erfasse("J.K. Rowling", "Harry Potter 6");
	_bib->erfasse("J.K. Rowling", "Harry Potter 7");
	_bib->erfasse("Raymond Chen", "The old new thing");
	_bib->erfasse("Joel Spolsky", "Joel on software");
	_bib->erfasse("Donald E. Knuth",
			"The Art of Computer Programming 1 - Fundamental Algorithms");
	_bib->erfasse("Donald E. Knuth",
			"The Art of Computer Programming 2 - Seminumerical Algorithms");
	_bib->erfasse("Donald E. Knuth",
			"The Art of Computer Programming 3 - Sorting and Searching");
	_bib->erfasse("David Woods", "How Apollo flew to the Moon");
	_bib->erfasse("Michael Collins", "Carrying the Fire");

	_bib->anmelden("Max Mustermann");
	_bib->anmelden("Dagobert Duck");
	_bib->anmelden("Abraham Lincoln");
	_bib->anmelden("Dustin Hoffman");
	_bib->anmelden("George R.R. Martin");
}

void BibliotheksManager::manage() {
	bool run = true;

	while (run) {
		cout
				<< "-----BibManager 1.0 (aus der Zeit, als es noch keine grafischen Benutzeroberflaechen gab)-----"
				<< endl;
		cout << "Unterstuetzte Aktionen:" << endl;
		cout << "\t b = Beenden." << endl;
		cout << "\t l = Liste aller Buecher anzeigen." << endl;
		cout << "\t m = Liste aller Mitglieder anzeigen." << endl;
		cout << "\t r = Buch zurueckgeben." << endl;
		cout << "\t a = Buch ausleihen." << endl;
		cout << "Befehl? " << endl;
		char c = readFromCIN<char>();
		switch (c) {
		case 'b': {
			cout << "System beendet." << endl;
			run = false;
			break;
		}
		case 'l': {
			_bib->listeBuecherAuf();
			break;
		}
		case 'm': {
			_bib->listeBenutzerAuf();
			break;
		}
		case 'a': {
			cout << "Ausleihen: Buch?" << endl;
			unsigned int buch = readFromCIN<unsigned int>();
			cout << "Ausleihen: Mitglied?" << endl;
			unsigned int mitglied = readFromCIN<unsigned int>();
			Bibliothek::Resultat result = _bib->ausleihe(buch, mitglied);

			switch (result) {
			case Bibliothek::AUSLEIHE_OK:
				cout << "Buch ausgeliehen" << endl;
				break;
			case Bibliothek::MITGLIED_NICHT_VORHANDEN:
				cout << "Unbekannte Mitgliedsnummer" << endl;
				break;
			case Bibliothek::BUCH_AUSGELIEHEN:
				cout << "Buch leider bereits ausgeliehen" << endl;
				break;
			case Bibliothek::BUCH_NICHT_VORHANDEN:
				cout << "Unbekanntes Buch, Inventarnummer nicht gefunden"
						<< endl;
				break;
			case Bibliothek::AUSLEIH_LIMIT_ERREICHT:
				cout
						<< "Es sind bereits zu viele Buecher von diesem Mitglied ausgeliehen."
						<< endl;
				cout << "Es muessen erst Buecher zurueckgegeben werden."
						<< endl;
				break;
			}
			break;
		}
		case 'r': {
			cout << "Rueckgabe: Buch?" << endl;
			unsigned int buch = readFromCIN<unsigned int>();
			if (_bib->rueckgabe(buch)) {
				cout << "Rueckgabe eingetragen." << endl;
			} else {
				cout << "Unbekanntes Buch, Inventarnummer nicht gefunden"
						<< endl;
			}
			break;
		}
		default: {
			cout << "Unbekannter Befehl: " << c << endl;
		}
		}
		cout << endl;
	}
}
