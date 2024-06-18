/*

Definiálja azt a void rotateLines(const std::string& fileName) függvényt, 
ami a fileName nevű fájlban található szövegsorokat egymás után kiolvassa, 
majd megjeleníti őket eredeti alakjukban, illetve 1, 2, ..., n-1 karakterrel balra forgatva is, 
ahol n a karakterlánc hossza.
  
Tájékoztatásul, a words1.txt fájlt tartalma a következő:

abcdef
qwertzuiop

*/

#include<iostream>
#include<fstream>

using namespace std;

void rotateLines(const std::string& fileName){

    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "Failed to open file." << endl;
        return;
    }

    string line;

    while(getline(file, line)){
        for(unsigned int i=0; i<line.length(); i++){
            unsigned int step = i;
            for (unsigned int j=0; j<line.length(); j++){   
                cout << line[step];
                step++;
                if (step==(line.length())) step=0;
            }
            cout << endl;
        } 
    }
    file.close();
}

int main(){

    rotateLines("./words1.txt");

    return 0;
}
