#ifndef SRC_BANKKONTO_H_
#define SRC_BANKKONTO_H_

#include<string>
#include<iostream>
using namespace std;

class Bankkonto{
protected:
	unsigned long Kontonummer;
	string Inhaber;
	int Kontostand = 0;
	int grenz = 0;
public:
	Bankkonto();
	Bankkonto(unsigned long nummer,string Name);
	void gutschreiben(int betrag);
	virtual int kontostand() const;
	virtual void anzeigen() const;
	unsigned long kontonummer() const;
};



#endif /* SRC_BANKKONTO_H_ */
