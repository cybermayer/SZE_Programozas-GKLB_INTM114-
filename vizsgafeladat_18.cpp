/*

Definiálja azt a void sortByArea(rectangle* rects, int n) függvényt, 
amely a paraméterként kapott n elemű tömbben szereplő téglalapokat területük szerint 
helyben növekvő sorrendbe rendezi! A paraméter tömb olyan struktúrákból áll, 
melyeknek width nevű tagja a téglalap szélességét, height nevű tagja pedig a magasságát határozza meg, 
és mindkettő dupla pontosságú lebegőpontos érték. A feladat része a megfelelő típusú struktúra definiálása is!

*/

#include<iostream>

using namespace std;

struct rectangle {
    double width;
    double height; 
};

void sortByArea(rectangle* rects, int n){
    for (int i = 0; i<n-1; i++){
        bool swap_flag = false;
        for (int j=0; j<n-i-1; j++){
            double current_size = (rects[j].width*rects[j].height);
            if (current_size>(rects[j+1].height*rects[j+1].width)){
                swap(rects[j], rects[j+1]);
                swap_flag = true;
            }
        } 
        if (!swap_flag) break;
    }
}

void print(rectangle* rects, int n){
    for (int i=0; i<n; i++){
        cout << "[" << rects[i].width << "x" << rects[i].height << " = " << (rects[i].width*rects[i].height) << "]" << endl;
    }
}

int main(){

    	rectangle ra[] = {
		{ 3.5, 1.99 },
		{ 1.87, 2.2917 },
		{ 3.112, 1.301 }
	};

	const int size = sizeof(ra)/sizeof(rectangle);
	sortByArea(ra, size);
	print(ra, size);

    return 0;
}
