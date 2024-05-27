#include <iostream>

using namespace std;

#define SIZE 2

struct coordinate{

    int x;
    int y;
};

struct triangle{

    coordinate a;
    coordinate b;
    coordinate c;
};

void createTriangle(triangle* ptrTriangle){

    cout << "X: ";
    cin >> ptrTriangle -> a.x ;
    cout << "Y: ";
    cin >> ptrTriangle -> a.y;
    
    cout << "X: ";
    cin >> ptrTriangle -> b.x; 
    cout << "Y: ";
    cin >> ptrTriangle -> b.y;

    cout << "X: ";
    cin >> ptrTriangle -> c.x;
    cout << "Y: ";
    cin >> ptrTriangle -> c.y;
}

void printTriangle(triangle* ptrTriangle){

    cout << "X: " << ptrTriangle -> a.x << " Y: " << ptrTriangle -> a.y << endl;
    cout << "X: " << ptrTriangle -> b.x << " Y: " << ptrTriangle -> b.y << endl;
    cout << "X: " << ptrTriangle -> c.x << " Y: " << ptrTriangle -> c.y << endl;
}


int main(){

    triangle datas[SIZE];
    cout << "Haromszogek kezelese" << endl;
  
    for (unsigned int i = 1; i<=SIZE; i++){
        cout << i << ". haromszog adatai:" << endl;
        createTriangle(&datas[i-1]);
    }

    cout << "A beolvasott haromszogek adatai: " << endl;

    for (unsigned int i = 1; i<=SIZE; i++){
        cout << i << ". haromszog csucsainak koordinatai: " << endl;
        printTriangle(&datas[i-1]);
    }

    return 0;
}
