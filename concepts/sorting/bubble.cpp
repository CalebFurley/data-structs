#include <iostream>
using namespace std;

int* bubbleSort(int* array, size_t size)
{
  //[7,3,4,5,1]

  //sorting
  for (int i=1; i<size; ++i)
  {
    for (int j=i+1; j>0; --j)
    {
      if (array[i] > array[j])
      {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

    //printing
    cout << "[";
    for (int i=0; i<size; ++i) 
    {
      cout << array[i] << ", ";
    }
    cout << "]" << endl;
  }

  return array;
}

int main(int argx, char** argv)
{
  //create intitial array
  int array[] = {6,4,9,3,1,2,7,8,5};
  const int SIZE = 9;

  //sort and asign to heap array
  int* sortedArray = bubbleSort(array, SIZE);
  sortedArray = nullptr;

  return 0;
}