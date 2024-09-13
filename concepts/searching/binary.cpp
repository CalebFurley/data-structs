#include <iostream>
using namespace std;

int binarySearch(int array[], size_t size, int key)
{
  int low = 0;
  int high = size-1;

  int middle = (low + high) / 2;

  if (middle == key) {
    array[middle];
  }
  else { //needs fixing


  //write it recursivly!!!!!

  //if(low < high) binarysearch(mid+1)



    while (low <= high)
    {
      int middle = low + (high - low) / 2; //fancy way to find midpoint without int value overflow
      int value = array[middle];
  
      cout << "Middle = " << middle << endl;

      if (value < key)
        low = middle + 1;
      else if (value > key)
        high = middle - 1;
      else
        return middle;
    }
  }

  return -1;
}

int main(int argx, char** argv)
{
  int array[] = {1,2,3,4,5,6,7,8,9};
  int size = 9;
  int key = 8;

  int indexFound = binarySearch(array, size, key);

  cout << "Found Key (" << key << ") at index = " << indexFound << endl;
  return 0;
}