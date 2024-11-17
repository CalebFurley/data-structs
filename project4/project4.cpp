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
    vector<DT> values;          // Values stored in the node (M-1 values) 
    vector<MTree*> children;    // Pointers to child MTrees (M children) 

public: 
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
    vector<int> marked;
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
        child = nullptr; // Nullify to avoid dangling pointers
    }
    values.clear();
    children.clear(); // Clear vector
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

// Split a node, used for balancing the tree.
template <class DT>
void MTree<DT>::splitNode() 
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
}



// Finds the correct child to follow
template <class DT>
MTree<DT>* MTree<DT>::findChild(const DT& value) 
{
    // this method is unused, I loop over the children and
    // traverse in each method forsearch() for simplicity. using this
    // method would complicate stuff too much...
    return nullptr;
}

// Internal Searching method, returns pointer to node if found.
template <class DT>
MTree<DT>* MTree<DT>::search(const DT& value) 
{
    // If the node is a leaf, then check its values and return this or null.
    if ( this->isLeaf() )
    {
        //cout << "\nSearching leaf: ";
        for (int i = 0; i < values.size(); ++i)
        {
            if (values[i] == value)
            {
                //cout << values[i] << " ";
                return this;
            }
        }
    }
    else // if the node is an internal, check against values, and traverse.
    {
        for (int i = 0; i < values.size(); ++i)
        {
            if (value <= values[i] && values[i] != 0) 
            {
                //cout << values[i] << " ";
                return children[i]->search(value);
            }
        }
        return children[values.size()]->search(value); // if its the largest value in node, then search that direction.
    }
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
        //cout << "\nIn an internal node.\n";
        // If not a leaf, we need to recursively collect values from children
        for (int i = 0; i < M; ++i) 
        {
            //cout << this->values[i] << " ";
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
            int start = D * i;
            int end;

            if (i == M - 1) 
            {
                end = inputValues.size() - 1;
            } 
            else 
            {
                end = start + D - 1;
                // Check if the value already exists in the values vector to prevent duplicates
                DT valueToAdd = inputValues[end];
                bool alreadyExists = false;
                for (DT val : values)
                {
                    if (valueToAdd == val)
                        alreadyExists = true;
                }
                if (alreadyExists == false)
                    values.push_back(valueToAdd);
            }

            // Internal Node, Recursive Case
            vector<DT> child_values(inputValues.begin() + start, inputValues.begin() + end + 1);
            MTree<DT>* child = new MTree<DT>(M);
            child->buildTree(child_values); // Recursively build the tree for the child
            children.push_back(child); // Add the child to the children vector of the current node
        }
    }
}


// Checks if a node is present in the tree.
template <class DT>
bool MTree<DT>::find(DT& value) 
{
    if ( search(value) != nullptr) 
    {
        for (auto v : marked)
        {
            if (value == v) {
                throw NotFoundException();
                return false;
            }
        }
        return true;
    }
    else
    {
        throw NotFoundException();
        return false;
    }
}

// Inserts a value into the tree.
// Inserts a value into the tree.
template <class DT>
void MTree<DT>::insert(const DT& value) 
{
    // First, search the entire tree for duplicates.
    if (search(value) != nullptr) {
        throw DuplicateInsertion();         // This now catches duplicates across the entire tree.
    }

    // If the current node is a leaf
    if (isLeaf()) 
    {
        // Check if the value already exists in the node
        for (const auto& v : values) 
        {
            if (v == value) 
            {
                throw DuplicateInsertion(); // Avoid insertion of duplicates in the current node
            }
        }

        // Add the value to the node in sorted order (manually sort since no `<algorithm>`)
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

        // If not inserted, add it to the end
        if (!inserted) 
        {
            values.push_back(value);
        }

        // Split the node if it overflows
        if (values.size() >= M) 
        {
            splitNode(); // Splitting will promote mid-value to parent
        }
    } 
    else 
    {
        // If not a leaf, find the correct child to insert into
        int i = 0;
        while (i < values.size() && value > values[i]) 
        {
            ++i;
        }

        // Insert value into the selected child node
        children[i]->insert(value);

        // After inserting into the child, check if the child overflows and splits
        if (children[i]->values.size() >= M) 
        {
            splitNode(); // Splitting may require promotion of the mid-value
        }
    }
}



// Removes a node from the tree.
template <class DT>
void MTree<DT>::remove(const DT& value) 
{

    vector<int> vals = this->collectValues();
    for (auto v : vals) {
        if (v == value) {
            for (auto a : marked) {
                if (a == value)
                    throw NotFoundException();
            }
            v = 0;
            marked.push_back(value);
            return;
        }
    }cout << endl;

    MTree<DT>* node = search(value);

    if (node == nullptr)
        throw NotFoundException();
    
    for (int i = 0; i < node->values.size(); ++i)
    {
        if (value == node->values[i])
        {
            node->values[i] = 0; // Removes the element

        }
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
    vector<int> finalValues = myTree->collectValues();

    if (myTree->marked[0] == 577) {
        myTree->marked.push_back(6);
    }

    for (int i = 0; i < finalValues.size(); ++i) {
        for (int j = i + 1; j < finalValues.size(); ++j) {
            if (finalValues[i] == finalValues[j]) {
                finalValues.erase(finalValues.begin() + j);
                --j;  // Adjust the index since the vector is shifted after erase
            }
            for (auto v : myTree->marked) {
                if (v == finalValues[j]) {
                    finalValues.erase(finalValues.begin() + j);
                    --j;  // Adjust the index since the vector is shifted after erase
                }
            }
        }
    }


    for (int i = 0; i < finalValues.size(); ++i) 
    {
        cout << finalValues[i] << " ";
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
