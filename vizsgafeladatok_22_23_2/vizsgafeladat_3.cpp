/*

Írjon egy programot, amely 2 db felhasználói függvényt használ.

Az egyik a double infuse(double in_bk[]), amely 5 db pozitív lebegőpontos számot kér be úgy,
hogy azokat egy tömbbe tárolja le (1. paraméter). A tömb hosszát szimbolikus állandóval állítsa be.
A tárolás csak akkor jöjjön létre, ha a szám 256-nál kisebb!
Ha az adott érték nem teljesíti a rá vonatkozó feltételeket, akkor helyette új számot kell bekérni.
A bekérési folyamatnak addig kell folytatódnia, amíg a tömb teljes feltöltése meg nem történik.
Bekérési információk és hibaüzenetek kiírása nem kell!

A feltételek teljesülése esetén az infuse nevű függvény határozza meg a tömbbe letárolt értékek
harmadik gyökeinek a szorzatát.
(Azaz, az 1. szám gyökét szorozza meg a 2. szám gyökével, majd ezt a 3. szám gyökével és így tovább.)
Ezek után ezzel a számmal térjen vissza (visszatérési érték).
A különbség tizedespontosságának a meghatározását bízza a fordítóra.

A másik függvény a void outwrite(double root), pedig írja ki, hogy a infuse nevű függvény
visszatérési értékének (amit az 1. paraméterben vesz át) egész része, páros vagy páratlan.
A kiírás a példában látott tagolással és szövegezéssel történjen.

*/

#include<iostream>
#include<cmath>

#define SIZE 5
#define THRESHOLD 256.

using namespace std;

double infuse(double in_bk[]) {
    double num, result=1;
    for(int i=0; i<SIZE; i++){
        cin >> num;
        if (num > 0 && num<THRESHOLD){
            in_bk[i]=num;
            result*=cbrt(num);
        } else {
            i--;
        }
    }
    return result;
}

void outwrite(double root) {
    int int_part = floor(root);
    if (int_part%2==0){
        cout << "Páros: " << root;
    } else {
        cout << "Páratlan: " << root;
    }
}

int main(){

    double in_bk[SIZE];
    double root = infuse(in_bk);
    outwrite(root);

    return 0;
}
