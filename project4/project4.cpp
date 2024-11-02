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
  int M;                        // Maximum number of children per node (M+1 way split) 
  vector<DT> values;            // Values stored in the node (M-1 values) 
  vector<MTree*> children;      // Pointers to child MTrees (M+1 children) 

public: 
  MTree(int M); 
  ~MTree(); 

  bool isLeaf() const;                        // Check if the current node is a leaf 
  void insert(const DT& value);               // Insert a value into the MTree 
  void splitNode();                           // Split the node if it exceeds capacity (i.e >=M) 
  MTree* findChild(const DT& value);          // Find the correct child to follow  
  bool search(const DT& value);               // Search for a value in the MTree 
  void remove(const DT& value);               // Delete a value from the MTree 
  void buildTree(vector<DT>& input_values);   // Build the tree  
  vector<DT>& collectValues();                // Collect values from all leaf nodes  
  bool find (DT& value); 
};

//______________________________________ IMPLEMENTATION ______________________________________//
/*CLASS IMPLEMENTATION GOES HERE..*/

//_________________________________________ TESTING __________________________________________//
int main() { 
  int n; // number of numbers in the initial sorted array 
  int MValue; 
  int numCommands; 
  char command; 
  int value; 

  vector<int> mySortedValues(n); 

  //read n numbers from the input and add them to the vector mySortedValues 

  //Get the M value 
  cin >> MValue; 
  MTree<int>* myTree = new MTree<int>(MValue); 

  //Build the tree 
  (*myTree).buildTree (mySortedValues); 

  cin >> numCommands;  // Read the number of commands 


  /************** Read each command Process ***************/

  for (int i = 0; i < numCommands; i++) { 
    cin >> command;  // Read the command type 

    switch (command) { 
      case 'I': {  // Insert 
        cin >> value; 
        try { 
          myTree->insert(value); 
        }
        catch (DuplicateInsertion& e) { 
          cout << "The value = " << value << " already in the tree.";
          cout << endl; 
        } 
        break; 
      } 
      case 'R': {  // Remove  
        cin >> value; 
        try { 
          myTree->remove(value); 
        }  
        catch (NotFoundException& e) { 
          cout << "The value = " << value << " not found.";
        } 
        break; 
      } 

      case 'F': {  // Find  
        cin >> value; 
        if ( myTree->find(value) ) 
          cout << "The element with value = " << value << " was found."; 
        else 
          cout << "The element with value = " << value << " not found."; 
        cout << endl; 
        break; 
      } 

      case 'B': {  // Rebuild Tree 
        vector<int> myValues = myTree->collectValues(); 
        myTree->buildTree (myValues); 
        break; 
      } 

      default: 
        cout << "Invalid command!" << endl; 
    } 
  }

  delete myTree; 
  return 0; 
}

//________________________________________ DEBUG PLAN ________________________________________//
/*DEBUG PLAN GOES HERE..*/

//________________________________________ LLM USAGE _________________________________________//
/*LLM USAGE GOES HERE..*/
