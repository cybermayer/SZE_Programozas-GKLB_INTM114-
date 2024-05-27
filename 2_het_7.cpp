#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int a, b, op;
    do {  
    cout << "Matematikai muveletek elvegzese\n" << "1 - Osszeadas\n" << "2 - Szorzas\n" << "3 - Hatvanyozas\n" << endl;
    cout <<"Adja meg a muvelet menupontjat, vagy barmilyen mas szamot a kilepeshez! ";
    cin >> op;
    if (op == 1) {
        cout << "Elso osszeadando: ";
        cin >> a;
        cout << "Masodik osszeadando: ";
        cin >> b;
        cout << "Az osszeg: " << a+b << endl;
    } else if (op == 2) {
        cout << "Szorzando: ";
        cin >> a;
        cout << "Szorzo: ";
        cin >> b;
        cout << "A szorzat: " << a*b << endl;
    } else if (op == 3) {
        cout << "Alap: ";
        cin >> a;
        cout << "Kitevo: ";
        cin >> b;
        cout << "A hatvany: " << pow(a, b) << endl;
    }    
    }  while (op >=1 && op <= 3);

    return 0;
}
