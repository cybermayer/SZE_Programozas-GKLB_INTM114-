#include<iostream>

using namespace std;

int main(){

    int a, b, c, t;
    cout << "Szamtani sorozat ellenorzes\n";
    bool arith_ser = true;

        cout << "Elso szam: ";
        cin >> a;
        cout << "Masodik szam: ";
        cin >> b;
        cout << "Harmadik szam: ";
        cin >> c;

        
        cout << "Tovabbi szamokat is megadhat. Leallas negativ ertekre.\n";
        do {
            if (b-a != c-b) {
            arith_ser = false;
            }
            cout << "Kovetkezo szam: ";
            cin >> t;
            a = b;
            b = c;
            c = t;
        }  while (t > 0);

        if (arith_ser == true){
            cout << "Szamtani sorozatot alkotnak a szamok.";
        } else {
            cout << "A szamok nem alkotnak szamtani sorozatot.";
        }

    return 0;
}
