#include "sparkonto.h"

Sparkonto::Sparkonto(){};
Sparkonto::Sparkonto(unsigned long nummer, string Name){
	Inhaber = Name;
	Kontonummer = nummer;
	grenz = 100;
	Kontostand = 100;
}
int Sparkonto::auszahlen(int betrag){
	if(Kontostand - betrag > grenz){
		Kontostand -= betrag;
		return betrag;
	}
	else{
		int hilf = Kontostand - grenz;
		Kontostand = grenz;
		return hilf;
	}
}
int Sparkonto::aufloesen(){
	aufgeloest = true;
	Kontostand = 0;
	return grenz;
}
void Sparkonto::gutschreiben(int betrag){
	if(!aufgeloest){
		Bankkonto::gutschreiben(betrag);
	}
	else cerr << "Das Konto ist ausgeloest." << endl;
}

