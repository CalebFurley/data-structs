#include "exceptions.h"
#include <iostream>

class LinkedListException : public Exception {};
class LinkedListMemory : public LinkedListException {};
class LinkedListBounds : public LinkedListException {};
class LinkedListNotFound : public LinkedListException {};
class LinkedListAttachToEmpty : public LinkedListException {};

/*********************  PROTOTYPE **********************/
template<class DT>
class LinkedList {
    DT*             _info;
    LinkedList<DT>* _next;
    
public:
    LinkedList();
    LinkedList(const DT& info);
    LinkedList(const DT& info, LinkedList<DT>* next);
    ~LinkedList();

    int size();
    bool isEmpty();

    DT infoAt(int position);
    DT findValue(DT key);

    void insertAt(int position, DT info);
    void removeAt(int position);
    void pushFront(DT info);
};

/******************  IMPLEMENTATION ********************/

template<class DT>
LinkedList<DT>::LinkedList() {
    _info = nullptr;
    _next = nullptr;
}

template <class DT>
LinkedList<DT>::LinkedList(const DT &info) {
    _info = new DT(info);
    if (_info == nullptr) throw LinkedListMemory();
    _next = nullptr;
}

template <class DT>
LinkedList<DT>::LinkedList(const DT& info, LinkedList<DT> *next) {
    _info = new DT(info);
    if (_info == nullptr) throw LinkedListMemory();
    _next = next;
}

template <class DT>
LinkedList<DT>::~LinkedList() {
    if (_info == nullptr) delete _info;
    if (_next == nullptr) delete _next; //recursive-delete-here..
}

template <class DT>
int LinkedList<DT>::size() {
    if (_next == nullptr && _info == nullptr) return 0;
    else if (_next == nullptr && _info != nullptr) return 1;
    else return 1 + _next->size();
}

template <class DT>
bool LinkedList<DT>::isEmpty() {
    return _info == nullptr && _next == nullptr;
}

template<class DT>
DT LinkedList<DT>::infoAt(int position) {
    if(position < 0 || position >= this->size())
        throw LinkedListBounds();
    if(position == 0) return *_info;
    else return _next->infoAt(position-1);
}

template <class DT>
DT LinkedList<DT>::findValue(DT key) {
    if((*_info) == key) return (*_info);
    else if (_info == nullptr) throw LinkedListBounds();
    else if (_next == nullptr) throw LinkedListBounds();
    else return (_next->findValue(key));
}

template <class DT>
void LinkedList<DT>::insertAt(int position, DT info) {
    //check bounds
    if (position < 0 || position >= this->size())
        throw LinkedListBounds();
    //step to position
    if (position != 0) _next->insertAt(position - 1, info);
    //setup newNode and rewire everything
    else {
        //setup new node for existing data
        LinkedList<DT>* moveNode = new LinkedList<DT>();
        moveNode->_info = _info;
        moveNode->_next = _next;
        //set current node to new data
        this->_info = new DT(info);
        this->_next = moveNode;
    }
}

template <class DT>
void LinkedList<DT>::removeAt(int position) {
    //step to position
    //rewire node then delete node at position
}

template <class DT>
void LinkedList<DT>::pushFront(DT info) {
    //setup moveNode with existing data
    LinkedList<DT>* moveNode = new LinkedList();
    moveNode->_info = _info;
    moveNode->_next = _next;
    if (moveNode == nullptr) throw LinkedListMemory();
    //set current node to new data
    this->_info = new DT(info);
    if (_info == nullptr) throw LinkedListMemory();
    this->_next = moveNode;
}

/*********************  TESTING ************************/

int main() {
    LinkedList<int> *list = new LinkedList<int>();

    list->pushFront(5);
    list->pushFront(10);
    list->pushFront(15);
    list->pushFront(20);

    std::cout << "size() = " 
        << list->size() << std::endl;

    std::cout << "findValue(20) = " << 
        list->findValue(20) << std::endl;

    std::cout << "infoAt(0) = " << list->infoAt(0) << std::endl;
    std::cout << "infoAt(1) = "<< list->infoAt(1) << std::endl;
    std::cout << "infoAt(2) = "<< list->infoAt(2) << std::endl;
    std::cout << "infoAt(3) = "<< list->infoAt(3) << std::endl;


    list->insertAt(2, 11);
    std::cout << "inserted 11 @ 2" << std::endl;
    std::cout << "infoAt(2) = " << list->infoAt(2) << std::endl;
    std::cout << "infoAt(3) = " << list->infoAt(3) << std::endl;
    std::cout << "size() = " << list->size() << std::endl;

    delete list;
    return 0;
}