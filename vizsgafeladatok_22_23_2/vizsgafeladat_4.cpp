/*

Írjon egy programot, amely 2 db felhasználói függvényt használ.
Az egyik az int feltolt(char s_tb[]),
amely feltölt egy karakter tömböt (1. paraméter) ékezet nélküli szöveggel
az ENTER billentyű leütéséig, vagy maximum 50 db karakterig.
Bekérési információk és hibaüzenetek kiírása nem kell!
A tömb hosszát szimbolikus állandóval állítsa be.
A függvény visszatérési értéke a feltöltött tömb hossza legyen.
A másik függvény a void torol(char s_tb[], int h),
pedig a feltöltött tömb (1. paraméter) minden második elemét törölje,
majd az így módosított tömb tartalmát írja is ki.
A torol függvény 2. paramétere a feltolt függvény visszatérési értéke.


*/

#include<iostream> 
#include<cstring>
#include<cmath>

#define MAX_SIZE 50

using namespace std;

int feltolt(char*& s_tb){

    unsigned int i = 0;
    string str;
    getline(cin, str);
    unsigned int size = (str.length()<=50) ? str.length() : MAX_SIZE;
    delete[] s_tb;
    s_tb = new char[size];

    while ( i<size && i!=50 ){

        s_tb[i] = str[i];
        i++;
    }
    return size;
}

void torol(char*& s_tb, int h)
{
    int new_size = (h+1)/2;
    char* half_array = new char[new_size+1];
    int new_iterator =0;
    for(int i=0; i<h; i+=2){
        half_array[new_iterator] = s_tb[i];
        new_iterator++;
    }
    delete[] s_tb;
    s_tb = half_array;
    for (int i=0; i<new_size; i++){
        cout << s_tb[i];
    }
}

int main(){

    char* s_tb=new char[MAX_SIZE];
    int h = feltolt(s_tb);
    torol(s_tb,h);
    delete[] s_tb;

    return 0;
}
