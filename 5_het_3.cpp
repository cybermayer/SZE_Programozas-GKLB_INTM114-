#include <iostream>

using namespace std;

double szamtaniOsszeg(double a1, double d, int n) {

    double result;
    result = (((2 * a1) + (n-1)*d)*n)/2;

    return result;    
}

int main(){

  cout << szamtaniOsszeg(1., 1., 3) << endl;
  cout << szamtaniOsszeg(2.5, 3.1, 10) << endl;
  cout << szamtaniOsszeg(1., 2., 100) << endl;

  return 0;
}
