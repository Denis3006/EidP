#include <iostream>
using namespace std;

int main() {

	int Bin[8];
	int Dez;
	int i = 0;
	cout << "Bitte eine Zahl eingeben: ";
	cin >> Dez;
	if (Dez >= 0 && Dez < 256) {
		do {
			Bin[i] = Dez % 2;
			Dez /= 2;
			i++;
		} while (i < 8);
		cout << "Binaerdarstellung: ";
		for (int n = 7; n >= 0; n--)
			cout << Bin[n];
	} else {
		cout << "Geben Sie bitte einen Zahl aus dem Wertebereich 0-255 ein.";
		return 1;
	}
	cout << endl << "Invertierte Binaerdarstellung: ";
	for (int n = 7; n >= 0; n--) {
		if (Bin[n] != 0) {
			Bin[n] = 0;
			cout << Bin[n];
		} else {
			Bin[n] = 1;
			cout << Bin[n];
		}
	}

	cout << endl << "Invertierte Zahl: "
			<< 2 * 2 * 2 * 2 * 2 * 2 * 2 * Bin[7]
					+ 2 * 2 * 2 * 2 * 2 * 2 * Bin[6]
					+ 2 * 2 * 2 * 2 * 2 * Bin[5] + 2 * 2 * 2 * 2 * Bin[4]
					+ 2 * 2 * 2 * Bin[3] + 2 * 2 * Bin[2] + 2 * Bin[1] + Bin[0];
	cout << endl << "Invertierte Zahl: "
			<< ((((((Bin[7] * 2 + Bin[6]) * 2 + Bin[5]) * 2 + Bin[4]) * 2
					+ Bin[3]) * 2 + Bin[2]) * 2 + Bin[1]) * 2 + Bin[0];
	/* 08.07.2019 
		Dez = 0;
		for(int i = 7; i <= 0; i--)
			Dez += pow(2, i) * Bin[i];
		cout << Dez;

		So währe schöner, ich wußte aber nicht, wie man 2^i in C++ schreibt =)
	*/
	return 0;
}
