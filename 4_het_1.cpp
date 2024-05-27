#include <iostream>
#include <cmath>

#define WIDTH 78
#define HEIGHT 24

using namespace std;

int main() {
    for(int s=HEIGHT/2; s>=-HEIGHT/2; s--) {
        for(int o=0; o<=WIDTH; o++) {
            cout<<(s == round(sin(2.*M_PI*(double(o) / WIDTH)) * (HEIGHT/2.)) ? '*' : ' ');
        }
        cout << endl;
}
  return 0;
}
