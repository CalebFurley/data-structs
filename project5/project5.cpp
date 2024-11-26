#include <iostream> 
#include <fstream> 
#include <string> 
#include <unordered_map> 
#include <map> 
#include <iterator> 
#include <algorithm> 

using namespace std;

/**
 * This program reads in a text file and hashes each word as a token
 * into a map. This map also counts the occurence of each word and 
 * at the end of the program outputs the occurences of each word in
 * descending order.
 * 
 * This program is helpful as it can lower the space needed to store
 * the strings in a file and can be used as a compression technique.
 * 
 * After finishing this program, use the bonus section to uncompress
 * the tokens from this script and rebuilt the original paragraph.
 */

 
int main () { 
 
  //read the name of the file ./a.out < filename.txt 
      
  //get each token and store them in the unordered_map (or map) increment 
  //its frequencies. You MAY be able to do myTokens[aToken]++. Work on this. 
 
  //close the file (filename.txt) 
  //sort the myTokens in the decreasing order of VALUE which is frequencies 
  //print the KEYS in myTokens (which has been sorted)separated by a space. 
 
  //after you printed the KEYS Do this 
  cout << endl; 
  cout << "********" << endl; 
   
  //Now open the filename.text file again for reading 
  //Read token by token as you have done this before 
  //each time you get a token, find its position in the myTokens (sorted 
  //data structure and print the position followed by space 
 
  cout << endl; 
 
  return 0; 
}