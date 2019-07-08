#include "elektrofahrzeug.h"
#include "ladegutschein.h"

class Ladestation {
private:
	double strom;
public:
	Ladestation();
	Ladestation(double euro);
	double getStrom();
	void laden(Elektrofahrzeug *Auto, Ladegutschein *Gutschein);
	~Ladestation() {};
};
