#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> stack;

  //when operand exists, push
  //when operator exists, pop 2, calculate, push result

  //input operands and opertaors
  //set precedence

  char operators[] = {'*','/','+','-'};
  int precedence[] = {2,2,1,1};

  int size;
  cout << "input length of equation: "; 
  cin >> size; cout << endl;

  cout << "input the equation: ";
  char equation[size] = {};
  for (int i=0; i<size; ++i) {
    cin >> equation[i];
  } cout << endl;

  for (int i=0; i<size; ++i)
    cout << equation[i] << " ";
  cout << endl;
  
  int first = 0;
  int second = 0;

  for (int i=0; i<size; ++i) {
    switch(equation[i]) {
      case '*':
        first = stack.top();
        stack.pop();
        second = stack.top();
        stack.pop();
        cout << first << " * " << second << endl;
        stack.push(first * second);
        cout << stack.top();
        break;

      default:
        stack.push(equation[i]);
        break;
    }
  }

  return 0;
}

