/*
 * main.cpp
 *
 *  Created on: 09.12.2014
 *      Author: quad
 */

#include "buch.h"
#include "mitglied.h"
#include "bibliothek.h"
#include "bibmanager.h"

 //Aufgabe 1
//int main(){
//	Buch b("Raymond Chen", "The old new thing", 95457);
//
//	b.print();
//
//	return 0;
//}

// Aufgabe 2
//int main(){
//	//Benutzer b("Max Mustermann", 123);
//
//	Mitglied b("Max Mustermann", 123);
//
//	b.print();
//
//	return 0;
//}

// Aufgabe 3, Testumgebung - wird von uns bereit gestellt

int main(){

	Bibliothek bib;

	BibliotheksManager manager(&bib);
	manager.manage();


	return 0;
}





















