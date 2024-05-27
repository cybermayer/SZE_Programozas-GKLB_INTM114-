#include <iostream>

using namespace std;

bool prime(int n) {

    if (n<=1) {
        return false;
    } else {
        for (int i=2; i*i <= n; i++) {          
            if  (n%i==0){
                return false;
            }
        }
    }
    
    return true;
}

int main(){

  cout << (prime(11) ? "Primszam" : "Nem prim") << endl;
  cout << (prime(4) ? "Primszam" : "Nem prim") << endl;
  cout << (prime(607) ? "Primszam" : "Nem prim") << endl;
  cout << (prime(829) ? "Primszam" : "Nem prim") << endl;
  cout << (prime(1111) ? "Primszam" : "Nem prim") << endl;

  return 0;
}
