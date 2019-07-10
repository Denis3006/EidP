#ifndef TABELLE_H_
#define TABELLE_H_

#include"buchbestandteil.h"

class Tabelle : public Buchbestandteil{
private:
	int cntr = 1;
public:
	Tabelle();
	unsigned int getAnzahlTabellen() const;
};



#endif /* TABELLE_H_ */
