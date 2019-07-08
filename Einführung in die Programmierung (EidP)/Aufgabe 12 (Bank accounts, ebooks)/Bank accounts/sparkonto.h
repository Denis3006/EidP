#ifndef SRC_SPARKONTO_H_
#define SRC_SPARKONTO_H_

#include"bankkonto.h"
class Sparkonto : public Bankkonto{
private:
protected:
	bool aufgeloest = false;
public:
	Sparkonto();
	int aufloesen();
	Sparkonto(unsigned long nummer, string Name);
	void gutschreiben(int betrag);
	int auszahlen(int betrag);
};



#endif /* SRC_SPARKONTO_H_ */
