//#include <iostream>
//
//#include "Abbildung.h"
//#include "Buchbestandteil.h"
//#include "Kapitel.h"
//#include "Tabelle.h"
//#include "Text.h"
//#include "eidpliste.h"
//
//using namespace std;
//
//int main()
//{
//    Text text0("Es war einmal...");
//    Text text1("Lorem ipsum dolor sit amet, consectetaur adipisicing elit, sed do eiusmod tempor incididunt ut labore "
//               "et dolore magna aliqua.");
//    Abbildung angryBird;
//    Abbildung darthVader;
//    Abbildung skyNet;
//    Text text2("Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo "
//               "consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat "
//               "nulla pariatur.");
//    Abbildung sonnenaufgang;
//    Text text3("Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est "
//               "laborum Et harumd und lookum like Greek to me, dereud facilis est er expedit distinct.");
//    Tabelle nullSummenSpiel;
//    Text text4("Nam liber te conscient to factor tum poen legum odioque civiuda. Et tam neque pecun modut est neque "
//               "nonor et imper ned libidig met, consectetur adipiscing elit, sed ut labore et dolore magna aliquam "
//               "makes one wonder who would ever read this stuff?");
//    Abbildung haeschenAufWiese;
//    Text text5("Bis nostrud exercitation ullam mmodo consequet. Duis aute in voluptate velit esse cillum dolore eu "
//               "fugiat nulla pariatur. At vver eos et accusam dignissum qui blandit est praesent luptatum delenit "
//               "aigue excepteur sint occae.");
//    Tabelle gewinnUndVerlustrechnung;
//    Text text6("Ende.");
//
//    Liste<Buchbestandteil *> liste1;
//    liste1.append(&text0);
//    liste1.append(&text1);
//    liste1.append(&angryBird);
//    liste1.append(&darthVader);
//    liste1.append(&skyNet);
//    Kapitel exposition(liste1);
//    Liste<Buchbestandteil *> liste2;
//    liste2.append(&text2);
//    liste2.append(&sonnenaufgang);
//    Kapitel komplikation(liste2);
//    Liste<Buchbestandteil *> liste3;
//    liste3.append(&text3);
//    liste3.append(&nullSummenSpiel);
//    Kapitel peripetie(liste3);
//    Liste<Buchbestandteil *> liste4;
//    liste4.append(&text4);
//    liste4.append(&haeschenAufWiese);
//    Kapitel retardation(liste4);
//    Liste<Buchbestandteil *> liste5;
//    liste5.append(&text5);
//    liste5.append(&gewinnUndVerlustrechnung);
//    liste5.append(&text6);
//    Kapitel katastrophe(liste5);
//
//    Liste<Buchbestandteil *> gesamt;
//    gesamt.append(&exposition);
//    gesamt.append(&komplikation);
//    gesamt.append(&peripetie);
//    gesamt.append(&retardation);
//    gesamt.append(&katastrophe);
//    Kapitel sunspring(gesamt);
//
//    cout << "Das Machwerk enthält:" << endl;
//    cout << "- " << sunspring.getAnzahlAbbildungen() << " Abbildungen" << endl;
//    cout << "- " << sunspring.getAnzahlTabellen() << " Tabellen" << endl;
//    cout << "- " << sunspring.getAnzahlFloats() << " Floats" << endl;
//    cout << "- " << sunspring.getAnzahlZeichen() << " Zeichen" << endl;
//
//    return 0;
//}
