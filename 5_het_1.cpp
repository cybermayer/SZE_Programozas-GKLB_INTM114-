#include <iostream>

using namespace std;

float add(float numb1, float numb2){

    float result;
    result = numb1 + numb2;

    return result;
}



int main() {

    float a, b;
    cout << "Adjon meg ket szamot!";
    cin >> a >> b;
    cout << " Az osszeguk: " << add(a, b) << endl;

    return 0;
}
