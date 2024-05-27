#include <iostream>
#include <string>
#include <cctype>


using namespace std;

int main(){

    string whole;
    do {
        whole ="";
        cout << "Adjon meg egy rendszamot!";
        getline(cin, whole);
        if (whole == "k") {
                break;
            }
        if (whole.length()==7){
            if (isalpha(whole[0]) && isalpha(whole[1]) && isalpha(whole[2]) && isalpha(whole[3]) && isdigit(whole[4]) && isdigit(whole[5]) && isdigit(whole[6])) {
            cout << " A rendszam BBBBSSS formatumu!" << endl;
            }   else {
            cout << " A rendszam nem BBBBSSS formatumu!" << endl;
            }
        } else {
            cout << " A rendszam nem BBBBSSS formatumu!" << endl;
        }       
    } while(whole != "k");

    return 0;
}
