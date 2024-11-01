#include <iostream>
#include "../lib/tree_BinaryTree.h"

class BinaryTree {
protected:
  BinaryTree* _right;
  BinaryTree* _left;
  int _rootData;

public:
  BinaryTree();
  BinaryTree(/*_right and _left and _root*/);
  ~BinaryTree();

  //All-Trees
  void setRight();
  void setLeft();
  void goRight();
  void goLeft();
  void rootData();
  void preOrderEnumeration(); //figure out a return type for this and next two.
  void inOrderEnumeration();
  void postOrderEnumeration();

  //Binary-Trees
  void _find(); //protected _find() for insert and remove methods.
  void insert();
  void remove();
  void search();
  void rangeSearch();

};

int main() {

  return 0;
}