#include <vector> 
#include <iostream> 
using namespace std; 

//_________________________________________ SUMMARY __________________________________________//
/*
  Summary:
    This file is for Data Structures Project 4. The file follows the structure
    listed immediately below.

  Organization:
    1. Summary
    2. Exceptions
    3. Prototype
    4. Implementation
    5. Testing
    6. Debug Plan
    7. LLM Usage
*/

//________________________________________ EXCEPTIONS ________________________________________//
class Exception {};
class DuplicateInsertion : public Exception {};
class NotFoundException : public Exception {};

//________________________________________ PROTOTYPE _________________________________________//
template <class DT> 
class MTree { 
protected: 
  int M;                      // Maximum number of children per node (M+1 way split) 
  vector<DT> values;          // Values stored in the node (M-1 values) 
  vector<MTree*> children;    // Pointers to child MTrees (M+1 children) 

public: 
  MTree(int M); 
  ~MTree(); 

  bool isLeaf() const;                      // Check if the current node is a leaf 
  void splitNode();                         // Split the node if it exceeds capacity (i.e >=M) 
  MTree<DT>* findChild(const DT& value);    // Find the correct child to follow  
  bool search(const DT& value);             // Internal searching function.
  vector<DT>& collectValues();              // Collect values from all leaf nodes  

  void buildTree(const vector<DT>& input_values);   // Build the tree  

  bool find(DT& value);             // Find a value from the MTree
  void insert(const DT& value);     // Insert a value into the MTree
  void remove(const DT& value);     // Delete a value from the MTree 

};

//______________________________________ IMPLEMENTATION ______________________________________//
template <class DT>
MTree<DT>::MTree(int M) {
}

template <class DT>
MTree<DT>::~MTree() {
}

template <class DT>
bool MTree<DT>::isLeaf() const {
  return false;
}

template <class DT>
void MTree<DT>::insert(const DT &value) {
}

template <class DT>
void MTree<DT>::splitNode() {
}

template <class DT>
MTree<DT>* MTree<DT>::findChild(const DT& value) {
  return nullptr;
}

template <class DT>
bool MTree<DT>::search(const DT &value) {
  return false;
}

template <class DT>
void MTree<DT>::remove(const DT &value) {
}

template <class DT>
void MTree<DT>::buildTree(const vector<DT> &input_values) {
  // TODO: THIS IS THE FIRST METHOD THAT NEEDS TO BE BUILT AS IT IS CALLED FROM THE TOP OF MAIN()
  // Build the tree /******************************************** */ /// TODO WORKING HERE ///
  // call to function is on like 124 down in main().
}

template <class DT>
vector<DT>& MTree<DT>::collectValues() {
  // TODO add a return statement here. 
}

template <class DT>
bool MTree<DT>::find(DT &value) {
  return false;
}

//_________________________________________ TESTING __________________________________________//
int main(int argc, char** argv) {
  int n; // number of numbers in the initial sorted array
  int MValue;
  int numCommands;
  char command;
  int value;
  
  cin >> n; // read in size and create empty sorted array.
  vector<int> mySortedValues(n);

  // read numbers from input and add them to the sorted array.
  for (int i = 0; i < n; ++i) {
    cin >> value;
    mySortedValues[i] = value;
  } 

  // get the M value (number of nodes in the tree)
  cin >> MValue;
  MTree<int> *myTree = new MTree<int>(MValue);

  // build the tree
  myTree->buildTree(mySortedValues);

  cin >> numCommands; // Read the number of commands

  /******* Process the Commands ********/
  for (int i = 0; i < numCommands; i++) {
    cin >> command; // Read the command type

    // based on command type, perform action:
    switch (command) {
      case 'I': { // Insert
        cin >> value;
        try { 
          myTree->insert(value); 
        } catch (DuplicateInsertion& e) { 
          cout << "The value = " << value << " already in the tree." << endl;
        } 
        break; 
      }  
      case 'R': {  // Remove  
        cin >> value; 
        try { 
          myTree->remove(value); 
          cout << "The value = " << value << " has been removed." << endl;
        }  
        catch (NotFoundException& e) { 
          cout << "The value = " << value << " not found." << endl;
        } 
        break; 
      } 
      case 'F': {  // Find  
        cin >> value; 
        try {
          myTree->find(value);
          cout << "The element with value = " << value << " was found." << endl; 
        }
        catch (NotFoundException& e) {
          cout << "The element with value = " << value << " not found." << endl; 
        } 
        break; 
      } 

      case 'B': {  // Rebuild Tree 
        vector<int> myValues = myTree->collectValues(); // inOrder traverse the tree and make sorted array?
        myTree->buildTree(myValues); 
        cout << "The tree has been rebuilt." << endl;
        break; 
      } 

      default: {
        cout << "Invalid command!" << endl; 
      }
    } 
  }

  //end of program
  delete myTree; 
  return 0;
}

//________________________________________ DEBUG PLAN ________________________________________//
/*DEBUG PLAN GOES HERE..*/

//________________________________________ LLM USAGE _________________________________________//
/*LLM USAGE GOES HERE..*/
