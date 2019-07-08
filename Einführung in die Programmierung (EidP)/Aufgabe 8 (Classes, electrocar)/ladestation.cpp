#include "ladestation.h"
#include<iostream>

Ladestation::Ladestation():Ladestation(1){};
Ladestation::Ladestation(double euro) {
	strom = euro;
}

double Ladestation::getStrom(){
	return strom;
}

void Ladestation::laden(Elektrofahrzeug *Auto, Ladegutschein *Gutschein) {
	if (((100 - Auto->leseLadestand()) / 100) * Auto->leseKap() * strom <= Gutschein->getGutschein()) {
		Gutschein->setzeGutschein(Gutschein->getGutschein() - ((100 - Auto->leseLadestand()) / 100) * Auto->leseKap() * strom);
		Auto->aufladen(strom);
	} else {
		Auto->setzeLadestand(((Auto->leseLadestand() / 100) * Auto->leseKap() + Gutschein->getGutschein() / strom) * 100 / Auto->leseKap());
		Gutschein->setzeGutschein(0);
	}
}

