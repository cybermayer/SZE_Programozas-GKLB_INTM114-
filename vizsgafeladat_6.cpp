/*

Készítse el azt a std::string consonants(const std::string& word) függvényt, 
ami a paraméterként kapott word karakterláncnak csak a mássalhangzóit adja vissza. 
A visszatérési értékben és az eredeti karakterláncban ugyanolyan sorrendben kell lenniük a mássalhangzóknak, 
továbbá meg kell őrizni a kis- és nagybetűk közötti különbséget is.

*/
    
#include <iostream>
#include <string>

using namespace std;

string consonants(const string& word) {
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

int main(){

    std::cout << consonants("This is the beginning of a beautiful friendship.") << std::endl;
    return 0;

}
