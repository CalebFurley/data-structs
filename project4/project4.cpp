#include <vector> 
#include <iostream> 
using namespace std; 

//________________________________________________ SUMMARY ________________________________________________//
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


//_______________________________________________ EXCEPTIONS ______________________________________________//
class Exception {};
class DuplicateInsertion : public Exception {};
class NotFoundException : public Exception {};

//_______________________________________________ PROTOTYPE _______________________________________________//

template <class DT> 
class MTree 
{ 
protected: 
    int M;                       // Maximum number of children per node (M way split) 
    vector<DT>* values;          // Values stored in the node (M-1 values) 
    vector<MTree*>* children;    // Pointers to child MTrees (M children) 

public: 
    MTree(int M); 
    ~MTree(); 

    bool isLeaf() const;                      // Check if the current node is a leaf 
    void splitNode();                         // Split the node if it exceeds capacity (i.e >=M) 

    MTree<DT>* findChild(const DT& value);    // Find the correct child to follow  
    MTree<DT>* search(const DT& value);       // Interal searching function.
    vector<DT>& collectValues();              // Collect values from all leaf nodes  

    void buildTree(const vector<DT>& input_values);   // Build the tree  

    bool find(DT& value);             // Find a value from the MTree
    void insert(const DT& value);     // Insert a value into the MTree
    void remove(const DT& value);     // Remove a value from the MTree 
};


//____________________________________________ IMPLEMENTATION _____________________________________________//

// Constructs a new node with M-1 values and M slots for children.
template <class DT>
MTree<DT>::MTree(int M) 
{
    this->M = M;
    this->values = new vector<DT>(M-1);
    this->children = new vector<MTree*>(M);
}

// Destructor for tree nodes.
template <class DT>
MTree<DT>::~MTree() 
{
    if ( values != nullptr ) 
    {
        delete this->values;
    }

    if ( children != nullptr ) 
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
MTree<DT>* MTree<DT>::search(const DT& value) 
{
    return nullptr;
}

// collects and returns a sorted list of the nodes in the tree.
template <class DT>
vector<DT>& MTree<DT>::collectValues() 
{
    // RETURN A SORTED LIST OF ALL LEAF NODES (the values are only stored in the leafs)
    ///////////////////////////////////////////////////////////////////////////////////

    // An inorder traversal of a tree is a sorted list <-- use this fact.
    // TODO add a return statement here. 

    //for (int i = 0; i < M; ++i) 
    //{
    //    
    //}

    // go left,
    //print first,
    // go 2nd
    // print second
    // go 3rd
    // print third
    // go last
    // print last


    return *values; //stubby.
}

// Builds tree from a given a vector of values.
template <class DT>
void MTree<DT>::buildTree(const vector<DT>& input_values) 
{
    if (input_values.size() <= M - 1) // Leaf Node, Base Case
    {
        values = new vector<DT>(input_values);
    } 
    else 
    {
        int D = input_values.size() / M; // chunks the input_values into M sections
        for (int i = 0; i < M; i++) 
        {
            // The if else statements create child nodes
            int start = D * i;
            //cout << "start: " << start << " - ";
            int end;

            if (i == M - 1) 
            {
                end = input_values.size() - 1;
                //cout << "end: " << end << endl;
            } 
            else 
            {
                end = start + D - 1;
                //cout << "end: " << end << endl;
                values->push_back(input_values[end]); // pushes the last value of each chunk into values for the internal nodes.
            }

            // Internal Node, Recursive Case
            vector<DT> child_values(input_values.begin() + start, input_values.begin() + end + 1);
            MTree<DT>* child = new MTree<DT>(M);
            child->buildTree(child_values); // calls the build tree on the newly created child
            children->push_back(child); // pushes the child to the children vector of the current node
        }
    }
}

// Checks if a node is present in the tree.
template <class DT>
bool MTree<DT>::find(DT& value) 
{
    if ( search(value) != nullptr) 
    {
        return true;
    }
    else
    {
        return false;
    }
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


//________________________________________________ TESTING ________________________________________________//
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


//______________________________________________ DEGBUG PLAN ______________________________________________//
/*DEBUG PLAN GOES HERE..*/


//_______________________________________________ LLN USAGE _______________________________________________//
/*LLM USAGE GOES HERE..*/
