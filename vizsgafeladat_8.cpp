/*

Adott két kör a síkon, c1 és c2. c1 középpontjának koordinátái x1 és y1, sugara r1. 
c2 középpontjának koordinátái x2 és y2, sugara r2. 
Definiálja azt a bool isC1inC2(double x1, double y1, double r1, double x2, double y2, double r2) függvényt,
amely logikai igaz értékkel tér vissza, ha c1 benne van c2 belsejében, vagy érintik egymást, különben hamissal!

*/

#include<iostream>
#include<cmath>

bool isC1inC2(double x1, double y1, double r1, double x2, double y2, double r2) {
    double distance = sqrt(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
    return (r1+distance<=r2) ? true : false;
}

int main(){

    std::cout << (isC1inC2(0., 0., 1., 0., 0., 2.) ? "C1 is inside C2 or touching each other." : "C1 is not inside C2.") << std::endl;
    std::cout << (isC1inC2(0., 0., 2., 0., 0., 1.) ? "C1 is inside C2 or touching each other." : "C1 is not inside C2.") << std::endl;

    return 0;
}
