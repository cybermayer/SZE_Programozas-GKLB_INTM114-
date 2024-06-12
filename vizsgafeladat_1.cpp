#include <iostream>
#include <string>

struct elem {
    std::string szo;
    elem* kov;
};

void kiir(elem* horgony) {
    elem* aktualis = horgony;
    while (aktualis != nullptr) {
        std::cout << aktualis->szo << " ";
        aktualis = aktualis->kov;
    }
    std::cout << std::endl;
}

int szamol(elem* horgony) {
    int osszesen = 0;
    elem* aktualis = horgony;
    while (aktualis != nullptr) {
        osszesen++;
        aktualis = aktualis->kov;
    }
    return osszesen;
}

elem* rendez(elem* horgony) {
    int osszesen = szamol(horgony);
    for (int i = 0; i < osszesen - 1; i++) {
        elem* aktualis = horgony;
        for (int j = 0; j < osszesen - i - 1; j++) {
            elem* kovetkezo = aktualis->kov;
            if (aktualis->szo > kovetkezo->szo) {
                std::string temp = aktualis->szo;
                aktualis->szo = kovetkezo->szo;
                kovetkezo->szo = temp;
            }
            aktualis = kovetkezo;
        }
    }
    return horgony;
}

elem* beszur(elem* horgony, std::string szo) {
    elem* uj_elem = new elem;
    uj_elem->szo = szo;
    uj_elem->kov = nullptr;

    if (horgony == nullptr) {
        return uj_elem;
    } else {
        elem* aktualis = horgony;
        while (aktualis->kov != nullptr) {
            aktualis = aktualis->kov;
        }
        aktualis->kov = uj_elem;
    }

    return rendez(horgony);
}

void felszabadit(elem* horgony) {
    while (horgony != nullptr) {
        elem* kov = horgony->kov;
        delete horgony;
        horgony = kov;
    }
}

int main() {
    
    elem* horgony = nullptr;
    horgony = beszur(horgony, "banan");
    horgony = beszur(horgony, "dio");
    horgony = beszur(horgony, "alma");
    horgony = beszur(horgony, "cekla");
    kiir(horgony);

    felszabadit(horgony); 

    return 0;
}
