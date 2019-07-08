#ifndef KAPITEL_H_
#define KAPITEL_H_

#include "buchbestandteil.h"
#include "eidpliste.h"
class Kapitel : public Buchbestandteil{
private:
	Liste<Buchbestandteil*> bestandteile;
public:
	Kapitel(Liste<Buchbestandteil*> const &list);
	unsigned int getAnzahlZeichen() const;
	unsigned int getAnzahlAbbildungen() const;
	unsigned int getAnzahlTabellen() const;
};



#endif /* KAPITEL_H_ */
