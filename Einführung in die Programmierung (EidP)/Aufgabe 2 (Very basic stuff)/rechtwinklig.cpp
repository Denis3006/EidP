#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((a >= c) || (b >= c)) {
		cout << "c ist nicht das Maximum.";
		return 1;
	} else if ((a <= 0) || (b <= 0) || (c <= 0))
		cout << "Nicht alle Variablen sind positiv.";
	else if (c * c == a * a + b * b)
		cout << "Das Dreieck mit den Seitenlaengen " << a << ", " << b << ", "
				<< c << " ist rechtwinklig.";
	else
		cout << "Das Dreieck mit den Seitenlaengen " << a << ", " << b << ", "
				<< c << " ist nicht rechtwinklig.";
	return 0;
}

