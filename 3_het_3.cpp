#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    cout << "Adjon meg egesz szamokat! Leallas negativ ertekre." << endl;
    int actual; 
    unsigned int i;
    vector<int> numbers;
    do {
        cout << "Kovetkezo szam: ";
        cin >> actual;
        if (actual>0){
            numbers.push_back(actual);            
        }
    } while (actual>0);
    sort(numbers.begin(), numbers.end());
    cout<<"Az adatok rendezes utan: ";
    for (i=0; i<numbers.size(); i++) {
        cout << numbers[i] << " ";       
        }

    return 0;
}
