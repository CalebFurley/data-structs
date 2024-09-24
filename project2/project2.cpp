#include <iostream>
#include <string> 
using namespace std; 
 
class Chip { 
private: 
    char chipType = ' ';    // Type of the chip (A: Addition, S: Subtraction, etc.) 
    string id = "";        // Unique identifier for the chip 
    Chip* input1 = nullptr;     // Pointer to the first input chip 
    Chip* input2 = nullptr;     // Pointer to the second input chip (can be NULL) 
    Chip* output = nullptr;      // Ptr to the output chip (is NULL for output chips) 
    double inputValue = 0.0; //for the input chip 
 
public: 
    //Constructors 
    Chip();
    Chip(char type, const string& id); 
    ~Chip();
 
    //Mutators 
    void setInput1(Chip* inputChip);  // Sets the first input chip 
    void setInput2(Chip* inputChip);  // second input chip (can be NULL) 
    void setOutput(Chip* outputChip); // Sets the output chip (can be NULL) 
    void setInputValue(double value);

    //Functionality
    void compute(); // Performs the operation based on the chip type 
    void display() const; // Displays the chip's information 

    //Accessors
    char getType() const; // Returns the chip Type  
    string getId() const; // Returns the chip ID 
    string getName() const; //Returns full chip name ("type+id")

    //Overloads
    friend ostream& operator << (ostream& stream, const Chip& self); // Output overload
};
//////////////////////////////////////////////////////////////////////////////////

Chip::Chip()
{
}

Chip::Chip(char type, const string &id)
    : chipType(type), id(id)
{
}

Chip::~Chip()
{
    if (input1 != nullptr) delete input1;
    if (input2 != nullptr) delete input2;
    if (output != nullptr) delete output;
}

void Chip::setInput1(Chip *inputChip)
{
    if (input1 != nullptr) {
        setInput2(inputChip);
        return;
    }
    else {
        input1 = inputChip;
    }
}

void Chip::setInput2(Chip *inputChip)
{
    input2 = inputChip;
}

void Chip::setOutput(Chip *outputChip)
{
    output = outputChip;
}

void Chip::setInputValue(double value)
{
    this->inputValue = value;
}

void Chip::compute()
{
    switch(chipType) {
        case 'A':
            //add-values
            break;
        case 'S':
            //subtract-values
            break;
        case 'M':
            //multiply-values
            break;
        case 'D':
            //divide-values
            break;
        case 'N':
            //negate-value
            break;
        case 'I':
            //input
            break;
        case 'O':
            //output
            break;
        default:
            break;
    }
}

void Chip::display() const {
    cout << getName();
    if (input1 != nullptr) cout << ", Input 1 = " << this->input1->getName();
    if (input2 != nullptr) cout << ", Input 2 = " << this->input2->getName();
    if (output != nullptr) cout << ", Output = " << this->output->getName();
    cout << endl;;
}

char Chip::getType() const
{
    return this->chipType;
}

string Chip::getId() const
{
    return this->id;
}

string Chip::getName() const
{
    return this->getType() + this->getId();
}

ostream &operator<<(ostream &stream, const Chip &self)
{
    stream << self.chipType << self.id << endl;
    return stream;
}

//////////////////////////////////////////////////////////////////////////////////

int searchChips(Chip** chipsArray, size_t numChips, string chipName) {
    for (int i=0; i<numChips; ++i) {
        if ( chipsArray[i]->getName() == chipName ) {
            return i;
        }
    }
    return -1;
}

int main () { 
 
    int numChips; 
    Chip** allChips; 
    int numCommands;
    string inputBuffer = ""; 
    Chip* inputChip;

    char chipType = ' ';
    string chipID = "";
    string chipName = "";
    double value = 0.0;

    int firstIndex, secondIndex;

    cin >> numChips; //create an array Chip objects pointers 
    allChips = new Chip*[numChips]; //each array location is a pointer to a Chip Object 
    
    for (int i=0; i < numChips; i++) { 
        inputBuffer = "";

        //read the chip ID based on the first letter to determine its type 
        cin >> inputBuffer;
        chipType = inputBuffer[0];
        inputBuffer.erase(0,1);
        chipID = inputBuffer;

        //create the chip object and store it in allChips array.
        allChips[i] = new Chip(chipType, chipID);
    } 
    

    //read from input the links and make the appropriate  
    //connections. You may need to search the array allChips  
    //to find the chip that is referred and connect.
    
    cin >> numCommands;
    for (int i=0; i < numCommands; i++) {

        cin >> chipType; //read chip type

        switch(chipType) {

            //Connect two chips together.
            case 'A':
                //read the input chips name
                cin >> chipName;
                firstIndex = searchChips(allChips, numChips, chipName);
                //read the output chips name
                cin >> chipName;
                secondIndex = searchChips(allChips, numChips, chipName);
                //set input-chip as input to output-chip
                allChips[secondIndex]->setInput1(allChips[firstIndex]);
                //set output-chip as output to input-chip
                allChips[firstIndex]->setOutput(allChips[secondIndex]);
                break;

            //Set the input value of the chip.
            case 'I':
                //read in the chip name
                cin >> chipName;
                firstIndex = searchChips(allChips, numChips, chipName);
                //read in the value
                cin >> value;
                //set the value to the chip
                allChips[firstIndex]->setInputValue(value);
                break;

            case 'O':
                //nothing
                break;

            default:
                break;
        }
    }

    cout << "***** Showing the connections that were established" << endl; 
    for (int i=0; i<numChips; ++i) {
        allChips[i]->display();
    }

    //End program safely.
    delete[] allChips;
    allChips = nullptr;
    return 0; 
}