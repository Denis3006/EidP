#include"text.h"

Text::Text(string str){
	inhalt = str;
}
unsigned int Text::getAnzahlZeichen() const{
	return inhalt.size();
}
