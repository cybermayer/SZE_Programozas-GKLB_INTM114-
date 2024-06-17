/*

Készítse el a void DMY2MonthSpelledOut(const std::string& d) függvényt, 
ami paraméterként egy dd/mm/yyyyy (d = nap, m = hónap, y = év) formátumú dátum karakterláncot fogad, 
és kinyomtatja a dátumot dd mmmm yyyy formátumban, azaz a hónap nem numerikusan, hanem szövegesen jelenik meg, angolul.

*/


#include <iostream>
#include <string>
#include <array>

using namespace std;

void DMY2MonthSpelledOut(const std::string& d) {
    array<const string, 12> months = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    string day = d.substr(0, 2);
    string mon = d.substr(3, 2);
    string year = d.substr(6, 4);
    
    int moni = stoi(mon);  // Convert the month substring to an integer

    cout << day << " " << months[moni - 1] << " " << year << endl;
}

int main() {
    const string date = "16/01/2012";
    DMY2MonthSpelledOut(date);
    return 0;
}
