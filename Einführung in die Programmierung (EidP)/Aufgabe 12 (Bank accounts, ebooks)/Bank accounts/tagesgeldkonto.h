
#ifndef SRC_TAGESGELDKONTO_H_
#define SRC_TAGESGELDKONTO_H_

#include "bankkonto.h"
#include "girokonto.h"

class Tagesgeldkonto : public Bankkonto{
private:
	Girokonto *zielKonto;
public:
	Tagesgeldkonto(unsigned long nummer, string Name, Girokonto &ziel);
	int umbuchen(int betrag);
};



#endif
