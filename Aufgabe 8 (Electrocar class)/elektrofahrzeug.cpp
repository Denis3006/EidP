#include "elektrofahrzeug.h"
#include <iostream>
using namespace std;

Elektrofahrzeug::Elektrofahrzeug():Elektrofahrzeug(180, 80, 50, 11, 50000) {}

Elektrofahrzeug::Elektrofahrzeug(int kmh, double ah, double proz, double ahkm, double km) {
	if (kmh <= 0 || ah <= 0 || proz < 0 || proz > 100 || ahkm <= 0 || km < 0 || proz > 100) {
		gesch = 180;
		kap = 80;
		ladestand = 50;
		everbrauch = 11;
		kmstand = 50000;
		fehler();
	}
	gesch = kmh;
	kap = ah;
	ladestand = proz;
	everbrauch = ahkm;
	kmstand = km;
}

void Elektrofahrzeug::fehler() {
	cerr << "Ungültig." << endl;
	exit(1);
}

double Elektrofahrzeug::aufladen(double euro) {
	ladestand = 100;
	return (kap * (ladestand / 100) * euro);
}

bool Elektrofahrzeug::fahren(double dist) {
	if (dist * everbrauch / 100 < (ladestand / 100) * kap) {
		kmstand += dist;
		ladestand -= dist * everbrauch / 100;
		return true;
	}
	return false;
}

double Elektrofahrzeug::maximaleReichwerte() {
	double spar = everbrauch - everbrauch / 10;
	return kap * (ladestand / 100) / (spar * 1 / 100);
}

bool Elektrofahrzeug::zielSchnellErreichbar(double dist, double stunden) {
	double schnell = everbrauch + 2 * everbrauch / 10;
	if (dist / stunden > gesch)
		return false;
	else if (schnell * dist / 100 >= kap * (ladestand / 100)) {
		return false;
	}
	return true;
}
