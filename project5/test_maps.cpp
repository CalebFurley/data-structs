#include <unordered_map> //unordere map with O(1) lookup based on keys
#include <map> //red black tree with ordered keys O(log(n))
#include <iterator> //use to get an iterator
#include <algorithm> //use for sort()
#include <iostream> //use for io operations
using namespace std;

/**
 * This script is for testing out the two types of maps in the STL.
 * 
 * The unordered_map will be used to store "String Keys" within the 
 * project and an "Integer" value that will increment every time
 * that value repeats.
 * 
 * Once all the tokens are stored, use the sort() function from the 
 * algorithm library to sort the token in descending order of their
 * frequency.
 */


int main() {
  unordered_map<string,int> myMap; //maps string keys to integer values
  myMap["Caleb"] = 23;
  myMap["Harry"] = 2;
  myMap["Ivette"] = 30;
  /* cout << "Harry = " << myMap["Harry"] << endl; */

  map<int,string> myMap2;
  myMap2[23] = "Caleb";
  myMap2[2] = "Harry";
  myMap2[30] = "Ivette";

  cout << "Tree[30] = " << myMap2[30] << endl;

  return 0;
}