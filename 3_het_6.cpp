#include<iostream>
#include<vector>

using namespace std;

int main(){

    unsigned int i;
    vector<int> numbers;
    int actual; 
    for (i=1; i<=5; i++){
        cout << i << ". szam: ";
        cin >> actual;
        numbers.push_back(actual);
    }
    actual = numbers[0];
    numbers.erase(numbers.begin());
    numbers.push_back(actual);
    cout << "Forgatas utan: ";
    for (i=0; i<numbers.size(); i++) {
        cout << numbers[i] << " "; 
    }

    return 0;
}
