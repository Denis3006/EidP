#include <iostream>
#include "kreditkarte.h"

using namespace std;
/*
int main()
{
    Kreditkarte k1(1000);
    Kreditkarte k2(200);

    cout << "Karte 1:" << endl;
    k1.aufladen(200);
    k1.bezahlen(380);
    k1.druck();
    cout << endl;

    k1.setLimit(500);
    k1.druck();
    cout << endl;

    k1.bezahlen(100);
    k1.druck();
    cout << endl << "===========================" << endl;

    cout << "Karte 2:" << endl;
    k2.bezahlen(199);
    k2.druck();
    cout << endl;

    k2.aufladen(600);
    k2.druck();
    cout << endl;

    k2.bezahlen(100);
    k2.druck();
    cout << endl << "===========================" << endl;

    cout << "Karte 3 = Uebertrag von Karte 2 auf Karte 1:" << endl;
    Kreditkarte *k3 = &k1.uebertragen(k2, 400);
    cout << "Karte 3:" << endl;
    k3->druck();
    cout << endl;
    cout << "Karte 1:" << endl;
    k1.druck();
    cout << endl;

    // die folgenden Funktionsaufrufe mit try/catch absichern:
	try {
		k1.bezahlen(3000);
	}
	catch (KreditKarteException& e) {
		e.what();
	}
	try {
		k2.aufladen(8000);
	}
	catch (KreditKarteException& e) {
		e.what();
	}
	try{
		k1.uebertragen(k2, 900);
	}
	catch (KreditKarteException& e) {
		e.what();
	}
	try{
		k2.setLimit(0);
	}
	catch (KreditKarteException& e) {
		e.what();
	}

    /* SOLLAUSGABE (Bsp.):
    !!! LimitException:          -- betrag:    3000 -- limit:        500
    !!! GuthabenException:       -- betrag:    8000 -- max guthaben: 5000
    !!! LimitException:          -- betrag:     900 -- limit:        200
    !!! LimitUngueltigException: -- betrag:       0 -- neues limit:    0
     

    cout << "EOP" << endl;
    return 0;
}
*/
