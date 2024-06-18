/*

Olvassa be szabályos tetraéderek élhosszait mindaddig, amíg pozitív élhosszakat ad meg a felhasználó! 
Minden beolvasást tájékoztató szövegnek kell megelőznie. Jelenítse meg a test térfogatát! 
A szabályos tetraéder térfogata: Szabályos tetraéder térfogatának egyenlete, ahol a az oldal hossza.

*/

#include<iostream>
#include<cmath>

using namespace std;

int main(){

double a=0;
double V;

while(true){

    cout << "Edge length: ";
    cin >> a;
    if (a<=0) break;
    cout << endl;
    V = (pow(a, 3)*sqrt(2))/12;
    cout << "Volume: " << V << endl;

}
    return 0;
}
