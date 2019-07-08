
#ifndef BUCHBESTANDTEIL_H_
#define BUCHBESTANDTEIL_H_

class Buchbestandteil{
public:
	virtual unsigned int getAnzahlZeichen() const = 0;
	virtual unsigned int getAnzahlAbbildungen() const = 0;
	virtual unsigned int getAnzahlTabellen() const = 0;
	unsigned int getAnzahlFloats() const;
};




#endif /* BUCHBESTANDTEIL_H_ */
