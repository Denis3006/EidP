#include "ladegutschein.h"
#include<iostream>

using namespace std;

Ladegutschein::Ladegutschein(double geld) {
	static unsigned int id = 0;
	id++;
	ID = id;
	euro = geld;
}

void Ladegutschein::fehler() {
	cerr << "Ung�ltig." << endl;
	exit(1);
}

unsigned int Ladegutschein::getID() {
	return ID;
}

double Ladegutschein::getGutschein() {
	return euro;
}

void Ladegutschein::setzeGutschein(double geld) {
	euro = geld;
}


