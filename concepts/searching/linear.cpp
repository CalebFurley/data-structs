#include <iostream>
using namespace std;

int linearSearch(int array[], size_t size, int key)
{
  for(int i=0; i<size; ++i)
  {
    if(array[i] == key)
    {
      return i;
    }
  }
  return -1;
}

int main(int argx, char** argv)
{
  int array[] = {6,4,9,6,3,1,2,7,8};
  int size = 9;
  int key = 1;

  cout << "Found at Index = " << linearSearch(array, size, key) << endl;
  return 0;
}