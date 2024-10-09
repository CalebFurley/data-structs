#include <iostream>
#include "exceptions.h"
using namespace std;


int addN(int N) {
  if (N == 0) return 0;
  else return N + addN(N-1);
}

int factorial(int N) {
  if (N <= 1) return 1;
  else return N * factorial(N-1);
}

int fibonacci(int N) {
  if (N <= 2) return 1;
  else return fibonacci(N-1) + fibonacci(N-2);
}

void reverseStr(const char* str, int length) {
  if (length < 0) return;
  else {
    cout << str[length];
    reverseStr(str, length-1);
  }
}

int maxInt(const int* Arr, int L, int R) {
  
  if (L == R) return Arr[L];
  else {
    int M = (L + R) / 2;
    int maxR = maxInt(Arr, M+1, R);
    int maxL = maxInt(Arr, L, M);

    if (maxR > maxL) return maxR;
    else return maxL;
  }
}

int main() {
  cout << addN(5) << endl;
  cout << factorial(4) << endl;
  cout << fibonacci(6) << endl;
  reverseStr("apple", 5);

  cout << endl;

  int arr[6] = {5,11,9,2,7,4};
    //sometimes given addys with existing info.
  cout << maxInt(arr, 0, 6) << endl;
 
  return 0;
}
