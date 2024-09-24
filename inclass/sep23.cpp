#include <iostream>

/*Reading
    1. Read Chapter 3
        -Finish ArrayClass
        -Finish Project2

    2. Read Chapter 4- linked lists
        -...
*/

/*LinkedLists
    1. Grow and shrink in size.
        -Grow and shrink by re-connecting pointers
        -Can only insert to beginning or end(on doubly-linked-lists)

        -Advatange is fast growth
        -DisAdvantage is slow lookup

    2. LinkedLists-Attributes
        -create
        -add, to the beginning
        -remove
        -etc..etc..
*/

/*Advice
    1. Make very general abstract version of all structures.
    2. Inherit rom that and build your custom structures.
*/

// !!! Finish the ArrayClass, can use in many other places for ease of printing and just everything bh.


class Node {
    int  _value;
    int* _nextBox;
public:
    void goNext();
};

class LinkedList {
    int _value = NULL;
    int* _next = nullptr;
public:
    LinkedList();//needed?
    ~LinkedList();//cool-destruct
    void add();
    void remove();
    void size();//recursive-addup
};


int main(int argc, char** argv) 
{
    std::cout << "Hello World" << std::endl;
    return 0;
}