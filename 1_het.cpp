#include<iostream>

using namespace std;

int main(){

    //1. feladat
    cout << "1. Feladat" << endl;
    cout << "------------------------------------------" << endl;
    int numb;
    cout << "Adjon meg egy egesz szamot! " ;
    cin >> numb;
    cout << numb << " * 2 = " << numb * 2 << endl;
    cout << "------------------------------------------" << endl;

    //2. feladat
    cout << "2. Feladat" << endl;
    cout << "------------------------------------------" << endl
    int numb1, numb2;
    cout << "Adjon meg ket egesz szamot! " ;
    cin >> numb1 >> numb2;
    cout << numb1 << " + " << numb2 << " = " << numb1 + numb2 << "\n" << numb1 << " * " << numb2 << " = " << numb1 * numb2 << "\n" << "(" << numb1 << " * " << numb2 << ")" << " - " << "(" << numb1 << " + " << numb2 << ")" << " = " << (numb1*numb2)-(numb1+numb2) << endl;
    cout << "------------------------------------------" << endl;

    //3. feladat
    cout << "3. Feladat" << endl;
    cout << "------------------------------------------" << endl
    int numb;
    cin >> numb;
    if (numb<0) {

        cout << "Adjon meg egy egesz szamot! Abszolut erteke: " << numb * (-1) << endl;
    } else {        
        cout <<  "Adjon meg egy egesz szamot! Abszolut erteke: " << numb << endl;
    } if (numb%2 == 0) {
        cout << "\nFele: " << numb/2 << endl;
    }
    cout << "------------------------------------------" << endl;

    //4. feladat
    cout << "4. Feladat" << endl;
    cout << "------------------------------------------" << endl
    int num1, num2;
    cout << "Adjon meg ket egesz szamot! ";
    cin >> num1 >> num2;
    if (num1 > num2) {
        cout << num1 << " - " << num2 << " = " << num1-num2 << endl;
    } if (num1 < 10 && num2 < 10) {
        cout << "" << num1 << " * " << num2 << " = " << num1*num2 << endl;
    }
    cout << "------------------------------------------" << endl;

    //5. feladat
    cout << "5. Feladat" << endl;
    cout << "------------------------------------------" << endl
    for (int i=1; i<=100; i++) {
        cout << i << " ";
    }
    cout << "------------------------------------------" << endl;

    //6. feladat
    cout << "6. Feladat" << endl;
    cout << "------------------------------------------" << endl
    int n, i;
    cout << "n erteke? ";
    cin >> n;
    for (i=1; i <= n ; i++) {
        cout << i << " ";
    }
    cout << "------------------------------------------" << endl;

    //7. feladat
    cout << "7. Feladat" << endl;
    cout << "------------------------------------------" << endl
    int n = 0, i;
    while (n <= 1) {
      cout << "n erteke? ";
      cin >> n;
    }
    if (n > 1) {
      for (i=1; i <= n ; i++) {
        cout << i << " ";
      }
    }
    cout << "------------------------------------------" << endl;

    //8. feladat
    cout << "8. Feladat" << endl;
    cout << "------------------------------------------" << endl
    int n = 0, i, sum = 0;
    while (n <= 1) {
      cout << "n erteke? ";
      cin >> n;
    }
    if (n > 1) {
      for (i=1; i <= n ; i++) {
        cout << i << " ";
        sum += i;
    }
    }
    cout << "A szamok osszege: " << sum;
    cout << "------------------------------------------" << endl;

    //9. feladat
    cout << "9. Feladat" << endl;
    cout << "------------------------------------------" << endl
    int n = 0, i;
    cout << "n erteke? ";
    cin >> n;
    if (n > 1) {
      for (i=1; i <= n ; i++) {       
        if (i%2==0) {
            cout << i << " ";
        }
      }
    }
    cout << "------------------------------------------" << endl;

    //10. feladat
    cout << "10. Feladat" << endl;
    cout << "------------------------------------------" << endl
    int a, b, i;
    cout << "Adja meg az intervallum hatarait! ";
    cin >> a >> b;
    if (a==b) {
        cout << a;
    }else if (a>b) {
        for(i=a; i>=b; i--) {
            cout  << i << " ";
        }
    } else {
        for(i=a; i<=b; i++) {
        cout << i << " "; 
        }
    }
    cout << "------------------------------------------" << endl;

    //11. feladat
    cout << "11. Feladat" << endl;
    cout << "------------------------------------------" << endl
    int n, i, f=1;
    cout << "Adja meg n erteket! ";
    cin >> n;
    if(n==0) {
        cout << n << "!" << " = " << "1";
    } else {
        for(i=1; i<=n; i++) {
        f = f*i;        
    }
    cout << n << "!" << " = " << f;
    }
    cout << "------------------------------------------" << endl;

    //12. feladat
    cout << "12. Feladat" << endl;
    cout << "------------------------------------------" << endl
    int i;
    for(i=1; i<=100; i++) {
        if(i%3==0 && i%5==0) {
            cout << "FizzBuzz ";
        } else if (i%3==0) {         
            cout << "Fizz ";  
        } else if (i%5==0) {
            cout << "Buzz ";
        } else {
            cout << i << " ";
        }
    }
    cout << "------------------------------------------" << endl;
  
    return 0;
}
