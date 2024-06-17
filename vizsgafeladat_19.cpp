/*

Definiálja azt a bool isSymmetric(int** mtx, int size) függvényt, mely a neki átadott négyzetes, 
size sorból és oszlopból álló, dinamikusan létrehozott mátrixról eldönti, 
hogy szimmetrikus-e (azaz aij = aji minden i, j = 1, ..., n indexre).

*/

#include<iostream>

using namespace std;

int** createSquaredMtx(int* list, int size){

    int** mtx = new int* [size];
    for (int i = 0; i < size; i++){
        mtx[i] = new int[i];
    }
    for(int i=0; i<size; i++){
        for(int j=0; j < size; j++){
            mtx[i][j] = list[i+j];
        }
    }
    return mtx;
}

void freeMem(int** mtx, int size){
    for(int i =0; i<size; i++){
        delete[] mtx[i];
    }
    delete[] mtx;
}

bool isSymmetric(int** mtx, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if (mtx[i][j]!=mtx[j][i]) return false; 
        }
    }
    return true;
}

int main(){

        int data[] = {
        1, 7, 3,
        7, 4, 5,
        3, 5, 2
    };

    const int size = 3;
    int** mtx = createSquaredMtx(data, size);
    std::cout << (isSymmetric(mtx, size) ? "Symmetric" : "Not symmetric") << std::endl;
    freeMem(mtx, size);

    return 0;
}
