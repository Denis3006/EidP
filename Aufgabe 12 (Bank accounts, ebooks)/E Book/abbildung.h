
#ifndef ABBILDUNG_H_
#define ABBILDUNG_H_

#include "buchbestandteil.h"
class Abbildung : public Buchbestandteil{
private:
	int cntr = 1;
public:
	unsigned int getAnzahlAbbildungen() const;
};



#endif /* ABBILDUNG_H_ */
