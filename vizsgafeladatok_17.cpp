/*

Definiálja azt a factor* factorization(int n) függvényt, mely elkészíti az n természetes szám prímtényezős felbontását! A prímeket és azok kitevőit adja vissza a factor típusú elemekből álló láncolt listában! A struktúra már előzetesen definiált a következőképpen:
struct factor {
    int prime;
    int exponent;
    factor* next;
};
Ebben prime egy prímtényező, exponent pedig annak kitevője, azaz a prím ennyiszer szerepel a felbontásban.

*/

#include<iostream>
#include<vector>

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

void printAndDelete(factor* head){
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

int main(){

    int n = 180;
	factor* f = factorization(n);
	std::cout << n << " = ";
	printAndDelete(f);
	std::cout << std::endl;

    return 0;
}
