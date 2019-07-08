#include"buch.h"
using namespace std;

Buch::Buch(string Aut, string Tit, unsigned int Inv){
Autor = Aut;
Titel = Tit;
Inventarnummer = Inv;
Mitgliedsnummer = 0;
}

bool Buch::istVerliehen(){
	if (Mitgliedsnummer != 0)
		return true;
	return false;
}
unsigned int Buch::inventarNummer(){
	return Inventarnummer;
}
unsigned int Buch::ausgeliehenVon(){
	return Mitgliedsnummer;
}

bool Buch::verlieheAn(unsigned int mitglied){
	if(Mitgliedsnummer == 0){
		Mitgliedsnummer = mitglied;
		return true;
	}
	return false;
}
void Buch::rueckgabe(){
Mitgliedsnummer = 0;
}
void Buch::print(){
cout << "Buch - Inventarnummer " << Inventarnummer << ": " << Titel + " von " + Autor + ',' + ' ';
if(istVerliehen())
	cout << "nicht verfügbar." << endl;
else cout << "verfügbar." << endl;
}

