#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> datas;

int main() {
    cout << "Datumok csokkeno sorrendbe rendezese" << endl << endl;

    string year, month, day, date;
    int imonth = 0, iday = 0;

    for (unsigned int i = 1; i <= 5; i++) {
        cout << i << ". szemely szuletesi eve: ";
        cin >> year;

        cout << "Szuletes honapja: ";
        cin >> month;
        imonth = stoi(month);
        if (imonth <= 9) {
            month = "0" + month;
        }

        cout << "Szuletes napja: ";     
        cin >> day;
        iday = stoi(day);
        if (iday <= 9) {
            day = "0" + day;
        }

        date = year + "." + month + "." + day;
        datas.push_back(date);
    }
  
    for (unsigned int i = 0; i < datas.size() - 1; i++) {
        for (unsigned int j = 0; j < datas.size() - i - 1; j++) {
            if (datas[j] < datas[j + 1]) {
                swap(datas[j], datas[j + 1]);
            }
        }
    }

    cout << "Kor szerint novekvoen rendezett adatok: " << endl;
    for (unsigned int p = 0; p < datas.size(); p++) {
        cout << datas[p] << endl;
    }

    return 0;
}
