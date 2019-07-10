#include"buchbestandteil.h"

unsigned int Buchbestandteil::getAnzahlFloats() const{
	return getAnzahlTabellen()+getAnzahlAbbildungen();
}
