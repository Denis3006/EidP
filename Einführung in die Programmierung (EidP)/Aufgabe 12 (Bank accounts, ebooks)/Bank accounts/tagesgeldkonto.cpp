#include "tagesgeldkonto.h"

Tagesgeldkonto::Tagesgeldkonto(unsigned long nummer, string Name, Girokonto &ziel){
	zielKonto = &ziel;
	Inhaber = Name;
	Kontonummer = nummer;
}
int Tagesgeldkonto::umbuchen(int betrag){
	if(Kontostand - betrag > grenz){
			zielKonto->gutschreiben(betrag);
			Kontostand -=betrag;
			return betrag;
		}
		else{
			zielKonto->gutschreiben(Kontostand);
			int hilf = Kontostand;
			Kontostand = grenz;
			return hilf;
		}

}


