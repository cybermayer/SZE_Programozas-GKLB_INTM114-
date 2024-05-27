#include<iostream>
#include<vector>

using namespace std;

int main() {

    unsigned int i; 
    int actual;
    vector<int> numbers;
    cout << "Adjon meg egesz szamokat! Leallas negativ ertekre." << endl;
    cin >> actual;
    while ((numbers.size() < 10) && actual > 0) {
            numbers.push_back(actual);
            cout << "Kovetkezo szam: ";
            cin >> actual;
    }
    if ((numbers.size()<10)){
        cout << "Kovetkezo szam: ";
    }
    if (numbers.size()>0){
        cout << "A beolvasott adatok: ";
        for (i=0; i<(numbers.size()); i++){

        cout << numbers[i] << " ";
        }
    }

    return 0;
}
