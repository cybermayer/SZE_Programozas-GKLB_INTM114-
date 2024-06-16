#include<iostream>

using namespace std;

void shadow(string s){
    const unsigned int WIDTH = s.length()+4;
    for (int i =1; i<= 5; i++){
        for (unsigned int j = 1; j<=WIDTH; j++){
            if (i==1 || i==5){
                if (j!=WIDTH){
                    cout << "*";
                }else {
                    cout << "*" << endl;
                }
            } else if (i==2 || i==4){
                if (j==1 || j>=WIDTH-1){
                    cout << "*";
                    if (j==WIDTH){
                        cout << endl;
                    }
                }else {
                    cout << " ";
                }
            } else if (i==3){
                if (j==1){
                    cout << "*";
                    if (j==WIDTH){
                        cout << endl;
                    }
                } else if (j==2){
                    cout << " " << s << " " << "**" << endl;
                    j+=(WIDTH);
                }
            }
        }
    }
}


int main(){

    string s = "Anything could be written here";
    shadow(s);
  
    return 0;
}
