#include<iostream>

using namespace std;

int main(){

    int height, i, j;
    cout << "Lepcso magassaga? ";
    cin >> height;
    for(i=1; i<=height; i++) {
        for (j=1; j<=height; j++) {        
            if (j <= i) {            
                cout << "*" ;
            } else {
                cout << " ";
            }
            if (j==height){
                cout << "\n";
            }
        }   
    }

    return 0;   
}
