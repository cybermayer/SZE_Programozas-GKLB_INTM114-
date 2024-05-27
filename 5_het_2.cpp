#include <iostream>

using namespace std;

float whichIsLarger(float num1, float num2) {

    float result;
    if (num1 >= num2) {
        result = num1;
    } else {
        result = num2;
    }

    return result;

}


int main() {

    float a,b;
    cout << "Adjon meg ket szamot!";
    cin >> a >> b;
    cout << " A nagyobb ertek: " << whichIsLarger(a, b) << endl;


    return 0;
}
