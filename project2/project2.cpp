#include <iostream>
#include <string> 
using namespace std; 

/*
    The program is broken up into 5 sections:
      1. Chip Prototype
      2. Chip Implementation
      3. Helper Functions and Testing via main()
      4. LLM Usage Documentation
      5. Debug Plan Documentation
*/

/*************************** Chip Prototype ***************************/
class Chip { 
private: 
    char chipType = ' '; // Type of the chip (A: Addition, S: Subtraction, etc.) 
    string id = "";      // Unique identifier for the chip 
    Chip* input1 = nullptr; // Pointer to the first input chip 
    Chip* input2 = nullptr; // Pointer to the second input chip (can be NULL) 
    Chip* output = nullptr; // Ptr to the output chip (is NULL for output chips) 
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
    void setInputValue(double value); // Sets the inputValue member field.

    //Functionality
    void compute(); // Performs the operation based on the chip type 
    void display() const; // Displays the chip's information 

    //Accessors
    char getType() const; // Returns the chip Type  
    string getId() const; // Returns the chip ID 
    string getName() const; //Returns full chip name ("type+id")

    //Overloads
    friend ostream& operator << (ostream& stream, const Chip& self);
};

/************************ Chip Implementations ************************/
//Default Constructor.
Chip::Chip() {}

//Constructor.
Chip::Chip(char type, const string &id)
    : chipType(type), id(id) {}

//Destructor.
Chip::~Chip() {
    if (input1 != nullptr) delete input1;
    if (input2 != nullptr) delete input2;
    if (output != nullptr) delete output;
}

//Sets the input1 chip.
void Chip::setInput1(Chip *inputChip) {
    if (input1 != nullptr) setInput2(inputChip);
    else input1 = inputChip;
}

//Sets the input2 chip.
void Chip::setInput2(Chip *inputChip) {
    input2 = inputChip;
}

//Sets the output chip.
void Chip::setOutput(Chip *outputChip) {
    output = outputChip;
}

//Sets the inputValue.
void Chip::setInputValue(double value) {
    this->inputValue = value;
}

//Performs the computations when the program is ran.
void Chip::compute() {
    switch(chipType) {
        case 'A':
            if (input1 != nullptr && input2 != nullptr) {
                input1->compute();
                input2->compute();
                inputValue = input1->inputValue + input2->inputValue;
            }
            break;
        case 'S':
            if (input1 != nullptr && input2 != nullptr) {
                input1->compute();
                input2->compute();
                inputValue = input1->inputValue - input2->inputValue;
            }
            break;
        case 'M':
            if (input1 != nullptr && input2 != nullptr) {
                input1->compute();
                input2->compute();
                inputValue = input1->inputValue * input2->inputValue;
            }
            break;
        case 'D':
            if (input1 != nullptr && input2 != nullptr) {
                input1->compute();
                input2->compute();
                if (input2->inputValue != 0) {
                    inputValue = input1->inputValue / input2->inputValue;
                } else {
                    cerr << "Error: Division by zero" << endl;
                }
            }
            break;
        case 'N':
            if (input1 != nullptr) {
                input1->compute();
                inputValue = -input1->inputValue;
            }
            break;
        case 'I':
            // Input value is already set
            break;
        case 'O':
            cout << "Computation Starts" << endl;
            if (input1 != nullptr) {
                input1->compute();
                cout << "The output value from this circuit is " << input1->inputValue << endl;
            }
            break;
        default:
            cerr << "Error: Unknown chip type" << endl;
            break;
    }
}

//Displays the current chip to the console.
void Chip::display() const {
    cout << getName();

    if (input1 != nullptr) cout << ", Input 1 = " << this->input1->getName();
    else if (chipType != 'I' && chipType != 'O') cout << ", Input 1 = None";
    
    if (input2 != nullptr) cout << ", Input 2 = " << this->input2->getName();
    else if (chipType != 'I' && chipType != 'O') cout << ", Input 2 = None";
    
    if (output != nullptr) cout << ", Output = " << this->output->getName();
    cout << endl;;
}

//Returns the type of the chip.
char Chip::getType() const {
    return this->chipType;
}

//Returns the id of the chip.
string Chip::getId() const {
    return this->id;
}

//Returns the name of the chip.
string Chip::getName() const {
    return this->getType() + this->getId();
}

//Overloads the << operator for easy printing.
ostream &operator<<(ostream &stream, const Chip &self) {
    stream << self.chipType << self.id << endl;
    return stream;
}

/******************** Helper Functions for Testing ********************/

// Searches the chips array and returns the index of the named chip that
// was passed into the function.
int searchChips(Chip** chipsArray, size_t numChips, string chipName) {
    for (int i=0; i<numChips; ++i) {
        if ( chipsArray[i]->getName() == chipName ) {
            return i;
        }
    }
    return -1;
}

// Testing done here in the main function.
int main (int argc, char** argv) { 
 
    /* Testing Variables Global to Main */
    int numChips; 
    Chip** allChips; 
    int numCommands;
    string inputBuffer = ""; 
    Chip* inputChip;

    char chipType = ' ';
    string chipID = "";
    string chipName = "";
    double value = 0.0;
    int firstIndex = 0;
    int secondIndex = 0;

    /* Read in the chips into the allChips[] array. */
    cin >> numChips;
    allChips = new Chip*[numChips];
    
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
    
    /* Connect all the chips, and set the input values. */
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

    /* Compute and go through recursion here. */
    int index = searchChips(allChips, numChips, "O50");
    allChips[index]->compute(); //computation begins at O50 chip.


    /* Display the connections portion of the output. */
    cout << "***** Showing the connections that were established" << endl; 
    for (int i=0; i<numChips; ++i) {
        if (allChips[i]->getType() == 'O') continue;
        allChips[i]->display();
    }
    index = searchChips(allChips, numChips, "O50");
    allChips[index]->display();

    //End program safely.
    delete[] allChips;
    allChips = nullptr;
    return 0; 
}

/******************** LLM USAGE DOCUMENTATION ********************/

/*
-----------------------------------------------------------------------------------------------------------------------
    Prompt:
        How can I get a certain character from a c++ string. Is there a way I can pop it?

    Response:
        To get a certain character from a C++ string, you can use the `at()` method or the subscript 
        operator `[]`. However, if you want to remove (pop) a character from the string, you can use the 
        `erase()` method.

        Here's how you can do both:

        1. **Access a character**:
        ```cpp
        char c = inputBuffer.at(index); // Using at() method
        char c = inputBuffer[index];    // Using subscript operator
        ```

        2. **Remove (pop) a character**:
        ```cpp
        inputBuffer.erase(index, 1); // Removes the character at the specified index
        ```

        Here's an example demonstrating both:

        ```cpp
        #include <iostream>
        #include <string>

        int main() {
            std::string inputBuffer = "example";

            // Access the character at index 2
            char c = inputBuffer.at(2); // or inputBuffer[2]
            std::cout << "Character at index 2: " << c << std::endl;

            // Remove (pop) the character at index 2
            inputBuffer.erase(2, 1);
            std::cout << "String after popping character at index 2: " << inputBuffer << std::endl;

            return 0;
        }
        ```

        In your specific case, if you want to read the chip ID based on the first letter and then 
        remove that letter from the string, you can do something like this:

        ```cpp
        for (int i = 0; i < numChips; i++) { 
            inputBuffer = "";
            cin >> inputBuffer;
            cout << inputBuffer << "\n";
            
            // Read the chip ID based on the first letter
            char chipID = inputBuffer[0];
            inputBuffer.erase(0, 1); // Remove the first letter from the string
            
            // Create the chip object and initialize it appropriately
            // Store the chip object in the allChips array
        }
        ```

    Reasoning: 
        Looking for an efficient way to breakdown and read the input strings for building
        the chips.
    -----------------------------------------------------------------------------------------------------------------------
    Prompt:
        What is this error? 
            terminate called after throwing an instance of 'std::bad_alloc'
            what():  std::bad_alloc
            Aborted (core dumped)

    Response:
            The `std::bad_alloc` exception is thrown when the program fails to allocate memory using `new`.
            This can happen if the system runs out of memory or if there is a bug in the code that causes
            excessive memory allocation.

            To diagnose and fix this issue, follow these steps:

            1. **Check Memory Allocation**: Ensure that memory allocation is done correctly and that there are no
            excessive or unnecessary allocations.

            2. **Check for Memory Leaks**: Ensure that all allocated memory is properly deallocated.

            3. **Check Array Size**: Ensure that the size of the array being allocated is reasonable and within the 
            limits of available memory.

            Here's an example of how you might allocate and deallocate memory for an array of objects:

            ```cpp
            #include <iostream>
            #include <stdexcept>

            class Chip {
                // Chip class definition
            };

            int main() {
                int numChips = 10; // Example number of chips
                Chip* allChips = nullptr;

                try {
                    allChips = new Chip[numChips]; // Allocate memory for an array of Chip objects
                } catch (const std::bad_alloc& e) {
                    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
                    return 1;
                }

                // Use the allChips array
                // ...

                // Safely deallocate memory
                delete[] allChips;
                allChips = nullptr;

                return 0;
            }
            ```

            If the problem persists, you might want to use tools like Valgrind to detect memory leaks and other 
            memory-related issues. Run the following command in your terminal to use Valgrind:

            ```sh
            valgrind --leak-check=full ./your_program
            ```

            Replace `./your_program` with the path to your compiled executable. This will help you identify where
            the memory allocation issues are occurring.

        Reasoning:
            When compiling that error was thrown.
        -----------------------------------------------------------------------------------------------------------------------
        Prompt: 
            Pasted progam here..
            Can you check my program for any leaks that could have caused the previous error?

        Response:
                To check for potential memory leaks and issues in your program, let's review the code step-by-step:

            1. **Memory Allocation and Deallocation**:
            - You allocate memory for [`allChips`]
            - Each element in [`allChips`]
            - You correctly deallocate

            2. **Destructor**:
            - The `Chip` destructor deletes `input1`, `input2`, and `output`. This can cause double deletion if multiple `Chip`
            objects point to the same `Chip` object. Ensure that each `Chip` object is only deleted once.

            3. **Potential Issues**:
            - **Double Deletion**: If multiple `Chip` objects share the same `input1`, `input2`, or `output`, deleting 
            one `Chip` will invalidate the pointers in the others.
            - **Uninitialized Pointers**: Ensure that `input1`, `input2`, and `output` are initialized to [`nullptr`]

            Here's a revised version of your code with some fixes:

            ***********************
            **pastes program here**
            ***********************

            ### Key Changes:
            1. **Initialization of Pointers**: Ensure `input1`, `input2`, and `output` are initialized to [`nullptr`]
            2. **Destructor**: Only delete `input1`, `input2`, and `output` if they are not [`nullptr`]
            3. **Memory Deallocation in `main`**: Added a loop to delete each `Chip` object in [`allChips`]

            These changes should help prevent memory leaks and double deletions. If the problem persists, consider using 
            Valgrind to further diagnose memory issues.

        Reasoning:
            Quick debugging so I can keep moving forward with development. I may still install valgrind like
            suggested since I have heard of that tool in the past. It did not end up fixing the issue so I'm
            going to debug this by hand. Literally found the block where the error was in 2 seconds... lol.
        -----------------------------------------------------------------------------------------------------------------------
        Prompt:
            int searchChips(Chip* chipsArray, size_t numChips, string chipName) {
                for (int i=0; i<numChips; ++i) {
                    if ( chipsArray[i].getName() == chipName ) {
                        return i;
                    }
                }
                return -1;
            }

            I think this causes the error somehow

        Response:
        1. **Dereferencing Null Pointers**: If [`chipsArray`]
        2. **Incorrect Array Passing**: Ensure that [`chipsArray`]
        3. **Memory Corruption**: If there is memory corruption elsewhere in the program, it could affect the 
        behavior of this function.
        Let's add some checks and debug output to help diagnose the issue:

        ***********************
        **pastes program here**
        ***********************

        ### Key Changes:
        1. **Null Pointer Check**: Added a check in [`searchChips`]
        2. **Error Messages**: Added error messages to help diagnose issues when a chip is not found or when
        a null pointer is encountered.
        3. **Correct Array Passing**: Changed the parameter type of [`chipsArray`]

        These changes should help you identify if there are any null pointers or other issues causing the error.

    Reasoning:
        Help with debugging the error, the code generated by copilot just added debug prints........ But I myself saw that the
        bug was actually the way I was passing the array into the searchChips function. Fixed the error, got segmentation becaz
        copilt generated a second freaking delete[] array but as a loop at the end of my code, so I deleted that crap, and now
        the code works.
    -----------------------------------------------------------------------------------------------------------------------
    Prompt:
        I am currently trying to implement the compute method of my program. The point of the program to to recursivly step
        through and check if all the inputs are null or not, if null, they need to keep stepping until a value is found then 
        return it back up to the 050 chip to be outputted.

    Response:
        To implement the [`compute`]

    Here's a revised version of your [`compute`]

    ```cpp
    void Chip::compute() {
        switch(chipType) {
            case 'A':
                if (input1 != nullptr && input2 != nullptr) {
                    input1->compute();
                    input2->compute();
                    inputValue = input1->inputValue + input2->inputValue;
                }
                break;
            case 'S':
                if (input1 != nullptr && input2 != nullptr) {
                    input1->compute();
                    input2->compute();
                    inputValue = input1->inputValue - input2->inputValue;
                }
                break;
            case 'M':
                if (input1 != nullptr && input2 != nullptr) {
                    input1->compute();
                    input2->compute();
                    inputValue = input1->inputValue * input2->inputValue;
                }
                break;
            case 'D':
                if (input1 != nullptr && input2 != nullptr) {
                    input1->compute();
                    input2->compute();
                    if (input2->inputValue != 0) {
                        inputValue = input1->inputValue / input2->inputValue;
                    } else {
                        cerr << "Error: Division by zero" << endl;
                    }
                }
                break;
            case 'N':
                if (input1 != nullptr) {
                    input1->compute();
                    inputValue = -input1->inputValue;
                }
                break;
            case 'I':
                // Input value is already set
                break;
            case 'O':
                cout << "Computation Starts" << endl;
                if (input1 != nullptr) {
                    input1->compute();
                    cout << "The output value from this circuit is " << input1->inputValue << endl;
                } else {
                    cerr << "Error: No input for output chip" << endl;
                }
                break;
            default:
                cerr << "Error: Unknown chip type" << endl;
                break;
        }
    }
    ```

    ### Explanation:
    1. **Addition [`A`]
    2. **Subtraction [`S`]
    3. **Multiplication [`M`]
    4. **Division [`D`]
    5. **Negation [`N`]
    6. **Input [`I`]
    7. **Output [`O`]

    ### Usage Example:
    To use the [`compute`]

    ```cpp
    int main() {
        Chip inputChip('I', "1");
        inputChip.setInputValue(10);

        Chip addChip('A', "2");
        addChip.setInput1(&inputChip);
        addChip.setInput2(&inputChip);

        Chip outputChip('O', "3");
        outputChip.setInput1(&addChip);

        outputChip.compute();

        return 0;
    }
    ```

    This example sets up an input chip with a value of 10, an addition chip that adds the input chip's value 
    to itself, and an output chip that prints the result. The [`compute`]

    Reasoning:
        After a couple days of struggling to make progress on the best way to implement the recursive
        portion of the project, I decided to ask copilot and its answer was along the track of my thiking.
        Just helping to figure out the best way to implement this without writing spagheti code.

        Despite the above generated code by copliot being sufficient to finish the project. I am going to 
        go back through and try to use this code as a hint and still try to implement the method myself. This
        is good recursive practice Id prefer not to miss out on. Plus I wrote the entire rest of the project
        so giving it up to copilot in the end feels kind of bad..
*/


/******************** DEBUG PLAN DOCUMENTATOIN ********************/
/*
    Specific-Tests:
        During development of the project, debug printing was used substantially. Putting print statements
        throughout the code while developing allowed me to track values. (I suppose in future I could use VSCode
        debugger and breakpoints) For example, during the connetion of the chips, I printed out statements such as:
            "Chip300" set as input to "Chip500"
            "Chip400" set as input to "Chip500"
            etc...
        This allowed me to track how the chips where connecting so whilst I debugged a bug I wrote during this phase
        of development.

        After development, I did not write any assert() functions this time, but I did make sure that the output matched
        to the provided output files for the project. Which when running input1, input2, and input3 through the compiled
        program, all the outputs to the console matched with the provided output files.

        For future, I could write exceptions and test putting purposefully bugs into the input files and makeing sure the
        program and catch and handle those errors as necessary. But for now, banking on the fact that the user can provide
        a correctly formatted input file.
        

    Issues-Resolutions:
        Describe issues and resolutions here..

        1.
            I ran into this issue "terminate called after throwing an instance of 'std::bad_alloc'
            what():  std::bad_alloc" When writing the code to asign connections between chips.
                This error was due to the way I was passing the allChips[] array into my searchChps
                function. I tried to intitially debug this with copilot, but copilot couldnt find the
                error and actually genereted a another error in my code at the end of main... So i scrapped
                all the code copilot gave me including its little error checks and started commenting out
                the code I had just written until I realized the searchChips() function was the cause of the
                error, and I thats when I noticed I passed te array wrong.

        2.
            Another issue I ran into was when connecting the chips together via th inputs, I would
            get this output:
                Set I1 as input 1 to A100
                Set I2 as input 1 to A100
                Set I2 as input 2 to A100
            Notice that the first two lines set the chip fine, but then the third line overwrites the
            first..
            The error was in the logic of my setInput1() function. I changed this code:
                if (input1 != nullptr) setInput2(inputChip); 
                input1 = inputChip;
            To this code:
                if (input1 != nullptr) setInput2(inputChip);
                else input1 = inputChip;
            The error was in the fact that when setInput2() was called from within setInput1(),
            the function would then return to setInput1() and then set the input.. so adding the else
            statement fixed that because it wouldnt just run the code following the return no matter what.

        3.
            Lastly, this wasn't so much a bug or error, but I struggled conseptually on the best way to write the
            compute() function and after a few days of being stuck handed this off to copilot to see how it would write
            the function. It wrote it in a way I thought of, but way better without needing to pass any parameters and
            just calling the compute() all the way through the recursion then instead of returning any values, just
            altering the inputValue member variable of the chips all the way back to the output chip where it was originally
            called and outputing the inputValue variable after the recursion completed. Obvisouly I went back and I took the
            time to understand how it was written because I'm still working on my recursive thinking.
        
        4.
            I ran into an error with input file 2 and 3 where the output did not print "Input 2 = None" for the negation chip
            so I added some checks in the display method to handle this and make sure all chips are properly printing.

        5. 
            Lastly, when submitting the program, I ran into the bug where the input3 file had the 050 chip read in
            earlier than normal. After almost bashing my head against a wall, I wrote some dirty code at the bottom
            of main to skip over printing the 050 chip during the print loop, then print it after.


    Verification:
        The class was verified through running the program with the main function that was developed alongside the 
        program. When the main function was written, the output was matched up against the output files provided for
        the project and verified that all the values where equal. Past this, the project was then verified through the
        test cases provided through the gradescope upload page.

*/
