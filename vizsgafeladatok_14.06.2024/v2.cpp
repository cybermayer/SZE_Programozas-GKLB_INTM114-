/*

2. Definiálja azt a void box(const string& s) függvényt, 
ami egy árnyékot vető dobozban jeleníti meg az egy soros s szöveget! 
A doboz körvonala és az árnyék * karakterekből áll, 
és a szöveg körül elmarad egy karakternyi hely minden oldalon. 
Itt azt hiszem a szöveg az volt, hogy box in the shadow.

*/

#pragma region<include>                                                                   //INCLUDE

    #include<iostream>

    using namespace std;

#pragma endregion<include>

void box(const string& s){                                                                //SHADOW FUNCTION                                                                  

    #pragma region<frame>                                                                   //Frame constraints

        unsigned int WIDTH = s.length()+5;                                                  
        unsigned int HEIGHT = 5;

    #pragma endregion<frame>

    for(unsigned int i = 1; i<=HEIGHT; i++){                                                //Function engine
        for(unsigned int j=1; j<=WIDTH; j++){
                if(i==1 || i==5) {if(j<=WIDTH){cout<<"*";}}
                else if(i==2 || i==4) {if(j==1 || j>=WIDTH-1){cout<<"*";}else{cout << " ";}}
                else if(i==3) {cout<<"* " << s << " **"; break;}  
        }
        cout << endl;
    }
}

int main(){                                                                               //MAIN

    string str = "Stick that underfunctioning moodle-compiler deep in your ass";

    box(str);

    return 0;
}
