/*

Definiálja azt a void spinningLetters(std::string str) függvényt, 
ami először megjelenít egy annyi a betűből álló karakterláncot, amilyen hosszú str. 
Amennyiben a két karakterlánc nem egyforma, most olyan, az str-rel egyező 
hosszú karakterláncot nyomtasson, ahol csak azokon a helyeken szerepel a betű, 
ahol str-ben is a szerepelt, a többi helyén szerepeltessen b-t! Folytassa ezt 
így tovább c, d, e, stb. betűkkel, amíg str összes karaktere meg nem jelenik a képernyőn!
Ne különböztesse meg a kis- és nagybetűket egymástól! Feltételezheti, 
hogy az angol abc jelein kívül mást az str karakterlánc nem tartalmaz.

*/

#include<iostream>
#include<string>
#include<cctype>


using namespace std;

string abc = "abcdefghijklmnopqrstuvwxyz";

void spinningLetters(std::string str) {

    string lstr="";
    string printable = "";

    //generate printable
    for (unsigned int i = 1; i <= str.length(); i++){
        printable.push_back('1');
    }

    //generate lower string
    for (char ch : str){
        lstr.push_back(tolower(ch));
    }

do {    
    for(char ch : abc){
        for (unsigned int i = 0; i < lstr.length(); i++){
            if (lstr[i]!=printable[i]){
                printable[i]=ch;
            } else {
                printable[i] = lstr[i];
            }
        }       
        cout << printable << endl;
        if (printable.compare(lstr) == 0){
                break;
        }
    }
} while(printable.compare(lstr) != 0); 
}

int main(){
  
    spinningLetters("Jenny");
    return 0;
}
