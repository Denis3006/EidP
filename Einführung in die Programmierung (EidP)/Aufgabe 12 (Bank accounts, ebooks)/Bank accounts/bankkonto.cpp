#include "bankkonto.h"


Bankkonto::Bankkonto(unsigned long nummer, string Name){
	Inhaber = Name;
	Kontonummer = nummer;
}
Bankkonto::Bankkonto(){
}
void Bankkonto::gutschreiben(int betrag) {
		if(betrag > 0)
			Kontostand += betrag;
		else cerr << "Betrag ist kleiner als 0.";
	};
int Bankkonto::kontostand() const{
	return Kontostand;
}
void Bankkonto::anzeigen() const{
	cout << "Kontoinhaber: " << Inhaber << " Kontonummer: " << Kontonummer << " Kontostand: " << Kontostand << endl;
}
unsigned long Bankkonto::kontonummer() const{
	return Kontonummer;
}





