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

void printUpperTriangle(const int* const* triangle, int size){

    for (int i = 0; i < size; i++){
        cout<< " " << string(i*3, ' ');
        for (int j=0; j <= size-i-1; j++){
            cout << triangle[i][j] << " ";

        }
        cout << endl;
    }

}

void freeUpperTriangle(int** triangle, int size){

    for (int i=0; i < size; i++){
        delete[] triangle[i];
    }
    delete[] triangle;


}


int** generateUpperTriangle(int size){

    int** triangle = new int*[size];
    for (int i = 0; i < size; i++){
        triangle[i] = new int[size-i];
        for (int j=0; j <= size-1-i; j++){
            triangle[i][j] = (i+1)*10 + (j+i+1);
        }
    }
    return triangle;
}


void printPascal(const int* const* pascal, int size){

    for(int i=0; i<size; i++){        
        for(int j=0; j<=i; j++){
            cout << pascal[i][j] << '\t';
        }
        cout << endl;
    }


}

void freePascal(const int* const* pascal, int size){

    for (int i =0; i < size; i++){
        delete[] pascal[i];
    }
    delete[] pascal;


}

int** generatePascal(int size){

    int** pascal = new int*[size];
    for(int i = 0; i<size; i++){
        pascal[i] = new int[i+1];
        for(int j=0; j<=i; j++){
            if (j == 0 || j == i){
                pascal[i][j]=1;

            } else {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }

        }
    }
    return pascal;
}

void printTR(const char* const* tr){

    cout << " " << "|" << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
    cout << "-+--------------------------" << endl;

    for(int i=0; i<26; i++){
        cout<< static_cast<char>(65+i) << "|";
        for(int j=0; j<26; j++){            
            cout << tr[i][j];
        }
        cout << endl;
    }
}

void freeTR(char** tr){

    for(int i=0; i<26; i++){
        delete[] tr[i];
    }
    delete[] tr;

}

char** createTR() {

    char** tabularecta = new char*[26];
    for(int i=0; i<26; i++){
        tabularecta[i] = new char[26];
        int ascii_of_letter = static_cast<int>('A')+i;
        for(int j=0; j<26; j++){
            if (ascii_of_letter > 90){
            ascii_of_letter -= 26;      
            }
            tabularecta[i][j]=static_cast<char>(ascii_of_letter);
            ascii_of_letter++;
        }
    }

    return tabularecta;
}

int main(){
    
    //1. feladat
    cout << "1. Feladat" << endl;
    cout << "------------------------------------------" << endl;
    int size = 9;
    int** triangle = generateLowerTriangle(size);
    printLowerTriangle(triangle, size);
    freeLowerTriangle(triangle, size);
    cout << "------------------------------------------" << endl;
    int size = 3;
    int** triangle = generateLowerTriangle(size);
    printLowerTriangle(triangle, size);
    freeLowerTriangle(triangle, size);
    cout << "------------------------------------------" << endl;

    //2. feladat
    cout << "2. Feladat" << endl;
    cout << "------------------------------------------" << endl;
    int size = 9;
    int** triangle = generateUpperTriangle(size);
    printUpperTriangle(triangle, size);
    freeUpperTriangle(triangle, size);
    cout << "------------------------------------------" << endl;
    int size = 3;
    int** triangle = generateUpperTriangle(size);
    printUpperTriangle(triangle, size);
    freeUpperTriangle(triangle, size);
    cout << "------------------------------------------" << endl;

    //3. feladat
    cout << "3. Feladat" << endl;
    cout << "------------------------------------------" << endl;
    int size=0;
    cout << "Pascal-haromszog szamito program. Adja meg a sorok szamat! ";
    cin >> size;
    int** pascal = generatePascal(size);
    printPascal(pascal, size);
    freePascal(pascal, size);
    cout << "------------------------------------------" << endl;

    //4. feladat
    cout << "4. Feladat" << endl;
    cout << "------------------------------------------" << endl;
    int size=0;
    cout << "Pascal-haromszog szamito program. Adja meg a sorok szamat! ";
    cin >> size;
    int** pascal = generatePascal(size);
    printPascal(pascal, size);
    freePascal(pascal, size);
    cout << "------------------------------------------" << endl;

    

    return 0;
}
