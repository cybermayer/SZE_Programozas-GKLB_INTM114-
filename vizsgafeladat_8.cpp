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
