 
#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 

/**
 * This program reads tokens from
 * a file then outputs them to the
 * console.
 */

int main () { 
 
  ifstream myInputFile ("input/input1.txt"); //file set to input mode
  string token; //string for storing token values
  char aChar; //char value buffer for reading file
 
  while (!myInputFile.eof()) { 
    do { //process dilemeters
      myInputFile.get(aChar); //read next char from input
    } while ((!myInputFile.eof()) && ((aChar == ' ') || (aChar == '\n'))); //until the char != a dilemeter

    if (!myInputFile.eof()) { //process token 
      token.clear(); //clear token string
      while ((!myInputFile.eof()) && ((aChar != ' ') && (aChar != '\n'))) { //while != dilemeter
        token += aChar; //concat char to token string 
        myInputFile.get(aChar); //read next char from file
      }  
     cout << token << endl; //output token to console
    } //end if 
  } //end while 
  return 0; 
} 