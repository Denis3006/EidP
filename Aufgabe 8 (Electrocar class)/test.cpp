#include <iostream>
#include "elektrofahrzeug.h"
#include "ladegutschein.h"
#include "ladestation.h"

using namespace std;

void Zustand(Elektrofahrzeug C, Elektrofahrzeug D, Elektrofahrzeug E) {
	cout << "\t Roadster" << endl << "Höchstgeschwindigkeit: " << C.leseGesch()
			<< endl << "Batteriekapazität: " << C.leseKap() << endl
			<< "Batterieladestatus: " << C.leseLadestand() << endl
			<< "Durchnschnittsverbrauch: " << C.leseEverbrauch() << endl
			<< "Kilometerstand: " << C.leseKmstand() << endl << "\t Clever"
			<< endl << "Höchstgeschwindigkeit: " << D.leseGesch() << endl
			<< "Batteriekapazität: " << D.leseKap() << endl
			<< "Batterieladestatus: " << D.leseLadestand() << endl
			<< "Durchnschnittsverbrauch: " << D.leseEverbrauch() << endl
			<< "Kilometerstand: " << D.leseKmstand() << endl << "\t PKW" << endl
			<< "Höchstgeschwindigkeit: " << E.leseGesch() << endl
			<< "Batteriekapazität: " << E.leseKap() << endl
			<< "Batterieladestatus: " << E.leseLadestand() << endl
			<< "Durchnschnittsverbrauch: " << E.leseEverbrauch() << endl
			<< "Kilometerstand: " << E.leseKmstand() << endl;
}

int main() {
	Elektrofahrzeug Roadster(300, 200, 70, 20, 5000);
	Elektrofahrzeug Clever(70, 40, 30, 15, 12000);
	Elektrofahrzeug PKW;

	cout << "Zustand vor dem 1. Test:" << endl;
	Zustand(Roadster, Clever, PKW);

	cout << endl << endl << "1) Reichwert." << endl << "Roadster: "
			<< Roadster.maximaleReichwerte() << "km" << endl << "Clever: "
			<< Clever.maximaleReichwerte() << "km" << endl << "PKW: "
			<< PKW.maximaleReichwerte() << endl << endl
			<< "Zustand nach dem 1. Test:" << endl;
	Zustand(Roadster, Clever, PKW);

	cout << endl << endl << "2) Erreichbarkeit" << endl << "\t 100 km" << endl
			<< "Roadster: ";
	if (Roadster.maximaleReichwerte() >= 100)
		cout << "Ja." << endl;
	else
		cout << "Nein." << endl;

	cout << "Clever: ";
	if (Clever.maximaleReichwerte() >= 100)
		cout << "Ja." << endl;
	else
		cout << "Nein." << endl;

	cout << "PKW: ";
	if (PKW.maximaleReichwerte() >= 100)
		cout << "Ja." << endl;
	else
		cout << "Nein." << endl;

	cout << "\t 200 km" << endl << "Roadster: ";
	if (Roadster.maximaleReichwerte() >= 200)
		cout << "Ja." << endl;
	else
		cout << "Nein." << endl;

	cout << "Clever: ";
	if (Clever.maximaleReichwerte() >= 200)
		cout << "Ja." << endl;
	else
		cout << "Nein." << endl;

	cout << "PKW: ";
	if (PKW.maximaleReichwerte() >= 200)
		cout << "Ja." << endl;
	else
		cout << "Nein." << endl;

	cout << endl << "Zustand nach dem 2. Test:" << endl;
	Zustand(Roadster, Clever, PKW);

	Roadster.fahren(200);
	Clever.fahren(200);
	PKW.fahren(200);

	cout << endl << "Zustand nach dem 3. Test: " << endl;
	Zustand(Roadster, Clever, PKW);

	cout << endl << "4) Aufladen." << endl << "Roadster: "
			<< Roadster.aufladen(1.20) << " Euro." << endl << "Clever: "
			<< Clever.aufladen(1.20) << " Euro." << endl << "PKW: "
			<< PKW.aufladen(1.20) << " Euro." << endl;
	cout << endl << "Zustand nach dem 4. Test:" << endl;

	Zustand(Roadster, Clever, PKW);
	PKW.setzeLadestand(PKW.leseKap() / 40);
	cout << endl << "5) Höchstgeschwindigkeit." << endl
			<< "\t 150 km in 2 Stunden mit 40 Ah:" << endl;

	cout << "PKW: ";
	if (PKW.zielSchnellErreichbar(150, 2))
		cout << "Ja." << endl;
	else
		cout << "Nein." << endl;

	PKW.aufladen(1.20);
	cout << "\t Volle Batterie." << endl << "PKW: ";
	if (PKW.zielSchnellErreichbar(150, 2))
		cout << "Ja." << endl;
	else
		cout << "Nein." << endl;
	cout << endl << "Zustand nach dem 5. Test:" << endl;
	Zustand(Roadster, Clever, PKW);

	Ladegutschein Kunde1(10);
	Ladegutschein Kunde2(20);
	Ladegutschein Kunde3(30);

	Ladegutschein Kunden[3] = { Kunde1, Kunde2, Kunde3 };
	Elektrofahrzeug EAutos[3] = { Roadster, Clever, PKW };
	Ladestation KeinGas(1.20);
	EAutos[0].setzeLadestand(50);
	EAutos[1].setzeLadestand(50);
	EAutos[2].setzeLadestand(50);

	cout << endl << "\t Vor den Ladenvorgängen.";
	cout << endl << "Roadster: \t Ladestand: " << EAutos[0].leseLadestand()
			<< "\t ID: " << Kunden[0].getID() << "\t Gutschein: "
			<< Kunden[0].getGutschein() << " Euro.";
	cout << endl << "Clever: \t Ladestand: " << EAutos[1].leseLadestand()
			<< "\t ID: " << Kunden[1].getID() << "\t Gutschein: "
			<< Kunden[1].getGutschein() << " Euro.";
	cout << endl << "PKW: \t \t Ladestand: " << EAutos[2].leseLadestand()
			<< "\t ID: " << Kunden[2].getID() << "\t Gutschein: "
			<< Kunden[2].getGutschein() << " Euro.";

	KeinGas.laden(&EAutos[0], &Kunden[0]);
	KeinGas.laden(&EAutos[1], &Kunden[1]);
	KeinGas.laden(&EAutos[2], &Kunden[2]);

	cout << endl << "\t Nach den Ladenvorgängen.";
	cout << endl << "Roadster: \t Ladestand: " << EAutos[0].leseLadestand()
			<< "\t ID: " << Kunden[0].getID() << "\t Gutschein: "
			<< Kunden[0].getGutschein() << " Euro.";
	cout << endl << "Clever: \t Ladestand: " << EAutos[1].leseLadestand()
			<< "\t ID: " << Kunden[1].getID() << "\t Gutschein: "
			<< Kunden[1].getGutschein() << " Euro.";
	cout << endl << "PKW: \t \t Ladestand: " << EAutos[2].leseLadestand()
			<< "\t ID: " << Kunden[2].getID() << "\t Gutschein: "
			<< Kunden[2].getGutschein() << " Euro.";

	return 0;
}

