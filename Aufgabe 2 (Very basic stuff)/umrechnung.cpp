#include <iostream>
using namespace std;

int main(){
double euro = 100000, dollar, yen, rubel;
dollar = euro/0.85;
yen = euro * 133.71;
rubel = euro * 67.7;
cout << euro << " Euro = " << dollar << " Dollar, " << yen <<" Yen, " << rubel <<" Ruble.";
return 0;
}


