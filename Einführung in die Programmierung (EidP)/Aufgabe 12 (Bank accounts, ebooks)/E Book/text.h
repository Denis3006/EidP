

#ifndef TEXT_H_
#define TEXT_H_

#include "buchbestandteil.h"
#include<string>
using namespace std;
class Text : public Buchbestandteil{
private:
	string inhalt;
public:
	Text(string str);
	unsigned int getAnzahlZeichen() const;
};


#endif /* TEXT_H_ */
