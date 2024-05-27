#include <iostream>

#define ZH_SZAM 2

using namespace std;

// struktura deklaracio
struct hallgato {
    string nev;
    string neptun;
    string targy;
    int pontok[ZH_SZAM];
};

// Ide kerulnek az On altal irt fuggvenyek

hallgato beolvas() {

    hallgato adatlap;
    cout << "Hallgato neve: ";
    cin >> adatlap.nev;
    cout << "Hallgato Neptun kodja: ";
    cin >> adatlap.neptun;
    cout << "Tantargy neve: ";
    cin >> adatlap.targy;
    cout << "A ZH-k pontszamai rendre: ";
    cin >> adatlap.pontok[0] >> adatlap.pontok[1];

    return adatlap;
}

float atlag(hallgato adatlap){
  
    float atlag;
    float szam1 = adatlap.pontok[0];
    float szam2 = adatlap.pontok[1];
    atlag = (szam1+szam2)/ZH_SZAM;

    return atlag;
}


int main() {
    cout << "Hallgatoi adatok beolvasasa es ZH atlag kiszamolasa" << endl;
    hallgato hg = beolvas();
    cout << "A hallgato atlaga az adott targybol: " << atlag(hg) << endl;
    return 0;
}
