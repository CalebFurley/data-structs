#include <iostream>

int main()
{
  int* someArray;
  int someArray_Length = 0;
  *someArray = 1; someArray_Length += 1;
  *(someArray+1) = 2; someArray_Length += 1;
  
  std::cout << *someArray << std::endl;
  std::cout << *(someArray+1) << std::endl;

}