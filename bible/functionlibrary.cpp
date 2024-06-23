/*


FUNCTION LIBRARY FOR C++ CODING AT SZECHENYI ISTVAN UNIVERSITY


*/

#pragma region<include>                                                 //LIBRARIES AND THEIR DESCRIPTION

    #include<iostream>
    #include<vector>
    #include<cstdlib>
    #include<string>
    #include<algorithm>
    #include<fstream>
    #include<sstream>
    #include<cctype>
    #include<array>
    #include<cmath>

    using namespace std;

#pragma endregion<include>

#pragma region<structs>                                                 //STRUCTS

    struct dataStruct{                                                      //Basic struct for linked lists                                                  
        int data;                                                               //holds data
        //int data2;                                                            //holds data2
        //int data3;                                                            //holds data3                                                              
        dataStruct* next;                                                       //holds address of the next entry
    };

    struct fileSystemEntry{                                                 //Struct for uniques/printFilesystem     
        std::string name;                                                       //holds the name of file or folder
        fileSystemEntry* next;                                                  //holds addreess of next entry in the same folder                                                  
        fileSystemEntry* content;                                               //holds address of the first entry in the next folder
    };

    struct productProperty{                                                 //Struct for holding properties of a product
        double footage;                                                         //holds area can be covered/unit
        int price;                                                              //holds price/unit                                                              
    };

    struct bike_shoes{                                                      //Struct for shoes 
        string name;                                                            //Holds the brandname
        double size_from, size_to;                                              //Holds size of available min and max size
        bool size_OK;                                                           //Holds the bool whether it's okay for our preferences
    };

    struct factor {                                                         //Struct for prime factorization
        int prime;                                                              //holds the base prime number
        int exponent;                                                           //holds the number of powers
        factor* next;                                                           //holds the address of next factor
    };

    struct rectangle{                                                       //Struct for rectangles 
        double width;                                                           //holds size of a                                                        
        double height;                                                          //holds size of b
    };

    struct triathlete{                                                     //Struct for triathletes
        string lic;                                                             //holds licence number
        int swim;                                                               //holds swimming time
        int cycle;                                                              //holds cycling time
        int run;                                                                //holds running time
        int depo;                                                               //holds deponation time
        int sum;                                                                //holds the result time
    };

    struct nameStruct{                                                                                     
        string last="";
        string first1="";
        string first2="";
    };

#pragma endregion<structs>

#pragma region<math>                                                    //FUNCTIONS FOR MATH TYPE PURPOSES

    bool isC1inC2(double x1, double y1, double r1,                          //Check whether Circle1 in Circle                      
                double x2, double y2, double r2) {  

        double distance = sqrt(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));

        return (r1+distance<=r2) ? true : false;
    }

    bool isPrime(int number) {                                              //Check whether a number is prime
                                                      
        if (number <= 1) return false;
        if (number == 2) return true;
        if (number % 2 == 0) return false;
        for (int i = 3; i * i <= number; i += 2) {
            if (number % i == 0) return false;
        }
        return true;
    }

    double* interpolation(double start, double end, int steps){             //Interpolates a range by the specified step
        double* values = new double[steps];    
        double step = (end-start) / (steps - 1);
        for (int i = 0; i < steps; i++){
            values[i] = start + i*step;
        }
    return values; 
    }

    double areaOfParalelogram(double a, double b, double delta) {           //Calculates area of a paralelogram
        
        const double PI = 3.14;
        double rad = delta*(PI/180);


        return a*b*sin(rad);
    }

    double perimeterOfParalelogram(double a, double b) {                //Calculates perimeter of a paralelogram

        return (2*a+2*b);
    }
    
    void sortRectanglesByArea(rectangle* rects, int n){                     //Sorts rectangles by area in place
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

    void print(rectangle* rects, int n){                                    //Prints rectangles
        
        for (int i=0; i<n; i++){
            cout << "[" << rects[i].width << "x" << rects[i].height << " = " << (rects[i].width*rects[i].height) << "]" << endl;
        }
    }

#pragma endregion<math>

#pragma region<linked lists>                                            //FUNCTIONS FOR LINKED LISTS

    dataStruct* createLLFromStaticList(int* list, int size){                //Creates linked list from static list   
        
        int i=0;
        dataStruct* act=new dataStruct;
        dataStruct*  head=act;
        while(i < size){
        act->data=list[i];
            act->next=(i<size-1)? new dataStruct : nullptr;
            act = act->next;
            i++;       
        }
        
        return head;
    }               

    void printLinkedList(dataStruct* head){                                 //Prints linked list

        dataStruct* act=head;
        while(act!=nullptr){
            cout << act->data << " ";
            act=act->next;
        }
        cout << endl;
    }

    void deleteLinkedList(dataStruct* head){                                //Deallocates memory

        dataStruct* act=head;
        dataStruct* to_delete;
        while(act!=nullptr){
            to_delete=act;
            act = act->next;
            delete to_delete;
        }
    }

    dataStruct* deleteLLOnCondition(dataStruct* head, int min){             //Deltes elements holding smaller value than min

        dataStruct* to_delete;
        dataStruct* act = head;
        dataStruct* recent_good=nullptr;
        head = nullptr;

        while(act!=nullptr){        
            if ((act->data)>=min){
                if (head==nullptr){head=act;};
                recent_good=act;
                act=act->next;
            } else {
                to_delete = act;
                act = act->next;
                if (recent_good!=nullptr){recent_good->next=act;};
                delete to_delete;
            }        
        }   
        return head;
    }

    void printAndDeleteLinkedList(factor* head){                            //Prints linked list, than deallocate memory

        factor* act=head;
        factor* to_delete;
        bool first_flag = true;
        while (act != nullptr){
            if (!first_flag){
                cout << " * " << act->prime << "^" << act->exponent;
                to_delete = act;
                act = act->next;
                delete to_delete;

            } else {
                cout << act->prime << "^" << act->exponent;
                first_flag=false;
                to_delete = act;
                act = act->next;
                delete to_delete;
            }
        }
    }

    int countLinkedList(dataStruct* head){                                  //Counts elements in a linked list

        int sum=0;
        dataStruct* act = head;
        while (act != nullptr){
            sum++;
            act = act->next;
        }
        return sum;
    }

    dataStruct* orderLinkedList(dataStruct* head){                          //Orders elements in a linked list (with Bubble)

        int sum = countLinkedList(head);

        for (int i = 0; i < sum-1; i++){
            dataStruct* act = head;
            for(int j = 0; j < sum-i-1; j++){
                dataStruct* next = act->next;
                if (act->data > next->data)
                {
                    int temp = act->data;
                    act->data = next->data;
                    next->data = temp;
                }
                act = next;
            }

        }

        return head;
    }

    dataStruct* reverseLinkedList(dataStruct* head){                        //Rerverses a linked list
           
        dataStruct* act = head;
        dataStruct* next = act->next;
        act->next=nullptr;
        
        while (next!=nullptr){
            head= next->next;
            next->next = act;
            act = next;
            next = head;
        }
            
        return head;
    }

    dataStruct* insertFront(dataStruct* head, int number){                  //Inserts element from forward

        dataStruct* new_front = new dataStruct;
        new_front->data = number;
        if(head!=nullptr){new_front->next = head;};
        return new_front;
    }

    void insertBack(dataStruct* head, int number){                          //Inserts element from backward
        
        if(head==nullptr){
            cerr << "Error: The provided linked list is empty!"; 
        }else{
        dataStruct* new_back = new dataStruct;
        new_back->data = number;
        new_back->next = nullptr;
        head->next = new_back;
        }
    }

    void compareOrderedLists(dataStruct* first, dataStruct* second) {       //Compares linked lists

        dataStruct* comp1 = first;
        dataStruct* comp2 = second;
        bool same = true;

        while (comp1 != nullptr && comp2 != nullptr) {
            //cout << "first: " << comp1->data << "second: " << comp2->data << endl;
            if ((comp1->data != comp2->data)  /*  || (comp1->data2 != comp2->data2) */  ) {
                same = false;
                break;
            }
            comp1 = comp1->next;
            comp2 = comp2->next;
        }

        (same==true) ? cout << "They are the same ones" : cout << "They aren't the same ones";
    }

    factor* primeFactorization(int n){                                      //Decomposes a number into prime factors

        vector<int> primes;
        int number =2;
        while (primes.size()<100){
            if (isPrime(number)){
                primes.push_back(number);
            }
            number++;
        }
        int d=n, i=0, e=0;
        factor* head; 
        factor* recent;
        bool first_flag = true;
        
        while (d>=1){
            if ((d % primes[i]) == 0){
                d = d/primes[i];
                e++;
                                        } else {
                                                if(e!=0){
                                                    factor* part = new factor;
                                                    part->prime = primes[i];
                                                    part->exponent = e;
                                                    part->next = nullptr;
                                                    (d==1) ? d-=1 : d*=1;

                                                    if (first_flag)         {
                                                        head=part;
                                                        first_flag=false;
                                                        recent = head;
                                                                                } else {
                                                                                    recent->next = part;
                                                                                    recent = part;
                                                                                }
                                                    e=0;
                                                }
                                                i++;    
            }
        }
        return head;
    }

    void lcm(factor* f1, factor* f2){                                       //Specifies the lowest common multiple, print as multiplication of decomponents on the power
        
        factor* thread1 = f1;
        factor* thread2 = f2;
        int base1 = 0;
        int base2 = 0;
        bool first_print_flag = true;

        auto firstPrint = [](int prime, int exponent, bool first_time) -> bool {
            //lambda functiom for printing logic (consideration of first case)

            if (!first_time){
                cout << " * " << prime << "^" << exponent;
            } else {
                cout << prime << "^" << exponent;
            }
            return false;                    
        };

        while(thread1!=nullptr || thread2!=nullptr){

            int e1=0, e2=0, n1=0, n2=0;

            if (thread1==nullptr) base1 = base2+1; //this lines keeps the boundaries for thread2 if thread1 has finished
            if (thread2==nullptr) base2 = base1; //this lines keeps the boundaries for thread1 if thread2 has finished

            //thread1 step forward process
            while (base1<=base2 && thread1!=nullptr){
                n1 = thread1->prime;
                e1 = thread1->exponent;
                thread1 = thread1->next;
                base1 = n1;
            }

            //thread2 step forward process
            while (base2<base1 && thread2!=nullptr){
                n2 = thread2->prime;
                e2 = thread2->exponent;
                thread2 = thread2->next;
                base2 = n2;
            }

            if(n1==n2){

                first_print_flag = firstPrint(n1, max(e1,e2), first_print_flag);

            } else {

                if (n1 != 0) {first_print_flag = firstPrint(n1, e1, first_print_flag);}           
                if (n2 != 0) {first_print_flag = firstPrint(n2, e2, first_print_flag);}
            }
        } 
    } 

#pragma endregion<linked lists>

#pragma region<strings>                                                 //FUNTIONS FOR STRING MANIPULATION

    void lettersDOWN(string& str){                                          //Lower casing in place                                                         

        for(char& ch:str){
            if(ch>='A' && ch<='Z'){ch=ch+('a'-'A');}
        }
    }

    void lettersUP(string& str){                                            //Upper casing in place 
        for (unsigned int i =0; i < str.length(); i++){
            int shift = static_cast<int>('a')-static_cast<int>('A');
            if (str[i] >= 'a' && str[i] <= 'z'){            
                int rep_int = static_cast<int>(str[i]);
                rep_int-=shift;
                str[i] = static_cast<char>(rep_int);
            }
        }
    }

    void capitalizeFirstLetter(string& str){
        int shift = static_cast<int>('a')-static_cast<int>('A');
        int rep_int = static_cast<int>(str[0]);
        rep_int-=shift;
        str[0] = static_cast<char>(rep_int);
    }

    void charCounter(std::string str, int n){                               //Print chr-s in abc order that can be found in str n-times

        std::string abc ="";
        int occurance[26]={0};
        for(int i = static_cast<int>('a'); i <= static_cast<int>('z'); i++) {
            abc.push_back(static_cast<char>(i));
        }
        for(char i : str){
            for (int j = 0; j<26; j++){
                if (abc[j]==tolower(i)){
                    occurance[j]++;
                }
            }
        }
        for (int i=0; i<26; i++){
        if (occurance[i]==n) {
                cout << abc[i] << " ";
        }
        }
    }

    string extractConsonants(const string& word) {                          //Return the consonants from a strig (case-senstive way)

        string tilos = " aeiouAEIOU0123456789.,";
        string result;
        
        for (unsigned int i = 0; i < word.length(); i++) {
            bool app = true;
            for (unsigned int j = 0; j < tilos.length(); j++) {
                if (word[i] == tilos[j]) {
                    app = false;
                    break;
                }
            }
            if (app) {
                result.push_back(word[i]);
            }
        }
        return result;  // Return the result string
    }

    void DMY2MonthSpelledOut(const std::string& d) {                        //Date conversion: '16/01/2012' to '16 January 2012'

        array<const string, 12> months = { //array has to be included
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };

        string day = d.substr(0, 2);
        string mon = d.substr(3, 2);
        string year = d.substr(6, 4);

        int moni = stoi(mon);  // Convert the month substring to an integer

        cout << day << " " << months[moni - 1] << " " << year << endl;
    }

    void spinningLetters(string str) {                                      //Spins the letters till hits JACKPOT (detailed explanation in function)

        /* Hard to explain in one line so, it does:
        aaaaa
        bbbbb
        ccccc
        ddddd
        eeeee
        fefff
        geggg
        hehhh
        ieiii
        jejjj
        jekkk
        jelll
        jemmm
        jennn
        jenno
        jennp
        jennq
        jennr
        jenns
        jennt
        jennu
        jennv
        jennw
        jennx
        jenny
        */

        const string abc = "abcdefghijklmnopqrstuvwxyz";
        string lstr="";
        string printable = "";

            //generate printable
            for (unsigned int i = 1; i <= str.length(); i++){
                printable.push_back('1');
            }

            //generate lower string
            for (char ch : str){
                lstr.push_back(tolower(ch));
            }

            do {    
                for(char ch : abc){
                    for (unsigned int i = 0; i < lstr.length(); i++){
                        if (lstr[i]!=printable[i]){
                            printable[i]=ch;
                                                    } else {
                                                        printable[i] = lstr[i];
                                                    }
                    }       
                    cout << printable << endl;
                    if (printable.compare(lstr) == 0){
                            break;
                    }
                }
                } while(printable.compare(lstr) != 0); 
    }

    void recognizeNPrintStrNtimes(string str){                              //Prints string n-times based on string (str: "3xJohnny")
        string snum, word;
        int num, x = 0;   
        while (str[x]!='x'){
            snum.push_back(str[x]);
            x++;
        }
        num = stoi(snum);
        word = str.substr(x+1);
        for (int i = 0; i < num; i++){
            cout << word;
    }
}

#pragma endregion<strings>

#pragma region<uniques>                                                 //FUNCTIONS FOR UNCATEGORISED PURPOSES 

    string rgb2hex(unsigned char r, unsigned char g, unsigned char b){      //Convert unsigned char(r,g,b) to #HEXCODE                             

        int red = static_cast<int>(r);
        int green = static_cast<int>(g);
        int blue = static_cast<int>(b);
        stringstream hexs;
        
        hexs << "#" << hex << red << hex << green << hex << blue;

        string hexstring = hexs.str();
        lettersUP(hexstring);

        return hexstring;
    }

    void printFileSystem(const fileSystemEntry* head) {                     //Print "filesystem" (tabulated on depth)

        vector<const fileSystemEntry*> stack;
        string tab = "";
        stack.push_back(head);

        while (!stack.empty()) {
            const fileSystemEntry* current = stack.back();
            stack.pop_back();

            if (current != nullptr) {
                cout << tab << current->name << endl;

                if (current->next != nullptr || (current->next == nullptr && current->content != nullptr)) {
                    stack.push_back(current->next);

                    } else if (current->next == nullptr && !tab.empty()){
                        tab.pop_back();
                        tab.pop_back();
                }
                if (current->content != nullptr) {
                    stack.push_back(current->content);
                    tab.push_back(' ');
                    tab.push_back(' ');
                }
                
            }
        }
    }

    double calcCost(productProperty flooring, double area) {                //Calc cost of flooring an area

        int pieces = ceil((area)/flooring.footage);

        return (pieces)*(flooring.price);

    };   
    
    int takeIntsPlaceOnCondRtSUM(int be_tb[], int *min, int *max){          //Takes ints, places them if cond has been met
        
        /*
        It takes int-s n-times pos 0 can be only 0,
        Even pos must be even, odd must be odd;
        Return sum of elements has been placed;
        */

        const int SIZE = 10;
        int sum = 0, num=-1;

        while(num!=0){
            cin >> num;
            if(num==0){
                be_tb[0]=0;
                }
            }

        for (int i = 1; i<SIZE; i++){
            cin >> num;
            if(i%2==0 && num%2==0){
                be_tb[i]=num;
            }else if(i%2!=0 && num%2!=0){
                be_tb[i]=num;
            } else {
                i--;
            }
        }

        for(int i=0; i<SIZE; i++){

            if (i%2==1 && be_tb[i]<(*min)) {(*min)=be_tb[i];}
            if (i%2==0 && be_tb[i]>(*max)) {(*max)=be_tb[i];}
            sum+=be_tb[i];
        }
        return sum;
    }

    double takeDblsPlaceOnCondRtMSUMofCbrts(double in_bk[]) {               //Takes doubles, places them if cond has been met

        /*
            Takes SIZE doubles and placing them,
            if they're between 0 and THRESHOLD;
            return multisum of cubicroots.
        */

        const int SIZE = 5;
        const double THRESHOLD = 256.;
        double num, result=1;
        for(int i=0; i<SIZE; i++){
            cin >> num;
            if (num > 0 && num<THRESHOLD){
                in_bk[i]=num;
                result*=cbrt(num);
            } else {
                i--;
            }
        }
    return result;
}

#pragma endregion<uniques>

#pragma region<character arrays>                                        //FUNCTIONS FOR CHARACTER ARRAYS

    char** createCharArray(string& str){                                    //Create null-terminated character arrays from string ending with nullptr 

        #pragma region<variables>                                           //Variable init

            vector<string> words;

        #pragma endregion<variables>

        #pragma region<data_reader>                                         //Read data and place into a vector

            unsigned int i=0;                                                                                  
            while(str[i] != '\0'){
                string word ="";
                while (str[i] != '\0' && str[i]!=' '){
                    word.push_back(str[i]);
                    i++;
                } if(str[i] != '\0'){i++;};
                words.push_back(word);
            }

        #pragma endregion<datareader>

        #pragma region<array_creater>                                       //Create and fill array

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

        return chr_arr;                                                     //Return dynamic array
}       

    void printChrArray(char** chrArr){                                      //Print a char** array char[i] ending nullptr char[i][j] ending '\0'
        
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

    void freeMem(char** chrArr){                                            //Memory deallocation of char** ending nullptr

        unsigned int i = 0;
        while (chrArr[i]!=nullptr){
            delete[] chrArr[i];
            i++;
        } delete[] chrArr;

    }  
    
    string kebabCase(char** chrArr){                                        //Return: word-word-word-word form from char**

        string kb="";
        unsigned int i = 0;
        while(chrArr[i]!=nullptr){
            unsigned int j = 0;
            string word = (i!=0)?"-":"";
            while(chrArr[i][j]!='\0'){
                word.push_back(chrArr[i][j]);
                j++;
            } i++;  
            lettersDOWN(word);
            kb+=word;        
        }
        return kb;      
    }
    
#pragma endregion<character arrays>

#pragma region<print shapes>                                            //FUNCTIONS TO PRINT SHAPES (MOSTLY USING *-s)

    void shadowBox(const string& s){                                        //Shadow-box funtion                                                                   

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
    
    int** generateLowerTriangle(int size){                                  //Generate lower triangle
    
        int** triangle = new int*[size];
        for (int i = 0; i <size; i++){
            triangle[i] = new int[i+i];
            for(int j = 0; j <= i; j++){
                triangle[i][j] = (i+1)*10 + (j+1);
            }
        }
        return triangle;
    }

    void printLowerTriangle(const int* const* triangle, int size){          //Print lower triangle

        for (int i = 0; i < size; i++){
            cout << " ";
            for (int j = 0; j <= i; j++){
                cout << triangle[i][j] << " ";
            }
            cout << endl;
        }
    }

    void freeLowerTriangle(int** triangle, int size){                       //Deallocate lower triangle
        
        for (int i = 0; i < size; i++){
            delete[] triangle[i];
        }
        delete[] triangle;
    } 

    int** generateUpperTriangle(int size){                                  //Generate upper triangle

        int** triangle = new int*[size];
        for (int i = 0; i < size; i++){
            triangle[i] = new int[size-i];
            for (int j=0; j <= size-1-i; j++){
                triangle[i][j] = (i+1)*10 + (j+i+1);
            }
        }
    return triangle;
    }

    void freeUpperTriangle(int** triangle, int size){                       //Deallocate upper triangle

        for (int i=0; i < size; i++){
            delete[] triangle[i];
        }
        delete[] triangle;
    }

    void printUpperTriangle(const int* const* triangle, int size){          //Print upper triangle

        for (int i = 0; i < size; i++){
            cout<< " " << string(i*3, ' ');
            for (int j=0; j <= size-i-1; j++){
                cout << triangle[i][j] << " ";

            }
            cout << endl;
        }

    }

    int** generatePascal(int size){                                         //Generate Pascal-triangle

        int** pascal = new int*[size];
            for(int i = 0; i<size; i++){
                pascal[i] = new int[i+1];
                for(int j=0; j<=i; j++){
                    if (j == 0 || j == i){
                        pascal[i][j]=1;
                    } else {
                        pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
                    }
                }
            }
    return pascal;
    }

    void printPascal(const int* const* pascal, int size){                   //Print Pascal-triangle

        for(int i=0; i<size; i++){        
            for(int j=0; j<=i; j++){
                cout << pascal[i][j] << '\t';
            }
            cout << endl;
        }       
    }

    void freePascal(const int* const* pascal, int size){                    //Deallocate Pascal-triangle

        for (int i =0; i < size; i++){
            delete[] pascal[i];
        }
        delete[] pascal;
    }     

    char** createTabulaRecta() {                                            //Generate Tabula Recta

        char** tabularecta = new char*[26];
        for(int i=0; i<26; i++){
            tabularecta[i] = new char[26];
            int ascii_of_letter = static_cast<int>('A')+i;
            for(int j=0; j<26; j++){
                if (ascii_of_letter > 90){
                ascii_of_letter -= 26;      
                }
                tabularecta[i][j]=static_cast<char>(ascii_of_letter);
                ascii_of_letter++;
            }
        }
    return tabularecta;
    }    

    void printTabulaRecta(const char* const* tr){                           //Print Tabula Recta

        //cout << " " << "|" << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
        //cout << "-+--------------------------" << endl;

        for(int i=0; i<26; i++){
            cout<< static_cast<char>(65+i) << "|";
            for(int j=0; j<26; j++){            
                cout << tr[i][j];
            }
            cout << endl;
        }
    }    

    void freeTabulaRecta(char** tr){                                        //Deallocate Tabula Recta

            for(int i=0; i<26; i++){
                delete[] tr[i];
            }
        delete[] tr;
    }       

    void prtRectFillRotStr(int width, int height, std::string text){        //Prints WxH rectangle, fills with rotating string

        for(int i=0; i<height; i++){
            unsigned int start = i;
            if (start>=text.length()) start -=(floor(i/text.length())*(text.length()));
            for(int j=0; j<width; j++){
                cout << text[start];
                start++;
                if (start==text.length()) start=0;
            }
            cout << endl;
        }
    }

#pragma endregion<print shapes>

#pragma region<arrays>                                                  //FUNCTIONS FOR ARRAY/MATRIX MANIPULATIONS AND OPERATIONS

    void lowerTriangleFromMTX(int** m, int n){                              //Print lower triangle from matrix (set upper parts to zeros)

        for(int i=0; i<n; i++){                                                                         
            for(int j=0; j<n; j++){
                if (j>i){m[i][j] = 0;}
                cout << m[i][j];
            } cout << endl;
        }
    }

    void upperTriangleFromMTX(int** m, int n){                              //Print uppewr triangle from matrix (set lower parts to zeros)

        for(int i=0; i<n; i++){                                                                         
            for(int j=0; j<n; j++){
                if (j<i){m[i][j] = 0;}
                cout << m[i][j];
            } cout << endl;
        }
    }

    double* avergeAdjacentElements(const double* array, int n){             //Averaging adjacent elements and create new array for them          

        if(array !=nullptr && n>1) {
            double* new_array = new double[n-1];
            for(int i = 0; i<n; i++){
                new_array[i] = (array[i]+array[i+1])/2;        
            }
            return new_array;
        }
        return nullptr;
    }

    double** crDynMTXFromStatMTX(double* start, int height, int width){     //Create D.MTX From S.MTX, arg. should be passed: &mtx[0][0]

        double** mtx=new double*[height];
        for (int i=0; i<height; i++){
                mtx[i]=new double[width]; 
            for (int j=0; j<width; j++){
                mtx[i][j] = *(start+i*width+j);
            }
        }
    return mtx;
    }

    void printMTX(double** mtx, int height, int width){                     //Print MTX

        for (int i = 0; i<height; i++){
            for (int j = 0; j<width; j++){
                cout << mtx[i][j] << " ";
            }
            cout << endl;
        }
    }

    void freeMTX(double** mtx, int rows){                                   //Deallocate memory

        for(int i =0; i<rows; i++){
            delete[] mtx[i];
        }
        delete [] mtx;
    }

    bool isSymmetric(int** mtx, int size){                                  //Considers whether a matrix is symmetric

        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if (mtx[i][j]!=mtx[j][i]) return false; 
            }
        }
    return true;
}

    double** average_3x3_Blocks(double** mtx, int height, int width){       //Averaging every 3x3 blocks and create a (h-2)x(w-2) D.MTX

        int avg_h = height-2;
        int avg_w = width-2;

        double** avgmtx = new double*[avg_h];

        //this part (2 outer loop) does the iterations of the blocks
        for(int i = 0; i<avg_h; i++){
            avgmtx[i] = new double[avg_w];
            for(int j = 0; j<avg_w; j++){
                //this part(2 inner loop) does the 3x3 iterations in the blocks regardless the startposition
                double sum = 0;
                for(int k = 0; k<3; k++){
                    for(int l = 0; l<3; l++){
                        sum += mtx[i+k][j+l];
                    }
                }
                avgmtx[i][j] = (sum/9.);
            }
        }
        return avgmtx;
    }

    void printList(double* list, int size){                                 //Prints the elements of an n-size static array
        for (int i=0; i<size; i++){ 
            cout << list[i] << " ";
        }
    }

#pragma endregion<arrays>

#pragma region<files>                                                   //FUNCTIONS FOR FILE OPERATIONS

    void examCount(const std::string& fileName){                            //Reads file, check the number of written exams by whom

        ifstream file(fileName);
        string line;
        while (getline(file, line)){
            istringstream iss(line);
            string word;
            int exam = -1;
            while (iss >> word){
                (exam<0) && cout << word;
                exam++;
            } 
            cout << " " << exam << endl;
        }
    }

    void rotateLinesReadFromFile(const std::string& fileName){              //Reads file, rotates and prints the lines

        ifstream file(fileName);

        if (!file.is_open()) {
            cerr << "Failed to open file." << endl;
            return;
        }

        string line;

        while(getline(file, line)){
            for(unsigned int i=0; i<line.length(); i++){
                unsigned int step = i;
                for (unsigned int j=0; j<line.length(); j++){   
                    std::cout << line[step];
                    step++;
                    if (step==(line.length())) step=0;
                }
                std::cout << endl;
            } 
        }
    file.close();
    }

    string tri_result(string fbe){                                          //Reads lines from files feed them into ordered array, return looser, print winner

        auto freeMem=[](triathlete** tris, int size)->void{

            for (int i=0; i<size; i++){
                delete tris[i];
            }
            delete[] tris; 
        };

        ifstream file(fbe);
        string line, win_lic, los_lic;
        int i =0, size, win=INT_MAX, los=INT_MIN;
        triathlete** tris = nullptr;
        bool first_flag = true;
        if(!file.is_open()){
            std::cout << "Sikertelen file-nyitás!" << endl; 
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
            
            std::cout << win_lic << " => " << hour << ":" << min << ":" << sec << " [h:m:s]" << endl;

        return los_lic;
    }

    int sizeSearch(string fbe, double my_size, string *brand) {             //Reads brands, check how much has a size meets or prefs

        #pragma region                                                               //VARIABLE INIT
                                                                                            
            int size, i=0, ok_for_us=0;                                                             
            string line;
            bool first_flag=true;
            bike_shoes** shoes;
            ifstream file(fbe);       

        #pragma endregion
                                                        
        if(!file.is_open()){                                                        //ERROR HANDLING
            cout << "Unable to open the file!" << endl;                                //cerr should be used, but that cannot be taken by moodle-compiler
            return 0;
        } 

        while(getline(file, line)){                                                 //FILE READING

        if  (first_flag){                                                                      //identication of the size

                size = stoi(line);
                shoes = new bike_shoes*[size];
                first_flag=false;

        
        }                                      
                                                else {                                         //read the lines
                                                
                                                        int j = 0;
                                                        shoes[i] = new bike_shoes;

                                                                while (line[j] != ' '){                     //get brand
                                                                    shoes[i]->name.push_back(line[j]);      
                                                                    j++;                                    
                                                                }                                           
                                                        j++;                                                

                                                        string size_from ="";                               //get lower size
                                                                while (line[j]!=' '){                       
                                                                    size_from.push_back(line[j]);           
                                                                    j++;
                                                                }
                                                        shoes[i]->size_from = stod(size_from);              
                                                        j++;                                                
                                                        
                                                        string size_to="";                                  //get upper size                                                        
                                                                while (line[j]!=' '){                       
                                                                    size_to.push_back(line[j]);     
                                                                    j++;
                                                                }
                                                        shoes[i]->size_to = stod(size_to);


                                                        (shoes[i]->size_OK) = (my_size>=(shoes[i]->size_from) && my_size<=(shoes[i]->size_to)) ? true : false;
                                                        i++;

                                                }

    }

        *brand = shoes[0]->name;                                                    //SET FIRST BRAND

        {for (i = 0; i<size; i++){                                                  //RETURN CALC AND MEMORY DEALLOC
            if (shoes[i]->size_OK==true){
                ok_for_us+=1;
            }
            delete shoes[i];
        }
                delete[] shoes;}

        return ok_for_us;                                                       //COUNT OF TYPES DO NOT MATCH 
}

    string* fullNameSort(string fbe, string fki){                           //Reads lines, from file, sorting authors alphabetically

    #pragma region                                                                          //Variable init

        ifstream in_file(fbe);
        ofstream out_file(fki, ios::app);
        vector<nameStruct>authors_vec;
        int i=0; 
        string line;   

    #pragma endregion                                                                                                                      

    #pragma region                                                                          //Error handling                                                                  

        if(!in_file.is_open()){                                                                 //open error
                cout << "Sikertelen file-nyitás!" << endl;                                          //cerr should be used, but that cannot be taken by moodle-complier
                return nullptr;
            }

        if(!out_file.is_open()){                                                                //saving error
                cout << "Háttértár hiba!" << endl;                                                 //cerr should be used, but that cannot be taken by moodle-complier
                return nullptr;
            }

    #pragma endregion

    while(getline(in_file, line)){                                                          //Data reading
        
        #pragma region                                                                          //loop variables init

            string act_last_name="";
            string act_first_name_1="";
            string act_first_name_2="";
            int char_i = 0;
            nameStruct Author;
            bool inserted=false;

        #pragma endregion

        #pragma region                                                                          //resolving names
                                                                                                
            while(line[char_i]!=',' && line[char_i] != '\0'){
                act_last_name.push_back(line[char_i]);
                char_i++;
            } char_i+=2;                                            
            while(line[char_i]!=' ' && line[char_i]!='\0'){
                act_first_name_1.push_back(line[char_i]);           
                char_i++;                
            }if(line[char_i]!='\0'){char_i++;}                      
            while(line[char_i]!='\0' && line[char_i]!=' '){
                act_first_name_2.push_back(line[char_i]);
                char_i++;
            }

        #pragma endregion
        
        #pragma region                                                                          //assemble and place Author-object
                            Author.last=act_last_name;
                            Author.first1=act_first_name_1;
                            if(act_first_name_2.length()>0){Author.first2=act_first_name_2;} 
                            if (authors_vec.empty()){authors_vec.push_back(Author);}                                                                                   
                                                                                   
                            else {for(unsigned int k=0; k<=i; k++){                              
                                        if ((authors_vec[k].last+authors_vec[k].first1+authors_vec[k].first2)>(act_last_name+act_first_name_1+act_first_name_2)){
                                            authors_vec.insert(authors_vec.begin() + (k), Author);
                                            inserted=true;
                                            break;
                                        }                                        
                                        if((k==i) && !inserted){authors_vec.push_back(Author);}
                                        
                                }}
                                   

        #pragma endregion

        i++;                                                                                    //increase iteration variable
                                                                                                
    
    }

    string* authors = new string[authors_vec.size()];                                       //Create the return array

    for (unsigned int auth=0; auth<authors_vec.size(); auth++){                             //Fill the return array, write into outfile and cout
    
        string string_value = authors_vec[auth].last + ", " + authors_vec[auth].first1 + " " + authors_vec[auth].first2;
        authors[auth] = string_value;
        out_file << string_value << endl;
        //cout << string_value << endl;

    }

    #pragma region                                                                          //Close open files

        in_file.close(); out_file.close();

    #pragma endregion

    return authors;                                                                         //Returns abc ordered array of authors
}

#pragma endregion<files>

int main(){
    
    return 0;
}

