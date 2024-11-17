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
    vector<DT> values;           // Values stored in the node (M-1 values) 
    vector<MTree*> children;     // Pointers to child MTrees (M children) 

public: 
    MTree(int M); 
    ~MTree(); 

    bool isLeaf() const;                      // Check if the current node is a leaf 
    void splitNode(MTree<DT>* parent);        // Split the node if it exceeds capacity (i.e >=M) 

    MTree<DT>* findChild(const DT& value);    // Find the correct child to follow
    MTree<DT>* search(const DT& value);       // Internal searching function.
    vector<DT> collectValues();               // Collect values from all leaf nodes  

    void buildTree(const vector<DT>& inputValues);  // Build the tree  

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
    for (MTree* child : children) 
    {
        delete child; // Safely delete child nodes
    }
    values.clear();
    children.clear(); // Clear vector
}

// Checks if the current node is a leaf.
template <class DT>
bool MTree<DT>::isLeaf() const 
{
    return children.empty();
}

// Splits a node, used for balancing the tree and promoting values to parent.
template <class DT>
void MTree<DT>::splitNode(MTree<DT>* parent) 
{
    if (values.size() < M - 1) 
        return;

    int midIndex = values.size() / 2;
    DT midValue = values[midIndex];

    MTree<DT>* rightNode = new MTree<DT>(M);

    // Move upper half of values and children to the new node
    rightNode->values.assign(values.begin() + midIndex + 1, values.end());
    values.resize(midIndex);

    if (!isLeaf()) 
    {
        rightNode->children.assign(children.begin() + midIndex + 1, children.end());
        children.resize(midIndex + 1);
    }

    if (parent) 
    {
        // Insert the middle value into the parent node
        parent->values.push_back(midValue);
        parent->children.push_back(rightNode);
        parent->splitNode(nullptr);  // Check if the parent needs to split
    }
}

// Finds the correct child to follow.
template <class DT>
MTree<DT>* MTree<DT>::findChild(const DT& value) 
{
    for (int i = 0; i < values.size(); ++i) 
    {
        if (value <= values[i]) 
            return children[i];
    }
    return children[values.size()]; // Return the last child if value is greater than all in the node.
}

// Internal Searching method, returns pointer to node if found.
template <class DT>
MTree<DT>* MTree<DT>::search(const DT& value) 
{
    if (isLeaf()) 
    {
        for (int i = 0; i < values.size(); ++i) 
        {
            if (values[i] == value)
                return this;
        }
    } 
    else 
    {
        for (int i = 0; i < values.size(); ++i) 
        {
            if (value <= values[i]) 
                return children[i]->search(value);
        }
        return children[values.size()]->search(value); // Search the last child if value is larger than all
    }
    return nullptr;
}

// Collects and returns a sorted list of values from leaf nodes.
template <class DT>
vector<DT> MTree<DT>::collectValues() 
{
    vector<DT> collectedValues;  
    if (isLeaf()) 
    {
        for (const auto& value : values) 
        {
            collectedValues.push_back(value);
        }
    } 
    else 
    {
        for (int i = 0; i < children.size(); ++i) 
        {
            vector<DT> childValues = children[i]->collectValues();
            collectedValues.insert(collectedValues.end(), childValues.begin(), childValues.end());
        }
    }
    return collectedValues;
}

// Builds tree from a vector of values.
template <class DT>
void MTree<DT>::buildTree(const vector<DT>& inputValues) 
{
    if (inputValues.size() <= M - 1) 
    {
        values = inputValues;
    } 
    else 
    {
        int D = inputValues.size() / M;
        for (int i = 0; i < M; ++i) 
        {
            int start = D * i;
            int end = (i == M - 1) ? inputValues.size() : start + D;
            
            vector<DT> child_values(inputValues.begin() + start, inputValues.begin() + end);
            MTree<DT>* child = new MTree<DT>(M);
            child->buildTree(child_values); // Recursively build the tree for the child
            children.push_back(child); // Add child to the current node
        }
    }
}

// Checks if a node is present in the tree.
template <class DT>
bool MTree<DT>::find(DT& value) 
{
    if (search(value) != nullptr) 
    {
        return true;
    }
    else
    {
        throw NotFoundException();
    }
}

// Inserts a value into the tree.
template <class DT>
void MTree<DT>::insert(const DT& value) 
{
    if (isLeaf()) 
    {
        for (const auto& v : values) 
        {
            if (v == value) 
            {
                throw DuplicateInsertion();
            }
        }

        bool inserted = false;
        for (int i = 0; i < values.size(); ++i) 
        {
            if (value < values[i]) 
            {
                values.insert(values.begin() + i, value);
                inserted = true;
                break;
            }
        }

        if (!inserted) 
        {
            values.push_back(value);
        }

        if (values.size() >= M) 
        {
            splitNode(nullptr);
        }
    } 
    else 
    {
        MTree<DT>* child = findChild(value);
        child->insert(value);

        if (child->values.size() >= M) 
        {
            splitNode(nullptr);
        }
    }
}

// Removes a node from the tree.
// Removes a node from the tree.
template <class DT>
void MTree<DT>::remove(const DT& value) 
{
    MTree<DT>* node = search(value);

    if (node == nullptr)
        throw NotFoundException();

    // Search manually for the value in the node's values
    bool found = false;
    for (int i = 0; i < node->values.size(); ++i) 
    {
        if (node->values[i] == value) 
        {
            node->values.erase(node->values.begin() + i);
            found = true;
            break;
        }
    }

    if (!found) 
    {
        throw NotFoundException();
    }

    // If the node has fewer than the minimum number of elements (underflow), handle it
    if (node->values.size() < (M / 2)) 
    {
        //handleUnderflow(node);
    }
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

    for (int i = 0; i < mySortedValues.size(); ++i) {
        for (int j = i + 1; j < mySortedValues.size(); ++j) {
            if (mySortedValues[i] == mySortedValues[j]) {
                mySortedValues.erase(mySortedValues.begin() + j);
                --j;  // Adjust the index since the vector is shifted after erase
            }
        }
    }


    for (int i = 0; i < mySortedValues.size(); ++i) 
    {
        cout << mySortedValues[i] << " ";
    }
    cout << endl;

    // End of program
    delete myTree; 
    return 0;
}
