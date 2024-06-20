/*

3. Definiálja azt a string rgb2hex(unsigned char r, unsigned char g, unsigned char b) függvényt, 
ami paraméterként megkapja egy képpont r (vörös), g (zöld) és b (kék) színkomponenseit, 
visszatérési értéke pedig egy #RRGGBB formátumú string objektum! 
Itt RR, GG és BB két helyiértékes hexadecimális számok. 
(Ezt a formátumot pl. HTML/CSS fájlokban is gyakran használják színek meghatározására.)

*/

#pragma region<include>                                                                         //INCLUDE

    #include<iostream>
    #include<sstream>
    #include<string>
    #include<cctype>

    using namespace std;

#pragma endregion<include>

void lettersUP(string& str){                                                                    //UPPER ALPHAS
    for (unsigned int i =0; i < str.length(); i++){
        int shift = static_cast<int>('a')-static_cast<int>('A');
        if (str[i] >= 'a' && str[i] <= 'z'){            
            int rep_int = static_cast<int>(str[i]);
            rep_int-=shift;
            str[i] = static_cast<char>(rep_int);
        }
    }
}

string rgb2hex(unsigned char r, unsigned char g, unsigned char b){                              //RGB TO HEX

    int red = static_cast<int>(r);
    int green = static_cast<int>(g);
    int blue = static_cast<int>(b);
    stringstream hexs;
    
    hexs << "#" << hex << red << hex << green << hex << blue;

    string hexstring = hexs.str();
    lettersUP(hexstring);

    return hexstring;
}

int main(){                                                                                     //MAIN
