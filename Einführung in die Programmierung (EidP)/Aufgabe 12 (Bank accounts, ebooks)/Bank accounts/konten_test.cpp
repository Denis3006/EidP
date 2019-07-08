#include <cstdlib>
#include <iostream>

#include "Bankkonto.h"
#include "Girokonto.h"
#include "Sparkonto.h"
#include "Tagesgeldkonto.h"

using namespace std;

template <class T>
void customassert(T istWert, T sollWert, string fehlerMeldung)
{
    if (istWert != sollWert) {
        cerr << "Gültigkeitsprüfung fehlgeschlagen - istWert: " << istWert << ", sollWert: " << sollWert << endl;
        cerr << "Fehlermeldung: " << fehlerMeldung << endl;
        exit(1);
    }
}

int main()
{
    Girokonto giro(10001, "Girokontoinhaber");
    Girokonto giro2(20002, "Girokontoinhaberin 2");
    Sparkonto spar(30003, "Sparkontoinhaber");
    Tagesgeldkonto tag(40004, "Tagesgeldkontoinhaberin", giro2);

    cout << "Übersicht der Konten:" << endl;
    giro.anzeigen();
    cout << endl;
    giro2.anzeigen();
    cout << endl;
    spar.anzeigen();
    cout << endl;
    tag.anzeigen();

    customassert(giro.kontostand(), 0, "Girokonto-Kontostand falsch initialisiert");
    customassert(spar.kontostand(), 100, "Girokonto-Kontostand falsch initialisiert");
    customassert(tag.kontostand(), 0, "Girokonto-Kontostand falsch initialisiert");

    cout << endl << "---------" << endl << endl;
    cout << "Teste Sparkonto..." << endl;

    cout << "Sparkonto: Gutschreiben von 900" << endl;
    spar.gutschreiben(900);
    cout << "-> Sparkonto: Kontostand: " << spar.kontostand() << endl;
    customassert(spar.kontostand(), 1000, "Sparkonto: Gutschreiben fehlerhaft");

    cout << "Sparkonto: Auszahlen von 200" << endl;
    spar.auszahlen(200);
    cout << "-> Sparkonto: Kontostand: " << spar.kontostand() << endl;
    customassert(spar.kontostand(), 800, "Sparkonto: Auszahlen fehlerhaft");

    cout << "Sparkonto: Auszahlen von 2000" << endl;
    int istBetrag = spar.auszahlen(2000);
    cout << "-> Sparkonto: Kontostand: " << spar.kontostand() << ", ausgezahlter Betrag " << istBetrag << endl;
    customassert(spar.kontostand(), 100, "Sparkonto: Auszahlen fehlerhaft da Limit ueberschritten");
    customassert(istBetrag, 700, "Sparkonto: Auszahlen fehlerhaft da Limit ueberschritten");

    cout << "Sparkonto: aufloesen" << endl;
    spar.aufloesen();
    cout << "-> Sparkonto: Kontostand: " << spar.kontostand() << endl;
    customassert(spar.kontostand(), 0, "Sparkonto: Aufloesen fehlerhaft");

    cout << "Sparkonto: Gutschreiben von 1000" << endl;
    spar.gutschreiben(1000);
    cout << "-> Sparkonto: Kontostand: " << spar.kontostand() << endl;
    customassert(spar.kontostand(), 0, "Sparkonto: Gutschreiben fehlerhaft; Konto aufgeloest");

    cout << endl << "---------" << endl << endl;
    cout << "Teste Girokonto..." << endl;

    cout << "Girokonto " << giro.kontonummer() << ": Gutschreiben von 200000" << endl;
    giro.gutschreiben(200000);
    cout << "-> Girokonto " << giro.kontonummer() << ": Kontostand: " << giro.kontostand() << endl;
    customassert(giro.kontostand(), 200000, "Girokonto: Gutschreiben fehlerhaft");

    cout << "Girokonto " << giro.kontonummer() << ": Auszahlen von 250000" << endl;
    giro.auszahlen(250000);
    cout << "-> Girokonto " << giro.kontonummer() << ": Kontostand: " << giro.kontostand() << endl;
    customassert(giro.kontostand(), -50000, "Girokonto: Auszahlen fehlerhaft");

    cout << "Girokonto " << giro.kontonummer() << ": Auszahlen von 200000" << endl;
    giro.auszahlen(20000);
    cout << "-> Girokonto " << giro.kontonummer() << ": Kontostand: " << giro.kontostand() << endl;
    customassert(giro.kontostand(), -70000, "Girokonto: Auszahlen fehlerhaft");

    cout << "Girokonto " << giro.kontonummer() << ": Auszahlen von 100000" << endl;
    istBetrag = giro.auszahlen(100000);
    cout << "-> Girokonto " << giro.kontonummer() << ": Kontostand: " << giro.kontostand() << ", ausgezahlter Betrag "
         << istBetrag << endl;
    customassert(giro.kontostand(), -100000,
                      "Girokonto: Auszahlen fehlerhaft da Limit von -100000 ueberschritten");

    cout << "Girokonto " << giro.kontonummer() << ": Gutschreiben von 200000" << endl;
    giro.gutschreiben(200000);
    cout << "-> Girokonto " << giro.kontonummer() << ": Kontostand: " << giro.kontostand() << endl;
    customassert(giro.kontostand(), 100000, "Sparkonto: Gutschreiben fehlerhaft");

    cout << "Girokonto " << giro.kontonummer() << ": Ueberweise 50000 auf Girokonto " << giro2.kontonummer()
         << " mit Kontostand " << giro2.kontostand() << endl;
    istBetrag = giro.ueberweisen(giro2, 50000);
    cout << "-> Girokonto " << giro.kontonummer() << ": Kontostand: " << giro.kontostand() << endl;
    cout << "-> Girokonto " << giro2.kontonummer() << " : Kontostand: " << giro2.kontostand() << endl;
    customassert(giro.kontostand(), 50000, "Girokonto: Ueberweisen fehlerhaft");
    customassert(giro2.kontostand(), 50000, "Girokonto: Ueberweisen fehlerhaft");

    cout << "Girokonto " << giro.kontonummer() << ": Ueberweise 700000 auf Girokonto " << giro2.kontonummer()
         << " mit Kontostand " << giro2.kontostand() << endl;
    istBetrag = giro.ueberweisen(giro2, 700000);
    cout << "-> tatsaechlich uberwiesen: " << istBetrag << endl;
    cout << "-> Girokonto " << giro.kontonummer() << ": Kontostand: " << giro.kontostand() << endl;
    cout << "-> Girokonto " << giro2.kontonummer() << ": Kontostand: " << giro2.kontostand() << endl;
    customassert(istBetrag, 150000, "Girokonto: Ueberweisen fehlerhaft da Limit ueberschritten");
    customassert(giro.kontostand(), -100000, "Girokonto: Ueberweisen fehlerhaft da Limit ueberschritten");
    customassert(giro2.kontostand(), 200000, "Girokonto: Ueberweisen fehlerhaft da Limit ueberschritten");

    cout << "Girokonto " << giro2.kontonummer() << ": Ueberweise 1 auf das gleiche Konto" << endl;
    giro2.ueberweisen(giro2, 1);
    cout << "-> Girokonto " << giro2.kontonummer() << ": Kontostand: " << giro2.kontostand() << endl;
    customassert(giro2.kontostand(), 200000, "Girokonto: Ueberweisen auf identisches Konto veraendert Kontostand");

    cout << endl << "---------" << endl << endl;
    cout << "Teste Tagesgeldkonto..." << endl;

    cout << "Tagesgeldkonto: Umbuchen 1000" << endl;
    istBetrag = tag.umbuchen(10);
    customassert(tag.kontostand(), 0, "Tagesgeldkonto: Umbuchen fehlerhaft da Limit ueberzogen");
    customassert(giro2.kontostand(), 200000,
                      "Tagesgeldkonto: Umbuchen fehlerhaft da Limit ueberzogen und keine Aenderung am Girokonto");

    cout << "Tagesgeldkonto: Einzahlen 1000" << endl;
    cout << "-> Tagesgeldkonto Kontostand: " << tag.kontostand() << endl;
    tag.gutschreiben(1000);
    customassert(tag.kontostand(), 1000, "Tagesgeldkonto: Gutschreiben fehlerhaft");

    cout << "Tagesgeldkonto: Umbuchen 100" << endl;
    istBetrag = tag.umbuchen(100);
    cout << "-> Tagesgeldkonto Kontostand: " << tag.kontostand() << endl;
    cout << "-> Girokonto " << giro2.kontonummer() << ": Kontostand: " << giro2.kontostand() << endl;
    customassert(tag.kontostand(), 900, "Tagesgeldkonto: Umbuchen fehlerhaft");
    customassert(giro2.kontostand(), 200100, "Tagesgeldkonto: Umbuchen fehlerhaft");

    cout << "Tagesgeldkonto: Umbuchen 1000" << endl;
    istBetrag = tag.umbuchen(1000);
    cout << "-> tatsaechlicher Betrag: " << istBetrag << endl;
    cout << "-> Tagesgeldkonto Kontostand: " << tag.kontostand() << endl;
    cout << "-> Girokonto " << giro2.kontonummer() << ": Kontostand: " << giro2.kontostand() << endl;
    customassert(istBetrag, 900, "Tagesgeldkonto: Umbuchen fehlerhaft da Limit ueberschritten");
    customassert(tag.kontostand(), 0, "Tagesgeldkonto: Umbuchen fehlerhaft da Limit ueberschritten");
    customassert(giro2.kontostand(), 201000, "Tagesgeldkonto: Umbuchen fehlerhaft da Limit ueberschritten");

    cout << endl << "Alle Tests fehlerfrei ausgefuehrt!" << endl;

    cout << endl << "Testen der Anzeigefunktion..." << endl << endl;
    Bankkonto *konto;

    konto = &spar;
    cout << endl << "Anzeigen von Sparkonto " << spar.kontonummer() << endl << endl;
    konto->anzeigen();

    konto = &giro;
    cout << endl << "Anzeigen von Girokonto " << giro.kontonummer() << endl << endl;
    konto->anzeigen();

    konto = &tag;
    cout << endl << "Anzeigen von Tagesgeldkonto " << tag.kontonummer() << endl << endl;
    konto->anzeigen();

    return 0;
}
