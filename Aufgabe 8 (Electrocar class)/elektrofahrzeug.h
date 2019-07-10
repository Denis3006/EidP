#ifndef ELEKTROFAHRZEUG_H
#define ELEKTROFAHRZEUG_H

#include <iostream>
class Elektrofahrzeug {
private:
	int gesch;
	double kap, ladestand, everbrauch, kmstand;
	void fehler();
public:
	Elektrofahrzeug();
	Elektrofahrzeug(int kmh, double ah, double proz, double ahkm, double km);
	void setzeGesch(int kmh) {
		if (kmh <= 0)
			fehler();
		else
			gesch = kmh;
	}
	int leseGesch() {
		return gesch;
	}

	void setzeKap(double ah) {
		if (ah <= 0)
			fehler();
		else
			kap = ah;
	}

	double leseKap() {
		return kap;
	}

	void setzeLadestand(double proz) {
		if (proz < 0)
			fehler();
		else
			ladestand = proz;
	}

	double leseLadestand() {
		return ladestand;
	}

	void setzeEverbrauch(double ahkm) {
		if (ahkm <= 0)
			fehler();
		else
			everbrauch = ahkm;
	}

	double leseEverbrauch() {
		return everbrauch;
	}

	double leseKmstand() {
		return kmstand;
	}

	void setzeKmstand(double km) {
		if (km < 0)
			fehler();
		else
			kmstand = km;
	}
	double aufladen(double euro);
	bool fahren(double dist);
	double maximaleReichwerte();
	bool zielSchnellErreichbar(double dist, double stunden);
	~Elektrofahrzeug() {}

};
#endif
