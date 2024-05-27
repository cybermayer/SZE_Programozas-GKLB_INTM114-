#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main() {

    unsigned int i;
    int actual;
    vector<int> numbers;
    for (i=1; i<=5; i++) {
        cout << i << ". szam: ";
        cin >> actual;
        numbers.push_back(actual);
    }  
    cout << "Mennyivel forgassunk balra? ";
    cin >> actual;
    if (actual < 0) {
        actual = 5 - (abs(actual)%5);
    }
    
    rotate(numbers.begin(), numbers.begin() + (actual%5), numbers.end());
    cout << "Forgatas utan: ";
    for (i=0; i<numbers.size(); i++) {
        cout << numbers[i] << " ";
    }

    return 0;
}
