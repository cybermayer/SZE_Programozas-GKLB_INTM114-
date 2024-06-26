/*

Definiálja azt a void charCounter(std::string str, int n) függvényt, 
ami abc-sorrendben a szabvány kimenetre nyomtatja azokat a betűket szóközzel elválasztva, 
melyek pontosan n alkalommal fordultak elő az str karakterláncban! 
A kis- és nagybetűket ne különböztesse meg egymástól! Feltételezheti, 
hogy az str karakterlánc csak az angol abc betűit tartalmazza.

*/

#include<iostream> 
#include<string>

using namespace std;

void charCounter(std::string str, int n){
    std::string abc ="";
    int occurance[26]={0};
    for(int i = static_cast<int>('a'); i <= static_cast<int>('z'); i++) 
    {
        abc.push_back(static_cast<char>(i));
    }

    for(char i : str){
        for (int j = 0; j<26; j++){
            if (abc[j]==tolower(i)){
                occurance[j]++;
            }
        }
    }
    for (int i=0; i<26; i++){
       if (occurance[i]==n) {
            cout << abc[i] << " ";
       }
    }

}

int main(){

    charCounter("OneTwoThree", 1);

    return 0;
}
