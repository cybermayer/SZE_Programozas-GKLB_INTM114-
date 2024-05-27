#include <iostream>
#include <string>
#include <cctype>


using namespace std;

string sanitizeString(string input){    
    string sanitizedString="";
    for (char ch : input) {     
        if (ch != '-') {
            sanitizedString.push_back(ch);
        }
    }
    return sanitizedString;
}

int main(){

    string whole;
    string raw_whole;
    do {
        whole ="";
        cout << "Adjon meg egy rendszamot!";
        getline(cin, raw_whole);
        whole = sanitizeString(raw_whole);
        if (whole == "k") {
                break;
            }
        if (whole.length()==7){
            if (isalpha(whole[0]) && isalpha(whole[1]) && isalpha(whole[2]) && isalpha(whole[3]) && isdigit(whole[4]) && isdigit(whole[5]) && isdigit(whole[6])) {
            cout << " OK" << endl;
            }   else {
            cout << " Formai hiba." << endl;
            }
        } else {
            cout << " Formai hiba." << endl;
        }        
    } while(whole != "k");

    return 0;
}
