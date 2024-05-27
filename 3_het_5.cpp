#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    unsigned int i;
    int actual, count=1;
    vector<int> numbers;
  
    for(i=1; i <= 10; i++) {
        cout << i << ". szam: ";
        cin >> actual;
        numbers.push_back(actual);      
    }
    while (count > 0) {
        cout << "Minek az elofordulasat szeretne szamolni?";
        cin >> actual;
        count = 0;
        for (i=0; i<numbers.size(); i++){
            if (numbers[i]==actual) {
                count++;
            }
        }        
        cout << " A " << actual << " ertek elofordulasainak szama: " << count << "\n";
    }

    return 0;
}
