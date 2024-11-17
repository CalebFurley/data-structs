#include <vector>
#include <iostream>
using namespace std;

//________________________________________________ EXCEPTIONS ___________________________________________//
class Exception {};
class DuplicateInsertion : public Exception {};
class NotFoundException : public Exception {};

//________________________________________________ PROTOTYPE ____________________________________________//
template <class DT>
class MTree {
protected:
    int M;                       // Maximum number of children per node (M-way tree)
    vector<DT> values;           // Values stored in the node
    vector<MTree*> children;     // Children pointers (M-way branching)

    void splitNode(MTree<DT>* parent, int index); // Split a node and adjust the parent
    void mergeOrRedistribute(MTree<DT>* parent, int index); // Handle underflow (extra)

public:
    MTree(int M);                // Constructor
    ~MTree();                    // Destructor

    void buildTree(const vector<DT>& inputValues);   // Build the tree  


    bool isLeaf() const;         // Check if the current node is a leaf
    void insert(const DT& value); // Insert a value
    void remove(const DT& value); // Remove a value
    MTree<DT>* search(const DT& value); // Search for a value
    bool find(const DT& value);  // Check if a value exists in the tree
    vector<DT> collectValues();  // Collect all values in sorted order
};

//________________________________________________ IMPLEMENTATION ________________________________________//

// Constructor
template <class DT>
MTree<DT>::MTree(int M) : M(M) {}

// Destructor
template <class DT>
MTree<DT>::~MTree() {
    for (auto child : children) {
        delete child;
    }
}

// Check if the node is a leaf
template <class DT>
bool MTree<DT>::isLeaf() const {
    return children.empty();
}

// Split a node and adjust its parent
template <class DT>
void MTree<DT>::splitNode(MTree<DT>* parent, int index) {
    int midIndex = values.size() / 2;
    DT midValue = values[midIndex];

    // Create a new node for the right half
    MTree<DT>* rightNode = new MTree<DT>(M);
    rightNode->values.assign(values.begin() + midIndex + 1, values.end());
    values.resize(midIndex);

    // If not a leaf, transfer children
    if (!isLeaf()) {
        rightNode->children.assign(children.begin() + midIndex + 1, children.end());
        children.resize(midIndex + 1);
    }

    // Insert midValue into the parent
    parent->values.insert(parent->values.begin() + index, midValue);
    parent->children.insert(parent->children.begin() + index + 1, rightNode);
}

// Search for a value in the tree
template <class DT>
MTree<DT>* MTree<DT>::search(const DT& value) {
    // Traverse through the current node's values
    int i = 0;
    while (i < values.size() && value > values[i]) {
        ++i;
    }

    // If found in the current node
    if (i < values.size() && value == values[i]) {
        return this;
    }

    // If it's a leaf, the value is not found
    if (isLeaf()) {
        return nullptr;
    }

    // Recur to the appropriate child
    return children[i]->search(value);
}

// Insert a value into the tree
template <class DT>
void MTree<DT>::insert(const DT& value) {
    // Check for duplicates
    if (search(value)) {
        throw DuplicateInsertion();
    }

    // If the node is a leaf, insert the value directly
    if (isLeaf()) {
        values.push_back(value);
        sort(values.begin(), values.end());

        // Split if overflow
        if (values.size() >= M) {
            throw runtime_error("Splitting logic requires parent reference.");
        }
    } else {
        // Find the correct child to insert into
        int i = 0;
        while (i < values.size() && value > values[i]) {
            ++i;
        }

        // Insert recursively into the appropriate child
        children[i]->insert(value);

        // Handle child splits (currently requires parent logic, omitted)
    }
}

// Remove a value from the tree
template <class DT>
void MTree<DT>::remove(const DT& value) {
    throw runtime_error("Remove logic requires full underflow handling.");
}

// Find if a value exists
template <class DT>
bool MTree<DT>::find(const DT& value) {
    return search(value) != nullptr;
}

// Collect all values from the tree in sorted order
template <class DT>
vector<DT> MTree<DT>::collectValues() {
    vector<DT> result;

    // Collect values from the current node
    result.insert(result.end(), values.begin(), values.end());

    // Collect values from children (if any)
    for (auto child : children) {
        vector<DT> childValues = child->collectValues();
        result.insert(result.end(), childValues.begin(), childValues.end());
    }

    return result;
}

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
