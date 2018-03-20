/*
Implement a function reverseWords that reverses the order of the words in the array in the most efficient manner.
Ex: arr = [ 'p', 'e', 'r', 'f', 'e', 'c', 't', ' ', 'm', 'a', 'k', 'e', 's', ' ', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e' ]
output: [ 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e', ' ', 'm', 'a', 'k', 'e', 's', ' ', 'p', 'e', 'r', 'f', 'e', 'c', 't' ]
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<char> reverseWords(vector<char>& arr ) 
{
  // your code goes here
  string inputStr;
  for(char& c: arr) {
    inputStr+=c;
  }
  
  std::reverse(inputStr.begin(), inputStr.end());
  istringstream iss(inputStr);
  string individualWord, finalOutput;

  while(iss>>individualWord) {
    std::reverse(individualWord.begin(), individualWord.end());
    finalOutput+=individualWord;
    finalOutput+=' ';
  }
  
  vector<char> result;
  for(char& c: finalOutput)
    result.push_back(c);
  
  return result;
}

int main() {
  vector<char> arr= {'p', 'e', 'r', 'f', 'e', 'c', 't', ' ',
                'm', 'a', 'k', 'e', 's', ' ',
                'p', 'r', 'a', 'c', 't', 'i', 'c', 'e' };
  vector<char> ans = reverseWords(arr);
  
  for(auto& each: ans) cout<<each<<" ";
  
  return 0;
}
