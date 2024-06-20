/*

4. Definiálja azt a string kebabCase(const char** words) függvényt, 
ami a words szavakat kisbetűssé alakítja, majd kötőjelekkel elválasztva összefűzi és visszaadja string objektumként! 
A words egy mutatótömb, melynek utolsó eleme mindig nullptr.

*/

#pragma region<include>                                                                     //INCLUDE

    #include<iostream>
    #include<vector>

    using namespace std;

#pragma endregion<include>

void lowerCase(string& str){                                                                //Lower casing in place                                                        

    for(char& ch:str){
        if(ch>='A' && ch<='Z'){ch=ch+('a'-'A');}
    }
}

void freeMem(char** chrArr){                                                                //MEMORY DEALLOCATION

    unsigned int i = 0;
    while (chrArr[i]!=nullptr){
        delete[] chrArr[i];
        i++;
    } delete[] chrArr;

}                                                                 

void printChrArray(char** chrArr){                                                          //PRINT CHAR** ARRAY <- backcheck function
        
    unsigned int i = 0;
    while (chrArr[i] != nullptr){
        unsigned int j = 0;
        while (chrArr[i][j] != '\0'){
            cout << chrArr[i][j];
            j++;
        }
        cout << " "; 
        i++;
    }
} 

char** createChrArray(string& str){                                                         //CREATE CHAR** ARRAY FROM STRING 

    #pragma region<variables>                                                                   //Variable init

        vector<string> words;

    #pragma endregion<variables>

    #pragma region<data_reader>                                                                 //Read data and place into a vector

        unsigned int i=0;                                                                                  
        while(str[i] != '\0'){
            string word ="";
            while (str[i] != '\0' && str[i]!=' '){
                word.push_back(str[i]);
                i++;
            } if(str[i] != '\0'){i++;};
            words.push_back(word);
        }

    #pragma endregion<data_reader>

    #pragma region<array_creater>                                                               //Create and fill array

        const unsigned int SIZE = words.size();                                                     
        char** chr_arr = new char*[SIZE+1];
        for(i=0; i<SIZE; i++){
            unsigned int wL = words[i].length();
            chr_arr[i]= new char[wL+1];
            for(unsigned j=0; j<wL; j++){
                chr_arr[i][j]=words[i][j];
            } chr_arr[i][wL] = '\0';
        } chr_arr[SIZE] = nullptr;

    #pragma endregion<array_createry>

    return chr_arr;                                                                             //Return dynamic array
}

string kebabCase(char** chrArr){                                                            //Task function (naming? i dont get it too..)

    string kb="";
    unsigned int i = 0;
    while(chrArr[i]!=nullptr){
        unsigned int j = 0;
        string word = (i!=0)?"-":"";
        while(chrArr[i][j]!='\0'){
            word.push_back(chrArr[i][j]);
            j++;
        } i++;  
        lowerCase(word);
        kb+=word;        
    }
    return kb;      
}

int main(){                                                                                 //MAIN

    string kebab, str = "These Tasks Are Pain In The Ass";
    char** array = createChrArray(str);
    kebab = kebabCase(array);
    cout << kebab;
    freeMem(array);

    return 0;
}
