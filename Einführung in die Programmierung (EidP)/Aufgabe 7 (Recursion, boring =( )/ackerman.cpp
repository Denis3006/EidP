#include<iostream>
using namespace std;

int ack(int n, int m) {
if(n == 0)
	return ++m;
else if (m == 0){
	return ack((n-1), 1);
}
else {
	return ack((n-1), ack(n, m - 1));
}
}

int ack2(int n, int m) {
	while (n != 0) {
		if (m == 0)
			m = 1;
		else
			m = ack2(n, (m - 1));
		n--;
	}
	return ++m;
}

int main() {
	int n = 3;
	int m = 13;
	cout << ack2(n, m) << endl;
	cout << ack(n, m);
	return 0;
}

