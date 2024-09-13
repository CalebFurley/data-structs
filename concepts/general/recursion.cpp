#include <iostream>
#include <vector>
using namespace std;

int addN(int N);

int main()
{
  //recursive recursion recursing recursivly.

  int n = 5;
  cout << "N = " << n << endl;
  cout << "Sum = " << addN(n) << endl;

  return 0;
}

int addN(int N)
{
  if (N <= 1)
    return 1;

  return N + addN(N-1);
}