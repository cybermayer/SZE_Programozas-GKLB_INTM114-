#include<iostream>
#include<vector>

using namespace std;


int main() {

    vector<int> numbers;
    int actual, even=0, count=0, last=0;
    do {        
        cout << "Adjon meg egy szamot! ";
        cin  >> actual;
        count++;
        numbers.push_back(actual);
        if (actual%2==0) {
            even++;
        }
        if (count>=2) {
            last = numbers[count-2];
        } else { 
            last = actual +1;
        }

    } while (last!=actual);   
    cout << "Osszesen " << count << " szamot adott meg, melyek kozott " << even  << " paros szam volt.";

  return 0;
}
