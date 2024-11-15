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

  Quehacer:
    --------------
    1. search()
    2. findChild()
    3. find()
    --------------
    4. splitNode()
    5. insert()
    6. remove()
    --------------
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
    vector<DT> values;          // Values stored in the node (M-1 values) 

public: 
    vector<MTree*> children;    // Pointers to child MTrees (M children) 

    MTree(int M); 
    ~MTree(); 

    bool isLeaf() const;                      // Check if the current node is a leaf 
    void splitNode();                         // Split the node if it exceeds capacity (i.e >=M) 

    MTree<DT>* findChild(const DT& value);    // Find the correct child to follow  
    MTree<DT>* search(const DT& value);       // Interal searching function.
    vector<DT> collectValues();              // Collect values from all leaf nodes  

    void buildTree(const vector<DT>& inputValues);   // Build the tree  

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
}

// Destructor for tree nodes.
template <class DT>
MTree<DT>::~MTree() 
{
    if ( !values.empty() ) 
    {
        values.clear();
    }

    if ( !children.empty() ) 
    {
        children.clear();
    }
}

// Checks if the current node is a leaf.
template <class DT>
bool MTree<DT>::isLeaf() const 
{
    if ( children.empty() ) 
    {
        return true;
    }
    else
    {
        return false;
    }
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
vector<DT> MTree<DT>::collectValues() // according to GPT, modern c++ compilers optimize this return by value.
{
    // Vector to store collected values from the leaf nodes.
    vector<int> collectedValues;  

    // If the current node is a leaf, collect its values.
    if (this->isLeaf()) 
    {
        //cout << "In a leaf node.\n";
        // Loop through and collect the values from this leaf.
        for (int i = 0; i < M-1; ++i) 
        {
            if (this->values[i] != 0)
            {
                collectedValues.push_back( this->values[i] );
            }
        }
    }
    else 
    {
        //cout << "In an internal node.\n";
        // If not a leaf, we need to recursively collect values from children
        for (int i = 0; i < M; ++i) 
        {
            // Recursively collect values from the child nodes
            if (this->children[i] != nullptr) 
            {
                vector<DT> childValues = this->children[i]->collectValues();
                collectedValues.insert(collectedValues.end(), childValues.begin(), childValues.end());
            }
            //else cout << "Child is nullptr" << endl;
        }
    }

    return collectedValues;
}

// Builds tree from a given a vector of values.
template <class DT>
void MTree<DT>::buildTree(const vector<DT>& inputValues) 
{
    if (inputValues.size() <= M - 1) // Leaf Node, Base Case
    {
        values = inputValues;
    } 
    else 
    {
        int D = inputValues.size() / M; // chunks the input_values into M sections
        for (int i = 0; i < M; i++) 
        {
            // The if else statements create child nodes
            int start = D * i;
            //cout << "start: " << start << " - ";
            int end;

            if (i == M - 1) 
            {
                end = inputValues.size() - 1;
                //cout << "end: " << end << endl;
            } 
            else 
            {
                end = start + D - 1;
                //cout << "end: " << end << endl;
                values.push_back(inputValues[end]); // pushes the last value of each chunk into values for the internal nodes.
            }

            // Internal Node, Recursive Case
            vector<DT> child_values(inputValues.begin() + start, inputValues.begin() + end + 1);
            MTree<DT>* child = new MTree<DT>(M);
            child->buildTree(child_values); // calls the build tree on the newly created child
            children.push_back(child); // pushes the child to the children vector of the current node
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

    int n;              // Count of numbers to stores in initial tree.
    int MValue;         // M value for the tree (number of children) (M-1 values in each node)
    int numCommands;    // Number of commands in the program.
    char command;       // Variable to store the type of each command.
    int value;          // Variable to store the values associated with each command.
    
    // Read the size of the values array and define the array.
    cin >> n;
    vector<int> mySortedValues(n);
 
    // Read numbers from input and store in a sorted array.
    for (int i = 0; i < n; ++i) 
    {
        cin >> value;
        mySortedValues[i] = value;
    } 

    // Read in the MValue and create the root of the tree.
    cin >> MValue;
    MTree<int>* myTree = new MTree<int>(MValue);

    // Build the intitial tree.
    myTree->buildTree(mySortedValues);

    // Read in the number of commands.
    cin >> numCommands;

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
                vector<int> myValues = myTree->collectValues();
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

    // Print out the final list.
    cout << "Final list: ";
    mySortedValues = myTree->collectValues();
    for (int i = 0; i < mySortedValues.size(); ++i) 
    {
        cout << mySortedValues[i] << " ";
    }
    cout << endl;

    // End of program
    delete myTree; 
    return 0;
}


//______________________________________________ DEGBUG PLAN ______________________________________________//
/*DEBUG PLAN GOES HERE..*/


//_______________________________________________ LLN USAGE _______________________________________________//
/*LLM USAGE GOES HERE..*/
