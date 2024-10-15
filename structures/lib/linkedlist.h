#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "exception.h"
using std::ostream;

class LinkedListException : public Exception {};
class LinkedListMemory : public LinkedListException {};
class LinkedListBounds : public LinkedListException {};
//define other exceptions
//implement exceptions throughout class

template <class DT>
class LinkedList {
protected:
  DT* _info; //points to information at node.
  LinkedList<DT>* _next; //points to next node.

public:
  //Constructors
  LinkedList(); //default constructor.
  LinkedList(DT& info); //constructs new node with info.
  LinkedList(const LinkedList<DT>& other);//copy constructor.
  ~LinkedList(); //destructor, cool implementation.

  //ErrorChecks
  bool isEmpty() const;

  //Accessors
  int size() const; //calculates and returns size of list.
  DT infoAt(int position) const; //returns info at given position.
  int find(const DT& info) const; //returns index of given info.

  //Mutators
  void add(const DT& info); //adds new node with given info to current position.
  void insertAt(const DT& info, int position); //adds new node to given position.
  void remove(int position); //remove node from given position.

  //Operators
  LinkedList<DT>* operator = (const LinkedList<DT>& other); //asignment deep-copy.
  template<class U>
  friend ostream& operator << (ostream& stream, LinkedList<U> list); //print.
};

template<class DT>
LinkedList<DT>::LinkedList() {
  this->_info = nullptr;
  this->_next = nullptr;
}

template<class DT>
LinkedList<DT>::LinkedList(DT& info) {
  this->_info = new DT(info);
  this->_next = nullptr;
}

template<class DT>
LinkedList<DT>::LinkedList(const LinkedList<DT>& other) {
  //set-information
  if(other._info == nullptr) this->_info = nullptr;
  else this->_info = new DT(*(other._info));
  //set-next-node
  if(other._next == nullptr) this->_next = nullptr;
  else this->_next = new LinkedList<DT>(other._next);
}

template<class DT>
LinkedList<DT>::~LinkedList() {
  if (this->_info != nullptr) delete this->_info;
  if (this->_next != nullptr) delete this->_next;//recursive-delete
}

template<class DT>
bool LinkedList<DT>::isEmpty() const {
  return this->_info == nullptr;
}

template<class DT>
int LinkedList<DT>::size() const {
  if (_next == nullptr) {
    if (_info == nullptr) return 0;
    else return 1;
  }
  else return 1 + _next->size();
}

template<class DT>
DT LinkedList<DT>::infoAt(int position) const {
  if (position == 0) return _info;
  else return _next->infoAt(position-1);
}

template<class DT>
int LinkedList<DT>::find(const DT& info) const {
  if (*(this->_info) == info) return this->_info;
  else return _next->find(info);
}

template<class DT>
void LinkedList<DT>::add(const DT& info) {
  //newNode<-currentNode
  LinkedList<DT>* newNode = new LinkedList<DT>();
  newNode->_info = this->_info;
  newNode->_next = this->-next;
  //currentNode=newInformation,_next->newNode
  this->_info = new DT(info);
  this->_next = newNode();
}

template<class DT>
void LinkedList<DT>::insertAt(const DT& info, int position) {
  if (position == 0) this->add(info);
  else _next->insertAt(info,position-1);
}

template<class DT>
void LinkedList<DT>::remove(int position) {
  //copy _next node into this node TODO CHECK THIS
  LinkedList<DT>* tempNode = _next;
  this->_info = new DT(*(_next->_info));
  _next = tempNode;
  //delete old _next node
  _next->_next = nullptr;
  delete _next;
}

template<class DT>
LinkedList<DT>* LinkedList<DT>::operator=(const LinkedList<DT>& other) {
  return nullptr;
}

template<class U>
ostream& operator << (ostream& stream, LinkedList<U> list) {
  return stream;
}

#endif
