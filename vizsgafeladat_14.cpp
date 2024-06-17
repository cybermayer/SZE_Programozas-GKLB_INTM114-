/*

Írjon olyan programot, amely beolvassa a billentyűzetről háromszögek A, B és C oldalának hosszúságát, 
majd eldönti, hogy a háromszög megszerkeszthető-e! Ha igen, akkor az oldalhosszakat kimenti 
a triangles.txt nevű fájlba. Minden oldal hossza kerüljön külön oszlopba, melyeket szóköz választ el egymástól. 
Minden háromszög adata külön sorba kerüljön! Az adatbeolvasást addig kell folytatni, 
amíg a felhasználó az A oldal hosszaként pozitív értékeket ad meg.

*/

#include<iostream>
#include<cstdlib>
#include<fstream>

using namespace std;

int main(){

    int a, b, c;
    while(true){
        cout << "A: ";
        cin >> a;
        if (a<0)
            break;
        cout << "B: ";
        cin >> b;
        if (b<0)
            break;
        cout << "C: ";
        cin >> c;
        if (c<0)
            break;

        ofstream outFile;
        outFile.open("triangles.txt", ios::app);
        if (a+b>c && a+c>b && b+c>a) {  
        if(!outFile) {
            cerr << "Error: This shit cannot be opened.";
            return 1;
        }
        outFile << a << " " << b << " " << c << " " << endl;;
        }
        outFile.close();
    
}
    try {
        system("echo; cat triangles.txt");
    } catch (const std::exception& e) {
        // Print nothing on error
    }

    return 0;
}
