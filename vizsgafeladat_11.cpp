/*

Laminált padlóval szeretnénk burkolni egy area területű szobát. 
A boltban kapható laminált padló jellemzőit a flooringStruct 
struktúra segítségével lehet megadni. Ennek footage tagja megadja, 
hogy egy csomag mekkora terület lefedésére alkalmas (racionális szám), 
a price tag pedig egy csomag padló ára (egész szám). 
Csomagokat a boltban nem bontanak meg, csak egész számút lehet vásárolni.
Definiálja a struktúrát, majd azt a double calcCost(flooringStruct flooring, double area) függvényt,
 ami visszaadja, hogy mennyibe kerülne leburkolni flooring típusú laminált padlóval az area nagyságú szobát!

*/

#include<iostream>
#include<cmath>

using namespace std;

struct flooringStruct {

    double footage;
    int price;
};

double calcCost(flooringStruct flooring, double area) {    
    int pieces = ceil((area)/flooring.footage);
    return pieces*flooring.price;    
};

int main(){

    std::cout << calcCost({1.727, 15417}, 2.5) << std::endl;
    return 0;

}
