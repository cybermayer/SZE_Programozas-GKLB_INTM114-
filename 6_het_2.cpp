#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;

const unsigned int ROWS = 5;
const unsigned int COLS = 2;


float roundToPrecision(float value, int precision) {
    float factor = pow(10, precision);
    return round(value * factor) / factor;
}

void sorting(string datas[ROWS][COLS]){

    bool swapped;
    for (unsigned int i=0; i<ROWS-1; i++) {
        swapped = false;
        for (unsigned int j=0; j<ROWS-i-1; j++) {
            float num1, num2;
            num1 = stof(datas[j][1]);
            num2 = stof(datas[j+1][1]);
            if (num1 > num2){
            swap(datas[j][0], datas[j+1][0]);
            swap(datas[j][1], datas[j+1][1]);
            swapped = true;
            }
        }
        if (!swapped){break;}
    }
}




int main(){

    string datas[5][2];
    cout << "Tavolsagok csokkeno sorrendbe rendezese" << endl << endl;
    for (unsigned int i=0; i<ROWS; i++){
        cout << i+1 << ". szemely neve: ";
        cin >> datas[i][0];
        cout << "Tavolsag: ";
        cin >> datas[i][1];
    }
        sorting(datas);
        cout << "Tavolsag szerint csokkenoen rendezett adatok: " << endl;
        for (unsigned int j=ROWS-1; j >=0; j--){
            string spacing;
            float distance, rDistance;
            distance =stof(datas[j][1]);
            rDistance = roundToPrecision(distance, 3);
            if (j==(ROWS-1)){
                spacing = "   ";
            } else if (j<ROWS-1 && j!=0) {
                spacing = "    ";
            } else {             
                spacing = "     ";
            }
            cout << datas[j][0] << endl;
            cout << spacing << fixed << setprecision(3) << rDistance << endl;        
            if (j==0){break;}    
    }
        return 0;
}
