#include <iostream>

using namespace std;



void printLowerTriangle(const int* const* triangle, int size){

    for (int i = 0; i < size; i++){
        cout << " ";
        for (int j = 0; j <= i; j++){
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

void freeLowerTriangle(int** triangle, int size){
    for (int i = 0; i < size; i++){
        delete[] triangle[i];
    }
    delete[] triangle;
} 



int** generateLowerTriangle(int size){
    
    int** triangle = new int*[size];
    for (int i = 0; i <size; i++){
        triangle[i] = new int[i+i];
        for(int j = 0; j <= i; j++){
            triangle[i][j] = (i+1)*10 + (j+1);
        }
    }

    return triangle;
}




int main(){
    
    cout << "1. Feladat" << endl;
    cout
    int size = 9;
    int** triangle = generateLowerTriangle(size);
    printLowerTriangle(triangle, size);
    freeLowerTriangle(triangle, size);

    return 0;
}
