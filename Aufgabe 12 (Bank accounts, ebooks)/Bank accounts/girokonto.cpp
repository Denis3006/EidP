#include "girokonto.h"

Girokonto::Girokonto(unsigned long nummer, string Name){
	Inhaber = Name;
	Kontonummer = nummer;
	grenz = -100000;
	Kontostand = 0;
}
int Girokonto::ueberweisen(Bankkonto &zielKonto, int betrag){
	if(Kontostand - betrag > grenz){
		zielKonto.gutschreiben(betrag);
		Kontostand -=betrag;
		return betrag;
	}
	else{
		zielKonto.gutschreiben(Kontostand+abs(grenz));
		int hilf = Kontostand +abs(grenz);
		Kontostand = grenz;
		return hilf;
	}

}



