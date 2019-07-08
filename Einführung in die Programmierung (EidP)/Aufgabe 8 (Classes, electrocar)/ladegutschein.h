#ifndef LADEGUTSCHEIN_H
#define LADEGUTSCHEIN_H
class Ladegutschein {
private:
	unsigned int ID;
	double euro;
	void fehler();
public:
	Ladegutschein(double geld);
	unsigned int getID();
	double getGutschein();
	void setzeGutschein(double geld);
	~Ladegutschein() {}
};
#endif
