/*

Készítse el azt a void fillRect(int width, int height, std::string text) függvényt, 
ami kirajzol egy width szélességű és height magasságú téglalapot a text betűiből úgy, 
hogy balról jobbra és fentről lefelé haladva is ugyanaz a szöveg ismétlődjön folyamatosan a mintának megfelelően!

*/

#include<iostream>
#include<cmath>

using namespace std;

void fillRect(int width, int height, std::string text){

    for(int i=0; i<height; i++){
        unsigned int start = i;
        if (start>=text.length()) start -=(floor(i/text.length())*(text.length()));
        for(int j=0; j<width; j++){
            cout << text[start];
            start++;
            if (start==text.length()) start=0;
        }
        cout << endl;
    }
}


int main(){

    fillRect(9, 7, "C++Programming");

    return 0;
}
