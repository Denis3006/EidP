#include <iostream>
using namespace std;

void subtrahiere(int* t, int w) {
	*t -= w;
}

int main() {
	int x = 59, y = -12, z = 23;
	int *a, *b, *c;
	a = &x;
	b = &y;
	c = &z;
	cout << "--- Ausgabe nach Teilaufgabe a) ---" << endl
			<< "\t \t Adresse \t Inhalt \t referenzierter Wert" << endl
			<< "Variable x \t " << &x << "\t " << x << endl << "Variable y \t "
			<< &y << "\t " << y << endl << "Variable z \t " << &z << "\t " << z
			<< endl << endl << "Zeiger a \t " << &a << "\t " << a << "\t" << *a
			<< endl << "Zeiger b \t " << &b << "\t " << b << "\t" << *b << endl
			<< "Zeiger c \t " << &c << "\t " << c << "\t" << *c << endl;
	int *hilf;
	hilf = a;
	a = b;
	b = hilf;
	cout << "--- Ausgabe nach Teilaufgabe b) ---" << endl
			<< "\t \t Adresse \t Inhalt \t referenzierter Wert" << endl
			<< "Variable x \t " << &x << "\t " << x << endl << "Variable y \t "
			<< &y << "\t " << y << endl << "Variable z \t " << &z << "\t " << z
			<< endl << endl << "Zeiger a \t " << &a << "\t " << a << "\t" << *a
			<< endl << "Zeiger b \t " << &b << "\t " << b << "\t" << *b << endl
			<< "Zeiger c \t " << &c << "\t " << c << "\t" << *c << endl;
	*a += 8;
	cout << "--- Ausgabe nach Teilaufgabe d) ---" << endl
			<< "\t \t Adresse \t Inhalt \t referenzierter Wert" << endl
			<< "Variable x \t " << &x << "\t " << x << endl << "Variable y \t "
			<< &y << "\t " << y << endl << "Variable z \t " << &z << "\t " << z
			<< endl << endl << "Zeiger a \t " << &a << "\t " << a << "\t" << *a
			<< endl << "Zeiger b \t " << &b << "\t " << b << "\t" << *b << endl
			<< "Zeiger c \t " << &c << "\t " << c << "\t" << *c << endl
			<< "--- Ausgabe vor Teilaufgabe e) ---" << endl
			<< "\t \t Adresse \t Inhalt \t referenzierter Wert" << endl
			<< "Variable y \t " << &y << "\t " << y << endl;
	subtrahiere(a, 50);
	cout << "--- Ausgabe nach Teilaufgabe e) ---" << endl
			<< "\t \t Adresse \t Inhalt \t referenzierter Wert" << endl
			<< "Variable y \t " << &y << "\t " << y << endl;
return 0;
}

