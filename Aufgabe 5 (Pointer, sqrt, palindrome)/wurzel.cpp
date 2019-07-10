#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

static int i = 0;

/*double wurzel(double a) {
	double x[100];
	double wurz;
	x[0] = (a + 1) / 2;
	for (i = 0; (i > 100) || (x[i - 1] != x[i]); i++) {
		x[i + 1] = (x[i] + a / x[i]) / 2;
		wurz = x[i + 1];
	}
	return wurz;
}
*/
double wurzel(double a) {
	double hilf = 0;
	double wurz = (a + 1)/2;
	while(wurz != hilf){
		hilf  = wurz;
		wurz = (hilf + a / hilf)/2;
		i++;
	}
	return wurz;
}

int main() {
	double n = 8;
	double dif = sqrt(n) - wurzel(n);
	cout << "Ergebnis wurzel(a):" << wurzel(n) << endl << "Ergebnis sqrt(a):"  
			<< sqrt(n) << endl;
	cout << "Anzahl Schleifendurchl�ufe: " << i << endl;
	cout << "Differenz: " << setprecision(17) << dif << endl;
}
