/*

Előzetesen definiáltuk a factor struktúrát, mely egy szám prímtényezős felbontását tároló láncolt lista elemeinek típusa. 
Ennek prime tagja egy prímszám, exponent tagja pedig a prímszám kitevője, azaz ennyiszer fordul elő a prím a szám felbontásában.

struct factor {
    int prime;
    int exponent;
    factor* next;
};

Definiálja azt a void lcm(factor* f1, factor* f2) függvényt, ami a szabvány kimenetre nyomtatja két, 
előzetesen prímtényezőire bontott szám legkisebb közös többszörösének prímtényezős felbontását!
A legkisebb közös többszörös meghatározható úgy, hogy a számokat prímtényezőkre bontjuk, 
majd a közös és nem közös tényezőket a legmagasabb hatványon összeszorozzuk.

*/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct factor {
    int prime;
    int exponent;
    factor* next;
};

using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) return false;
    }
    return true;
}

factor* factorization(int n){
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
                    if (first_flag){
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

void print(factor* head){
    factor* actual = head;
    bool first_flag = true;
    while (actual!=nullptr){
        if(!first_flag){
            cout << " * " << actual->prime << "^" << actual->exponent;
            actual=actual->next;
        }else{
            cout << actual->prime << "^" << actual->exponent;
            actual=actual->next;
            first_flag = false;
        }
    }
    cout << endl;
}


void freeMem(factor* head){
    factor* actual = head;
    factor* to_delete;
    while(actual!=nullptr){
        to_delete = actual;
        actual = actual->next;
        delete to_delete;
    }
}

bool firstPrint(int prime, int exponent, bool first_time){

    if (!first_time){
        cout << " * " << prime << "^" << exponent;
    } else {
        cout << prime << "^" << exponent;
    }
    
    return false;                    
}

void lcm(factor* f1, factor* f2){
    factor* thread1 = f1;
    factor* thread2 = f2;
    int base1 = 0;
    int base2 = 0;
    bool first_print_flag = true;

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

int main(){

int n1 = 18;
factor* f1 = factorization(n1);
cout << n1 << " = "; print(f1);

int n2 = 30;
factor* f2 = factorization(n2);
cout << n2 << " = "; print(f2);

cout << "LCM(" << n1 << ", " << n2 << ") = ";
lcm(f1, f2);
freeMem(f1); freeMem(f2);

    return 0;
}
