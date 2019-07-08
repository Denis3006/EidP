#include"mitglied.h"
using namespace std;

Mitglied::Mitglied(string name, unsigned int nummer){
	Name = name;
	Mitgliedsnummer = nummer;
}

unsigned int Mitglied::mitgliedsNummer(){
	return Mitgliedsnummer;
}

void Mitglied::print(){
	cout << "Mitglied " << Mitgliedsnummer << ": " << Name + '.' << endl;
}
