#include <iostream>

void qsort(int arr[], int start, int end){

    if (start<end){        
        int s=start;
        int e=end;
        int pivot = arr[(s+e)/2];
        while (s<=e){
           while (arr[s]<pivot){
                s=s+1;                
           }
           while (arr[e] > pivot){
                e=e-1;
           }
           if (s<=e) {
                swap(arr[s], arr[e]);
                s = s+1;
                e = e-1;
           };
        }
        qsort(arr, start, e);
        qsort(arr, s, end);
    }
}

int main() {


  cout << "--------------------------------------------------------" << endl;
  int numbers[] = { 7, 3, 8, 5, 1, 6, 4, 2 };
  int n = sizeof(numbers)/sizeof(numbers[0]);
  qsort(numbers, 0, n-1);
  print(numbers, n);
  cout << "--------------------------------------------------------" << endl;
  
    return 0;
  }
