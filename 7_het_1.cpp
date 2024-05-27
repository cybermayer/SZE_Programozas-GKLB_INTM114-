#include<iostream>

using namespace std;

struct coordinates {

    int x;
    int y;
    int z;
};

int main() {

    coordinates c[2];
    cout << "Toltse fel a(z) 2 elemu tombot x, y, z koordinatakkal! " << endl;
    cout << "1. koordinata: ";
    cin >> c[0].x >> c[0].y >> c[0].z;
    cout << "2. koordinata: ";
    cin >> c[1].x >> c[1].y >> c[1].z;
  
    for (unsigned int i=0; i<2; i++){
        cout << (i+1) << ". koordinata: ";
        cout << c[i].x << " " << c[i].y << " " << c[i].z << endl;

    }

    return 0;
}
