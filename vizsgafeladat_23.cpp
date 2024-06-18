/*

Definiálja azt a void nyomtat(std::string str) függvényt, ami olyan karakterláncot kap paraméterként, mely a következő részekből áll:
kezdődik egy nemnegatív egész számmal,
amit egy x betű választ el
egy tetszőleges hosszúságú és tartalmú rész-karakterlánctól.
A függvény feladata a szabvány kimenetre nyomtatni az 1. részben adott számú alkalommal a 3. rész-karakterláncot egymás után.

*/

#include<iostream>

using namespace std;

void nyomtat(std::string str){
    string snum, word;
    int num, x = 0;   
    while (str[x]!='x'){
        snum.push_back(str[x]);
        x++;
    }
    num = stoi(snum);
    word = str.substr(x+1);
    for (int i = 0; i < num; i++){
        cout << word;
    }
}


int main(){

    nyomtat("3xJani");
    return 0;
}
