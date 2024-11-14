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
class MTree 
{ 
protected: 
    int M;                      // Maximum number of children per node (M+1 way split) 
    vector<DT>* values;          // Values stored in the node (M-1 values) 
    vector<MTree*>* children;    // Pointers to child MTrees (M+1 children) 

public: 
    MTree(int M); 
    ~MTree(); 

    bool isLeaf() const;                      // Check if the current node is a leaf 
    void splitNode();                         // Split the node if it exceeds capacity (i.e >=M) 
    MTree<DT>* findChild(const DT& value);    // Find the correct child to follow  
    bool search(const DT& value);             // Interal searching function.
    vector<DT>& collectValues();              // Collect values from all leaf nodes  

    void buildTree(const vector<DT>& input_values);   // Build the tree  

    bool find(DT& value);             // Find a value from the MTree
    void insert(const DT& value);     // Insert a value into the MTree
    void remove(const DT& value);     // Remove a value from the MTree 
};


//______________________________________ IMPLEMENTATION ______________________________________//

// Constructs a new node with M-1 values and M slots for children.
template <class DT>
MTree<DT>::MTree(int M) 
{
    this->M = M;
    this->values = new vector<DT>(M);
    this->children = new vector<MTree*>(M);
}

// Destructor for tree nodes.
template <class DT>
MTree<DT>::~MTree() 
{
    if (values != nullptr) 
    {
        delete this->values;
    }
    
    if (children != nullptr) 
    {
        delete this->children;
    }
}

// Checks if the current node is a leaf.
template <class DT>
bool MTree<DT>::isLeaf() const 
{
    for (int i = 0; i < M; ++i)
    {
        if (values[i] != 0)
        {
            return false;
        }
    }
    return true;
}

// Splits a node, used for balancing the tree.
template <class DT>
void MTree<DT>::splitNode() 
{
    return; 
}

// Finds the correct child to follow? <- probably for traversal??
template <class DT>
MTree<DT>* MTree<DT>::findChild(const DT& value) 
{
    return nullptr;
}

// Internally searches the tree for a node. <- should be internal??
template <class DT>
bool MTree<DT>::search(const DT& value) 
{
    return false;
}

// collects and returns a sorted list of the nodes in the tree.
template <class DT>
vector<DT>& MTree<DT>::collectValues() 
{
    // An inorder traversal of a tree is a sorted list <-- use this fact.
    // TODO add a return statement here. 
    return *values; //stubby.
}

// Builds tree from a given a vector of values.
template <class DT>
void MTree<DT>::buildTree(const vector<DT>& input_values) 
{
    if (input_values.size() <= M - 1) // If input values can fit in a single node put them in.
    {
        values = new vector<DT>(input_values);
    } 
    else 
    {
        int D = input_values.size() / M; // D is maxmimun numbers of nodes that may need to be built.
        for (int i = 0; i < M; i++) 
        {
            int start = D * i;
            cout << "start: " << start << " - ";
            int end;

            if (i == M - 1) 
            {
                end = input_values.size() - 1;
                cout << "end: " << end << endl;
            } 
            else 
            {
                end = start + D - 1;
                cout << "end: " << end << endl;
                values->push_back(input_values[end]);
            }

            vector<DT> child_values(input_values.begin() + start, input_values.begin() + end + 1);
            MTree<DT>* child = new MTree<DT>(M);
            child->buildTree(child_values);
            children->push_back(child);
        }
    }
}

// Checks if a node is present in the tree.
template <class DT>
bool MTree<DT>::find(DT& value) 
{
    return false;
}

// Inserts a value into the tree.
template <class DT>
void MTree<DT>::insert(const DT& value) 
{
    return;
}

// Removes a node from the tree.
template <class DT>
void MTree<DT>::remove(const DT& value) 
{
    return;
}


//_________________________________________ TESTING __________________________________________//
int main(int argc, char** argv) 
{
    int n; // Number of numbers in the initial sorted array
    int MValue;
    int numCommands;
    char command;
    int value;
    
    cin >> n; // Read in size and create empty sorted array.
    vector<int> mySortedValues(n);

    // Read numbers from input and add them to the sorted array.
    for (int i = 0; i < n; ++i) 
    {
        cin >> value;
        mySortedValues[i] = value;
    } 

    cin >> MValue; // Read in the MValue
    MTree<int>* myTree = new MTree<int>(MValue); // Create the root of the tree.

    myTree->buildTree(mySortedValues); // Build the intitial tree.

    cin >> numCommands; // Read the number of commands.

    /******* Process the Commands ********/
    for (int i = 0; i < numCommands; i++) 
    {
        cin >> command; // Read the command type.
        switch (command) // Switch based on command.
        {
            case 'I': // Insert
            {
                cin >> value;
                try 
                { 
                    myTree->insert(value); 
                } 
                catch (DuplicateInsertion& e) { 
                    cout << "The value = " << value << " already in the tree." << endl;
                } 
                break; 
            }  
            case 'R': // Remove  
            {  
                cin >> value; 
                try 
                { 
                    myTree->remove(value); 
                    cout << "The value = " << value << " has been removed." << endl;
                }  
                catch (NotFoundException& e) 
                { 
                    cout << "The value = " << value << " not found." << endl;
                } 
                break; 
            } 
            case 'F': // Find
            { 
                cin >> value; 
                try 
                {
                    myTree->find(value);
                    cout << "The element with value = " << value << " was found." << endl; 
                }
                catch (NotFoundException& e) 
                {
                    cout << "The element with value = " << value << " not found." << endl; 
                } 
                break; 
            } 
            case 'B': // Rebuild Tree
            {
                vector<int> myValues = myTree->collectValues(); // inOrder traverse the tree and make sorted array?
                myTree->buildTree(myValues); 
                cout << "The tree has been rebuilt." << endl;
                break; 
            } 
            default: 
            {
                cout << "Invalid command!" << endl; 
            }
        } 
    }

    // End of program
    delete myTree; 
    return 0;
}


//________________________________________ DEBUG PLAN ________________________________________//
/*DEBUG PLAN GOES HERE..*/


//________________________________________ LLM USAGE _________________________________________//
/*LLM USAGE GOES HERE..*/
