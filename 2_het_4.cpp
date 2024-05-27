#include<iostream>

using namespace std;

int main(){

    int n, row, column;
    cout << "Mekkora negyzetet szeretne? ";
    cin >> n;
    for(row=1; row<=n; row++) {      
        for(column=1; column<=n; column++) {
            if (row==1 || row==n) {
                cout << "*";                          
            } else if (column==1 || column == n) {
                cout << "*";            
            } else {
                if (column==row || (column+row)==(n+1) ) {
                    cout << "*";
                } else {
                    cout << " ";
                }            
            }
            if (column==n) {
                    cout << "\n";
                }
        }
    }

    return 0;
}
