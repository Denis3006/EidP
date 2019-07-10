#include<iostream>
using namespace std;

/*void umwandlung(char isbn[], int zahl[10]) {
 for(int i = 0; i < 10; i++){
 switch (isbn[i]) {
 case '0':
 zahl[i] = 0;
 break;
 case '1':
 zahl[i] = 1;
 break;
 case '2':
 zahl[i] = 2;
 break;
 case '3':
 zahl[i] = 3;
 break;
 case '4':
 zahl[i] = 4;
 break;
 case '5':
 zahl[i] = 5;
 break;
 case '6':
 zahl[i] = 6;
 break;
 case '7':
 zahl[i] = 7;
 break;
 case '8':
 zahl[i] = 8;
 break;
 case '9':
 zahl[i] = 9;
 break;
 case 'x':
 zahl[i] = 10;
 break;
 default:
 cout << "Keine ISBN-Nummer." << endl;
 }


 }
 }
 */
int umwandlung(char isbn) {
	int zahl = 0;
	switch (isbn) {
	case '0':
		zahl = 0;
		break;
	case '1':
		zahl = 1;
		break;
	case '2':
		zahl = 2;
		break;
	case '3':
		zahl = 3;
		break;
	case '4':
		zahl = 4;
		break;
	case '5':
		zahl = 5;
		break;
	case '6':
		zahl = 6;
		break;
	case '7':
		zahl = 7;
		break;
	case '8':
		zahl = 8;
		break;
	case '9':
		zahl = 9;
		break;
	case 'x':
		zahl = 10;
		break;
	}
	return zahl;
}

bool isbn10check(int isbn[]) {
	int mod = 0;
	for (int i = 0; i < 9; i++) {
		mod += (i + 1) * isbn[i];
	}
	return (mod % 11 == isbn[9]);
}

int main() {
	char isbn1[] = "349913599x";
	char isbn2[] = "2871499367";
	int zahl1[10];
	int zahl2[10];
	for (int i = 0; i < 10; i++)
		zahl1[i] = umwandlung(isbn1[i]);
	if (isbn10check(zahl1)) {
		cout << "Die Zahl ";
		for (int i = 0; i < 10; i++)
			cout << isbn1[i];
		cout << " ist eine ISBN-Nummer." << endl;
	} else {
		cout << "Die Zahl ";
		for (int i = 0; i < 10; i++)
			cout << isbn1[i];
		cout << " ist keine ISBN-Nummer." << endl;
	}
	for (int i = 0; i < 10; i++)
		zahl2[i] = umwandlung(isbn2[i]);
	if (isbn10check(zahl2)) {
		cout << "Die Zahl";
		for (int i = 0; i < 10; i++)
			cout << isbn2[i];
		cout << " ist eine ISBN-Nummer";
	} else {
		cout << "Die Zahl ";
		for (int i = 0; i < 10; i++)
			cout << isbn2[i];
		cout << " ist keine ISBN-Nummer";
	}
	return 0;
}

