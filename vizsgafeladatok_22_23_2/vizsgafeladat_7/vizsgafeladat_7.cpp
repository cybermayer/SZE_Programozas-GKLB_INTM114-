/*

Írjon egy string tri_result(string fbe) függvényt, amely kiírja egy adott triatlon
verseny győztesének az azonosítóját (licence), és a cél-idejét; óra:perc:másodperc
alakban. A cél-idő a következő részeredményekből tevődik össze:
úszás + kerékpár + futás + depo. A kiírás pontos formátumát a példa mutatja!
A célba érkezett versenyzők számát és a részidőket egy adat-file tartalmazza,
amelynek a létezését ellenőrizni kell! A hibaüzenet formátumát a példa mutatja!
Ennek az állománynak az azonosítója lesz a tri_result függvény paramétere.
Az adat-file első sora egy pozitív egész szám, amely a célba érkezettek száma.
A további mindenegyes sora egy-egy sportolót azonosít és tartalmazza a részidejeit
másodpercben, a következők szerint:

            licence úszás-idő kerékpár-idő futás-idő depó-idő.

Az adatokat szóközök választják el egymástól! Pl.:

            df-572ki 1500 4500 2500 125
            …
            do-565yy 1900 4900 2900 129
            
Az adat-file elemeit tárolja el egy struktúra-tömbbe, amihez használja a megadott
struct triathlete típust! A struktúra-tömböt a dinamikus memóriába hozza létre!
A versenyzők kiszámolt cél-idejeit (másodpercben) az int sum tagváltozókba
mentsék el. Ezen adatokból kell megállapítani a győztes és az utolsó versenyző
cél-idejeit. Ugyanis a függvény visszatérési értéke az utolsó versenyző licence legyen.
Ha az adat-file nem létezik, akkor a visszatérési érték az ”N/A!” karaktersorozat legyen!
(A cerr << ... utasítást NE használják! moodle… :( )

*/

#include<iostream>
#include<fstream> 
#include<string>
#include<climits>
#include<cmath>

using namespace std;

struct triathlete {
  string lic;
  int swim;
  int cycle;
  int run;
  int depo;
  int sum;
};

void freeMem(triathlete** tris, int size){

    for (int i=0; i<size; i++){
        delete tris[i];
    }
    delete[] tris; 
}

string tri_result(string fbe){

    ifstream file(fbe);
    string line, win_lic, los_lic;
    int i =0, size, win=INT_MAX, los=INT_MIN;
    triathlete** tris = nullptr;
    bool first_flag = true;
    if(!file.is_open()){
        cout << "Sikertelen file-nyitás!" << endl;
        return "N/A!";
    }

    while(getline(file, line)){

        if(first_flag){

            size = stoi(line);
            tris = new triathlete*[size];
            first_flag = false;

        }else{
            
        tris[i] = new triathlete;
        tris[i]->lic = line.substr(0,8);
        tris[i]->swim = stoi(line.substr(9,4));
        tris[i]->cycle = stoi(line.substr(14,4));
        tris[i]->run = stoi(line.substr(19,4));
        tris[i]->depo = stoi(line.substr(24,3));
        tris[i]->sum = (tris[i]->swim) + (tris[i]->cycle) + (tris[i]->run) + (tris[i]->depo);
        
        i++;
        }
        } 
  
        file.close();
        for (i = 0; i < size; i++){
            if ((tris[i]->sum)<win) {win=tris[i]->sum; win_lic=tris[i]->lic;}
            if ((tris[i]->sum)>los) {los=tris[i]->sum; los_lic=tris[i]->lic;}
        }

        freeMem(tris, size);

        int hour = floor(win/3600); win-=(hour*3600);
        int min = floor(win/60); win-=(min*60);
        int sec = win;
        
        cout << win_lic << " => " << hour << ":" << min << ":" << sec << " [h:m:s]" << endl;

    return los_lic;
}

int main(){

    string u=tri_result("./Chip.txt");
    std::cout << u;

    u=tri_result("./Chi.txt");
    std::cout << u;

    return 0;
}
