/*

Definiálja azt a double* interpolation(double start, double end, int steps) függvényt, 
mely meghatározza a start és end közötti steps-2 értéket úgy, mintha azok egy számtani 
sorozat tagjai lennének. A visszatérési érték egy dinamikus tömb, amely tartalmazza
a start értékét, a kiszámított tagokat, majd végül az end értékét is.

*/


#include<iostream>

using namespace std;

void print(double* list, int count){
    for (int i=0; i<count; i++){
        cout << list[i] << " ";
    }
}

double* interpolation (double start, double end, int steps){
    double* values = new double[steps];    
    double step = (end-start) / (steps - 1);
    for (int i = 0; i < steps; i++){
        values[i] = start + i*step;
    }
    return values; 
}

int main(){
    {
	double* values = interpolation(0, 1, 3);
	print(values, 3);
	delete[] values;
    }
    return 0;
}
