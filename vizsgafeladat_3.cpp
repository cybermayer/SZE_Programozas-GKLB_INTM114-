#include<iostream>

using namespace std;

double* atlagok(const double* tomb, int n){

    if(tomb !=nullptr && n>1) {
        double* uj_tomb = new double[n-1];
        for(int i = 0; i<n; i++){
            uj_tomb[i] = (tomb[i]+tomb[i+1])/2;        
        }
        return uj_tomb;
    }
    return nullptr;
}

void print(const double* tomb, int n){

    if (n<=1)
    {
        cout << "OK";
    }
    for(int i =0; i<=n; i++)
    {
        cout << tomb[i] << " ";
    }

}

int main(){

    double t[] = { 1, 2, 4, 8, 16 }; 
	double* a = atlagok(t, 5);
	print(a, 4);
	delete[] a;
    
    return 0;
}
