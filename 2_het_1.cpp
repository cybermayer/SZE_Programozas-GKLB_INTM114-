#include<iostream>

using namespace std;

int main() {

    cout << "Adjon meg ket szamot! ";
    int a, b;
    cin >> a >> b;
    if (a==b) {
        cout << a << " es " << b << " egyenlo.";
    } else if (a > b) {
        cout << a << " nagyobb, mint " << b;
    } else {
        cout << a << " kisebb, mint " << b;        
    }

    return 0;
}
