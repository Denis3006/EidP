#include "sparkonto.h"

#ifndef SRC_GIROKONTO_H_
#define SRC_GIROKONTO_H_

class Girokonto : public Sparkonto{
public:
	Girokonto(unsigned long nummer, string Name);
	int ueberweisen(Bankkonto &zielKonto, int betrag);
};



#endif
