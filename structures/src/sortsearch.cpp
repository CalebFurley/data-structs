#include <iostream>
using std::cout;
using std::endl;

//Time:O(n^2);Space:O(1);
void insertionSort(int* array, int size) {
  for (int i=0; i<size; ++i) {
    int min = array[i];
    int j = i - 1;
    while (j >= 0 && min < array[j]) {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = min;
  }
}

//Time:O(logn);Space:O(1);
int binarySearchRecur(int* array, int low, int high, int key) {
  if (low > high) return -1;
  else {
    int mid = (low+high)/2;
    if (key == array[mid]) return mid;
    else if (key < array[mid])
      return binarySearchRecur(array,low,mid-1,key);
    else
      return binarySearchRecur(array,mid+1,high,key);
  }
}

//Time:O(logn);Space:O(1);
int binarySearchIter(int* array, int size, int key) { 
  int low = 0;
  int high = size-1;
  while(low <= high) {
    int mid = (low+high)/2;
    if(key == array[mid]) return mid;
    else if(key < array[mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return -1;
}

//merge(){}
//mergeSort(){}
//bucketSort(){}

int main() {

  int array[] = {7,2,9,5,3,6,1,4,8};
  int size = 9;

  cout << "InsertionSort = ";
  insertionSort(array, size);
  for (int i=0; i<size; ++i) cout << array[i] << " ";
  cout << endl;

  cout << "BinarySearchRecur = ";
  cout << binarySearchRecur(array,0,size-1,3) << endl;
  
  cout << "BinarySearchIter = ";
  cout << binarySearchIter(array,size,3) << endl;

  return 0;
}
