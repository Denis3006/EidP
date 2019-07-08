#ifndef MITGLIED_H_
#define MITGLIED_H_
#include<string>
#include<iostream>

using namespace std;

class Mitglied{
private:
	string Name;
	unsigned int Mitgliedsnummer;
public:
	Mitglied(string name, unsigned int nummer);
	unsigned int mitgliedsNummer();
	void print();
	~Mitglied(){};
};



#endif /* MITGLIED_H_ */
