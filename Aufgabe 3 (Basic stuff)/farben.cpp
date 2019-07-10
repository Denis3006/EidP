#include <iostream>
using namespace std;

int main() {

	enum Farben {
		Rot, Gruen, Blau, Gelb, Weiss, Schwarz
	};
	for (int i = Rot; i <= 5; i++) {

		for (int j = Rot; j <= 5; j++) {

			switch (i) {
			case Rot:
				cout << "Rot ";
				break;
			case Gruen:
				cout << "Gruen ";
				break;
			case Blau:
				cout << "Blau ";
				break;
			case Gelb:
				cout << "Gelb ";
				break;
			case Weiss:
				cout << "Weiss ";
				break;
			case Schwarz:
				cout << "Schwarz ";
				break;
			}
			switch (j) {
			case Rot:
				cout << "Rot: ";
				if (j == i)
					cout << "gewonnen";
				else
					cout << "verloren";
				cout << endl;
				break;
			case Gruen:
				cout << "Gruen: ";
				if (j == i)
					cout << "gewonnen";
				else
					cout << "verloren";
				cout << endl;
				break;
			case Blau:
				cout << "Blau: ";
				if (j == i)
					cout << "gewonnen";
				else
					cout << "verloren";
				cout << endl;
				break;
			case Gelb:
				cout << "Gelb: ";
				if (j == i)
					cout << "gewonnen";
				else
					cout << "verloren";
				cout << endl;
				break;
			case Weiss:
				cout << "Weiss: ";
				if (j == i)
					cout << "gewonnen";
				else
					cout << "verloren";
				cout << endl;
				break;
			case Schwarz:
				cout << "Schwarz: ";
				if (j == i)
					cout << "gewonnen";
				else
					cout << "verloren";
				cout << endl;
				break;
			}

		}
	}

	return 0;
}

