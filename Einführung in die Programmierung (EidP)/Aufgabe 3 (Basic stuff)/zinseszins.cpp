/*
 *  Berechnet Zinsen f�r eine variable Anzahl von Jahren bei 6% Zinsen
 */

#include <iostream>
using namespace std;

int main(){
        short jahre;
        int betrag;

        cout << "Bitte den Startbetrag eingeben      : ";
        cin >> betrag;
        cout << "Bitte die Laufzeit in Jahren angeben: ";
        cin >> jahre;
        if (jahre < 0){
		cout << "Geben Sie bitte eine positive Anzahl der Jahre an.";
	        return 1;
        }
        while (jahre != 0) {
                betrag = betrag * 1.06;
                cout <<  "Schleifenausgabe : Jahreswert: " << jahre << " Betragswert:"
                        << betrag <<endl;
                jahre--;
        }

        cout << "Der Endbetrag ist: " << betrag << endl;
        return 0;
}
