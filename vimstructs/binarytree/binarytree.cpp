#include <iostream>
using std::cout;
using std::endl;

class BinaryTree {
public:
  BinaryTree* _left;
  BinaryTree* _right;
  int* _root;
  
  BinaryTree();
  BinaryTree(int root);
  BinaryTree(int root, BinaryTree* left, BinaryTree* right);
  ~BinaryTree();
  
  int size();         //returns number of nodes in the tree
  int height();       //returns height of the tree

  int preOrder();     //displays the preorder traversal
  int inOrder();      //displays the inorder traversal
  int postOrder();    //displays the postorder traversal
};

BinaryTree::BinaryTree() 
  : _right(nullptr)
  , _left(nullptr)
  , _root(nullptr) 
  {}

BinaryTree::BinaryTree(int root) {
  _root = new int(root);
}

BinaryTree::BinaryTree(int root, BinaryTree* left, BinaryTree* right) {
  _root = new int(root);
  _left = left;
  _right = right;
}

BinaryTree::~BinaryTree(){//deletes the entire tree
  if (_root != nullptr) { delete _root; _root = nullptr; }
  if (_right != nullptr) { delete _right; _right = nullptr; } 
  if (_left != nullptr) { delete _left; _left = nullptr; }
};

int BinaryTree::size() {
  int leftheight = 0;
  int totalheight;
  
  if (_left == nullptr) totalheight = 0;
  else leftheight = _left->size(); 
  
  if (_right == nullptr) totalheight = 1 + leftheight;
  else totalheight = 1 + leftheight + _right->size();

  return totalheight;
}

int BinaryTree::height() {
  //TODO write the height method.
  //      after, write the traversals
  //       also read book and see other methods.
  return 0;
}

int main(int argc, char** argv) {
  BinaryTree* tree = new BinaryTree(1);
  tree->_right = new BinaryTree(2);
  tree->_left = new BinaryTree(3);
  tree->_left->_left = new BinaryTree(4);
  tree->_left->_right = new BinaryTree(5);
  tree->_right->_left = new BinaryTree(6);

  cout << tree->size() << endl;

  delete tree;
  return 0;
};
