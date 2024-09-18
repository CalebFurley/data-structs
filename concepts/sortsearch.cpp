#include <iostream>

//Selection Sort: O(n^2)
void selectionSort(int* array, size_t size) {
    for (int i=0; i<size; ++i) {
        int minIndex = i;
        for (int j=i+1; j<size; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        
        int tempInt = array[i];
        array[i] = array[minIndex];
        array[minIndex] = tempInt;
    }
}

//Insertion Sort: O(n^2)
void insertionSort(int* array, size_t size) {
    for (int i=1; i<size; ++i) {
        int temp = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > temp) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}

//Bucket Sort: O(?)
int* bucketSort(int* array, size_t size, int maxVal) {

    int* bucketArray = new int[maxVal];

    for (int i=0; i<size; ++i) {

    }

    return bucketArray;
}

//Merging Arrays: O(n+m)
void merge(int* leftArray, int* rightArray, int* array) {

}

//Merge Sort: O(nlog(n))
void mergeSort(int* array, size_t size) {
    //todo
}

//Linear Search: O(n)
int linearSearch(int* array, size_t size) {
    return -1;//todo
}

//Binary Search: O(log(n))
int binarySearch(int* array, int low, int high, int key) {
    
    if (low > high) { //default-case
        return -1;
    }
    else {
        int mid = (low + high)/2;

        if (array[mid] == key)
            return mid;
        
        if (array[mid] < key)
            return binarySearch(array, mid+1, high, key);
        else   
            return binarySearch(array, low, mid-1, key);
    }
}

void scrambleArrayHelper(int* array, const int* reference, size_t size) {
    for (int i=0; i<size; ++i) {
        array[i] = reference[i];
    }
}

void printArrayHelper(int* array, size_t size) {
    std::cout << "[";
    for (int i=0; i<size-1; ++i) {
        std::cout << array[i] << ", ";
    }
    std::cout << array[size-1] << "]" << std::endl;
}

//Main method for testing
int main(int argc, char** argv) {

    //setup array and reference array
    size_t size = 20;
    int maxVal = 99;
    const int REF_ARRAY[] = {76,34,12,91,34,26,12,84,21,68,3,54,23,35,79,99,1,42,8,10};
    int array[size];
    scrambleArrayHelper(array, REF_ARRAY, size);

    //print array's original values
    std::cout << "\nOriginal = "; printArrayHelper(array, size); std::cout <<"\n";

    //selection sorting here..
    selectionSort(array, size);
    std::cout << "Selection Sort = "; printArrayHelper(array, size);  std::cout <<"\n";
    scrambleArrayHelper(array, REF_ARRAY, size);

    //insertion sorting here..
    insertionSort(array, size);
    std::cout << "Insertion Sort = "; printArrayHelper(array, size);  std::cout <<"\n";
    scrambleArrayHelper(array, REF_ARRAY, size);

    //bucket sorting here..
    int* bucketArray = bucketSort(array, size, maxVal);
    std::cout << "Bucket Sort = "; printArrayHelper(array, size);  std::cout <<"\n";
    scrambleArrayHelper(array, REF_ARRAY, size);

    //merge sorting here..
    mergeSort(array, size);
    std::cout << "Merge Sort = "; printArrayHelper(array, size);  std::cout <<"\n";
    scrambleArrayHelper(array, REF_ARRAY, size);

    delete[] bucketArray;
    return 0;
}
