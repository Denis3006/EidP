// recreated 08.07.2019
#ifndef KREDITKARTE_H_
#define KREDITKARTE_H_
#include <iostream>
using namespace std;

class KreditKarteException {
public:
	int betrag, error;
	virtual void what() = 0;
	KreditKarteException(int b, int err) : betrag(b), error(err) {};
};

class LimitException : public KreditKarteException {
public:
	LimitException(int b, int err) : KreditKarteException(b, err){};
	void what() {
		cout << "LimitException: \t --betrag : " << betrag << "  --limit : " << error << endl;
	}
};

class GuthabenException : public KreditKarteException {
public:
	GuthabenException(int b, int err) : KreditKarteException(b, err) {};
	void what() {
		cout << "GuthabenException: \t --betrag : " << betrag << "  --max Guthaben : " << error << endl;
	}
};

class LimitUngueltigException : public KreditKarteException {
public:
	LimitUngueltigException(int b, int err) : KreditKarteException(b, err) {};
	void what() {
		cout << "LimitUngueltigException: \t --betrag : " << betrag << "  --neues limit : " << error << endl;
	}
};

class Kreditkarte {
public:
    Kreditkarte(int limit);
    virtual ~Kreditkarte() = default;

    void aufladen(int betrag);
    void bezahlen(int betrag);
    int getSaldo() const;
    Kreditkarte &uebertragen(Kreditkarte &karte, int betrag);
    void setLimit(int limit);
    void druck() const;

private:
    int m_limit;
    int m_saldo = 0;
    int m_maxGuthaben = 5000;
};

#endif /* KREDITKARTE_H_ */
