/*

Definiáljon a double terulet(double a, double b, double delta) függvényt, 
ami visszaadja az a és b oldalhosszú paralelogrammak a területét, 
amennyiben a két oldal delta szöget zár be egymással! A szög fokokban adott.  π értékét vegye 3.14-nek!
Definiálja a double kerulet(double a, double b) függvényt is!

*/

#include<iostream>
#include<cmath>

#define PI 3.14

using namespace std;

double terulet(double a, double b, double delta) {
    double rad = delta*(PI/180);
    return a*b*sin(rad);
}

double kerulet(double a, double b) {
    return (2*a+2*b);
}

int main(){
	double a = 3.;
	double b = 3.;
	double delta = 90.;
	std::cout << "Kerulet: " << kerulet(a, b) << ", terulet: " << terulet(a, b, delta) << std::endl;
  
    return 0;
}

