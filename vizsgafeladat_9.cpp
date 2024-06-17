/*

Adott egy szövegfájl, mely soronként tartalmazza egy hallgató keresztnevét, 
majd a vizsgákon elért eredményeit, szóközökkel elválasztva. Például az exam1.txt tartalma a következő:

Mary 1 4
Joe 5
John 1 1 2
Jenny 3

Definiálja a void examCount(const std::string& fileName) függvényt, 
ami külön sorokban kiírja a hallgatók nevét és vizsgáik számát!

*/

#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

void examCount(const std::string& fileName){

    ifstream file(fileName);
    string line;
    while (getline(file, line)){
        istringstream iss(line);
        string word;
        int exam = -1;
        while (iss >> word){
            (exam<0) && cout << word;
            exam++;
        } 
        cout << " " << exam << endl;
    }
}

int main(){

    examCount("./exam1.txt");

    return 0;
}
