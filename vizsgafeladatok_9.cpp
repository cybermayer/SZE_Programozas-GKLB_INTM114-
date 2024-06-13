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
