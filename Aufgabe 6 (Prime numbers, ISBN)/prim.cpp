#include<iostream>
using namespace std;

//static const int n = 1000;
/*
 void gibPrimfaktorenAus(int zahl, bool ist_prim[]) {
 for (int y = 2; y < n; y++) {
 while (ist_prim[y] && y <= zahl && zahl % y == 0) {
 cout << y << ", ";
 zahl /= y;

 }

 }
 cout << endl;
 }
 */

void gibPrimfaktorenAus(int zahl, int anz_primzahlen, int primzahlen[]) {
	for (int y = 0; primzahlen[y] < anz_primzahlen; y++) {
		while (zahl % primzahlen[y] == 0) {
			cout << primzahlen[y] << ", ";
			if (primzahlen[y] * primzahlen[y] > zahl)
				break;
			zahl /= primzahlen[y];
		}
	}
	cout << endl;
}

int main() {
	const int n = 1000;
	bool *ist_prim;
	ist_prim = new bool[n];
	ist_prim[0] = {false};
	ist_prim[1] = {false};
	for (int i = 2; i < n; i++) {
		ist_prim[i] = true;
	}
	int i = 2;
	while (i * i < n) {
		if (ist_prim[i] == true) {
			int j = 2 * i;
			while (j < n) {
				ist_prim[j] = false;
				j += i;
			}
		}
		i++;
	}
	int *primzahlen;
	primzahlen = new int[n];
	int x = 0;
	for (i = 2; i < n; i++) {
		if (ist_prim[i]) {
			primzahlen[x] = i;
			x++;
		}
	}
	int c = 0;
	for (i = 2; i < n; i++) {
		if (i == primzahlen[c]) {
			cout << i << ": prim" << endl;
			c++;
		} else {
			cout << i << ": ";
			gibPrimfaktorenAus(i, n, primzahlen);
		}
	}

	delete[] ist_prim;
	delete[] primzahlen;
	return 0;
}
