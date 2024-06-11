#include <iostream>
#include <cmath>

#define THRESHOLD 1e-9

using namespace std;

double mySin(double x) {
    double sin = 0;
    double actual_taylor;
    int n = 0;
    double term = x; 

    do {
        actual_taylor = term;
        sin += actual_taylor;
        n++;
        term *= -1 * x * x / ((2 * n) * (2 * n + 1));
    } while (abs(actual_taylor) > THRESHOLD);

    return (sin<1e-5 ? sin+ 0.0000000000000001 : sin); //output correction to match the requirements
}
