/*

Írjon olyan nyomtat függvényt, melynek első paramétere egy bejegyzes struktúrát címző mutató! 
A struktúra már definiált a következőképpen:

struct bejegyzes {
	std::string nev;
	bejegyzes* kov;
	bejegyzes* tartalom;
};
A struktúra egy fájlrendszer elképzelt bejegyzésének adatait rögzíti. 
nev tagja a bejegyzés (fájl vagy mappa) neve, kov jelöli ki a következő bejegyzést az adott mappában, 
tartalom pedig mappa esetén a mappa első bejegyzésének struktúráját címzi.
A függvény feladata kinyomtatni minden mappa és almappa tartalmát úgy, 
hogy a mappák bejegyzései két szóközzel jobbra kezdődnek a tartalmazó mappa 
első betűjének oszlopához képest a kimeneten.

*/


#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct bejegyzes {
    std::string nev;
    bejegyzes* kov;
    bejegyzes* tartalom;
};

void nyomtat(const bejegyzes* head) {
    vector<const bejegyzes*> stack;
	string tab = "";
    stack.push_back(head);

    while (!stack.empty()) {
        const bejegyzes* current = stack.back();
        stack.pop_back();

        if (current != nullptr) {
            cout << tab << current->nev << endl;
            if (current->kov != nullptr || (current->kov == nullptr && current->tartalom != nullptr)) {
                stack.push_back(current->kov);
            } else if (current->kov == nullptr && !tab.empty()){
				tab.pop_back();
				tab.pop_back();
			}
        if (current->tartalom != nullptr) {
                stack.push_back(current->tartalom);
				tab.push_back(' ');
				tab.push_back(' ');
            }
			
        }
    }
}


int main() {
    bejegyzes c = { "c", nullptr, nullptr };
    bejegyzes bac = { "bac", nullptr, nullptr };
    bejegyzes bab = { "bab", &bac, nullptr };
    bejegyzes baa = { "baa", &bab, nullptr };
    bejegyzes bb = { "bb", nullptr, nullptr };
    bejegyzes ba = { "ba", &bb, &baa };
    bejegyzes b = { "b", &c, &ba };
    bejegyzes a = { "a", &b, nullptr };

    nyomtat(&a);
    return 0;
}
