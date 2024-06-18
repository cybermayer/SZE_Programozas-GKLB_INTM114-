/*

Definiálja azt a double** average(double** mtx, int height, int width) függvényt, 
amely paraméterként egy height sorból és width oszlopból álló mtx dinamikus mátrixot kap. 
Visszatérési értéke legyen egy olyan dinamikus mátrix, mely a paraméter mátrix összes 3x3-as 
méretű blokkjának számtani közepét tartalmazza ugyanolyan elrendezésben, 
ahogyan a blokkok az eredeti mátrixban is elhelyezkedtek!

*/

#include<iostream>

using namespace std;

double** createMtx(double* start, int height, int width){

    double** mtx=new double*[height];
    for (int i=0; i<height; i++){
            mtx[i]=new double[width];
        for (int j=0; j<width; j++){
            mtx[i][j] = *(start+i*width+j);
        }
    }
    return mtx;
}

void print(double** mtx, int height, int width){

    for (int i = 0; i<height; i++){
        for (int j = 0; j<width; j++){
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
}

void freemem(double** mtx, int rows){

    for(int i =0; i<rows; i++){
        delete[] mtx[i];
    }
    delete [] mtx;
}

double** average(double** mtx, int height, int width){
    
    int avg_h = height-2;
    int avg_w = width-2;

    double** avgmtx = new double*[avg_h];

    //this part (2 outer loop) does the iterations of the blocks
    for(int i = 0; i<avg_h; i++){
        avgmtx[i] = new double[avg_w];
        for(int j = 0; j<avg_w; j++){
            //this part(2 inner loop) does the 3x3 iterations in the blocks regardless the startposition
            double sum = 0;
            for(int k = 0; k<3; k++){
                for(int l = 0; l<3; l++){
                    sum += mtx[i+k][j+l];
                }
            }
            avgmtx[i][j] = (sum/9.);
        }
    }
    return avgmtx;
}

int main(){

    double mtx[3][3] = {
    {1., 2., 3.},
    {4., 5., 6.},
    {7., 8., 9.}
};
double** mtx2d = createMtx(&mtx[0][0], 3, 3);
double** block = average(mtx2d, 3, 3);
print(block, 1, 1);
freemem(block, 1);
delete[] mtx2d;

    return 0;
}
