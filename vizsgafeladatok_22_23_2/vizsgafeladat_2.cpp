/*

Írjon egy programot, amely 2 db felhasználói függvényt használ.
Az egyik az int beker(int be_tb[], int *min, int *max),
amely 10 db előjeles egész számot kér be úgy, hogy azokat egy tömbbe tárolja le.
A tömb hosszát szimbolikus állandóval állítsa be.
A tárolás csak akkor jöjjön létre, ha az alábbi feltételek teljesülnek.
A tömb 0. indexén csak a nulla érték, a páratlan indexein csak páratlan értékek
és a páros indexein csak páros számok szerepelhetnek!
Ha az adott érték nem teljesíti a rá vonatkozó feltételt, akkor új számot kell bekérni.
Bekérési információk és hibaüzenetek kiírása nem kell!
A feltételek teljesülése esetén a beker függvény határozza meg és tárolja el a
legkisebb páratlan, illetve a legnagyobb páros számokat.
Ezen értékek a függvény 2. és 3. paraméterei, amíg az 1. paraméter a tároló tömb.
A függvény visszatérési értéke a 10 db szám összege legyen.
A másik függvény a void kiir(int szum, int min, int max),
pedig írja ki a beker függvény visszatérési értékét illetve a 2. és 3. paraméterek
értékeit a példában látott szövegezéssel.

*/

#include<iostream>
#include<climits>

#define SIZE 10

using namespace std;

int beker(int be_tb[], int *min, int *max){
    int sum = 0, num=-1;

    while(num!=0){
        cin >> num;
        if(num==0){
            be_tb[0]=0;
            }
        }

    for (int i = 1; i<SIZE; i++){
        cin >> num;
        if(i%2==0 && num%2==0){
            be_tb[i]=num;
        }else if(i%2!=0 && num%2!=0){
            be_tb[i]=num;
        } else {
            i--;
        }
    }

    for(int i=0; i<SIZE; i++){

        if (i%2==1 && be_tb[i]<(*min)) {(*min)=be_tb[i];}
        if (i%2==0 && be_tb[i]>(*max)) {(*max)=be_tb[i];}
        sum+=be_tb[i];
    }
    return sum;
}

void kiir(int szum, int min, int max){

    cout << "Szum: " << szum << endl;
    cout << "Prtln min: " << min << endl;
    cout << "Prs max: " << max << endl;

}

int main(){

    int be_tb[SIZE];
    int min=INT_MAX;
    int max=INT_MIN;
    int sum = beker(be_tb, &min, &max);
    kiir(sum, min, max);

    return 0;
}
