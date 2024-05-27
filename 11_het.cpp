#include <iostream>

using namespace std;

struct elem {

    int szam;
    elem* kov;

};

int szamol(elem* horgony){

    int osszesen=0;
    elem* aktualis = horgony;
    while (aktualis != nullptr){
        osszesen++;
        aktualis = aktualis->kov;
    }
    return osszesen;
}

elem* rendez(elem* horgony){

    int osszesen = szamol(horgony);
    for (int i = 0; i < osszesen-1; i++){
        elem* aktualis = horgony;
        for(int j = 0; j < osszesen-i-1; j++){
            elem* kovetkezo = aktualis->kov;
            if (aktualis->szam > kovetkezo->szam)
            {
                int temp = aktualis->szam;
                aktualis->szam = kovetkezo->szam;
                kovetkezo->szam = temp;
            }
            aktualis = kovetkezo;
        }

    }

    return horgony;
}

elem* fordit(elem* horgony){
    
    elem* aktualis = horgony;
    elem* kovetkezo = aktualis->kov;
    aktualis->kov=nullptr;
    
    while (kovetkezo!=nullptr)
    {
        horgony = kovetkezo->kov;
        kovetkezo->kov = aktualis;
        aktualis = kovetkezo;
        kovetkezo = horgony;
    }
        
    return aktualis;
}

elem* beszurElore(elem* horgony, int szam){

    elem* regi_elso_elem = horgony;
    elem* uj = new elem;
    uj->szam = szam;
    uj->kov = regi_elso_elem;
    horgony = uj;

    return horgony;
}

elem* beszurHatra(elem* horgony, int szam){

    if (horgony == nullptr) {
        elem* uj = new elem;
        uj->szam = szam;
        uj->kov = nullptr;
        return uj;
    }

    elem* aktualis = horgony;
    while(aktualis->kov!=nullptr){
        aktualis = aktualis->kov;
    }
    elem* uj = new elem;
    uj->szam=szam;
    uj->kov=nullptr;
    aktualis->kov = uj;

    return horgony;
}

void kiir(elem* horgony){

    elem* aktualis = horgony;
    while (aktualis != nullptr){
        cout << aktualis->szam << " ";
        aktualis = aktualis->kov;
    }
    cout << endl;
}

void felszabadit(elem* horgony){
    while (horgony != nullptr){
        elem* aktualis = horgony;
        horgony = horgony->kov;
        delete aktualis;
    }
}


elem* letrehoz(int szamok[]){
  
    elem* horgony = nullptr;
    for (int i=0; szamok[i] != -1; i++){
        elem* uj = new elem;
        uj->szam = szamok[i];
        uj->kov = horgony;
        horgony = uj;
    }
    return horgony;
}


int main(){

    //1. feladat
    cout << "1. Feladat" << endl;
    cout << "------------------------------------------" << endl;
    int sz[] = {1, 2, 3, 4, 5, -1};
    elem* horgony = letrehoz(sz);
    kiir(horgony);
    felszabadit(horgony);
    cout << "------------------------------------------" << endl;

    //2. feladat
    cout << "2. Feladat" << endl;
    cout << "------------------------------------------" << endl;
    int sz[] = {1, 2, 3, 4, 5, -1};
    elem* horgony = letrehoz(sz);
    cout << "Eredeti lista tartalma:\n";
    kiir(horgony);
    horgony = beszurElore(horgony, 42);
    cout << "A lista elejere torteno beszuras utan:\n";
    kiir(horgony);
    horgony = beszurHatra(horgony, 666);
    cout << "A lista vegere torteno beszuras utan:\n";
    kiir(horgony);
    felszabadit(horgony);
    cout << "------------------------------------------" << endl;

    //3.. feladat
    cout << "3. Feladat" << endl;
    cout << "------------------------------------------" << endl;
    int sz[] = {1, 2, 3, 4, 5, -1};
    elem* horgony = letrehoz(sz);
    kiir(horgony);
    horgony = fordit(horgony);
    kiir(horgony);
    felszabadit(horgony);
    cout << "------------------------------------------" << endl;

    //3.. feladat
    cout << "3. Feladat" << endl;
    cout << "------------------------------------------" << endl;
    int sz[] = {29, -3, 5, 998, 2, -56, 146, -1};
    elem* horgony = letrehoz(sz);
    kiir(horgony);
    horgony = rendez(horgony);
    kiir(horgony);
    felszabadit(horgony);
    int sz[] = {55, 1, 65, 46544, -232, 34, 3, -1};
    elem* horgony = letrehoz(sz);
    kiir(horgony);
    horgony = rendez(horgony);
    kiir(horgony);
    felszabadit(horgony);    
    cout << "------------------------------------------" << endl;

    

    
    return 0;
}
