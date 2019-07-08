// Lösung: WwWwSXSwWwW
// 08.07.2019: Ich erinnere mich ich dachte, dieses Programm war echt cool und bisschen schwer. 
// Ich dachte, dass man auch ähnliche Programme für echte Problemstellungen schreibt. 
#include <iostream>
using namespace std;

void spiel(int x, string y) {
	switch (x) {
	case 0:
		cout << "";
		break;
	case 1:
		cout << y;
		break;
	case 2:
		cout << y << y;
		break;
	case 3:
		cout << y << y << y;
		break;
	}
}
;
int main() {

	enum subjekte {
		Boot = 0, Wolf = 1, Schaf = 2
	};

	struct info {
		char name[10];
		int anzahl;
	};

	info nord[3];
	info boot = { "Boot", 1 };
	nord[Boot] = boot;
	info wolf = { "Wolf", 3 };
	nord[Wolf] = wolf;
	info schaf = { "Schaf", 3 };
	nord[Schaf] = schaf;

	info sued[3];
	info bootsued = { "Boot", 0 };
	sued[Boot] = bootsued;
	info wolfsued = { "Wolf", 0 };
	sued[Wolf] = wolfsued;
	info schafsued = { "Schaf", 0 };
	sued[Schaf] = schafsued;

	bool abbruch = false;
	int i = 1;
	while (!abbruch) {
		char c;
		cout << "Geben Sie bitte ein Zeichen ein:";
		cin >> c;
		cout << endl;
		switch (c) {
		case 'w': {
			if (i % 2 == 1) {
				if (nord[Wolf].anzahl > 0) {
					nord[Wolf].anzahl -= 1;
					sued[Wolf].anzahl += 1;
					nord[Boot].anzahl -= 1;
					sued[Boot].anzahl += 1;

					cout << "Ufer Nord: ";

					spiel(nord[Boot].anzahl, "Boot ");
					spiel(nord[Wolf].anzahl, "Wolf ");
					spiel(nord[Schaf].anzahl, "Schaf ");

					cout << endl
							<< "------------------------------------------------"
							<< endl;

					cout << "Ufer S�d: ";

					spiel(sued[Boot].anzahl, "Boot ");
					spiel(sued[Wolf].anzahl, "Wolf ");
					spiel(sued[Schaf].anzahl, "Schaf ");
					cout << endl;
					i++;
				} else
					cout << "Fehler! Versuchen Sie bitte nochmal!" << endl;
			} else if (sued[Wolf].anzahl > 0) {
				nord[Wolf].anzahl += 1;
				sued[Wolf].anzahl -= 1;
				sued[Boot].anzahl -= 1;
				nord[Boot].anzahl += 1;

				cout << "Ufer Nord: ";

				spiel(nord[Boot].anzahl, "Boot ");
				spiel(nord[Wolf].anzahl, "Wolf ");
				spiel(nord[Schaf].anzahl, "Schaf ");

				cout << endl
						<< "------------------------------------------------"
						<< endl;

				cout << "Ufer S�d: ";

				spiel(sued[Boot].anzahl, "Boot ");
				spiel(sued[Wolf].anzahl, "Wolf ");
				spiel(sued[Schaf].anzahl, "Schaf ");
				cout << endl;
				i++;
			} else
				cout << "Fehler. Versuchen Sie bitte nochmal!" << endl;

			break;
		}

		case 'W': {
			if (i % 2 == 1) {
				if (nord[Wolf].anzahl > 1) {
					nord[Wolf].anzahl -= 2;
					sued[Wolf].anzahl += 2;
					nord[Boot].anzahl -= 1;
					sued[Boot].anzahl += 1;

					cout << "Ufer Nord: ";

					spiel(nord[Boot].anzahl, "Boot ");
					spiel(nord[Wolf].anzahl, "Wolf ");
					spiel(nord[Schaf].anzahl, "Schaf ");

					cout << endl
							<< "------------------------------------------------"
							<< endl;

					cout << "Ufer S�d: ";

					spiel(sued[Boot].anzahl, "Boot ");
					spiel(sued[Wolf].anzahl, "Wolf ");
					spiel(sued[Schaf].anzahl, "Schaf ");
					cout << endl;
					i++;
				} else
					cout << "Fehler. Versuchen Sie bitte nochmal!" << endl;
			} else if (sued[Wolf].anzahl > 1) {
				sued[Wolf].anzahl -= 2;
				nord[Wolf].anzahl += 2;
				sued[Boot].anzahl -= 1;
				nord[Boot].anzahl += 1;

				cout << "Ufer Nord: ";

				spiel(nord[Boot].anzahl, "Boot ");
				spiel(nord[Wolf].anzahl, "Wolf ");
				spiel(nord[Schaf].anzahl, "Schaf ");

				cout << endl
						<< "------------------------------------------------"
						<< endl;

				cout << "Ufer S�d: ";

				spiel(sued[Boot].anzahl, "Boot ");
				spiel(sued[Wolf].anzahl, "Wolf ");
				spiel(sued[Schaf].anzahl, "Schaf ");
				cout << endl;
				i++;
			} else
				cout << "Fehler! Versuchen Sie bitte nochmal!" << endl;
			break;
		}
		case 's': {
			if (i % 2 == 1) {
				if (nord[Schaf].anzahl > 0) {
					nord[Schaf].anzahl -= 1;
					sued[Schaf].anzahl += 1;
					nord[Boot].anzahl -= 1;
					sued[Boot].anzahl += 1;

					cout << "Ufer Nord: ";

					spiel(nord[Boot].anzahl, "Boot ");
					spiel(nord[Wolf].anzahl, "Wolf ");
					spiel(nord[Schaf].anzahl, "Schaf ");

					cout << endl
							<< "------------------------------------------------"
							<< endl;

					cout << "Ufer S�d: ";

					spiel(sued[Boot].anzahl, "Boot ");
					spiel(sued[Wolf].anzahl, "Wolf ");
					spiel(sued[Schaf].anzahl, "Schaf ");
					cout << endl;
					i++;
				} else
					cout << "Fehler! Versuchen Sie bitte nochmal!" << endl;
			} else

			if (sued[Schaf].anzahl > 0) {
				sued[Schaf].anzahl -= 1;
				nord[Schaf].anzahl += 1;
				sued[Boot].anzahl -= 1;
				nord[Boot].anzahl += 1;

				cout << "Ufer Nord: ";

				spiel(nord[Boot].anzahl, "Boot ");
				spiel(nord[Wolf].anzahl, "Wolf ");
				spiel(nord[Schaf].anzahl, "Schaf ");

				cout << endl
						<< "------------------------------------------------"
						<< endl;

				cout << "Ufer S�d: ";

				spiel(sued[Boot].anzahl, "Boot ");
				spiel(sued[Wolf].anzahl, "Wolf ");
				spiel(sued[Schaf].anzahl, "Schaf ");
				cout << endl;
				i++;
			} else
				cout << "Fehler! Versuchen Sie bitte nochmal!" << endl;
			break;
		}
		case 'S': {
			if (i % 2 == 1) {
				if (nord[Schaf].anzahl > 1) {
					nord[Schaf].anzahl -= 2;
					sued[Schaf].anzahl += 2;
					nord[Boot].anzahl -= 1;
					sued[Boot].anzahl += 1;

					cout << "Ufer Nord: ";

					spiel(nord[Boot].anzahl, "Boot ");
					spiel(nord[Wolf].anzahl, "Wolf ");
					spiel(nord[Schaf].anzahl, "Schaf ");

					cout << endl
							<< "------------------------------------------------"
							<< endl;

					cout << "Ufer S�d: ";

					spiel(sued[Boot].anzahl, "Boot ");
					spiel(sued[Wolf].anzahl, "Wolf ");
					spiel(sued[Schaf].anzahl, "Schaf ");
					cout << endl;
					i++;
				} else
					cout << "Fehler! Versuchen Sie bitte nochmal!" << endl;
			} else if (sued[Schaf].anzahl > 1) {
				sued[Schaf].anzahl -= 2;
				nord[Schaf].anzahl += 2;
				sued[Boot].anzahl += 1;
				nord[Boot].anzahl -= 1;

				cout << "Ufer Nord: ";

				spiel(nord[Boot].anzahl, "Boot ");
				spiel(nord[Wolf].anzahl, "Wolf ");
				spiel(nord[Schaf].anzahl, "Schaf ");

				cout << endl
						<< "------------------------------------------------"
						<< endl;

				cout << "Ufer S�d: ";

				spiel(sued[Boot].anzahl, "Boot ");
				spiel(sued[Wolf].anzahl, "Wolf ");
				spiel(sued[Schaf].anzahl, "Schaf ");
				cout << endl;
				i++;
			} else
				cout << "Fehler! Versuchen Sie bitte nochmal!" << endl;
			break;
		}
		case 'X': {
			if (i % 2 == 1) {
				if (nord[Wolf].anzahl > 0 && nord[Schaf].anzahl > 0) {
					nord[Schaf].anzahl -= 1;
					sued[Schaf].anzahl += 1;
					nord[Wolf].anzahl -= 1;
					sued[Wolf].anzahl += 1;
					nord[Boot].anzahl -= 1;
					sued[Boot].anzahl += 1;

					cout << "Ufer Nord: ";

					spiel(nord[Boot].anzahl, "Boot ");
					spiel(nord[Wolf].anzahl, "Wolf ");
					spiel(nord[Schaf].anzahl, "Schaf ");

					cout << endl
							<< "------------------------------------------------"
							<< endl;

					cout << "Ufer S�d: ";

					spiel(sued[Boot].anzahl, "Boot ");
					spiel(sued[Wolf].anzahl, "Wolf ");
					spiel(sued[Schaf].anzahl, "Schaf ");
					cout << endl;
					i++;
				} else
					cout << "Fehler! Versuchen Sie bitte Nochmal!" << endl;
			} else if (sued[Wolf].anzahl > 0 && sued[Schaf].anzahl > 0) {
				sued[Schaf].anzahl -= 1;
				nord[Schaf].anzahl += 1;
				sued[Wolf].anzahl -= 1;
				nord[Wolf].anzahl += 1;
				sued[Boot].anzahl -= 1;
				nord[Boot].anzahl += 1;

				cout << "Ufer Nord: ";

				spiel(nord[Boot].anzahl, "Boot ");
				spiel(nord[Wolf].anzahl, "Wolf ");
				spiel(nord[Schaf].anzahl, "Schaf ");

				cout << endl
						<< "------------------------------------------------"
						<< endl;

				cout << "Ufer S�d: ";

				spiel(sued[Boot].anzahl, "Boot ");
				spiel(sued[Wolf].anzahl, "Wolf ");
				spiel(sued[Schaf].anzahl, "Schaf ");
				cout << endl;
				i++;
			} else
				cout << "Fehler! Versuchen Sie bitte nochmal!" << endl;
			break;
		}
		case 'Q': {
			cout << "Ufer Nord: ";

			spiel(nord[Boot].anzahl, "Boot ");
			spiel(nord[Wolf].anzahl, "Wolf ");
			spiel(nord[Schaf].anzahl, "Schaf ");

			cout << endl << "------------------------------------------------"
					<< endl;

			cout << "Ufer S�d: ";

			spiel(sued[Boot].anzahl, "Boot ");
			spiel(sued[Wolf].anzahl, "Wolf ");
			spiel(sued[Schaf].anzahl, "Schaf ");
			abbruch = true;
			break;
		}

		default: {
			cout << "Fehler. Falsche Aktion.";
			break;
		}
		}
		if (((nord[Wolf].anzahl > nord[Schaf].anzahl)
				|| (sued[Wolf].anzahl > sued[Schaf].anzahl))
				&& (sued[Schaf].anzahl > 0) && (nord[Schaf].anzahl > 0)) {
			abbruch = true;
			cout << "Es gibt mehr Wolfen, als Schafen";
		}
		if (sued[Wolf].anzahl == 3 && sued[Schaf].anzahl == 3) {
			cout << "Erfolg! Alle Tiere haben das andere Ufer erreicht!";
			abbruch = true;
		}
	}
	return 0;
}
