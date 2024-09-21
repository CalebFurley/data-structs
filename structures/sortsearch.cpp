#include <iostream>

//Selection Sort: O(n^2)
void selectionSort(int* array, size_t size) {

    /*
        Time = O(n^2), double loops.
        Space = O(1), in place.

        This is the easiest algorithm to implement.

        It starts at index=0, set that value to min,
        then runs through the rest of the array and 
        checks all values to see if its truly the min.

        Whatever the min is on that run, AFTER checking
        all the other values, is swapped with the value at
        i, then i is increased and the process is ran again.
    */

    //write here..

/*    
       for (int outerIndex = 0; outerIndex < size; ++outerIndex) {

        int minIndex = outerIndex;
        
        for (int innerIndex = outerIndex + 1; innerIndex < size; ++innerIndex) {

            if (array[innerIndex] < array[minIndex]) {
                minIndex = innerIndex;
            }
        }

        //perform the swap
        int tempInteger = array[outerIndex];
        array[outerIndex] = array[minIndex];
        array[minIndex] = tempInteger;
    }
*/    
}

//Insertion Sort: O(n^2)
void insertionSort(int* array, size_t size) {
    
    /*
        Time = O(n^2), double loops.
        Space = O(1), in place.

        This sorting algorithm starts at i=1 and checks
        values going left to see if its less than the values at i.

        The algorithm stores stores the value at the outerIndex as
        a minimum tempInteger, and sets the innerIndex to outerIndex-1
        to get ready for comparing left in the array.

        If the value is not less, then it pushes the array to the right
        in order to make space to put the tempMin value where it belongs.

        If the value at j is ever less than the value at i, then the value at
        j+1 gets set to i, since that is the correct location for the point.
    */

    //write here..

    //this the alg that checks left
    for (int outerIndex = 0; outerIndex < size; ++outerIndex) {

        int minInt = array[outerIndex];
        int innerIndex = outerIndex - 1;

        while (innerIndex >= 0 && minInt < array[innerIndex]) {
            
            array[innerIndex + 1] = array[innerIndex]; //pushing values right
            innerIndex--; //decrement (going left)
        }

        array[innerIndex + 1] = minInt;

    }

/*
    for (int outerIndex = 1; outerIndex < size; ++outerIndex) {

        int minInteger = array[outerIndex];
        int innerIndex = outerIndex - 1;

        while (innerIndex >= 0 && minInteger < array[innerIndex]) {

            array[innerIndex + 1] = array[innerIndex]; //push array right
            innerIndex--;
        }

        array[innerIndex + 1] = minInteger; //once spot is found that is smaller, step one to right, and place tempMin value.
    }
*/
}


//Bucket Sort: O(n^2)
void bucketSort(int* array, size_t size, int maxVal) {

    /*
        Time = O(n^2), two O(n) loops, one to breakdown, one to build-up.
        Space = O(M), linear space (makes a copy array)

        The bucket sort algorithm creates a bucketArray that is the lengh of
        the max value of the array to sort.

        Next, the algorithm runs through the new array, and increments the index of
        that array by 1, every time its index == a value in the original array.

        After the bucketArray is filled, the algorithm then runs through the bucketArray
        and runs a small while loop that adds the index(literally index number) of the bucketArray 
        into the original array, until the value in the bucketArray is 0, then steps forward.
    */

    //write here..

    //declare bucket array
    int bucketArray[maxVal+1] = {0};

    //build bucket array
    for (int arrayIndex = 0; arrayIndex < size; ++arrayIndex) {
        bucketArray[array[arrayIndex]]++;
    }

    //build oriArray back up
    for (int bucketIndex = 0; bucketIndex < maxVal+1; ++bucketIndex) {

        int arrayIndex = 0;

        while (bucketArray[bucketIndex] > 0) {
            array[arrayIndex] = bucketIndex;
            arrayIndex++;
            bucketArray[bucketIndex]--;
        }
    }

/*
    int bucketArray[maxVal + 1] = {0}; //init bucketArray with 0s.

    //fill-up the bucketArray
    for (int arrayIndex = 0; arrayIndex < size; ++arrayIndex) {

        bucketArray[array[arrayIndex]]++; //increment the index of the value inside the original array
    }

    //fill-up the originalArray 
    int arrayIndex = 0;
    for (int bucketIndex = 0; bucketIndex < maxVal + 1; ++bucketIndex) {

        while (bucketArray[bucketIndex] > 0) {
            array[arrayIndex] = bucketIndex;        //set array[itsIndex] = bucket arrays index
            arrayIndex++;                           //increase the original arrays index
            bucketArray[bucketIndex]--;             //decrease the count held in the bucket array
        }
    }
*/
}

//Merging Arrays: O(n+m)
void merge(int* arrayA, size_t sizeA, int* arrayB, size_t sizeB, int* arrayC, size_t sizeC) {
    
    /*
        Time = O(n+m), linear time for both arrays.
        Space = O(n+m), linear, since a third copy array is made.

        ArrayA and ArrayB are the smaller arrays, where arrayC is the array 
        larger array that will be built from the smaller two.

        To merge them (unsortingly) we will run through and compare the values
        of both whilst counting up on the third array until one of the smaller
        arrays have been completely copied over.

        Then we will copy both the arrays over on their own(but note since one array
        will have already been copied, technically its while loop will just get skipped
        over) effectly just copying the remaining array into the third.
    */

    //write here..

/*
    //check if arrayC is large enough to hold arrayA + arrayB
    if (sizeA + sizeB > sizeC) {
        std::cerr << "ArrayC is not large enough to hold both arrays." << std::endl;
        return;
    }

    //create index counters for the three arrays
    size_t indexA = 0;
    size_t indexB = 0;
    size_t indexC = 0;

    //copying both
    while (indexA < sizeA && indexB < sizeB) {

        if (arrayA[indexA] < arrayB[indexB]) {
            arrayC[indexC] = arrayA[indexA];
            indexA++;
            indexC++;
        }
        else {
            arrayC[indexC] = arrayB[indexB];
            indexB++;
            indexC++;
        }
    }

    //copy remaining of A
    while (indexA < sizeA) {
        arrayC[indexC] = arrayA[indexA];
        indexA++;
        indexC++;
    }

    //copy remaining of B
    while (indexB < sizeB) {
        arrayC[indexC] = arrayB[indexB];
        indexB++;
        indexC++;
    }
*/
}

//Merging for merge sort: O(?)
void merge(int* array, int low, int mid, int high) {

    /*
        Time = O(?)
        Space = O(?)

        This is for merging together the broken down elements
        from the mergesort algorithm.
    */

    //write here..

}

//Merge Sort: O(nlog(n))
void mergeSort(int* array, int low, int high) {
    
    /*
        Time = O(nlog(n)), linear amount of log(n) algs???
        Space = O(n), copies to new array

        Breaks down the array (through halving) until there is only 1 element, 
        then starts building it back up whilst sorting it along the way.
    */

    //write here..

/*
    if (low < high) { //if low >= high, then theres only 1 element, so stop breakdown
        
        int mid = (low + high) / 2; //set middle index

        mergeSort(array, low, mid); //breakdown going-left
        mergeSort(array, mid+1, high); //breakdown going-right
        merge(array, low, mid, high); //merge-up the broken-pieces
    }
*/
}

//Linear Search: O(n)
int linearSearch(int* array, size_t size, int key) {

    /*
        Time = O(n), linear
        Space = O(1), constant

        Simple searching algorithm, just steps
        through each element in the array and returns
        when it finds the correct value.
    */

   //write here..

/*
    for (int index = 0; index < size; ++index) {
        
        if (array[index] == key) {
            return index;
        }
    }


    return -1;
*/
}

//Binary Search Recursive: O(log(n))
int binarySearch(int* array, int low, int high, int key) {
    
    /*
        Time = O(log(n)), since keeps halving the array each step the graph flattens out.
        Space = O(1), its a searching algorithm, doesn't affect space.

        Binary Search Recursive is binary search which calls upons itself
        instead of looping like the iterative version.

        Binary search starts in the middle of the array, then tests if
        the key to search for is equal to the value in the middle of the array,
        if so it returns that index and the algprithm is complete.
        
        If it is not equal, then it checks if the key is less than or greater than
        the value at the middle index it was inserted at.
            If the value less than the key, then the algorithm sets the lower bound
            to be middle plus one, and calls itself again to search the upper half.
            If the value is greater than the key, then is sets the upper bound to be the middle
            index minus one. and searching lower half.
        
        Don't forget on this recursive version to return each time the function is called,
        this way the found element can be passed back up and returned in the first called
        version of the algortihm to return to the user from where they called it.
    */

    //write here..

/*
    //to avoid overrunning the array
    if (low > high) {
        return -1;//the value was never found.
    }

    int mid = (low + high) / 2;

    if (array[mid] == key) {
        return mid;//return index of found key
    }
    else {

        if (key > array[mid]) {    
            low = mid + 1; 
            return binarySearch(array, low, high, key);
        }
        else {
            high = mid - 1;
            return binarySearch(array, low, high, key);
        }
    }
*/
}

//Binary Search Iterative: O(log(n))
int binarySearch(int* array, size_t size, int key) {

    /*
        Time = O(log(n))
        Space = O(1), constanst since is just searching

        The iterative version of Binary Search uses loops instead
        of recursion to achieve the goal of finding the key.

        First the algorithms inserts into the middle of the array
        and checks if that value is equal to the key. If so it returns the
        index, if not:
            it checks if the key < array[mid] if so, high = mid - 1, mid = (low+high) / 2;
            it checks if the key > array[mid] if so, low = mid + 1, mid = (low+high) / 2;
        
        Using the above loop, the algorithms keeps halving the array until either:
            the key is found, and its index is returned.
            or if(low > high) returns -1, because the key was never found.
    */

    //write here..

/*
    int low = 0;
    int high = size - 1;
    
    while (low <= high) {
        int mid = (low + high) / 2; //set mid

        if (array[mid] == key) { //if key found, return the index
            return mid;
        }
        else {

            if (key < array[mid]) {
                //go-down
                high = mid - 1;
            }
            else {
                //go-up
                low = mid + 1;
            }
        }
    }

    return -1;//default-case, key not found

*/
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
    bucketSort(array, size, maxVal);
    std::cout << "Bucket Sort = "; printArrayHelper(array, size);  std::cout <<"\n";
    scrambleArrayHelper(array, REF_ARRAY, size);

    //test merging here..
    std::cout << "Merging test.." << std::endl;
    int arrayA[] = {4,5,2};
    int arrayB[] = {1,6,3};
    int arrayC[6] = {0};
    merge(arrayA, 3, arrayB, 3, arrayC, 6);
    std::cout << "Merge result = "; printArrayHelper(arrayC, 6); std::cout <<"\n";

    //merge sorting here..
    mergeSort(array, 0, size-1);
    std::cout << "Merge Sort = "; printArrayHelper(array, size);  std::cout <<"\n";
    scrambleArrayHelper(array, REF_ARRAY, size);

    //setting up for seaching algorithms below.
    insertionSort(array, size); //make sure the array is sorted.
    int inputKey = 0; //for sorting the key input for the searching algorithms.
    int returnIndex = 0; //for the returned index of the key when sorting.

    //binary search iterative here..
    std::cout << "Linear Search." << std::endl;
    std::cout << "Enter key to find: "; std::cin >> inputKey;
    returnIndex = binarySearch(array, size, inputKey);
    std::cout << "Found Key = " << inputKey << ", at Index = " << returnIndex << ".\n\n";

    //binary search recursive here..
    std::cout << "Binary Search Recursive." << std::endl;
    std::cout << "Enter key to find: "; std::cin >> inputKey;
    returnIndex = binarySearch(array, 0, size, inputKey);
    std::cout << "Found Key = " << inputKey << ", at Index = " << returnIndex << ".\n\n";

    //binary search iterative here..
    std::cout << "Binary Search Iterative." << std::endl;
    std::cout << "Enter key to find: "; std::cin >> inputKey;
    returnIndex = binarySearch(array, size, inputKey);
    std::cout << "Found Key = " << inputKey << ", at Index = " << returnIndex << ".\n\n";

    //end the program.
    std::cout << "End of testing program.........\n" << std::endl;
    return 0;
}
