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

  //-------------------------------------------------------------------------------------------
  /*** Program Variables ***/
  ofstream tempFile("temp.txt");
  ifstream inputFile("temp.txt");
  char ch;
  string token;
  unordered_map<string,int> tokensMap;
  //-------------------------------------------------------------------------------------------
  //read the name of the file ./a.out < filename.txt (this does not work btw.)
  //^^this command redirect input, it does not get filename.. To get around this
  //  im going to make a temp file from the cin input.
  while (!cin.eof()) {
    cin.get(ch);
    tempFile.put(ch);
  }
  tempFile.close();
  //-------------------------------------------------------------------------------------------
  //read from the temp input file and store tokens and counts in tokensMap.
    //get each token and store them in the unordered_map (or map) increment 
    //its frequencies. You MAY be able to do myTokens[aToken]++. Work on this.
  while (!inputFile.eof()) {
    do { //process dilemeters
      inputFile.get(ch);
    } while ((!inputFile.eof()) && ((ch == ' ') || (ch == '\n')));

    if (!inputFile.eof()) { //process tokens
      token.clear();
      while ((!inputFile.eof()) && ((ch != ' ') && (ch != '\n'))) {
        token += ch;
        inputFile.get(ch); 
      }
      if (tokensMap[token] == 0) { //==NULL
        tokensMap[token] = 1;
      }
      else {
        tokensMap[token]++;
      }
    }
  }
  //-------------------------------------------------------------------------------------------
  //close the file (filename.txt) 
  inputFile.close();

  // Multimap to store frequencies, with inner map sorting the words lexicographically
  multimap<int, map<string, int>, greater<int>> tokensMapSorted;

  // Fill the multimap with data
  for (const auto& pair : tokensMap) {
    // Try to find the frequency group in the multimap
    auto it = tokensMapSorted.find(pair.second);

    // If the frequency group doesn't exist, create a new one
    if (it == tokensMapSorted.end()) {
      map<string, int> innerMap;
      innerMap[pair.first] = pair.second;
      tokensMapSorted.insert({pair.second, innerMap});
    } else {
      // If the frequency group exists, insert the word into the inner map
      it->second[pair.first] = pair.second;
    }
  }

  // Print the words, first sorted by frequency and then by lexicographical order
  for (const auto& freqPair : tokensMapSorted) {
    // Iterate over the map of strings for each frequency group
    for (const auto& wordPair : freqPair.second) {
      cout << wordPair.first << " ";
    }
  }
  //-------------------------------------------------------------------------------------------
  //after you printed the KEYS Do this 
  cout << endl; 
  cout << "********" << endl; 
   
  //Now open the filename.text file again for reading 
  ifstream inputFile2("temp.txt");

  while (!inputFile2.eof()) {
    do { 
      // Process delimiters (spaces or newlines)
      inputFile2.get(ch);
    } while ((!inputFile2.eof()) && ((ch == ' ') || (ch == '\n')));

    if (!inputFile2.eof()) {
      // Process tokens
      token.clear();
      while ((!inputFile2.eof()) && ((ch != ' ') && (ch != '\n'))) {
        token += ch;
        inputFile2.get(ch);
      }

      // Now, token contains the word. Find its position in the sorted map.
      bool found = false;
      int globalIndex = 1;  // Initialize a global index to track position across all frequency groups

      for (const auto& freqPair : tokensMapSorted) {
        int localIndex = 0;  // Local index within a frequency group
        // Iterate over the map of strings for each frequency group
        for (const auto& wordPair : freqPair.second) {
          if (wordPair.first == token) {
            cout << globalIndex + localIndex << " "; // Position is the global index + local index
            found = true;
            break;
          }
          localIndex++;  // Increment local index within the current frequency group
        }
        if (found) {
          break; // If found, exit the outer loop
        }
        globalIndex += freqPair.second.size(); // Increment the global index for the next frequency group
      }

      if (!found) {
        cout << "-1 ";  // If the token was not found, print -1
      }
    }
  }
 
  cout << endl; 
  return 0; 
//-------------------------------------------------------------------------------------------
}