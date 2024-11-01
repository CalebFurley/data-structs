#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

/*
  Other Trees to Build:
    1. Splay
    2. Red/Black
    3. AVL
    4. 2-3
*/

class BST {
protected:
  BST* _right;
  BST* _left;
  int  _data;
  int  _color;//0=black,1=red
  
  BST* _find(int data);
  stack<BST*>& pushToBtmLeft(stack<BST*>& stack, BST* top);
public:
  BST();
  BST(int data);
  BST(BST* left, BST* right, int data);
  ~BST();

  int  find(int data);
  void insert(int data);
  BST* remove(int data);

  int height();
  int size();

  int* preOrder();
  int* inOrder();
  int* postOrder();
 
  BST* buildTree(int* arr, BST* left, BST* right);
    //inorder()->array; buildTree(array);
   
  void zig();
  void zag();

  void display();
};

BST* BST::_find(int data) { // check this method
  if (data < _data && _left != nullptr) 
    return _left->_find(data);
  else if (data > _data && _right != nullptr) 
    return _right->_find(data);
  else return this;
}

BST::BST()
:_right(nullptr)
,_left(nullptr)
,_data(0)
,_color(-1){}

BST::BST(int data)
:_right(nullptr)
,_left(nullptr)
,_data(data)
,_color(-1){}

BST::BST(BST* left, BST* right, int data)
:_left(left)
,_right(right)
,_data(data)
,_color(-1){}

BST::~BST(){
  delete _right;
  delete _left;
}

int BST::find(int data) {
  return _find(data)->_data;
}

void BST::insert(int data) {
  BST* parent = _find(data);
  if (data == parent->_data)
    return;
  else if (data < parent->_data)
    parent->_left = new BST(data);
  else
    parent->_right = new BST(data);
}

BST* BST::remove(int data) {
  // this method will be tricky..
  return nullptr; //TODO
}

int BST::height() {
  int height;
  int leftheight;
  if (_left == nullptr) leftheight = 0;
  else leftheight = _left->height();
  if (_right == nullptr) height = 1 + leftheight;
  else height = 1 + max(leftheight,_right->height());
  return height;
}

int BST::size() {
  int size;
  int leftsize;
  if (_left == nullptr) leftsize = 0;
  else leftsize = _left->size();
  if (_right == nullptr) size = 1 + leftsize;
  else size = 1 + leftsize + _right->size();
  return size;
}

int* BST::preOrder() {
  int* array = new int[size()];
  int index = 0;
  stack<BST*> stack;
  stack.push(this);
  BST* current = nullptr;
  while ( !(stack.empty()) ) {
    current = stack.top();
    stack.pop();
    if (current->_right != nullptr)
      stack.push (current->_right);
    if (current->_left != nullptr)
      stack.push (current->_left);
    array[index++] = current->_data;
  }
  return array;
}

stack<BST*>& BST::pushToBtmLeft(stack<BST*>& stack, BST* top) {
  BST* current = top;
  while(current != nullptr) {
    stack.push(current);
    current = current->_left;
  }
  return stack;
}

int* BST::inOrder() { //this shit is fucked up TODO TODO
  int* array = new int[size()];
  int index = 0;
  BST* top = this;
  stack<BST*> stack;
  stack.push(top);
  stack = pushToBtmLeft(stack,top);

  while( !(stack.empty()) ) {
    top = stack.top();
    cout << top->_data << endl; //DEBUGGING
    stack.pop();                //PICKUP HERE TODO
    if (top->_right != nullptr) {
      top = top->_right;
    }
    stack = pushToBtmLeft(stack,top);
  }

  return array;
}

int* BST::postOrder() {
  return nullptr;
}

BST* BST::buildTree(int* arr, BST* left, BST* right) {
  //inorder()->array; buildTree(array);
  return nullptr;
}
   
void BST::zig() {
}

void BST::zag() {
}

void BST::display() {
}

int main(){
  BST* bst = new BST(10);
  bst->insert(5);
  bst->insert(2);
  bst->insert(14);
  bst->insert(7);
  cout << bst->height() << endl;
  
  cout << endl;
  bst->inOrder();
  cout << endl;

  int* array = bst->preOrder();
  for (int i=0; i<bst->size(); ++i)
    cout << array[i] << " ";
  cout << endl;

  delete array;
  delete bst;
  return 0;
}
