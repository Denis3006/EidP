// recreated 08.07.2019
#include "kreditkarte.h"
#include <iostream>

using namespace std;

Kreditkarte::Kreditkarte(int limit) : m_limit{ limit } {}

void Kreditkarte::druck() const
{
    cout << "Aktueller Saldo ist " << m_saldo << " EUR, "
         << " maximale Ueberziehung " << m_limit << " EUR" << endl;
}

void Kreditkarte::bezahlen(int betrag)
{
	if (m_saldo - betrag < -m_limit)
		throw(LimitException(betrag, m_limit));
	m_saldo -= betrag;
}

void Kreditkarte::aufladen(int betrag) 
{
	if (m_saldo + betrag > m_maxGuthaben)
		throw(GuthabenException(betrag, m_maxGuthaben));
	m_saldo += betrag;
}

int Kreditkarte::getSaldo() const 
{
	return m_saldo;
}

Kreditkarte& Kreditkarte::uebertragen(Kreditkarte& v, int betrag)
{
	v.bezahlen(betrag);
	aufladen(betrag);
	return v;
}

void Kreditkarte::setLimit(int limit) 
{
	if (m_saldo <= -limit)
		throw(LimitUngueltigException(m_saldo, limit));
	m_limit = limit;
}