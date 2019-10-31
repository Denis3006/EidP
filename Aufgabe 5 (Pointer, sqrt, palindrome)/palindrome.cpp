#include <iostream>
#include <cstring>

using namespace std;

/* 08.07.2019 die Fkt. war falsch, da ich nur den letzten Symbol überpfrüft habe. 
   Zufälligerweise hat der nicht-palindrom aus der Aufgabenstellung ungleiche erste und letzte Zeichen. 
bool istPalindrom(char string[]) {

	int laenge = strlen(string);
	bool palindrom;
	for (int i = 0; i < laenge; i++) {
		laenge--;
		palindrom = (string[i] == string[laenge]);
	}
	return palindrom;

}
*/

// Ergänzt 08.07.2019

bool istPalindrom(char* string) {

	int right = strlen(string) - 1;
	for (int left = 0; left < right; left++, right--) {
		if (string[left] != string[right])
			return false;
	}
	return true;
}

int main() {
	char string1[] = "reliefpfeiler";
	char string2[] = "erikafeuertnuruntreuefakire";
	char string3[] = "programmierenlernen?";
	char string4[] = "programmierenlernen?p";  // 08.07.2019 Dies wäre ein Palindrom nach ursrünglicher Funktion 

	cout << "Palindrom-Check" << endl;
	cout << "---------------" << endl;

	cout << endl;
	cout << "Beim Ausdruck " << string1 << " handelt es sich um ";
	if (istPalindrom(string1))
		cout << "ein Palindrom.";
	else
		cout << "KEIN Palindrom.";
	cout << endl;
	cout << "Beim Ausdruck " << string2 << " handelt es sich um ";
	if (istPalindrom(string2))
		cout << "ein Palindrom.";
	else
		cout << "KEIN Palindrom.";
	cout << endl;
	cout << "Beim Ausdruck " << string3 << " handelt es sich um ";
	if (istPalindrom(string3))
		cout << "ein Palindrom.";
	else
		cout << "KEIN Palindrom.";
		cout << endl;
	cout << "Beim Ausdruck " << string4 << " handelt es sich um ";
	if (istPalindrom(string4))
		cout << "ein Palindrom.";
	else
		cout << "KEIN Palindrom.";

	return 0;
}
