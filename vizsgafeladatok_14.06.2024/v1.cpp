/*

1. Definiálja azt a void lower(int** m, int n) függvényt, 
ami az nxn-es négyzetes mátrixból alsó háromszögmátrixot készít, 
azaz a főátló feletti elemeit lenullázza!

*/

#pragma region<inclcude>                                                                            //INCLUDING

    #include<iostream>

    using namespace std;

#pragma endregion<include>

void lower(int** m, int n){                                                                         //PRINT LOWER TRIANGLE

    for(int i=0; i<n; i++){                                                                         
        for(int j=0; j<n; j++){
            if (j>i){m[i][j] = 0;}
            cout << m[i][j];
        } cout << endl;
    }
}

int main(){                                                                                         //MAIN

    const int SIZE = 5;

    int matrix[SIZE][SIZE] = {
        {7, 2, 9, 4, 1},
        {3, 5, 0, 8, 6},
        {2, 7, 4, 9, 3},
        {5, 9, 1, 2, 7},
        {6, 3, 8, 0, 9}
    };

    int* ptrMatrix[SIZE];

    for (int i=0; i<SIZE; i++){
        ptrMatrix[i] = matrix[i];
    }

    lower(ptrMatrix, SIZE);

    return 0;
}
