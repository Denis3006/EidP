#include<iostream>
#include<cmath>
using namespace std;

long long rekLind(unsigned int n, unsigned int &count) {
	int b = 1;
	int a = 3;
	if (n == 1){
		count++;
		return 1;
	}
	if (n == 2){
		count++;
		return 1;
	}
	else{
		count ++;
		return (b * (rekLind((n - 1), count)) + (a * (rekLind((n - 2), count))));
	}

}

long long itLind(unsigned int n, unsigned int &count) {
	int a = 3;
	int b = 1;
	long long Lind = 1;
	long long Lind3 = 1;
	long long Lind2 = 1;
	for (unsigned int i = 3; i <= n; i++) {
		Lind = b*(Lind2) + a *(Lind3);
		Lind3 = Lind2;
		Lind2 = Lind;
		count++;
	}
	return Lind;
}

long long moivreBinetLind(unsigned int n){
	return (1/sqrt(13))*(pow(((1+sqrt(13))/2), n) - pow(((1-sqrt(13))/2), n));
}

int main() {
	unsigned int countr = 0;
	unsigned int counti = 0;
	unsigned int n = 49;
	//cout << rekLind(n, countr) << " " << countr << endl;
	cout << itLind(n, counti) << " " << counti << endl;
	cout << moivreBinetLind(n) << endl;
	return 0;
}

